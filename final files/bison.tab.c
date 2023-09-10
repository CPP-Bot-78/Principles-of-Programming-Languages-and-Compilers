/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror(char *);
extern FILE *yyin;								
extern FILE *yyout;
extern char* yytext;
extern int new_line;
int errors;	

char *ids_memory[1024];
int num_of_ids=0;

char *radio_button_ids_memory[1024];
int num_of_radio_button_ids=0;
int wanted_radio_buttons=0;

int max_value;

char* checkbutton;


#line 95 "bison.tab.c"

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

#include "bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LINEAR = 3,                     /* LINEAR  */
  YYSYMBOL_RELATIVE = 4,                   /* RELATIVE  */
  YYSYMBOL_TEXTVIEW = 5,                   /* TEXTVIEW  */
  YYSYMBOL_IMAGEVIEW = 6,                  /* IMAGEVIEW  */
  YYSYMBOL_BUTTON = 7,                     /* BUTTON  */
  YYSYMBOL_RADIOGROUP = 8,                 /* RADIOGROUP  */
  YYSYMBOL_RADIOBUTTON = 9,                /* RADIOBUTTON  */
  YYSYMBOL_PROGRESSBAR = 10,               /* PROGRESSBAR  */
  YYSYMBOL_WIDTH = 11,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 12,                    /* HEIGHT  */
  YYSYMBOL_ID = 13,                        /* ID  */
  YYSYMBOL_ORIENTATION = 14,               /* ORIENTATION  */
  YYSYMBOL_TEXT = 15,                      /* TEXT  */
  YYSYMBOL_TEXTCOLOR = 16,                 /* TEXTCOLOR  */
  YYSYMBOL_SRC = 17,                       /* SRC  */
  YYSYMBOL_PADDING = 18,                   /* PADDING  */
  YYSYMBOL_CHECKBUTTON = 19,               /* CHECKBUTTON  */
  YYSYMBOL_MAX = 20,                       /* MAX  */
  YYSYMBOL_PROGRESS = 21,                  /* PROGRESS  */
  YYSYMBOL_EQUAL = 22,                     /* EQUAL  */
  YYSYMBOL_LEFTSYMBOL = 23,                /* LEFTSYMBOL  */
  YYSYMBOL_RIGHTSYMBOL = 24,               /* RIGHTSYMBOL  */
  YYSYMBOL_ENDSYMBOL = 25,                 /* ENDSYMBOL  */
  YYSYMBOL_QUOTES = 26,                    /* QUOTES  */
  YYSYMBOL_STARTCOMMENT = 27,              /* STARTCOMMENT  */
  YYSYMBOL_ENDCOMMENT = 28,                /* ENDCOMMENT  */
  YYSYMBOL_POSINT = 29,                    /* POSINT  */
  YYSYMBOL_STRING = 30,                    /* STRING  */
  YYSYMBOL_NORADIOBUTTON = 31,             /* NORADIOBUTTON  */
  YYSYMBOL_COMMENT_CHAR = 32,              /* COMMENT_CHAR  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_root_layout = 34,               /* root_layout  */
  YYSYMBOL_linear_layout = 35,             /* linear_layout  */
  YYSYMBOL_relative_layout = 36,           /* relative_layout  */
  YYSYMBOL_relative_elements = 37,         /* relative_elements  */
  YYSYMBOL_linear_elements = 38,           /* linear_elements  */
  YYSYMBOL_must_atributes = 39,            /* must_atributes  */
  YYSYMBOL_must_atributes_values = 40,     /* must_atributes_values  */
  YYSYMBOL_text_view = 41,                 /* text_view  */
  YYSYMBOL_image_view = 42,                /* image_view  */
  YYSYMBOL_button = 43,                    /* button  */
  YYSYMBOL_radio_group = 44,               /* radio_group  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_radio_button = 47,              /* radio_button  */
  YYSYMBOL_progress_bar = 48,              /* progress_bar  */
  YYSYMBOL_id_feature = 49,                /* id_feature  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_radio_button_id_feature = 51,   /* radio_button_id_feature  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_orientation_feature = 53,       /* orientation_feature  */
  YYSYMBOL_textcolor_feature = 54,         /* textcolor_feature  */
  YYSYMBOL_padding_feature = 55,           /* padding_feature  */
  YYSYMBOL_56_5 = 56,                      /* $@5  */
  YYSYMBOL_checkbutton_feature = 57,       /* checkbutton_feature  */
  YYSYMBOL_58_6 = 58,                      /* $@6  */
  YYSYMBOL_max_feature = 59,               /* max_feature  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_progress_feature = 61,          /* progress_feature  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_relative_elements_null_or_more = 63, /* relative_elements_null_or_more  */
  YYSYMBOL_linear_elements_one_or_more = 64, /* linear_elements_one_or_more  */
  YYSYMBOL_radio_button_one_or_more = 65   /* radio_button_one_or_more  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    39,    42,    49,    55,    55,    55,    55,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    58,
      63,    69,    76,    82,    88,    95,    99,    94,   121,   127,
     136,   136,   136,   147,   147,   147,   161,   161,   163,   163,
     165,   165,   165,   172,   172,   172,   175,   175,   175,   177,
     177,   177,   185,   185,   185,   189,   189,   190,   190
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LINEAR", "RELATIVE",
  "TEXTVIEW", "IMAGEVIEW", "BUTTON", "RADIOGROUP", "RADIOBUTTON",
  "PROGRESSBAR", "WIDTH", "HEIGHT", "ID", "ORIENTATION", "TEXT",
  "TEXTCOLOR", "SRC", "PADDING", "CHECKBUTTON", "MAX", "PROGRESS", "EQUAL",
  "LEFTSYMBOL", "RIGHTSYMBOL", "ENDSYMBOL", "QUOTES", "STARTCOMMENT",
  "ENDCOMMENT", "POSINT", "STRING", "NORADIOBUTTON", "COMMENT_CHAR",
  "$accept", "root_layout", "linear_layout", "relative_layout",
  "relative_elements", "linear_elements", "must_atributes",
  "must_atributes_values", "text_view", "image_view", "button",
  "radio_group", "$@1", "$@2", "radio_button", "progress_bar",
  "id_feature", "$@3", "radio_button_id_feature", "$@4",
  "orientation_feature", "textcolor_feature", "padding_feature", "$@5",
  "checkbutton_feature", "$@6", "max_feature", "$@7", "progress_feature",
  "$@8", "relative_elements_null_or_more", "linear_elements_one_or_more",
  "radio_button_one_or_more", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    25,    21,   -33,   -33,    13,    13,   -33,     4,    17,
      17,     6,    16,    33,    24,    11,    26,    28,    29,    31,
     -33,   -33,    36,    39,    45,    49,    60,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,    50,    62,   -33,    46,    53,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,    52,    13,    13,
      13,    13,    13,    12,   -33,    55,    54,    56,     0,   -33,
      17,    61,    64,    57,    17,    77,    58,   -33,   -33,    80,
      70,    65,    67,    68,    66,    69,    11,    72,    75,    73,
      74,    76,    79,    71,   -33,    78,   -33,    81,    82,    83,
      85,    84,    86,    90,   -33,    87,    92,    93,   -33,    91,
      95,    98,    97,    17,    17,    99,   -33,   100,   -33,    89,
      88,    88,    17,   101,   -33,    94,   103,   102,   105,   106,
     107,   -33,   108,   109,   112,   111,   114,   115,   110,   116,
     -33,   113,   -33,   104,   -33,   -33,   118,   119,   120,   -33,
     117,   136,   -33,   125,   -33,   123,   -33,    13,    14,   -33,
     -33,   124,    96,   143,   -33,   130,   138,   -33,   128,   133,
     132,   127,   134,   -33,   -33,   129,   135,   137,   -33,   139,
     141,   -33
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     0,     1,     0,    30,
      30,     0,     0,    36,     0,     0,     0,     0,     0,     0,
      21,    20,     0,     0,     0,     0,     0,    11,    53,     6,
       7,     8,     9,    10,     0,     0,    31,     0,     0,    18,
      17,    55,    12,    13,    14,    15,    16,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,    56,
      30,     0,     0,     0,    30,     0,     0,    32,    37,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     5,     0,     4,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,    25,     0,
       0,     0,     0,    30,    30,     0,    47,     0,    29,    38,
      40,    40,    30,     0,    50,     0,     0,     0,     0,     0,
      43,    48,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,    22,     0,    23,    24,     0,     0,     0,    41,
       0,     0,    58,     0,    39,     0,    44,     0,     0,    57,
      42,     0,    33,     0,    45,     0,     0,    26,     0,     0,
       0,     0,     0,    27,    34,     0,     0,     0,    35,     0,
       0,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -33,   -33,   158,     2,   140,    44,    -6,    22,   -16,   -14,
     -13,   -12,   -33,   -33,   -32,   -11,    -9,   -33,   -33,   -33,
     -33,   -33,    51,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    39,    27,    28,    41,     9,    22,    29,    30,
      31,    32,   105,   160,   142,    33,    13,    56,   156,   166,
      18,   116,   118,   145,   129,   151,    83,   113,    93,   122,
      34,    47,   143
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      10,    14,     4,     5,     6,    48,    49,    50,    51,    42,
      52,    43,    44,    45,    46,     1,     6,    48,    49,    50,
      51,     7,    52,   147,     8,    69,    11,    40,     5,     6,
      12,    42,    15,    43,    44,    45,    46,    65,    16,   153,
      20,    21,    60,    61,    62,    63,    64,    17,    19,    40,
      24,    70,    23,    25,    26,    74,     5,     6,    48,    49,
      50,    51,    35,    52,     6,    48,    49,    50,    51,    36,
      52,    37,    38,    53,    55,    58,    57,    66,    71,    72,
      67,    75,    68,    77,    76,    78,    82,    79,    73,    80,
      81,    59,    92,    84,   110,   111,    86,    87,    85,    88,
      89,    91,    90,   120,    94,   115,   117,    95,   100,   155,
      99,   149,    96,    97,    98,   101,   123,   102,   103,   104,
     106,   107,   108,   109,   125,   112,   128,   121,   124,   114,
     126,   127,   136,   139,   130,   131,   132,   133,   134,   135,
     137,   152,   141,   138,   140,   147,   144,   146,   148,   150,
     154,   157,   158,   159,   161,   162,   163,   164,     3,   167,
     165,   168,   119,   169,   170,   171,     0,     0,     0,     0,
       0,     0,     0,     0,    54
};

static const yytype_int16 yycheck[] =
{
       6,    10,     0,     3,     4,     5,     6,     7,     8,    25,
      10,    25,    25,    25,    25,    23,     4,     5,     6,     7,
       8,     0,    10,     9,    11,    25,    22,    25,     3,     4,
      13,    47,    26,    47,    47,    47,    47,    25,    22,    25,
      29,    30,    48,    49,    50,    51,    52,    14,    24,    47,
      22,    60,    26,    24,    23,    64,     3,     4,     5,     6,
       7,     8,    26,    10,     4,     5,     6,     7,     8,    30,
      10,    26,    23,    23,    12,    23,    30,    22,    17,    15,
      26,     4,    26,     3,    26,    15,    20,    22,    31,    22,
      22,    47,    21,    24,   103,   104,    24,    22,    76,    26,
      26,    22,    26,   112,    26,    16,    18,    26,    22,    13,
      26,   143,    30,    30,    29,    25,    22,    30,    26,    26,
      29,    26,    24,    26,    22,    26,    19,    26,    25,    29,
      25,    25,    22,    29,    26,    26,    24,    26,    24,    24,
      24,   147,    23,    30,    26,     9,    26,    30,    23,    26,
      26,     8,    22,    15,    26,    22,    24,    30,     0,    30,
      26,    26,   111,    26,    25,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    34,    35,    36,     3,     4,     0,    11,    39,
      39,    22,    13,    49,    49,    26,    22,    14,    53,    24,
      29,    30,    40,    26,    22,    24,    23,    36,    37,    41,
      42,    43,    44,    48,    63,    26,    30,    26,    23,    35,
      36,    38,    41,    42,    43,    44,    48,    64,     5,     6,
       7,     8,    10,    23,    37,    12,    50,    30,    23,    38,
      39,    39,    39,    39,    39,    25,    22,    26,    26,    25,
      49,    17,    15,    31,    49,     4,    26,     3,    15,    22,
      22,    22,    20,    59,    24,    40,    24,    22,    26,    26,
      26,    22,    21,    61,    26,    26,    30,    30,    29,    26,
      22,    25,    30,    26,    26,    45,    29,    26,    24,    26,
      49,    49,    26,    60,    29,    16,    54,    18,    55,    55,
      49,    26,    62,    22,    25,    22,    25,    25,    19,    57,
      26,    26,    24,    26,    24,    24,    22,    24,    30,    29,
      26,    23,    47,    65,    26,    56,    30,     9,    23,    47,
      26,    58,    39,    25,    26,    13,    51,     8,    22,    15,
      46,    26,    22,    24,    30,    26,    52,    30,    26,    26,
      25,    24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    35,    36,    37,    37,    37,    37,
      37,    37,    38,    38,    38,    38,    38,    38,    38,    39,
      40,    40,    41,    42,    43,    45,    46,    44,    47,    48,
      49,    50,    49,    51,    52,    51,    53,    53,    54,    54,
      55,    56,    55,    57,    58,    57,    59,    60,    59,    61,
      62,    61,    63,    63,    63,    64,    64,    65,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,    11,    10,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,    10,
       1,     1,    12,    12,    12,     0,     0,    18,    11,     8,
       0,     0,     6,     0,     0,     6,     0,     5,     0,     5,
       0,     0,     6,     0,     0,     6,     0,     0,     6,     0,
       0,     6,     0,     1,     2,     1,     2,     2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 20: /* must_atributes_values: STRING  */
#line 63 "bison.y"
                               { // αν είναι string ελέγχουμε μεσω της strcmp(0 αν είναι ίδια) αν έχει μια εκ των δύο παρακάτω τιμών, αλλιώς error
                            if (strcmp(yytext, "wrap_content") != 0 && strcmp(yytext, "match_parent") != 0) { 
                            printf("\nError line %d: Allowed android:layout_width and android:layout_height values are \"wrap_content\", \"match_parent\" or an positive integer number.", new_line);
                            exit(1);
                        }
                      }
#line 1260 "bison.tab.c"
    break;

  case 21: /* must_atributes_values: POSINT  */
#line 69 "bison.y"
                               { if (atoi(yytext) <=0) {
                            printf("\nError line %d: Allowed android:layout_width and android:layout_height values are \"wrap_content\", \"match_parent\" or an positive integer number.", new_line);
                            exit(1);
                        }
                      }
#line 1270 "bison.tab.c"
    break;

  case 25: /* $@1: %empty  */
#line 95 "bison.y"
                                             {wanted_radio_buttons=atoi(yytext);}
#line 1276 "bison.tab.c"
    break;

  case 26: /* $@2: %empty  */
#line 99 "bison.y"
                                            {
                int checkbutton_on_radio_list=0; //Ερ 2d: λογικό flag. Αν γίνει 1, τότε βρήκαμε την τιμή του checkedButton στον πινακα με τα ids των radio buttons.
                for (int j=0; j<num_of_radio_button_ids; j++){ 
                    if (strcmp(checkbutton, radio_button_ids_memory[j])==0){ //συγκρίνουμε με κάθε τιμή
                        checkbutton_on_radio_list = 1;
                    }
                }
                if(!checkbutton_on_radio_list){ // αν δεν βρεθεί τυπώνουμε error
                    fprintf(stderr, "\nError line %d: This value should match with a RadioButton Id value\n", new_line);
                    exit(1); //έξοδος από το πρόγραμμά με σφάλμα
                }
                else if (num_of_radio_button_ids != wanted_radio_buttons){ // Ερ 3. Aν ο αριθμός των radio buttons δεν ειναι αυτός του έξτρα στοιχείου τυπώνουμε error
                    fprintf(stderr, "\nError line %d: The number of radio buttons is not the same as the android:radio_button_number value\n", new_line);
                    exit(1); //έξοδος από το πρόγραμμά με σφάλμα
                }
                else { // καθαρίζουμε το checkbutton, τον πίνακα με τα id radio buttons, το πληθος αυτων των ids σε περιπτωση που ακολουθει άλλο radio group
                    checkbutton=strdup("");
                    memset(radio_button_ids_memory, '\0', sizeof(num_of_radio_button_ids));
                    num_of_radio_button_ids=0;
                }
            }
#line 1302 "bison.tab.c"
    break;

  case 31: /* $@3: %empty  */
#line 136 "bison.y"
                                               { //ερ 2a. Στην 1η επαναληψη δεν τρέχει(πληθος id =0), έπειτα ελέγχει το νέο id με τα υπόλοιπα του πίνακα
    for (int i=0; i<num_of_ids; i++) { 
        if (strcmp(ids_memory[i],yytext)==0) { //αν υπάρχει ηδη τυπώνουμε error και τερματίζει το προγραμμα
            fprintf(stderr, "\nError line %d: This Id value has been used again. Duplicated Id values cannot be accepted\n.", new_line);
            exit(1); //έξοδος από το πρόγραμμά με σφάλμα
            }
        }
        ids_memory[num_of_ids] = strdup(yytext); //αν δεν υπάρχει προστίθεται στον πίνακα 
        num_of_ids++;// αυξάνουμε το πλήθος κατά 1
}
#line 1317 "bison.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 147 "bison.y"
                                                            { //ίδιο με πάνω, προστίθεται το id και σε έναν ξεχωριστό πίνακα
    for (int i=0; i<num_of_ids; i++) {
        if (strcmp(yytext, ids_memory[i])==0) {
            fprintf(stderr, "\nError line %d: This Id value has been used again. Duplicated Id values cannot be accepted.\n", new_line);
            exit(1); //έξοδος από το πρόγραμμά με σφάλμα
            }
    }
    ids_memory[num_of_ids] = strdup(yytext);  
    radio_button_ids_memory[num_of_radio_button_ids] = strdup(yytext); 
    num_of_ids++;
    num_of_radio_button_ids++;

}
#line 1335 "bison.tab.c"
    break;

  case 41: /* $@5: %empty  */
#line 165 "bison.y"
                                                         { if (atoi(yytext) <=0) { // ερ 2c, αν padding <=0 -> error & exit
        printf("\nError line %d: Allowed android:padding values are positive integer numbers. ", new_line);
        exit(1);
            }
        }
#line 1345 "bison.tab.c"
    break;

  case 44: /* $@6: %empty  */
#line 172 "bison.y"
                                                                {checkbutton= strdup(yytext);}
#line 1351 "bison.tab.c"
    break;

  case 47: /* $@7: %empty  */
#line 175 "bison.y"
                                                 {max_value=atoi(yytext);}
#line 1357 "bison.tab.c"
    break;

  case 50: /* $@8: %empty  */
#line 177 "bison.y"
                                                           {
    if (atoi(yytext)<0 || atoi(yytext)>max_value) { 
        fprintf(stderr, "Error line %d: This is not an allowed value. The value entered should be between 0 and the max value defined"), new_line;
        exit(1); //έξοδος από το πρόγραμμά με σφάλμα
    }
}
#line 1368 "bison.tab.c"
    break;


#line 1372 "bison.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 192 "bison.y"

yyerror(const char *error_msg)
{   
    errors++;
    fprintf(stderr, "\nThere was a syntax error in line %d: %s\n", new_line, error_msg); //υποχρεωτική συνάρτηση στο μεταπροόγραμμα bison, καλείται όταν υπάρχει συνακτικό σφάλμα
}

int main(int argc, char **argv){
	errors=0;  
    FILE *jfile = fopen(argv[1], "r");
	yyin = jfile;
    if (!yyin){
            perror("\nThe file could not be opened");
            return 1;
        }
    yyparse();
	
	if(errors==0) {
	     printf("\nProgram Compiled Succesfully\n"); 
    }
    else {
        printf("\n");
        printf("%d syntax errors have occured\n", errors);
    }
	  
	return 0;
}			

