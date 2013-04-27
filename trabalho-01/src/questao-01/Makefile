GCC=gcc
FILE=mypart

.PHONY: clean

# This is the default task
compile:
	$(GCC) $(FILE).c -o $(FILE)
	
clean:
	@ echo Cleaning...
	rm -rf $(FILE)
	rm -rf *.o 
	rm -rf *.*~ 
	rm -rf *~
