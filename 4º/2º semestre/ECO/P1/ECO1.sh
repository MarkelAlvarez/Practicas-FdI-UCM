#!/bin/sh
echo "\e[33mAPARTADO 1: TIME\e[0m"
echo "\e[32m/usr/bin/time -v -p echo test\e[0m"
/usr/bin/time -v -p echo test
echo "\e[32mLimpiando caches...\e[0m"
sudo sysctl -w vm.drop_caches=3
echo "\e[32mfind /usr > /dev/null # primera vez (caches del FS vacías)\e[0m"
/usr/bin/time -v -p find /usr > /dev/null # primera vez (caches del FS vacías)
echo "\e[32mfind /usr > /dev/null # siguientes veces (caches llenas)\e[0m"
/usr/bin/time -v -p find /usr > /dev/null # siguientes veces (caches llenas)
echo "\e[32mdd if=/dev/zero of=/var/tmp/prueba count=100K bs=1K\e[0m"
/usr/bin/time -v -p dd if=/dev/zero of=/var/tmp/prueba count=100K bs=1K
echo "\e[32mdd if=/dev/zero of=/var/tmp/prueba count=100K bs=1K oflag=direct\e[0m"
/usr/bin/time -v -p dd if=/dev/zero of=/var/tmp/prueba count=100K bs=1K oflag=direct
echo "\e[32mdd if=/dev/urandom of=/var/tmp/prueba count=100K bs=1K\e[0m"
/usr/bin/time -v -p dd if=/dev/urandom of=/var/tmp/prueba count=100K bs=1K

echo "\n\e[33mAPARTADO 2: PS"
echo "\e[32mps -U root -eo euser,pri,pcpu,size,vsize --sort -pcpu\e[0m"
ps -U root -eo euser,pri,pcpu,size,vsize --sort -pcpu

echo "\n\e[33mAPARTADO 3: TOP"
echo "\e[32mCompilamos el programa...\e[0m"
gcc cpu_mem.c -o cpu_mem -lm
echo "\e[32mCuando haya lanzado el programa con \"./cpu_mem 1200\", pulse cualquier tecla...\e[0m"
read tecla
echo "\e[32mtop -b -d 1 | egrep \"PID|cpu_mem|kswapd0\"\e[0m"
top -b -d 1 | egrep "PID|cpu_mem|kswapd0"