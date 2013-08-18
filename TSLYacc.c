
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */


#include "tsee.h"
#include "tsc.h"
extern int yylex();
extern void yyerror();
void echo(const char*, const char*);



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

/* "%code requires" blocks.  */

#include "tsc.h"



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     VARIANT = 261,
     INC_OP = 262,
     DEC_OP = 263,
     LE_OP = 264,
     GE_OP = 265,
     EQ_OP = 266,
     NE_OP = 267,
     AND_OP = 268,
     OR_OP = 269,
     MUL_ASSIGN = 270,
     DIV_ASSIGN = 271,
     MOD_ASSIGN = 272,
     ADD_ASSIGN = 273,
     SUB_ASSIGN = 274,
     IFX = 275,
     ELSE = 276,
     IF = 277,
     WHILE = 278,
     DO = 279,
     FOR = 280,
     CONTINUE = 281,
     BREAK = 282,
     RETURN = 283,
     FUNCTION = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


	TSStr* strVal;
	PriExp* priExp;
	Operation* op;
	PostExp* postExp;
	ArgExpList* argExpList;
	UnaryExp* unaryExp;
	MulExp* mulExp;
	AddExp* addExp;
	RelExp* relExp;
	EqExp* eqExp;
	LogAndExp* logAndExp;
	LogOrExp* logOrExp;
	CondExp* condExp;
	AssignExp* assignExp;
	int assignOp;
	Exp* exp;
	IDList* idList;
	Stmt* stmt;
	CompStmt* compStmt;
	StmtList* stmtList;
	ExpStmt* expStmt;
	SelStmt* selStmt;
	ItorStmt* itorStmt;
	TransUnit* transUnit;
	ExtDecl* extDecl;
	FunDef* funDef;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */



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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   177

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  132

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,     2,     2,    37,     2,     2,
      31,    32,    35,    38,    33,    39,    30,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    47,
      40,    44,    41,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    18,    22,    27,
      31,    35,    37,    39,    41,    45,    47,    50,    52,    56,
      60,    64,    66,    70,    74,    76,    80,    84,    88,    92,
      94,    98,   102,   104,   108,   110,   114,   116,   122,   124,
     128,   130,   132,   134,   136,   138,   140,   142,   146,   148,
     152,   154,   156,   158,   160,   163,   167,   169,   172,   174,
     177,   183,   191,   197,   205,   213,   215,   218,   220,   222,
     229
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      71,     0,    -1,     3,    -1,     6,    -1,     3,    30,     3,
      -1,    49,    -1,    49,    31,    52,    32,    -1,    49,    31,
      32,    -1,    50,    31,    52,    32,    -1,    50,    31,    32,
      -1,    31,    63,    32,    -1,     4,    -1,     5,    -1,    61,
      -1,    52,    33,    61,    -1,    51,    -1,    34,    53,    -1,
      53,    -1,    54,    35,    51,    -1,    54,    36,    51,    -1,
      54,    37,    51,    -1,    54,    -1,    55,    38,    54,    -1,
      55,    39,    54,    -1,    55,    -1,    56,    40,    55,    -1,
      56,    41,    55,    -1,    56,     9,    55,    -1,    56,    10,
      55,    -1,    56,    -1,    57,    11,    56,    -1,    57,    12,
      56,    -1,    57,    -1,    58,    13,    57,    -1,    58,    -1,
      59,    14,    58,    -1,    59,    -1,    59,    42,    63,    43,
      60,    -1,    60,    -1,     6,    62,    61,    -1,    44,    -1,
      15,    -1,    16,    -1,    17,    -1,    18,    -1,    19,    -1,
      61,    -1,    63,    33,    61,    -1,     6,    -1,    64,    33,
       6,    -1,    66,    -1,    68,    -1,    69,    -1,    70,    -1,
      45,    46,    -1,    45,    67,    46,    -1,    65,    -1,    67,
      65,    -1,    47,    -1,    63,    47,    -1,    22,    31,    63,
      32,    65,    -1,    22,    31,    63,    32,    65,    21,    65,
      -1,    23,    31,    63,    32,    65,    -1,    24,    65,    23,
      31,    63,    32,    47,    -1,    25,    31,    68,    68,    63,
      32,    65,    -1,    72,    -1,    71,    72,    -1,    66,    -1,
      73,    -1,    29,     3,    31,    64,    32,    66,    -1,    29,
       3,    31,    32,    66,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    86,    95,   103,   108,   114,   120,   126,
     132,   137,   144,   153,   158,   166,   171,   178,   183,   190,
     197,   207,   212,   219,   229,   234,   241,   248,   255,   265,
     270,   277,   287,   292,   301,   306,   315,   320,   330,   335,
     345,   348,   351,   354,   357,   360,   366,   371,   380,   385,
     402,   407,   412,   417,   425,   429,   437,   442,   451,   455,
     463,   469,   479,   485,   491,   502,   507,   516,   521,   528,
     535
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "VARIANT", "INC_OP", "DEC_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "IFX", "ELSE", "IF", "WHILE",
  "DO", "FOR", "CONTINUE", "BREAK", "RETURN", "FUNCTION", "'.'", "'('",
  "')'", "','", "'!'", "'*'", "'/'", "'%'", "'+'", "'-'", "'<'", "'>'",
  "'?'", "':'", "'='", "'{'", "'}'", "';'", "$accept",
  "primary_expression", "op_expression", "postfix_expression",
  "argument_expression_list", "unary_expression",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "identifier_list", "statement", "compound_statement", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "translation_unit", "external_declaration", "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      46,    40,    41,    44,    33,    42,    47,    37,    43,    45,
      60,    62,    63,    58,    61,   123,   125,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    55,    55,    55,    56,    56,    56,    56,    56,    57,
      57,    57,    58,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    71,    71,    72,    72,    73,
      73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     4,     3,     4,     3,
       3,     1,     1,     1,     3,     1,     2,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     3,     1,     2,     1,     2,
       5,     7,     5,     7,     7,     1,     2,     1,     1,     6,
       5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    67,     0,    65,    68,     0,     2,    11,
      12,     3,     0,     0,     0,     0,     0,     0,    54,    58,
       5,     0,    15,    17,    21,    24,    29,    32,    34,    36,
      38,    46,     0,    56,    50,     0,    51,    52,    53,     1,
      66,     0,     0,    41,    42,    43,    44,    45,    40,     0,
       0,     0,     0,     0,     0,     3,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    55,    57,    48,     0,     0,
       4,    39,     0,     0,     0,     0,    10,     7,     0,    13,
       9,     0,    18,    19,    20,    22,    23,    27,    28,    25,
      26,    30,    31,    33,    35,     0,    47,    70,     0,     0,
       0,     0,     0,     0,     6,     0,     8,     0,    69,    49,
      60,    62,     0,     0,    14,    37,     0,     0,     0,    61,
      63,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    20,    21,    22,    88,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    49,    32,    79,    33,    34,    35,
      36,    37,    38,     4,     5,     6
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const yytype_int16 yypact[] =
{
       6,    29,    19,   -48,     4,   -48,   -48,   -24,    17,   -48,
     -48,   122,     5,    21,   102,    23,   117,   125,   -48,   -48,
      31,    36,   -48,   -48,   118,   -26,    -1,    60,    56,    -8,
     -48,   -48,    30,   -48,   -48,    70,   -48,   -48,   -48,   -48,
     -48,    25,    75,   -48,   -48,   -48,   -48,   -48,   -48,   117,
     117,   117,   109,    14,   -17,   -48,   -48,    24,    79,   139,
     139,   139,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   117,   117,   -48,   -48,   -48,   -48,    53,    48,
     -48,   -48,    58,    86,   115,    14,   -48,   -48,   131,   -48,
     -48,   135,   -48,   -48,   -48,   118,   118,   -26,   -26,   -26,
     -26,    -1,    -1,    60,    56,    27,   -48,   -48,    53,   144,
     102,   102,   117,   117,   -48,   117,   -48,   125,   -48,   -48,
     136,   -48,   140,   142,   -48,   -48,   102,   105,   102,   -48,
     -48,   -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   -48,   -48,   101,   100,   148,    40,    22,    66,    99,
     106,   -48,    54,   -47,   -48,   -13,   -48,   -14,     1,   -48,
     -39,   -48,   -48,   -48,   172,   -48
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,     3,    81,    54,    39,     3,    71,    41,    64,    65,
      89,    89,    62,    63,    85,    86,    73,     8,     9,    10,
      11,    76,     8,     9,    10,    11,   106,     8,     9,    10,
      11,    77,     7,     1,    72,     1,    50,    82,    83,    66,
      67,    12,    13,    14,    15,    16,   113,    42,    17,     2,
      16,     2,    51,    17,    53,    16,    87,    78,    17,   105,
      73,    19,    57,    73,     2,    18,    19,    58,   124,    70,
     117,    68,    69,     8,     9,    10,    11,    74,    80,   107,
     108,   109,     8,     9,    10,    11,    97,    98,    99,   100,
     110,    73,    12,    13,    14,    15,   120,   121,     2,   122,
     123,    16,    95,    96,    17,     8,     9,    10,    11,   118,
      16,    90,   129,    17,   131,     2,    75,    19,   111,    73,
       8,     9,    10,    11,    12,    13,    14,    15,     8,     9,
      10,    55,    84,    16,   101,   102,    17,    43,    44,    45,
      46,    47,     8,     9,    10,    55,   112,     2,    16,    19,
     119,    17,   130,    59,    60,    61,    16,   126,    91,    17,
      92,    93,    94,   114,   115,    56,    48,   116,   115,   103,
      16,   125,   127,    73,   128,    73,    40,   104
};

static const yytype_uint8 yycheck[] =
{
      14,     0,    49,    16,     0,     4,    14,    31,     9,    10,
      57,    58,    38,    39,    53,    32,    33,     3,     4,     5,
       6,    35,     3,     4,     5,     6,    73,     3,     4,     5,
       6,     6,     3,    29,    42,    29,    31,    50,    51,    40,
      41,    22,    23,    24,    25,    31,    85,    30,    34,    45,
      31,    45,    31,    34,    31,    31,    32,    32,    34,    72,
      33,    47,    31,    33,    45,    46,    47,    31,   115,    13,
      43,    11,    12,     3,     4,     5,     6,    47,     3,    78,
      32,    33,     3,     4,     5,     6,    64,    65,    66,    67,
      32,    33,    22,    23,    24,    25,   110,   111,    45,   112,
     113,    31,    62,    63,    34,     3,     4,     5,     6,   108,
      31,    32,   126,    34,   128,    45,    46,    47,    32,    33,
       3,     4,     5,     6,    22,    23,    24,    25,     3,     4,
       5,     6,    23,    31,    68,    69,    34,    15,    16,    17,
      18,    19,     3,     4,     5,     6,    31,    45,    31,    47,
       6,    34,    47,    35,    36,    37,    31,    21,    58,    34,
      59,    60,    61,    32,    33,    17,    44,    32,    33,    70,
      31,   117,    32,    33,    32,    33,     4,    71
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    45,    66,    71,    72,    73,     3,     3,     4,
       5,     6,    22,    23,    24,    25,    31,    34,    46,    47,
      49,    50,    51,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    63,    65,    66,    67,    68,    69,    70,     0,
      72,    31,    30,    15,    16,    17,    18,    19,    44,    62,
      31,    31,    65,    31,    63,     6,    53,    31,    31,    35,
      36,    37,    38,    39,     9,    10,    40,    41,    11,    12,
      13,    14,    42,    33,    47,    46,    65,     6,    32,    64,
       3,    61,    63,    63,    23,    68,    32,    32,    52,    61,
      32,    52,    51,    51,    51,    54,    54,    55,    55,    55,
      55,    56,    56,    57,    58,    63,    61,    66,    32,    33,
      32,    32,    31,    68,    32,    33,    32,    43,    66,     6,
      65,    65,    63,    63,    61,    60,    21,    32,    32,    65,
      47,    65
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
      yyerror (program, YY_("syntax error: cannot back up")); \
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
		  Type, Value, program); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, EEProgram* program)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, program)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    EEProgram* program;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (program);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, EEProgram* program)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, program)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    EEProgram* program;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, program);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, EEProgram* program)
#else
static void
yy_reduce_print (yyvsp, yyrule, program)
    YYSTYPE *yyvsp;
    int yyrule;
    EEProgram* program;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , program);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, program); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, EEProgram* program)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, program)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    EEProgram* program;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (program);

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
int yyparse (EEProgram* program);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
yyparse (EEProgram* program)
#else
int
yyparse (program)
    EEProgram* program;
#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

/* User initialization code.  */

{
	/*Just a mark place*/
}


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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

    {
	(yyval.priExp) = (PriExp*)_tsmalloc(sizeof(PriExp));
	(yyval.priExp)->type = 1; 
	(yyval.priExp)->token = (yyvsp[(1) - (1)].strVal); 
	printf("Identifier: %s.\n", (yyvsp[(1) - (1)].strVal)->String);
	;}
    break;

  case 3:

    {
	(yyval.priExp) = (PriExp*)_tsmalloc(sizeof(PriExp));
	(yyval.priExp)->type = 2; 
	(yyval.priExp)->token = (yyvsp[(1) - (1)].strVal); 
	printf("Variant: %s.\n", (yyvsp[(1) - (1)].strVal)->String);
	;}
    break;

  case 4:

    {
	(yyval.op) = (Operation*)_tsmalloc(sizeof(Operation));
	(yyval.op)->component = (yyvsp[(1) - (3)].strVal);
	(yyval.op)->function = (yyvsp[(3) - (3)].strVal);
	printf("Operation: %s.%s.\n", (yyvsp[(1) - (3)].strVal)->String, (yyvsp[(3) - (3)].strVal)->String);
	;}
    break;

  case 5:

    {
	(yyval.postExp) = (PostExp*)_tsmalloc(sizeof(PostExp));
	(yyval.postExp)->type = 1;
	(yyval.postExp)->comp.priExp = (yyvsp[(1) - (1)].priExp);
	;}
    break;

  case 6:

    {
	(yyval.postExp) = (PostExp*)_tsmalloc(sizeof(PostExp));
	(yyval.postExp)->type = 2;
	(yyval.postExp)->comp.funCall.priExp = (yyvsp[(1) - (4)].priExp);
	(yyval.postExp)->comp.funCall.argList = (yyvsp[(3) - (4)].argExpList);
	;}
    break;

  case 7:

    {
	(yyval.postExp) = (PostExp*)_tsmalloc(sizeof(PostExp));
	(yyval.postExp)->type = 2;
	(yyval.postExp)->comp.funCall.priExp = (yyvsp[(1) - (3)].priExp);
	(yyval.postExp)->comp.funCall.argList = NULL;
	;}
    break;

  case 8:

    {
	(yyval.postExp) = (PostExp*) _tsmalloc(sizeof(PostExp));
	(yyval.postExp)->type = 3;
	(yyval.postExp)->comp.opCall.op = (yyvsp[(1) - (4)].op);
	(yyval.postExp)->comp.opCall.argList = (yyvsp[(3) - (4)].argExpList);
	;}
    break;

  case 9:

    {
	(yyval.postExp) = (PostExp*) _tsmalloc(sizeof(PostExp));
	(yyval.postExp)->type = 3;
	(yyval.postExp)->comp.opCall.op = (yyvsp[(1) - (3)].op);
	(yyval.postExp)->comp.opCall.argList = NULL;
	;}
    break;

  case 10:

    {
	(yyval.postExp) = (PostExp*) _tsmalloc(sizeof(PostExp));
	(yyval.postExp)->type = 4;
	(yyval.postExp)->comp.exp = (yyvsp[(2) - (3)].exp);
	;}
    break;

  case 11:

    {
	(yyval.postExp) = (PostExp*) _tsmalloc(sizeof(PostExp));
	(yyval.postExp)->type = 5;
	(yyval.postExp)->comp.number = StrToNum((yyvsp[(1) - (1)].strVal));
	printf("Const: %u.\n", (yyval.postExp)->comp.number);
	StrDestroy((yyvsp[(1) - (1)].strVal));
	;}
    break;

  case 12:

    {
	(yyval.postExp) = (PostExp*) _tsmalloc(sizeof(PostExp));
	(yyval.postExp)->type = 6;
	(yyval.postExp)->comp.strVal = (yyvsp[(1) - (1)].strVal);
	printf("String Liberal: %s.\n", (yyval.postExp)->comp.strVal->String);
	;}
    break;

  case 13:

    {
	(yyval.argExpList) = (ArgExpList*)_tsmalloc(sizeof(ArgExpList)); 
	(yyval.argExpList)->type = 1;
	(yyval.argExpList)->comp.assignExp = (yyvsp[(1) - (1)].assignExp);
	;}
    break;

  case 14:

    {
	(yyval.argExpList) = (ArgExpList*)_tsmalloc(sizeof(ArgExpList)); 
	(yyval.argExpList)->type = 2;
	(yyval.argExpList)->comp.mulArgList.assignExp = (yyvsp[(3) - (3)].assignExp);
	(yyval.argExpList)->comp.mulArgList.argList = (yyvsp[(1) - (3)].argExpList);
	;}
    break;

  case 15:

    {
	(yyval.unaryExp) = (UnaryExp*) _tsmalloc(sizeof(UnaryExp));
	(yyval.unaryExp)->type = 1;
	(yyval.unaryExp)->comp.postExp = (yyvsp[(1) - (1)].postExp);
	;}
    break;

  case 16:

    {
	(yyval.unaryExp) = (UnaryExp*) _tsmalloc(sizeof(UnaryExp));
	(yyval.unaryExp)->type = 2;
	(yyval.unaryExp)->comp.unaryExp = (yyvsp[(2) - (2)].unaryExp);
	;}
    break;

  case 17:

    {
	(yyval.mulExp) = (MulExp*) _tsmalloc(sizeof(MulExp));
	(yyval.mulExp)->type = 1;
	(yyval.mulExp)->comp.unaryExp = (yyvsp[(1) - (1)].unaryExp);
	;}
    break;

  case 18:

    {
	(yyval.mulExp) = (MulExp*) _tsmalloc(sizeof(MulExp));
	(yyval.mulExp)->type = 2;
	(yyval.mulExp)->comp.caltor.op = 1;
	(yyval.mulExp)->comp.caltor.mulExp = (yyvsp[(1) - (3)].mulExp);
	(yyval.mulExp)->comp.caltor.postExp = (yyvsp[(3) - (3)].postExp);
	;}
    break;

  case 19:

    {
	(yyval.mulExp) = (MulExp*) _tsmalloc(sizeof(MulExp));
	(yyval.mulExp)->type = 2;
	(yyval.mulExp)->comp.caltor.op = 2;
	(yyval.mulExp)->comp.caltor.mulExp = (yyvsp[(1) - (3)].mulExp);
	(yyval.mulExp)->comp.caltor.postExp = (yyvsp[(3) - (3)].postExp);
	;}
    break;

  case 20:

    {
	(yyval.mulExp) = (MulExp*) _tsmalloc(sizeof(MulExp));
	(yyval.mulExp)->type = 2;
	(yyval.mulExp)->comp.caltor.op = 3;
	(yyval.mulExp)->comp.caltor.mulExp = (yyvsp[(1) - (3)].mulExp);
	(yyval.mulExp)->comp.caltor.postExp = (yyvsp[(3) - (3)].postExp);
	;}
    break;

  case 21:

    {
	(yyval.addExp) = (AddExp*)_tsmalloc(sizeof(AddExp));
	(yyval.addExp)->type = 1;
	(yyval.addExp)->comp.mulExp = (yyvsp[(1) - (1)].mulExp);
	;}
    break;

  case 22:

    {
	(yyval.addExp) = (AddExp*)_tsmalloc(sizeof(AddExp));
	(yyval.addExp)->type = 2;
	(yyval.addExp)->comp.caltor.op = 1;
	(yyval.addExp)->comp.caltor.mulExp = (yyvsp[(3) - (3)].mulExp);
	(yyval.addExp)->comp.caltor.addExp = (yyvsp[(1) - (3)].addExp);
	;}
    break;

  case 23:

    {
	(yyval.addExp) = (AddExp*)_tsmalloc(sizeof(AddExp));
	(yyval.addExp)->type = 2;
	(yyval.addExp)->comp.caltor.op = 2;
	(yyval.addExp)->comp.caltor.mulExp = (yyvsp[(3) - (3)].mulExp);
	(yyval.addExp)->comp.caltor.addExp = (yyvsp[(1) - (3)].addExp);
	;}
    break;

  case 24:

    {
	(yyval.relExp) = (RelExp*) _tsmalloc(sizeof(RelExp));
	(yyval.relExp)->type = 1;
	(yyval.relExp)->comp.addExp = (yyvsp[(1) - (1)].addExp);
	;}
    break;

  case 25:

    {
	(yyval.relExp) = (RelExp*) _tsmalloc(sizeof(RelExp));
	(yyval.relExp)->type = 2;
	(yyval.relExp)->comp.caltor.addExp = (yyvsp[(3) - (3)].addExp);
	(yyval.relExp)->comp.caltor.relExp = (yyvsp[(1) - (3)].relExp);
	(yyval.relExp)->comp.caltor.op = 1;
	;}
    break;

  case 26:

    {
	(yyval.relExp) = (RelExp*) _tsmalloc(sizeof(RelExp));
	(yyval.relExp)->type = 2;
	(yyval.relExp)->comp.caltor.addExp = (yyvsp[(3) - (3)].addExp);
	(yyval.relExp)->comp.caltor.relExp = (yyvsp[(1) - (3)].relExp);
	(yyval.relExp)->comp.caltor.op = 2;
	;}
    break;

  case 27:

    {
	(yyval.relExp) = (RelExp*) _tsmalloc(sizeof(RelExp));
	(yyval.relExp)->type = 2;
	(yyval.relExp)->comp.caltor.addExp = (yyvsp[(3) - (3)].addExp);
	(yyval.relExp)->comp.caltor.relExp = (yyvsp[(1) - (3)].relExp);
	(yyval.relExp)->comp.caltor.op = 3;
	;}
    break;

  case 28:

    {
	(yyval.relExp) = (RelExp*) _tsmalloc(sizeof(RelExp));
	(yyval.relExp)->type = 2;
	(yyval.relExp)->comp.caltor.addExp = (yyvsp[(3) - (3)].addExp);
	(yyval.relExp)->comp.caltor.relExp = (yyvsp[(1) - (3)].relExp);
	(yyval.relExp)->comp.caltor.op = 4;
	;}
    break;

  case 29:

    {
	(yyval.eqExp) = (EqExp*) _tsmalloc(sizeof(EqExp));
	(yyval.eqExp)->type = 1;
	(yyval.eqExp)->comp.relExp = (yyvsp[(1) - (1)].relExp);
	;}
    break;

  case 30:

    {
	(yyval.eqExp) = (EqExp*) _tsmalloc(sizeof(EqExp));
	(yyval.eqExp)->type = 2;
	(yyval.eqExp)->comp.caltor.relExp = (yyvsp[(3) - (3)].relExp);
	(yyval.eqExp)->comp.caltor.eqExp = (yyvsp[(1) - (3)].eqExp);
	(yyval.eqExp)->comp.caltor.op = 1;
	;}
    break;

  case 31:

    {
	(yyval.eqExp) = (EqExp*) _tsmalloc(sizeof(EqExp));
	(yyval.eqExp)->type = 2;
	(yyval.eqExp)->comp.caltor.relExp = (yyvsp[(3) - (3)].relExp);
	(yyval.eqExp)->comp.caltor.eqExp = (yyvsp[(1) - (3)].eqExp);
	(yyval.eqExp)->comp.caltor.op = 3;
	;}
    break;

  case 32:

    {
	(yyval.logAndExp) = (LogAndExp*) _tsmalloc(sizeof(LogAndExp));
	(yyval.logAndExp)->type = 1;
	(yyval.logAndExp)->comp.eqExp = (yyvsp[(1) - (1)].eqExp);
	;}
    break;

  case 33:

    {
	(yyval.logAndExp) = (LogAndExp*) _tsmalloc(sizeof(LogAndExp));
	(yyval.logAndExp)->type = 2;
	(yyval.logAndExp)->comp.caltor.logExp = (yyvsp[(1) - (3)].logAndExp);
	(yyval.logAndExp)->comp.caltor.eqExp = (yyvsp[(3) - (3)].eqExp);
	;}
    break;

  case 34:

    {
	(yyval.logOrExp) = (LogOrExp*) _tsmalloc(sizeof(LogOrExp));
	(yyval.logOrExp)->type = 1;
	(yyval.logOrExp)->comp.andExp = (yyvsp[(1) - (1)].logAndExp);
	;}
    break;

  case 35:

    {
	(yyval.logOrExp) = (LogOrExp*) _tsmalloc(sizeof(LogOrExp));
	(yyval.logOrExp)->type = 2;
	(yyval.logOrExp)->comp.caltor.andExp = (yyvsp[(3) - (3)].logAndExp);
	(yyval.logOrExp)->comp.caltor.orExp = (yyvsp[(1) - (3)].logOrExp);
	;}
    break;

  case 36:

    {
	(yyval.condExp) = (CondExp*) _tsmalloc(sizeof(CondExp));
	(yyval.condExp)->type = 1;
	(yyval.condExp)->comp.orExp = (yyvsp[(1) - (1)].logOrExp);
	;}
    break;

  case 37:

    {
	(yyval.condExp) = (CondExp*) _tsmalloc(sizeof(CondExp));
	(yyval.condExp)->type = 2;
	(yyval.condExp)->comp.mulCaltor.orExp = (yyvsp[(1) - (5)].logOrExp);
	(yyval.condExp)->comp.mulCaltor.exp = (yyvsp[(3) - (5)].exp);
	(yyval.condExp)->comp.mulCaltor.condExp = (yyvsp[(5) - (5)].condExp);
	;}
    break;

  case 38:

    {
	(yyval.assignExp) = (AssignExp*) _tsmalloc(sizeof(AssignExp));
	(yyval.assignExp)->type = 1;
	(yyval.assignExp)->comp.condExp = (yyvsp[(1) - (1)].condExp);
	;}
    break;

  case 39:

    {
	(yyval.assignExp) = (AssignExp*) _tsmalloc(sizeof(AssignExp));
	(yyval.assignExp)->type = 2;
	(yyval.assignExp)->comp.exp.strVal = (yyvsp[(1) - (3)].strVal);
	(yyval.assignExp)->comp.exp.op = (yyvsp[(2) - (3)].assignOp);
	(yyval.assignExp)->comp.exp.assignExp = (yyvsp[(3) - (3)].assignExp);
	;}
    break;

  case 40:

    {
	(yyval.assignOp) = 1;
	;}
    break;

  case 41:

    {
	(yyval.assignOp) = 2;
	;}
    break;

  case 42:

    {
	(yyval.assignOp) = 3;
	;}
    break;

  case 43:

    {
	(yyval.assignOp) = 4;
	;}
    break;

  case 44:

    {
	(yyval.assignOp) = 5;
	;}
    break;

  case 45:

    {
	(yyval.assignOp) = 6;
	;}
    break;

  case 46:

    {
	(yyval.exp) = (Exp*) _tsmalloc(sizeof(Exp));
	(yyval.exp)->type = 1;
	(yyval.exp)->comp.assignExp = (yyvsp[(1) - (1)].assignExp);
	;}
    break;

  case 47:

    {
	(yyval.exp) = (Exp*) _tsmalloc(sizeof(Exp));
	(yyval.exp)->type = 2;
	(yyval.exp)->comp.mulExp.assignExp = (yyvsp[(3) - (3)].assignExp);
	(yyval.exp)->comp.mulExp.exp = (yyvsp[(1) - (3)].exp);
	;}
    break;

  case 48:

    {
	(yyval.idList) = (IDList*) _tsmalloc(sizeof(IDList));
	(yyval.idList)->type = 1;
	(yyval.idList)->comp.id = (yyvsp[(1) - (1)].strVal);
	;}
    break;

  case 49:

    {
	IDList* temp;
	(yyval.idList) = (IDList*) _tsmalloc(sizeof(IDList));
	(yyval.idList)->type = 2;
	(yyval.idList)->comp.mulExp.id = (yyvsp[(3) - (3)].strVal);
	(yyval.idList)->comp.mulExp.ilist = (yyvsp[(1) - (3)].idList);
	printf("ID List:\n");
	temp = (yyval.idList);
	while(temp->type != 1){
		printf("%s\n", temp->comp.mulExp.id->String);
		temp = temp->comp.mulExp.ilist;
	}
	printf("%s\n", temp->comp.id->String);
	;}
    break;

  case 50:

    {
	(yyval.stmt) = (Stmt*) _tsmalloc(sizeof(Stmt));
	(yyval.stmt)->type = 1;
	(yyval.stmt)->comp.compStmt = (yyvsp[(1) - (1)].compStmt);
	;}
    break;

  case 51:

    {
	(yyval.stmt) = (Stmt*) _tsmalloc(sizeof(Stmt));
	(yyval.stmt)->type = 2;
	(yyval.stmt)->comp.expStmt = (yyvsp[(1) - (1)].expStmt);
	;}
    break;

  case 52:

    {
	(yyval.stmt) = (Stmt*) _tsmalloc(sizeof(Stmt));
	(yyval.stmt)->type = 3;
	(yyval.stmt)->comp.selStmt = (yyvsp[(1) - (1)].selStmt);
	;}
    break;

  case 53:

    {
	(yyval.stmt) = (Stmt*) _tsmalloc(sizeof(Stmt));
	(yyval.stmt)->type = 4;
	(yyval.stmt)->comp.itorStmt = (yyvsp[(1) - (1)].itorStmt);
	;}
    break;

  case 54:

    {
	(yyval.compStmt) = (CompStmt*) _tsmalloc(sizeof(CompStmt));
	(yyval.compStmt)->type = 1;
	;}
    break;

  case 55:

    {
	(yyval.compStmt) = (CompStmt*) _tsmalloc(sizeof(CompStmt));
	(yyval.compStmt)->type = 2;
	(yyval.compStmt)->stmtList = (yyvsp[(2) - (3)].stmtList);
	;}
    break;

  case 56:

    {
	(yyval.stmtList) = (StmtList*) _tsmalloc(sizeof(StmtList));
	(yyval.stmtList)->type = 1;
	(yyval.stmtList)->comp.stmt = (yyvsp[(1) - (1)].stmt);
	;}
    break;

  case 57:

    {
	(yyval.stmtList) = (StmtList*) _tsmalloc(sizeof(StmtList));
	(yyval.stmtList)->type = 2;
	(yyval.stmtList)->comp.list.stmt = (yyvsp[(2) - (2)].stmt);
	(yyval.stmtList)->comp.list.slist = (yyvsp[(1) - (2)].stmtList);
	;}
    break;

  case 58:

    {
	(yyval.expStmt) = (ExpStmt*) _tsmalloc(sizeof(ExpStmt));
	(yyval.expStmt)->type = 1;
	;}
    break;

  case 59:

    {
	(yyval.expStmt) = (ExpStmt*) _tsmalloc(sizeof(ExpStmt));
	(yyval.expStmt)->type = 2;
	(yyval.expStmt)->exp = (yyvsp[(1) - (2)].exp);
	;}
    break;

  case 60:

    {
	(yyval.selStmt) = (SelStmt*) _tsmalloc(sizeof(SelStmt));
	(yyval.selStmt)->type = 1;
	(yyval.selStmt)->exp = (yyvsp[(3) - (5)].exp);
	(yyval.selStmt)->ifStmt = (yyvsp[(5) - (5)].stmt);
	;}
    break;

  case 61:

    {
	(yyval.selStmt) = (SelStmt*) _tsmalloc(sizeof(SelStmt));
	(yyval.selStmt)->type = 1;
	(yyval.selStmt)->exp = (yyvsp[(3) - (7)].exp);
	(yyval.selStmt)->ifStmt = (yyvsp[(5) - (7)].stmt);
	(yyval.selStmt)->elStmt = (yyvsp[(7) - (7)].stmt);
	;}
    break;

  case 62:

    {
	(yyval.itorStmt) = (ItorStmt*) _tsmalloc(sizeof(ItorStmt));
	(yyval.itorStmt)->type = 1;
	(yyval.itorStmt)->comp.wstmt.exp = (yyvsp[(3) - (5)].exp);
	(yyval.itorStmt)->comp.wstmt.stmt = (yyvsp[(5) - (5)].stmt);
	;}
    break;

  case 63:

    {
	(yyval.itorStmt) = (ItorStmt*) _tsmalloc(sizeof(ItorStmt));
	(yyval.itorStmt)->type = 2;
	(yyval.itorStmt)->comp.wstmt.exp = (yyvsp[(5) - (7)].exp);
	(yyval.itorStmt)->comp.wstmt.stmt = (yyvsp[(2) - (7)].stmt);
	;}
    break;

  case 64:

    {
	(yyval.itorStmt) = (ItorStmt*) _tsmalloc(sizeof(ItorStmt));
	(yyval.itorStmt)->type = 3;
	(yyval.itorStmt)->comp.fstmt.expStmt1 = (yyvsp[(3) - (7)].expStmt);
	(yyval.itorStmt)->comp.fstmt.expStmt2 = (yyvsp[(4) - (7)].expStmt);
	(yyval.itorStmt)->comp.fstmt.exp = (yyvsp[(5) - (7)].exp);
	(yyval.itorStmt)->comp.fstmt.stmt = (yyvsp[(7) - (7)].stmt);
	;}
    break;

  case 65:

    {
	(yyval.transUnit) = (TransUnit*) _tsmalloc(sizeof(TransUnit));
	(yyval.transUnit)->type = 1;
	(yyval.transUnit)->comp.extDecl = (yyvsp[(1) - (1)].extDecl);
	;}
    break;

  case 66:

    {
	(yyval.transUnit) = (TransUnit*) _tsmalloc(sizeof(TransUnit));
	(yyval.transUnit)->type = 1;
	(yyval.transUnit)->comp.mulUnit.extDecl = (yyvsp[(2) - (2)].extDecl);
	(yyval.transUnit)->comp.mulUnit.transUnit = (yyvsp[(1) - (2)].transUnit);
	;}
    break;

  case 67:

    {
	(yyval.extDecl) = (ExtDecl*) _tsmalloc(sizeof(ExtDecl));
	(yyval.extDecl)->type = 1;
	(yyval.extDecl)->comp.compStmt = (yyvsp[(1) - (1)].compStmt);
	;}
    break;

  case 68:

    {
	(yyval.extDecl) = (ExtDecl*) _tsmalloc(sizeof(ExtDecl));
	(yyval.extDecl)->type = 2;
	(yyval.extDecl)->comp.funDef = (yyvsp[(1) - (1)].funDef);
	;}
    break;

  case 69:

    {
	(yyval.funDef) = (FunDef*) _tsmalloc(sizeof(FunDef));
	(yyval.funDef)->name = (yyvsp[(2) - (6)].strVal);
	(yyval.funDef)->ilist = (yyvsp[(4) - (6)].idList);
	(yyval.funDef)->compStmt = (yyvsp[(6) - (6)].compStmt);
	printf("Found function: %s.\n", (yyvsp[(2) - (6)].strVal)->String);
	;}
    break;

  case 70:

    {
	(yyval.funDef) = (FunDef*) _tsmalloc(sizeof(FunDef));
	(yyval.funDef)->name = (yyvsp[(2) - (5)].strVal);
	(yyval.funDef)->ilist = NULL;
	(yyval.funDef)->compStmt = (yyvsp[(5) - (5)].compStmt);
	printf("Found function: %s.\n", (yyvsp[(2) - (5)].strVal)->String);
	;}
    break;



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
      yyerror (program, YY_("syntax error"));
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
	    yyerror (program, yymsg);
	  }
	else
	  {
	    yyerror (program, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
		      yytoken, &yylval, program);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
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
		  yystos[yystate], yyvsp, program);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (program, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, program);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, program);
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




#include <stdio.h>

extern char yytext[];
extern int column;

void echo(const char* grouping, const char* terms){
	printf("grouping found: %s => %s.\n", grouping, terms);
}


