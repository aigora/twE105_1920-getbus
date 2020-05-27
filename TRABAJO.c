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

int compruebaBus (int v[B], int opcion);

int compruebaPlaza (int v[B], int opcion);

void leerfichero(char nombreFich[]); 

int compruebaRobot (int numero, int b);

int numAleatorio (int a);

void imprime (int v[B]);

int llenaPlazas (autobuses bus, int opcion, int nplazas);

float comida (autobuses bus);

float descuentos (float total, char op);

int main () {
	
	/*ENCABEZADO DEL PROGRAMA*/
	FILE *dest;
	
	int i = 0, j, codigo, naleatorio, contador = 0, n = DIM-1, op, nplazas, disponibles, notarjeta = 0, cont;
	int v[DIM], tarjeta[DIM], vec[B], conf[4];
	float precio = 0, total;
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
	fflush (stdin);
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
			
			printf ("Selecciona donde quieres ir\n\n");
			
			scanf ("%d", &op);
			getchar();
			fflush (stdin);
			
			switch (op) {
				
				case 1:
					
					printf ("Madrid-Sevilla\n\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n\n", vec[op-1]);
					
					i = compruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n\n");
					
					nplazas = compruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*27.99; //CANTIDAD A PAGAR POR EL USUARIO (SOLO TICKETS)
					
					cont = llenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont); //MODIFICO EL NUMERO DE PLAZAS LIBRES
					
					imprime (vec);
					
					printf ("La cantidad a pagar es de %.2f euros. Quedan %d plazas\n\n", bus[op-1].precio, vec[op-1]);
					
					total = bus[op-1].precio + comida (bus[op-1]); //LLAMADA A LA FUNCION DE SERVICIO COMPLEMENTARIO
					
					printf ("El total a pagar es de %.2f euros\n\n", total); 
					
					printf ("La cantidad a pagar es de %.2f\n\n", descuentos (total, opcion)); //LLAMADA A LA FUNCION DESCUENTO
					
					fflush (stdin);
					
				break;
				
				case 2:
				
				    printf ("Madrid-Malaga\n\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n\n", vec[op-1]);
					
					i = compruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n\n");
					
					nplazas = compruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*34; 
						
					cont = llenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("La cantidad a pagar es de %.2f euros. Quedan %d plazas\n\n", bus[op-1].precio, vec[op-1]);
					
					total = bus[op-1].precio + comida (bus[op-1]);
					
					printf ("El total a pagar es de %.2f euros\n\n", total);
					
					printf ("La cantidad a pagar es de %.2f\n\n", descuentos (total, opcion));
					
					fflush (stdin);
 				    
				break;
				
				case 3:
					
					printf ("Madrid-Murcia\n\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n\n", vec[op-1]);
					
					i = compruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n\n");
					
					nplazas = compruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*34.70; 
						
					cont = llenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("La cantidad a pagar es de %.2f euros. Quedan %d plazas\n\n", bus[op-1].precio, vec[op-1]);
					
					total = bus[op-1].precio + comida (bus[op-1]);
					
					printf ("El total a pagar es de %.2f euros\n\n", total);
					
					printf ("La cantidad a pagar es de %.2f\n\n", descuentos (total, opcion));
					
					fflush (stdin);
					
				break;
				
				case 4:
			
					printf ("Madrid-Valencia\n\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n\n", vec[op-1]);
					
					i = compruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n\n");
					
					nplazas = compruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*28.50;
						
					cont = llenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("La cantidad a pagar es de %.2f euros. Quedan %d plazas\n\n", bus[op-1].precio, vec[op-1]);
					
					total = bus[op-1].precio + comida (bus[op-1]);
					
					printf ("El total a pagar es de %.2f euros\n\n", total);
					
					printf ("La cantidad a pagar es de %.2f\n\n", descuentos (total, opcion));
					
					fflush (stdin);
					
				break;
				
				case 5:
					
					printf ("Madrid-Barcelona\n\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n\n", vec[op-1]);
					
					i = compruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n\n");
					
					nplazas = compruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*35.50;
					
					cont = llenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("La cantidad a pagar es de %.2f euros. Quedan %d plazas\n\n", bus[op-1].precio, vec[op-1]);
					
					total = bus[op-1].precio + comida (bus[op-1]);
					
					printf ("El total a pagar es de %.2f euros\n\n", total);
					
					printf ("La cantidad a pagar es de %.2f\n\n", descuentos (total, opcion));
					
					fflush (stdin);
				
				break;
				
				case 6:
					
					printf ("Madrid-Zaragoza\n\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n\n", vec[op-1]);
					
					i = compruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n\n");
					
					nplazas = compruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*24.20;
						
					cont = llenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("La cantidad a pagar es de %.2f euros. Quedan %d plazas\n\n", bus[op-1].precio, vec[op-1]);
					
					total = bus[op-1].precio + comida (bus[op-1]);
					
					printf ("El total a pagar es de %.2f euros\n\n", total);
					
					printf ("La cantidad a pagar es de %.2f\n\n", descuentos (total, opcion));
					
					fflush (stdin);
						
				break;
				
				case 7:
					
					printf ("Madrid-Bilbao\n\n");
					
					notarjeta = 0;
										
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n\n", vec[op-1]);
					
					i = compruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n\n");
					
					nplazas = compruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*31.99;
		
					cont = llenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("La cantidad a pagar es de %.2f euros. Quedan %d plazas\n\n", bus[op-1].precio, vec[op-1]);
					
					total = bus[op-1].precio + comida (bus[op-1]);
					
					printf ("El total a pagar es de %.2f euros\n\n", total);
					
					printf ("La cantidad a pagar es de %.2f\n\n", descuentos (total, opcion));
					
					fflush (stdin);
					
				break;
				
				case 8:
					
					printf ("Madrid-A Coruna\n\n");
					
					notarjeta = 0;
					
					guardaplaza(vec);
					
					printf ("Hay %d plazas disponibles\n\n", vec[op-1]);
					
					i = compruebaBus (vec, op);
					
					if (i == 1) {
						
						printf ("Lo sentimos, el autobus se encuentra lleno\n\n");
						notarjeta = 1;
						system ("Pause");
						break;
					}
					
					printf ("Selecciona numero de plazas que deseas abonar\n\n");
					
					nplazas = compruebaPlaza(vec, op);
					
					bus[op-1].precio = nplazas*29.99;
						
					cont = llenaPlazas (bus[op-1], op, nplazas);
					
					vec[op-1] = (vec[op-1] - cont);
					
					imprime (vec);
					
					printf ("La cantidad a pagar es de %.2f euros. Quedan %d plazas\n\n", bus[op-1].precio, vec[op-1]);
					
					total = bus[op-1].precio + comida (bus[op-1]);
					
					printf ("El total a pagar es de %.2f euros\n\n", total);
					
					printf ("La cantidad a pagar es de %.2f\n\n", descuentos (total, opcion));
					
					fflush (stdin);
					
				break;
				
				default:
					
					printf ("ERROR. El numero introducido no coincide con ningun autobus\n\n");
				    system ("Pause");
				break;
			}
			
			if ((notarjeta == 0) && (op >= 1 && op <= 8)) {
			
			printf ("Introduce tu numero de tarjeta:\n\n");
			
			scanf ("%llu", &numtarjeta);
			
			fflush (stdin);
			
			i = 0;
			
			while (numtarjeta > 0) {
			
			  v[i] = numtarjeta % 10;
			  numtarjeta = numtarjeta / 10;
			  i++;
			}
			printf ("Tu numero de tarjeta es:\n\n");
			
			for (i = 0; i < DIM; i++) {
			  tarjeta[i] = v[n];
			  printf ("%d ", tarjeta[i]);
			  n--;
			}
			printf ("\n\n");
			
			printf ("Gracias por confiar en GETBUS. Que tenga un buen viaje\n\n");
			
			system ("Pause");
			getchar();
			}
		
			break;
			
		case 'R':
		case 'r':
			system("cls");
			//FUNCION REGISTRO DE USUARIO USO DE ESTRUCTURAS (FUNCION COMPRUEBA ROBOT FUNCION SRAND)
			naleatorio = numAleatorio(1);
			printf ("Verificacion de codigo: %d\n\n", naleatorio);
			scanf ("%d", &codigo);
			getchar();
			fflush (stdin);
			
			system("cls");
			
			while (compruebaRobot (codigo, naleatorio) != 1) {
				
			   printf ("Introduce de nuevo el codigo: %d\n\n");
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
			system("pause");
			
		    break;
		    
		case 'S':
		case 's':
			system("cls");
			/*EL CLIENTE PODRA ELEGIR LOS COMPLEMENTOS QUE DESEE SEGUN LA OPCION ESCOGIDA*/
			leerfichero("comida.txt");
			system("pause");
					
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
	
	printf ("Introduce tu nombre y apellidos\n\n");
	
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
	
	printf ("Tu nombre no figura en el registro.\n\nRegistrate ahora %s:\n\n", nom);
	
	strncpy(cliente.nombre,nom, 100);
	
	system("pause");
	
	system("cls");
	
	printf ("Introduce un telefono de contacto\n\n");
	
	scanf ("%s", cliente.telefono);
		
	longitud = strlen (cliente.telefono);
			
	while (longitud != 9) {
			
	    printf ("ERROR. Tu numero no tiene 9 cifras\n\n");
		scanf ("%s", cliente.telefono);
		longitud = strlen (cliente.telefono);
	}
		
	fputs (cliente.nombre, registro);
		
	fprintf (registro, " ");
	
	fprintf (registro, "%s", cliente.telefono);
	
	fprintf (registro, "\n");
	
	fclose (registro);
	
	system("cls");
	
	printf("Gracias por registrarse en GETBUS. Obtendra un 10 %% de descuento en el pago final\n\n");
	
	system("pause");
	
	}
}

int numAleatorio (int a) {
	
	int num;
	srand (time(0)); /*GENERADOR NUMERO ALEATORIO*/
	num = rand()%50001;
    
	return num;
}

int compruebaRobot (int numero, int b) {

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

void leerfichero(char nombreFich[]){
	
	FILE *lee;
	char texto[10][100];
	int num[10], i = 0;

	lee = fopen (nombreFich, "r");
	
	if(lee == NULL){
		printf("El fichero no se ha abierto correctamente...\n\n");
	}
	else{
	
	   while(fscanf(lee," %s %d", texto[i], &num[i]) != EOF){
	        printf("%s - %d\n", texto[i], num[i]);
			i++;
		}
    }
	fclose(lee);
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

int compruebaPlaza (int v[B], int opcion) {
	
	int nplazas;
	
	scanf ("%d", &nplazas);
	fflush (stdin);

    while (nplazas > v[opcion-1]) {

       printf ("Lo sentimos, el numero introducido es mayor que el numero de plazas disponibles. Intentalo de nuevo\n\n");
       scanf ("%d", &nplazas);
   }
   return nplazas;	
}

int compruebaBus (int v[B], int opcion) {
	
	int lleno = 0;

    if (v[opcion-1] == 0) {
    	
	   lleno = 1;
	}
	return lleno;
}

int llenaPlazas (autobuses bus, int opcion, int nplazas) {
	
	int i, contador = 0;
	
	for (i = 0; i < nplazas; i++) {
	
	    bus.plaza[i] = 1;
	}
	
	for (i = 0; i < A; i++) { //CUENTA EL NUMERO DE PLAZAS QUE SE HAN AÑADIDO
	
	    if (bus.plaza[i] == 1) {
		
		    contador++;
		}
	}
	return contador;
}

float comida (autobuses bus) {
	
	int i, eleccion, selec, num, C = 3;
	float precioComida[C];
	float total = 0;
	
	for (i = 0; i < C; i++) { //GUARDAMOS EN CADA COMPONENTE DEL VECTOR EL PRECIO DE CADA ARTICULO
		
		if (i == 0) {
			
			precioComida[i] = 3; //REFRESCO
		}
		
		if (i == 1) {
			
			precioComida[i] = 2; //PATATAS
		}
		
		if (i == 2) {
			
			precioComida[i] = 5;  //SANDWICH
		}
	}
	
	system ("pause");
	system("cls");
	
	printf ("Si desea consumir alguno de nuestros articulos pulse 1. En caso contrario pulse 2\n\n");
	
	leerfichero("comida.txt");
	
	printf ("\n");
	
	scanf ("%d", &eleccion);
	getchar();
	fflush (stdin);
	
	while (eleccion != 1 && eleccion != 2) {
		
		printf ("Opcion incorrecta. Por favor, introduzcala de nuevo\n\n");
		scanf ("%d", &eleccion);
		getchar();
	}
	
	if (eleccion == 1) {
		
		printf ("Desea tomar algun refresco? Pulse 1 en caso afirmativo. Otra tecla en caso contrario\n\n");
		scanf ("%d", &selec);
		getchar();
		fflush (stdin);
		
		if (selec == 1) {
			
			printf ("Por favor, seleccione el numero de refrescos que desea encargar:\n\n");
			scanf ("%d", &num);
			getchar();
			fflush (stdin);
			total = precioComida[selec-1]*num;
		}
		
		printf ("Desea tomar patatas fritas? Pulse 2 en caso afirmativo. Otra tecla en caso contrario\n\n");
		scanf ("%d", &selec);
		getchar();
		fflush (stdin);
		
		if (selec == 2) {
			
			printf ("Por favor, seleccione el numero de bolsas de patatas que desea encargar:\n\n");
			scanf ("%d", &num);
			getchar();
			fflush (stdin);
			total = total + precioComida[selec-1]*num;
		}
		
		printf ("Desea tomar algun sandwich? Pulse 3 en caso afirmativo. Otra tecla en caso contrario\n\n");
		scanf ("%d", &selec);
		getchar();
		fflush (stdin);
		
		if (selec == 3) {
			
			printf ("Por favor, seleccione el numero de sandwichs que desea encargar:\n\n");
			scanf ("%d", &num);
			getchar();
			fflush (stdin);
			total = total + precioComida[selec-1]*num;
		}
	}
	
	if (eleccion == 2) {
		
		printf ("Sentimos que no desee consumir nada durante el viaje. A continuacion comienza el proceso de pago\n\n");
	}
	return total;
}

float descuentos (float total, char op) {
	
	op = 'R'; //MODIFICAMOS LA COPIA DEL PARAMETRO PARA USO DE FUNCION REGISTRO
	
	int eleccion, naleatorio, codigo;
	
	system ("pause");
	system("cls");
	
	printf ("Desea obtener descuento del 10%%? Para ello debe registrarse. 1 - Afirmativo. Otra tecla en caso contrario\n\n");
	
	scanf ("%d", &eleccion);
	getchar();
	fflush (stdin);
	
	if (eleccion == 1) {
		
		naleatorio = numAleatorio(1);
		printf ("Verificacion de codigo: %d\n\n", naleatorio);
		scanf ("%d", &codigo);
		getchar();
		fflush (stdin);
		
		system("cls");
		
		while (compruebaRobot (codigo, naleatorio) != 1) {
		
		    printf ("Introduce de nuevo el codigo: %d\n\n");
			scanf ("%d", &codigo);
			getchar();
		}
			
		registro (op);
		
		total = total*0.9;
		printf ("Gracias por confiar en nosotros al aplicar su descuento\n\n");
	}
	
	else {
		
		printf ("Sentimos que no desee ningun descuento\n\n");
	}
	
	return total;
}
