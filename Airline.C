#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

#include "funciones.h"


/* Macros y/o constantes para usar en multiples partes del codigo */
#define MAX_ASIENTOS 10
#define MAX_ASIENTOS_FILA 2
#define MAX_COMPRA_UNITARIA 3
#define PRECIO_BOLETO 100

/* inclusion de librerias para el uso de los graficos y mouse por parte del lenguaje */
#include <graphics.h>
#include <mouse.h>
/*
    funcion para inicializar el modo grafico
    coco porque lleva todo

*/
int coco = DETECT, modo, errorcode;

/* Variables iteradoras */
int contador = 0, i, j, k;


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
int vlongitud, vlongitudmenu, xcol, xfil, vcolor, vcentromenu, vcentro;

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
int Valoracion(char Entrada[20], char Validacion[20]);

void pintarAreaRectangulo(int x, int y, int x2, int y2, int relleno, int color);


int main()
{

    /* inicialiar el modo grafico */
    initgraph(&coco, &modo, "C:\\turboc3\\bgi");

    /* retorno temprano por si pasa algo malo  */
    errorcode = graphresult();
    if (errorcode != grOk) /* an error occurred */
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1); /* terminate with an error code */
    }



    if (login("admin", "Usuario") == 0)
    {
         
        if (login("1234", "password") == 0)
        {
            cleardevice();
            menu();
        }
    }
    else
    {
        logout();
    }


    return 0;
}


/* xd */
void logout()
{
    cleardevice();
    outtextxy(255, 220, "Saliendo");
    getch();
    exit(1);
}

/* Verifica que la clave y el usuario sean los correctos, y bloquea el programa al tercer intento */
int login(char validacion[20], char Campo[20])
{
    char user[20];
    char key;
    char EntradaTeclado[20] = "";
    int iEntrada = 0, intentos = 3;
    char input_pass[20];
    pintarAreaRectangulo(0, 0, 680, 600, WIDE_DOT_FILL, BLUE);
    outtextxy(255, 200, "Ingrese el ");
    outtextxy(345, 200, Campo);
    
    /* Validar si se ha precionado una tecla */
    do{  
        /* Validamos si hay entrada por el teclado */
        if (kbhit())
        {
            printf("%i",iEntrada);
            /* Validar si intentos se acabaron */
            if (intentos <= 0)
            {
                logout();
            }

            /* se obtine la tecla presionada*/
            key = getch();

            /* Validamos si se la tecla precionada es enter y logica para el usuario*/
            if (key == 13)
            {
                /* guardamos el string obtenido en la variable user */
                strcpy(user, EntradaTeclado);
                /* validamos si no es un espacio en blanco y si coincide con el usuario */
                if (strcmp(user, " ") != 0 && Valoracion(user, validacion) == 0)
                {
                    strcpy(EntradaTeclado, " ");
                    pintarAreaRectangulo(245, 210, 265 + (15 * (iEntrada + 1)), 220, WIDE_DOT_FILL, BLUE);
                    return 0;
                }

                
                /* evitar errores visuales */
                if(intentos == 3)
                {
                    outtextxy(245, 220, "Ingrese el campo correcto");
                }
                strcpy(EntradaTeclado, 00);
                pintarAreaRectangulo(245, 210, 265 + (15 * (iEntrada + 1)), 215, WIDE_DOT_FILL, BLUE);
                iEntrada = 0;
                intentos--;
            }
            /* logtica para borrar cuando l9e das a backspaces */
            else if (key == 8 && iEntrada >= 0)
            {
                /* Elimina el ultimo caracter escrito igualandolo a NULL */
                EntradaTeclado[iEntrada] = 00;
                /* Se borra los escrito ateriormnete tapandolo con un rectangulo, la distancia se calcula con respecto al valor de interacion que se calcula cuando se toca alguna tecla */
                pintarAreaRectangulo(235, 210, 275 + (15 * (iEntrada + 1)), 220, WIDE_DOT_FILL, BLUE);
                iEntrada--;
                outtextxy(255, 210, EntradaTeclado);

                /* para evitar errores con el borrado */
                if (iEntrada < 0)
                    iEntrada++;
                
            }
            /* valida si no es el backspaces y si hay espcio para guardar el texto */
            else if (key != 8 && iEntrada != 20)
            {
                /* guardamos en el la variable y lo mostramos */
                EntradaTeclado[iEntrada] = key;
                /* Se suma a la interacion */
                iEntrada++;
                /* se manda a imprimir */
                outtextxy(255, 210, EntradaTeclado);

            }

            /* validar escape para salir del programa */
            if (key == 27)
            {
                logout();
            }
        }

    } while (intentos > 0);
    return 1;
}

/* Muestra toda la interfaz de opciones que se pueden realizar,
cada opcion retorna una funcion que ejecuta su accion correspondiente */
int menu()
{

    return 1;
}

int presentacion()
{


    return menu();
}

/* Funcion para comprar boletos */
int adquirir()
{

    return menu();
}

/* casi la misma logica que adquirir, solo que aqui se pide el id del boleto para usarlo como
indice/referencia o posicion que tiene guardados los datos de la persona */
int cancelar()
{
    
    return menu();
}

int disponibilidad()
{
  
    return menu();
}

/* Imprime todos los datos de un boleto usando el id ingresado como el indice para acceder a cada campo,
ya lo demas que está comentado anteriormente, leer bien */
int ver_boleto()
{
    
    return menu();
}

void pintarAreaRectangulo(int x, int y, int x2, int y2, int relleno, int color)
{
    setfillstyle(relleno, color);
    rectangle(x, y, x2, y2);
    bar(x, y, x2, y2);
}



int Valoracion(char Entrada[20], char Validacion[20])
{
    int i = 0;
    do
    {
        if (Entrada[i] > 96 && Entrada[i] < 123)
            Entrada[i] = Entrada[i] - 32;

        i++;
    } while (Entrada[i] != NULL);
    i = 0;
    do
    {
        if (Validacion[i] > 96 && Validacion[i] < 123)
            Validacion[i] = Validacion[i] - 32;
            i++;
    } while(Validacion[i] != NULL);
    

    if (strcmp(Entrada, Validacion) == 0)
    {
        printf("Sexo");
        return 0;
    }
    return 1;
}