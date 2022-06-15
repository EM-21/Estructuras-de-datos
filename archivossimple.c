#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

main()
{
        FILE *archivoCiudades;
        char ciudades;
        int distanciaRecorrida;

        archivoCiudades = fopen("muestra.txt","r");
        if (archivoCiudades == NULL){
                printf("No se logro abrir el archivo.\n" );
                exit(1);

        }


        printf("Ciudades Disponibles: \n" );
        ciudades = getc(archivoCiudades);
        while (feof(archivoCiudades) == 0) {
                printf("%c",ciudades);
                ciudades = getc(archivoCiudades);

        }

        if (fclose(archivoCiudades) != 0)
        printf("Problema cerrando el archivo");



}
