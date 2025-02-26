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

/* Se genera el nombre de los asientos en base a la cantidad maxima, y su limite por filas */
char letra = 65;
char numero = '1';
/* Superior solo se usa para saber si se excedio la cantidad de letras mayusculas en los nombres,
para asi parar a nombrar los asientos con letras minusculas */
int superior = 0;

int entrar, entrar2;

int main()
{

    /* for que recorre cada espacio de los asientos para asiganarlos como libres, darles nombre, y
    especificar que el numero total de compras en 0 */
    for (i = 0; i < MAX_ASIENTOS; i++)
    {
        /* Si se supera el valor numerico 90 (equivalente a z en ascii), se pasa a nombrar con letras
        minusculas (la primera de todas tiene valor 97 en ascii) */
        if (numero - 49 == MAX_ASIENTOS_FILA)
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
        for (j = 0; j < MAX_COMPRA_UNITARIA; j++)
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



    /* Varifica si el usuario es correcto */
    if (login("admin", "Usuario") == 0)
    {
      /* Verifica si la contraseña es correcta */
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

