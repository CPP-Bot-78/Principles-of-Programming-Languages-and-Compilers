%option noyywrap

%{
#include "bison.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int chars=0;  not used
//int words=0;
//int lines=0;
%}

nums ([0-9])+
strings ([a-zA-Z])+  //    string (\\.|[^\"])* 

%%
"LinearLayout" {return LINEAR;}
"RelativeLayout" {return RELATIVE;}
"TextView" {return TEXTVIEW;}
"ImageView" {return IMAGEVIEW;}
"Button" {return BUTTON;}
"RadioGroup" {return RADIOGROUP;}
"RadioButton" {return RADIOBUTTON;}
"ProgressBar" {return PROGRESSBAR;}

"android:layout_width" {return WIDTH;}
"android:layout_height" {return HEIGHT;}
"android:id" {return ID;}
"android:orientation" {return ORIENTATION;}
"android:text" {return TEXT;}
"android:textColor" {return TEXTCOLOR;}
"android:src" {return SRC;}
"android:padding" {return PADDING;}
"android:checkedButton" {return CHECKBUTTON;}
"android:max" {return MAX;}
"android:progress" {return PROGRESS;}

"=" {return EQUAL}
"<" {return LEFTSYMBOL;}
">" {return RIGHTSYMBOL;}
"/" {return ENDSYMBOL;}
"\"" {return QUOTES;}
"<!--" {return STARTCOMMENT;}
"-->" {return ENDCOMMENT;}
{nums}   { yylval.integer = atoi(yytext); return POSINT; } //yylval: θέτει τιμή για χρήση στα actions
{strings} { yylval.string = strdup(yytext); return STRING; }
%%