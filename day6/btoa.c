#include <stdio.h>

void BinaryToASCII(int x)
{
    int temp = x/10;
    if (temp){
        BinaryToASCII(temp);
    }
    printf("%c ",x%10+'0');
}

int main()
{
    BinaryToASCII(9876);
    return 0;
}