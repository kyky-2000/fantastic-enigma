#include "../head/linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    (*L) = (LinkedList)malloc( sizeof(LNode) );
    if(NULL == *L)
    {
        printf("分配失败！\n");
        exit(-1);
    }

    (*L)->next = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList pL, pHead;

    pHead = *L;
    while(NULL != pHead->next)
    {
        pL = pHead;
        pHead = pHead->next;
        free(pL);
    }
    free(pHead);
    pHead = NULL;
    return;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    q->next = p->next;
    p->next = q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    LNode * pL;
    if(NULL == p->next)
    {
        return ERROR;
    }
    else
    {
        pL = p->next;
        p->next = p->next->next;
        *e = pL->data;
        free(pL);
    }
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LNode * p;

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

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    int n = 1;
    LNode * p;
    p = L->next;
    while(p != NULL)
    {
        n++;
        if(e == p->data)
        {
            printf("数据存在\n");
            printf("该数据在链表的第%d个节点\n", n);
            return SUCCESS;
        }
        p = p->next;
    }
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    LNode *p, *q, *pTail;

    if(NULL == (*L)->next)
    {
        printf("链表为空，操作失败！\n");
        return ERROR;
    }

    p = (*L)->next;
    (*L)->next = NULL;
    q = NULL;
    while(NULL != p)
    {
        pTail = p->next;
        p->next = q;
        q = p;
        p = pTail;
    }
    (*L)->next = q;
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LNode *fast, *slow;

    if(NULL==L->next || NULL==L->next->next)
    {
        printf("链表长度过短，成不了环\n");
        return ERROR;
    }
    slow = L->next;
    fast = L->next->next;
    while(NULL!=slow && NULL!=fast)
    {
        if(fast == slow)
            return SUCCESS;
        slow = slow->next;
        if(NULL == fast->next)
            break;
        fast = fast->next->next;
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    int i = 1;
    LNode *p1, *p2, *p3, *pTail;

    if(NULL==(*L)->next || NULL==(*L)->next->next)
    {
        printf("链表过短，无需操作！\n");
        return (*L);
    }

    p1 = (*L);
    p2 = p1->next;
    p3 = p2->next;
    while(NULL != p3)
    {
        if(i%2 == 1)
        {
            p1->next = p3;
            pTail = p3->next;
            p3->next = p2;
            p2->next = pTail;
            p1 = p3;
            p3 = p2->next;
            i++;
            continue;
        }
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
        i++;
    }
    return (*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    LNode *pHead, *fast, *slow;

    pHead = (*L);
    if(NULL==pHead->next || NULL==pHead->next->next)
    {
        printf("链表只有少于等于两个节点\n");
        return NULL;
    }
    slow = pHead->next;
    fast = pHead->next->next;
    while(NULL != fast)
    {
        if(NULL == fast->next)
        {
            printf("链表中间有两个节点分别为：%d, %d\n", slow->data, slow->next->data);
            return NULL;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("链表的中间节点为：%d\n", slow->data);
    return NULL;
}

void Visit_Date(ElemType e){
    printf("%7d", e);
}

//Seek the Nodel int the list.
LNode * Seek_Node(LinkedList L, int pos){
    int i = 0;
    LNode *p = L;

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
LNode * Create_Node(int val){
    LNode *pL = (LNode *)malloc(sizeof(LNode));

    if(NULL == pL)
    {
        printf("分配失败！");
        exit(-1);
    }

    pL->data = val;
    pL->next = NULL;
    return pL;
}

//draw the int from the system.in;
int Draw_Data(int digit){
    int i, n, m;
    char a, str[20];

    if(4 == digit)
        m = 999;
    else
        m = 9;

    while((a=getchar()) != '\n')
        continue;
    scanf("%s", str);
    for(i=0, n=0; str[i]!='\0'&&n<m; ++i)
    {
        if(str[i]>='0' && str[i]<='9')
            n = n*10 + (str[i]-'0');
    }
    return n;
}
