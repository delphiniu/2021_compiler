/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "compiler_hw3.y"

    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    #define codegen(...) \
        do { \
            for (int i = 0; i < INDENT; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    
    /* Other global variables */
    FILE *fout = NULL;
    bool HAS_ERROR = false;
    int INDENT = 0;
    
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(/* ... */);
    static void insert_symbol(char *, int);
    static int lookup_symbol(char *);
    static void dump_symbol(/* ... */);
    static void precedence(char);
    static void print_optr(char, char);
    static void new_expr();
    static void type_validation(char, char, char);
    static char *ret_type(char);
    static char *itostr(int);
    static char *ftostr(float);
    static char *tostr(char *);
    static void incdec_codegen(int, int);
    static void print_assign();

    // variables for print .j file
    char load_type = '\0';
    char index_cast = '\0';
    int onearith_addr = 0;
    int printbool_num = 0;
    int gtr_num = 0;
    int leq_num = 0;
    int eql_num = 0;
    int neq_num = 0;
    int lss_num = 0;
    int sign_num = 0;
    int reverse_num = 0;
    int while_num = 0;
    int while_top = -1;
    int while_stack[100];
    int for_num = 0;
    int for_top = -1;
    int for_stack[100];
    int if_num = 0;
    int if_top = -1;
    int if_stack[100];
    int end_top = -1;
    int end_stack[100];
    int end_num = 0;
    int assign_ad = 0;
    int isArray = 0;
    int rhs_ad = 0;
    int load_array = 0;
    char *assign_optr;

    // variables for correct output message
    int declare = 0;
    int scope_level = -1;
    int addr = 0;
    int top = -1;
    int parr = 0;
    int errcond = 0;
    int deferr = 0;
    int rhs = 1;
    char type[10], printype[10], ctype = '\0', asgn = '\0';
    char id[10];
    char check_valid[2][10] = {{'\0'}, {'\0'}};
    table *tb_stack[10];
    char sign[100];
    char errlhs[7] = "";
    char ptable[2][13] = {{'|', '&', '<', '>', 'a', 'b', 'c', 'd', '+', '-', '*', '/', '%'},
                          {'0', '1', '2', '2', '2', '2', '2', '2', '3', '3', '4', '4', '4'}};
    estack *exprs;

#line 163 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    BOOL = 260,
    STRING = 261,
    SEMICOLON = 262,
    LoopStmt = 263,
    PRINT = 264,
    INC = 265,
    DEC = 266,
    BIG_EQU = 267,
    SMALL_EQU = 268,
    EQUAL = 269,
    NOT_EQUAL = 270,
    AND = 271,
    OR = 272,
    TRUE = 273,
    FALSE = 274,
    IF = 275,
    ELSE = 276,
    WHILE = 277,
    FOR = 278,
    ADD_ASSIGN = 279,
    SUB_ASSIGN = 280,
    MUL_ASSIGN = 281,
    QUO_ASSIGN = 282,
    REM_ASSIGN = 283,
    INT_LIT = 284,
    FLOAT_LIT = 285,
    STRING_LIT = 286,
    IDENT = 287
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define BOOL 260
#define STRING 261
#define SEMICOLON 262
#define LoopStmt 263
#define PRINT 264
#define INC 265
#define DEC 266
#define BIG_EQU 267
#define SMALL_EQU 268
#define EQUAL 269
#define NOT_EQUAL 270
#define AND 271
#define OR 272
#define TRUE 273
#define FALSE 274
#define IF 275
#define ELSE 276
#define WHILE 277
#define FOR 278
#define ADD_ASSIGN 279
#define SUB_ASSIGN 280
#define MUL_ASSIGN 281
#define QUO_ASSIGN 282
#define REM_ASSIGN 283
#define INT_LIT 284
#define FLOAT_LIT 285
#define STRING_LIT 286
#define IDENT 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 100 "compiler_hw3.y"

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 286 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

#define YYUNDEFTOK  2
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    39,     2,     2,    46,     2,     2,
      34,    35,    44,    42,     2,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      40,    38,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   135,   135,   139,   143,   144,   145,   146,   147,   148,
     149,   150,   154,   161,   165,   172,   176,   182,   189,   194,
     199,   200,   202,   211,   218,   224,   230,   235,   239,   243,
     247,   248,   249,   250,   255,   268,   280,   285,   286,   287,
     288,   292,   361,   362,   363,   379,   396,   412,   417,   430,
     431,   435,   452,   456,   457,   461,   462,   465,   468,   471,
     474,   480,   486,   487,   491,   495,   496,   500,   501,   502,
     503,   504,   505,   509,   510,   514,   515,   519,   520,   524,
     525,   526,   530,   537,   550,   554,   559,   563,   568,   572,
     573,   574,   575,   576,   577,   578,   579,   583,   584,   585,
     594,   605,   609,   616,   648,   652,   662,   666,   680,   683
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "BOOL", "STRING",
  "SEMICOLON", "LoopStmt", "PRINT", "INC", "DEC", "BIG_EQU", "SMALL_EQU",
  "EQUAL", "NOT_EQUAL", "AND", "OR", "TRUE", "FALSE", "IF", "ELSE",
  "WHILE", "FOR", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN",
  "REM_ASSIGN", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "IDENT", "';'",
  "'('", "')'", "'{'", "'}'", "'='", "'\"'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "'['", "']'", "$accept", "Program", "Start",
  "StatementList", "InterWhileCond", "WhileLeaveExpr", "while_end",
  "PrintForLabel", "ForLeaveExpr", "ForAssign", "for_end", "IfStmt",
  "ElseStmt", "IfLeaveExpr", "ElseLeaveExpr", "IfEndScope", "ElseEndScope",
  "Cond", "NewScope", "EndScope", "Statement", "DeclarationStmt", "Type",
  "TypeName", "Ident", "LitInit", "Literal", "str", "Expr", "LeaveExpr",
  "or", "Assign", "AssignOptr", "ErrLHS", "AndExpr", "and", "CmprExpr",
  "Cmpr", "AddExpr", "Add", "MulExpr", "Mul", "UnaExpr", "SignOpt",
  "Reverse", "Atom", "EnterCast", "Boolean", "PrintStmt", "EnterPrint",
  "LeavePrint", "IndHead", "IndEnd", "BracHead", "BracEnd", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    59,    40,    41,   123,   125,    61,    34,
      60,    62,    43,    45,    42,    47,    37,    33,    91,    93
};
# endif

#define YYPACT_NINF (-137)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-101)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -137,    27,   223,  -137,  -137,  -137,  -137,  -137,  -137,    -4,
      11,    15,    17,   -26,   -26,    12,  -137,    52,    32,  -137,
      44,  -137,  -137,    75,    66,  -137,    68,    23,    86,   105,
    -137,  -137,    85,    85,  -137,    85,  -137,  -137,  -137,  -137,
     145,  -137,   -23,   224,  -137,    85,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,    85,    85,  -137,  -137,    85,  -137,  -137,
    -137,    85,    44,    44,  -137,  -137,    29,    67,    -2,  -137,
    -137,    82,    85,  -137,  -137,  -137,    48,  -137,    85,  -137,
    -137,    83,  -137,  -137,    85,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,    61,  -137,  -137,    85,    73,    79,  -137,  -137,  -137,
    -137,   224,  -137,  -137,    70,    85,  -137,    70,   -10,  -137,
    -137,    96,  -137,  -137,    84,  -137,  -137,  -137,  -137,    87,
    -137,   101,   103,  -137,  -137,  -137,    85,  -137,   223,   101,
      85,    70,   102,   223,  -137,  -137,  -137,   119,  -137,   102,
    -137,    -8,  -137,   171,  -137,   109,  -137,   110,   223,  -137,
      85,    85,   102,  -137,  -137,  -137,   224,   108,  -137,   111,
    -137,   101,   101,   223,   223,   102,   102,   119,  -137,   197,
    -137,  -137,  -137
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,    86,     1,    37,    38,    40,    39,    32,     0,
       0,     0,     0,    86,    86,    88,     2,    86,     0,    30,
       0,    36,    51,    50,    63,    66,    74,    78,     0,     0,
      33,   104,    86,    86,    12,    86,    84,    85,    87,    11,
      86,    41,    44,    54,    52,    86,    70,    69,    71,    72,
      64,    67,    68,    86,    86,    75,    76,    86,    79,    80,
      81,    86,     0,     0,    45,    46,   108,     0,    89,    94,
      82,     0,    86,   101,   102,    83,     0,    27,    86,    51,
       4,     0,   106,    34,    86,    56,    57,    58,    59,    60,
      55,    31,    61,    49,    62,    65,    73,    77,    92,    93,
      48,     0,    90,    91,    86,     0,     0,   105,   103,    51,
      27,    54,    42,    43,     0,    86,    47,     0,     0,   109,
      95,     0,    23,    51,     0,   107,    35,    51,    96,    97,
      98,     0,     0,    13,    15,    53,    86,    28,    86,     0,
      86,     0,     0,    86,    27,    99,    29,    22,    25,     0,
      51,     0,    19,    86,    14,     0,    16,     0,    86,     6,
      86,    86,     0,    51,    51,    21,    54,     0,    24,     0,
      17,     0,     0,    86,    86,     0,     0,    22,    26,    86,
      18,    20,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,   -17,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,   -30,  -137,  -137,  -137,  -137,  -100,  -108,  -136,
    -137,  -137,  -137,    81,   -25,  -137,   -70,  -137,   -31,   -73,
    -137,  -104,  -137,  -137,   106,  -137,  -137,  -137,   -33,  -137,
      94,  -137,  -137,   120,   143,  -137,  -137,    80,  -137,  -137,
    -137,   -63,   -99,  -137,  -137
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    78,   132,   153,   140,   155,   169,
     179,    17,   152,   121,   167,   147,   177,   109,   138,   148,
      18,    19,    20,    21,    42,    83,    69,   101,    22,    43,
      45,    91,    92,   115,    23,    53,    24,    54,    25,    57,
      26,    61,    27,    28,    29,    70,    71,    75,    30,    32,
     108,    84,   126,    72,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    76,    77,    68,    79,   104,   111,   124,   102,   103,
     123,   112,   157,   154,    93,    81,    13,    14,   128,    64,
      65,    95,    41,    80,    96,    82,   165,     3,   137,    67,
      31,   143,  -100,  -100,  -100,  -100,   122,    98,    99,   178,
     180,   106,   145,   158,   150,    33,    82,   110,   130,    34,
     133,    35,   -10,   114,   135,     4,     5,     6,     7,    15,
       8,     9,   170,   173,   174,    40,   136,    58,    59,    60,
     -88,   -88,    10,   117,    11,    12,    41,   156,    46,    47,
      48,    49,    50,   107,   127,     4,     5,     6,     7,   -10,
     166,   168,    44,   129,    13,    14,    62,    63,   100,    15,
     116,    73,    74,   -88,   -88,   141,    51,    52,   118,   144,
      55,    56,    64,    65,   119,    64,    65,   134,    41,   125,
      66,   142,    67,    73,    74,    67,   149,    13,    14,   163,
     164,   131,    15,    36,    37,    82,   159,   137,   139,   146,
     151,   162,   160,   171,   161,    -5,   172,   181,     4,     5,
       6,     7,   105,     8,     9,    97,   175,   176,    38,    94,
       0,   113,   182,   -88,   -88,    10,     0,    11,    12,     0,
       0,    -7,     0,     0,     4,     5,     6,     7,     0,     8,
       9,     0,    -5,     0,     0,     0,     0,    13,    14,   -88,
     -88,    10,    15,    11,    12,     0,     0,    -9,     0,     0,
       4,     5,     6,     7,     0,     8,     9,     0,    -7,     0,
       0,     0,     0,    13,    14,   -88,   -88,    10,    15,    11,
      12,     0,     0,     0,     0,     0,     4,     5,     6,     7,
       0,     8,     9,     0,    -9,     0,     0,     0,     0,    13,
      14,   -88,   -88,    10,    15,    11,    12,     0,    85,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,    13,    14,     0,     0,     0,
      15
};

static const yytype_int16 yycheck[] =
{
      17,    32,    33,    28,    35,    68,    79,   111,    10,    11,
     110,    81,    20,   149,    45,    38,    42,    43,   117,    29,
      30,    54,    32,    40,    57,    48,   162,     0,    36,    39,
      34,   139,     3,     4,     5,     6,   109,    62,    63,   175,
     176,    72,   141,   151,   144,    34,    48,    78,   118,    34,
     123,    34,     0,    84,   127,     3,     4,     5,     6,    47,
       8,     9,   166,   171,   172,    33,   129,    44,    45,    46,
      18,    19,    20,   104,    22,    23,    32,   150,    12,    13,
      14,    15,    16,    35,   115,     3,     4,     5,     6,    37,
     163,   164,    17,   118,    42,    43,    10,    11,    31,    47,
      39,    18,    19,    18,    19,   136,    40,    41,    35,   140,
      42,    43,    29,    30,    35,    29,    30,    33,    32,    49,
      34,   138,    39,    18,    19,    39,   143,    42,    43,   160,
     161,    35,    47,    13,    14,    48,   153,    36,    35,    37,
      21,   158,    33,    35,    34,     0,    35,   177,     3,     4,
       5,     6,    71,     8,     9,    61,   173,   174,    15,    53,
      -1,    81,   179,    18,    19,    20,    -1,    22,    23,    -1,
      -1,     0,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    37,    -1,    -1,    -1,    -1,    42,    43,    18,
      19,    20,    47,    22,    23,    -1,    -1,     0,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    37,    -1,
      -1,    -1,    -1,    42,    43,    18,    19,    20,    47,    22,
      23,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    37,    -1,    -1,    -1,    -1,    42,
      43,    18,    19,    20,    47,    22,    23,    -1,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    42,    43,    -1,    -1,    -1,
      47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,     3,     4,     5,     6,     8,     9,
      20,    22,    23,    42,    43,    47,    53,    61,    70,    71,
      72,    73,    78,    84,    86,    88,    90,    92,    93,    94,
      98,    34,    99,    34,    34,    34,    93,    93,    94,    53,
      33,    32,    74,    79,    17,    80,    12,    13,    14,    15,
      16,    40,    41,    85,    87,    42,    43,    89,    44,    45,
      46,    91,    10,    11,    29,    30,    34,    39,    74,    76,
      95,    96,   103,    18,    19,    97,    78,    78,    54,    78,
      53,    38,    48,    75,   101,    24,    25,    26,    27,    28,
      38,    81,    82,    78,    84,    88,    88,    90,    74,    74,
      31,    77,    10,    11,   101,    73,    78,    35,   100,    67,
      78,    79,    76,    97,    78,    83,    39,    78,    35,    35,
     104,    63,    79,    67,    81,    49,   102,    78,   102,    74,
      76,    35,    55,    79,    33,    79,   101,    36,    68,    35,
      57,    78,    53,    68,    78,   102,    37,    65,    69,    53,
      67,    21,    62,    56,    69,    58,    79,    20,    68,    53,
      33,    34,    53,    78,    78,    69,    79,    64,    79,    59,
      81,    35,    35,    68,    68,    53,    53,    66,    69,    60,
      69,    62,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    62,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    70,    70,    70,    71,    71,    72,    73,    73,    73,
      73,    74,    75,    75,    75,    76,    76,    76,    77,    78,
      78,    79,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    83,    84,    84,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    91,    92,    92,    93,    93,    93,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    97,    97,    98,    99,   100,   101,   102,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     3,     2,    11,    10,    19,    18,
       1,     2,     0,     1,     1,     0,     1,     1,     1,    10,
      10,     4,     0,     1,     1,     1,     1,     0,     1,     1,
       1,     3,     1,     1,     3,     5,     1,     1,     1,     1,
       1,     1,     2,     2,     0,     1,     1,     3,     1,     3,
       1,     0,     1,     4,     0,     1,     1,     1,     1,     1,
       1,     0,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     2,     2,     2,     0,     2,     0,     1,
       2,     2,     2,     2,     1,     3,     4,     4,     4,     7,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 135 "compiler_hw3.y"
                          { dump_symbol(); }
#line 1617 "y.tab.c"
    break;

  case 3:
#line 139 "compiler_hw3.y"
      { create_symbol(); new_expr(); }
#line 1623 "y.tab.c"
    break;

  case 12:
#line 154 "compiler_hw3.y"
      {
        fprintf(fout, "while_loop%d:\n", while_num);
        while_stack[++while_top] = while_num;
      }
#line 1632 "y.tab.c"
    break;

  case 13:
#line 161 "compiler_hw3.y"
                { fprintf(fout, "ifeq exit_while%d\n", while_num++); }
#line 1638 "y.tab.c"
    break;

  case 14:
#line 165 "compiler_hw3.y"
               {
                   fprintf(fout, "goto while_loop%d\n", while_stack[while_top]);
                   fprintf(fout, "exit_while%d:\n", while_stack[while_top--]);
               }
#line 1647 "y.tab.c"
    break;

  case 15:
#line 172 "compiler_hw3.y"
      { fprintf(fout, "for_loop%d:\n", for_num); }
#line 1653 "y.tab.c"
    break;

  case 16:
#line 176 "compiler_hw3.y"
                { fprintf(fout, "ifeq exit_for%d\n", for_num);
                  fprintf(fout, "goto for_statement%d\n", for_num);
                  fprintf(fout, "for_index_update%d:\n", for_num); }
#line 1661 "y.tab.c"
    break;

  case 17:
#line 182 "compiler_hw3.y"
             { fprintf(fout, "goto for_loop%d\n", for_num);
               fprintf(fout, "for_statement%d:\n", for_num); 
               for_stack[++for_top] = for_num++;
             }
#line 1670 "y.tab.c"
    break;

  case 18:
#line 189 "compiler_hw3.y"
               { fprintf(fout, "goto for_index_update%d\n", for_stack[for_top]);
                 fprintf(fout, "exit_for%d:\n", for_stack[for_top--]); }
#line 1677 "y.tab.c"
    break;

  case 21:
#line 200 "compiler_hw3.y"
                                           { //fprintf(fout, "else%d:\n", if_stack[if_top--]);
                                             fprintf(fout, "if_end%d:\n", end_stack[end_top--]); }
#line 1684 "y.tab.c"
    break;

  case 22:
#line 202 "compiler_hw3.y"
      { //fprintf(fout, "else%d:\n", if_stack[if_top--]);
        fprintf(fout, "if_end%d:\n", end_stack[end_top--]); }
#line 1691 "y.tab.c"
    break;

  case 23:
#line 211 "compiler_hw3.y"
                { fprintf(fout, "ifeq else%d\n", if_num); 
                  if_stack[++if_top] = if_num++;
                  end_stack[++end_top] = end_num++;
                }
#line 1700 "y.tab.c"
    break;

  case 24:
#line 218 "compiler_hw3.y"
                { fprintf(fout, "ifeq else%d\n", if_num); 
                  if_stack[++if_top] = if_num++;
                }
#line 1708 "y.tab.c"
    break;

  case 25:
#line 224 "compiler_hw3.y"
               { fprintf(fout, "goto if_end%d\n", end_stack[end_top]); 
                 fprintf(fout, "else%d:\n", if_stack[if_top--]);
               }
#line 1716 "y.tab.c"
    break;

  case 26:
#line 230 "compiler_hw3.y"
               { fprintf(fout, "goto if_end%d\n", end_stack[end_top]);
                 fprintf(fout, "else%d:\n", if_stack[if_top--]); }
#line 1723 "y.tab.c"
    break;

  case 27:
#line 235 "compiler_hw3.y"
      { errcond = 1; }
#line 1729 "y.tab.c"
    break;

  case 28:
#line 239 "compiler_hw3.y"
          { create_symbol(); }
#line 1735 "y.tab.c"
    break;

  case 29:
#line 243 "compiler_hw3.y"
          { dump_symbol(); }
#line 1741 "y.tab.c"
    break;

  case 34:
#line 255 "compiler_hw3.y"
                         {  if(declare)
                            {   
                                if(type[0] == 's')
                                    fprintf(fout, "astore %d\n", addr);
                                else if(type[0] == 'b')
                                    fprintf(fout, "istore %d\n", addr);
                                else
                                    fprintf(fout, "%cstore %d\n", type[0], addr);
                                insert_symbol(id, 0);
                                printf("> Insert {%s} into symbol table (scope level: %d)\n", id, scope_level);
                                declare = 0;
                            }
                         }
#line 1759 "y.tab.c"
    break;

  case 35:
#line 268 "compiler_hw3.y"
                                     { if(declare)
                                   {   
                                        fprintf(fout, "newarray %s\n", type);
                                        fprintf(fout, "astore %d\n", addr);
                                        insert_symbol(id, 1);
                                        printf("> Insert {%s} into symbol table (scope level: %d)\n", id, scope_level);
                                        declare = 0;
                                   }
                                 }
#line 1773 "y.tab.c"
    break;

  case 36:
#line 280 "compiler_hw3.y"
               { /*$1 = $$;*/
                 declare = 1; }
#line 1780 "y.tab.c"
    break;

  case 37:
#line 285 "compiler_hw3.y"
          { strcpy(type, "int"); if(ctype == 'a') ctype ='i'; }
#line 1786 "y.tab.c"
    break;

  case 38:
#line 286 "compiler_hw3.y"
            { strcpy(type, "float"); if(ctype == 'a') ctype = 'f'; }
#line 1792 "y.tab.c"
    break;

  case 39:
#line 287 "compiler_hw3.y"
             { strcpy(type, "string"); }
#line 1798 "y.tab.c"
    break;

  case 40:
#line 288 "compiler_hw3.y"
           { strcpy(type, "bool"); }
#line 1804 "y.tab.c"
    break;

  case 41:
#line 292 "compiler_hw3.y"
            { strcpy(id, (yyval.s_val));
              int array_tmp = isArray;
              if(!declare)
              {
                  int ad = lookup_symbol((yyval.s_val));
                  if(ad != -1 && !isArray)
                  {
                      if(load_type == 's')
                          fprintf(fout, "aload %d\n", ad);
                      else if(load_type == 'b')
                          fprintf(fout, "iload %d\n", ad);
                      else
                          fprintf(fout, "%cload %d\n", load_type, ad);
                      // load_type = '\0';
                      printf("IDENT (name=%s, address=%d)\n", (yyval.s_val), ad);
                  }
                  else if(isArray)
                      fprintf(fout, "aload %d\n", ad);
                  onearith_addr = ad;
                  rhs_ad = ad; 
                  if(!asgn)
                      assign_ad = ad;
              }
              int k;
              for(k = top; k >= 0; k--)
              {
                  table *t = tb_stack[k];
                  int i;
                  for(i = 0; i <= t -> top; i++)
                      if(strcmp(t -> stack[i] -> id_name, (yyval.s_val)) == 0)
                      {
                          if(k == top && declare)
                          {
                              printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, (yyval.s_val), t -> stack[i] -> line);
                              declare = 0;
                              break;
                          }
                          if(t -> stack[i] -> arr)
                              parr = 1;
                          strcpy(printype, t -> stack[i] -> type);
                          if(ctype)
                          {
                              if(!isArray)
                                  fprintf(fout, "%c2%c\n", t -> stack[i] -> type[0], ctype);
                              printf("%c to %c\n", t -> stack[i] -> type[0] - 32, ctype - 32);
                              exprs -> nstk[exprs -> top + 1] = ctype;
                          }
                          else
                              exprs -> nstk[exprs -> top + 1] = t -> stack[i] -> type[0];
                          index_cast = ctype;
                          ctype = '\0';
                          break;
                      }
                  if(i < t -> top + 1)
                  break;
              }
              if(k < 0 && !declare)
              {
                  printf("error:%d: undefined: %s\n", yylineno, (yyval.s_val));
                  deferr = 1;
              }
              if(rhs)
                  strcpy(errlhs, "");
              if(asgn)
                  isArray = array_tmp;
            }
#line 1875 "y.tab.c"
    break;

  case 42:
#line 361 "compiler_hw3.y"
                  {}
#line 1881 "y.tab.c"
    break;

  case 43:
#line 362 "compiler_hw3.y"
                  { strcpy(printype, "bool"); }
#line 1887 "y.tab.c"
    break;

  case 44:
#line 363 "compiler_hw3.y"
      { switch(type[0])
        {
            case 'i':
                fprintf(fout, "ldc 0\n");
                break;
            case 'f':
                fprintf(fout, "ldc 0.0\n");
                break;
            case 's':
                fprintf(fout, "ldc \"\"\n");
                break;
        }
      }
#line 1905 "y.tab.c"
    break;

  case 45:
#line 379 "compiler_hw3.y"
              {
        printf("INT_LIT %d\n", (yyval.i_val));
        fprintf(fout, "ldc %d\n", (yyval.i_val));
        if(!parr)
            strcpy(printype, "int");
        if(ctype)
        {
            fprintf(fout, "i2%c\n", ctype);
            printf("I to %c\n", ctype - 32);
            exprs -> nstk[exprs -> top + 1] = ctype;
        }
        else
            exprs -> nstk[exprs -> top + 1] = 'i';
        ctype = '\0';
        if(rhs)
            strcpy(errlhs, "int");
    }
#line 1927 "y.tab.c"
    break;

  case 46:
#line 396 "compiler_hw3.y"
                {
        printf("FLOAT_LIT %f\n", (yyval.f_val));
        fprintf(fout, "ldc %f\n", (yyval.f_val));
        strcpy(printype, "float");
        if(ctype)
        {
            fprintf(fout, "f2%c\n", ctype);
            printf("F to %c\n", ctype - 32);
            exprs -> nstk[exprs -> top + 1] = ctype;
        }
        else
            exprs -> nstk[exprs -> top + 1] = 'f';
        ctype = '\0';
        if(rhs)
            strcpy(errlhs, "float");
    }
#line 1948 "y.tab.c"
    break;

  case 47:
#line 412 "compiler_hw3.y"
                  { strcpy(printype, "string"); exprs -> nstk[exprs -> top + 1] = 's'; if(rhs) strcpy(errlhs, "string"); }
#line 1954 "y.tab.c"
    break;

  case 48:
#line 417 "compiler_hw3.y"
                 { printf("STRING_LIT %s\n", (yyval.s_val)); 
                    /*
                   char str[100];
                   strcpy(str, $<s_val>$);
                   if(str[strlen(str) - 2] == '\\' && str[strlen(str) - 1] == 'n')
                       str[strlen(str) - 2] = '\0';
                    printf("str: %s", str);
                    */
                   fprintf(fout, "ldc \"%s\"\n", (yyval.s_val));
                 }
#line 1969 "y.tab.c"
    break;

  case 51:
#line 435 "compiler_hw3.y"
      {  while(exprs -> top > -1) 
         {
             int k = exprs -> top;
             type_validation(exprs -> stk[k], exprs -> nstk[k], exprs -> nstk[k + 1]);
             print_optr(exprs -> nstk[k], exprs -> stk[exprs -> top--]); 
         }

        if(errcond)
                printf("error:%d: non-bool (type %s) used as for condition\n", yylineno + 1, ret_type(exprs -> nstk[0]));
        errcond = 0;
        if(!rhs)
            printf("error:%d: cannot assign to %s\n", yylineno, errlhs);
        rhs = 1;
      }
#line 1988 "y.tab.c"
    break;

  case 52:
#line 452 "compiler_hw3.y"
         { precedence('|'); strcpy(printype, "bool"); }
#line 1994 "y.tab.c"
    break;

  case 53:
#line 456 "compiler_hw3.y"
                                       { print_assign(); }
#line 2000 "y.tab.c"
    break;

  case 55:
#line 461 "compiler_hw3.y"
          { asgn = exprs -> nstk[0]; assign_optr = "ASSIGN\n"; }
#line 2006 "y.tab.c"
    break;

  case 56:
#line 462 "compiler_hw3.y"
                 { asgn = exprs -> nstk[0]; assign_optr = "ADD_ASSIGN\n"; 
                   fprintf(fout, "%cload %d\n", asgn, assign_ad);
                 }
#line 2014 "y.tab.c"
    break;

  case 57:
#line 465 "compiler_hw3.y"
                 { asgn = exprs -> nstk[0]; assign_optr = "SUB_ASSIGN\n"; 
                   fprintf(fout, "%cload %d\n", asgn, assign_ad);
                 }
#line 2022 "y.tab.c"
    break;

  case 58:
#line 468 "compiler_hw3.y"
                 { asgn = exprs -> nstk[0]; assign_optr = "MUL_ASSIGN\n"; 
                   fprintf(fout, "%cload %d\n", asgn, assign_ad);
                 }
#line 2030 "y.tab.c"
    break;

  case 59:
#line 471 "compiler_hw3.y"
                 { asgn = exprs -> nstk[0]; assign_optr = "QUO_ASSIGN\n"; 
                   fprintf(fout, "%cload %d\n", asgn, assign_ad);
                 }
#line 2038 "y.tab.c"
    break;

  case 60:
#line 474 "compiler_hw3.y"
                 { asgn = exprs -> nstk[0]; assign_optr = "REM_ASSIGN\n"; 
                   fprintf(fout, "%cload %d\n", asgn, assign_ad);
                 }
#line 2046 "y.tab.c"
    break;

  case 61:
#line 480 "compiler_hw3.y"
      { if(strcmp(errlhs, ""))
            rhs = 0;
      }
#line 2054 "y.tab.c"
    break;

  case 64:
#line 491 "compiler_hw3.y"
          { precedence('&'); strcpy(printype, "bool"); }
#line 2060 "y.tab.c"
    break;

  case 67:
#line 500 "compiler_hw3.y"
          { precedence('<'); }
#line 2066 "y.tab.c"
    break;

  case 68:
#line 501 "compiler_hw3.y"
          { precedence('>'); }
#line 2072 "y.tab.c"
    break;

  case 69:
#line 502 "compiler_hw3.y"
                { precedence('a'); }
#line 2078 "y.tab.c"
    break;

  case 70:
#line 503 "compiler_hw3.y"
              { precedence('b'); }
#line 2084 "y.tab.c"
    break;

  case 71:
#line 504 "compiler_hw3.y"
            { precedence('c'); }
#line 2090 "y.tab.c"
    break;

  case 72:
#line 505 "compiler_hw3.y"
                { precedence('d'); }
#line 2096 "y.tab.c"
    break;

  case 75:
#line 514 "compiler_hw3.y"
          { precedence('+'); }
#line 2102 "y.tab.c"
    break;

  case 76:
#line 515 "compiler_hw3.y"
          { precedence('-'); }
#line 2108 "y.tab.c"
    break;

  case 79:
#line 524 "compiler_hw3.y"
          { precedence('*'); }
#line 2114 "y.tab.c"
    break;

  case 80:
#line 525 "compiler_hw3.y"
          { precedence('/'); }
#line 2120 "y.tab.c"
    break;

  case 81:
#line 526 "compiler_hw3.y"
          { precedence('%'); }
#line 2126 "y.tab.c"
    break;

  case 82:
#line 530 "compiler_hw3.y"
                   { printf("%s", sign); strcpy(sign, ""); 
                     while(sign_num)
                     {
                        fprintf(fout, "%cneg\n", exprs -> nstk[exprs -> top + 1]);
                        sign_num--;
                     }
                   }
#line 2138 "y.tab.c"
    break;

  case 83:
#line 537 "compiler_hw3.y"
                      { printf("%s", sign); 
                        strcpy(sign, ""); 
                        strcpy(printype, "bool");
                        while(reverse_num)
                        {
                            fprintf(fout, "iconst_1\n");
                            fprintf(fout, "ixor\n");
                            reverse_num--;
                        }
                      }
#line 2153 "y.tab.c"
    break;

  case 84:
#line 550 "compiler_hw3.y"
                  { char s[100] = "POS\n";
                    strcat(s, sign);
                    strcpy(sign, s);
                  }
#line 2162 "y.tab.c"
    break;

  case 85:
#line 554 "compiler_hw3.y"
                  { char s[100] = "NEG\n";
                    strcat(s, sign);
                    strcpy(sign, s);
                    sign_num++;
                  }
#line 2172 "y.tab.c"
    break;

  case 87:
#line 563 "compiler_hw3.y"
                  { char s[100] = "NOT\n";
                    strcat(s, sign);
                    strcpy(sign, s);
                    reverse_num++;
                  }
#line 2182 "y.tab.c"
    break;

  case 90:
#line 573 "compiler_hw3.y"
                { incdec_codegen(1, 0); }
#line 2188 "y.tab.c"
    break;

  case 91:
#line 574 "compiler_hw3.y"
                { incdec_codegen(0, 0); }
#line 2194 "y.tab.c"
    break;

  case 92:
#line 575 "compiler_hw3.y"
                { incdec_codegen(1, 1); }
#line 2200 "y.tab.c"
    break;

  case 93:
#line 576 "compiler_hw3.y"
                { incdec_codegen(0, 1); }
#line 2206 "y.tab.c"
    break;

  case 96:
#line 579 "compiler_hw3.y"
                                { if(asgn || load_array) 
                                      fprintf(fout, "%caload\n", load_type); 
                                      // fprintf(fout, "%caload %d\n", load_type, rhs_ad); 
                                }
#line 2215 "y.tab.c"
    break;

  case 99:
#line 585 "compiler_hw3.y"
                                                       {
                                                           if(load_array)
                                                               fprintf(fout, "%caload\n", load_type);
                                                           fprintf(fout, "%c2%c\n", load_type, index_cast);
                                                           index_cast = '\0';
                                                       }
#line 2226 "y.tab.c"
    break;

  case 100:
#line 594 "compiler_hw3.y"
          { ctype = 'a'; }
#line 2232 "y.tab.c"
    break;

  case 101:
#line 605 "compiler_hw3.y"
           { printf("TRUE\n"); 
             fprintf(fout, "iconst_1\n");
             exprs -> nstk[exprs -> top + 1] = 'b';
           }
#line 2241 "y.tab.c"
    break;

  case 102:
#line 609 "compiler_hw3.y"
            { printf("FALSE\n"); 
              fprintf(fout, "iconst_0\n");
              exprs -> nstk[exprs -> top + 1] = 'b';
            }
#line 2250 "y.tab.c"
    break;

  case 103:
#line 616 "compiler_hw3.y"
                                       {
                                  if(exprs -> nstk[exprs -> top + 1] == 's')
                                  {
                                      fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                      fprintf(fout, "swap\n");
                                      fprintf(fout, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                  }
                                  else if(exprs -> nstk[exprs -> top + 1] == 'b')
                                  {
                                      fprintf(fout, "ifeq FALSE_%d\n", printbool_num);
                                      fprintf(fout, "TRUE_%d:\n", printbool_num);
                                      fprintf(fout, "ldc \"true\"\n");
                                      fprintf(fout, "goto exit_printbool%d\n", printbool_num);
                                      fprintf(fout, "FALSE_%d:\n", printbool_num);
                                      fprintf(fout, "ldc \"false\"\n");
                                      fprintf(fout, "exit_printbool%d:\n", printbool_num);
                                      fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                      fprintf(fout, "swap\n");
                                      fprintf(fout, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                      printbool_num++;
                                  }
                                  else
                                  {
                                      fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                      fprintf(fout, "swap\n");
                                      fprintf(fout, "invokevirtual java/io/PrintStream/print(%c)V\n", exprs -> nstk[exprs -> top + 1] - 32);
                                  }
                                  printf("PRINT %s\n", printype); parr = 0; 
                                }
#line 2284 "y.tab.c"
    break;

  case 104:
#line 648 "compiler_hw3.y"
          { load_array = 1; }
#line 2290 "y.tab.c"
    break;

  case 105:
#line 652 "compiler_hw3.y"
          { while(exprs -> top > -1)                                                      
            {
                 print_optr(exprs -> nstk[exprs -> top], exprs -> stk[exprs -> top]); 
                 exprs -> top--;
            }
            load_array = 0;
          }
#line 2302 "y.tab.c"
    break;

  case 106:
#line 662 "compiler_hw3.y"
          { new_expr(); }
#line 2308 "y.tab.c"
    break;

  case 107:
#line 666 "compiler_hw3.y"
          { estack * p = exprs;
          exprs = exprs -> next;
          while(p -> top > -1) 
          {
              print_optr(p -> nstk[p -> top], p -> stk[p -> top]);
              p -> top--;
          }
              free(p); 
            if(rhs)
                strcpy(errlhs, ""); 
          }
#line 2324 "y.tab.c"
    break;

  case 108:
#line 680 "compiler_hw3.y"
          { new_expr(); }
#line 2330 "y.tab.c"
    break;

  case 109:
#line 683 "compiler_hw3.y"
          { estack * p = exprs;
          exprs = exprs -> next;
          while(p -> top > -1) 
          {
              int k = p -> top;
              type_validation(p -> stk[k], p -> nstk[k], p -> nstk[k + 1]);
              print_optr(p -> nstk[p -> top], p -> stk[p -> top]);
              p -> top--;
          }
          exprs -> nstk[exprs -> top + 1] = p -> nstk[0];
          free(p); 
          }
#line 2347 "y.tab.c"
    break;


#line 2351 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 697 "compiler_hw3.y"


/* C code section */
static void create_symbol(/* ... */)
{
    tb_stack[++top] = (table *)malloc(sizeof(table));
    tb_stack[top] -> scope_level = ++scope_level;
    tb_stack[top] -> top = -1;
}

static void insert_symbol(char *id, int arr)
{
    int t = ++tb_stack[top] -> top;
    tb_stack[top] -> stack[t] = (entry *)malloc(sizeof(entry));
    tb_stack[top] -> stack[t] -> addr = addr;
    tb_stack[top] -> stack[t] -> line = yylineno;
    tb_stack[top] -> stack[t] -> arr = arr;
    strcpy(tb_stack[top] -> stack[t] -> id_name, id);
    strcpy(tb_stack[top] -> stack[t] -> type, type);
    addr++;
}

static int lookup_symbol(char *id)
{
    for(int i = top; i >= 0; i--)
        for(int j = 0; j <= tb_stack[i] -> top; j++)
            if(!strcmp(tb_stack[i] -> stack[j] -> id_name, id))
            {
                load_type = tb_stack[i] -> stack[j] -> type[0];
                isArray = tb_stack[i] -> stack[j] -> arr;
                return tb_stack[i] -> stack[j] -> addr;
            }
    return -1;
}

static void dump_symbol(/* ... */)
{
    printf("> Dump symbol table (scope level: %d)\n", scope_level--);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n", "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(int i = 0; i <= tb_stack[top] -> top; i++)
    {
        entry *e = tb_stack[top] -> stack[i];
        if(!e -> arr)
            printf("%-10d%-10s%-10s%-10d%-10d%s\n", i, e -> id_name, e -> type, e -> addr, e -> line, "-");
        else
            printf("%-10d%-10s%-10s%-10d%-10d%s\n", i, e -> id_name, "array", e -> addr, e -> line, e -> type);
        free(e);
    }
    free(tb_stack[top]);
    top--;
}

char *ret_type(char c)
{
    switch(c)
    {
        case 'i':
            return "int";
        case 'f':
            return "float";
        case 'b':
            return "bool";
    }
    return NULL;
}

void type_validation(char op, char fst, char snd)
{
    char tp1[6], tp2[6];
    strcpy(tp1, ret_type(fst));
    strcpy(tp2, ret_type(snd));

    if(op == '%')
    {
        if(fst != 'i')
            printf("error:%d: invalid operation: (operator REM not defined on %s)\n", yylineno, tp1);
        else if(snd != 'i')
            printf("error:%d: invalid operation: (operator REM not defined on %s)\n", yylineno, tp2);
    }
    else if(op == '|' || op == '&')
    {
        char s[10];
        if(op == '|')
            strcpy(s, "OR");
        else if(op == '&')
            strcpy(s, "AND");
        if(fst != 'b')
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", yylineno, s, tp1);
        else if(snd != 'b')
            printf("error:%d: invalid operation: (operator %s not defined on %s)\n", yylineno, s, tp2);
    }
    else if(fst != snd)
    {
        char s[10];
        switch(op)
        {
            case '+':
                strcpy(s, "ADD");
                break;
            case '-':
                strcpy(s, "SUB");
                break;
            case '*':
                strcpy(s, "MUL");
                break;
            case '/':
                strcpy(s, "QUO");
                break;
            case '=':
                strcpy(s, "ASSIGN");
                break;
        }
        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, s, tp1, tp2);
    }
    else if(op == '<' || op == '>' || op == 'a' || op == 'b' || op == 'c' || op == 'd')
    {
        if(exprs -> nstk[exprs -> top] == 'i')
            fprintf(fout, "isub\n");
        else if(exprs -> nstk[exprs -> top] == 'f')
            fprintf(fout, "fcmpl\n");
        exprs -> nstk[exprs -> top] = 'b';
    }
}

void new_expr()
{
    estack *p = (estack *)malloc(sizeof(estack));
    memset(p -> stk, '\0', 100);
    memset(p -> nstk, '\0', 100);
    p -> top = -1;
    p -> next = exprs;
    exprs = p;
}


void precedence(char c)
{
    if(exprs -> top != -1)
    {
        int ci, i;
        for(int i = 0; i < 13; i++)
            if(c == ptable[0][i])
            {
                ci = ptable[1][i];
                break;
            }
        for(i = 12; ptable[1][i] >= ci; i--)
            if(exprs -> top > -1 && exprs -> stk[exprs -> top] == ptable[0][i])
            {
                int k = exprs -> top;
                type_validation(exprs -> stk[k], exprs -> nstk[k], exprs -> nstk[k + 1]);
                print_optr(exprs -> nstk[k], exprs -> stk[exprs -> top--]);
                i = 12;
            }
    }
    exprs -> stk[++exprs -> top] = c;
}

void print_optr(char optr_type, char optr)
{
    switch(optr)
    {
        case '|':
            fprintf(fout, "ior\n");
            printf("OR\n");
            break;
        case '&':
            fprintf(fout, "iand\n");
            printf("AND\n");
            break;
        case '<':
            fprintf(fout, "iflt L_lss%d_1\n", lss_num);
            fprintf(fout, "L_lss%d_0:\n", lss_num);
            fprintf(fout, "iconst_0\n");
            fprintf(fout, "goto exit_lss%d_cmp\n", lss_num);
            fprintf(fout, "L_lss%d_1:\n", lss_num);
            fprintf(fout, "iconst_1\n");
            fprintf(fout, "exit_lss%d_cmp:\n", lss_num);
            lss_num++;
            printf("LSS\n");
            break;
        case '>':
            fprintf(fout, "ifgt L_gtr%d_1\n", gtr_num);
            fprintf(fout, "L_gtr%d_0:\n", gtr_num);
            fprintf(fout, "iconst_0\n");
            fprintf(fout, "goto exit_gtr%d_cmp\n", gtr_num);
            fprintf(fout, "L_gtr%d_1:\n", gtr_num);
            fprintf(fout, "iconst_1\n");
            fprintf(fout, "exit_gtr%d_cmp:\n", gtr_num);
            gtr_num++;
            printf("GTR\n");
            break;
        case 'a':
            fprintf(fout, "ifle L_leq%d_1\n", leq_num);
            fprintf(fout, "L_leq%d_0:\n", leq_num);
            fprintf(fout, "iconst_0\n");
            fprintf(fout, "goto exit_leq%d_cmp\n", leq_num);
            fprintf(fout, "L_leq%d_1:\n", leq_num);
            fprintf(fout, "iconst_1\n");
            fprintf(fout, "exit_leq%d_cmp:\n", leq_num);
            leq_num++;
            printf("LEQ\n");
            break;
        case 'b':
            printf("GEQ\n");
            break;
        case 'c':
            fprintf(fout, "ifeq L_eql%d_1\n", eql_num);
            fprintf(fout, "L_eql%d_0:\n", eql_num);
            fprintf(fout, "iconst_0\n");
            fprintf(fout, "goto exit_eql%d_cmp\n", eql_num);
            fprintf(fout, "L_eql%d_1:\n", eql_num);
            fprintf(fout, "iconst_1\n");
            fprintf(fout, "exit_eql%d_cmp:\n", eql_num);
            eql_num++;
            printf("EQL\n");
            break;
        case 'd':
            fprintf(fout, "ifne L_neq%d_1\n", neq_num);
            fprintf(fout, "L_neq%d_0:\n", neq_num);
            fprintf(fout, "iconst_0\n");
            fprintf(fout, "goto exit_neq%d_cmp\n", neq_num);
            fprintf(fout, "L_neq%d_1:\n", neq_num);
            fprintf(fout, "iconst_1\n");
            fprintf(fout, "exit_neq%d_cmp:\n", neq_num);
            neq_num++;
            printf("NEQ\n");
            break;
        case '+':
            fprintf(fout, "%cadd\n", optr_type);
            printf("ADD\n");
            break;
        case '-':
            fprintf(fout, "%csub\n", optr_type);
            printf("SUB\n");
            break;
        case '*':
            fprintf(fout, "%cmul\n", optr_type);
            printf("MUL\n");
            break;
        case '/':
            fprintf(fout, "%cdiv\n", optr_type);
            printf("QUO\n");
            break;
        case '%':
            fprintf(fout, "irem\n");
            printf("REM\n");
    }

}

void incdec_codegen(int inc, int pre)
{
    if(load_type == 'i')
        fprintf(fout, "ldc 1\n");
    else
        fprintf(fout, "ldc 1.0\n");

    if(inc)
    {
        fprintf(fout, "%cadd\n", load_type);
        printf("INC\n");
    }
    else
    {
        fprintf(fout, "%csub\n", load_type);
        printf("DEC\n");
    }
    fprintf(fout, "%cstore %d\n", load_type, onearith_addr);
    /*
    fprintf(fout, "%cload %d\n", load_type, onearith_addr);
    if(!pre)
    {
        if(load_type == 'i')
            fprintf(fout, "ldc 1\n");
        else
            fprintf(fout, "ldc 1.0\n");
        if(inc)
            fprintf(fout, "%csub\n", load_type);
        else
            fprintf(fout, "%cadd\n", load_type);
    }
    */
}

char *itostr(int num)
{
    char *str = (char *)calloc(4, sizeof(char));
    int tmp = num, div = 1000, top = -1;
    while(tmp)
    {
        if(top > -1 || tmp / div)
        {
            int cur = tmp/div;
            str[++top] = cur + 48;
            tmp -= tmp / div * div;
        }
        div /= 10;
    }
    return str;
}

void print_assign()
{ 
    if(!isArray)
    {
        if(exprs -> nstk[0] != 's' && !deferr) 
            type_validation('=', asgn, exprs -> nstk[0]);
        if(asgn == 's')
            fprintf(fout, "astore %d\n", assign_ad);
        else if(asgn == 'b')
            fprintf(fout, "istore %d\n", assign_ad);
        else
        {
            switch(assign_optr[0])
            {
                case 'A':
                    if(strcmp(assign_optr, "ADD_ASSIGN\n") == 0)
                        fprintf(fout, "%cadd\n", asgn);
                    break;
                case 'S':
                    fprintf(fout, "%csub\n", asgn);
                    break;
                case 'M':
                    fprintf(fout, "%cmul\n", asgn);
                    break;
                case 'Q':
                    fprintf(fout, "%cdiv\n", asgn);
                    break;
                case 'R':
                    fprintf(fout, "%crem\n", asgn);
                    break;
            }
            fprintf(fout, "%cstore %d\n", asgn, assign_ad);
        }
    }
    else
        fprintf(fout, "%castore\n", asgn);
     // fprintf(fout, "%castore %d\n", asgn, assign_ad);
    asgn = '\0';
    deferr = 0;
    printf("%s\n", assign_optr); 
    strcpy(errlhs, "");
    isArray = 0;
}

char *tostr(char *s)
{
    char *str = (char *)calloc(100, sizeof(char));
    strcpy(str, "\"");
    strcat(str, s);
    strcat(str, "\"");
    return str;
}

char *ftostr(float fnum)
{
    char *str = (char *)calloc(10, sizeof(char));
    int integer = fnum;
    char *istr = itostr(integer);
    strcpy(str, istr);
    strcat(str, ".");
    float remain = 10 * (fnum - integer);
    int rem = remain, top = strlen(str) - 1;
    //do { }while(remain > 0);
    for(int i = 0; i < 2; i++)
    {
        str[++top] = rem + 48;
        remain -= rem;
        remain *= 10;
        rem = remain;
    }

    return str;
}

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    codegen(".source hw3.j\n");
    codegen(".class public Main\n");
    codegen(".super java/lang/Object\n");
    codegen(".method public static main([Ljava/lang/String;)V\n");
    codegen(".limit stack 100\n");
    codegen(".limit locals 100\n");
    INDENT++;

    yyparse();

	printf("Total lines: %d\n", yylineno);

    /* Codegen end */
    codegen("return\n");
    INDENT--;
    codegen(".end method\n");
    fclose(fout);
    fclose(yyin);

    if (HAS_ERROR) {
        remove(bytecode_filename);
    }
    return 0;
}
