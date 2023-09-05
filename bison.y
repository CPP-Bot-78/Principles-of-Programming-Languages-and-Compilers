%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *);
extern FILE *yyin;								
extern FILE *yyout;
extern yylineno=1;
int errors;	

char* ids_memory[100];
int new_id_num=0;
%}

%token LINEAR RELATIVE TEXTVIEW IMAGEVIEW BUTTON RADIOGROUP RADIOBUTTON PROGRESSBAR 
%token WIDTH HEIGHT ID ORIENTATION TEXT TEXTCOLOR SRC PADDING CHECKBUTTON MAX PROGRESS 
%token EQUAL LEFTSYMBOL RIGHTSYMBOL ENDSYMBOL QUOTES STARTCOMMENT ENDCOMMENT POSINT STRING

%%
root_layout: linear_layout 
           | relative_layout 
           ;

must_atributes: WIDTH EQUAL QUOTES (STRING|POSINT) QUOTES
              | HEIGHT QUOTES (STRING|POSINT) QUOTES
              ;

linear_layout: LEFTSYMBOL LINEAR must_atributes
                                 [ID EQUAL QUOTES STRING QUOTES]
                                 [ORIENTATION EQUAL QUOTES STRING QUOTES] RIGHTSYMBOL
                                 (elements|linear_layout)+
                LEFTSYMBOL ENDSYMBOL LINEAR RIGHTSYMBOL
                ;

relative_layout: LEFTSYMBOL RELATIVE must_atributes
                                 [ID EQUAL QUOTES STRING QUOTES] RIGHTSYMBOL
                                 (elements|relative_layout)* //στο bison χρησιμοποιείται * αντί για {}
                 LEFTSYMBOL ENDSYMBOL RELATIVE RIGHTSYMBOL
                 ;

elements: text_view | image_view | button | radio_group | progress_bar;

text_view: LEFTSYMBOL TEXTVIEW must_atributes
           TEXT EQUAL QUOTES STRING QUOTES
           [ID EQUAL QUOTES STRING QUOTES]
           [TEXTCOLOR EQUAL QUOTES STRING QUOTES] ENDSYMBOL RIGHTSYMBOL
           ;

image_view: LEFTSYMBOL IMAGEVIEW must_atributes
            SRC EQUAL QUOTES STRING QUOTES
            [ID EQUAL QUOTES STRING QUOTES]
            [PADDING EQUAL QUOTES POSINT QUOTES] ENDSYMBOL RIGHTSYMBOL
            ;

button: LEFTSYMBOL BUTTON must_atributes
            TEXT EQUAL QUOTES STRING QUOTES
            [ID EQUAL QUOTES STRING QUOTES]
            [PADDING EQUAL QUOTES POSINT QUOTES] ENDSYMBOL RIGHTSYMBOL
            ;

radio_group: LEFTSYMBOL RADIOGROUP must_atributes
            NORADIOBUTTON EQUAL QUOTES POSINT QUOTES //ερώτημα 3
            [ID EQUAL QUOTES STRING QUOTES]
            [CHECKBUTTON EQUAL QUOTES STRING QUOTES] RIGHTSYMBOL
            radio_button
            LEFTSYMBOL RADIOGROUP ENDSYMBOL RIGHTSYMBOL
            ;

radio_button: LEFTSYMBOL RADIOBUTTON must_atributes
              TEXT EQUAL QUOTES STRING QUOTES
              [ID EQUAL QUOTES STRING QUOTES] ENDSYMBOL RIGHTSYMBOL
              ;

progress_bar: LEFTSYMBOL PROGRESSBAR must_atributes
              [ID EQUAL QUOTES STRING QUOTES]
              [MAX EQUAL QUOTES POSINT QUOTES]
              [PROGRESS EQUAL QUOTES POSINT QUOTES] ENDSYMBOL RIGHTSYMBOL
              ;

//διαφοροποίηση από αρχικό BNF - μπορεί όχι σωστό
//POSINT: POSINT*
//STRING: STRING*
//comment: STARTCOMMENT STRING ENDCOMMENT

%%
yyerror(const char *error_msg)
{   
    errors++;
    printf(stderr, "There was a syntax error in line %d: %s/n", yylineno, error_msg); //υποχρεωτική στο μεταπροόγραμμα bison, καλείται όταν συνακτικό σφάλμα
}
int main(int argc, char **argv){
	argv++;
	argc--;
	errors=0;  
	
    if(argc>0)
		yyin=fopen(argv[0], "r");
        if (!yyin){
            perror("The file could not be opened");
            return 1;
        }
	else
		yyin=stdin;	
	
    yyparse();
	
	if(errors==0) {
	     printf("Program Compiled Succesfully\n"); 
    }
    else {
        printf("%d syntax errors have occured\n", errors);
    }
	  
	return 0;
}			

//{printf("Successful Parsing! The code you wrote is in the correct form\n");}