using namespace std; 
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#define INPUT_FILE "input.txt"
#define MAX_LINES 3

/* El archivo de entrada debe tener un salto de linea al final de los puntos*/
int defineRegion(int x, int y, int* window){
	int a,b,c,d;
	int region = 0;
	a = window[0];
	b = window[1];
	c = window[2];
	d = window[3];
	if (x <= a)			region += 2;
	else if (x >= c)	region += 1;
	if (y >= d)			region += 8;
	else if (y <= b)	region += 4;
	return region;
}

char* cohenSuth(int* window,int* line){
	int reg1,reg2;
	char* result;
	reg1 = defineRegion(line[0],line[1],window);
	reg2 = defineRegion(line[2],line[3],window);
	if ((reg1 | reg2) == 0) result = "dibuja";
	else if((reg1 & reg2) == 0) result = "recorta";
	else result = "descarta";
	return result;
}

void readLines(int* window, char * filename){
	char ch;
	char str_point[11] = "";
	int step = 0;
	int lines = 0;
	int points = 0;
	int line[4];
	fstream fin(filename, fstream::in);
	while (fin >> noskipws >> ch) {
		if (ch == ' ' || ch == '\n') {
			char *substring = (char *)malloc((step + 1) * sizeof(char));;
			strncpy(substring, str_point, step);
			substring[step+1] = '\0';
			line[points] = (int)strtol(substring, (char **)NULL, 10);
			points++;
			step = 0;
			if (points == 4) {
				points = 0;
				lines++;
				if(lines<=MAX_LINES) printf("La linea de (%d, %d) a (%d, %d) se %s\n", line[0], line[1], line[2], line[3], cohenSuth(window, line));
			}
		}
		else {
			str_point[step] = ch;
			step++;
		}
	}
}

int* getWindow() {
	int* window = (int*)malloc(4 * sizeof(int));
	printf("\t\tPaso 1\nInserte el punto inferior izquierdo\nX: ");
	scanf("%d", &window[0]);
	printf("\nY: ");
	scanf("%d", &window[1]);
	printf("\n\t\tPaso 2\nInserte el punto superior derecho\nX: ");
	scanf("%d", &window[2]);
	printf("\nY: ");
	scanf("%d", &window[3]);
	system("cls");
	printf("\nResultado\n");
	for (size_t i = 0; i < 4; i++)
		if (window[i] < 0) {
			system("cls");
			printf("\nERROR: Los numeros deben ser enteros positivos.\n");
			return getWindow();
		}
	return window;
}

int main(){
	readLines(getWindow(),INPUT_FILE);
	system("pause");
	return 0;
}