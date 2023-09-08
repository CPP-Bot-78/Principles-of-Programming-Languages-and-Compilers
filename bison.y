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

%%
root_layout: linear_layout 
           | relative_layout 
           ;

must_atributes: WIDTH EQUAL QUOTES must_atributes_values QUOTES
                HEIGHT QUOTES must_atributes_values QUOTES
              ;

must_atributes_values: STRING {
                            if (strcmp($1, "wrap_content") != 0 && strcmp($1, "match_parent") != 0) {
                            printf("Error: Allowed android:layout_width and android:layout_height values are \"wrap_content\", \"match_parent\" or an positive integer number.");
                            exit(1);
                        }
                      }
                      | POSINT { if ($1 <=0) {
                            printf("Error: Allowed android:layout_width and android:layout_height values are \"wrap_content\", \"match_parent\" or an positive integer number.");
                            exit(1);
                        }
                      }

linear_layout: LEFTSYMBOL LINEAR must_atributes
                                 id_feature
                                 orientation_feature RIGHTSYMBOL
                                 elements_one_or_more
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

text_view: LEFTSYMBOL TEXTVIEW must_atributes
           TEXT EQUAL QUOTES STRING QUOTES
           id_feature
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
            NORADIOBUTTON EQUAL QUOTES POSINT QUOTES //ερώτημα 3
            id_feature
            checkbutton_feature RIGHTSYMBOL
            radio_button
            LEFTSYMBOL RADIOGROUP ENDSYMBOL RIGHTSYMBOL
            ;

radio_button: LEFTSYMBOL RADIOBUTTON must_atributes
              TEXT EQUAL QUOTES STRING QUOTES
              radio_button_id_feature ENDSYMBOL RIGHTSYMBOL
              ;

progress_bar: LEFTSYMBOL PROGRESSBAR must_atributes
              id_feature
              max_feature
              progress_feature ENDSYMBOL RIGHTSYMBOL
              ;

comment: STARTCOMMENT comment_string ENDCOMMENT ;
//_____________________________________________________________________________
//ορισμός κανώνων προαιρετικών στοιχείων
id_feature: /*empty*/ | ID EQUAL QUOTES STRING {
    for (int i=0; i<num_of_ids; i++) {
        if (strcmp($1, ids_memory[i]==0)) {
            fprintf(stderr, "Errror: This Id value has been used again. Duplicated Id values cannot be accepted.");
            exit(1); //έξοδος από το πρόγραμμά με σφάλμα
            }
        strncpy(ids_memory[num_of_ids], $1, sizeof(ids_memory[i])); // strncpy(char1,char2,n)
        num_of_ids++;
        //$$ = $1; // Επιστροφή της τιμής για χρήση στον κώδικα //XREIAZETAI??
    }
};

radio_button_id_feature: /*empty*/ | ID EQUAL QUOTES STRING {
    for (int i=0; i<num_of_ids; i++) {
        if (strcmp($1, ids_memory[i]==0)) {
            fprintf(stderr, "Errror: This Id value has been used again. Duplicated Id values cannot be accepted.");
            exit(1); //έξοδος από το πρόγραμμά με σφάλμα
            }
        strncpy(ids_memory[num_of_ids], $1, sizeof(ids_memory[i]));
        strncpy(ids_memory[num_of_radio_button_ids], $1, sizeof(radio_button_ids_memory[i]));
        num_of_ids++;
        num_of_radio_button_ids++;
        //$$ = $1; // Επιστροφή της τιμής για χρήση στον κώδικα //XREIAZETAI??
    }
} QUOTES;

orientation_feature: /*empty*/ | ORIENTATION EQUAL QUOTES STRING QUOTES ;

textcolor_feature: /*empty*/ | TEXTCOLOR EQUAL QUOTES STRING QUOTES;

padding_feature: /*empty*/ | PADDING EQUAL QUOTES POSINT { if ($1 <=0) {
        printf("Error: Allowed android:layout_width and android:layout_height values are \"wrap_content\", \"match_parent\" or an positive integer number.");
        exit(1);
            }
        }  QUOTES;

checkbutton_feature: /*empty*/ | CHECKBUTTON EQUAL QUOTES STRING {
    for (int i=0; i<num_of_radio_button_ids; i++) {
        if (strcmp($1, radio_button_ids_memory[i]==0)) {
            fprintf(stderr, "Errror: This value should much with a RadioButton Id value");
            exit(1); //έξοδος από το πρόγραμμά με σφάλμα
            }
        strncpy(radio_button_ids_memory[num_of_radio_button_ids], $1, sizeof(radio_button_ids_memory[i]));
        num_of_radio_button_ids++;
    }
} QUOTES;

max_feature: /*empty*/ | MAX EQUAL QUOTES POSINT {max_value=$1;} QUOTES;

progress_feature: /*empty*/ | PROGRESS EQUAL QUOTES POSINT {
    if ($1<0 || $1>max_value) { 
        fprintf(stderr, "Errror: This is not an allowed value. The value entered should be between 0 and the max value defined");
        exit(1); //έξοδος από το πρόγραμμά με σφάλμα
    }
} QUOTES;
//_____________________________________________________________________________
//ορισμός κανώνων για στοιχεία που μπορούν να εμφανιστούν 0 ή πολλαπλές φορές
elements_null_or_more: /*empty*/ | elements_null_or_more | elements ;
relative_layout_null_or_more: /*empty*/ | relative_layout_null_or_more | relative_layout ;
comment_string:  /*empty*/ | comment_string | COMMENT_CHAR;
//______________________________________________________________________________
//ορισμός κανώνων για στοιχεία που πρέπει να εμφανιστούν 1 ή περισσότερες φορές
elements_one_or_more: elements_null_or_more | elements;
linear_layout_one_or_more: linear_layout_one_or_more | linear_layout ;

%%
yyerror(const char *error_msg)
{   
    errors++;
    fprintf(stderr, "There was a syntax error in line %d: %s/n", new_line, error_msg); //υποχρεωτική συνάρτηση στο μεταπροόγραμμα bison, καλείται όταν υπάρχει συνακτικό σφάλμα
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