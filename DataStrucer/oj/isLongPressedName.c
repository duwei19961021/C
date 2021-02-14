/*
 * 长按键入
 * 链接：https://leetcode-cn.com/problems/long-pressed-name/
 */

bool isLongPressedName(char * name, char * typed)
{
    int i = 0, j = 0;
    while(name[i] != '\0' && typed[j] != '\0')
    {
        if (name[i] == typed[j]) // 如果相同则两个指针同时向后移动一位
        {
            i++;
            j++;
        }
        else
        {
            if(j == 0) return false; // 在不相同的情况下,如果j或者i等于0则说明第一位就不同直接return false。
            while(typed[j] != '\0' && typed[j] == typed[j-1]) j++; // 使j跨越重复项
            if(name[i] == typed[j]) // 跨越重复项之后再次与name[i]比较,相同则继续往后移动
            {
                i++;
                j++;
            }
            else
            {
                return false;
            }
        }
    }

    if(name[i] != '\0') return false; // 走出循环: 如果此时name的指针i没有指向末尾则说明name没有匹配完,可以直接return false了。
    while(typed[j] != '\0') // 如果是typed的指针j没有指向末尾则需要判断剩下的所有字符是否与当前j指向的字符一致(name:"alex" type:"alexxrrrrssda",此时j指向第一个r,要判断此时的j及其之后的所有字符是否与j-1位置上的字符相等)
    {
        if(typed[j] == typed[j-1])
            j++;
        else
            return false;
    }
    return true;
}
