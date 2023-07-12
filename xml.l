%option noyywrap

%{
#include "bison.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int chars=0;
int words=0;
int lines=0;

%}

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

"<" {return LEFTSYMBOL;}
">" {return RIGHTSYMBOL;}
"/" {return ENDSYMBOL;}
"\"" = {return QUOTES;}
%%