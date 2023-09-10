%{
#include "bison.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PrintCode fprintf(yyout, "%.*s", yyleng, yytext)
int new_line=1;
%}
%option noyywrap
%s COMMENT


%%
<COMMENT>{
"-->" {BEGIN(INITIAL);}
(.|\n) {PrintCode;} /*(.|\n)**/
(--) {printf("\n-- is now allowed in comments.\n");exit(1);}
}

<INITIAL>{
"<!--" {BEGIN(COMMENT);}
"LinearLayout" {PrintCode; return LINEAR;}
"RelativeLayout" {PrintCode; return RELATIVE;}
"TextView" {PrintCode; return TEXTVIEW;}
"ImageView" {PrintCode; return IMAGEVIEW;}
"Button" {PrintCode; return BUTTON;}
"RadioGroup" {PrintCode; return RADIOGROUP;}
"RadioButton" {PrintCode; return RADIOBUTTON;}
"ProgressBar" {PrintCode; return PROGRESSBAR;}

"android:layout_width" {PrintCode; return WIDTH;}
"android:layout_height" {PrintCode; return HEIGHT;}
"android:id" {PrintCode; return ID;}
"android:orientation" {PrintCode; return ORIENTATION;}
"android:text" {PrintCode; return TEXT;}
"android:textColor" {PrintCode; return TEXTCOLOR;}
"android:src" {PrintCode; return SRC;}
"android:padding" {PrintCode; return PADDING;}
"android:checkedButton" {PrintCode; return CHECKBUTTON;}
"android:max" {PrintCode; return MAX;}
"android:progress" {PrintCode; return PROGRESS;}
"android:radio_button_number" {PrintCode; return NORADIOBUTTON;} //ερώτημα 3

"=" {PrintCode; return EQUAL;}
"<" {PrintCode; return LEFTSYMBOL;}
">" {PrintCode; return RIGHTSYMBOL;}
"/" {PrintCode; return ENDSYMBOL;}
"\"" {PrintCode; return QUOTES;}
. {PrintCode; return COMMENT_CHAR;}  //οποιαδήποτε χαρακτήρας
[1-9][0-9]* {PrintCode; yylval.integer=atoi(yytext); return POSINT;}
[a-zA-Z0-9_ ]+ {yylval.string=strdup(yytext); PrintCode; return STRING;}
[\n] {PrintCode;new_line++;}
[\t]+ {PrintCode;}
}
%%
