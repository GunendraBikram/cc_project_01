CC	= gcc
YACC	= yacc
LEX	= lex

demo: y.tab.c lex.yy.c
	$(CC) lex.yy.c y.tab.c
y.tab.c: demo.y
	$(YACC) -d demo.y
lex.yy.c: demo.l y.tab.h
	$(LEX) demo.l	
clean: 
	rm a.out lex.yy.c y.tab.c y.tab.h	
