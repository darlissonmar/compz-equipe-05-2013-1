FILE=valida
BIN_DIR=bin

.PHONY: clean

compile:	$(FILE).lex.c
	@ echo Compiling...
	@ gcc -o $(BIN_DIR)/$(FILE).o $(FILE).lex.c -lfl
	@ echo "done"

valida.lex.c:
	@ flex -o $(FILE).lex.c $(FILE).lex
	
teste:	compile
	./$(FILE).o lista_email.txt >> saida/saida.txt

clean:
	@ echo Cleaning...
	@ rm -rf *.c
	@ rm -rf $(BIN_DIR)/*.o
	@ rm -rf *.*~ 
	@ rm -rf *~
	@ rm -rf saida/*.txt
	@ echo "done"
