%{
/*
 * @author: Matt Scaperoth
 * Project 3.1
 * File: parser.y
 * Class: CSCI 3313-10 FA13
 * 
 */
 #include "hash.h"
 #include "extensions/remove_ext.h"
 //#define YYDEBUG 1  //for debugging 


 void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s); 
 }



 %}
 %union semrec{
   int integer;
   double real;
   char *id;
   char *string;
   char charval;
 }
 /*declare tokens*/
 %start  program
 %token  ASSIGNOP DIVOP
 %token  OPAR CPAR 
 %token  DOT COMMA SEMICOLON COLON
 %token  VAR REAL BEGINS END PROGRAM
 %token  DO WHILE IF THEN ELSE NOT
 %token <charval> ADDOP MULOP
 %token <string> RELOP
 %token <integer> INTEGER
 %token <integer> INTNO
 %token <real> REALNO
 %token <id> ID 
 %type <string> procedure_statement identifier_list 
 %type <charval> type factor statement expression simple_expression term expression_list

 %%

 program: 
 PROGRAM ID {create_fill_and_pop_sym(ht,$2,'u',0);

 fprintf(out, ".data\n");
 fprintf(out, "user_input: .word 0\n");
 fprintf(out, "readspace: .asciiz \"read: \"\n");
 fprintf(out, "writespace: .asciiz \"write: \"\n");
 fprintf(out, "space: .asciiz \"\\n\"\n");

 } OPAR identifier_list {add_type_and_pop_all('g',0);} CPAR SEMICOLON
 declarations{

  fprintf(out, "\n.text\n.globl main\n main:\n");
}
compound_statement
DOT
{if(PRINT_ERRORS) printf("Parsed the program!\n");
fprintf(out,"\n\n### END THE PROGRAM ###\n");
fprintf(out,"\nli\t$v0, 10\t#the end\n");
fprintf(out,"syscall\n");
}
;

identifier_list:
ID {if(PRINT_ERRORS) printf("reducing identifier_list: ID\n");create_and_fill_sym($1,'u',0);}
|identifier_list COMMA ID {create_and_fill_sym($3,'u',0);if(PRINT_ERRORS) printf("reducing identifier_list: identifier_list COMMA ID\n");}
;

declarations:
declarations VAR identifier_list COLON type 
{ 
  add_type_and_pop_all($5,0);
  } SEMICOLON
  {if(PRINT_ERRORS) printf("reducing delcarations: declarations VAR identifier_list COLON type SEMICOLON\n");}
  |{if(PRINT_ERRORS) printf("reducing declarations EMPTY rule\n");}
  ;

  type:
  INTEGER { $$='i';if(PRINT_ERRORS) printf("reducing type: INTEGER\n");}
  |REAL {$$='r';if(PRINT_ERRORS) printf("reducing type: REAL\n"); }
  ;

  compound_statement:
  BEGINS 
  optional_statements
  END
  {if(PRINT_ERRORS) printf("compound statement\n");}
  ;

  optional_statements:
  statement_list {if(PRINT_ERRORS) printf("reducing optional_statements: statement_list\n");}
  |{if(PRINT_ERRORS) printf("reducing optional statements EMPTY rule\n");}
  ;

  statement_list:
  statement {if(PRINT_ERRORS) printf("reducing statement_list: statement\n");}
  |statement_list SEMICOLON statement {if(PRINT_ERRORS) printf("reducing statement_list: statement_list SEMICOLON statement\n");}
  ;

  statement:
  ID ASSIGNOP expression {check_type_mismatch($1,$3);if(PRINT_ERRORS) printf("reducing statement: ID ASSIGNOP expression\n");
  fprintf(out, "\n\n###POP THE STACK FOR ASSIGNOP###\n");
  fprintf(out, "lw\t$t0, ($sp)\t#pop 1st!\n");
  fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr\n");
  fprintf(out, "sw\t$t0, %s\t#add value to variable\n",$1);
/*print message
  fprintf(out,"\n\n### PRINT THE ASSIGNMENT MESSAGE ###\n");
  fprintf(out,"li\t$v0, 4\t#print instruction\n");
  fprintf(out,"la\t$a0, emsg\t#put the message to be print\n");
  fprintf(out,"syscall\t\n");
  */
}
|procedure_statement {if(PRINT_ERRORS) printf("reducing statement: procedure_statement\n");}
|compound_statement {if(PRINT_ERRORS) printf("reducing statement: compound_statement\n");}
|IF expression THEN statement ELSE statement 
{
  if(PRINT_ERRORS) printf("reducing statement: IF...THEN... ELSE\n");
  
}
|WHILE expression DO statement {if(PRINT_ERRORS) printf("reducing statement: WHILE...DO\n");}
;

procedure_statement:
ID {/*$$=symbol_is_declared($1);*/if(PRINT_ERRORS) printf("reducing procedure_statement: ID\n");
}
|ID OPAR expression_list CPAR {
  if(PRINT_ERRORS) printf("reducing procedure_statement: ID OPAR expression_list CPAR\n");
  if(strcmp($1,"read")==0){
    fprintf(out,"\n\n### READ INPUT ###\n");
    fprintf(out,"li\t$v0, 4\t#print instruction\n");
    fprintf(out,"la\t$a0, readspace\t#put the message to be print\n");
    fprintf(out,"syscall\t\n"); 

    switch($3){
      case 'i':
      fprintf(out,"li\t$v0, 5\t#accept input instruction\n");
      break;
      case 'r':
      fprintf(out,"li\t$v0, 7\t#accept input instruction\n");
      break;
      default:
      break;
    }
    
    fprintf(out,"syscall\t\n");
    fprintf(out, "sw\t$v0, ($t0)\t#add value to variable\n");

    /*
    fprintf(out,"la\t$a0, ($t0)\t#put the message to be print\n");
    fprintf(out,"li\t$v0, 1\t#print instruction\n");
    fprintf(out,"syscall\t\n"); */

    fprintf(out,"li\t$v0, 4\t#print instruction\n");
    fprintf(out,"la\t$a0, space\t#put the message to be print\n");
    fprintf(out,"syscall\t\n"); 
  }
  else if(strcmp($1,"write")==0){
    fprintf(out,"\n\n### PRINT THE RESULT ###\n");
    fprintf(out,"li\t$v0, 4\t#print instruction\n");
    fprintf(out,"la\t$a0, writespace\t#put the message to be print\n");
    fprintf(out,"syscall\t\n"); 

    fprintf(out, "lw\t$t0, ($sp)\t#pop 1st!\n");

    switch($3){
      case 'i':
      fprintf(out,"li\t$v0, 1\t#print instruction\n");
      break;
      case 'r':
      fprintf(out,"li\t$v0, 3\t#accept input instruction\n");
      break;
      default:
      break;
    }

    fprintf(out,"move\t$a0, $t0\t#put the value to be print\n"); 
    fprintf(out,"syscall\t\n");

    fprintf(out,"li\t$v0, 4\t#print instruction\n");
    fprintf(out,"la\t$a0, space\t#put the message to be print\n");
    fprintf(out,"syscall\t\n"); 

  }
}
;

expression_list:
expression {if(PRINT_ERRORS) printf("reducing expression_list: expression\n");}
|expression_list COMMA expression {if(PRINT_ERRORS) printf("reducing expression_list: expression_list COMMA expression\n");}
;

expression:
simple_expression {if(PRINT_ERRORS) printf("reducing expression simple_expression\n");}
|simple_expression RELOP simple_expression {
  $$='i';if(PRINT_ERRORS) printf("reducing expression: simple_expression RELOP simple_expression\n");
  fprintf(out,"\n\n### PERFORMING RELOP ###\n");
  fprintf(out, "lw\t$t0, ($sp)\t#pop 1st!\n");

  fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr\n");
  fprintf(out, "lw\t$t1, ($sp)\t#pop 2nd!\n");

  if(strcmp($2, "<")==0){
    if($1<$3){
      fprintf(out, "li\t$t0, 1\t#add\n");
    }
    else fprintf(out, "li\t$t0, 0\t#add\n");
  }
  else if(strcmp($2, ">")==0){
    if($1>$3){
      fprintf(out, "li\t$t0, 1\t#add\n");
    }
    else fprintf(out, "li\t$t0, 0\t#add\n");
  }
  else if(strcmp($2, ">=")==0){
    if($1>=$3){
      fprintf(out, "li\t$t0, 1\t#add\n");
    }
    else fprintf(out, "li\t$t0, 0\t#add\n");
  }
  else if(strcmp($2, "<=")==0){
    if($1<=$3){
      fprintf(out, "li\t$t0, 1\t#add\n");
    }
    else fprintf(out, "li\t$t0, 0\t#add\n");
  }
  fprintf(out, "subu\t$sp, $sp, 4\t#move the stack ptr\n");
  fprintf(out, "sw\t$t0, ($sp)\t#push!\n");
}
;

simple_expression:
term {if(PRINT_ERRORS) printf("reducing simple_expression term\n");}
|sign term {if(PRINT_ERRORS) printf("reducing simple_expression sign term\n");}
|simple_expression ADDOP term {if($1 == 'r' || $3 == 'r')$$ = 'r'; else $$='i'; if(PRINT_ERRORS) printf("reducing simple_expression: simple_expression ADDOP term\n");
fprintf(out,"\n\n### PERFORMING ADDITION ###\n");
fprintf(out, "lw\t$t0, ($sp)\t#pop 1st!\n");

fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr\n");
fprintf(out, "lw\t$t1, ($sp)\t#pop 2nd!\n");


fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr\n");

switch($2){
  case '+':
  fprintf(out, "add\t$t0, $t1, $t0\t#add\n");
  break;
  case'-':
  fprintf(out, "sub\t$t0, $t1, $t0\t#add\n");
  break;
  default:
  fprintf(out,"#Wrong ADDOP Operation\n");
  break;
}
fprintf(out, "subu\t$sp, $sp, 4\t#move the stack ptr\n");
fprintf(out, "sw\t$t0, ($sp)\t#push!\n");
  /*print out what was just read in
  fprintf(out,"\n\n### PRINT THE RESULT ###\n");
  fprintf(out,"li\t$v0, 1\t#print instruction\n");
  fprintf(out,"move\t$a0, $t0\t#put the value to be print\n");
  fprintf(out,"syscall\t\n");*/

  /*print message
  fprintf(out,"\n\n### PRINT THE ADDITION MESSAGE ###\n");
  fprintf(out,"li\t$v0, 4\t#print instruction\n");
  fprintf(out,"la\t$a0, amsg\t#put the value to be print\n");
  fprintf(out,"syscall\t\n");*/ 
}
;

term:
factor {if(PRINT_ERRORS) printf("reducing term: factor\n");}
|term MULOP factor {if($1 == 'r' || $3 == 'r')$$ = 'r'; else $$='i';if(PRINT_ERRORS) printf("reducing term: term MULOP factor\n");
fprintf(out,"\n\n### PERFORMING MULTIPLICATION ###\n");
fprintf(out, "lw\t$t0, ($sp)\t#pop 1st!\n");
fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr\n");
fprintf(out, "lw\t$t1, ($sp)\t#pop 2nd!\n");
fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr\n");
switch($2){
  case '*':
  fprintf(out, "mul\t$t0, $t1, $t0\t#multiply\n");
  break;
  case '/':
  fprintf(out, "div\t$t0, $t1, $t0\t#divide\n");
  break;
  default:
  fprintf(out,"#Wrong MULOP Operation\n");
  break;
}

fprintf(out, "subu\t$sp, $sp, 4\t#move the stack ptr\n");
fprintf(out, "sw\t$t0, ($sp)\t#push!\n");

  /*print out what was just read in
  fprintf(out,"\n\n### PRINT THE RESULT ###\n");
  fprintf(out,"\nli\t$v0, 1\t#print instruction\n");
  fprintf(out,"\nmove\t$a0, $t0\t#put the value to be print\n");
  fprintf(out,"syscall\t\n");*/

  /*print message
  fprintf(out,"\n\n### PRINT THE MULTIPLICATION MESSAGE ###\n");
  fprintf(out,"li\t$v0, 4\t#print instruction\n");
  fprintf(out,"la\t$a0, mmsg\t#put the value to be print\n");
  fprintf(out,"syscall\t\n");*/ 
}
;

factor:
ID {$$=symbol_is_declared($1);if(PRINT_ERRORS) printf("reducing factor: ID\n");
fprintf(out, "\n\n### ADDING AN ID TO THE STACK ####\n");
fprintf(out, "lw\t $t0, %s\t #store value from id into t0\n",$1);
fprintf(out, "subu\t $sp, $sp, 4\t #move the stack ptr\n");
fprintf(out, "sw\t $t0, ($sp)\t #push!\n");
fprintf(out, "la\t$t0, %s\t #load address of var into t0",$1);
}
|ID OPAR expression_list CPAR {if(PRINT_ERRORS) printf("reducing factor: ID OPAR expression_list CPAR\n");
}
|INTNO {$$='i';if(PRINT_ERRORS) printf("reducing factor: INTNO\n");
//put value of current number at the top of the stack 
fprintf(out, "\n\n### ADDING AN INT TO THE STACK ####\n");
fprintf(out, "li\t$t0, %d\t #store value\n",$1);
fprintf(out, "subu\t$sp, $sp, 4\t#move the stack ptr\n");
fprintf(out, "sw\t $t0, ($sp)\t#push!\n");

    /*print out what was just read in
  fprintf(out,"\n\n### PRINT THE RESULT ###\n");
  fprintf(out,"li\t$v0, 1\t#print instruction\n");
  fprintf(out,"move\t$a0, $t0\t#put the value to be print\n");
  fprintf(out,"syscall\t\n");*/
}
|REALNO {$$='r';if(PRINT_ERRORS) printf("reducing factor: REALNO\n");
fprintf(out, "\n\n### ADDING A DOUBLE/FLOAT/REAL TO THE STACK ####\n");
fprintf(out, "li\t$t0, %f\t #store value\n",$1);
fprintf(out, "subu\t$sp, $sp, 4\t#move the stack ptr\n");
fprintf(out, "sw\t $t0, ($sp)\t#push!\n");

}
|OPAR expression CPAR {if(PRINT_ERRORS) printf("reducing factor: OPAR expression CPAR\n");}
|NOT factor {if(PRINT_ERRORS) printf("reducing factor: NOT factor\n");}
;

sign:
ADDOP {if(PRINT_ERRORS) printf("reducing sign: ADDOP\n");}
;

%%
extern FILE *yyin; 

main(int argc, char **argv) {
  init_hash(ht);
  char *filename;
  char *outfile;
  /* read input */
  if( argc > 1) {
    FILE * file;
    filename = argv [1];
    file = fopen( filename, "r");
    if (! file) {
      exit (1);
    }
    yyin = file;
  }

  printf("File name: %s\n",filename);
  filename = basename(filename);

  printf("Creating output file...\n");
  outfile = remove_ext(filename, '.', '/');

  //printf ("new filename: [%s]\n",outfile);

  strcat(outfile,".s");
  /* out file */
  if ((out = fopen(outfile, "w")) == NULL) {
    printf("ERROR: Output file cannot be generated.");
  }
  
  yyparse();
  close(out);

  if(!NUM_ERRORS && !PRINT_ERRORS)
  printf("0 errors\n");

  if(PRINT_ERRORS){
    printf("%d Errors\n",NUM_ERRORS);
    print_hash(ht);
  }  

}

