#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ftw.h>

char* user; 
char* name;
char* type;
int permis, tfnd, nfnd, pfnd, ufnd; 


static int display_info(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf)
{
  if((tflag == FTW_D))
  printf("%-3s %2d %7jd   %-40s %d %s\n",
      (tflag == FTW_D) ?   "d"   : (tflag == FTW_DNR) ? "dnr" :
      (tflag == FTW_DP) ?  "dp"  : (tflag == FTW_F) ?   "f" :
      (tflag == FTW_NS) ?  "ns"  : (tflag == FTW_SL) ?  "sl" :
      (tflag == FTW_SLN) ? "sln" : "???",
      ftwbuf->level, (intmax_t) sb->st_size,
      fpath, ftwbuf->base, fpath + ftwbuf->base);
  return 0;  
}

int main(int argc, char *argv[])
{
  int opt;
  tfnd = 0;
  pfnd = 0;
  ufnd = 0;
  nfnd = 0; 
  permis = 0;

  while ((opt = getopt(argc, argv, "n:p:t:u:")) != -1) {
    switch (opt)
    {
      case 'n':
        name = malloc(sizeof(optarg));
        strcpy(name,optarg); 
        nfnd = 1;
        break;

      case 't':
        type = malloc(sizeof(optarg));
        strcpy(type,optarg); 
        tfnd = 1;
        break;

      case 'p':
        permis = atoi(optarg);
        pfnd = 1;
        break;

      case 'u':
        user = malloc(sizeof(optarg));
        strcpy(user,optarg);
        ufnd = 1;
        break;

      default:
        fprintf(stderr, "Uso %s: path [-t tipo] [-n nombre] [-p permisos] [-u usuario]\n",argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  printf("%s", nfnd? name:"");
  printf("%s", ufnd? user:"");
  printf("%s", tfnd? type:"");
  if(pfnd)printf("%d", permis);
  fflush(stdout);
  if (optind >= argc) {
      fprintf(stderr, "Se esperaba argumento\n");
      exit(EXIT_FAILURE);
  }


  if (nftw((argc < 2) ? "." : argv[1], display_info, 20, FTW_PHYS)== -1) {
    perror("nftw");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
