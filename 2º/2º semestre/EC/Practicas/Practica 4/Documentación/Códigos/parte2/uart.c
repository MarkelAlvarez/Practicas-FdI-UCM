#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "44b.h"
#include "uart.h"
#include "intcontroller.h"

#define BUFLEN 100

// Estructura utilizada para mantener el estado de cada puerto
struct port_stat {
	enum URxTxMode rxmode;       //Modo de recepción (DIS, POLL, INT, DMA)
	enum URxTxMode txmode;       //Modo de envío     (DIS, POLL, INT, DMA)
	unsigned char ibuf[BUFLEN];  //Buffer de recepción (usado en modo INT)
	int rP;                      //Puntero de lectura en ibuf (modo INT)
	int wP;                      //Puntero de escritura en ibuf (modo INT)
	char *sendP;                 //Puntero a la cadena de envío (modo INT)
	enum ONOFF echo;             //Marca si el puerto debe hacer eco de los caracteres recibidos
};

static struct port_stat uport[2]; //Array con el estado de los puertos

// COMPLETAR: Declaración adelantada de las rutinas de tratamiento de
// interrupción de la uart por línea IRQ (las marca como ISRs)
// Las rutinas son: Uart0_RxInt, Uart0_TxInt, Uart1_RxInt, Uart1_TxInt

void uart_init(void)
{
	int i;

	// Inicialización de las estructuras de estado de los puertos
	for (i=0; i < 2; i++) {
		uport[i].rxmode = DIS;
		uport[i].txmode = DIS;
		uport[i].rP = 0;
		uport[i].wP = 0;
		uport[i].sendP = NULL;
		uport[i].echo = OFF;
	}

	//COMPLETAR: Registrar adecuadamente las rutinas de tratamiento de
	//interrupción de la uart

	//COMPLETAR: Configurar las líneas de interrupción de la uart en modo IRQ
}
	
/* uart_lconf: Esta función configura el modo línea de la uart,
 *       Número de bits por trama
 *       Número de bits de parada
 *       Paridad
 *       Modo infrarrojos
 *       Baudios
 * y configura los pines adecuados para que las líneas Rx y Tx de los puertos
 * salgan fuera del chip, hacia los conectores DB9 de la placa
 */
int uart_lconf(enum UART port, struct ulconf *lconf)
{
	unsigned int confvalue = 0; // valor de configuración del registro ULCON
	int baud;
		
	// COMPLETAR: darle a confvalue el valor adecuado en función de la
	// configuración deseada (parámetro lconf)

	baud = (int)( MCLK /(16.0 * lconf->baud) + 0.5) - 1;

	switch (port) {
		case UART0:
			rULCON0 = confvalue;
			rUBRDIV0 = baud;
			// habilitamos la salida fuera del chip de las señales RxD0 y TxD0
			rPCONE = (rPCONE & ~(0xF << 2)) | (0x2 << 2) | (0x2 << 4);
			break;

		case UART1:
			rULCON1 = confvalue;
			rUBRDIV1 = baud;
			// habilitamos la salida fuera del chip de las señales RxD1 y TxD1
			rPCONC = rPCONC  | (0xF << 24);
			break;

		default:
			return -1;
	}

	uport[port].echo = lconf->echo;

	return 0;
}

/* uart_conf_txmode: función que configura el modo de transmisión del puerto
 */
int uart_conf_txmode(enum UART port, enum URxTxMode mode)
{
	int conf = 0; //variable para modo POLL/INT o DMA

	if (mode < 0 || mode > 3)
		return -1;

	if (port < 0 || port > 1)
		return -1;

	switch (mode) {
		case POLL:
		case INT:
			conf = 1;
			break;
		case DMA:
			conf = (port == UART0) ? 2 : 3;
			break;
		default:
			conf = 0;
	}
		

	switch (port) {
		case UART0:
			rUCON0 = //COMPLETAR: modo indicado por conf, Tx interrupt por nivel
			break;

		case UART1:
			rUCON1 = //COMPLETAR: modo indicado por conf, Tx interrupt por nivel
			break;
	}

	uport[port].txmode = mode;

	return 0;
}

/* uart_conf_rxmode: función que configura el modo de recepción del puerto
 */
int uart_conf_rxmode(enum UART port, enum URxTxMode mode)
{
	int conf = 0; //variable para modo POLL/INT o DMA

	if (mode < 0 || mode > 3)
		return -1;

	if (port < 0 || port > 1)
		return -1;

	switch (mode) {
		case POLL:
		case INT:
			conf = 1;
			break;
		case DMA:
			conf = (port == UART0) ? 2 : 3;
			break;
		default:
			conf = 0;
	}

	switch (port) {
		case UART0:
			rUCON0 = //COMPLETAR: modo indicado por conf, Rx interrupt por pulso
			//COMPLETAR: si se el modo es por interrupciones habilitar la línea
			//de interrupción por recepción en el puerto 0
			break;

		case UART1:
			rUCON1 = //COMPLETAR: modo indicado por conf, Rx interrupt por pulso
			//COMPLETAR: si se el modo es por interrupciones habilitar la línea
			//de interrupción por recepción en el puerto 1
			break;
	}

	uport[port].rxmode = mode;

	return 0;
}

/* uart_rx_ready: función que realiza un espera activa hasta que el puerto haya
 * recibido un byte
 */
static void uart_rx_ready(enum UART port)
{
	switch (port) {
		case UART0:
			//COMPLETAR: esperar a que la uart0 haya recibido un dato (UTRSTAT0,
			//Receive Buffer Data Ready)
			break;

		case UART1:
			//COMPLETAR: esperar a que la uart1 haya recibido un dato (UTRSTAT1,
			//Receive Buffer Data Ready)
			break;
	}
}

/* uart_tx_ready: función que realiza un espera activa hasta que se vacíe el
 * buffer de transmisión del puerto
 */
static void uart_tx_ready(enum UART port)
{
	switch (port) {
		case UART0:
			//COMPLETAR: esperar a que se vacíe el buffer de transmisión de la
			//uart0 (UTRSTAT0, Transmit Buffer Empty)
			break;

		case UART1:
			//COMPLETAR: esperar a que se vacíe el buffer de transmisión de la
			//uart1 (UTRSTAT1, Transmit Buffer Empty)
			break;
	}
}

/* uart_write: función que escribe un byte en el buffer de transmisión del
 * puerto
 */
static void uart_write(enum UART port, char c)
{
	if (port == UART0)
		//COMPLETAR: Escribir el carácter c en el puerto 0, usar la macro WrUTXH0
	else
		//COMPLETAR: Escribir el carácter c en el puerto 1, usar la macro WrUTXH1
}
 
/* uart_read: función que lee un byte del buffer (registro) de recepción del
 * puerto, y hace el eco del carácter si el puerto tiene el eco activado
 */
static char uart_read(enum UART port)
{
	char c;

	if (port == UART0)
		c = //COMPLETAR: Leer un byte del puerto 0, usar la macro RdUTXH0
	else
		c = //COMPLETAR: Leer un byte del puerto 1, usar la macro RdUTXH1

	if (uport[port].echo == ON) {
		//COMPLETAR: Esperar a que el puerto esté listo para transmitir
		//COMPLETAR: Escribir el carácter leído (c) en el puerto port
	}
	return c;
}

/* uart_readtobuf: función invocada por la ISR de recepción. Su misión es
 * escribir el carácter recibido en el buffer de reccepción del puerto (campo
 * ibuf de la estructura port_stat correspondiente)
 */
static void uart_readtobuf(enum UART port)
{
	char c;
	struct port_stat *pst = &uport[port];

	/* COMPLETAR:
	 * 1. Leer un byte del puerto y copiarlo en el buffer de reccepción del
	 *    puerto en la posición indicada por el puntero de escritura.
	 *
	 * 2. Incrementar el puntero de escritura y si es necesario corregir su
	 *    valor para que esté siempre en el rango 0 - BUFLEN-1 (gestionado de
	 *    forma circular)
	 */
}

/* uart_readfrombuf: función invocada por uart_getch en el caso de que el puerto
 * esté configurado por interrupciones para la recepción. Su misión es esperar a
 * que al menos haya un byte en el buffer de recepción, y entonces sacarlo del
 * buffer y devolverlo como byte leído.
 */
static char uart_readfrombuf(enum UART port)
{
	struct port_stat *pst = &uport[port];

	/* COMPLETAR:
	 * 1. Corregir (de forma circular) el valor del puntero de lectura si está
	 *    fuera del rango 0 - BUFLEN-1.
	 * 2. Esperar a que el buffer de recepción contenga algún byte.
	 * 3. Extraer el primer byte y devolverlo (el byte se devuelve y el puntero
	 *    de lectura se deja incrementado, con lo que el byte queda fuera del
	 *    buffer)
	 */
}

/* ISR de recepción por el puerto 0 */
void Uart0_RxInt(void)
{
	uart_readtobuf(UART0);
	
	//COMPLETAR: borrar el flag de interrupción por recepción en el puerto 0
}

/* ISR de recepción por el puerto 1 */
void Uart1_RxInt(void)
{
	uart_readtobuf(UART1);
	
	//COMPLETAR: borrar el flag de interrupción por recepción en el puerto 1
}

/* uart_dotxint: rutina invocada por la ISR de transmisión. Su misión es enviar
 * el siguiente byte del buffer de transmisión, apuntado por el campo sendP de
 * la estructura port_stat asociada al puerto, y si la transmisión ha finalizado
 * desactivar las interrupciones de envío y señalizar el final del envío
 * poniendo el puntero sendP a NULL.
 */
static void uart_dotxint(enum UART port)
{
	struct port_stat *pst = &uport[port];

	if (*pst->sendP != '\0' ) {
		if (*pst->sendP == '\n') {
			/* Para que funcione bien con los terminales windows, vamos a hacer
			 * la conversión de \n por \r\n, por tanto enviamos un carácter \r
			 * extra en este caso
			 */
			//COMPLETAR: enviar \r y esperar a que el puerto quede libre para
			//enviar
		}
		//COMPLETAR: enviar el carácter apuntado por sendP e incrementar dicho
		//puntero
	}

	if (*pst->sendP == '\0') {
		//COMPLETAR: si hemos llegado al final de la cadena de caracteres
		// deshabilitamos la línea de interrupción por transmisión del puerto
		// y ponemos el puntero sendP a NULL
	}
}

/* ISR de transmisión por el puerto 0 */
void Uart0_TxInt(void)
{
	uart_dotxint(UART0);
	
	//COMPLETAR: borrar el flag de interrupción por transmisión en el puerto 0
}

/* ISR de transmisión por el puerto 1 */
void Uart1_TxInt(void)
{
	uart_dotxint(UART1);
	
	//COMPLETAR: borrar el flag de interrupción por transmisión en el puerto 1
}


/* uart_getch: función bloqueante (síncrona) para la recepción de un byte por el
 * puerto serie
 */
int uart_getch(enum UART port, char *c)
{
	if (port < 0 || port > 1)
		return -1;

	switch (uport[port].rxmode) {
		case POLL:
			// COMPLETAR: Esperar a que el puerto port haya recibido un byte
			// Leer dicho byte y escribirlo en la dirección apuntada por c
			break;

		case INT:
			// COMPLETAR: Leer el primer byte del buffer de recepción del puerto
			// y copiarlo en la dirección apuntada por c
			break;

		case DMA:
			//OPCIONAL
			return -1;
			break;

		default:
			return -1;
	}

	return 0;
}

/* uart_sendch: función bloqueante (síncrona) para la transmisión de un byte por el
 * puerto serie
 */
int uart_sendch(enum UART port, char c)
{
	char localB[2] = {0};

	if (port < 0 || port > 1)
		return -1;

	switch (uport[port].txmode) {
		case POLL:
			/* COMPLETAR: 
			 * 1. Esperar a que el puerto esté listo para transmitir un byte
			 * 2. Si el byte es \n envíamos primero \r y volvemos a esperar a
			 *    que esté listo para transmitir
			 * 3. Enviamos el carácter c por el puerto
			 */
			break;

		case INT:
			localB[0] = c;
			uart_send_str(port, localB);
			break;

		case DMA:
			//OPCIONAL
			return -1;
			break;

		default:
			return -1;
	}

	return 0;
}

/* uart_send_str: función bloqueante (síncrona) para la transmisión de una
 * cadena de caracteres por el puerto serie
 */
int uart_send_str(enum UART port, char *str)
{
	int line;

	if (port < 0 || port > 1)
		return -1;

	switch (uport[port].txmode) {
		case POLL:
			//COMPLETAR: usar uart_sendch para enviar todos los bytes de la
			//cadena apuntada por str
			break;

		case INT:
			/* COMPLETAR:
			 * 1. Hacer que el puntero del buffer de envío (campo sendP en la
			 *    estructura port_stat del puerto) apunte al comienzo de la
			 *    cadena str.
			 * 2. Habilitar las interrupciones por transmisión en el puerto
			 * 3. Esperar a que se complete el envío (la ISR pondrá a NULL el
			 *    puntero de envío sendP)
			 */
			break;

		case DMA:
			//TODO
			return -1;
			break;

		default:
			return -1;
	}

	return 0;

}

/* uart_printf: función bloqueante (síncrona) para la transmisión de una
 * cadena de caracteres con formato por el puerto serie
 */
void uart_printf(enum UART port, char *fmt, ...)
{
    va_list ap;
    char str[256];

    va_start(ap, fmt);
    vsnprintf(str, 256, fmt, ap);
    uart_send_str(port, str);
    va_end(ap);
}

