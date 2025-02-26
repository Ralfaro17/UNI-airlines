
/* Macros y/o constantes para usar en multiples partes del codigo */
#define MAX_ASIENTOS 10
#define MAX_ASIENTOS_FILA 2
#define MAX_COMPRA_UNITARIA 3
#define PRECIO_BOLETO 100

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
