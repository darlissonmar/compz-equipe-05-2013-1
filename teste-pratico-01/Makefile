compile: bhaskara.y bhaskara.flex
	bison -d bhaskara.y
	flex  -o bhaskara.flex.c bhaskara.flex
	gcc  -o bhaskara bhaskara.flex.c bhaskara.tab.c -lfl -lm

clean:
	rm -f *.c *.h sql
