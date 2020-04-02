# include "../head/duLinkedList.h"

int main(void)
{
    int i, val, n, pos1, pos2, flag;
    DuLinkedList pHead;
    DuLNode *p, *q, *s;
    char a, ch, ch1, ch2, flag1;

    ch = 'Y';

    InitList_DuL(&pHead);   //����ĳ�ʼ��������Ϊ��

    while(ch=='Y' || ch=='y')
    {
        ch1 = 'Y';
        ch2 = 'Y';
        for(i=0; i<30; ++i)  //�����˵�
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
        printf("3----��������\n");
        for(i=0; i<30; ++i)
            printf("***");
        printf("\n");

        scanf("%d", &flag);
        switch(flag)     //switch�����и�ѡ�����ת
        {
        case 1:
            while(ch1=='Y' || ch1=='y')
            {
                printf("������Ҫ����ڵ�����������ֵ(�����������λ��Ч����)��\n");
                val = Draw_Data(4);    //���ú��������û�������ַ�������������ȡ��λ��Ч����
                q = Create_Node(val);
                printf("������Ҫ���뵽�ڼ����ڵ����λ(�����������λ��Ч����)��\n");
                pos1 = Draw_Data(2);  //���ú��������û�������ַ�������������ȡ��λ��Ч����
                if(NULL != (p=Seek_Node(pHead, pos1)))  //���ú�������û������λ���Ƿ�Ϸ����Ϸ��Ž��н������Ĳ���
                {
                    printf("������Ҫ�嵽�ýڵ��ǰ��������R�����Ǻ󷽣�����L����\n");
                    while((a=getchar()) != '\n')    //����flag1����Ҫ������ķǷ��ַ�
                        continue;
                    scanf("%c", &flag1);    //switch�����и�ѡ�����ת
                    switch(flag1)
                    {
                    case 'R':
                    case 'r':
                        if(SUCCESS == InsertBeforeList_DuL(p, q))
                            printf("����ɹ���\n");
                        break;
                    case 'L':
                    case 'l':
                        if(SUCCESS == InsertAfterList_DuL(p, q))
                            printf("����ɹ���\n");
                        break;
                    default:      //��ѡ����������ݽ���ͳһ����
                        printf("�Ƿ����룬����ʧ�ܣ�\n");
                        break;
                    }
                }
                printf("�����Ƿ�Ҫ����ڵ㣨Y/N��");
                while((a=getchar()) != '\n')      //����ch1����Ҫ������ķǷ��ַ�
                    continue;
                scanf("%c", &ch1);
            }
            break;
        case 2:
            while(ch2=='Y' || ch2=='y')
            {
                printf("������Ҫɾ���ڼ����ڵ�(�����������λ��Ч����)��\n");
                pos2 = Draw_Data(2);      //���ú��������û�������ַ�������������ȡ��λ��Ч����
                if(NULL != (s=Seek_Node(pHead, pos2)))     //���ú�������û������λ���Ƿ�Ϸ����Ϸ��Ž��н������Ĳ���
                {
                    if(NULL == s->prior)
                        printf("ɾ��ʧ�ܣ�������ɾ��ͷ��㣡\n");
                    else
                    {
                        DeleteList_DuL(s->prior, &n);
                        printf("ɾ���Ľڵ������Ϊ��%d\n", n);
                    }
                }
                printf("�Ƿ�Ҫ����ɾ���ڵ㣨Y/N��\n");
                while((a=getchar()) != '\n')      //����ch2����Ҫ������ķǷ��ַ�
                    continue;
                ch2 = getchar();
            }
            break;
        case 3:
            TraverseList_DuL(pHead, Visit_Date);
            break;
        default:
            printf("�Ƿ����룬������\n");
            break;
        }

        printf("�Ƿ񷵻����˵�(���밴y)\n");     //�������˵�ѡ��
        while((a=getchar()) != '\n')
            continue;
        scanf("%c", &ch);
        if('Y'!=ch && 'y'!=ch)
            printf("�������\n");
    }
    DestroyList_DuL(&pHead);     //����������̬����Ŀռ��ͷŵ�
    return 0;

}
