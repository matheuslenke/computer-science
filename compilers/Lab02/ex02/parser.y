%define parse.error verbose // Give proper messages when a syntax error is found.
%define parse.lac full      // Enable LAC to improve syntax error handling.


%{
#include <stdio.h>
int yylex(void);
void yyerror(char const *s);
int sum = 0;
int op = 0;
void sum_number_global(int number) {
    if(op == 0) {
        sum = sum + number;
    } else if (op == 1) {
        sum = sum - number;
    } else if (op == 2) {
        sum = sum * number;
    } else if (op == 3) {
        sum = sum / number;
    }
}
void set_operator(int number) {
    op = number;
}
%}

%token NUMBER PLUS MINUS TIMES DIVISION LEFT_PARENTHESIS RIGHT_PARENTHESIS ENTER
%left PLUS MINUS    // Ops associativos a esquerda.
%left TIMES DIVISION    // Mais para baixo, maior precedencia.

%%
line: expr ENTER ;
expr: expr operator expr | LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  | NUMBER { sum_number_global($1); }  | %empty  ;
operator: PLUS { set_operator(0); } | MINUS { set_operator(1); } | TIMES { set_operator(2); } | DIVISION { set_operator(3); }
%%


int main(void) {
    if (yyparse() == 0) printf("PARSE SUCCESSFUL! Result = %d\n", sum);
    else                printf("PARSE FAILED!\n");
    return 0;
}
