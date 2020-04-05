#ifndef RPN_H_INCLUDED
#define RPN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

//用于将中缀表达式转化为后缀表达式
typedef struct Stack
{
    char * C;
    int top;
}Stack;

//用于计算后缀表达式的结果（之所以和上面分开是因为上面栈存放运算符，而这个存放数据）
typedef struct DStack
{
    double * D;
    int top;
}DStack;

Stack * Init_Stack1(void);//第一个栈的初始化
DStack * Init_Stack2(void);//第二个栈的初始化
void push(Stack *pS, char ch);//对应第一个栈的压栈
int IsEmpty(Stack * pS);  //查看栈是否为空
char pop(Stack * pS);    //对应第一个栈的出栈
char getTop(Stack * pS);    //得到栈顶元素
double Dpop(DStack * pS);   //对应第二个栈的出栈
void Dpush(DStack *pS, double d);   //对应第二个栈的压栈


#endif
