# include "LQueue.h"

void InitLQueue(LQueue **Q)
{
    *Q = (LQueue *)malloc(sizeof(LQueue));
    (*Q)->rear = (*Q)->front = NULL;
    (*Q)->length = 0;

}

void DestoryLQueue(LQueue *Q)
{
    if(TRUE == IsEmptyLQueue(Q))
    {
        free(Q);
        return;
    }
    Node *p = Q->front;
    while(p != NULL)
    {
        Q->front = Q->front->next;
        free(p);
        p = Q->front;
    }
    free(Q);
    return;
}

Status IsEmptyLQueue(const LQueue *Q)
{
    if(0 == Q->length)
    {
        printf("队列空了哦\n");
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Status GetHeadLQueue(LQueue *Q, void **e)
{
    if(TRUE == IsEmptyLQueue(Q))
        return FALSE;
    (*e) = Q->front->data;
    return TRUE;
}

int LengthLQueue(LQueue *Q)
{
    return Q->length;
}

Status EnLQueue(LQueue *Q, void *data)
{
    Node *p =(Node *)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    if(Q->front == NULL)
    {
        p->number = 1;
        Q->rear = p;
        Q->front = p;
        Q->length++;
        return TRUE;
    }
    p->number = Q->rear->number + 1;
    Q->rear->next = p;
    Q->rear = p;
    Q->length++;
    return TRUE;
}

Status DeLQueue(LQueue *Q)
{

    if(TRUE == IsEmptyLQueue(Q))
        return FALSE;
    Node *p = Q->front;
    type = datatype[p->number];
    if('d' == type)
    {
        int *i = (int *)p->data;
        printf("%d", *i);
    }
    else if('f' == type)
    {
        float *f = (float *)p->data;
        printf("%f", *f);
    }
    else if('c' == type)
    {
        char *ch = (char *)p->data;
        printf("%c", *ch);
    }
    else
    {
        char *ch = (char *)p->data;
        printf("%s", ch);
    }
    Q->front = Q->front->next;
    Q->length--;
    if(Q->front == NULL)
        Q->rear = NULL;
    free(p);
}

void ClearLQueue(LQueue *Q)
{
    if(TRUE == IsEmptyLQueue(Q))
        return;
    Node *p = Q->front;
    while(p != NULL)
    {
        Q->front = Q->front->next;
        free(p);
        p = Q->front;
    }
    Q->length = 0;
    Q->front = Q->rear = NULL;
    return;
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(int i, void *q))
{
    Node *p = Q->front;
    while(p != NULL)
    {
        (*foo)(p->number, p->data);
        p = p->next;
    }
    printf("\n");
}

void LPrint(int i, void *q)
{
    type = datatype[i];
    if('d' == type)
    {
        int *k = (int *)q;
        printf("%6d", *k);
    }
    else if('f' == type)
    {
        float *f = (float *)q;
        printf("%8.3f", *f);
    }
    else if('c' == type)
    {
        char *c = (char *)q;
        printf("%3c", *c);
    }
    else
    {
        char *c = (char *)q;
        printf("%8s", c);
    }
}
