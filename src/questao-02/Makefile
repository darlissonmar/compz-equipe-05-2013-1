BIN_DIR=bin
SAIDA_DIR=saida
GCC=gcc
FILE=valida_email

compile:
	@ mkdir -p $(BIN_DIR)
	@ mkdir -p $(SAIDA_DIR)
	@ $(GCC) $(FILE).c -o $(BIN_DIR)/$(FILE)

clean:
	@ rm -rf $(SAIDA_DIR)/saida.txt	
	@ rm -rf $(BIN_DIR)/$(FILE)
	@ rm -rf *.o 
	@ rm -rf *.*~ 
	@ rm -rf *~

