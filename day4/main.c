#include <stdio.h>
#include <string.h>

void reverse_str(char * str, int start, int end){
    while (start<end){
        char temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

int main(){
    char str[100];
    fgets(str,100+1,stdin);
    int length = strlen(str);
    str[length-1]='\0';
    length = strlen(str);
    reverse_str(str,0,length-1);

    int start = 0,end = 0;
    for (int i = 0; i < length+1; ++i) {
        if (' ' == str[i] || '\0' == str[i]){
            end = i-1;
            reverse_str(str,start,end);
            start=i+1;
        }
    }
    printf("%s\n",str);
    return 0;
}