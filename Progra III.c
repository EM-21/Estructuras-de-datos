#include <stdio.h>
#include <stdlib.h>
#define ciudad struct ciudad
#define arista struct arista
#define lista struct lista
#define lista_resultado struct lista_resultado
#define nodo struct nodo


ciudad{

	int dato;
	ciudad*siguiente;
	arista*adyacencia;
	int visitado,terminado;
	int distancia;
	int anterior;
};

arista{
	ciudad*vertice;
	arista*siguiente;
	int distancia_interna;
};

lista{
	ciudad*dato;
	lista*siguiente;
};

lista_resultado {
    ciudad* inicio;
    ciudad* siguiente;
};

nodo { //nodo es el nombre de la estructura
    int valor;
    nodo *sig; //El puntero siguiente para recorrer la lista enlazada
}; //tnodo es el tipo de dato para declarar la estructura

typedef nodo *tpuntero; //Puntero al tipo de dato tnodo para no utilizar punteros de punteros


ciudad*inicio=NULL;
lista*ini=NULL;
lista*final=NULL;

lista_resultado *resultados = NULL;


void insertar_ciudad(int dato){

    ciudad* aux;
	ciudad* nuevo=(ciudad*)malloc(sizeof(ciudad));
	nuevo->dato = dato;
	nuevo->siguiente=NULL;
    nuevo->adyacencia=NULL;
    nuevo->visitado=nuevo->terminado=0;
    nuevo->distancia=-1;
    nuevo->anterior=0;
    if(inicio==NULL){
        inicio=nuevo;
    }else{
        aux=inicio;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
      }

 }


void agregar_arista(ciudad* aux, ciudad* aux2, arista* nuevo){
    arista* a;
    if(aux->adyacencia==NULL){
	    aux->adyacencia=nuevo;
        nuevo->vertice=aux2;
    }else{
	    a=aux->adyacencia;
        while(a->siguiente!=NULL)
            a=a->siguiente;
        nuevo->vertice=aux2;
        a->siguiente=nuevo;
    }
}


void insertar_Arista(int ini, int fin, int distancia_interna){

    arista* nuevo=(arista*)malloc(sizeof(arista));
    nuevo->siguiente=NULL;
    ciudad* aux;
	ciudad* aux2;
    if(inicio==NULL){
         printf("Error: El grafo está vacio\n");
         return;
    }

    nuevo->distancia_interna = distancia_interna;

    aux=inicio;
    aux2=inicio;
    while(aux2!=NULL){
        if(aux2->dato==fin){
            break;
        }
        aux2=aux2->siguiente;
    }
    if(aux2==NULL){
    	printf("Error:Vertice no encontrado\n");
    	return;
	}
    while(aux!=NULL){
        if(aux->dato==ini){
            agregar_arista(aux,aux2,nuevo);
            return;
        }
        aux = aux->siguiente;
    }
    if(aux==NULL)
    	printf("Error:Vertice no encontrado\n");
}

void visualizar_grafo(){
    ciudad*aux=inicio;
    arista* ar;
    printf("ciudads\n");
    while(aux!=NULL){
	    printf("%i:    ",aux->dato);
        if(aux->adyacencia!=NULL){
            ar=aux->adyacencia;
            while(ar!=NULL){
			    printf(" %i",ar->vertice->dato);
                ar=ar->siguiente;
            }
        }
        printf("\n");
        aux=aux->siguiente;
    }
    printf("\n");
}

void insertar_pila(ciudad* aux){
	lista*nuevo=(lista*)malloc(sizeof(lista));
	nuevo->dato=aux;
	nuevo->siguiente=NULL;
	if(ini==NULL){
		ini=nuevo;
		final=nuevo;
	}else{
	   nuevo->siguiente=ini;
	   ini=nuevo;
	}
}


ciudad*extraer(){
	lista*aux;
	//printf("%i", ini->dato->dato);
	if(ini==NULL){
		return NULL;
	}else{
		aux=ini;
		ini=ini->siguiente;
		aux->siguiente=NULL;
		if(ini==NULL)
		final=NULL;
	}
	ciudad*resultado=aux->dato;
	free(aux);
	return resultado;
}

void reiniciar(){
	if(inicio!=NULL){
		ciudad*aux=inicio;
		while(aux!=NULL){
			aux->visitado=aux->terminado=0;
		    aux=aux->siguiente;
		}
	}
}


void insertar_en_lista (tpuntero *cabeza, int e){
    tpuntero nuevo;
    nuevo = malloc(sizeof(nodo));
    nuevo->valor = e;
    nuevo->sig = *cabeza;
    *cabeza = nuevo;
}

void imprimirLista(tpuntero cabeza){
    while(cabeza != NULL){

    if(cabeza->valor != 0){
        if(cabeza->valor < 5){
            printf("Bicicleta\n");
    }else{
        printf("Carro\n");
        }

    }
    cabeza = cabeza->sig;
    }
}

void imprimirLista_dos(tpuntero cabeza){
    while(cabeza != NULL){
        printf(" Ciudad %i \n", cabeza->valor);
    cabeza = cabeza->sig;
    }
}



void calcular_ruta(int a, int b){

    tpuntero cabeza;
    cabeza = NULL;
    
    tpuntero cabeza_dos;
    cabeza_dos = NULL;

	ciudad*aux=inicio;

	while(aux!=NULL){
		if(aux->dato==a){
			aux->terminado=1;
			aux->distancia=0;
			break;
		}
		aux=aux->siguiente;
	}
	if(aux==NULL){
		printf("Vertice no encontrado\n");
		return;
	}
	while(aux!=NULL){
		arista*a=aux->adyacencia;
	    while(a!=NULL){
		    if(a->vertice->distancia==-1 || (aux->distancia+a->distancia_interna)<a->vertice->distancia){
		    	a->vertice->distancia=aux->distancia+a->distancia_interna;
		        a->vertice->anterior=aux->dato;
			}
		    a=a->siguiente;
	    }
	    aux=inicio;
	    ciudad*min=inicio;
	    while(min->anterior==0 || min->terminado ==1)
	    min=min->siguiente;
	    while(aux!=NULL){
	    	if(aux->distancia<min->distancia && aux->terminado==0 && aux->anterior!=0)
	    	min=aux;
	    	aux=aux->siguiente;
		}
		aux=min;
		aux->terminado=1;
		if(aux->dato==b)
		break;
	}
	while(aux->anterior!=0){
		insertar_pila(aux);
		int temp=aux->anterior;
		aux=inicio;
		while(aux->dato!=temp){
		   aux=aux->siguiente;
		}
	}
	insertar_pila(aux);
	int distancia_nueva = 0;
	printf("La ruta ideal para el viaje seleccionado es la siguiente: \n\n");
	while(ini!=NULL){

	    ciudad *nodo_ciudad = extraer();


	    int distancia_actual = (nodo_ciudad->distancia) - distancia_nueva;
	    //printf(" Ciudad %i \n", nodo_ciudad->dato);
        insertar_en_lista (&cabeza_dos, nodo_ciudad->dato);
        insertar_en_lista (&cabeza, distancia_actual);
        distancia_nueva = nodo_ciudad->distancia;
	}
	    //imprimirLista_dos(cabeza_dos);
        printf("\nCon los siguientes medios de transporte: \n\n");

	    imprimirLista(cabeza);
		printf("\n");
	    reiniciar();
}


int main(){

    insertar_ciudad(1);
    insertar_ciudad(2);
    insertar_ciudad(3);
    insertar_ciudad(4);
    insertar_ciudad(5);
    insertar_ciudad(6);
    insertar_ciudad(7);

    visualizar_grafo();


    insertar_Arista(1, 3, 25);
    insertar_Arista(3, 2, 2);
    insertar_Arista(3, 7, 54);
    insertar_Arista(2, 5, 67);
    insertar_Arista(4, 6, 87);
    insertar_Arista(2, 7, 4);


    calcular_ruta(1, 7);
    
    calcular_ruta(3, 7);

}