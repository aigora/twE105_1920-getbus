#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define N 11
#define M 101
#define DIM 16

//DEFINICION DE FUNCIONES Y DE ESTRUCTURAS

struct {
    char nombre[20];
    char apellidos[30];
    char telefono[15];
} cliente;

void registro (char n); 

int CompruebaRobot (int numero, int b);

int NumAleatorio (int a);

int main () {
	
	/*ENCABEZADO DEL PROGRAMA*/
	FILE *dest;
	int i, j, codigo, naleatorio, contador = 0, v[DIM], tarjeta[DIM], n = DIM-1;
    unsigned long long int numtarjeta;
	char opcion, car;
	
	do {
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (i == 0 || i == N - 1)
			    printf ("=");
			else if (j == 0 || j == M - 1)
			    printf ("+");
			else 
			    printf (" ");
		}
		printf ("\n");
	}
	
	/*MENU PRINCIPAL*/
	
	printf ("\nBienvenidx a GETBUS. Introduzca alguna de las opciones:\n");
	
	printf ("M >> Mirar destinos\nC >> Comprar billetes\nR >> Registro de usuario (descuento de hasta el 10%%)\nD >> Descuentos disponibles\n");
	printf ("S >> Servicio de comida y bebida\nA >> Disponibilidad de autobuses\n\n");
	
	scanf ("%c", &opcion);
	getchar();
	printf ("\n");
	
	switch (opcion) {
		
		case 'M':
			//LEE FICHERO CON LOS DESTINOS INCLUIDOS PRECIOS
			printf ("Autobuses con salida desde Madrid. Todos los precios en euros (ida y vuelta):\n\n");
			dest = fopen ("destinos.txt", "r");
			do {
				contador = fscanf(dest, "%c", &car);
				printf("%c", car);
			}
			while (contador != EOF);
	
			fclose (dest);
			
			break;
			
		case 'C':
			//FUNCION PARA COMPRA DE BILLETES SOLO PAGO CON TARJETA
			
			printf ("Introduce tu numero de tarjeta:\n");
        
            scanf ("%lld", &numtarjeta);
            i = 0;    
            while (numtarjeta > 0) {
            	
              v[i] = numtarjeta % 10;
              numtarjeta = numtarjeta / 10;
              i++;
			}
			
			printf ("Tu numero de tarjeta es:\n");
			
			for (i = 0; i < DIM; i++) {
			    	
			  tarjeta[i] = v[n];
			  printf ("%d ", tarjeta[i]);
			  n--;
		      }
		
			printf ("\n\n");
		
			break;
			
		case 'R':
			
			//FUNCION REGISTRO DE USUARIO USO DE ESTRUCTURAS (FUNCION COMPRUEBA ROBOT FUNCION SRAND)
			naleatorio = NumAleatorio(1);
	        printf ("Verificacion de codigo: %d\n", naleatorio);
			scanf ("%d", &codigo);
			getchar();
			
			while (CompruebaRobot (codigo, naleatorio) != 1) {
			
				printf ("Introduce de nuevo el codigo: %d\n");
			    scanf ("%d", &codigo);
			    getchar();
			}
			
		    printf ("Introduce tu nombre, apellidos y numero de telefono\n");
			//LLAMADA A LA FUNCION si y solo si no eres un robot
			registro (opcion);
			    
			break;
			
		case 'D':
			
			/*FICHERO CON LOS DESCUENTOS DISPONIBLES*/
			
			
			
			
		    break;
		    
		case 'S':
			
			/*EL CLIENTE PODRA ELEGIR LOS COMPLEMENTOS QUE DESEE SEGUN LA OPCION ESCOGIDA*/
			
			
			
			break;
			
		case 'A':
			
			//FICHERO EN EL CUAL APARECERAN EL NUMERO DE PLAZAS DISPONIBLES
			
			
			break;
			
		default:
		
		   printf ("ERROR. LA OPCION INTRODUCIDA NO ES VALIDA\n\n");
		   
	       break;
	}

}

while (1);
	
	return 0;
}

void registro (char n) {
	//COMPRUEBA SI YA ESTAS REGISTRADO Y ADEMAS SI TU NUMERO TIENE 9 CIFRAS
	int i, longitud;
	
	scanf ("%s", cliente.nombre);
	getchar();
	gets (cliente.apellidos);
	scanf ("%s", cliente.telefono);
	longitud = strlen (cliente.telefono);
		
	while (longitud != 9) {
	    printf ("ERROR. Tu numero no tiene 9 cifras\n");
	    scanf ("%s", cliente.telefono);
	    longitud = strlen (cliente.telefono);
	}

	//FALTAN COSAS
}

int NumAleatorio (int a) {
	
	int num;
	srand (time(0)); /*GENERADOR NUMERO ALEATORIO*/
    num = rand()%50001;
    
	return num;
}

int CompruebaRobot (int numero, int b) {

	if (numero == b) 
		return 1;
	else 
	    return 0;
	
}




