FILE=valida
BIN_DIR=bin
SAIDA_DIR=saida
SCRIPT_FILE=script

.PHONY: clean

compile:	$(FILE).lex.c
	@ echo Compiling...
	@ rm -rf $(SAIDA_DIR)
	@ rm -rf $(BIN_DIR)
	@ mkdir $(SAIDA_DIR)
	@ mkdir $(BIN_DIR)
	@ gcc -o $(BIN_DIR)/$(FILE).o $(FILE).lex.c -lfl
	@ echo "done"

valida.lex.c:
	@ flex -o $(FILE).lex.c $(FILE).lex
	
teste: compile
	./$(SCRIPT_FILE).sh

clean:
	@ echo Cleaning...
	@ rm -rf *.c
	@ rm -rf *.*~ 
	@ rm -rf *~
	@ rm -rf $(SAIDA_DIR)
	@ rm -rf $(BIN_DIR)
	@ echo "done"
