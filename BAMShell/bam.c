#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAX_ARGS 64
#define LIMITADORES " \t\r\n\a"

FILE *bitacora;
char *linea;
int estado=1,changed=0,scripting=0,back_stout,back_sterr;
pthread_t his_thread,scr_thread;
int micd(char **args);
int miayuda(char **args);
int misalida(char **args);
int mihistory(char **args);
int miscript(char **args);
char *nuestros[] = {"cd","ayuda","salir","history","script"};
int (*funciones[]) (char **) = {&micd,&miayuda,&misalida,&mihistory,&miscript};

int cuantasFunciones()
{
	return sizeof(nuestros)/sizeof(char*);
}

char **parseo(char *linea)
{
	int pos = 0;
	char **tokens = malloc(MAX_ARGS * sizeof(char *));
	char *token;
	changed=1;
	do{}while(changed);
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
	fclose(bitacora);
	if((pid = fork())==0)
	{
		execvp(linea_parse[0], linea_parse);
		perror("bam");
		exit(0);
	}
	else if(pid<0)	perror("bam"),exit(0);
	else	waitpid(pid,&estado,WUNTRACED);
	bitacora = fopen("bitacora.txt","a");
	if(!bitacora)	perror("bam");
	return 1;
}

int ejecutar(char **linea_parse)
{
	int i;
	if(linea_parse[0]==NULL)	return 1;

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
	do {
		if(!scripting)printf("¬ ");
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
	time_t rawtime;
 	struct tm * timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	bitacora = fopen("bitacora.txt","a");
	if(!bitacora)	perror("bam");
	fprintf (bitacora,"Fecha y Hora: %s", asctime(timeinfo));
	do{
		if(changed)
		{
			if(scripting)	fprintf(stdout, "¬ %s", linea);
			fprintf(bitacora, "%s", linea);
			changed=0;		
		}
	}while(estado);
	fclose(bitacora);
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
	printf("\t\tBAM Shell\n");
	printf("Programado por Augusto Meza Peña y Rosa Maria Yolotzin Muñoz Alvarez\n");
	printf("Con codigo de Stephen Brennan's LSH https://github.com/brenns10/lsh\n");
	printf("Comandos del Shell\n");
	for (i = 0; i < cuantasFunciones(); i++)
    	printf("  %s\n", nuestros[i]);

    printf("Octubre - 2015, Facultad de Ingenieria UNAM\n");
    return 1;
}

int misalida(char **args)
{
	return 0;
}

int mihistory(char **args)
{
	char *hist[3] = {"cat","bitacora.txt",NULL};
	return correr(hist);
}

void *scrthread(void *args)
{
	char c;
	int sp_pipe[2];
	fclose(bitacora);
	pipe(sp_pipe);
	const pid_t pid = fork();
	if(!pid)
	{
		close(sp_pipe[1]);
		FILE *grabadora = fopen("grabadora","w");
		if(!grabadora) perror("bam");
		while(read(sp_pipe[0],&c,1) > 0) 
		{
    		putchar(c);
    		fputc(c,grabadora);
    		if(c=='\n') 
    		{
    			fflush(stdout);
    			fflush(grabadora);
    		}
		}
		putchar('\n');
    	close(sp_pipe[0]);
    	fclose(grabadora);
    	exit(1);
	}
	else
	{
		bitacora = fopen("bitacora.txt","a");
		close(sp_pipe[0]);
		back_sterr = dup(STDERR_FILENO);
		back_stout = dup(STDOUT_FILENO); 
    	dup2(sp_pipe[1],STDOUT_FILENO);  
    	dup2(sp_pipe[1],STDERR_FILENO); 
    	close(sp_pipe[1]);
	}
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
	}
	else
	{
		if(pthread_create(&scr_thread, NULL, scrthread, NULL))
		perror("bam");
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	if(pthread_create(&his_thread, NULL, histhread, NULL))
		perror("bam");
	system("clear");
	loop();
	if(pthread_join(his_thread, NULL))
		perror("bam");
	return 0;
}