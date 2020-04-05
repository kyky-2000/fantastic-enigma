#include "../head/LinkStack.h"

Status initLStack(LinkStack **s)  //��ʼ��ջ
{
    *s = (LinkStack *)malloc(sizeof(LinkStack));
    if(NULL == *s)
    {
        printf("�����ڴ�ʧ�ܣ�\n");
        exit(-1);
    }

    (*s)->top = NULL;
    (*s)->count = 0;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
    if(0 == s->count)
    {
        printf("ջΪ��\n");
        return SUCCESS;
    }
    return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
{
    if(SUCCESS == isEmptyLStack(s))
    {
        printf("��ȡʧ�ܣ�\n");
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

Status clearLStack(LinkStack *s)   //���ջ
{
    ElemType d;

    while(s->count)
    {
        popLStack(s, &d);
        printf("��ջ�ɹ�����ջԪ��Ϊ%d\n", d);
    }

    printf("�����ϣ�\n");
    return SUCCESS;
}

Status destroyLStack(LinkStack *s)   //����ջ
{
    clearLStack(s);
    free(s);
    printf("������ϣ�\n");
    return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)   //���ջ����
{
    *length = s->count;
    return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
    StackNode *pNew = (StackNode *)malloc(sizeof(StackNode));

    if(NULL == pNew)
    {
        printf("�����ڴ�ʧ�ܣ�\n");
        exit(-1);
    }
    pNew->data = data;
    pNew->next = s->top;
    s->top = pNew;
    s->count++;

    return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)   //��ջ
{
    LinkStackPtr pTail;

    if(SUCCESS == isEmptyLStack(s))
    {
        printf("��ջʧ�ܣ�\n");
        return ERROR;
    }

    pTail = s->top;
    s->top = s->top->next;
    s->count--;
    *data = pTail->data;
    free(pTail);

    return SUCCESS;
}

int Draw_Data(int digit)  //��������ַ�������ȡ��������
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
