#include <stdio.h>

#define TRUE 1
#define FALSE 0

int find_char(char **stings, char value) // 字符指针数组传参，arr是字符指针，传参的时候降维成二级字符指针
{
    char *string;
    while ((string = *stings++) !=NULL){ // *strings++ 每次++ 跳跃一个数组元素(字符指针),检查所有数组成员是否是空字符
        while (*string != '\0'){
            if (*string++ == value){
                return TRUE;
            }
        }
    }
    return FALSE;
}

int main(){
    char *arr[] = {"apple","banana","orange"};
    int ret = find_char(arr, 'a');
    printf("ret = %d\n", ret);
    return 0;
}