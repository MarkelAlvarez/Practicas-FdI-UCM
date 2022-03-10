#!/bin/sh
echo "\e[33mAPARTADO 1: VMSTAT\e[0m"
echo "\e[32mLimpiando caches...\e[0m"
sudo sysctl -w vm.drop_caches=3
echo "\e[32mCuando haya lanzado vmstat con \"vmstat -a -w 1 100\", pulse cualquier tecla...\e[0m"
read tecla
echo "\e[32mfind / > /dev/null\e[0m"
find / > /dev/null
echo "\e[32msudo dd if=/dev/sda of=/dev/null count=1M\e[0m"
sudo dd if=/dev/sda of=/dev/null count=1M
echo "\e[32mdd if=/dev/zero of=/var/tmp/prueba count=1M; sleep 10; rm  /var/tmp/prueba\e[0m"
dd if=/dev/zero of=/var/tmp/prueba count=1M; sleep 10; rm  /var/tmp/prueba
echo "\e[32mCompilamos el programa...\e[0m"
gcc cpu_mem.c -o cpu_mem -lm
echo "\e[32m./cpu_mem 1200\e[0m"
./cpu_mem 1200

echo "\n\e[33mAPARTADO 2: SAR\e[0m"
echo "\e[32mLimpiando caches...\e[0m"
sudo sysctl -w vm.drop_caches=3
echo "\e[32mCuando haya lanzado vmstat con \"sar 2 20 -d\", pulse cualquier tecla...\e[0m"
read tecla
echo "\e[32mfind / > /dev/null\e[0m"
find / > /dev/null
now=$(date +"%T")
echo "\e[32mMomento de finalización: $now\e[0m"
echo "\e[32msudo dd if=/dev/sda of=/dev/null count=1M\e[0m"
dd if=/dev/zero of=/var/tmp/prueba count=1M
echo "\e[32mLimpiando caches...\e[0m"
sudo sysctl -w vm.drop_caches=3
echo "\e[32mCompilamos el programa...\e[0m"
gcc cpu_mem.c -o cpu_mem -lm
echo "\e[32mCuando haya lanzado vmstat con \"sar 1 10 -B\", pulse cualquier tecla...\e[0m"
read tecla
echo "\e[32m./cpu_mem 1200\e[0m"
./cpu_mem 1200
end=$(date +"%T")
echo "\e[32mMomento de finalización: $end\e[0m"