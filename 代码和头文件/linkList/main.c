#include "../head/linkedList.h"
int main(void)
{
    int i, j, val, val1, n, pos1, pos2, flag;
    LinkedList pHead;
    LNode *p, *q, *s, *MidNode;
    char a, ch, ch1, ch2;

    ch = 'Y';
    InitList(&pHead);   //初始化，生成一个空链表

    for(i=0; i<30; ++i)  //展示菜单
        printf("***");
    printf("\n");
    printf("1----插入节点\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("2----删除节点\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("3----查找链表是否存在某节点\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("4----倒置链表\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("5----查询链表是否有环\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("6----进行链表的奇偶调转\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("7----查找链表的中间节点\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("8----遍历链表\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");

    while(ch=='Y' || ch=='y')
    {
        ch1 = 'Y';
        ch2 = 'Y';

        scanf("%d", &flag);
        switch(flag)        //switch语句进行各选项的跳转
        {
        case 1:
            while(ch1=='Y' || ch1=='y')
            {
                printf("请输入要插入节点的数据域的数值(至多可以有四位有效数字)：\n");
                val = Draw_Data(4);                                                 //调用函数处理用户输入的至多二十个字符，从中至多提取四位有效数字
                q = Create_Node(val);
                printf("请输入要插入到第几个节点的右端(至多可以有两位有效数字)：\n");
                pos1 = Draw_Data(2);                                                //调用函数处理用户输入的至多二十个9字符，从中至多提取两位有效数字
                if(NULL != (p=Seek_Node(pHead, pos1)))              //调用函数检测用户输入的位置是否合法，合法才进行接下来的操作
                    if(SUCCESS == InsertList(p, q))
                        printf("插入成功！\n");

                printf("请问是否还要插入节点（Y/N）\n");
                while((a=getchar()) != '\n')            //处理ch1所需要的以外的非法字符
                    continue;
                scanf("%c", &ch1);
            }
            if('N'!=ch && 'n'!=ch)
            {
                printf("输入错误\n");
                break;
            }
            break;
        case 2:
            while(ch2=='Y' || ch2=='y')
            {
                printf("请输入要删除第几个节点(至多可以有两位有效数字)：\n");
                pos2 = Draw_Data(2);                             //调用函数处理用户输入的至多二十个字符，从中至多提取两位有效数字
                if(NULL != (s=Seek_Node(pHead, pos2-1)))         //调用函数检测用户输入的位置是否合法，合法才进行接下来的操作
                {
                    if(NULL == s->next)
                        printf("删除失败，无此节点\n");
                    else
                    {
                        DeleteList(s, &n);
                        printf("删除的节点的数据为：%d\n", n);
                    }
                }
                else
                    printf("删除失败！\n");
                printf("是否还要继续删除节点（Y/N）\n");
                while((a=getchar()) != '\n')         //处理ch2所需要的以外的非法字符
                    continue;
                ch2 = getchar();
            }
            if('N'!=ch && 'n'!=ch)
            {
                printf("输入错误\n");
                break;
            }
            break;
        case 3:
            printf("请输入要查找的数据(至多可以有四位有效数字)\n");   //调用函数遍历链表看是否有要查找的数据
            val1 = Draw_Data(4);
            if(ERROR == SearchList(pHead, val))
                printf("查无此数据\n");
            break;
        case 4:
            if(SUCCESS == ReverseList(&pHead));
                TraverseList(pHead, Visit_Date);
            break;
        case 5:
            if(SUCCESS == IsLoopList(pHead))
                printf("链表有环\n");
            else
                printf("链表无环\n");
            break;
        case 6:
            pHead = ReverseEvenList(&pHead);
            TraverseList(pHead, Visit_Date);
            break;
        case 7:
            FindMidNode(&pHead);
            break;
        case 8:
            TraverseList(pHead, Visit_Date);
            break;
        default:
            printf("输入不合法\n");      //对选项以外的数据进行统一处理
        }
        printf("是否返回主菜单(是请输入y)\n");
        while((a=getchar()) != '\n')     //处理ch所需要的以外的非法字符
                    continue;
        scanf("%c", &ch);
        if('Y'!=ch && 'y'!=ch)
        {
            printf("程序结束\n");
            break;
        }
        printf("(功能提示：1插，2删，3查点，4倒置，5查环，6奇偶倒，7查中点，8遍历)\n");   //菜单过长，妨碍视线，不便直接再现
    }

    DestroyList(&pHead);     //将程序链表动态分配的空间释放掉
    return 0;
}
