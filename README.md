# Proyecto final de introducción a la ingeniería en computación

> [!CAUTION]
> Este programa está diseñado para ejecutarse en Turbo C++, utilizando el modor grafico proporcionado por la libreria Graphics.h nativa de Turbo C 2.0, pero se utilizo la version 3.0


**FUNCIONES**

funciones para definir la funciones del mouse

        msituar - funcion para situar el puntero en un punto especifico
            modo es el modo (no me acuero para que era XD)
            x1 - parametro x en el plano donde se colocara horizontalmente
            y1 -  parametro y en el plano donde se colocara verticalmente

        minlimit - funcion para verificar si el mouse se encuentra en el area delimitada en el plano, esta funcion calcula el area de forma rectangular que el primer par de coordenadas es el punto mas alto derecho y el segundo par de puntos es el punto mas bajo al izquierda

            modo es modo (sigo sin acordarme)
            x1, y1 - primer par de coordenadas, lo cual respactivamente x1 es para el coordenada en horizontal y y1 para la vertical respectivamente
            x2, y2 - segundo par de coordenadas, de tal manera que mismo modo que los punto x1 e y1 representan los dos puntos x2 e y2

        mshow - funcion para mostrar el puntero
            esta no tiene parametros de uso, por lo tanto su uso es unicamente llamar la funcion

        mocultar - funcion para ocultar el punto
            esta no tiene parametros de uso, por lo tanto su uso es unicamente llamar la funcion

        mouseinit - funcion para inicializar el puntero del mouse
            (esto en el documento de Grevin pero me da pereza buscarlo)


pintarAreaRectangulo - Esta funcion es para mejorar el uso de tal forma que con una funcion haces las tres cosas rapido, cabe aclarar de definir y incializar el modo grafico primeramente

        los parametros de coordenadas son x e y los cuale sos dos para poder dar las dimeciones del rectangulo
        relleno - una constante de tipo entero la cuales estan en la tabla de abajo que ya estan definidas por la misma libreria
        Color - una constante de tipo entero la cuales representan los colore van del 0 al 15 siendo 0 negro, igualmente ya definidas por la libreria


**Curiosidades**

Hay unas funciones las cuales no estan definidas nativamente, que en este proyeco se desarrollaron para un uso mas consistente y de mayor facilidad

Entre las cuales tenemos los estilos de relleno que se stan utilizando y colores los cuales tambien como lo estilos son opcines definidas nativamente por la libreria conio.h aqui una tabla para los estilos de relleno y colores con sus corresponiente descripcion


| Constante        | **Descripción**                          |
|------------------|--------------------------------------|
| EMPTY_FILL      | Sin relleno                          |
| SOLID_FILL      | Relleno sólido                       |
| LINE_FILL       | Líneas horizontales                  |
| LTSLASH_FILL    | Líneas diagonales finas             |
| SLASH_FILL      | Líneas diagonales gruesas           |
| BKSLASH_FILL    | Líneas diagonales invertidas        |
| LTBKSLASH_FILL  | Líneas diagonales finas invertidas  |
| HATCH_FILL      | Patrón de cuadros                   |
| XHATCH_FILL     | Cruce de líneas                     |
| INTERLEAVE_FILL | Líneas intercaladas                 |
| WIDE_DOT_FILL   | Patrón de puntos anchos             |
| CLOSE_DOT_FILL  | Patrón de puntos pequeños           |


| Constante       | **Color**             | Código RGB          |
|-----------------|-------------------|----------------------|
| BLACK          | Negro             | (0, 0, 0)           |
| BLUE           | Azul              | (0, 0, 255)         |
| GREEN          | Verde             | (0, 255, 0)         |
| CYAN           | Cian              | (0, 255, 255)       |
| RED            | Rojo              | (255, 0, 0)         |
| MAGENTA        | Magenta           | (255, 0, 255)       |
| BROWN          | Marrón            | (165, 42, 42)       |
| LIGHTGRAY      | Gris claro        | (211, 211, 211)     |
| DARKGRAY       | Gris oscuro       | (169, 169, 169)     |
| LIGHTBLUE      | Azul claro        | (173, 216, 230)     |
| LIGHTGREEN     | Verde claro       | (144, 238, 144)     |
| LIGHTCYAN      | Cian claro        | (224, 255, 255)     |
| LIGHTRED       | Rojo claro        | (255, 182, 193)     |
| LIGHTMAGENTA   | Magenta claro     | (255, 160, 211)     |
| YELLOW         | Amarillo          | (255, 255, 0)       |
| WHITE          | Blanco            | (255, 255, 255)     |

![COCO](https://i.blogs.es/2f4318/team-fortress-2-2/450_1000.jpeg)
