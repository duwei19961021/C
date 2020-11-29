#include <stdio.h>
#define TRUE 1

void process_standard_input(void );
void process_file(char *file_name);

int option_a, option_b;

int main(int argc, char **argv)
{
    while (*++argv != NULL && **argv == '-'){ // 检查每个参数是否是 '-' 开头
        switch (*++*argv) { //检查 '-' 后面的字母, *argv表示数组的地址，解引用之后表示第一个元素，第一个元素又是指针，进行++之后表示从第二个字符开始的位置(指针)，再解引用表示字符。
            case 'a':
                option_a = TRUE;
                break;
            case 'b':
                option_b = TRUE;
                break;
        }
    }

    if (*argv == NULL){ // 这里是根据传入参数进行不同的处理，具体的处理函数没有实现
        process_standard_input();
    } else{
        do {
            process_file(*argv);
        } while (*++argv != NULL);
    }
    return 0;
}

