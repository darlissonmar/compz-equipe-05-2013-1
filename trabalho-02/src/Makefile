FILE=valida

.PHONY: clean

compile:	$(FILE).lex.c
	@ echo Compiling...
	@ gcc -o $(FILE).o $(FILE).lex.c -lfl
	@ echo "done"

valida.lex.c:
	@ flex -o $(FILE).lex.c $(FILE).lex
	
teste:	compile
	./$(FILE).o lista_email.txt

clean:
	@ echo Cleaning...
	@ rm -rf *.c
	@ rm -rf *.o
	@ rm -rf *.*~ 
	@ rm -rf *~
	@ echo "done"
