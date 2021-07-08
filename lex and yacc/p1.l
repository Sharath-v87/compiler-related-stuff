%{
    #include <stdlib.h>
    #include<stdlib.h>
    #include "y.tab.h"
    void yyerror (char *);
    extern int yylval;
%}
%%
START     return START;
END       return END;
print     return PRINT;
[a-zA-Z]       {
                yylval = *yytext - 'a';
                return VARIABLE;
            }

    /* integers */
[0-9]+      {
                yylval = atoi(yytext);
                return NUMBER;
            }
[-+()=/*\n] {return *yytext;}
[ \t]         ;
yyerror("invalid expression");
%%
int yywrap(void) {
    return 1;
}
           