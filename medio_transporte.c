#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define CARROC 16.79
#define BICIE 10
#define BICI 5


// 2 * (esfuerzo * distancia) > (carbono * distancia)
//(2 * (BICIE * distancia)) > (CARROC * distancia)
//((2 * (BICIE * distancia)) > (CARROC * distancia)

int distancia = 0;
int transporte = 0;


int medio(){
	
	if(distancia<=5){
		if((2 * (BICI * distancia)) < (CARROC * distancia)){
			transporte = 1;
			printf("salio en bici");
			return transporte;
		
		}
			 
			}else if(distancia > 5){
			
			if((2 * (BICIE * distancia)) > (CARROC * distancia)){
				transporte = 2;
				printf("Salio en carro");
			 return transporte;
				}
			
			}
return 0;			
}			
	



int main(){
	printf("Ingrese una distancia");
	scanf("%d", &distancia);
	medio(distancia);
	
	
	}





