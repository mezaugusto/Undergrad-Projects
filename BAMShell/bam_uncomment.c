#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>	
#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>
#include <fcntl.h>

#define MAX_ARGS 64				
#define LIMITADORES " \t\r\n\a" 
#define INPUT_CTRL	11			
#define BIT_PATH "bitacora"
#define GRA_PATH "grabadora"

FILE *bitacora;
char *linea;
char *prompt;

pthread_t his_thread;

int estado=1,newLine=0,scripting=0,isChild=0,back_stout,back_sterr;

int cuantasPipe();
int mipipe(char **args,int i);
int mireds(char **args,int i);
int mirede(char **args,int i);
int mired2(char **args,int i);
char *pipedel[] = {"|",">","<","2>"};
int (*pipefunc[]) (char **,int i) = {&mipipe,&mirede,&mireds,&mired2};

int cuantasFunciones();
int micd(char **args);
int miayuda(char **args);
int misalida(char **args);
int mihistory(char **args);
int miscript(char **args);
int mitee(char **args);
char *nuestros[] = {"cd","ayuda","salir","history","script","tee"};
int (*funciones[]) (char **) = {
	&micd,&miayuda,&misalida,&mihistory,&miscript,&mitee
};

int correr(char **linea_parse);
char **parseo(char *linea);
int ejecutar(char **linea_parse);
void loop();

void veintinueve();
void treinta();
void treintauno();

int cuantasPipe()
{
	return sizeof(pipedel)/sizeof(char*);
}

int mipipe(char **args,int div)
{
	int p[2],i,j;
    pid_t pid,pid2;
    char *args1[div+1];
    char *args2[MAX_ARGS-div+1];
    args[div]=NULL;
    for(i=0;i<div;i++)
    	args1[i]=args[i];
   	args1[i]=NULL;
   	for(j=0,i++;args[i]!=NULL;i++,j++)
    	args2[j]=args[i];
    args2[j]=NULL;
    pipe(p);
    if(!isChild)
    {
    	fclose(bitacora);
    	isChild=isChild?0:1;
    }
    if((pid = fork()) == 0){
    	close(1);
        close(p[0]); 
        dup2(p[1],1);
        close(p[1]);
        ejecutar(args1);
        exit(EXIT_SUCCESS);
    }else{ 
   		if((pid2 = fork()) == 0){ 
	        close(0);
	        close(p[1]); 
	        dup2(p[0],0);
        	close(p[0]);
           	ejecutar(args2);
	        exit(EXIT_SUCCESS);
    	}
    	bitacora = fopen(BIT_PATH,"a");
    	isChild=isChild?0:1;
    	close(p[0]);   		
    	close(p[1]);
    }
    waitpid(pid,NULL,0);
	waitpid(pid2,NULL,0);
	return 1;
}

int mirede(char **args,int div)
{
	int p[2],readbytes,a,i,j;
    char *buffer;
    pid_t pid,pid2;
    buffer = malloc(sizeof(char)*FILENAME_MAX);
    char *args1[div+1];
    char *args2[MAX_ARGS-div+1];
    args[div]=NULL;
    for(i=0;i<div;i++)
    	args1[i]=args[i];
   	args1[i]=NULL;
   	for(j=0,i++;args[i]!=NULL;i++,j++)
    	args2[j]=args[i];
    args2[j]=NULL;
    pipe(p);
    if(!isChild)
    {
    	fclose(bitacora);
    	isChild=isChild?0:1;
    }
    if((pid = fork()) == 0){ 
    	close(1);
        close(p[0]); 
        dup2(p[1],1);
        close(p[1]);
        ejecutar(args1);
        exit(EXIT_SUCCESS);
    }else{   
   		if((pid2 = fork()) == 0){ 
	        close(0);
	        close(p[1]); 
           	a = open(args2[0],O_WRONLY | O_CREAT | O_TRUNC,0644);
           	while((readbytes = read(p[0],buffer,FILENAME_MAX)) > 0)
	            write(a,buffer,readbytes); 
        	close(p[0]);
	        exit(EXIT_SUCCESS);
    	}
    	bitacora = fopen(BIT_PATH,"a");
    	isChild=isChild?0:1;
    	close(p[0]);   		
    	close(p[1]);
    }
    waitpid(pid,NULL,0);
	waitpid(pid2,NULL,0);
	free(buffer);
	return 1;
}

int mireds(char **args,int div)
{
	int p[2],readbytes,a,i,j;
    char *buffer;
    pid_t pid,pid2;
    buffer = malloc(sizeof(char)*FILENAME_MAX);
    char *args1[div+1];
    char *args2[MAX_ARGS-div+1];
    args[div]=NULL;
    for(i=0;i<div;i++)
    	args1[i]=args[i];
   	args1[i]=NULL;
   	for(j=0,i++;args[i]!=NULL;i++,j++)
    	args2[j]=args[i];
    args2[j]=NULL;
    pipe(p);
    if(!isChild)
    {
    	fclose(bitacora);
    	isChild=isChild?0:1;
    }
    if((pid = fork()) == 0){
    	close(0);
        close(p[1]); 
        dup2(p[0],0);
        close(p[0]);
        ejecutar(args1);
        exit(EXIT_SUCCESS);
    }else{ 
   		if((pid2 = fork()) == 0){ 
	        close(1);
	        close(p[0]); 
           	a = open(args2[0],O_RDONLY,0644);
           	while((readbytes = read(a,buffer,FILENAME_MAX)) > 0)
	            write(p[1],buffer,readbytes); 
        	close(p[1]);
	        exit(EXIT_SUCCESS);
    	}
    	bitacora = fopen(BIT_PATH,"a");
    	isChild=isChild?0:1;
    	close(p[0]);   		
    	close(p[1]);
    }
    waitpid(pid,NULL,0);
	waitpid(pid2,NULL,0);
	free(buffer);
	return 1;
}

int mired2(char **args,int div)
{
	int p[2],readbytes,a,i,j;
    char *buffer;
    pid_t pid,pid2;
    buffer = malloc(sizeof(char)*FILENAME_MAX);
    char *args1[div+1];
    char *args2[MAX_ARGS-div+1];
    args[div]=NULL;
    for(i=0;i<div;i++)
    	args1[i]=args[i];
   	args1[i]=NULL;
   	for(j=0,i++;args[i]!=NULL;i++,j++)
    	args2[j]=args[i];
    args2[j]=NULL;
    pipe(p);
    if(!isChild)
    {
    	fclose(bitacora);
    	isChild=isChild?0:1;
    }
    if((pid = fork()) == 0){
    	close(2);
        close(p[0]); 
        dup2(p[1],2);
        close(p[1]);
        ejecutar(args1);
        exit(EXIT_SUCCESS);
    }else{   
   		if((pid2 = fork()) == 0){ 
	        close(0);
	        close(p[1]); 
           	a = open(args2[0],O_WRONLY | O_CREAT | O_TRUNC,0644);
           	while((readbytes = read(p[0],buffer,FILENAME_MAX)) > 0)
	            write(a,buffer,readbytes);
        	close(p[0]);
	        exit(EXIT_SUCCESS);
    	}
    	bitacora = fopen(BIT_PATH,"a");
    	isChild=isChild?0:1;
    	close(p[0]);   		
    	close(p[1]);
    }
    waitpid(pid,NULL,0);
	waitpid(pid2,NULL,0);
	free(buffer);
	return 1;
}

int cuantasFunciones()
{
	return sizeof(nuestros)/sizeof(char*);
}

int micd(char **args)
{
	if(args[1] == NULL)
		fprintf(stderr, "bam:\"cd\" requiere 1 argumento\n");
	else
		if(chdir(args[1]) != 0)	perror("bam");
	return 1;
}

int miayuda(char **args)
{
	int i;
	system("clear");
	printf("\t\tBAM Shell\n");
	printf("Autores:\n\tMeza Peña Augusto\n\tMuñoz Alvarez Rosa Maria\n");
	printf("Comandos del Shell\n");
	for (i = 0; i < cuantasFunciones(); i++)
    	printf("  %s\n", nuestros[i]);
    printf("Con reutilización de codigo de Stephen Brennan lsh\n\thttps://github.com/brenns10/lsh\n");
    return 1;
}

int misalida(char **args)
{
	return 0;
}

int mihistory(char **args)
{
	char *hist[3] = {"cat",BIT_PATH,NULL};
	return correr(hist);
}

int mitee(char **args)
{
	int p[2],readbytes,a;
    char *buffer;
    buffer = malloc(sizeof(char)*FILENAME_MAX);
    size_t lon = 0;
    pid_t pid;
    pipe(p);
    if(!isChild)
    {
    	fclose(bitacora);
    	isChild=isChild?0:1;
    }
    fflush(stdout);
    if((pid = fork()) == 0){
        close(p[1]);
        a = open(args[1],O_WRONLY | O_CREAT | O_TRUNC,0644);
        while((readbytes = read(p[0],buffer,FILENAME_MAX)) > 0){
            write(a,buffer,readbytes);
            write(1,buffer,readbytes);
        }
        close(a);
        close(p[0]);
        exit(EXIT_SUCCESS);
    }else{
        close(p[0]);
        while(!feof(stdin)){
            buffer = (char*)NULL;
            getline(&buffer,&lon,stdin); 
            write(p[1],buffer,strlen(buffer));
        }
        close(p[1]);
        bitacora = fopen(BIT_PATH,"a");
    	isChild=isChild?0:1;
    }
    waitpid(pid,NULL,0); 
    free(buffer);
	return 1;
}

int miscript(char **args)
{
	scripting=scripting?0:1;
	if(!scripting)
	{
		dup2(back_sterr, STDERR_FILENO);
		close(back_sterr);
		dup2(back_stout, STDOUT_FILENO);
		close(back_stout);
		fflush(stdout);
		printf("Cerrando script....\n");
	}
	else
	{
		printf("Abriendo script....\n");
		char c;
		int sp_pipe[2];
		fclose(bitacora);
		pipe(sp_pipe);
		const pid_t pid = fork();
		if(!pid)
		{
			close(sp_pipe[1]);
			int noprint=0;
			FILE *grabadora;
			grabadora = fopen(GRA_PATH,"w");
			if(!grabadora) perror("bam");
			fprintf(grabadora,"Grabando script....\n");
			while(read(sp_pipe[0],&c,1) > 0) 
			{
				if(c==INPUT_CTRL)	noprint=noprint?0:1;
				else
				{
					fputc(c,grabadora);
	    			if(!noprint)putchar(c);
	    			fflush(stdout);
	    			fflush(grabadora);
	    		}
			}
	    	close(sp_pipe[0]);
	    	fprintf(grabadora,"Cerrando script....\n");
	    	fclose(grabadora);
	    	fflush(stdout);
	    	exit(1);
		}
		else
		{
			bitacora = fopen(BIT_PATH,"a");
			close(sp_pipe[0]);
			back_sterr = dup(STDERR_FILENO);
			back_stout = dup(STDOUT_FILENO); 
	    	dup2(sp_pipe[1],STDOUT_FILENO);  
	    	dup2(sp_pipe[1],STDERR_FILENO); 
	    	close(sp_pipe[1]);
		}
	}
	return 1;
}

char **parseo(char *linea)
{
	int pos = 0;
	char **tokens = malloc(MAX_ARGS * sizeof(char *));
	char *token;
	newLine=1;
	do{}while(newLine && !isChild);
	if(!tokens)
	{
		fprintf(stderr, "bam: no se pudo reservar memoria\n");
        exit(EXIT_FAILURE);
	}
	token = strtok(linea,LIMITADORES);
	while(token != NULL)
	{
		tokens[pos] = token;
		pos++;
		if(pos>=MAX_ARGS)
		{
			fprintf(stderr, "bam: excedido el numero maximo de argumentos\n");
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
	fflush(stdout);
	if(!isChild)	fclose(bitacora);
	if((pid = fork())==0)
	{
		
		execvp(linea_parse[0], linea_parse);
		perror("bam");
		exit(0);
	}
	else if(pid<0)	perror("bam"),exit(0);
	else	waitpid(pid,&estado,WUNTRACED);
	if(!isChild) bitacora = fopen(BIT_PATH,"a");
	if(!bitacora)	perror("bam");
	return 1;
}

int ejecutar(char **linea_parse)
{
	int i,j=0;
	if(linea_parse[0]==NULL)	return 1;
	for(i=0;i<MAX_ARGS;i++)
		for(j=0;j<cuantasPipe();j++)
		{
			if(linea_parse[i]==NULL)	i=MAX_ARGS,j=cuantasPipe();
			else if (strcmp(linea_parse[i],pipedel[j])==0)
			{
				return(*pipefunc[j])(linea_parse,i);
			}
		}
	
	for(i=0;i<cuantasFunciones();i++)
	{
		if(strcmp(linea_parse[0],nuestros[i])==0)
			return(*funciones[i])(linea_parse);
	}	
  	return correr(linea_parse);
}

void loop()
{
	char **linea_parse;
	size_t lon = 0;
	signal(29, veintinueve);
	signal(30, treinta);
	signal(31, treintauno);
	do {
		printf("%s ",prompt);
		fflush(stdout);
		linea = (char*)NULL;
		getline(&linea,&lon,stdin);
		linea_parse = parseo(linea);
		estado = ejecutar(linea_parse);
		free(linea);
		free(linea_parse);
	}while(estado);
}

void *histhread(void *args)
{
	bitacora = fopen(BIT_PATH,"a");
	if(!bitacora)	perror("bam");
	time_t rawtime;
 	struct tm * timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	fprintf (bitacora,"Fecha y Hora: %s", asctime(timeinfo));
	do{
		if(newLine && !isChild)
		{
			if(scripting)q
			{
				fprintf(stdout, "%c%s%c", INPUT_CTRL,linea,INPUT_CTRL);
				fflush(stdout);
			}
			fprintf(bitacora, "%s", linea);
			newLine=0;
		}
	}while(estado);
	fclose(bitacora);
}

void veintinueve()
{
	strcpy(prompt,"=D");
}

void treinta()
{
	strcpy(prompt,"=P");
}

void treintauno()
{
	strcpy(prompt,"O.o");
}

int main(int argc, char const *argv[])
{
	prompt=malloc(sizeof(char)*3);
	strcpy(prompt,"¬");
	system("clear");
	if(pthread_create(&his_thread, NULL, histhread, NULL))	perror("bam");
	loop();
	if(pthread_join(his_thread, NULL))	perror("bam");
	free(prompt);
	return 0;
}
