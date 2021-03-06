%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput

%{
#include "parser.h" // For the token types from bison.
%}

%%

[0-9]+  { yylval = atoi(yytext); return NUMBER; }
"+"     { return PLUS; }
"-"     { return MINUS; }
"*"     { return TIMES; }
"/"     { return DIVISION; }
"("     { return LEFT_PARENTHESIS; }
")"     { return RIGHT_PARENTHESIS; }
"\n"    { return ENTER; }
<<EOF>> { return EOF; }
" "     { /* ignore spaces */ }
.       { printf("LEXICAL ERROR: Unknown symbol %s\n", yytext);
          exit(EXIT_FAILURE); }
