/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIGNOP = 258,
     DIVOP = 259,
     OPAR = 260,
     CPAR = 261,
     DOT = 262,
     COMMA = 263,
     SEMICOLON = 264,
     COLON = 265,
     VAR = 266,
     REAL = 267,
     BEGINS = 268,
     END = 269,
     PROGRAM = 270,
     DO = 271,
     WHILE = 272,
     IF = 273,
     THEN = 274,
     ELSE = 275,
     NOT = 276,
     ADDOP = 277,
     MULOP = 278,
     RELOP = 279,
     INTEGER = 280,
     INTNO = 281,
     REALNO = 282,
     ID = 283
   };
#endif
/* Tokens.  */
#define ASSIGNOP 258
#define DIVOP 259
#define OPAR 260
#define CPAR 261
#define DOT 262
#define COMMA 263
#define SEMICOLON 264
#define COLON 265
#define VAR 266
#define REAL 267
#define BEGINS 268
#define END 269
#define PROGRAM 270
#define DO 271
#define WHILE 272
#define IF 273
#define THEN 274
#define ELSE 275
#define NOT 276
#define ADDOP 277
#define MULOP 278
#define RELOP 279
#define INTEGER 280
#define INTNO 281
#define REALNO 282
#define ID 283




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union
#line 21 "parser.y"
semrec{
   int integer;
   double real;
   char *id;
   char *string;
   char charval;
 }
/* Line 1529 of yacc.c.  */
#line 113 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

