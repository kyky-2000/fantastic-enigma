#include "../head/LinkStack.h"

Status initLStack(LinkStack **s)  //初始化栈
{
    *s = (LinkStack *)malloc(sizeof(LinkStack));
    if(NULL == *s)
    {
        printf("分配内存失败！\n");
        exit(-1);
    }

    (*s)->top = NULL;
    (*s)->count = 0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)   //判断栈是否为空
{
    if(0 == s->count)
    {
        printf("栈为空\n");
        return SUCCESS;
    }
    return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
    if(SUCCESS == isEmptyLStack(s))
    {
        printf("获取失败！\n");
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

Status clearLStack(LinkStack *s)   //清空栈
{
    ElemType d;

    while(s->count)
    {
        popLStack(s, &d);
        printf("出栈成功，出栈元素为%d\n", d);
    }

    printf("清空完毕！\n");
    return SUCCESS;
}

Status destroyLStack(LinkStack *s)   //销毁栈
{
    clearLStack(s);
    free(s);
    printf("销毁完毕！\n");
    return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)   //检测栈长度
{
    *length = s->count;
    return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
    StackNode *pNew = (StackNode *)malloc(sizeof(StackNode));

    if(NULL == pNew)
    {
        printf("分配内存失败！\n");
        exit(-1);
    }
    pNew->data = data;
    pNew->next = s->top;
    s->top = pNew;
    s->count++;

    return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
    LinkStackPtr pTail;

    if(SUCCESS == isEmptyLStack(s))
    {
        printf("出栈失败！\n");
        return ERROR;
    }

    pTail = s->top;
    s->top = s->top->next;
    s->count--;
    *data = pTail->data;
    free(pTail);

    return SUCCESS;
}

int Draw_Data(int digit)  //从输入的字符串中提取整型数字
{
    int i, n;
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
