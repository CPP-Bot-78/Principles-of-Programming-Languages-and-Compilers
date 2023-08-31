%option noyywrap

%{
#include "bison.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PrintCode fwrite(yytext, yyleng, yyout)
//int chars=0;  not used
//int words=0;
//int lines=0; //string (\\.|[^\"])*
%}

nums ([0-9])+
strings ([a-zA-Z])+       
white_spaces [\t\n]

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

"=" {PrintCode; return EQUAL}
"<" {PrintCode; return LEFTSYMBOL;}
">" {PrintCode; return RIGHTSYMBOL;}
"/" {PrintCode; return ENDSYMBOL;}
"\"" {PrintCode; return QUOTES;}
"<!--" {PrintCode; return STARTCOMMENT;}
"-->" {PrintCode; return ENDCOMMENT;}
{nums}   {PrintCode; return POSINT;} //yylval: θέτει τιμή για χρήση στα actions
{strings} {PrintCode; return STRING;}
{white_spaces} {/* Ignore whitespaces. */}
%%

//{nums}   { yylval.integer = atoi(yytext); return POSINT; } //yylval: θέτει τιμή για χρήση στα actions
//{strings} { yylval.string = strdup(yytext); return STRING; }