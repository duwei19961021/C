//
// Created by duwei on 2021/1/27.
//

/*
 * 转换成小写字母
 * 链接：https://leetcode-cn.com/problems/to-lower-case/
 * */

char * toLowerCase(char * str){
    int length = 0;
    for (int i = 0; str[i]!='\0'; ++i)
    {
        length++;
    }

    char* retStr = (char*)malloc(sizeof(char)*length+1);

    for (int i = 0; str[i]!='\0'; ++i)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            retStr[i] = str[i]+32;
        }
        else
        {
            retStr[i] = str[i];
        }
    }
    retStr[length] = '\0';
    return retStr;
}