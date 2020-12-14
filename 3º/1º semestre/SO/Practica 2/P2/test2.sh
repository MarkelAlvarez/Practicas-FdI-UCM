#!/bin/bash


#a) Copie dos ficheros de texto que ocupen más de un bloque (por ejemplo fuseLib.c y myFS.h) a nuestro SF y a un directorio temporal, por ejemplo ./temp
echo "Creando nuestro SF..."
if [ -d mount-point ]; then
    rm -rf mount-point/*
else
    mkdir mount-point
fi

echo "Creando un directorio temporal..."
if [ -d tmp ]; then
    rm -rf tmp/*
else
    mkdir tmp
fi
echo "Iniciamos el copiado de archivos..."
cp src/fuseLib.c mount-point/fuseLib.c
cp src/fuseLib.c tmp/fuseLib.c

cp src/myFS.c mount-point/myFS.c
cp src/myFS.c tmp/myFS.c
sleep 2
echo "Hecho"
#b) Audite el disco y haga un diff entre los ficheros originales y los copiados en el SF. Trunque el primer fichero (man truncate) en copiasTemporales y en nuestro SF de manera que ocupe ocupe un bloque de datos menos.
echo "Empezando la auditoria..."
./my-fsck virtual-disk
if diff -q mount-point/fuseLib.c tmp/fuseLib.c; then
    echo "fuseLib.c IGUAL"
else
    echo "fuseLib.c DISTINTO"
fi

if diff -q mount-point/myFS.c tmp/myFS.c; then
    echo "myFS.c IGUAL"
else
    echo "myFS.c DISTINTO"
fi

truncate -s -4096 mount-point/fuseLib.c
truncate -s -4096 tmp/fuseLib.c
#c) Audite el disco y haga un diff entre el fichero original y el truncado.
./my-fsck virtual-disk
if diff -q src/fuseLib.c mount-point/fuseLib.c; then
    echo "fuseLib.c y el truncado IGUALES"
else
    echo "fuseLib.c y el truncado DISTINTOS"
fi
#d) Copie un tercer fichero de texto a nuestro SF.
cp src/fuseLib.h mount-point/fuseLib.h
#e) Audite el disco y haga un diff entre el fichero original y el copiado en el SF
./my-fsck virtual-disk
if diff -q src/fuseLib.h mount-point/fuseLib.h; then
    echo "El original y el truncado IGUALES"
else
    echo "El original y el truncado DISTINTOS"
fi
#f) Trunque el segundo fichero en copiasTemporales y en nuestro SF haciendo que ocupe algún bloque de datos más.
truncate -s +8192 mount-point/myFS.c
truncate -s +8192 tmp/myFS.c
#g) Audite el disco y haga un diff entre el fichero original y el truncado.
./my-fsck virtual-disk
if diff -q src/myFS.c mount-point/myFS.c; then
    echo "El original y el truncado IGUALES"
else
    echo "El original y el truncado DISTINTOS"
fi

echo "Desmontamos el punto de montaje"
fusermount -u mount-point