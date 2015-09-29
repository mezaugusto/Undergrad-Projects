#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define LIMITADORES " \t\r\n\a"

int micd(char **args);
int miayuda(char **args);
int misalida(char **args);

char *nuestros[] = {"cd","ayuda","salir"};
int (*funciones[]) (char **) = {&micd,&miayuda,&misalida};
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
	printf("\t\tBAM Shell\n");
	printf("Programado por Augusto Meza y Rosa Maria Yolotzin Muñoz Alvarez\n");
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

char **parseo(char *linea)
{
	int pos = 0;
	char **tokens = malloc(MAX_ARGS * sizeof(char *));
	char *token;
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
	if((pid = fork())==0)
	{
		execvp(linea_parse[0], linea_parse);
		perror("bam");
	}
	else if(pid<0)	perror("bam");
	else	waitpid(pid,&estado,WUNTRACED);
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
	char *linea;
	char **linea_parse;
	size_t lon = 0;
	int estado;

	do {
		printf("¬ ");
		linea = (char*)NULL;
		getline(&linea,&lon,stdin);
		linea_parse = parseo(linea);
		estado = ejecutar(linea_parse);
		free(linea);
		free(linea_parse);
	}while(estado);
}

int main(int argc, char const *argv[])
{
	system("clear");
	loop();
	return 0;
}