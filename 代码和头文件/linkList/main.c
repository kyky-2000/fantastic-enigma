#include "../head/linkedList.h"
int main(void)
{
    int i, j, val, val1, n, pos1, pos2, flag;
    LinkedList pHead;
    LNode *p, *q, *s, *MidNode;
    char a, ch, ch1, ch2;

    ch = 'Y';
    InitList(&pHead);   //��ʼ��������һ��������

    for(i=0; i<30; ++i)  //չʾ�˵�
        printf("***");
    printf("\n");
    printf("1----����ڵ�\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("2----ɾ���ڵ�\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("3----���������Ƿ����ĳ�ڵ�\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("4----��������\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("5----��ѯ�����Ƿ��л�\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("6----�����������ż��ת\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("7----����������м�ڵ�\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");
    printf("8----��������\n");
    for(i=0; i<30; ++i)
        printf("***");
    printf("\n");

    while(ch=='Y' || ch=='y')
    {
        ch1 = 'Y';
        ch2 = 'Y';

        scanf("%d", &flag);
        switch(flag)        //switch�����и�ѡ�����ת
        {
        case 1:
            while(ch1=='Y' || ch1=='y')
            {
                printf("������Ҫ����ڵ�����������ֵ(�����������λ��Ч����)��\n");
                val = Draw_Data(4);                                                 //���ú��������û�����������ʮ���ַ�������������ȡ��λ��Ч����
                q = Create_Node(val);
                printf("������Ҫ���뵽�ڼ����ڵ���Ҷ�(�����������λ��Ч����)��\n");
                pos1 = Draw_Data(2);                                                //���ú��������û�����������ʮ��9�ַ�������������ȡ��λ��Ч����
                if(NULL != (p=Seek_Node(pHead, pos1)))              //���ú�������û������λ���Ƿ�Ϸ����Ϸ��Ž��н������Ĳ���
                    if(SUCCESS == InsertList(p, q))
                        printf("����ɹ���\n");

                printf("�����Ƿ�Ҫ����ڵ㣨Y/N��\n");
                while((a=getchar()) != '\n')            //����ch1����Ҫ������ķǷ��ַ�
                    continue;
                scanf("%c", &ch1);
            }
            if('N'!=ch && 'n'!=ch)
            {
                printf("�������\n");
                break;
            }
            break;
        case 2:
            while(ch2=='Y' || ch2=='y')
            {
                printf("������Ҫɾ���ڼ����ڵ�(�����������λ��Ч����)��\n");
                pos2 = Draw_Data(2);                             //���ú��������û�����������ʮ���ַ�������������ȡ��λ��Ч����
                if(NULL != (s=Seek_Node(pHead, pos2-1)))         //���ú�������û������λ���Ƿ�Ϸ����Ϸ��Ž��н������Ĳ���
                {
                    if(NULL == s->next)
                        printf("ɾ��ʧ�ܣ��޴˽ڵ�\n");
                    else
                    {
                        DeleteList(s, &n);
                        printf("ɾ���Ľڵ������Ϊ��%d\n", n);
                    }
                }
                else
                    printf("ɾ��ʧ�ܣ�\n");
                printf("�Ƿ�Ҫ����ɾ���ڵ㣨Y/N��\n");
                while((a=getchar()) != '\n')         //����ch2����Ҫ������ķǷ��ַ�
                    continue;
                ch2 = getchar();
            }
            if('N'!=ch && 'n'!=ch)
            {
                printf("�������\n");
                break;
            }
            break;
        case 3:
            printf("������Ҫ���ҵ�����(�����������λ��Ч����)\n");   //���ú������������Ƿ���Ҫ���ҵ�����
            val1 = Draw_Data(4);
            if(ERROR == SearchList(pHead, val))
                printf("���޴�����\n");
            break;
        case 4:
            if(SUCCESS == ReverseList(&pHead));
                TraverseList(pHead, Visit_Date);
            break;
        case 5:
            if(SUCCESS == IsLoopList(pHead))
                printf("�����л�\n");
            else
                printf("�����޻�\n");
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
            printf("���벻�Ϸ�\n");      //��ѡ����������ݽ���ͳһ����
        }
        printf("�Ƿ񷵻����˵�(��������y)\n");
        while((a=getchar()) != '\n')     //����ch����Ҫ������ķǷ��ַ�
                    continue;
        scanf("%c", &ch);
        if('Y'!=ch && 'y'!=ch)
        {
            printf("�������\n");
            break;
        }
        printf("(������ʾ��1�壬2ɾ��3��㣬4���ã�5�黷��6��ż����7���е㣬8����)\n");   //�˵��������������ߣ�����ֱ������
    }

    DestroyList(&pHead);     //����������̬����Ŀռ��ͷŵ�
    return 0;
}
