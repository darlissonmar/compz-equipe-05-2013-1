make clean
make compile

for i in 1 2 3 4 5 6 7 8 9 10
do
	./bin/valida_email entrada/arquivo-emails$i.txt >> saida/saida.txt
done
