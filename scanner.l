%{
/*
 * @author: Matt Scaperoth
 * Project 2
 * FILE: scanner.l
 * Class: CSCI 3313-10 FA13
 * 
 */
 #include <string.h>
#include "parser.tab.h"
%}
%%
[+\-]                           {yylval.charval = yytext[0];return ADDOP ; }
[*/]|"and"|"or"|"mod"|"div"     {yylval.charval = yytext[0];return MULOP ; }
":="                            {return ASSIGNOP ; }
"<"|">"                         {return RELOP ; }
"<>"|"<="|">="			        {yylval.string = strdup(yytext);return RELOP ; }
\(                              {return OPAR ; }
\)                              {return CPAR ; }
[0-9]+							{yylval.integer = atoi(yytext);return INTNO;}
[0-9]+\.[0-9]+					{yylval.real = atof(yytext);return REALNO;}
\.                              {return DOT ; }
\,                              {return COMMA ; }
\;                              {return SEMICOLON ; }
\:                              {return COLON  ; }
"program"                       {return PROGRAM ; }
"var"                           {return VAR ; }
"integer"                       {return INTEGER ; }
"real"                          {return REAL ;}
"begin"                         {return BEGINS ; }
"end"                           {return END ; }
"do"                            {return DO ; }
"while"                         {return WHILE ; }
"if"                            {return IF ; }
"then"                          {return THEN ; }
"else"                          {return ELSE ; }
"not"                           {return NOT ; }
[a-z][a-zA-Z0-9]*               {yylval.id = (char *) strdup( yytext ); return ID ; }
[ \t]                           {/*whitespace*/}
[\n\r\0\x0B]+                   {/*end of line chars*/}
.                               {printf("Mystery character %c\n ", *yytext); }
%%