%{#include<stdio.h>
   void yyerror(char *);
   int yylex(void);
   int sym[26];
%}
%token START END VARIABLE NUMBER
%left '+' '-'
%left '*' '/'
%left '(' ')'
%%
program:
         program statement '\n'
         |
         ;

Arithmeticexp: 
            E         {printf("%d\n", $1);}
            | VARIABLE '=' E {sym[$1]=$3;}
            ;
E:
            NUMBER
            | VARIABLE    {$$ = sym[$1];}
            | E '+' E     {$$ = $1+$3;}
            | E '-' E     {$$ = $1-$3;}
            | E '*' E     {$$ = $1*$3;}
            | E '/' E     {$$ = $1/$3;}
            | '(' E ')'   {$$ = $2;}
            ;
%%

void yyerror(char *s) {
   fprintf(stderr, "%s\n", s);
}
int main(void) {
   yyparse();
   return 0;
}
  