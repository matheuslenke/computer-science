%{
#include <stdio.h>
int yylex(void);
void yyerror(char const *s);
%}
%token EXP IF OTHER ELSE ENTER LP RP
%%
statement: ifstmt | OTHER;
ifstmt: IF LP exp RP statement end | IF LP exp RP statement ELSE statement end
exp: EXP
end: ENTER | %empty
%%
int main(void) {
    if (yyparse() == 0) printf("PARSE SUCCESSFUL!\n");
    else                printf("PARSE FAILED!\n");
    return 0;
}
