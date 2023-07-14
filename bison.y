%{
#include <stdio.h>
#include <stdlib.h>
%}

%token LINEAR RELATIVE TEXTVIEW IMAGEVIEW BUTTON RADIOGROUP RADIOBUTTON PROGRESSBAR 
%token WIDTH HEIGHT ID ORIENTATION TEXT TEXTCOLOR SRC PADDING CHECKBUTTON MAX PROGRESS 
%token LEFTSYMBOL RIGHTSYMBOL ENDSYMBOL QUOTES STARTCOMMENT ENDCOMMENT POSINT STRING

%%
//programm: root_layout {fprintf(yyout, "%i/n", $1;)} //δεν ξέρω αν χρειάζεται και τι κάνει το είδα από διαφάνειες
root_layout: linear_layout
           | relative_layout

must_atributes:



%%
yyerror(char *error_msg)
{
    fprintf(stderr, "%s/n", error_msg)
}
main()
{
    yyparse(); //υλοποίηση συντακτικού αναλυτή -> εκτελέι κάθε φορά την yylex() προς αναγνώριση κάποιας λεκτικής μονάδας
}