#include "../Head/SqStack.h"

Status initStack(SqStack **s,int sizes)
{
    (*s) = (SqStack *)malloc(sizeof(SqStack));
    (*s)->elem = (ElemType *)malloc(20 * sizeof(ElemType));

    if(NULL==(*s) || NULL==(*s)->elem)
    {
        printf("·ÖÅäÊ§°Ü£¡\n");
        exit(-1);
    }
    (*s)->size = sizes;
    (*s)->top = -1;
    return SUCCESS;
}

Status isEmptyStack(SqStack *s)
{
    int len;
    char a, ch;

    if(-1 == s->top)
    {
        printf("Õ»Îª¿Õ£¡\n");
        return SUCCESS;
    }
    else
        return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e)
{
    *e = s->elem[s->top];
    return SUCCESS;
}

Status clearStack(SqStack *s)
{
    s->top = -1;
    printf("Çå¿ÕÍê±Ï£¡\n");
    return SUCCESS;
}

Status destroyStack(SqStack *s)
{
    free(s->elem);
    free(s);
    printf("Õ»ÒÑÏú»Ù£¡\n");
    return SUCCESS;
}

Status stackLength(SqStack *s,int *length)
{
    *length = s->top + 1;
    return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)
{
    if((s->size)-1 == s->top)
    {
        printf("Õ»ÒÑÂú£¡\n");
        return ERROR;
    }
    else
    {
        s->elem[++(s->top)] = data;
        return SUCCESS;
    }
}

Status popStack(SqStack *s,ElemType *data)
{
    if(SUCCESS == isEmptyStack(s))
    {
        printf("³öÕ»Ê§°Ü£¡\n");
        return ERROR;
    }
    else
    {
        *data = s->elem[(s->top)--];
        return SUCCESS;
    }

}

//draw the int from the system.in;
ElemType Draw_Data1(void){
    ElemType i, n;
    char a, str[20];

    while((a=getchar()) != '\n')
        continue;
    scanf("%s", str);
    for(i=0, n=0; str[i]!='\0'&&n<999; ++i)
    {
        if(str[i]>='0' && str[i]<='9')
            n = n*10 + (str[i]-'0');
    }

    return n;
}

ElemType Draw_Data2(void){
    ElemType i, n;
    char a, str[20];

    scanf("%s", str);
    for(i=0, n=0; str[i]!='\0'&&n<9; ++i)
    {
        if(str[i]>='0' && str[i]<='9')
            n = n*10 + (str[i]-'0');
    }

    return n;
}
