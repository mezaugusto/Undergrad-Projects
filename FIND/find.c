#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pwd.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <ftw.h>

#define MAX_ARGS 64             //Numero maximo de argumentos por linea
#define LIMITADORES " \t\r\n\a" //Separadores de Argumentos

char* user; 
char* name;
char* type;
char* permis;
char* commands;
int tfnd, nfnd, pfnd, ufnd, efnd;

char **parseo(char *linea)
{
    int pos = 0;
    char **tokens = malloc(MAX_ARGS * sizeof(char *));
    char *token;
    if(!tokens)
    {
        fprintf(stderr, "myfind: no se pudo reservar memoria\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(linea,LIMITADORES);
    while(token != NULL)
    {
        tokens[pos] = token;
        pos++;
        if(pos>=MAX_ARGS)
        {
            fprintf(stderr, "myfind: excedido el numero maximo de argumentos\n");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, LIMITADORES);
    }
    tokens[pos] = NULL;
    return tokens;
}

int correr(char **linea_parse)
{
    int estado,pid;
    if((pid = fork())==0)
    {
        execvp(linea_parse[0], linea_parse);
        perror("myfind");
        exit(0);
    }
    else if(pid<0)  perror("myfind"),exit(0);
    else    waitpid(pid,&estado,WUNTRACED);
    return 1;
}

int str_cut(char *str, int begin, int len)
{
    int l = strlen(str);
    if (begin<0)    return -1;
    if (len < 0) len = l - begin;
    if (begin + len > l) len = l - begin;
    memmove(str + begin, str + begin + len, l - len + 1);
    return len;
}

int byType(const struct stat st)
{
    int isTrue=0;
    switch (st.st_mode & S_IFMT)
    {
        case S_IFBLK:  isTrue=!strcmp("block",type)?1:isTrue;   break;
        case S_IFCHR:  isTrue=!strcmp("char",type)?1:isTrue;    break;
        case S_IFDIR:  isTrue=!strcmp("dir",type)?1:isTrue;     break;
        case S_IFIFO:  isTrue=!strcmp("pipe",type)?1:isTrue;    break;
        case S_IFLNK:  isTrue=!strcmp("sln",type)?1:isTrue;     break;
        case S_IFREG:  isTrue=!strcmp("normal",type)?1:isTrue;  break;
        case S_IFSOCK: isTrue=!strcmp("sock",type)?1:isTrue;    break;
        default:       perror("Unknown file Type");             break;
    }
    return isTrue;
}

int byName(const char *fpath)
{
    int isTrue=0;
    char backup[strlen(fpath)];
    strcpy(backup,fpath);
    str_cut(backup,0,strlen(backup)-strlen(name));
    isTrue=!strcmp(backup,name)?1:isTrue;
    return isTrue;
}

int byUser(const struct stat st)
{
    int isTrue=0;
    isTrue=!strcmp(getpwuid(st.st_uid)->pw_name,user)?1:isTrue;
    return isTrue;
}

int byPerm(const struct stat st)
{
    int isTrue=0;
    char modo[7];
    snprintf(modo,sizeof(modo),"%lo", (unsigned long) st.st_mode);
    str_cut(modo,0,strlen(modo)-(strlen(permis)==4?4:3));
    isTrue=!strcmp(modo,permis)?1:isTrue;
    return isTrue;
}

static int display_info(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf)
{
    if((tfnd?byType(*sb):1) && (ufnd?byUser(*sb):1) && (nfnd?byName(fpath):1) && (pfnd?byPerm(*sb):1))
        printf("%s\n", fpath);
    return 0;  
}

int main(int argc, char *argv[])
{
  int opt;
  tfnd = 0;
  pfnd = 0;
  ufnd = 0;
  nfnd = 0;
  efnd = 0;

  while ((opt = getopt(argc, argv, "n:p:t:u:e:")) != -1) {
    switch (opt)
    {
      case 'n':
        name = malloc(sizeof(optarg)+strlen("/"));
        strcat(name,"/");
        strcat(name,optarg);
        nfnd = 1;
        break;

      case 't':
        type = malloc(sizeof(optarg));
        strcpy(type,optarg); 
        tfnd = 1;
        break;

      case 'p':
        permis = malloc(sizeof(optarg));
        strcpy(permis,optarg); 
        pfnd = 1;
        break;

      case 'u':
        user = malloc(sizeof(optarg));
        strcpy(user,optarg);
        ufnd = 1;
        break;
      case 'e':
        commands = malloc(sizeof(optarg));
        strcpy(commands,optarg);
        efnd = 1;
        break;  

      default:
        fprintf(stderr, "Uso %s: path [-t tipo] [-n nombre] [-p permisos] [-u usuario]\n\
            Permisions in octal\n\
            Types:\n\
            \tSpecial Block File(block)\n\
            \tCharacter(char)\n\
            \tDirectory(dir)\n\
            \tPipe or FIFO(pipe)\n\
            \tSymbolic Link(sln)\n\
            \tRegular File(normal)\n\
            \tSocket(sock)\n",argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  if (optind >= argc) {
      fprintf(stderr, "Se esperaba argumento\n");
      exit(EXIT_FAILURE);
  }

  if(efnd)
  {
    int p[2];
    pid_t pid,pid2;
    pipe(p);
    if((pid = fork()) == 0){ // codigo del hijo
        close(1);
        dup(p[1]);
        close(p[0]); 
        close(p[1]);
        if (nftw((argc < 2) ? "." : argv[optind], display_info, 10, FTW_PHYS)== -1)
  {
    perror("myfind");
    exit(EXIT_FAILURE);
  }
        exit(EXIT_SUCCESS);
    }
    if((pid2 = fork()) == 0)
    { // codigo del hijo 
        close(0);
        dup(p[0]);
        close(p[1]); 
        close(p[0]);
        correr(parseo(commands));
        exit(EXIT_SUCCESS);
    }
    close(p[0]);        
    close(p[1]);
    waitpid(pid,NULL,0);
    waitpid(pid2,NULL,0);
  }
  else
  {
    if (nftw((argc < 2) ? "." : argv[optind], display_info, 10, FTW_PHYS)== -1)
    {
    perror("myfind");
    exit(EXIT_FAILURE);
    }
  }
  free(name);
  free(type);
  free(user);
  free(permis);
  exit(EXIT_SUCCESS);
}