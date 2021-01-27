#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

int selectPatternMenu();
int selectSpeed();
void contadorBinarioAscendente(int file, int vel);
void circular(int file, int vel);
void alternando(int file, int vel);
void si(int file);

int main() {

    int pattern;
    int ledsFile = open("/dev/leds", O_WRONLY | O_CREAT | O_TRUNC);

    while(pattern = selectPatternMenu()){

        switch (pattern){

            case 0: return 0;
                break;

            case 1:
                contadorBinarioAscendente(ledsFile, selectSpeed());
                break;

            case 2:
                circular(ledsFile, selectSpeed());
                break;

            case 3:
                alternando(ledsFile, selectSpeed());
                break;

            case 4:
            	si(ledsFile);
                break;

            default: 
                printf("Introduzca una opción válida.\n");
                break;
        }

    }

    close(ledsFile);
    return 0;

}

int selectPatternMenu(){

    int pattern;

    printf("0- Salir\n");
    printf("1- Contador binario ascendente.\n");
    printf("2- Circular\n");
    printf("3- Alternando\n");
    printf("4- Monitorea diferentes opciones\n");
    printf("Introduzca su opcion: ");
    scanf("%i", &pattern);
    printf("-----------------------------------\n");

    return pattern;

}

int selectSpeed() {

    int vel = 1;
    int aux;
    printf("Introduzca la velocidad en milisegundos que desea: ");
    scanf("%i", &aux);
    if (aux)
        vel = abs(aux);

    return (1000 * vel);

}

void contadorBinarioAscendente(int file, int vel){

    char* states[8] = {"", "3", "2", "23", "1", "13", "12", "123"};
    int i;

    for (i = 0; i < 8; i++){
        write(file, states[i], strlen(states[i]));
        usleep(vel);
    }

    write(file, "0", 1);

} 

void circular(int file, int vel){

    char* states[8] = {"3", "2", "1"};
    int i;

    for (i = 0; i < 15; i++){
        write(file, states[i%3], strlen(states[i%3]));
        usleep(vel);
    }

    write(file, "0", 1);

}

void alternando(int file, int vel){

    char* states[8] = {"13", "2"};
    int i;

    for (i = 0; i < 10; i++){
        write(file, states[i%2], strlen(states[i%2]));
        usleep(vel);
    }

    write(file, "0", 1);

}

void si(int file){

	int fd;
	int wd;
	char buffer[EVENT_BUF_LEN];
	int length;
	int i;
	int op;

	fd = inotify_init();
	if ( fd < 0 )
    	perror("inotify_init");

    	printf("Chose the device to monitor:\n");
    	printf("1- Touchpad\n");
    	printf("2- USB keyboard\n");
    	printf("3- Keyboard\n");
    	printf("4- CPU\n");

    	scanf("%d",&op);

    	if (op == 1) wd = inotify_add_watch(fd, "/dev/input/by-path/pci-0000:00:15.1-platform-i2c_designware.1-event-mouse", IN_ACCESS);
    	else if (op == 2) wd = inotify_add_watch(fd, "/dev/input/by-id/usb-Cherry_GmbH_SmartBoard_XX44-event-kbd", IN_ACCESS);
    	else if (op == 3) wd = inotify_add_watch(fd, "/dev/input/by-path/platform-i8042-serio-0-event-kbd", IN_ACCESS);
    	else if (op == 4) wd = inotify_add_watch(fd, "/proc/stat", IN_ACCESS);
    	else wd = inotify_add_watch(fd, "/dev/input/by-id/usb-LITEON_Technology_USB_Multimedia_Keyboard-event-kbd", IN_ACCESS);

    	while(1)
	{
    		i = 0;
    		length = read(fd, buffer, EVENT_BUF_LEN);

    		while ( i < length )
		{   
    			struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];
			if(event->mask & IN_ACCESS)
			{
				printf("event detected IN_ACCESS\n");
				write(file, "123", 3);
				usleep(50);
			}

			i += EVENT_SIZE + event->len;

    		}
		write(file, "", 1);
    	}

    	inotify_rm_watch(fd, wd);
    	close(fd);
}