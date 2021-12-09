#include <stdio.h>

//PROTOTIPOS DE LAS FUNCIONES
void categorias();
void ingresoCategoria (int op);
void empezarJuego (char palabras[][15], char nombre[]);
void dibujo (int intentos);


//FUNCION PRINCIPAL MAIN
int main(){
	system("mode con cols=80 lines=25");
	categorias();
	system("pause");
	return 0;
}

//FUNCION CATEGORIAS, IMPRIME EN PANTALLA EL MENU Y PERMITE ELEGIR UNA CATEGORIA
void categorias(){
	int op;
	do{
		system("cls");
		printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
		printf(" CATEGORIAS\n\n");
		printf(" Para salir presione ctrl + c \n\n");
		printf(" 1. Frutas\n");
		printf(" 2. Animales\n");
		printf(" 3. Paises\n");
		printf(" 4. Generos Musicales\n");
		printf(" 5. Dias de la semana\n");
		printf(" 6. Estados de Mexico\n");
		printf(" 7. Meses\n");
		printf(" 8. Colores\n");
		printf(" 9. Artistas femeninas pop\n");
		printf(" 10. Objetos\n\n");
		printf(" Ingresa una opcion: ");
		scanf("%i",&op);		
	}while(op<1 || op>10);

	if (op==1) ingresoCategoria(op);
	if (op==2) ingresoCategoria(op);
	if (op==3) ingresoCategoria(op);
	if (op==4) ingresoCategoria(op);
	if (op==5) ingresoCategoria(op);
	if (op==6) ingresoCategoria(op);
	if (op==7) ingresoCategoria(op);
	if (op==8) ingresoCategoria(op);
	if (op==9) ingresoCategoria(op);
	if (op==10) ingresoCategoria(op);
	
}


//ESTA FUNCION RECIBE UN VALOR, Y DEPENDIENDO DEL VALOR RECIBIDO LLAMA A OTRA FUNCION PARA EMPEZAR EL JUEGO
void ingresoCategoria (int op)
{
	char nombrecat[10][15] = {"Frutas","Animales","Paises", "generos", "dias", "estados", "meses", "colores", "artistas", "Objetos"};
	char frutas [10][15] = {"MELON","PAPAYA","SANDIA","MANZANA","PERA","NARANJA","UVA","CEREZA","CIRUELA","KIWI"};
	char animales [10][15] = {"PERRO","PERICO","CABALLO","TRIGRE","JIRAFA","MONO","RINOCERONTE","CONEJO","TORTUGA","LOBO"};
	char paises [10][15] = {"PERU","JAMAICA","ARGENTINA","NICARAGUA","ITALIA","MEXICO","CANADA","RUSIA","JAPON","BRASIL"};
	char generos [10][15] = {"REGGETON", "POP", "BACHATA", "BANDA", "ROCK", "JAZZ", "COUNTRY", "SALSA", "TANGO", "METAL"};
	char dias [7][15] = {"LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO"};
	char estados [10][15] = {"CHIHUAHUA", "OAXACA", "HIDALGO", "SINALOA", "PUEBLA", "MORELOS", "QUERETARO", "VERACRUZ", "NAYARIT", "GUANAJUATO"};
	char meses [12][15] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
	char colores [10][15] = {"AMARILLO", "ROSA", "BLANCO", "NEGRO", "AZUL", "ROJO", "MORADO", "PURPURA", "NARANJA", "GRIS"};
	char artistas [7][15] = {"BEYONCE", "RIHANNA", "ARIANA GRANDE", "DUA LIPA", "TAYLOR SWITF", "SELENA GOMEZ", "BILLIE EILISH"};
	char objetos [10][15] = {"MOCHILA","RELOJ","ZAPATO","MUEBLE","CUADERNO","SILLA","MESA","CELULAR","PUERTA","AUDIFONOS"};
	
	switch(op){
		case 1:
			empezarJuego(frutas,nombrecat[op-1]);
			break;
		case 2:
			empezarJuego(animales,nombrecat[op-1]);
			break;
		case 3:
			empezarJuego(paises,nombrecat[op-1]);
			break;
		case 4:
			empezarJuego(generos,nombrecat[op-1]);
			break;
		case 5:
			empezarJuego(dias,nombrecat[op-1]);
			break;
		case 6:
			empezarJuego(estados,nombrecat[op-1]);
			break;
		case 7:
			empezarJuego(meses,nombrecat[op-1]);
			break;
		case 8:
			empezarJuego(colores,nombrecat[op-1]);
			break;
		case 9:
			empezarJuego(artistas,nombrecat[op-1]);
			break;
		case 10:
			empezarJuego(objetos,nombrecat[op-1]);
			break;	
	}	
}


//FUNCION QUE CONTIENE EL ALGORITMO DEL JUEGO
void empezarJuego (char palabras[][15], char nombre[])
{
	int opcion,i,j,m,k,longitud,espacios,puntos=1200;
	char letra;
	int aciertos = 0;
	int intentos = 0;
	int ganar = 0;
//Generador de aleatorios
	srand(time(NULL));
	
	opcion = rand() % 10; 
//Se guarda la longitud de la palabra
	longitud = strlen(palabras[opcion]); 
	char frase[longitud];
	
//Se ponen los guines para que se pueda acompletar la frase 
	for(i=0; i < longitud; i++){
		frase[i] = '_';
	}
	
	
	do{
		aciertos = 0;
		system("cls");
		printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
		printf(" CATEGORIA: %s\n\n",nombre);
//Se pone la palabra alrevez
		printf("La palabra contiene las siguientes letras: ");
		for  (m=longitud; m>=0; m--){
		printf("%c", palabras[opcion][m]);	
		}
		printf(" \nIntentos Disponibles: %i\t\t\t\tPuntuacion: %i\n\n",6-intentos,puntos);
		dibujo(intentos);
		
		
//Se pone en pantalla los guiones bajos  
		printf("\n\n\n");
		for(i=0; i < longitud; i++){
			printf(" %c ",frase[i]);
		}

		
		if (intentos == 6){
			printf("\n\n PERDISTE!!\n");
			printf(" LA SOLUCION ERA: %s\n\n",palabras[opcion]);
			printf(" Presiona una tecla para volver a jugar..");
			getch();
			categorias();	
		}
		
		
//PROCESO QUE COMPRUEBA SI SE HA ADIVINADO LA PALABRA
		espacios=0;
		
		for (i = 0; i < longitud; i++){
			if (frase[i] == '_')
				espacios++;
		}
		
		
		if (espacios == 0){
			printf("\n\n FELICIDADES.. GANASTE!!\n\n");
			printf(" Presiona una tecla para volver a jugar..");
			getch();
			categorias();		
		}
		
		
		printf("\n\n Digite una letra: ");
		scanf(" %c",&letra);
		
//PROCESO QUE VERIFICA SI LA LETRA INGRESADA EXISTE EN LA PALABRA, SI ESTO ES VERDADERO, SE REEMPLAZA EL CARACTER GUION BAJO POR LA LETRA INGRESADA 
		for (j = 0; j < longitud; j++){
			if (letra == palabras[opcion][j]){
				frase[j] = letra;
				aciertos++;
			}	
		}
		
		if (aciertos == 0){
			intentos++;	
			puntos -= 200;
		}
		
		
			
	}while(intentos != 7);
	
	
	printf("\n\n");		
}

//FUNCION QUE REALIZA EL DIBUJO DE EL AHORCADO, RECIBE EL NUMERO DE INTENTOS Y CON ESE DATO REALIZA EL DIBUJO
void dibujo (int intentos){
	switch(intentos){
		case 0:
			printf("\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------");
			break;
		case 1:
			printf("\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------");
			break;
		case 2:
			printf("\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------");
			break;
		case 3:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------");
			break;
		case 4:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |\n    |\n    |\n ----------");
			break;
		case 5:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |      /\n    |\n    |\n ----------");
			break;
		case 6:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |      / ");
			printf("\\");
			printf("\n");
			printf("    |\n    |\n ----------");
			break;
	}
	
}


