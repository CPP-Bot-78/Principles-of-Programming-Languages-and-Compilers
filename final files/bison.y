%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror(char *);
extern FILE *yyin;								
extern FILE *yyout;
extern char* yytext;
extern int new_line;
int errors;	

char *ids_memory[1024];
int num_of_ids=0;

char *radio_button_ids_memory[1024];
int num_of_radio_button_ids=0;
int wanted_radio_buttons=0;

int max_value;

char* checkbutton;

%}

%token LINEAR RELATIVE TEXTVIEW IMAGEVIEW BUTTON RADIOGROUP RADIOBUTTON PROGRESSBAR 
%token WIDTH HEIGHT ID ORIENTATION TEXT TEXTCOLOR SRC PADDING CHECKBUTTON MAX PROGRESS 
%token EQUAL LEFTSYMBOL RIGHTSYMBOL ENDSYMBOL QUOTES STARTCOMMENT ENDCOMMENT POSINT STRING
%token NORADIOBUTTON COMMENT_CHAR

%union{
char* string;
unsigned int integer;
}

%start root_layout

%%
root_layout: linear_layout
           | relative_layout 
           ;

linear_layout: LEFTSYMBOL LINEAR must_atributes
                                 id_feature
                                 orientation_feature RIGHTSYMBOL
                                 linear_elements_one_or_more
                LEFTSYMBOL ENDSYMBOL LINEAR RIGHTSYMBOL
                ;

relative_layout: LEFTSYMBOL RELATIVE must_atributes
                                 id_feature RIGHTSYMBOL
                                 relative_elements_null_or_more
                 LEFTSYMBOL ENDSYMBOL RELATIVE RIGHTSYMBOL
                 ;

relative_elements: text_view | image_view | button | radio_group | progress_bar | relative_layout;
linear_elements: text_view | image_view | button | radio_group | progress_bar | relative_layout |linear_layout;

must_atributes: WIDTH EQUAL QUOTES must_atributes_values QUOTES
                HEIGHT EQUAL QUOTES must_atributes_values QUOTES
              ;
        
              
must_atributes_values: STRING  { // αν είναι string ελέγχουμε μεσω της strcmp(0 αν είναι ίδια) αν έχει μια εκ των δύο παρακάτω τιμών, αλλιώς error
                            if (strcmp(yytext, "wrap_content") != 0 && strcmp(yytext, "match_parent") != 0) { 
                            printf("\nError line %d: Allowed android:layout_width and android:layout_height values are \"wrap_content\", \"match_parent\" or an positive integer number.", new_line);
                            exit(1);
                        }
                      } // αν είναι int ελέγχουμε αν είναι <=0 για να εμφανιστεί error
                      | POSINT { if (atoi(yytext) <=0) {
                            printf("\nError line %d: Allowed android:layout_width and android:layout_height values are \"wrap_content\", \"match_parent\" or an positive integer number.", new_line);
                            exit(1);
                        }
                      };


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
            NORADIOBUTTON EQUAL QUOTES POSINT{wanted_radio_buttons=atoi(yytext);} QUOTES //3ερ. Ποσα radio buttons θελουμε
            id_feature
            checkbutton_feature RIGHTSYMBOL
            radio_button_one_or_more
            LEFTSYMBOL ENDSYMBOL RADIOGROUP {
                int checkbutton_on_radio_list=0; //Ερ 2d: λογικό flag. Αν γίνει 1, τότε βρήκαμε την τιμή του checkedButton στον πινακα με τα ids των radio buttons.
                for (int j=0; j<num_of_radio_button_ids; j++){ 
                    if (strcmp(checkbutton, radio_button_ids_memory[j])==0){ //συγκρίνουμε με κάθε τιμή
                        checkbutton_on_radio_list = 1;
                    }
                }
                if(!checkbutton_on_radio_list){ // αν δεν βρεθεί τυπώνουμε error
                    fprintf(stderr, "\nError line %d: This value should match with a RadioButton Id value\n", new_line);
                    exit(1); //έξοδος από το πρόγραμμά με σφάλμα
                }
                else if (num_of_radio_button_ids != wanted_radio_buttons){ // Ερ 3. Aν ο αριθμός των radio buttons δεν ειναι αυτός του έξτρα στοιχείου τυπώνουμε error
                    fprintf(stderr, "\nError line %d: The number of radio buttons is not the same as the android:radio_button_number value\n", new_line);
                    exit(1); //έξοδος από το πρόγραμμά με σφάλμα
                }
                else { // καθαρίζουμε το checkbutton, τον πίνακα με τα id radio buttons, το πληθος αυτων των ids σε περιπτωση που ακολουθει άλλο radio group
                    checkbutton=strdup("");
                    memset(radio_button_ids_memory, '\0', sizeof(num_of_radio_button_ids));
                    num_of_radio_button_ids=0;
                }
            } RIGHTSYMBOL;

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

//comment: STARTCOMMENT comment_string ENDCOMMENT ;
//_____________________________________________________________________________
//ορισμός κανώνων προαιρετικών στοιχείων
id_feature: /*empty*/ | ID EQUAL QUOTES STRING { //ερ 2a. Στην 1η επαναληψη δεν τρέχει(πληθος id =0), έπειτα ελέγχει το νέο id με τα υπόλοιπα του πίνακα
    for (int i=0; i<num_of_ids; i++) { 
        if (strcmp(ids_memory[i],yytext)==0) { //αν υπάρχει ηδη τυπώνουμε error και τερματίζει το προγραμμα
            fprintf(stderr, "\nError line %d: This Id value has been used again. Duplicated Id values cannot be accepted\n.", new_line);
            exit(1); //έξοδος από το πρόγραμμά με σφάλμα
            }
        }
        ids_memory[num_of_ids] = strdup(yytext); //αν δεν υπάρχει προστίθεται στον πίνακα 
        num_of_ids++;// αυξάνουμε το πλήθος κατά 1
} QUOTES;

radio_button_id_feature: /*empty*/ | ID EQUAL QUOTES STRING { //ίδιο με πάνω, προστίθεται το id και σε έναν ξεχωριστό πίνακα
    for (int i=0; i<num_of_ids; i++) {
        if (strcmp(yytext, ids_memory[i])==0) {
            fprintf(stderr, "\nError line %d: This Id value has been used again. Duplicated Id values cannot be accepted.\n", new_line);
            exit(1); //έξοδος από το πρόγραμμά με σφάλμα
            }
    }
    ids_memory[num_of_ids] = strdup(yytext);  
    radio_button_ids_memory[num_of_radio_button_ids] = strdup(yytext); 
    num_of_ids++;
    num_of_radio_button_ids++;

} QUOTES;

orientation_feature: /*empty*/ | ORIENTATION EQUAL QUOTES STRING QUOTES ;

textcolor_feature: /*empty*/ | TEXTCOLOR EQUAL QUOTES STRING QUOTES;

padding_feature: /*empty*/ | PADDING EQUAL QUOTES POSINT { if (atoi(yytext) <=0) { // ερ 2c, αν padding <=0 -> error & exit
        printf("\nError line %d: Allowed android:padding values are positive integer numbers. ", new_line);
        exit(1);
            }
        }  QUOTES;

//Ερ 2d. αποθηκεύουμε την τιμή του checkbutton στην μεταβλητή ώστε να την χρησιμοποιήσουμε αργότερα(βλ. πάνω)
checkbutton_feature: /*empty*/ | CHECKBUTTON EQUAL QUOTES STRING{checkbutton= strdup(yytext);} QUOTES; 

//Το ίδιο με πάνω, ερ 2e
max_feature: /*empty*/ | MAX EQUAL QUOTES POSINT {max_value=atoi(yytext);} QUOTES;

progress_feature: /*empty*/ | PROGRESS EQUAL QUOTES POSINT {
    if (atoi(yytext)<0 || atoi(yytext)>max_value) { 
        fprintf(stderr, "Error line %d: This is not an allowed value. The value entered should be between 0 and the max value defined"), new_line;
        exit(1); //έξοδος από το πρόγραμμά με σφάλμα
    }
} QUOTES;
//_____________________________________________________________________________
//ορισμός κανoνων για στοιχεία που μπορούν να εμφανιστούν 0 ή πολλαπλές φορές
relative_elements_null_or_more: /*empty*/ | relative_elements | relative_elements_null_or_more relative_elements;
//comment_string:  /*empty*/| comment_string COMMENT_CHAR | comment_string ;
//______________________________________________________________________________
//ορισμός κανoνων για στοιχεία που πρέπει να εμφανιστούν 1 ή περισσότερες φορές
linear_elements_one_or_more: linear_elements | linear_elements_one_or_more linear_elements;
radio_button_one_or_more: radio_button_one_or_more radio_button | radio_button;

%%
yyerror(const char *error_msg)
{   
    errors++;
    fprintf(stderr, "\nThere was a syntax error in line %d: %s\n", new_line, error_msg); //υποχρεωτική συνάρτηση στο μεταπροόγραμμα bison, καλείται όταν υπάρχει συνακτικό σφάλμα
}

int main(int argc, char **argv){
	errors=0;  
    FILE *jfile = fopen(argv[1], "r");
	yyin = jfile;
    if (!yyin){
            perror("\nThe file could not be opened");
            return 1;
        }
    yyparse();
	
	if(errors==0) {
	     printf("\nProgram Compiled Succesfully\n"); 
    }
    else {
        printf("\n");
        printf("%d syntax errors have occured\n", errors);
    }
	  
	return 0;
}			

