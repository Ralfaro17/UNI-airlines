#ifndef funciones_h
#define funciones_h


/* Prototipos de las funciones */
void logout();
void notBlank();
int login(char validacion[20], char Campo[20]);
int menu();
int presentacion();
int adquirir();
int cancelar();
int disponibilidad();
int ver_boleto();
int Valoracion(char Entrada[20], char Validacion[20]);

void pintarAreaRectangulo(int x, int y, int x2, int y2, int relleno, int color);

void msituar(int modo, int x, int y);
int minlimit(int modo, int x1, int y1, int x2, int y2);


#endif