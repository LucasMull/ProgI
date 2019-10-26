#!/bin/bash
kernel=$1
diretorio=$2
data=$(date +%d-%m-%y)

if test -d "$diretorio"; then
	echo Diretório já existe
	cd ~/$diretorio
else
	mkdir ~/$diretorio
	cd ~/$diretorio
fi

grep -s '<warn>' $kernel > ~/$diretorio/${data}_warn.log
grep -s '<error>' $kernel > ~/$diretorio/${data}_error.log
grep -s '<info>' $kernel > ~/$diretorio/${data}_info.log

tar -c ~/$diretorio/* -f logs.tar.gz -vz

if test "~/$diretorio/logs.tar.gz"; then
	logger SUCESSO
else
	logger ERRO
fi
