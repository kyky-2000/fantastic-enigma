# include "../head/RPN.h"

int IsEmpty(Stack * pS)
{
    if(-1 == pS->top)
        return 1;
    else
        return 0;
}

char pop(Stack * pS)
{
    char ch;
    ch = pS->C[pS->top];
    pS->top--;
    return ch;
}

void push(Stack *pS, char ch)
{
    pS->top++;
    pS->C[pS->top] = ch;
    return;
}

char getTop(Stack * pS)
{
    return pS->C[pS->top];
}

double Dpop(DStack * pS)
{
    double d;
    d = pS->D[pS->top];
    pS->top--;
    return d;
}

void Dpush(DStack *pS, double d)
{
    pS->top++;
    pS->D[pS->top] = d;
    return;
}

Stack * Init_Stack1(void)
{
    Stack * pS;
    pS = (Stack *)malloc(sizeof(Stack));
    pS->C = (char *)malloc(sizeof(char) * 15);

    if(NULL==pS || NULL==pS->C)
    {
        printf("·ÖÅäÊ§°Ü£¡\n");
        exit(-1);
    }
    pS->top = -1;
    return pS;
}

DStack * Init_Stack2(void)
{
    DStack * pS;
    pS = (DStack *)malloc(sizeof(DStack));
    pS->D = (double *)malloc(sizeof(double) * 15);

    if(NULL==pS || NULL==pS->D)
    {
        printf("·ÖÅäÊ§°Ü£¡\n");
        exit(-1);
    }
    pS->top = -1;
    return pS;
}
