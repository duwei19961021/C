//
// Created by duwei on 2021/2/9.
//

int lengthOfLastWord(char * s){
    int lastIndex = strlen(s)-1;
    while(s[lastIndex] == ' ') // 去除末尾的空格
    {
        lastIndex--;
        if(lastIndex < 0) // 如果lastIndex小于0说明字符串全部是空格
            return 0;
        if(s[lastIndex] != ' ') // 当遇到非空格的时候停下来
            break;
    }

    int count = 0;
    while(s[lastIndex] != ' ') // 此时循环从字符串的最后一个非空格字符开始从后往前遍历
    {
        count++;
        lastIndex--;
        if(lastIndex<0) // lastIndex 小于 0 则已经遍历完成
            break;
    }
    return count;
}