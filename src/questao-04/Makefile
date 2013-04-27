#criando algoritmo linear probing

SCRIPTS_PATH=../../test/scripts

all: 	gerador_aleatorio
	gcc linear_probing.c -o linear_probing

gerador_aleatorio:
	cd $(SCRIPTS_PATH)/ && make all
	cd $(SCRIPTS_PATH)/ && ./gerar.sh
	cp $(SCRIPTS_PATH)/*.output .
	cd $(SCRIPTS_PATH)/ && make clean

clean:
	rm -f *.o
	rm -f linear_probing
	rm -f *.output
	rm -f *.*~
