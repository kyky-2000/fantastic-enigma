# include "../head/duLinkedList.h"

int main(void)
{
    int i, val, n, pos1, pos2, flag;
    DuLinkedList pHead;
    DuLNode *p, *q, *s;
    char a, ch, ch1, ch2, flag1;

    ch = 'Y';

    InitList_DuL(&pHead);   //链表的初始化，链表为空

    while(ch=='Y' || ch=='y')
    {
        ch1 = 'Y';
        ch2 = 'Y';
        for(i=0; i<30; ++i)  //操作菜单
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
        printf("3----遍历链表\n");
        for(i=0; i<30; ++i)
            printf("***");
        printf("\n");

        scanf("%d", &flag);
        switch(flag)     //switch语句进行各选项的跳转
        {
        case 1:
            while(ch1=='Y' || ch1=='y')
            {
                printf("请输入要插入节点的数据域的数值(至多可以有四位有效数字)：\n");
                val = Draw_Data(4);    //调用函数处理用户输入的字符，从中至多提取四位有效数字
                q = Create_Node(val);
                printf("请输入要插入到第几个节点的邻位(至多可以有两位有效数字)：\n");
                pos1 = Draw_Data(2);  //调用函数处理用户输入的字符，从中至多提取两位有效数字
                if(NULL != (p=Seek_Node(pHead, pos1)))  //调用函数检测用户输入的位置是否合法，合法才进行接下来的操作
                {
                    printf("请输入要插到该节点的前方（输入R）还是后方（输入L）：\n");
                    while((a=getchar()) != '\n')    //处理flag1所需要的以外的非法字符
                        continue;
                    scanf("%c", &flag1);    //switch语句进行各选项的跳转
                    switch(flag1)
                    {
                    case 'R':
                    case 'r':
                        if(SUCCESS == InsertBeforeList_DuL(p, q))
                            printf("插入成功！\n");
                        break;
                    case 'L':
                    case 'l':
                        if(SUCCESS == InsertAfterList_DuL(p, q))
                            printf("插入成功！\n");
                        break;
                    default:      //对选项以外的数据进行统一处理
                        printf("非法输入，插入失败！\n");
                        break;
                    }
                }
                printf("请问是否还要插入节点（Y/N）");
                while((a=getchar()) != '\n')      //处理ch1所需要的以外的非法字符
                    continue;
                scanf("%c", &ch1);
            }
            break;
        case 2:
            while(ch2=='Y' || ch2=='y')
            {
                printf("请输入要删除第几个节点(至多可以有两位有效数字)：\n");
                pos2 = Draw_Data(2);      //调用函数处理用户输入的字符，从中至多提取两位有效数字
                if(NULL != (s=Seek_Node(pHead, pos2)))     //调用函数检测用户输入的位置是否合法，合法才进行接下来的操作
                {
                    if(NULL == s->prior)
                        printf("删除失败，不允许删除头结点！\n");
                    else
                    {
                        DeleteList_DuL(s->prior, &n);
                        printf("删除的节点的数据为：%d\n", n);
                    }
                }
                printf("是否还要继续删除节点（Y/N）\n");
                while((a=getchar()) != '\n')      //处理ch2所需要的以外的非法字符
                    continue;
                ch2 = getchar();
            }
            break;
        case 3:
            TraverseList_DuL(pHead, Visit_Date);
            break;
        default:
            printf("非法输入，请重试\n");
            break;
        }

        printf("是否返回主菜单(是请按y)\n");     //返回主菜单选项
        while((a=getchar()) != '\n')
            continue;
        scanf("%c", &ch);
        if('Y'!=ch && 'y'!=ch)
            printf("程序结束\n");
    }
    DestroyList_DuL(&pHead);     //将程序链表动态分配的空间释放掉
    return 0;

}
