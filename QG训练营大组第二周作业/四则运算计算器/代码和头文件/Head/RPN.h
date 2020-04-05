#ifndef RPN_H_INCLUDED
#define RPN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

//���ڽ���׺���ʽת��Ϊ��׺���ʽ
typedef struct Stack
{
    char * C;
    int top;
}Stack;

//���ڼ����׺���ʽ�Ľ����֮���Ժ�����ֿ�����Ϊ����ջ���������������������ݣ�
typedef struct DStack
{
    double * D;
    int top;
}DStack;

Stack * Init_Stack1(void);//��һ��ջ�ĳ�ʼ��
DStack * Init_Stack2(void);//�ڶ���ջ�ĳ�ʼ��
void push(Stack *pS, char ch);//��Ӧ��һ��ջ��ѹջ
int IsEmpty(Stack * pS);  //�鿴ջ�Ƿ�Ϊ��
char pop(Stack * pS);    //��Ӧ��һ��ջ�ĳ�ջ
char getTop(Stack * pS);    //�õ�ջ��Ԫ��
double Dpop(DStack * pS);   //��Ӧ�ڶ���ջ�ĳ�ջ
void Dpush(DStack *pS, double d);   //��Ӧ�ڶ���ջ��ѹջ


#endif
