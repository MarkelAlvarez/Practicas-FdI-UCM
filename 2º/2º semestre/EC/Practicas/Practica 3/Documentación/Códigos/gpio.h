#ifndef GPIO_H_
#define GPIO_H_

enum digital {
	LOW = 0,
	HIGH = 1
};

enum port_mode {
	INPUT  = 0,
	OUTPUT = 1,
	SIGOUT = 2,
	EINT   = 3
};

enum trigger {
	LLOW  = 0,
	LHIGH = 1,
	FALLING = 2,
	RISING  = 3,
	EDGE    = 4
};

// Port B interface
int portB_conf(int pin, enum port_mode mode);
int portB_write(int pin, enum digital val);

// Port G interface
int portG_conf(int pin, enum port_mode mode);
int portG_eint_trig(int pin, enum trigger trig);
int portG_write(int pin, enum digital val);
int portG_read(int pin, enum digital* val);
int portG_conf_pup(int pin, enum enable st);

#endif
