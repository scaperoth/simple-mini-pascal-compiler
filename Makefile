#makefile
PROJNAME = project3
SUBVERSION = .2
CC= gcc
OBJ = project3.tab.o lex.yy.o
CFLAGS = -lfl -o
LEX = scanner.l
PARSE = parser.y
PARSEFLAGS = -v -d

$(PROJNAME)$(SUBVERSION): $(OBJ)
	$(CC) parser.tab.c lex.yy.c $(CFLAGS) $@

$(PROJNAME).tab.o: $(PARSE)
	bison $(PARSEFLAGS) $(PARSE)
	#for debugging add -t to the command above

lex.yy.o: $(LEX)
	flex $(LEX)

clean: 
	rm parser.tab.* lex.yy.* $(PROJNAME)$(SUBVERSION) *.s *.output 
