// Arrays, struct, cadenas de caracteres, punteros, operaciones sobre bits

struct t_dummy {
	char cx;
	char cy;
	int lat;
	int longitud;
};
struct t_dummy st;

unsigned int tabla[8]= { 0x1, 0x3, 0x5, 0x7, 0x9, 0xB, 0xD, 0xF };

// Operaciones sobre bits
#define LED1 0x01
#define LED2 0x02
static unsigned int status = 0;
// Punteros

unsigned int * puntero;
char str_tecla[27] = "\nTecla pulsada\0";;
char * puntero2;

int main() {

	st.cx = 1;
	st.cy = 2;
	st.lat = 3;
	st.longitud = 4;

	status |=  LED1;
	status &=  ~LED1;
	status ^= (LED1 | LED2);
	status = (tabla[7]<< 4 ) | tabla [2] | (tabla[4]<<8);
	status  = (status & ~(0xf << 12)) | (0x7 << 12);
// punteros y cadenas de caracteres
	puntero = tabla;
	puntero++;

	puntero2 = str_tecla;
	return 0;
}
