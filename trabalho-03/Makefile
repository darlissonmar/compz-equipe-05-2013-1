compile: sql.y sql.flex
	bison -d sql.y
	flex  -o sql.flex.c sql.flex
	gcc  -o sql sql.flex.c sql.tab.c -lfl -lm

clean:
	rm -f *.c *.h sql
