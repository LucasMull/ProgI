#!/bin/bash

wget http://www.inf.ufpr.br/cursos/ci056/aulas/dados_exercicio1.tar.gz;
tar -vzxf dados_exercicios1.tar.gz


  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##

mkdir speedrun  
./bolha > ./speedrun/dados_nao_ordenados.dat
cd speedrun

gnuplot -persist <<-Muller1
set terminal png size 600,600
set output 'nao_ordenadas.png'
plot "dados_nao_ordenados.dat" using 2 title 'Bolha' with lines, "dados_nao_ordenados.dat" using 3 title 'Insertion' with lines, "dados_nao_ordenados.dat" using 4 title 'Selection' with lines
Muller1

cd ..


  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##

./bolha2 > ./speedrun/dados_ordenados.dat

cd speedrun

gnuplot -persist <<-Muller2
set terminal png size 600,600
set output 'ordenadas.png'
plot "dados_ordenados.dat" using 2 title 'Bolha' with lines, "dados_ordenados.dat" using 3 title 'Insertion' with lines, "dados_ordenados.dat" using 4 title 'Selection' with lines
Muller2

cd ..

rm entries.txt
