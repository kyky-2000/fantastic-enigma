# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include "AQueue.h"

void InitAQueue(AQueue **Q)
{
    int i;
    (*Q) = (AQueue *)malloc(sizeof(AQueue));
    if(NULL == (*Q))
    {
        printf("����ʧ�ܣ�\n");
        return;
    }
    for(i=0; i<MAXQUEUE; ++i)
        (*Q)->data[i] = NULL;
    (*Q)->front = 0;
    (*Q)->rear = 0;
    (*Q)->length = 0;
}

void DestoryAQueue(AQueue *Q)
{
    void ClearAQueue(Q);
    free(Q);
    printf("������ϣ�\n");
    return;
}

Status IsFullAQueue(const AQueue *Q)
{
    if((Q->rear+1)%MAXQUEUE == Q->front)
    {
       printf("��������\n");
        return TRUE;
    }
    else
        return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->rear == Q->front)
    {
        printf("����Ϊ��\n");
        return TRUE;
    }
    else
        return FALSE;
}

Status GetHeadAQueue(AQueue *Q, void **e)
{
    if(TRUE == IsEmptyAQueue(Q))
        return FALSE;
    else
    {
        (*e) = Q->data[Q->front];
        return TRUE;
    }
}

int LengthAQueue(AQueue *Q)
{
    return Q->length;
}

Status EnAQueue(AQueue *Q, void *data)
{
    if(TRUE == IsFullAQueue(Q))
    {
        return FALSE;
    }
    (Q->data)[Q->rear] = data;
    Q->rear = (Q->rear+1) % MAXQUEUE;
    Q->length++;
    return TRUE;
}

Status DeAQueue(AQueue *Q)
{
    if(TRUE == IsEmptyAQueue(Q))
        return FALSE;
    type = datatype[Q->front];
    if('d' == type)
    {
        int *i = (int *)Q->data[Q->front];
        printf("����Ԫ��Ϊ %d\n", *i);
    }
    else if('f' == type)
    {
        float *f = (float *)Q->data[Q->front];
        printf("����Ԫ��Ϊ %.3f\n", *f);
    }
    else if('c' == type)
    {
        char *c = (char *)Q->data[Q->front];
        printf("����Ԫ��Ϊ %c\n", *c);
    }
    else
    {
        char *c = (char *)Q->data[Q->front];
        printf("����Ԫ��Ϊ %s\n", c);
    }
    free(Q->data[Q->front]);
    Q->front = (Q->front+1) % MAXQUEUE;
    Q->length--;
    return TRUE;
}

void ClearAQueue(AQueue *Q)
{
    if(TRUE == IsEmptyAQueue(Q))
    {
        return;
    }
    int i;
    for(i=Q->front; i!=Q->rear; i=(i+1)%MAXQUEUE)
    {
        free(Q->data[i]);
    }
    Q->front = Q->rear;
    Q->length = 0;
    printf("�����ϣ�\n");
    return;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(int i, void *q))
{
    int i;
    if(TRUE == IsEmptyAQueue(Q))
        return FALSE;
    for(i=Q->front; i!=Q->rear; i=(i+1)%MAXQUEUE)
    {
        (*foo)(i, Q->data[i]);
    }
    printf("\n");
}

void APrint(int i, void *q)
{
    type = datatype[i];
    if('d' == type)
    {
        int *i = (int *)q;
        printf("%7d", *i);
    }
    else if('f' == type)
    {
        float *f = (float *)q;
        printf("%7.3f", *f);
    }
    else if('c' == type)
    {
        char *c = (char *)q;
        printf("%7c", *c);
    }
    else
    {
        char *c = (char *)q;
        printf("%7s", c);
    }
    return;
}
