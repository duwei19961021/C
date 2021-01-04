//
// Created by duwei on 2021/1/4.
//

/*
 * 有效的括号
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 有效字符串需满足：
 *      左括号必须用相同类型的右括号闭合。
 *      左括号必须以正确的顺序闭合。
 *      注意空字符串可被认为是有效字符串。
 *      输入: "()"
 *      输出: true
 * 链接：https://leetcode-cn.com/problems/valid-parentheses
 * */

typedef char STDataType;

typedef struct
{
    STDataType* _a;
    int  _top;
    int _capacity;
} Stack;

void StackInit(Stack* pst)
{
    pst->_top = 0;
    pst->_a = (STDataType *)malloc(sizeof(STDataType) * 4);
    if (!pst->_a)
    {
        printf("malloc failed.\n");
        exit(-1);
    }
    pst->_capacity = 4;
}

void StackDestory(Stack* pst)
{
    assert(pst);
    free(pst->_a);
    pst->_a = NULL;
}

void StackPush(Stack* pst, STDataType x)
{
    assert(pst);
    if (pst->_top == pst->_capacity)
    {
        pst->_a = (STDataType*)realloc(pst->_a,sizeof(STDataType)*pst->_capacity*2);
        if (!pst->_a)
        {
            printf("realloc failed.\n");
            exit(-1);
        }
        pst->_capacity *= 2;
    }

    pst->_a[pst->_top] = x;
    pst->_top++;
}

void StackPop(Stack* pst)
{
    assert(pst);
    assert(pst->_top > 0);
    --pst->_top;
}

int StackSize(Stack* pst)
{
    assert(pst);
    return pst->_top;
}

int StackEmpty(Stack* pst)
{
    assert(pst);
    return !pst->_top;
}

STDataType StackTop(Stack* pst)
{
    assert(pst);
    assert(pst->_top > 0);
    return pst->_a[pst->_top-1];
}

bool isValid(char * s){
    Stack ps;
    StackInit(&ps);

    while (*s)
    {
        if (*s == '{' || *s == '[' || *s == '(') // 如果是括号起，压入栈中
        {
            StackPush(&ps,*s);
            s++;
        }
        else
        {
            if (StackEmpty(&ps)) // 能走到这里说明*s还没遍历完到末尾，但是栈却空了，起收括号对不上
            {
                return 0;
            }
            char top = StackTop(&ps);
            if (*s == ']' && top != '[')
            {
                return 0;
            }
            if (*s == '}' && top != '{')
            {
                return 0;
            }
            if (*s == ')' && top != '(')
            {
                return 0;
            }
            StackPop(&ps);
            s++;
        }
    }
    int ret = StackEmpty(&ps); // 循环走完如果栈不为空，则说明括号起和括号收的数量对不上，则必不可能满足要求
    StackDestory(&ps);
    return ret;
}