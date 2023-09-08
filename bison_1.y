%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *);
extern FILE *yyin;								
extern FILE *yyout;
extern int yylineno;//extern yylineno=1;
extern int new_line;
int errors;	

char* ids_memory[100];
int num_of_ids=0;

char* radio_button_ids_memory[100];
int num_of_radio_button_ids=0;

int max_value;
%}

%token LINEAR RELATIVE TEXTVIEW IMAGEVIEW BUTTON RADIOGROUP RADIOBUTTON PROGRESSBAR 
%token WIDTH HEIGHT ID ORIENTATION TEXT TEXTCOLOR SRC PADDING CHECKBUTTON MAX PROGRESS 
%token EQUAL LEFTSYMBOL RIGHTSYMBOL ENDSYMBOL QUOTES STARTCOMMENT ENDCOMMENT POSINT STRING
%token NORADIOBUTTON COMMENT_CHAR
%start root_layout

%%
root_layout: linear_layout
           | relative_layout 
           ;

must_atributes: WIDTH EQUAL QUOTES must_atributes_values QUOTES
                HEIGHT EQUAL QUOTES must_atributes_values QUOTES
              ;

must_atributes_values: STRING | POSINT ;

linear_layout: LEFTSYMBOL LINEAR must_atributes
                                 id_feature
                                 orientation_feature RIGHTSYMBOL
                                 linear_elements_one_or_more
                LEFTSYMBOL ENDSYMBOL LINEAR RIGHTSYMBOL
             |  LEFTSYMBOL LINEAR must_atributes
                                 id_feature
                                 orientation_feature RIGHTSYMBOL
                                 linear_layout_one_or_more
                LEFTSYMBOL ENDSYMBOL LINEAR RIGHTSYMBOL
                ;

relative_layout: LEFTSYMBOL RELATIVE must_atributes
                                 id_feature RIGHTSYMBOL
                                 elements_null_or_more
                 LEFTSYMBOL ENDSYMBOL RELATIVE RIGHTSYMBOL
               | LEFTSYMBOL RELATIVE must_atributes
                                 id_feature RIGHTSYMBOL
                                 relative_layout_null_or_more 
                 LEFTSYMBOL ENDSYMBOL RELATIVE RIGHTSYMBOL
                 ;

elements: text_view | image_view | button | radio_group | progress_bar;
linear_elements: text_view | image_view | button | radio_group | progress_bar |relative_layout;

text_view: LEFTSYMBOL TEXTVIEW must_atributes
           id_feature
           TEXT EQUAL QUOTES STRING QUOTES
           textcolor_feature ENDSYMBOL RIGHTSYMBOL
           ;

image_view: LEFTSYMBOL IMAGEVIEW must_atributes
            SRC EQUAL QUOTES STRING QUOTES
            id_feature
            padding_feature ENDSYMBOL RIGHTSYMBOL
            ;

button: LEFTSYMBOL BUTTON must_atributes
            TEXT EQUAL QUOTES STRING QUOTES
            id_feature
            padding_feature ENDSYMBOL RIGHTSYMBOL
            ;

radio_group: LEFTSYMBOL RADIOGROUP must_atributes
            id_feature
            checkbutton_feature RIGHTSYMBOL
            radio_button_one_or_more
            LEFTSYMBOL ENDSYMBOL RADIOGROUP RIGHTSYMBOL
            ;

radio_button: LEFTSYMBOL RADIOBUTTON must_atributes
              radio_button_id_feature
              TEXT EQUAL QUOTES STRING QUOTES
              ENDSYMBOL RIGHTSYMBOL
              ;

progress_bar: LEFTSYMBOL PROGRESSBAR must_atributes
              id_feature
              max_feature
              progress_feature ENDSYMBOL RIGHTSYMBOL
              ;

comment: STARTCOMMENT comment_string ENDCOMMENT ;
//_____________________________________________________________________________
//ορισμός κανώνων προαιρετικών στοιχείων
id_feature: /*empty*/ | ID EQUAL QUOTES STRING QUOTES;

radio_button_id_feature: /*empty*/ | ID EQUAL QUOTES STRING QUOTES;

orientation_feature: /*empty*/ | ORIENTATION EQUAL QUOTES STRING QUOTES ;

textcolor_feature: /*empty*/ | TEXTCOLOR EQUAL QUOTES STRING QUOTES;

padding_feature: /*empty*/ | PADDING EQUAL QUOTES POSINT QUOTES;

checkbutton_feature: /*empty*/ | CHECKBUTTON EQUAL QUOTES STRING QUOTES;

max_feature: /*empty*/ | MAX EQUAL QUOTES POSINT QUOTES;

progress_feature: /*empty*/ | PROGRESS EQUAL QUOTES POSINT QUOTES;
//_____________________________________________________________________________
//ορισμός κανώνων για στοιχεία που μπορούν να εμφανιστούν 0 ή πολλαπλές φορές
elements_null_or_more: /*empty*/ | elements_null_or_more  elements | elements ;
relative_layout_null_or_more: /*empty*/ | relative_layout_null_or_more relative_layout | relative_layout ;
comment_string:  /*empty*/| comment_string COMMENT_CHAR | comment_string ;
//______________________________________________________________________________
//ορισμός κανώνων για στοιχεία που πρέπει να εμφανιστούν 1 ή περισσότερες φορές
elements_one_or_more: elements | elements_one_or_more elements;
linear_elements_one_or_more: linear_elements | linear_elements_one_or_more linear_elements;
linear_layout_one_or_more: linear_layout_one_or_more linear_layout | linear_layout;
radio_button_one_or_more: radio_button_one_or_more radio_button | radio_button;

%%
yyerror(const char *error_msg)
{   
    errors++;
    fprintf(stderr, "There was a syntax error in line %d: %s\n", new_line, error_msg); //υποχρεωτική συνάρτηση στο μεταπροόγραμμα bison, καλείται όταν υπάρχει συνακτικό σφάλμα
}
int main(int argc, char **argv){
	//argv++;
	//argc--;
	errors=0;  

    if(argc>1)
		yyin=fopen(argv[1], "r");
        if (!yyin){
            perror("The file could not be opened");
            return 1;
        }
    yyparse();
	
	if(errors==0) {
	     printf("Program Compiled Succesfully\n"); 
    }
    else {
        printf("\n");
        printf("%d syntax errors have occured\n", errors);
    }
	  
	return 0;
}			

//{printf("Successful Parsing! The code you wrote is in the correct form\n");}
//διαφοροποίηση από αρχικό BNF - μπορεί όχι σωστό
//POSINT: POSINT*
//STRING: STRING*
//comment: STARTCOMMENT STRING ENDCOMMENT