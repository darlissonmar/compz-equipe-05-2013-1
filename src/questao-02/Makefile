BIN_DIR=bin
SAIDA_DIR=saida
ENTRADA_DIR=entrada
GCC=gcc
FILE=valida_email
FILE_SAIDA=saida
FILE_ENTRADA= arquivo-emails

.PHONY: clean

# This is the default task
compile:
	@ mkdir -p $(BIN_DIR)
	@ mkdir -p $(SAIDA_DIR)
	@ $(GCC) $(FILE).c -o $(BIN_DIR)/$(FILE)

