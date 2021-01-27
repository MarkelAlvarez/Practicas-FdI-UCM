#!/bin/bash
devfile="/dev/leds"
delay="0.35"
sequence1="3 2 1"
sequence2="- 3 2 23 1 13 12 123"
resume_text="Teclea ENTER para continuar..."
sep='#################################################'
sep2='-------------------------------------------------'

if [ ! -c  "$devfile" ]; then
	echo "Fichero de dispositivo $devfile no existe" 1>&2
	echo '¿Has cargado el módulo del kernel y creado el fichero de dispositivo con mknod?' 1>&2
	exit 1
fi 

echo "Fichero $devfile existe"
echo $sep
echo "TEST1: Secuencia LEDS registro de desplazamiento"
echo $sep2

for (( i=0; $i < 5 ; i++))
do
	for str in $sequence1
	do
		if [ "$str" == "-" ]; then
			str=" "
		fi
		sudo echo $str > $devfile
		sleep $delay
	done
done

sudo echo > $devfile

echo "fin TEST1. $resume_text"
read
echo $sep

echo "TEST2: Secuencia LEDS contador binario mod-8"
echo $sep2

for (( i=0; $i < 3 ; i++))
do
	for str in $sequence2
	do
		if [ "$str" == "-" ]; then
			str=" "
		fi
		sudo echo $str > $devfile
		sleep $delay
	done
done

sudo echo > $devfile
echo "fin TEST2. $resume_text"
read
echo $sep


echo "TEST3: Debería mostrarse 'error de escritura: Operación no permitida'"
echo $sep2
echo 12 > /dev/leds
echo $sep
sudo echo > $devfile
echo "TEST4: Otras cadenas válidas"
echo $sep2
echo "Se deberían encender los leds de la derecha y centro"
sudo echo "32" > /dev/leds 
sleep 2
sudo echo > $devfile
echo "Se deberían encender los leds de la derecha y centro"
sudo echo "2222232" > /dev/leds 
sleep 2
sudo echo > $devfile
echo "Se deberían encender los leds de la izquierda y derecha"
sudo echo "31" > /dev/leds 
sleep 2
sudo echo > $devfile
echo "Se deberían encender los leds de la izquierda y derecha"
sudo echo "3333313" > /dev/leds 
sleep 2
sudo echo > $devfile
echo $sep

echo "TEST5: Cadenas inválidas. Debería mostrarse 'error de escritura: Argumento invalido' y no alterarse el estado de los leds"
echo $sep2

for cadena in 'aaa' '12452' '32aa' '---76' '_____86'
do
	echo -n "Escribiendo cadena $cadena -> "
	echo $cadena > /dev/leds
	echo $sep2
	sleep 1
done
echo $sep


echo "TEST6: Cadena demasiado larga. Debería mostrarse 'error de escritura: No queda espacio en el dispositivo' y no alterarse el estado de los leds"
echo $sep2
cadena=`python -c 'print "A"*500'`
echo -n "Escribiendo cadena $cadena -> "
echo $cadena > /dev/leds
echo $sep2
echo $sep