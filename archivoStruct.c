#include <stdio.h>

struct provincias {
  char ciudadSalida[200];
  char ciudadLlegada[200];
  int distancia[200];
};
 
int main(){
  struct provincias ciudad;
  FILE *salida;
  
  salida = fopen("./muestra.txt", "rb");
  

  if(salida == NULL) { printf("No se pudo abrir el archivo... \n"); return -1; }
 
  // Escribimos 1 registro de tipo struct formulario
  fread(&ciudad, sizeof(struct provincia), 1, salida);
  
  printf("%s %s", ciudad.ciudadSalida"\n ", ciudad.ciudadLlegada"\n ");
  printf("A: %d", ciudad.distancia);
  
  return(0);
}