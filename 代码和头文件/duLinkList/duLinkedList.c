# include "../head/duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    (*L) = (DuLinkedList )malloc( sizeof(DuLNode) );
    if(NULL == *L)
    {
        printf("分配失败！\n");
        exit(-1);
    }

    (*L)->next = NULL;
    (*L)->prior = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList pD, pHead;

    pHead = *L;
    while(NULL != pHead->next)
    {
        pD = pHead;
        pHead = pHead->next;
        free(pD);
    }
    free(pHead);
    pHead = NULL;
    return;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if(NULL == p->prior)
    {
        printf("这里是头节点，不允许插入在头节点前方\n");
        return ERROR;
    }
    else
    {
        q->prior = p->prior;
        p->prior->next = q;
        p->prior = q;
        q->next = p;
    }
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if(NULL == p->next)
    {
        p->next = q;
        q->prior = p;
        q->next = NULL;
    }
    else
    {
        q->next = p->next;
        p->next->prior = q;
        p->next = q;
        q->prior = p;
    }
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    DuLNode * pD;
    if(NULL == p->next)
    {
        return ERROR;
    }
    else if(NULL == p->next->next)
    {
        pD = p->next;
        p->next = NULL;
        *e = pD->data;
        free(pD);
    }
    else
    {
        pD = p->next;
        pD->next->prior = p;
        p->next = pD->next;
        *e = pD->data;
        free(pD);
    }
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLNode * p;

    p = L->next;
    if(NULL == p)
        printf("链表为空\n");
    while(NULL != p)
    {
        visit( p->data );
        p = p->next;
    }
    printf("\n");
    return;
}

//Output the date of the Nodel.
void Visit_Date(ElemType e){
    printf("%7d", e);
}

//Seek the Nodel int the list.
DuLNode * Seek_Node(DuLinkedList L, int pos){
    int i = 0;
    DuLNode *p = L;

    while(NULL!=p && i<pos-1)
    {
        p = p->next;
        ++i;
    }
    if(i>pos-1 || NULL==p)
    {
        printf("查无此节点\n");
        return NULL;
    }
    else
        return p;

}

//Create a new nodel when uers input the date.
DuLNode * Create_Node(int val){
    DuLNode *pD = (DuLNode *)malloc(sizeof(DuLNode));

    if(NULL == pD)
    {
        printf("分配失败！");
        exit(-1);
    }

    pD->data = val;
    pD->next = NULL;
    pD->prior = NULL;
    return pD;
}

//draw the int from the system.in;
int Draw_Data(int digit){
    int i, n, m;
    char a, str[20];

    if(4 == digit)
        m = 999;
    else
        m = 9;

    while((a=getchar()) != '\n')    //处理flag1所需要的以外的非法字符
        continue;
    scanf("%s", str);
    for(i=0, n=0; str[i]!='\0'&&n<m; ++i)
    {
        if(str[i]>='0' && str[i]<='9')
            n = n*10 + (str[i]-'0');
    }
    return n;
}
