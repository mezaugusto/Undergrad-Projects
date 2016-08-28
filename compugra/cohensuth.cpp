#include <stdio.h>
#include <stdlib.h>
#define dimensions 2

int defineRegion(float x, float y, float* window)
{
	float a,b,c,d;
	int region = 0;
	// Lower left point
	a = window[0];
	b = window[1];
	// Upper right point
	c = window[2];
	d = window[3];
	if (x <= a)			region += 8;
	else if (x >= c)	region += 4;
	if (y >= d)			region += 2;
	else if (y <= b)	region += 1;
	return region;
}


char* cohensuth(float* window,float* line)
{
	int reg1,reg2;
	char* result;
	reg1 = defineRegion(line[0],line[1],window);
	reg2 = defineRegion(line[2],line[3],window);
	if ((reg1 | reg2) == 0) result = "dibuja";
	else if((reg1 & reg2) == 0) result = "recorta";
	else result = "descarta";
	return result;
}

int main(){
	float *window,*line;
	window = (float*)calloc(dimensions*2,sizeof(float));
	line = (float*)calloc(dimensions*2,sizeof(float));
	window[0] = 5.0;
	window[1] = 2.0;
	window[2] = 9.0;
	window[3] = 7.0;
	line[0] = 6.0;
	line[1] = 3.0;
	line[2] = 8.0;
	line[3] = 6.0;
	printf("La linea de (%1.2f, %1.2f) a (%1.2f, %1.2f) se %s\n",line[0],line[1],line[2],line[3],cohensuth(window,line));
	return 0;
}