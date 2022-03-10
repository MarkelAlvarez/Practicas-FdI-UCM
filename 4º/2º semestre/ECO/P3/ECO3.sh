#!/bin/sh
echo "\e[33mAPARTADO 1: GCC\e[0m"
echo "\e[32mCompilando con distintos niveles de optimización (-O0, -O1, -O2 y -O3)\e[0m"
gcc -o edges0 -O0 edges.c
gcc -o edges1 -O1 edges.c
gcc -o edges2 -O2 edges.c
gcc -o edges3 -O3 edges.c
echo "\e[32mMidiendo el tiempo de ejecución de los ejecutables...\e[0m"
time ./edges0 img.pgm out.pgm
time ./edges1 img.pgm out.pgm
time ./edges2 img.pgm out.pgm
time ./edges3 img.pgm out.pgm

echo "\e[32mObteniendo los tiempos de ejecución compilando con optimización basada en perfil\e[0m"
echo "\e[32mgcc -o edges1pg -O1 -fprofile-generate edges.c\e[0m"
gcc -o edges1pg -O1 -fprofile-generate edges.c

echo "\e[32m./edges1pg img.pgm out.pgm\e[0m"
./edges1pg img.pgm out.pgm

echo "\e[32mgcc -o edges1pu -O1 -fprofile-use edges.c\e[0m"
gcc -o edges1pu -O1 -fprofile-use edges.c
echo "\e[32mgcc -o edges2pu -O2 -fprofile-use edges.c\e[0m"
gcc -o edges2pu -O2 -fprofile-use edges.c
echo "\e[32mgcc -o edges3pu -O3 -fprofile-use edges.c\e[0m"
gcc -o edges3pu -O3 -fprofile-use edges.c

echo "\e[32mMidiendo el tiempo de ejecución con cada nivel de optimización...\e[0m"
echo "\e[32mNivel de optimización: -O1 (time ./edges1pu img.pgm out.pgm)\e[0m"
time ./edges1pu img.pgm out.pgm
echo "\e[32mNivel de optimización: -O2 (time ./edges2pu img.pgm out.pgm)\e[0m"
time ./edges2pu img.pgm out.pgm
echo "\e[32mNivel de optimización: -O3 (time ./edges3pu img.pgm out.pgm)\e[0m"
time ./edges3pu img.pgm out.pgm

echo "\e[33mAPARTADO 2: GPROF\e[0m"
echo "\e[32mObtén un perfil de ejecución del programa edges.c (sin optimización)\e[0m"
echo "\e[32mgcc -pg -o edges0gprofpg -O0 edges.c\e[0m"
gcc -pg -o edges0gprofpg -O0 edges.c
echo "\e[32m./edges0gprofpg img.pgm out.pgm\e[0m"
./edges0gprofpg img.pgm out.pgm
echo "\e[32mgprof edges0gprofpg gmon.out > analysis.txt\e[0m"
gprof edges0gprofpg gmon.out > analysis.txt
echo "\e[32mCalulando diferencias de tiempo entre los programas con y sin instrumentación...\e[0m"
echo "\e[32mTiempo de ejecución con instrumentación (time ./edges0gprofpg img.pgm out.pgm)\e[0m"
time ./edges0gprofpg img.pgm out.pgm
echo "\e[32mTiempo de ejecución sin instrumentación (time ./edges0 img.pgm out.pgm)\e[0m"
time ./edges0 img.pgm out.pgm

echo "\e[33mAPARTADO 2: GOOGLE-PPROF\e[0m"
echo "\e[32mObtener un perfil de ejecución en formato de texto del programa edges.c\e[0m"
echo "\e[32mgcc -lprofiler -o edges-google-pprof edges.c\e[0m"
gcc -lprofiler -o edges-google-pprof edges.c
echo "\e[32mGenera un grafo de llamadas en formato de texto y gif\e[0m"
CPUPROFILE=/tmp/edges.prof ./edges-google-pprof img.pgm out.pgm 
# PROFILE: interrupts/evictions/bytes = 220/122/9856
echo "\e[32mgoogle-pprof --text edges-google-pprof /tmp/edges.prof\e[0m"
google-pprof --text edges-google-pprof /tmp/edges.prof
echo "\e[32mgoogle-pprof --text edges-google-pprof /tmp/edges.prof\e[0m"
google-pprof --gif edges-google-pprof /tmp/edges.prof
echo "\e[32mCPUPROFILE=/tmp/edges.prof\e[0m"
CPUPROFILE=/tmp/edges.prof
echo "\e[32mCPUPROFILE_FREQUENCY=1000\e[0m"
CPUPROFILE_FREQUENCY=1000
echo "\e[32mCPUPROFILE_REALTIME=1\e[0m"
CPUPROFILE_REALTIME=1
echo "\e[32m./edges-google-pprof img.pgm out.pgm \e[0m"
./edges-google-pprof img.pgm out.pgm
echo "\e[32mObtén el tiempo de ejecución del programa sin instrumentación, con la instrumentación por  defecto y con instrumentación en tiempo real con frecuencia 1000\e[0m"
echo "\e[32mTiempo de ejecución sin instrumentación (time ./edges0 img.pgm out.pgm)\e[0m"
time ./edges0 img.pgm out.pgm
echo "\e[32mTiempo de ejecución con instrumentación (time ./edges0gprofpg img.pgm out.pgm)\e[0m"
time ./edges0gprofpg img.pgm out.pgm
echo "\e[32mTiempo de ejecución con instrumentación en tiempo real con frecuencia real (time ./edges-google-pprof img.pgm out.pgm)\e[0m"
time ./edges-google-pprof img.pgm out.pgm

echo "\e[32mObtener un perfil de ejecución por líneas de código\e[0m"
echo "\e[32mgcc -lprofiler -g -o edges-google-pprof-g edges.c\e[0m"
gcc -lprofiler -g -o edges-google-pprof-g edges.c
echo "\e[32mgoogle-pprof --text --lines edges-google-pprof /tmp/edges.prof\e[0m"
CPUPROFILE=/tmp/edges.prof ./edges-google-pprof-g img.pgm out.pgm
google-pprof --text --lines edges-google-pprof /tmp/edges.prof