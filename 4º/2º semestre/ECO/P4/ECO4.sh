#!/bin/sh
rm matrix1 1>/dev/null 2>/dev/null
rm matrix2 1>/dev/null 2>/dev/null
rm edges 1>/dev/null 2>/dev/null
rm perf* 1>/dev/null 2>/dev/null
rm out.pgm 1>/dev/null 2>/dev/null
rm callgrind* 1>/dev/null 2>/dev/null
echo "\e[33m\nAPARTADO 1: PERF\e[0m"
echo "\e[32mCompilando matrix1.c\e[0m"
gcc matrix1.c -o matrix1
echo "\e[32mperf stat ./matrix1\e[0m"
perf stat ./matrix1
echo "\e[32mperf stat -r 5 ./matrix1\e[0m"
perf stat -r 5 ./matrix1
echo "\e[32mperf stat -e L1-dcache-loads,L1-dcache-load-misses,L1-dcache-stores,L1-dcache-store-misses ./matrix1\e[0m"
perf stat -e L1-dcache-loads,L1-dcache-load-misses,L1-dcache-stores,L1-dcache-store-misses ./matrix1

echo "\e[32m\nCompilando matrix2.c\e[0m"
gcc matrix2.c -o matrix2
echo "\e[32mperf stat ./matrix2\e[0m"
perf stat ./matrix2
echo "\e[32mperf stat -r 5 ./matrix2\e[0m"
perf stat -r 5 ./matrix2
echo "\e[32mperf stat -e L1-dcache-loads,L1-dcache-load-misses,L1-dcache-stores,L1-dcache-store-misses ./matrix2\e[0m"
perf stat -e L1-dcache-loads,L1-dcache-load-misses,L1-dcache-stores,L1-dcache-store-misses ./matrix2

echo "\e[32m\nCompilando edges.c\e[0m"
gcc edges.c -o edges

echo "\e[32mperf record ./edges img.pgm out.pgm\e[0m"
perf record ./edges img.pgm out.pgm
echo "\e[32mperf report --stdio\e[0m"
perf report --stdio
echo "\e[32mperf script\e[0m"
perf script

echo "\e[32mObteniendo grafos...\e[0m"
echo "\e[32mperf record -g ./edges img.pgm out.pgm\e[0m"
perf record -g ./edges img.pgm out.pgm
echo "\e[32mperf report -g --stdio\e[0m"
perf report -g --stdio
echo "\e[32mperf script -g\e[0m"
perf script

echo "\e[32m\nObteniendo un perfil de ejecución del programa para los fallos de lectura...\e[0m"
echo "\e[32mperf record -e L1-dcache-load-misses -F 10000 ./edges img.pgm out.pgm\e[0m"
perf record -e L1-dcache-load-misses -F 10000 ./edges img.pgm out.pgm
echo "\e[32mperf report --stdio\e[0m"
perf report --stdio

echo "\e[32m\nObteniendo un perfil de ejecución del programa para los fallos del predictor de saltos...\e[0m"
echo "\e[32mperf record -e branch-misses -c 1 ./edges img.pgm out.pgm\e[0m"
perf record -e branch-misses -c 1 ./edges img.pgm out.pgm
echo "\e[32mperf report --stdio\e[0m"
perf report --stdio

echo "\e[32m\nObteniendo el tiempo de ejecución del programa sin instrumentación y con ella...\e[0m"
echo "\e[32mtime -p ./edges img.pgm out.pgm\e[0m"
time -p ./edges img.pgm out.pgm
echo "\e[32mperf record time -p ./edges img.pgm out.pgm\e[0m"
perf record time -p ./edges img.pgm out.pgm

echo "\n\e[33m\nAPARTADO 2: CALLGRIND\e[0m"
echo "\e[32mObteniendo un perfil de ejecución con simulación de la memoria cache de los programas matrix1 y matrix2\e[0m"
echo "\e[32mvalgrind --tool=callgrind --cache-sim=yes ./matrix1\e[0m"
valgrind --tool=callgrind --cache-sim=yes ./matrix1
echo "\e[32mcallgrind_annotate callgrind.out.<PID>\e[0m"
callgrind_annotate callgrind.out.<PID>
echo "\e[32mvalgrind --tool=callgrind --cache-sim=yes ./matrix1\e[0m"
valgrind --tool=callgrind --cache-sim=yes ./matrix2
echo "\e[32mcallgrind_annotate callgrind.out.<PID>\e[0m"
callgrind_annotate callgrind.out.<PID>

echo "\n\e[33m\nAPARTADO 3: STRACE\e[0m"
echo "\e[32mstrace -e /open* vmstat\e[0m"
strace -e /open* vmstat
echo "\e[32mstrace -e /open* ps\e[0m"
strace -e /open* ps
echo "\e[32mstrace -e /open* top\e[0m"
strace -e /open* top
echo "\e[32mstrace -e /open* /usr/lib/sysstat/sadc\e[0m"
strace -e /open* /usr/lib/sysstat/sadc
echo "\e[32m\nstrace -c find /etc > /dev/null\e[0m"
strace -c find /etc > /dev/null