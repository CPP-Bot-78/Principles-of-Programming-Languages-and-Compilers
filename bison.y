%{
#include <stdio.h>
#include <stdlib.h>
//voidyyerrer(char *);

%}

%token LINEAR RELATIVE TEXTVIEW IMAGEVIEW BUTTON RADIOGROUP RADIOBUTTON PROGRESSBAR 
%token WIDTH HEIGHT ID ORIENTATION TEXT TEXTCOLOR SRC PADDING CHECKBUTTON MAX PROGRESS 
%token EQUAL LEFTSYMBOL RIGHTSYMBOL ENDSYMBOL QUOTES STARTCOMMENT ENDCOMMENT POSINT STRING

%%
root_layout: linear_layout
           | relative_layout

must_atributes: WIDTH EQUAL QUOTES (string|pos_int) QUOTES
              | HEIGHT QUOTES (string|pos_int) QUOTES

linear_layout: LEFTSYMBOL LINEAR must_atributes
                                 [ID EQUAL QUOTES string QUOTES]
                                 [ORIENTATION EQUAL QUOTES string QUOTES] RIGHTSYMBOL
                                 (elements|linear_layout)+
                LEFTSYMBOL ENDSYMBOL LINEAR RIGHTSYMBOL

relative_layout: LEFTSYMBOL RELATIVE must_atributes
                                 [ID EQUAL QUOTES string QUOTES] RIGHTSYMBOL
                                 (elements|relative_layout)* //στο bison χρησιμοποιείται * αντί για {}
                 LEFTSYMBOL ENDSYMBOL RELATIVE RIGHTSYMBOL

elements: text_view | image_view | button | radio_group | progress_bar

text_view: LEFTSYMBOL TEXTVIEW must_atributes
           TEXT EQUAL QUOTES string QUOTES
           [ID EQUAL QUOTES string QUOTES]
           [TEXTCOLOR EQUAL QUOTES string QUOTES] ENDSYMBOL RIGHTSYMBOL

image_view: LEFTSYMBOL IMAGEVIEW must_atributes
            SRC EQUAL QUOTES string QUOTES
            [ID EQUAL QUOTES string QUOTES]
            [PADDING EQUAL QUOTES pos_int QUOTES] ENDSYMBOL RIGHTSYMBOL

button: LEFTSYMBOL BUTTON must_atributes
            TEXT EQUAL QUOTES string QUOTES
            [ID EQUAL QUOTES string QUOTES]
            [PADDING EQUAL QUOTES pos_int QUOTES] ENDSYMBOL RIGHTSYMBOL

radio_group: LEFTSYMBOL RADIOGROUP must_atributes
            [ID EQUAL QUOTES string QUOTES]
            [CHECKBUTTON EQUAL QUOTES string QUOTES] RIGHTSYMBOL
            radio_button
            LEFTSYMBOL RADIOGROUP ENDSYMBOL RIGHTSYMBOL

radio_button: LEFTSYMBOL RADIOBUTTON must_atributes
              TEXT EQUAL QUOTES string QUOTES
              [ID EQUAL QUOTES string QUOTES] ENDSYMBOL RIGHTSYMBOL

progress_bar: LEFTSYMBOL PROGRESSBAR must_atributes
              [ID EQUAL QUOTES string QUOTES]
              [MAX EQUAL QUOTES pos_int QUOTES]
              [PROGRESS EQUAL QUOTES pos_int QUOTES] ENDSYMBOL RIGHTSYMBOL

\\διαφοροποίηση από αρχικό BNF - μπορεί όχι σωστό
pos_int: POSINT*
string: STRING*
comment: STARTCOMMENT string ENDCOMMENT




                                 




%%
yyerror(char *error_msg)
{
    fprintf(stderr, "%s/n", error_msg) //υποχρεωτική στο μεταπροόγραμμα bison, καλείται όταν συνακτικό σφάλμα
}
int main()
{
    yyparse(); //υλοποίηση συντακτικού αναλυτή -> εκτελέι κάθε φορά την yylex() προς αναγνώριση κάποιας λεκτικής μονάδας
    return 0;
}