#include<stdio.h>
#include<string.h>

int table[128];

void shiftTable(char *searchStr){

    for(int i=0;i<128;i++){
        table[i] = strlen(searchStr);
    }

    for(int i=0;i<strlen(searchStr)-1;i++){
        table[searchStr[i]] = strlen(searchStr)-i-1;
    }
}

int horspool(char *str, char *searchStr){
    shiftTable(searchStr);
    int size = strlen(searchStr);
    int i = size-1;
    while(i<strlen(str)){
        int k=0;
        while(k<size && str[i-k] == searchStr[size-k-1]){
            k++;
        }
        if(k == size){
            return (i-size+2);
        }
        else{
            i+= table[str[i]];
        }
    }

    return -1; //Not found!

    
}

void main(){
    char str[50];
    char searchStr[50];

    printf("\nEnter the text you wanna search:\t");
    scanf("%s",str);

    printf("\nEnter the search string:\t");
    scanf("%s",searchStr);

    int pos = horspool(str,searchStr);
        if(pos != -1){
            printf("The search string is found at %d",pos);
        }
        else{
            printf("The search string is not found in the string!");
        }
}