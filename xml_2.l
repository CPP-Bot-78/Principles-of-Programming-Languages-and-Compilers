%option noyywrap

%{
#include "bison.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PrintCode fprintf(yyout, "%.*s", yyleng, yytext)
//#define PrintCode fwrite(yytext, yyleng, yyout)
//int chars=0;  not used
//int words=0;
//int lines=0; //string (\\.|[^\"])*
int new_line=1;
%}

nums ([0-9])+    
strings ([a-zA-Z_0-9])+
white_space ([ \t])+
newline [\n]

%%
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
"<!--" {PrintCode; return STARTCOMMENT;}
"-->" {PrintCode; return ENDCOMMENT;}
. {PrintCode; return COMMENT_CHAR;}  //οποιαδήποτε χαρακτήρας
{nums}   {PrintCode; return POSINT;}
{strings} {PrintCode; return STRING;}
{white_space} {;}
{newline} {++new_line;printf("\n");}
%%

//{nums}   { yylval.integer = atoi(yytext); return POSINT; } //yylval: θέτει τιμή για χρήση στα actions
//{strings} { yylval.string = strdup(yytext); return STRING; }