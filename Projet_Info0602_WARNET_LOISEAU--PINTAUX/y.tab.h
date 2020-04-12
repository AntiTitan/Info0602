/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    ENTIER = 258,
    VAR = 259,
    NOM = 260,
    DEBUTP = 261,
    FINP = 262,
    MAIN = 263,
    WHILE = 264,
    FINW = 265,
    IF = 266,
    ELSE = 267,
    ENDI = 268,
    PAR = 269,
    AV = 270,
    RE = 271,
    DR = 272,
    GA = 273,
    PO = 274,
    PR = 275,
    CA = 276,
    FIN = 277,
    EGAL = 278,
    DIFF = 279,
    TESTEG = 280,
    INF = 281,
    INFE = 282,
    SUP = 283,
    SUPE = 284
  };
#endif
/* Tokens.  */
#define ENTIER 258
#define VAR 259
#define NOM 260
#define DEBUTP 261
#define FINP 262
#define MAIN 263
#define WHILE 264
#define FINW 265
#define IF 266
#define ELSE 267
#define ENDI 268
#define PAR 269
#define AV 270
#define RE 271
#define DR 272
#define GA 273
#define PO 274
#define PR 275
#define CA 276
#define FIN 277
#define EGAL 278
#define DIFF 279
#define TESTEG 280
#define INF 281
#define INFE 282
#define SUP 283
#define SUPE 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
