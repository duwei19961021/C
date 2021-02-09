//
// Created by duwei on 2021/2/9.
//
/*
 * 链接：https://leetcode-cn.com/problems/ransom-note/submissions/
 */

bool canConstruct(char * ransomNote, char * magazine)
{
    int rand[26] = {0};
    int maga[26] = {0};
    while(*ransomNote != '\0')
    {
        rand[*ransomNote - 97]++;
        ransomNote++;
    }

    while(*magazine != '\0')
    {
        maga[*magazine - 97]++;
        magazine++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(rand[i] > maga[i])
            return false;
    }
    return true;
}