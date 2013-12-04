/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

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



 

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 181 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 194 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   69

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNRULES -- Number of states.  */
#define YYNSTATES  77

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,    19,    21,    25,    26,
      34,    35,    37,    39,    43,    45,    46,    48,    52,    56,
      58,    60,    67,    72,    74,    79,    81,    85,    87,    91,
      93,    96,   100,   102,   106,   108,   113,   115,   117,   121,
     124
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      30,     0,    -1,    -1,    -1,    -1,    15,    28,    31,     5,
      34,    32,     6,     9,    35,    33,    38,     7,    -1,    28,
      -1,    34,     8,    28,    -1,    -1,    35,    11,    34,    10,
      37,    36,     9,    -1,    -1,    25,    -1,    12,    -1,    13,
      39,    14,    -1,    40,    -1,    -1,    41,    -1,    40,     9,
      41,    -1,    28,     3,    44,    -1,    42,    -1,    38,    -1,
      18,    44,    19,    41,    20,    41,    -1,    17,    44,    16,
      41,    -1,    28,    -1,    28,     5,    43,     6,    -1,    44,
      -1,    43,     8,    44,    -1,    45,    -1,    45,    24,    45,
      -1,    46,    -1,    48,    46,    -1,    45,    22,    46,    -1,
      47,    -1,    46,    23,    47,    -1,    28,    -1,    28,     5,
      43,     6,    -1,    26,    -1,    27,    -1,     5,    44,     6,
      -1,    21,    47,    -1,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    55,    56,    47,    70,    71,    76,    75,
      80,    84,    85,    89,    96,    97,   101,   102,   106,   118,
     119,   120,   130,   134,   136,   198,   199,   203,   204,   252,
     253,   254,   292,   293,   329,   336,   338,   351,   358,   359,
     363
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGNOP", "DIVOP", "OPAR", "CPAR",
  "DOT", "COMMA", "SEMICOLON", "COLON", "VAR", "REAL", "BEGINS", "END",
  "PROGRAM", "DO", "WHILE", "IF", "THEN", "ELSE", "NOT", "ADDOP", "MULOP",
  "RELOP", "INTEGER", "INTNO", "REALNO", "ID", "$accept", "program", "@1",
  "@2", "@3", "identifier_list", "declarations", "@4", "type",
  "compound_statement", "optional_statements", "statement_list",
  "statement", "procedure_statement", "expression_list", "expression",
  "simple_expression", "term", "factor", "sign", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    31,    32,    33,    30,    34,    34,    36,    35,
      35,    37,    37,    38,    39,    39,    40,    40,    41,    41,
      41,    41,    41,    42,    42,    43,    43,    44,    44,    45,
      45,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      48
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,    12,     1,     3,     0,     7,
       0,     1,     1,     3,     1,     0,     1,     3,     3,     1,
       1,     6,     4,     1,     4,     1,     3,     1,     3,     1,
       2,     3,     1,     3,     1,     4,     1,     1,     3,     2,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     0,     6,     3,     0,
       0,     7,     0,    10,     4,     0,     0,     0,    15,     0,
       0,     0,     0,    23,    20,     0,    14,    16,    19,     5,
      12,    11,     8,     0,     0,    40,    36,    37,    34,     0,
      27,    29,    32,     0,     0,     0,     0,    13,     0,     0,
       0,    39,     0,     0,     0,     0,     0,    30,     0,    18,
       0,    25,    17,     9,    38,     0,    22,    31,    28,    33,
       0,    24,     0,    35,     0,    26,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     5,    10,    16,     8,    14,    49,    32,    24,
      25,    26,    27,    28,    60,    61,    40,    41,    42,    43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -46
static const yytype_int8 yypact[] =
{
      -8,   -18,    31,   -46,   -46,    37,    15,   -46,    36,    17,
      40,   -46,    38,   -46,    39,    15,    35,     1,     5,    42,
     -10,    -1,    -1,    14,   -46,    41,    43,   -46,   -46,   -46,
     -46,   -46,   -46,    -1,     9,   -46,   -46,   -46,    48,    44,
      10,    34,   -46,     9,    45,    -1,    -1,   -46,     5,    47,
      52,   -46,    -1,     5,     9,    -1,     9,    34,     5,   -46,
      32,   -46,   -46,   -46,   -46,    33,   -46,    34,    46,   -46,
      49,   -46,    -1,   -46,     5,   -46,   -46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -46,   -46,   -46,    50,   -46,   -46,   -46,    51,
     -46,   -46,   -45,   -46,     2,   -21,     4,   -38,   -28,   -46
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    44,    30,    62,    33,    57,    51,     1,    66,     9,
       3,    20,    50,    70,    33,    31,    67,    45,    18,    46,
      34,    35,    21,    22,    59,    36,    37,    38,    69,    76,
      34,     4,    54,    23,    55,    36,    37,    38,    71,    73,
      72,    72,     6,     7,     9,    11,    12,    13,    18,    29,
      15,    75,    48,    52,    65,    47,    63,    56,    64,    68,
      53,     0,     0,     0,    58,    17,     0,    19,    54,    74
};

static const yytype_int8 yycheck[] =
{
      21,    22,    12,    48,     5,    43,    34,    15,    53,     8,
      28,    10,    33,    58,     5,    25,    54,     3,    13,     5,
      21,    22,    17,    18,    45,    26,    27,    28,    56,    74,
      21,     0,    22,    28,    24,    26,    27,    28,     6,     6,
       8,     8,     5,    28,     8,    28,     6,     9,    13,     7,
      11,    72,     9,     5,    52,    14,     9,    23,     6,    55,
      16,    -1,    -1,    -1,    19,    15,    -1,    16,    22,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    30,    28,     0,    31,     5,    28,    34,     8,
      32,    28,     6,     9,    35,    11,    33,    34,    13,    38,
      10,    17,    18,    28,    38,    39,    40,    41,    42,     7,
      12,    25,    37,     5,    21,    22,    26,    27,    28,    44,
      45,    46,    47,    48,    44,     3,     5,    14,     9,    36,
      44,    47,     5,    16,    22,    24,    23,    46,    19,    44,
      43,    44,    41,     9,     6,    43,    41,    46,    45,    47,
      41,     6,     8,     6,    20,    44,    41
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 47 "parser.y"
    {create_fill_and_pop_sym(ht,(yyvsp[(2) - (2)].id),'u',0);

 fprintf(out, ".data\n");
 fprintf(out, "user_input: .word 0\n");
 fprintf(out, "readspace: .asciiz \"read: \"\n");
 fprintf(out, "writespace: .asciiz \"write: \"\n");
 fprintf(out, "space: .asciiz \"\\n\"\n");

 ;}
    break;

  case 3:
#line 55 "parser.y"
    {add_type_and_pop_all('g',0);;}
    break;

  case 4:
#line 56 "parser.y"
    {

  fprintf(out, "\n.text\n.globl main\n main:\n");
;}
    break;

  case 5:
#line 62 "parser.y"
    {if(PRINT_ERRORS) printf("Parsed the program!\n");
fprintf(out,"\n\n### END THE PROGRAM ###\n");
fprintf(out,"\nli\t$v0, 10\t#the end\n");
fprintf(out,"syscall\n");
;}
    break;

  case 6:
#line 70 "parser.y"
    {if(PRINT_ERRORS) printf("reducing identifier_list: ID\n");create_and_fill_sym((yyvsp[(1) - (1)].id),'u',0);;}
    break;

  case 7:
#line 71 "parser.y"
    {create_and_fill_sym((yyvsp[(3) - (3)].id),'u',0);if(PRINT_ERRORS) printf("reducing identifier_list: identifier_list COMMA ID\n");;}
    break;

  case 8:
#line 76 "parser.y"
    { 
  add_type_and_pop_all((yyvsp[(5) - (5)].charval),0);
  ;}
    break;

  case 9:
#line 79 "parser.y"
    {if(PRINT_ERRORS) printf("reducing delcarations: declarations VAR identifier_list COLON type SEMICOLON\n");;}
    break;

  case 10:
#line 80 "parser.y"
    {if(PRINT_ERRORS) printf("reducing declarations EMPTY rule\n");;}
    break;

  case 11:
#line 84 "parser.y"
    { (yyval.charval)='i';if(PRINT_ERRORS) printf("reducing type: INTEGER\n");;}
    break;

  case 12:
#line 85 "parser.y"
    {(yyval.charval)='r';if(PRINT_ERRORS) printf("reducing type: REAL\n"); ;}
    break;

  case 13:
#line 92 "parser.y"
    {if(PRINT_ERRORS) printf("compound statement\n");;}
    break;

  case 14:
#line 96 "parser.y"
    {if(PRINT_ERRORS) printf("reducing optional_statements: statement_list\n");;}
    break;

  case 15:
#line 97 "parser.y"
    {if(PRINT_ERRORS) printf("reducing optional statements EMPTY rule\n");;}
    break;

  case 16:
#line 101 "parser.y"
    {if(PRINT_ERRORS) printf("reducing statement_list: statement\n");;}
    break;

  case 17:
#line 102 "parser.y"
    {if(PRINT_ERRORS) printf("reducing statement_list: statement_list SEMICOLON statement\n");;}
    break;

  case 18:
#line 106 "parser.y"
    {check_type_mismatch((yyvsp[(1) - (3)].id),(yyvsp[(3) - (3)].charval));if(PRINT_ERRORS) printf("reducing statement: ID ASSIGNOP expression\n");
  fprintf(out, "\n\n###POP THE STACK FOR ASSIGNOP###\n");
  fprintf(out, "lw\t$t0, ($sp)\t#pop 1st!\n");
  fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr\n");
  fprintf(out, "sw\t$t0, %s\t#add value to variable\n",(yyvsp[(1) - (3)].id));
/*print message
  fprintf(out,"\n\n### PRINT THE ASSIGNMENT MESSAGE ###\n");
  fprintf(out,"li\t$v0, 4\t#print instruction\n");
  fprintf(out,"la\t$a0, emsg\t#put the message to be print\n");
  fprintf(out,"syscall\t\n");
  */
;}
    break;

  case 19:
#line 118 "parser.y"
    {if(PRINT_ERRORS) printf("reducing statement: procedure_statement\n");;}
    break;

  case 20:
#line 119 "parser.y"
    {if(PRINT_ERRORS) printf("reducing statement: compound_statement\n");;}
    break;

  case 21:
#line 121 "parser.y"
    {
  if(PRINT_ERRORS) printf("reducing statement: IF...THEN... ELSE\n");
  fprintf(out,"\n\n### IF THEN ELSE ###\n");
  fprintf(out, "lw\t$t0, ($sp)\t#pop 1st! (relop)\n");
  fprintf(out,"\n\n### PRINT THE RESULT ###\n");
  fprintf(out,"li\t$v0, 1\t#print instruction\n");
  fprintf(out,"move\t$a0, $t0\t#put the value to be print\n");
  fprintf(out,"syscall\t\n");
;}
    break;

  case 22:
#line 130 "parser.y"
    {if(PRINT_ERRORS) printf("reducing statement: WHILE...DO\n");;}
    break;

  case 23:
#line 134 "parser.y"
    {/*$$=symbol_is_declared($1);*/if(PRINT_ERRORS) printf("reducing procedure_statement: ID\n");
;}
    break;

  case 24:
#line 136 "parser.y"
    {
  if(PRINT_ERRORS) printf("reducing procedure_statement: ID OPAR expression_list CPAR\n");
  if(strcmp((yyvsp[(1) - (4)].id),"read")==0){
    fprintf(out,"\n\n### READ INPUT ###\n");
    fprintf(out,"li\t$v0, 4\t#print instruction\n");
    fprintf(out,"la\t$a0, readspace\t#put the message to be print\n");
    fprintf(out,"syscall\t\n"); 

    switch((yyvsp[(3) - (4)].charval)){
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
  else if(strcmp((yyvsp[(1) - (4)].id),"write")==0){
    fprintf(out,"\n\n### PRINT THE RESULT ###\n");
    fprintf(out,"li\t$v0, 4\t#print instruction\n");
    fprintf(out,"la\t$a0, writespace\t#put the message to be print\n");
    fprintf(out,"syscall\t\n"); 

    fprintf(out, "lw\t$t0, ($sp)\t#pop 1st!\n");

    switch((yyvsp[(3) - (4)].charval)){
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
;}
    break;

  case 25:
#line 198 "parser.y"
    {if(PRINT_ERRORS) printf("reducing expression_list: expression\n");;}
    break;

  case 26:
#line 199 "parser.y"
    {if(PRINT_ERRORS) printf("reducing expression_list: expression_list COMMA expression\n");;}
    break;

  case 27:
#line 203 "parser.y"
    {if(PRINT_ERRORS) printf("reducing expression simple_expression\n");;}
    break;

  case 28:
#line 204 "parser.y"
    {
  (yyval.charval)='i';if(PRINT_ERRORS) printf("reducing expression: simple_expression RELOP simple_expression\n");
  fprintf(out,"\n\n### PERFORMING RELOP ###\n");
  fprintf(out, "lw\t$t2, ($sp)\t#pop 1st! (relop)\n");

  fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr (relop)\n");
  fprintf(out, "lw\t$t1, ($sp)\t#pop 2nd!\n");
  fprintf(out, "subu\t$sp, $sp, 4\t#move the stack ptr\n");

  if(strcmp((yyvsp[(2) - (3)].string), "<")==0){
    fprintf(out, "slt\t$t0, $t1,$t2\t#is it less than?\n");
    fprintf(out, "BEQ \t$t0, 0,ELSE\t#go to else if not equal\n");
    fprintf(out, "li\t$t0, 1\t#t0 holds 1\n");
    fprintf(out, "j\tRES\t#jump to result!\n");
    fprintf(out, "ELSE: li\t$t0, 0\t#t0 holds 0\n");
    fprintf(out, "RES: sw\t$t0, ($sp)\t#push!\n");
  }
  else if(strcmp((yyvsp[(2) - (3)].string), ">")==0){
    fprintf(out, "slt\t$t0, $t2,$t1\t#is it greater than?\n");
    fprintf(out, "BEQ \t$t0, 0,ELSE\t#go to else if not equal\n");
    fprintf(out, "li\t$t0, 1\t#t0 holds 1\n");
    fprintf(out, "j\tRES\t#jump to result!\n");
    fprintf(out, "ELSE: li\t$t0, 0\t#t0 holds 0\n");
    fprintf(out, "RES: sw\t$t0, ($sp)\t#push!\n");
  }
  else if(strcmp((yyvsp[(2) - (3)].string), "<=")==0){
    fprintf(out, "BEQ\t$t1,$t2, IF\t#is it equal?\n");
    fprintf(out, "slt\t$t0, $t1,$t2\t#is it less than?\n");
    fprintf(out, "BEQ \t$t0, 0,ELSE\t#go to else if not equal\n");
    fprintf(out, "IF: li\t$t0, 1\t#t0 holds 1\n");
    fprintf(out, "j\tRES\t#jump to result!\n");
    fprintf(out, "ELSE: li\t$t0, 0\t#t0 holds 0\n");
    fprintf(out, "RES: sw\t$t0, ($sp)\t#push!\n");
  }
  else if(strcmp((yyvsp[(2) - (3)].string), ">=")==0){
    fprintf(out, "BEQ\t$t1,$t2, IF\t#is it equal?\n");
    fprintf(out, "slt\t$t0, $t2,$t1\t#is it greater than?\n");
    fprintf(out, "BEQ \t$t0, 0,ELSE\t#go to else if not equal\n");
    fprintf(out, "IF: li\t$t0, 1\t#t0 holds 1\n");
    fprintf(out, "j\tRES\t#jump to result!\n");
    fprintf(out, "ELSE: li\t$t0, 0\t#t0 holds 0\n");
    fprintf(out, "RES: sw\t$t0, ($sp)\t#push!\n");
  }
  fprintf(out, "sw\t$t0, ($sp)\t#push!\n");
;}
    break;

  case 29:
#line 252 "parser.y"
    {if(PRINT_ERRORS) printf("reducing simple_expression term\n");;}
    break;

  case 30:
#line 253 "parser.y"
    {if(PRINT_ERRORS) printf("reducing simple_expression sign term\n");;}
    break;

  case 31:
#line 254 "parser.y"
    {if((yyvsp[(1) - (3)].charval) == 'r' || (yyvsp[(3) - (3)].charval) == 'r')(yyval.charval) = 'r'; else (yyval.charval)='i'; if(PRINT_ERRORS) printf("reducing simple_expression: simple_expression ADDOP term\n");
fprintf(out,"\n\n### PERFORMING ADDITION ###\n");
fprintf(out, "lw\t$t0, ($sp)\t#pop 1st!\n");

fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr\n");
fprintf(out, "lw\t$t1, ($sp)\t#pop 2nd!\n");


fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr\n");

switch((yyvsp[(2) - (3)].charval)){
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
;}
    break;

  case 32:
#line 292 "parser.y"
    {if(PRINT_ERRORS) printf("reducing term: factor\n");;}
    break;

  case 33:
#line 293 "parser.y"
    {if((yyvsp[(1) - (3)].charval) == 'r' || (yyvsp[(3) - (3)].charval) == 'r')(yyval.charval) = 'r'; else (yyval.charval)='i';if(PRINT_ERRORS) printf("reducing term: term MULOP factor\n");
fprintf(out,"\n\n### PERFORMING MULTIPLICATION ###\n");
fprintf(out, "lw\t$t0, ($sp)\t#pop 1st!\n");
fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr\n");
fprintf(out, "lw\t$t1, ($sp)\t#pop 2nd!\n");
fprintf(out, "addu\t$sp, $sp, 4\t#move the ptr\n");
switch((yyvsp[(2) - (3)].charval)){
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
;}
    break;

  case 34:
#line 329 "parser.y"
    {(yyval.charval)=symbol_is_declared((yyvsp[(1) - (1)].id));if(PRINT_ERRORS) printf("reducing factor: ID\n");
fprintf(out, "\n\n### ADDING AN ID TO THE STACK ####\n");
fprintf(out, "lw\t $t0, %s\t #store value from id into t0\n",(yyvsp[(1) - (1)].id));
fprintf(out, "subu\t $sp, $sp, 4\t #move the stack ptr\n");
fprintf(out, "sw\t $t0, ($sp)\t #push!\n");
fprintf(out, "la\t$t0, %s\t #load address of var into t0",(yyvsp[(1) - (1)].id));
;}
    break;

  case 35:
#line 336 "parser.y"
    {if(PRINT_ERRORS) printf("reducing factor: ID OPAR expression_list CPAR\n");
;}
    break;

  case 36:
#line 338 "parser.y"
    {(yyval.charval)='i';if(PRINT_ERRORS) printf("reducing factor: INTNO\n");
//put value of current number at the top of the stack 
fprintf(out, "\n\n### ADDING AN INT TO THE STACK ####\n");
fprintf(out, "li\t$t0, %d\t #store value\n",(yyvsp[(1) - (1)].integer));
fprintf(out, "subu\t$sp, $sp, 4\t#move the stack ptr\n");
fprintf(out, "sw\t $t0, ($sp)\t#push!\n");

    /*print out what was just read in
  fprintf(out,"\n\n### PRINT THE RESULT ###\n");
  fprintf(out,"li\t$v0, 1\t#print instruction\n");
  fprintf(out,"move\t$a0, $t0\t#put the value to be print\n");
  fprintf(out,"syscall\t\n");*/
;}
    break;

  case 37:
#line 351 "parser.y"
    {(yyval.charval)='r';if(PRINT_ERRORS) printf("reducing factor: REALNO\n");
fprintf(out, "\n\n### ADDING A DOUBLE/FLOAT/REAL TO THE STACK ####\n");
fprintf(out, "li\t$t0, %f\t #store value\n",(yyvsp[(1) - (1)].real));
fprintf(out, "subu\t$sp, $sp, 4\t#move the stack ptr\n");
fprintf(out, "sw\t $t0, ($sp)\t#push!\n");

;}
    break;

  case 38:
#line 358 "parser.y"
    {if(PRINT_ERRORS) printf("reducing factor: OPAR expression CPAR\n");;}
    break;

  case 39:
#line 359 "parser.y"
    {if(PRINT_ERRORS) printf("reducing factor: NOT factor\n");;}
    break;

  case 40:
#line 363 "parser.y"
    {if(PRINT_ERRORS) printf("reducing sign: ADDOP\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 1872 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 366 "parser.y"

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


