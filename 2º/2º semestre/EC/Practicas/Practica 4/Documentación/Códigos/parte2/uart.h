#ifndef UART_H_
#define UART_H_

enum UART {
	UART0 = 0,
	UART1 = 1
};

enum UPARITY {
	NONE = 0,
	ODD = 1,
	EVEN = 2,
	FONE = 3,
	FZERO = 4
};

enum ONOFF {
	OFF = 0,
	ON = 1
};

enum USTOPB {
	ONE = 0,
	TWO = 1,
};


enum UWORDLEN {
	FIVE = 0,
	SIX  = 1,
	SEVEN = 2,
	EIGHT = 3
};

enum URxTxMode {
	DIS = 0,
	POLL = 1,
	INT = 2, 
	DMA = 3
};

struct ulconf {
	enum ONOFF ired;   // infrared on/off
	enum UPARITY par; // partity
	enum USTOPB stopb;        // stop bits 1 or 2
	enum UWORDLEN wordlen;
	enum ONOFF echo;
	int baud;
};

	
void uart_init(void);
int uart_lconf(enum UART port, struct ulconf *lconf);
int uart_conf_txmode(enum UART port, enum URxTxMode mode);
int uart_conf_rxmode(enum UART port, enum URxTxMode mode);
int uart_getch(enum UART port, char *c);
int uart_sendch(enum UART port, char c);
int uart_send_str(enum UART port, char *str);
void uart_printf(enum UART port, char *fmt, ...);

#endif
