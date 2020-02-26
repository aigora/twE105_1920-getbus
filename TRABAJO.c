#include <stdio.h>
#include <string.h>
#include <math.h>
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

int PagoTarjeta (int copiatarjeta[]);

int main () {
	
	/*ENCABEZADO DEL PROGRAMA*/
	
	int i, j, codigo, naleatorio, tarjeta[DIM];
	char opcion;
	
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
	
	printf ("\nBienvenidx a FASTBUS. Introduzca alguna de las opciones:\n");
	
	printf ("M >> Mirar destinos\nC >> Comprar billetes\nR >> Registro de usuario (descuento de hasta el 10%%)\n\n");
	
	scanf ("%c", &opcion);
	
	switch (opcion) {
		
		case 'M':
			//LEE FICHERO CON LOS DESTINOS INCLUIDOS PRECIOS
			break;
			
		case 'C':
			//FUNCION PARA COMPRA DE BILLETES SOLO PAGO CON TARJETA
			printf ("Introduce tu numero de tarjeta numero a numero:\n");
			for (i = 0; i < DIM; i++) {
				scanf ("%d", &tarjeta[i]);
			}
				
			while (PagoTarjeta (tarjeta) == 0); {
			    printf ("ERROR. Algun numero introducido no es positivo\n");
			    for (i = 0; i < DIM; i++) {
				scanf ("%d", &tarjeta[i]);
			    }
			}
		
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
			
		default:
		   
		    while (opcion != 'M' && opcion != 'C' && opcion != 'R') {
		    	
		    	getchar();
		    	printf ("ERROR. LA OPCION INTRODUCIDA NO ES VALIDA\n");
		        scanf ("%c", &opcion);

			}
		        //CUANDO SEA ALGUNO DE LOS CARACTERES LLAMAMOS A LA FUNCION DE CADA CASO
	
		    break;
	}

	return 0;
}

void registro (char n) {
	//COMPRUEBA SI YA ESTAS REGISTRADO Y ADEMAS SI TU NUMERO TIENE 9 CIFRAS
	int i, longitud;
	
	//EL PROGRAMA NO DEJA REGISTRARTE HASTA QUE VERIFIQUES QUE NO ERES UN ROBOT
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

int PagoTarjeta (int copiatarjeta[]) {
	/*COMPRUEBA QUE LOS NUMEROS INTRODUCIDOS NO SON NEGATIVOS*/
	int i, contador = 0;
	for (i = 0; i < DIM; i++) {
		if (copiatarjeta[i] < 0)
		    contador++;
	}
	
	if (contador != 0)
	    return 0;
	else 
	    return 1;
}



