#!/bin/csh
#Ensures that the node can sleep

#$ -l h_rt 00:05:00
#$ -pe 16way 16
#$ -q development
#$ -A acctName
#$ -N testDec28
#$ -o $JOB_ID.out
#$ -e $JOB_ID.err

#$ -M i.linwin@gmail.com
#$ -m b,e,a,s

#required for Tesseract
export TESSDATA_PREFIX="/share/home/01239/blake648/tesseract-2.04/"

/share/home/01239/blake648/main/main -i $HOME/input/H1123091.dng -o $HOME/output


