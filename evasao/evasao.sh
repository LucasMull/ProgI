#!/bash/bin
rm -fr CSVs

dir=$(find ~ -name evasao2014-18.tar.gz)
tar -vzxf $dir
mv evasao CSVs

sed '/FORMA_EVASAO,PERIODO,FORMA_INGRESSO,ANO_INGRESSO,SEXO/d' ./CSVs/*.csv > TEMP.txt
sed -i -e 's/ //g' -e 's/,/ /g' TEMP.txt


#RANKING EVASAO GERAL DECRESCENTE
echo -e "[ITEM 3]\n"
awk '{print $1}' TEMP.txt | sort | uniq -c | sort -k1 -rn | awk '{print $2" "$1"\n"}' | column -t -s ' '
echo

#RANKING EVASAO POR ANO DECRESCENTE

echo "Ano Evasoes" > evasoes-ano.dat
awk '{print $3}' TEMP.txt | sort -u | paste -sd ' ' | tee temp-evasoes-forma.dat  evasoes-forma.dat > /dev/null

j=1
for i in ./CSVs/*.csv;do	
	ANO=$(ls ./CSVs | grep -Eo '[0-9]{1,4}' | sed -n ''"$j"'p')
	echo -e "[$ANO]\n"
	sed -e '1d' -e 's/ //g' -e 's/,/ /g' $i | awk '{print $1}' | sort | uniq -c | sort -k1 -rn | awk '{print $2" "$1"\n"}' | column -t -s ' ' > ANO_TEMP.txt
	sed -e '1d' -e 's/ //g' -e 's/,/ /g' $i | awk '{print $3}' | sort > ITEM8.txt
	echo -e "$(cat ANO_TEMP.txt)\n"
	
	#GNUPLUT ITEM 7
	TOTAL_ANO=$(awk '{s+=$2} END {printf "%.0f\n", s}' ANO_TEMP.txt)
	echo $ANO $TOTAL_ANO >> evasoes-ano.dat
	
	#GNUPLOT ITEM 8
	col=$(< temp-evasoes-forma.dat wc -w)

	printf "$ANO" >> evasoes-forma.dat
		for (( i = 1; i <= col; i++ ));do
			word=$(awk '{print $'$i'}' temp-evasoes-forma.dat)
			printf " $(grep -c "$word" ITEM8.txt)" >> evasoes-forma.dat
		done
	echo >> evasoes-forma.dat	
	(( j++ ))
done
sed -i '1s/^/# /' evasoes-forma.dat


#QUANTIDADE DE ANOS QUE OS ALUNOS FICAM ANTES DE OCORRER A EVASAO
echo -e "[ITEM 4]\n\nALUNOS\tANOS"
j=1
for i in ./CSVs/*.csv;do
	ANO_EVASAO=$(ls ./CSVs | grep -Eo '[0-9]{1,4}' | sed -n ''"$j"'p')
	lnTotal=$(< $i wc -l)
	for (( ln = 1; ln < lnTotal; ln++ ));do
		ANO_INGRESSO=$(sed -e '1d' -e 's/ //g' -e 's/,/ /g' $i | sed -n ''"$ln"'p' | awk '{print $4}') 
		ANO_TOTAL=$(( ANO_EVASAO - ANO_INGRESSO ))
		echo $ANO_TOTAL >> ITEM4.txt
	done
	(( j++ ))
done
sort -n ITEM4.txt | uniq -c | awk '{print $1"\t"$2"\n"}'


#SEMESTRE COM MAIOR EVASAO A CADA ANO COM PORCENTAGEM CORRESPONDENTE
echo -e "[ITEM 5]\n"
j=1
for i in ./CSVs/*.csv;do
	ANO_EVASAO=$(ls ./CSVs | grep -Eo '[0-9]{1,4}' | sed -n ''"$j"'p')
	sed -e '1d' -e 's/ //g' -e 's/,/ /g' $i | awk '{print $2}' | uniq -c > ITEM5.txt
	FIRST=$(sed -n '1p' ITEM5.txt | awk '{print $1}')
	SECOND=$(sed -n '2p' ITEM5.txt | awk '{print $1}')
	TOTAL_EVASAO=$(awk '{s+=$1} END {printf "%.0f\n", s}' ITEM5.txt)

	if [ $FIRST -gt $SECOND ];then
		echo $ANO_EVASAO semestre 1 - $(( FIRST*100 / TOTAL_EVASAO ))"%"
	else
		echo $ANO_EVASAO semestre 2 - $(( SECOND*100 / TOTAL_EVASAO ))"%"
	fi
	echo
	(( j++ ))
done


#MÉDIA DE EVASÕES DO SEXO MASCULINO E FEMININO AO LONGO DE 5 ANOS EM PORCENTAGEM
echo -e "[ITEM 6]\n"
echo -e "SEXO\t MÉDIA EVASÕES (5 anos)"
for i in ./CSVs/*.csv;do
        ANO_EVASAO=$(ls ./CSVs | grep -Eo '[0-9]{1,4}' | sed -n ''"$j"'p')
        sed -e '1d' -e 's/ //g' -e 's/,/ /g' $i  | awk '{print $5}' >> ITEM6.txt
done

sort ITEM6.txt | sed '1d' | uniq -c | awk '{print $2" "$1}' > ITEM6_TEMP.txt

SEXO_F=$(sed -n '1p' ITEM6_TEMP.txt | awk '{print $2}' )
SEXO_M=$(sed -n '2p' ITEM6_TEMP.txt | awk '{print $2}' )
TOTAL_SEXO=$(( SEXO_F + SEXO_M ))

echo -e "\nF\t\t"$(( SEXO_F*100 / TOTAL_SEXO ))"%\n\nM\t\t"$(( SEXO_M*100 / TOTAL_SEXO ))"%"


#PLOTAR GRAFICO DE TOTAL DE EVASOES POR ANO
gnuplot -persist <<-ITEM7
set terminal png size 800,600
set xlabel "Ano"
set ylabel "Evasões"
set style data lines
set output 'evasoes-ano.png'
plot "evasoes-ano.dat" using 2:xticlabels(1) t "evasoes"
ITEM7

#PLOTAR GRÁFICO DE BARRAS
gnuplot -persist <<-ITEM8
set terminal png size 800,600 enhanced font "Helvetica, 10"
set output 'evasoes-forma.png'

green = "#00FF00";
yellow = "#FFFF00;
set style data histogram
set style histogram cluster gap 9
set style fill solid
set boxwidth 1
set auto x
set xtics format ""
set grid ytics

set title "Formas de Evasões"
plot "evasoes-forma.dat" using 2:xtic(1) title "AlunoItercâmbio", \
            '' using 3 title "AproveitamentoCursoSuperior", \
            '' using 4 title "ConvênioAUGM", \
            '' using 5 title "ConvênioPec-G", \
	    '' using 6 title "MobilidadeAcadêmica", \
            '' using 7 title "ProcessoSeletivo/ENEM", \
            '' using 8 title "Reopção", \
	    '' using 9 title "TransferênciaEx-Ofício", \
            '' using 10 title "TransferênciaProvar" linecolor rgb green, \
            '' using 11 title "Vestibular" linecolor rgb yellow
ITEM8

rm ./evasoes-ano.dat
rm ./evasoes-forma.dat
rm ./temp-evasoes-forma.dat
rm ./ITEM8.txt
rm ./ITEM6_TEMP.txt
rm ./ITEM6.txt
rm ./ITEM5.txt
rm ./ITEM4.txt
rm ./TEMP.txt
rm ./ANO_TEMP.txt
