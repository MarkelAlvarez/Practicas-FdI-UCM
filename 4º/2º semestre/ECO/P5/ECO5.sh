#!/bin/sh
echo "\e[33m\nAPARTADO 1: UnixBench\e[0m"
echo "\e[32mDescargando y compilando UnixBench\e[0m"
wget https://github.com/kdlucas/byte-unixbench/archive/v5.1.3.tar.gz 
tar -zxf v5.1.3.tar.gz 
cd byte-unixbench-5.1.3/UnixBench 
make
echo "\e[32mEjecutando el conjunto de pruebas por defecto\e[0m"
chmod +x Run
./Run -i 3

echo "\n\e[33m\nAPARTADO 2: IOzone\e[0m"
echo "\e[32mDescargando y compilando IOzone\e[0m"
wget http://www.iozone.org/src/current/iozone3_489.tar
tar -xf iozone3_489.tar
cd iozone3_489
make -C src/current linux
echo "\e[32mConsultando el manual de IOzone...\e[0m"
man docs/iozone.1
echo "\e[32mEjecutando una prueba sobre un fichero de 100MB...\e[0m"
src/current/iozone -s 100m
echo "\e[32mRepitiendo la prueba con la opción -I\e[0m"
src/current/iozone -I -s 100m
echo "\e[32mRepitiendo la prueba anterior con la opción -r 16k\e[0m"
src/current/iozone -I -s 100m -r 16k

echo "\n\e[33m\nAPARTADO 3: iPerf3\e[0m"
echo "\e[32mDescargando y compilando iPerf3\e[0m"
wget https://github.com/esnet/iperf/archive/3.7.tar.gz
tar zxf 3.7.tar.gz
cd iperf-3.7
./configure
make
sudo make install
echo "\e[32mArrancando servidor TCP\e[0m"
LD_LIBRARY_PATH=/usr/local/lib/ iperf3 -s
echo "\e[32mAbre otro terminal y ejecuta \"LD_LIBRARY_PATH=/usr/local/lib/ iperf3 -c localhost\", pulsa cualquier tecla cuando hayas terminado\e[0m"
read tecla
echo "\e[32mRepitiendo la prueba anterior con la opción -z\e[0m"
LD_LIBRARY_PATH=/usr/local/lib/ iperf3 -s -z

echo "\n\e[33m\nAPARTADO 4: Phoronix Test Suite\e[0m"
echo "\e[32mDescargando, compilando y ejecutando iPerf3\e[0m"
sudo apt-get install php5-cli
wget http://phoronix-test-suite.com/releases/phoronix-testsuite-9.4.0.tar.gz
tar zxf phoronix-test-suite-9.4.0.tar.gz
cd phoronix-test-suite
rm pts-core/objects/pts_openbenchmarking_upload.php
sudo ./install-sh
phoronix-test-suite
echo "\e[32mEdita el archivo \"~/.phoronix-test-suite/user-config.xml\" y estable la opción \"DynamicRunCount\" a \"FALSE\"\e[0m"
nano ~/.phoronix-test-suite/user-config.xml
echo "\e[32mEjecuta la primera prueba\e[0m"
sudo phoronix-test-suite install-dependencies openssl
phoronix-test-suite benchmark openssl
echo "\e[32mEjecuta la segunda prueba\e[0m"
phoronix-test-suite benchmark openssl
phoronix-test-suite result-file-to-text resul

sudo apt-get remove -y php5-cli