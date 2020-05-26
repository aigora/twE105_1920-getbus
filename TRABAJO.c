#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 11
#define M 101
#define DIM 16
#define A 50 //NUMERO DE PLAZAS DE CADA BUS
#define B 8 //NUMERO DE BUSES

//DEFINICION DE FUNCIONES Y DE ESTRUCTURAS

typedef struct {
	int plaza[A];
	float precio;
} autobuses;

struct {
    char nombre[100];
    char telefono[15];
} cliente;

void registro (char op);

void guardaplaza (int v[B]);

int CompruebaBus (int v[B], int opcion);

int CompruebaPlaza (int v[B], int opcion);

void leerfichero(char nombreFich[]); 

int CompruebaRobot (int numero, int b);

int NumAleatorio (int a);

void imprime (int v[B]);

int LlenaPlazas (autobuses bus, int opcion, int nplazas);

int comida (autobuses bus, int eleccion);

int main () {
	
	/*ENCABEZADO DEL PROGRAMA*/
	FILE *dest;
	FILE *buses;
	
	int i, j, codigo, naleatorio, contador = 0, v[DIM], tarjeta[DIM], n = DIM-1, op, nplazas, fin, disponibles, vec[B], notarjeta = 0, cont;
	float precio = 0;
	unsigned long long int numtarjeta;
	char opcion, car, nombreFich[N];
	
	autobuses bus[B] = {0, 0, 0, 0, 0, 0, 0, 0}; //VECTOR DE ESTRUCTURAS INICIALIZADO PARA EVITAR ERRORES
	
	do {
	system("cls");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (i == 0 || i == N - 1)
			    printf ("=");
			else if (j == 0 || j == M - 1)
			    printf ("+");
			else if (j == M - 19 && i == 5) {
				printf ("+");
			}
			else if (i == 5 && j == 40) {
				printf ("BIENVENIDO A GETBUS");
			}
			else 
			    printf (" ");
		}
		printf ("\n");
	}
	
	/*MENU PRINCIPAL*/
	
	printf ("\nBienvenidx a GETBUS. Introduzca alguna de las opciones:\n");
	
	printf ("M >> Mirar destinos\nC >> Comprar billetes\nR >> Registro de usuario (descuento de hasta el 10%%)\nD >> Descuentos disponibles\n");
	printf ("S >> Servicio de comida y bebida\n\n");
	
	scanf ("%c", &opcion);
	getchar();
	printf ("\n");
	
	switch (opcion) {
		
		case 'M':
		case 'm':
			//LEE FICHERO CON LOS DESTINOS INCLUIDOS PRECIOS
			system("cls");
			
			printf ("Autobuses con salida desde Madrid. Todos los precios en euros (ida y vuelta):\n\n");
			dest = fopen ("destinos.txt", "r");
			do {
			  contador = fscanf(dest, "%c", &car);
			  printf("%c", car);
			}
			while (contador != EOF);
	
			fclose (dest);
			system("PAUSE");
			
			break;
			
		case 'C':
		case 'c':
			//FUNCION PARA COMPRA DE BILLETES SOLO PAGO CON TARJETA
			system("cls");
			
			printf ("Autobuses con salida desde Madrid. Todos los precios en euros (ida y vuelta):\n\n");
			dest = fopen ("destinos.txt", "r");
			do {
			  contador = fscanf(dest, "%c", &car);
			  printf("%c", car);
			}
			while (contador != EOF);
	
			fclose (dest);
			
			printf ("Selecciona donde quieres ir\n");
			
			scanf ("%d", &op);
			getchar();
			
			switch (op) {
				
				case 1:
					
					printf ("Madrid-Sevilla\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n", vec[op-1]);
					
					i = CompruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n");
					
					nplazas = CompruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*27.99; //CANTIDAD A PAGAR POR EL USUARIO (SOLO TICKETS)
					
					cont = LlenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont); //MODIFICO EL NUMERO DE PLAZAS LIBRES
					
					imprime (vec);
					
					printf ("El total a pagar es de %.2f euros. Quedan %d plazas\n", bus[op-1].precio, vec[op-1]);
					
					system("Pause");
					getchar();
					
				break;
				
				case 2:
				
				    printf ("Madrid-Malaga\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n", vec[op-1]);
					
					i = CompruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n");
					
					nplazas = CompruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*34; 
						
					cont = LlenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("El total a pagar es de %.2f euros. Quedan %d plazas\n", bus[op-1].precio, vec[op-1]);
 				    
				break;
				
				case 3:
					
					printf ("Madrid-Murcia\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n", vec[op-1]);
					
					i = CompruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n");
					
					nplazas = CompruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*34.70; 
						
					cont = LlenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("El total a pagar es de %.2f euros. Quedan %d plazas\n", bus[op-1].precio, vec[op-1]);
					
				break;
				
				case 4:
			
					printf ("Madrid-Valencia\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n", vec[op-1]);
					
					i = CompruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n");
					
					nplazas = CompruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*28.50;
						
					cont = LlenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("El total a pagar es de %.2f euros. Quedan %d plazas\n", bus[op-1].precio, vec[op-1]);
					
				break;
				
				case 5:
					
					printf ("Madrid-Barcelona\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n", vec[op-1]);
					
					i = CompruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n");
					
					nplazas = CompruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*35.50;
					
					cont = LlenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("El total a pagar es de %.2f euros. Quedan %d plazas\n", bus[op-1].precio, vec[op-1]);
				
				break;
				
				case 6:
					
					printf ("Madrid-Zaragoza\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n", vec[op-1]);
					
					i = CompruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n");
					
					nplazas = CompruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*24.20;
						
					cont = LlenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("El total a pagar es de %.2f euros. Quedan %d plazas\n", bus[op-1].precio, vec[op-1]);
						
				break;
				
				case 7:
					
					printf ("Madrid-Bilbao\n");
					
					notarjeta = 0;
										
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n", vec[op-1]);
					
					i = CompruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n");
					
					nplazas = CompruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*31.99;
		
					cont = LlenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("El total a pagar es de %.2f euros. Quedan %d plazas\n", bus[op-1].precio, vec[op-1]);
					
				break;
				
				case 8:
					
					printf ("Madrid-A Coruna\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n", vec[op-1]);
					
					i = CompruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n");
					
					nplazas = CompruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*29.99;
						
					cont = LlenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("El total a pagar es de %.2f euros. Quedan %d plazas\n", bus[op-1].precio, vec[op-1]);
					
					fclose (buses);
					
				break;
				
				default:
					
					printf ("ERROR. El numero introducido no coincide con ningun autobus\n");
				    system ("Pause");
				break;
			}
			
			if ((notarjeta == 0) && (op >= 1 && op <= 8)) {
			
			printf ("Introduce tu numero de tarjeta:\n");
			
			scanf ("%llu", &numtarjeta);
			
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
			
			system ("Pause");
			getchar();
			}
		
			break;
			
		case 'R':
		case 'r':
			system("cls");
			//FUNCION REGISTRO DE USUARIO USO DE ESTRUCTURAS (FUNCION COMPRUEBA ROBOT FUNCION SRAND)
			naleatorio = NumAleatorio(1);
			printf ("Verificacion de codigo: %d\n", naleatorio);
			scanf ("%d", &codigo);
			getchar();
			
			system("cls");
			
			while (CompruebaRobot (codigo, naleatorio) != 1) {
				
			   printf ("Introduce de nuevo el codigo: %d\n");
			   scanf ("%d", &codigo);
			   getchar();
			}
			
			//LLAMADA A LA FUNCION REGISTRO
			registro (opcion);
			    
			break;
			
		case 'D':
		case 'd':
			system("cls");
			/*LEE FICHERO CON LOS DESCUENTOS DISPONIBLES*/
			leerfichero("descuentos.txt");
			
		    break;
		    
		case 'S':
		case 's':
			system("cls");
			/*EL CLIENTE PODRA ELEGIR LOS COMPLEMENTOS QUE DESEE SEGUN LA OPCION ESCOGIDA*/
			leerfichero("comida.txt");
					
			break;
			
		default:
			
		   printf ("ERROR. LA OPCION INTRODUCIDA NO ES VALIDA\n\n");
		   system("pause");
	       break;
	}

}

while (1);
	
	return 0;
}

void registro (char op) {
	//COMPRUEBA SI YA ESTAS REGISTRADO Y ADEMAS SI TU NUMERO TIENE 9 CIFRAS
	
	FILE *registro;
	
	int n = 100, encontrado = 0, longitud;
	
	char nom[n];
	
	registro = fopen ("registro.txt", "r");
	
	printf ("Introduce tu nombre y apellidos\n");
	
	gets (nom); 
	
	while (fgets (cliente.nombre, n, registro) != NULL) {
		
		if (strncmp(nom, cliente.nombre, strlen(nom)) == 0) {
			
			encontrado = 1;
		}
	}
	
	fclose (registro);
	
	if (encontrado == 1) {
	
	   printf ("Tu nombre y numero de telefono ya estan registrados\n\n");
	   system("pause");
	}
	
	else {
	
	registro = fopen ("registro.txt", "a");
	
	system("cls");
	
	printf ("Tu nombre no figura en el registro.\nRegistrate ahora %s:\n", nom);
	
	strncpy(cliente.nombre,nom, 100);
	
	system("pause");
	
	system("cls");
	
	printf ("Introduce un telefono de contacto\n");
	
	scanf ("%s", cliente.telefono);
		
	longitud = strlen (cliente.telefono);
			
	while (longitud != 9) {
			
	    printf ("ERROR. Tu numero no tiene 9 cifras\n");
		scanf ("%s", cliente.telefono);
		longitud = strlen (cliente.telefono);
	}
		
	fputs (cliente.nombre, registro);
		
	fprintf (registro, " ");
	
	fprintf (registro, "%s", cliente.telefono);
	
	fprintf (registro, "\n");
	
	fclose (registro);
	
	system("cls");
	
	printf("Gracias por registrarse en GETBUS. Utilizando el codigo 'BIENVENIDA' obtendra un 10 por ciento de descuento\n");
	
	system("pause");
	
	}
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

void imprime (int v[B]) {
	
	FILE *buses;
	
	int i;
	
	buses = fopen ("buses.txt", "w");
	
	for (i = 0; i < B; i++) {
		
		fprintf (buses, "%d\n", v[i]);
	}
	
	fclose (buses);
}



/*void leerfichero(char nombreFich[]){
	FILE *lee;
	char texto;
	int contador=0;
	lee = fopen (nombreFich, "r");
			do {
			  contador = fscanf(lee, "%c", &texto);
			  printf("%c", texto);
			}
			while (contador != EOF);
	
			fclose (lee);
			
		system("PAUSE");
}*/




void leerfichero(char nombreFich[]){
	
	FILE *lee;
	char texto[10][100];
	int num[10], i=0;

	lee = fopen (nombreFich, "r");
	
	if(lee == NULL){
		printf("El fichero no se ha abierto correctamente...\n");
	}
	else{
	
	   while(fscanf(lee," %s %d", texto[i], &num[i]) != EOF){
	        printf("%s - %d\n", texto[i], num[i]);
			i++;
		}
    }
	fclose(lee);
			
	system("PAUSE");
}

void guardaplaza (int v[B]) { //ABRE EL FICHERO DE PLAZAS DE CADA BUS Y LO GUARDA EN UN VECTOR
	
	FILE *buses;
	
	int i = 0, fin, disponibles;
	
	buses = fopen ("buses.txt", "r");
	
	fin = fscanf (buses, "%d", &disponibles);
	
	while (fin != EOF) {
	
	   v[i] = disponibles;
	   i++;
	   fin = fscanf (buses, "%d", &disponibles);
	}
	fclose (buses);
}

int CompruebaPlaza (int v[B], int opcion) {
	
	int nplazas;
	
	scanf ("%d", &nplazas);

    while (nplazas > v[opcion-1]) {

       printf ("Lo sentimos, el numero introducido es mayor que el numero de plazas disponibles. Intentalo de nuevo\n");
       scanf ("%d", &nplazas);
   }
   return nplazas;	
}

int CompruebaBus (int v[B], int opcion) {
	
	int lleno = 0;

    if (v[opcion-1] == 0) {
    	
	   lleno = 1;
	}
	return lleno;
}

int LlenaPlazas (autobuses bus, int opcion, int nplazas) {
	
	int i, contador = 0;
	
	for (i = 0; i < nplazas; i++) {
	
	    bus.plaza[i] = 1;
	}
	
	for (i = 0; i < A; i++) { //CUENTA EL NUMERO DE PLAZAS QUE SE HAN A�ADIDO
	
	    if (bus.plaza[i] == 1) {
		
		    contador++;
		}
	}
	return contador;
}

int comida (autobuses bus, int eleccion) {
	
	
	
	
}

