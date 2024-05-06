#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

/* Macros y/o constantes para usar en multiples partes del codigo */
#define MAX_ASIENTOS 10
#define MAX_ASIENTOS_FILA 2
#define MAX_COMPRA_UNITARIA 3
#define PRECIO_BOLETO 100


/* Variables iteradoras */
int contador = 0, i, j, k;

/*contante de titulo*/
int vcentro;
int vcentromenu;

/* Variable validadora */
int stringread;


/* Variables para comprar boletos */
int id, asientos[MAX_ASIENTOS];
int boletos_comprados[MAX_ASIENTOS];
char comprador[MAX_ASIENTOS][200], correo[MAX_ASIENTOS][70], telefono[MAX_ASIENTOS][20];
char posicion[MAX_ASIENTOS][3];
char asiento[100];
int asientos_disponibles = MAX_ASIENTOS;
int boletos;
int comprados[MAX_ASIENTOS][MAX_COMPRA_UNITARIA];

/*presentaciones de cuadros*/
char vtitulo[] = " Presentacion del proyecto";
char vtitulomenu[] = " ------------BIENVENIDO A UNI AIRLINES------------";
int vlongitud , vlongitudmenu, xcol , xfil , vcolor , vcentromenu , vcentro;

/* Prototipos de las funciones */
void logout();
void notBlank();
int login();
int menu();
int presentacion();
int adquirir();
int cancelar();
int disponibilidad();
int ver_boleto();


int main()
{
    /* Se genera el nombre de los asientos en base a la cantidad maxima, y su limite por filas */
    char letra = 65;
    char numero = '1';
    /* Superior solo se usa para saber si se excedio la cantidad de letras mayusculas en los nombres,
    para asi parar a nombrar los asientos con letras minusculas */
    int superior = 0;
    vcentro = (((55-vlongitud)/2)+1);
    vcentromenu = (((30-vlongitudmenu)/2)+1);
    /* for que recorre cada espacio de los asientos para asiganarlos como libres, darles nombre, y
    especificar que el numero total de compras en 0 */
    for(i = 0; i < MAX_ASIENTOS; i++)
    {
	    /* Si se supera el valor numerico 90 (equivalente a z en ascii), se pasa a nombrar con letras
	    minusculas (la primera de todas tiene valor 97 en ascii) */
	    if(numero - 49 == MAX_ASIENTOS_FILA)
	    {
			numero = 49;
	        letra++;
	        if (letra > 90 && superior == 0)
	        {
		        letra = 97;
		        superior = 1;
	        }
	    }
	/* Establece por default que ninguna persona tiene el indice de algun asiento comprado */
	for(j = 0; j < MAX_COMPRA_UNITARIA; j++)
	{
	    comprados[i][j] = -1;
	}

	    asientos[i] = 0;
	    boletos_comprados[i] = 0;
	    /* snprintf concatena la letra correspondiente al asiento con su respectivo numero,
	    y le da formato dependiendo de la cantidad de digitos del numero de asiento */
	    posicion[i][0] = letra;
        posicion[i][1] = numero;
		posicion[i][2] = '\0';
	    numero++;
    }
    system("cls");
    login();
    return 0;
}


/* Se encarga de prevenir que un usuario ingrese un string en blanco */
void notBlank(char string[], char text[])
{
    printf("%s", text);
    stringread = scanf("%[^\n]%*c", string);

    /* Si stringread es distinto a 1, la lectura del string dio error y se vuelve a pedir */
    while(stringread != 1)
    {
	printf ("\033[0;31m");
	    printf("Asegurate de no dejar este campo en blanco, vuelve a ingresarlo \n");
	printf ("\033[0m");
	    fflush(stdin);
	    stringread = scanf("%[^\n]%*c", string);
    }

    return;
}

/* xd */
void logout()
{
    system("cls");
	printf("cerrando sesion.");
    sleep(1);system("cls");
	printf("cerrando sesion..");
    sleep(1);system("cls");
	printf("cerrando sesion...");
    sleep(1); system("cls");
	printf("cerrando sesion.");
    sleep(1);system("cls");
	printf("cerrando sesion..");
    sleep(1);system("cls");
	printf("cerrando sesion...");
	sleep(1);
    system("cls");
    getch();
    return;
}


/* Verifica que la clave y el usuario sean los correctos, y bloquea el programa al tercer intento */
int login()
{
    char user[20];
    int intentos = 0;
    char input_pass[20];

    printf ("\033[0;32m");
    printf("Ingrese su usuario: ");
    printf ("\033[0m");
    stringread = scanf("%[^\n]%*c", user);


    /* misma logica que el notBlank(), pero con mas condiciones */
    while(stringread != 1 || strcmp(user, "admin") != 0)
    {
	    intentos++;
	printf ("\033[0;31m");
	    printf("Usuario incorrecto, ingrese nuevamente\n");
	printf ("\033[0m");
	    if (intentos == 3)
	    {
	    printf ("\033[0;36m");
		printf("Ha excedido el numero de intentos\n");
	    printf ("\033[0m");
		getch();
		return 0;
	    }
	    fflush(stdin);
	    stringread = scanf("%[^\n]%*c", user);
    }

    printf ("\033[0;32m");
    printf("Usuario valido, ingrese su contrasena: ");
    printf ("\033[0m");
    stringread = scanf("%[^\n]%*c", input_pass);

    /* misma logica que el notBlank(), pero con mas condiciones */
    while(stringread != 1 || strcmp(input_pass, "1234") != 0)
    {
	    intentos++;
	printf ("\033[0;31m");
	    printf("Contrase%ca incorrecta, ingrese nuevamente\n", 164);
	printf ("\033[0m");
	    if (intentos == 3)
	    {
	    printf ("\033[0;36m");
		printf("Ha excedido el numero de intentos\n");
	    printf ("\033[0m");
		getch();
		return 0;
	    }
	    fflush(stdin);
	    stringread = scanf("%[^\n]%*c", input_pass);
    }

    system("cls");
    return menu();
}


/* Muestra toda la interfaz de opciones que se pueden realizar,
cada opcion retorna una funcion que ejecuta su accion correspondiente */
int menu()
{
	char opcion[2];
	char continuar[2];
    for (xcol = 36 ; xcol < 46; xcol++)
{
textcolor(8);
gotoxy(xcol,10); cprintf("%c", 205);
gotoxy(37,11); cprintf("cargando");
delay(500);
}
textcolor(15);
clrscr();
textbackground(0);
    system("cls");
    /*bordes izquierdos*/
gotoxy(1,2); cprintf("%c" , 201);
gotoxy(1,20); cprintf("%c" , 200);
/*bordes derechos*/
gotoxy(79,2); cprintf("%c" , 187);
gotoxy(79,20); cprintf("%c" , 188);

/*vertical*/
for (xcol = 3 ; xcol < 20; xcol++)
{
gotoxy(1,xcol); cprintf("%c" , 186);
gotoxy(79,xcol); cprintf("%c" , 186);
}

/*hoizontal*/
for (xfil = 2; xfil <= 78; xfil++)
{
gotoxy(xfil,2); cprintf("%c" , 205);
gotoxy(xfil,20); cprintf("%c" , 205);
}

for (xcol = 2 ; xcol <= vcentromenu; xcol++)
{
vcolor = random(15); textcolor(vcolor);
gotoxy(xcol , 3); cprintf(vtitulomenu);
}
textcolor(10); gotoxy(3,5); cprintf("1 - Presentacion" );
textcolor(13); gotoxy(4,6); cprintf("2 - Adquirir boletos");
textcolor(9); gotoxy(5,7); cprintf("3 - Cancelar boletos");
textcolor(6); gotoxy(6,8); cprintf("4 - Ver disponiblilidad");
textcolor(2); gotoxy(7,9); cprintf("5 - Ver boletos");
textcolor(4); gotoxy(8,10); cprintf("6 - Salir");
gotoxy(3,12); notBlank(opcion, " ");


    if (strcmp("1", opcion) == 0)
    {
	    system("cls");
	    return presentacion();
    }
    else if (strcmp("2", opcion) == 0)
    {
	    system("cls");
	    return adquirir();
    }
    else if (strcmp("3", opcion) == 0)
    {
	    system("cls");
	    return cancelar();
    }
    else if (strcmp("4", opcion) == 0)
    {
	    system("cls");
	    return disponibilidad();
    }
    else if (strcmp("5", opcion) == 0)
    {
	    system("cls");
	    ver_boleto();
    }
    else if (strcmp("6", opcion) == 0)
    {
	    logout();
	    return 0;
    }
    else
    {
	clrscr();
	printf ("\033[0;31m");
	    printf("Has seleccionado una opcion invalida, deseas continuar? (y/n)\n");
	printf ("\033[0m");
	    stringread = scanf("%[^\n]%*c", continuar);

	    if(stringread != 1 || strcmp(continuar, "y") != 0)
	    {
		logout();
		return 2;
	    }
        clrscr();
	    return menu();
    }
clrscr();
    return 1;
}


int presentacion()
{

vlongitud = strlen(vtitulo);
textbackground(0);
clrscr();
textcolor(14);
/*bordes izquierdos*/
gotoxy(1,2); cprintf("%c" , 201);
gotoxy(1,20); cprintf("%c" , 200);
/*bordes derechos*/
gotoxy(79,2); cprintf("%c" , 187);
gotoxy(79,20); cprintf("%c" , 188);
/*vertical*/
for (xcol = 3 ; xcol < 20; xcol++)
{
gotoxy(1,xcol); cprintf("%c" , 186);
gotoxy(79,xcol); cprintf("%c" , 186); delay(30);
}
/*hoizontal*/
for (xfil = 2; xfil <= 78; xfil++)
{
gotoxy(xfil,2); cprintf("%c" , 205);
gotoxy(xfil,20); cprintf("%c" , 205); delay(30);
}
for (xcol = 2; xcol <= vcentro; xcol++)
{
vcolor = random(15); textcolor(vcolor);
gotoxy(xcol , 3); cprintf(vtitulo);
delay(50);
}
textcolor(10);
gotoxy(4,5); cprintf("Hecho por: Roger Alfaro - Jessua Solis - Sharon Briceno" );
textcolor(10);
gotoxy(4,6); cprintf("Carnets: 2023-0599U | 2023-0851U | 2023-0616U" );
textcolor(13);
gotoxy(4,7); printf("Docente: Ing. Kevin Euclides Ramirez de Arellano Castrillo");
textcolor(9);
gotoxy(4,8);  printf("Grupo: 1M1 - CO");
textcolor(15);
gotoxy(4,9);  printf("Universidad Nacional de Ingenieria (UNI)");

    getch();
    system("cls");
    return menu();
}


/* Funcion para comprar boletos */
int adquirir()
{
    int compra_exitosa = 0;
    char lector_boletos[50];
    int valido = 0;
    int cont2 = 0;
    int contador = 0;
    printf ("\033[95m");
    printf("---------- Compra de boletos ----------\n\n");
    printf ("\033[0m");

    /* Si no hay asientos disponibles, retorna al menu */
    if(asientos_disponibles <= 0)
    {
	printf ("\033[0;31m");
	    printf("lo sentimos, ya no hay asientos disponibles \n");
	printf ("\033[0m");
	    getch();
	    return menu();
    }

    /* ejecuta un for una cantidad de veces equivalente al valor de la cantidad maxima de asientos */
    for (i = 0; i < MAX_ASIENTOS; i++)
    {
	/* Si la posicion actual en el arreglo de boletos comprados, le brinda este espacio a un
	usuario para que se llene con sus datos */
	    if(boletos_comprados[i] == 0)
	    {
		/* la id va a servir como un indice mas adelante al crear o ver los boletos */
		id = i+1;

		/* pide los datos de nombre, correo y telefono del comprador */
	    valido = 0;
	    while(valido == 0)
	    {
		printf ("\033[0;32m");
		    notBlank(comprador[i], "Ingresa tu nombre completo: \n");
		printf ("\033[0m");
		contador = 0;
		for(j = 0; j < strlen(comprador[i]); j++)
		{
		    if(isalpha(comprador[i][j]) || comprador[i][j] == 32)
		    {
			contador++;
		    }
		}
		if (contador == strlen(comprador[i]))
		{
		    valido = 1;
		}
		else
		{
		    printf ("\033[0;33m");
		    printf("Tu nombre no puede contener numeros ni simbolos\n");
		    printf ("\033[0m");
		}
	    }


	    printf ("\033[0;32m");
		notBlank(correo[i], "Ingresa tu correo electronico personal: \n");
	    printf ("\033[0m");
		/* verifica que se ingrese un correo personal valido (que contenga @gmail.com)
		y que tenga al menos 11 caracteres */
		while(!(strstr(correo[i], "@gmail.com")) || strlen(correo[i]) < 11)
		{
		printf ("\033[0;31m");
			notBlank(correo[i], "Asegurate de ingresar un correo valido, vuelve a introducirlo: \n");
		printf ("\033[0m");
		}


		/* verifica los datos del numero telefonico */
	    valido = 0;
		while (valido == 0)
		{
		printf ("\033[0;32m");
			notBlank(telefono[i], "Ingresa tu numero de telefono: \n");
		printf ("\033[0m");
			/* Si mete un numero con cantidad de digitos distinta a 8, lo vuelve a pedir */
			while (strlen(telefono[i]) != 8)
			{
		    printf ("\033[0;33m");
			    notBlank(telefono[i], "Ingresa un numero de telefono valido para Nicaragua (8 digitos juntos): \n");
		    printf ("\033[0m");
			}
			/* Se usa un contador para conocer si todos los espacios del telefono son digitos */
			contador = 0;
			for(j = 0; j < 8; j++)
			{
			    if(isdigit(telefono[i][j]))
			    {
				    contador++;
			    }
			    if(contador == 8)
			    {
				    valido = 1;
			    }
			}
		if(contador != 8)
		{
		    printf ("\033[0;31m");
		    printf("Has ingresado un dato no valido\n");
		    printf ("\033[0m");
		}
		}
	    system("cls");

		/* Indica dinamicmente cuantos asientos hay disponible, su precio, y pide
		la cantidad de boletos a comprar  */
		printf ("\033[0;33m");
		printf("Tenemos %d asientos disponibles con un precio unitario de $%d\n\n", asientos_disponibles, PRECIO_BOLETO);
	    printf ("\033[0m");

	    printf ("\033[0;36m");
		printf("Ingresa la cantidad de boletos que deseas comprar (maximo %d): \n", MAX_COMPRA_UNITARIA);
	    printf ("\033[0m");
		stringread = scanf("%[^\n]%*c", lector_boletos);
		while(stringread != 1)
		{
		printf ("\033[0;31m");
			printf("Asegurate de no dejar este campo en blanco, vuelve a ingresarlo \n");
		printf ("\033[0m");
			fflush(stdin);
			stringread = scanf("%[^\n]%*c", lector_boletos);
		}

		/* Valida que no se ingresen datos menores a 1, mayores al maximo de boletos por persona
		o mayores a la cantidad de asientos disponibles */
		while(atoi(lector_boletos) < 1 || atoi(lector_boletos) > MAX_COMPRA_UNITARIA || atoi(lector_boletos) > asientos_disponibles)
		{
		printf ("\033[0;31m");
			printf("Asegurate de ingresar datos no mayores que la cantidad de boletos disponibles, ni negativos o mayores que %d, vuelve a ingresarlo: \n", MAX_COMPRA_UNITARIA);
			printf ("\033[0m");
		stringread = scanf("%[^\n]%*c", lector_boletos);

			while(stringread != 1)
			{
		    printf ("\033[0;31m");
			    printf("Asegurate de no dejar este campo en blanco, vuelve a ingresarlo \n");
			    printf ("\033[0m");
		    fflush(stdin);
			    stringread = scanf("%[^\n]%*c", lector_boletos);
			}
		}
		/* una vez validado todo, transforma la variable a un entero con la cantidad de boletos
		a comprar, y lo guarda dentro del espacio libre que se encontró en el arreglo de boletos
		comprados */
		boletos_comprados[i] = atoi(lector_boletos);

		/* ejecuta un for equivalente a la cantidad de boletos que compra la persona */
		for(j = 0; j < boletos_comprados[i]; j++)
		{
			valido = 0;
			/* Se ejecuta un ciclo en base a una variable validadora que indica cuando se realizó
			bien una compra de un asiento */
			while (valido == 0)
			{
			    contador = 0;
		    printf("Los siguientes asientos se encuentran disponibles: \n");
			    /* pide el asiento a comprar */
		    printf ("\033[0;32m");
		    for(k = 0; k < MAX_ASIENTOS; k++)
		    {
			if(asientos[k] == 0)
			{
			    /* Si el asiento está disponible, se imprime "posicion[i]" (es decir, el nombre del asiento
			    en la posicion actual) */
			    printf ("\033[0;33m");
			    printf("DISPONIBLE: %s\n", posicion[k]);
			    printf ("\033[0m");
			}
		    }
			    notBlank(asiento, "Ingresa el asiento que deseas comprar: \n");
		    printf ("\033[0m");

			    /* Recorre todos los asientos para saber si el dato ingresado existe, la variable
			    contadora es para mandar un mensaje de error si no hay coincidencias */
			    for(k = 0; k < MAX_ASIENTOS; k++)
                    {
                        /* Si en efecto hay una coicnidencia, se reduce en 1 los asientos disponibles,
                        el asiento seleccionado pasa a estar ocupado, se guarda el asiento comprado en
                        un arreglo bidimensional, y la variable validadora se vuelve  para pasar a
                        hacer este mismo proceso pero con un siguiente asiento en caso de haberlo (todo
                        ocurre en ese orden) */
                        if (strcmp(posicion[k], asiento) == 0 && asientos[k] == 0)
                        {
                            asientos_disponibles--;
                            asientos[k] = 1;
                            comprados[i][j] = k;
                            valido = 1;
                        }
                        else
                        {
                            contador++;
                        }
                        if(contador == MAX_ASIENTOS)
                        {
                            printf ("\033[0;33m");
                            printf("Este asiento no se encuentra disponible, vuelve a introducirlo\n");
                            printf ("\033[0m");
                        }
                    }

                }

            }
            /* Indica que la compra fue exitosa */
            compra_exitosa = 1;
        }
        /* si la compra fue exitosa, se imprimen los datos que ingresó la persona como si fuese un boleto */
        if (compra_exitosa == 1)
        {
            clrscr();
            /*bordes izquierdos*/
gotoxy(1,2); cprintf("%c" , 201);
gotoxy(1,10); cprintf("%c" , 200);
/*bordes derechos*/
gotoxy(79,2); cprintf("%c" , 187);
gotoxy(79,10); cprintf("%c" , 188);

/*vertical*/
for (xcol = 3 ; xcol < 10; xcol++)
{
gotoxy(1,xcol); cprintf("%c" , 186);
gotoxy(79,xcol); cprintf("%c" , 186); 
}

/*hoizontal*/
for (xfil = 2; xfil <= 78; xfil++)
{
gotoxy(xfil,2); cprintf("%c" , 205);
gotoxy(xfil,10); cprintf("%c" , 205); 
}

textcolor(10); gotoxy(4,3); cprintf("ID = %d", id);
textcolor(10); gotoxy(4,4); cprintf("NOMBRE = %s", comprador[i]);
textcolor(10); gotoxy(4,5); cprintf("CORREO = %s", correo[i]);
textcolor(10); gotoxy(4,6); cprintf("TELEFONO = %s", telefono[i]);
textcolor(10); gotoxy(4,7); cprintf("CANTIDAD DE BOLETOS = %d", boletos_comprados[i]);
textcolor(10); gotoxy(4,8); cprintf("ASIENTOS = ");
            /* ejecuta un for equivalente al valor de los boletos comprados de la persona, para así
            imprimir en pantalla los asientos que compró */
            for(j = 0; j < boletos_comprados[i]; j++)
            {
                printf ("\033[0;33m");
            gotoxy(15 + (cont2*4),8);cprintf(" %s ", posicion[comprados[i][j]]);
                printf ("\033[0m");
                cont2++;
            }
            /* Imprime el total a pagar multiplicando el precio de cada boleto, por la cantidad
            de boletos comprados por la persona */
            printf ("\033[0;35m");
            gotoxy(4,9);cprintf("TOTAL A PAGAR: $%d\n", PRECIO_BOLETO*boletos_comprados[i]);
            printf ("\033[0m");

            getch();
            system("cls");
            return menu();
        }
        
    }
    

    getch();
    system("cls");
    return menu();
}


/* casi la misma logica que adquirir, solo que aqui se pide el id del boleto para usarlo como 
indice/referencia o posicion que tiene guardados los datos de la persona */
int cancelar()
{
    int cont2 = 0;
    int cancelacion_exitosa = 0;
    int counter = 0;
    int valido = 0;
    char lector_id[50];
    char lector_boletos[50];
    printf ("\033[95m");
    printf("---------- Cancelacion de boletos ----------\n\n");
    printf ("\033[0m");

    /* Si la variable contadora obtiene el mismo valor que el del maximo de asientos, imprime en
    pantalla que no hay boletos que hayan sido vendidos o asignados */
    for(i = 0; i < MAX_ASIENTOS; i++)
    {
        if(boletos_comprados[i] == 0)
        {
            counter++;
        }
    }
    if(counter == MAX_ASIENTOS)
    {
        printf ("\033[0;33m");
        printf("Aun no se han vendido/asignado boletos\n");
        printf ("\033[0m");
        getch();
        system("cls");
        return menu();
    }


    /* pide el id del boleto para acceder a los datos de este usando el id como indice */
    printf ("\033[0;32m");
    notBlank(lector_id, "introduce el id de tu boleto para realizar la cancelacion: \n");
    printf ("\033[0m");
    /* Mientras el id no tenga asignados boletos comprados, sea mayor al numero maximo de
    asiento o menor a 0, lo vuelve a pedir */
    while(atoi(lector_id) < 1 || atoi(lector_id) > (MAX_ASIENTOS) || boletos_comprados[atoi(lector_id)-1] == 0)
    {
        printf ("\033[0;31m");
        notBlank(lector_id, "Este id no existe o no ha sido asignado, vuelve a introducirlo: \n");
        printf ("\033[0m");
    }
    id = atoi(lector_id);
    /* Le resta 1 al id para obtener lA verdadera posicion del boleto y datos de la persona tras haber
    hecho las validaciones pertinentes*/
    id = id-1;


    /* Pide la cantidad de boletos a cancelar, y verifica que la persona cuente realmente con una
    cantidad de boletos comprados igual o menor a la ingresada*/
    printf ("\033[0;33m");
    notBlank(lector_boletos, "Introduce la cantidad de boletos a cancelar: \n");
    printf ("\033[0m");
    while(atoi(lector_boletos) > boletos_comprados[id])
    {
        printf ("\033[0;31m");
        notBlank(lector_boletos, "Has ingresado mas boletos de los que has comprado, vuelve a introducir el dato: \n");
        printf ("\033[0m");
    }
    boletos = atoi(lector_boletos);
    if(boletos == 0)
    {
        printf ("\033[0;32m");
        printf("Has anulado la cancelacion del boleto \n");
        printf ("\033[0m");
        getch();
        return menu();
    }


    /* si la cantidad de boletos a cancelar es igual a la cantidad que boletos que compró la persona,
    se le cancelan todos directamente y se imprime su boleto */
    if(boletos == boletos_comprados[id])
    {
        /* Los asientos que ha comprado la persona vuelven a dejarse como disponibles, y se borran
        los datos de su compra */
        for(j = 0; j < boletos; j++)
        {
            asientos[comprados[id][j]] = 0;
            comprados[id][j] = -1;
        }
        boletos_comprados[id] = 0;
        cancelacion_exitosa = 1;
        asientos_disponibles += boletos;
        printf ("\033[0;33m");
        printf("Todos tus boletos han sido cancelados exitosamente \n");
        printf ("\033[0m");
        /* Se imprime como id + 1 por cuestiones de decoracion */
        clrscr();
            /*bordes izquierdos*/
gotoxy(1,2); cprintf("%c" , 201);
gotoxy(1,10); cprintf("%c" , 200);
/*bordes derechos*/
gotoxy(79,2); cprintf("%c" , 187);
gotoxy(79,10); cprintf("%c" , 188);

/*vertical*/
for (xcol = 3 ; xcol < 10; xcol++)
{
gotoxy(1,xcol); cprintf("%c" , 186);
gotoxy(79,xcol); cprintf("%c" , 186); 
}

/*hoizontal*/
for (xfil = 2; xfil <= 78; xfil++)
{
gotoxy(xfil,2); cprintf("%c" , 205);
gotoxy(xfil,10); cprintf("%c" , 205); 
}

textcolor(10); gotoxy(4,3);  printf("ID = %d", id+1);
textcolor(10); gotoxy(4,4); cprintf("NOMBRE = %s", comprador[id]);
textcolor(10); gotoxy(4,5); cprintf("CORREO = %s", correo[id]);
textcolor(10); gotoxy(4,6); cprintf("TELEFONO = %s", telefono[id]);
textcolor(10); gotoxy(4,7); cprintf("CANTIDAD DE BOLETOS = %d", boletos_comprados[id]);
textcolor(10); gotoxy(4,8); cprintf("ASIENTOS = ");
        for(i = 0; i < MAX_COMPRA_UNITARIA; i++)
        {
            /* Cuando se cancela un boleto, su celda en el arreglo "comprados" pasa a ser -1,
            por ello solo imprime el nombre del/los boletos correspondientes a los que estan
            guardados en "comprados" */
            if(comprados[id][i] > -1)
            {
                printf ("\033[0;33m");
            gotoxy(15 + (cont2*4),8); cprintf(" %s ", posicion[comprados[id][i]]);
                printf ("\033[0m");
                cont2++;
            }
        }
        printf ("\033[0;35m");
        gotoxy(4,9); cprintf("TOTAL A PAGAR: $%d\n", PRECIO_BOLETO*boletos_comprados[id]);
        printf ("\033[0m");

        getch();
        system("cls");
        return menu();
    }

    /* Este for se ejecuta una cantidad de veces equivalente a la cantidad de boletos que va a 
    cancelar la persona */
    for (i = 0; i < boletos; i++)
    {
        valido = 0;
        /* Ciclo que se ejeuta infinitamente mientras no se valide todo lo siguiente */
        while (valido == 0)
        {
            /* Imprime los boletos con los que cuenta la persona */
            for(j = 0; j < MAX_COMPRA_UNITARIA; j++)
            {
                if(comprados[id][j] > -1)
                {
                    printf ("\033[0;33m");
                    printf("ASIENTO COMPRADO = %s\n", posicion[comprados[id][j]]);
                    printf ("\033[0m");
                }
            }
            /* Pide el asiento a cancelar */
            printf ("\033[0;32m");
            notBlank(asiento, "Ingresa el asiento que deseas cancelar: \n");
            printf ("\033[0m");
            counter = 0;

            /* Si la variable contadora llega a un valor igual al maximo de asientos, entoonces 
            no hay coincidencias y el asiento no existe */
            for(j = 0; j < MAX_ASIENTOS; j++)
            {
                /* Verifica que haya una coincidencia (Que el asiento exista) */
                if(strcmp(posicion[j], asiento) == 0)
                {
                    /* Se ejecuta un for la cantidad de veces equivalente al valor de
                    MAX_COMPRA_UNITARIA */
                    for(k = 0; k < MAX_COMPRA_UNITARIA; k++)
                    {
                        /* Verifica que la persona realmente haya comprado ese asiento */
                        if(j == comprados[id][k])
                        {
                            /* Si todo lo anterior se cumple, se vuelve a dejar disponible el asiento, se
                            reduce en 1 la cantidad de boletos comprados por la persona,la celda con la
                            posicion del asiento comprado se vuelve -1, y se valida que la cancelacion fue
                            exitosa, todo en ese orden */
                            asientos[j] = 0;
                            boletos_comprados[id] -= 1;
                            comprados[id][k] = -1;
                            cancelacion_exitosa = 1;
                            asientos_disponibles++;
                            valido = 1;
                            printf ("\033[0;33m");
                            printf("Cancelacion exitosa\n");
                            printf ("\033[0m");
                        }

                    }
                }
                else
                {
                    counter++;
                }
                if(counter == MAX_ASIENTOS)
                {
                    printf ("\033[0;31m");
                    printf("Has ingresado un asiento invalido, vuelve a digitarlo\n");
                    printf ("\033[0m");
                }
            }
        }

    }

    /* Si la cancelacion fue exitosa, se imprime el boleto actualizado */
    if(cancelacion_exitosa == 1)
    {
        clrscr();
            /*bordes izquierdos*/
gotoxy(1,2); cprintf("%c" , 201);
gotoxy(1,10); cprintf("%c" , 200);
/*bordes derechos*/
gotoxy(79,2); cprintf("%c" , 187);
gotoxy(79,10); cprintf("%c" , 188);

/*vertical*/
for (xcol = 3 ; xcol < 10; xcol++)
{
gotoxy(1,xcol); cprintf("%c" , 186);
gotoxy(79,xcol); cprintf("%c" , 186); 
}

/*hoizontal*/
for (xfil = 2; xfil <= 78; xfil++)
{
gotoxy(xfil,2); cprintf("%c" , 205);
gotoxy(xfil,10); cprintf("%c" , 205); 
}

textcolor(10); gotoxy(4,3); cprintf("ID = %d", id+1);
textcolor(10); gotoxy(4,4); cprintf("NOMBRE = %s", comprador[id]);
textcolor(10); gotoxy(4,5); cprintf("CORREO = %s", correo[id]);
textcolor(10); gotoxy(4,6); cprintf("TELEFONO = %s", telefono[id]);
textcolor(10); gotoxy(4,7); cprintf("CANTIDAD DE BOLETOS = %d", boletos_comprados[id]);
textcolor(10); gotoxy(4,8); cprintf("ASIENTOS = ");
        for(i = 0; i < MAX_COMPRA_UNITARIA; i++)
        {
            if(comprados[id][i] > -1)
            {
                printf ("\033[0;33m");
                gotoxy(15 + (cont2*4),8); cprintf(" %s ", posicion[comprados[id][i]]);
                printf ("\033[0m");
                cont2++;
            }
        }
        printf ("\033[0;35m");
        gotoxy(4,9);cprintf("TOTAL A PAGAR: $%d\n", PRECIO_BOLETO*boletos_comprados[id]);
        printf ("\033[0m");
    }
    
    sleep(1);
    getch();
    system("cls");
    return menu();
}


int disponibilidad()
{
    printf ("\033[95m");
    printf("---------- ASIENTOS DISPONIBLES ----------\n");
    printf ("\033[0m");

    /* Se ejecuta un for la cantidad de veces equivalente al maximo de asiento, y se verifica que
    "asientos[i]" (es decir la disponibilidad del asiento actual) sea 0 (esté disponible) */
    for(i = 0; i < MAX_ASIENTOS; i++)
    {
        if(asientos[i] == 0)
        {
            /* Si el asiento está disponible, se imprime "posicion[i]" (es decir, el nombre del asiento
            en la posicion actual) */
            printf ("\033[0;33m");
            printf("DISPONIBLE: %s\n", posicion[i]);
            printf ("\033[0m");
        }
    }

    getch();
    system("cls");
    return menu();
}


/* Imprime todos los datos de un boleto usando el id ingresado como el indice para acceder a cada campo,
ya lo demas que está comentado anteriormente, leer bien */
int ver_boleto()
{
    int cont2 = 0;
    char lector_id[2];
    int counter = 0;
    printf ("\033[95m");
    printf("---------- ver boletos ----------\n\n");
    printf ("\033[0m");

    for(i = 0; i < MAX_ASIENTOS; i++)
    {
        if(boletos_comprados[i] == 0)
        {
            counter++;
        }
    }
    if(counter == MAX_ASIENTOS)
    {
        printf ("\033[0;31m");
        printf("Aun no se han vendido/asignado boletos\n");
        printf ("\033[0m");
        getch();
        system("cls");
        return menu();
    }

    printf ("\033[0;32m");
    notBlank(lector_id, "introduce el id del boleto para ver sus datos: \n");
    printf ("\033[0m");
    while(atoi(lector_id) < 1 || atoi(lector_id) > (MAX_ASIENTOS) || boletos_comprados[atoi(lector_id)-1] == 0)
    {
        printf ("\033[0;31m");
        notBlank(lector_id, "Este id no existe o no ha sido asignado, vuelve a introducirlo: \n");
        printf ("\033[0m");
    }
    id = atoi(lector_id);
    id = id-1;

    system("cls");
   clrscr();
            /*bordes izquierdos*/
gotoxy(1,2); cprintf("%c" , 201);
gotoxy(1,10); cprintf("%c" , 200);
/*bordes derechos*/
gotoxy(79,2); cprintf("%c" , 187);
gotoxy(79,10); cprintf("%c" , 188);

/*vertical*/
for (xcol = 3 ; xcol < 10; xcol++)
{
gotoxy(1,xcol); cprintf("%c" , 186);
gotoxy(79,xcol); cprintf("%c" , 186); 
}

/*hoizontal*/
for (xfil = 2; xfil <= 78; xfil++)
{
gotoxy(xfil,2); cprintf("%c" , 205);
gotoxy(xfil,10); cprintf("%c" , 205); 
}

textcolor(10); gotoxy(4,3); cprintf("ID = %d", id+1);
textcolor(10); gotoxy(4,4); cprintf("NOMBRE = %s", comprador[id]);
textcolor(10); gotoxy(4,5); cprintf("CORREO = %s", correo[id]);
textcolor(10); gotoxy(4,6); cprintf("TELEFONO = %s", telefono[id]);
textcolor(10); gotoxy(4,7); cprintf("CANTIDAD DE BOLETOS = %d", boletos_comprados[id]);
textcolor(10); gotoxy(4,8); cprintf("ASIENTOS = ");
    for(i = 0; i < MAX_COMPRA_UNITARIA; i++)
    {
        if(comprados[id][i] > -1)
        {
            printf ("\033[0;33m");
            gotoxy(15 + (cont2*4),8); cprintf(" %s ", posicion[comprados[id][i]]);
            printf ("\033[0m");
            cont2++;
        }
    }
    printf ("\033[0;35m");
    gotoxy(4,9);cprintf("TOTAL A PAGAR: $%d\n", PRECIO_BOLETO*boletos_comprados[id]);
    printf ("\033[0m");

    getch();
    system("cls");

    return menu();
}
