CC	= gcc
YACC	= yacc
LEX	= lex

comp:	y.tab.c lex.yy.c containers.c comp.c
	$(CC) lex.yy.c y.tab.c containers.c -o comp

y.tab.c: ambig.y
	$(YACC) -d ambig.y

lex.yy.c: ambig.l y.tab.h
	$(LEX) ambig.l

clean: 
	rm a.out lex.yy.c y.tab.c y.tab.h
