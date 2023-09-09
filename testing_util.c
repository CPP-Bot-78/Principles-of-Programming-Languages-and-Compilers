#include <stdio.h>

#include <string.h>
int i;
char* arr[1024]={"hi","hi","hi there"};
int main(void){


arr[4]="wowow";

int l = 1;

sprintf(arr, "%d", l);


for(i=0;i<10;i++) printf("%s\n",arr[i]);
printf("---------\n");
for(i=0;i<10;i++){
    if (strcmp(arr[i],"hi")==0){
        printf("Found\n");
    }
}

}