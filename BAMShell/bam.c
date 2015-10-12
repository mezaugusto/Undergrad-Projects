/*********************************************************************
* Para Compilar: gcc -pthread bam.c                                  *
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //FORK
#include <string.h> //STRCPY,STRCMP
#include <time.h>	
#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>
#include <fcntl.h>
/**************************
*       				  *
*   CONSTANTES GLOBALES   *
*       				  *
**************************/
#define MAX_ARGS 64				//Numero maximo de argumentos por linea
#define LIMITADORES " \t\r\n\a" //Separadores de Argumentos
#define INPUT_CTRL	11			//Script: char que separa los comandos
#define BIT_PATH "/bitacora"    //Paths para la grabadora y la bitacora
#define GRA_PATH "/grabadora"
/**************************
*       				  *
*   VARIABLES GLOBALES    *
*       				  *
**************************/	
FILE *bitacora;
char *linea;
char *prompt;
/**************************************
*       				              *
* VARIABLES Y FUNCIONES PARA EL HILO  *
*       				              *
**************************************/
pthread_t his_thread;
void *histhread(void *args);
/**************
*       	  *
*  BANDERAS   *
*       	  *
**************/
int estado=1,newLine=0,scripting=0,isChild=0,back_stout,back_sterr;
/*********************************************
*       				  					 *
*   DECLARACION DE LOS OPERADORES PROPIOS    *
*       				  					 *
*********************************************/
int cuantasPipe();
int mipipe(char **args,int i);
int mireds(char **args,int i);
int mirede(char **args,int i);
int mired2(char **args,int i);
char *pipedel[] = {"|",">","<","2>"};
int (*pipefunc[]) (char **,int i) = {&mipipe,&mirede,&mireds,&mired2};
/*********************************************
*       				  					 *
*    DECLARACION DE LAS FUNCIONES PROPIAS    *
*       				  					 *
*********************************************/
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
/*********************************************
*       				  					 *
*   DECLARACION DE LAS FUNCIONES DE PARSEO   *
*       				  					 *
*********************************************/
int correr(char **linea_parse);
char **parseo(char *linea);
int ejecutar(char **linea_parse);
void loop();
/*********************************************
*       				  					 *
*     DECLARACION DE LAS FUNCIONES CATCH     *
*       				  					 *
*********************************************/
void veintinueve();
void treinta();
void treintauno();
/*********************************************
*       				  					 *
*     IMPLEMENTACION DE LOS OPERADORES       *
*       				  					 *
*********************************************/
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
    if(!isChild) //Si es hijo la bitacora ya esta cerrada
    {
    	fclose(bitacora);
    	isChild=isChild?0:1;
    }
    if((pid = fork()) == 0){ // codigo del hijo
    	close(1);
        close(p[0]); 
        dup2(p[1],1);
        close(p[1]);
        ejecutar(args1);
        exit(EXIT_SUCCESS);
    }else{ // codigo del padre
   		if((pid2 = fork()) == 0){ // codigo del hijo 
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
    if((pid = fork()) == 0){ // codigo del hijo
    	close(1);
        close(p[0]); 
        dup2(p[1],1);
        close(p[1]);
        ejecutar(args1);
        exit(EXIT_SUCCESS);
    }else{ // codigo del padre  
   		if((pid2 = fork()) == 0){ // codigo del hijo 
	        close(0);
	        close(p[1]); 
           	a = open(args2[0],O_WRONLY | O_CREAT | O_TRUNC,0644);
           	while((readbytes = read(p[0],buffer,FILENAME_MAX)) > 0)
	            write(a,buffer,readbytes); //se escribe en el archivo
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
    if((pid = fork()) == 0){ // codigo del hijo
    	close(0);
        close(p[1]); 
        dup2(p[0],0);
        close(p[0]);
        ejecutar(args1);
        exit(EXIT_SUCCESS);
    }else{ // codigo del padre  
   		if((pid2 = fork()) == 0){ // codigo del hijo 
	        close(1);
	        close(p[0]); 
           	a = open(args2[0],O_RDONLY,0644);
           	while((readbytes = read(a,buffer,FILENAME_MAX)) > 0)
	            write(p[1],buffer,readbytes); //se escribe en el archivo
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
    if((pid = fork()) == 0){ // codigo del hijo
    	close(2);
        close(p[0]); 
        dup2(p[1],2);
        close(p[1]);
        ejecutar(args1);
        exit(EXIT_SUCCESS);
    }else{ // codigo del padre  
   		if((pid2 = fork()) == 0){ // codigo del hijo 
	        close(0);
	        close(p[1]); 
           	a = open(args2[0],O_WRONLY | O_CREAT | O_TRUNC,0644);
           	while((readbytes = read(p[0],buffer,FILENAME_MAX)) > 0)
	            write(a,buffer,readbytes); //se escribe en el archivo
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
/*********************************************
*       				  					 *
*     IMPLEMENTACION DE LAS FUNCIONES        *
*       				  					 *
*********************************************/
int cuantasFunciones()
{
	return sizeof(nuestros)/sizeof(char*);
}

int micd(char **args)
{
	if(args[1] == NULL)
		fprintf(stderr, "bam:\"cd\" requiere 1 argumento\n");
	else
		if(chdir(args[1]) != 0)	perror("bam");//cambia al directorio en cuestion, es el cd del sistema
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
    if((pid = fork()) == 0){ // codigo del hijo 
        close(p[1]); // cerramos escritura
        a = open(args[1],O_WRONLY | O_CREAT | O_TRUNC,0644); // se abre el archivo con sus respectivos modificadores de acceso y regresa su fd
        while((readbytes = read(p[0],buffer,FILENAME_MAX)) > 0){ //se lee el buffer, por bloques de tamaño FILENAME_MAX
            write(a,buffer,readbytes); //se escribe en el archivo
            write(1,buffer,readbytes); // se escribe en la terminal stdout
        }
        close(a); // cerramos flujos
        close(p[0]);
        exit(EXIT_SUCCESS);
    }else{ // codigo del padre
        close(p[0]); //cerramos lectura
        while(!feof(stdin)){
            buffer = (char*)NULL;
            getline(&buffer,&lon,stdin); 
            write(p[1],buffer,strlen(buffer)); // se escribe en la tuberia
        }
        close(p[1]); // cerramos flujos
        bitacora = fopen(BIT_PATH,"a");
    	isChild=isChild?0:1;
    }
    waitpid(pid,NULL,0); // se espera al hijo 
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
		fflush(stdout);//Vaciar el buffer de salida
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
			{//INPUT_CTRL es el caracter que me indica que lo que sigue es el comando
				if(c==INPUT_CTRL)	noprint=noprint?0:1;
				else
				{
					fputc(c,grabadora);
	    			if(!noprint)putchar(c);//para no imprimir dos veces el comando
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
			back_sterr = dup(STDERR_FILENO);//Hago un respaldo de stdout y stderr 
			back_stout = dup(STDOUT_FILENO); 
	    	dup2(sp_pipe[1],STDOUT_FILENO);  
	    	dup2(sp_pipe[1],STDERR_FILENO); 
	    	close(sp_pipe[1]);
		}
	}
	return 1;
}
/*********************************************
*       				  					 *
* IMPLEMENTACION DE LAS FUNCIONES DE PARSEO  *
*       				  					 *
*********************************************/
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
		getline(&linea,&lon,stdin);//Funcion que lee hasta un salto de linea o retorno de carro, del stdin
		linea_parse = parseo(linea);
		estado = ejecutar(linea_parse);
		free(linea);
		free(linea_parse);
	}while(estado);
}
/*********************************************
*       				  					 *
*           FUNCIONES DE LOS HILOS           *
*       				  					 *
*********************************************/
void *histhread(void *args)
{
	bitacora = fopen(BIT_PATH,"a");
	if(!bitacora)	perror("bam");
	time_t ti_sinf; //variable de la estructura del tiempo
 	struct tm * timeinfo; // estructura de la informacion del tiempo
	time(&ti_sinf);//guarda el tiempo sin formato
	timeinfo=localtime(&ti_sinf); //lo cambia al tiempo local
	fprintf (bitacora,"Fecha y Hora: %s", asctime(timeinfo));//imprime el tiempo
	do{
		if(newLine && !isChild) // si llego una nueva linea y no es hijo
		{
			if(scripting)// si esta en modo script pone los limites
			{
				fprintf(stdout, "%c%s%c", INPUT_CTRL,linea,INPUT_CTRL);
				fflush(stdout);
			}
			fprintf(bitacora, "%s", linea);// imprime la linea a la bitacora
			newLine=0;
		}
	}while(estado);//Mientras el programa corra
	fclose(bitacora);
	return NULL;
}
/*********************************************
*       				  					 *
*       FUNCIONES CATCH DE LAS SEÑALES       *
*       				  					 *
*********************************************/
void veintinueve()
{
	strcpy(prompt,"=D"); // reemplaza prompt con lo que hay en el segundo argumento
}

void treinta()
{
	strcpy(prompt,"=P");
}

void treintauno()
{
	strcpy(prompt,"O.o");
}
/**************************
*       				  *
*  	PROGRAMA PRINCIPAL    *
*       				  *
**************************/
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
