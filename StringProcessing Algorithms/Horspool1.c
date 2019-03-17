/*  
    @Author: Raghav Maheshwari
    @Date: 17th March, 2019
    @Topic: Horspool Algorithm


    Algorithm:
                #####   Main Function   ########

            Step 1: In the first step, accept the string in which the text is to be searched and the searchString as well.

                #####   ShiftTable      #######

            Step 2: Then pass the two strings in the horspool method and call the shiftTable method
            Step 3: In the shiftTbale function, assign the max length of the string (SearchString) to all 128 characters,
                    by making an integer array of 128
            Step 4: The remaining characters which are there in the searchString, their shifttable values are changed using the formula
                    strlen(searchStr)-i-1, stroed in table[searchStr[i]] 
                        -- Note here that searchStr[i] will give the charcter and that will be converted to integer and then used in the table.

                #####    HorspoolMethod  ########

            Step 5: The method or the function takes two character strings and are matched using the shift table.
            Step 6: Run the while loop till i<strlen(str)and then check if k<sizeOfSearchStr and str[i-k] == serachStr[size-k-1]
                    if this is the case go on incrementing k
            Step 7: If k comes out to be same as size then retrun size-i+2, if this is not the case, then add table[tr[i]] to the
                    vale of i. Please note that str[i] because we compare from the base string, not the serachString
            Step 8: If it comes out of the outer loop, without execution of return, then return -1

            #########          Main function Agian          #############

            Step 9: Now if pos is -1, say not found 
            Step 10: Otherwise, return pos as the position where the string is found

            ##########         Function Ends                ##############

*/

#include<stdio.h>
#include<string.h>

int table[128];
void shiftTable(char *searchStr){

    for(int i=0;i<128;i++){
        table[i] = strlen(searchStr);
    }

    for(int i=0;i<strlen(searchStr)-1;i++){
        table[searchStr[i]] = strlen(searchStr) - i -1;
    }
}

int horspool(char *str,char *searchStr){
    shiftTable(searchStr);
    int size = strlen(searchStr);
    int i = size -1;
    while(i<strlen(str)){
        int k =0;
        while(k<size && str[i-k] == searchStr[size-k-1]){
            k++;
        }

        if(k == size){
            return i - size +2;
        }
        else{
            i += table[str[i]];
        }
    }
    return -1;
}

void main(){
    char str[100];
    char searchStr[100];

    printf("\nEnter the string:\t");
    scanf("%s",str);

    printf("\nEnter the search string:\t");
    scanf("%s",searchStr);

    int pos = horspool(str,searchStr);
    if(pos == -1){
        printf("\n The pattern couldn't be found in the given string/text");
    }
    else{
        printf("The pattern is found at the position %d",pos);
    }
}