%option noyywrap

%{
#include "myParser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int chars=0;
int words=0;
int lines=0;

%}



%%


<>["root_layout" | "linear_layout"]


%%