
SCRIPTS_PATH=../../test/scripts

all:	gerador_aleatorio
	gcc myhash.c -o myhash
gerador_aleatorio:
	cd $(SCRIPTS_PATH)/ && make all
	cd $(SCRIPTS_PATH)/ && ./gerar.sh
	cp $(SCRIPTS_PATH)/*.output .
	cd $(SCRIPTS_PATH)/ && make clean
clean:
	rm -f myhash
	rm -f *.output
	rm -f *.c~
