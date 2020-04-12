# include "LQueue.h"

int main(void)
{
    LQueue * pLQ;
    int i, flag, len, len1, val1, val2, val3;
    char ch, ch1, ch2, ch3, ch4;
    int * k;
    float * f;
    char * c;


    for(i=0; i<35; ++i)       //չʾ�˵�
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("1----���Ԫ��\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("2----����Ԫ��\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("3----��ѯ�ӵĳ���\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("4----�õ���ͷԪ��\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("5----��ѯ�����Ƿ�Ϊ��\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("6----��ն���\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("7----��������\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    printf("\n");
    printf("������֧�������������ͣ�d---���ͣ�f---�����ͣ�c---�ַ��ͣ�s---�ַ���\n");


    InitLQueue(&pLQ);
    ch1 = 'Y';

    while('Y'==ch1 || 'y'==ch1)
    {
        ch2 = 'Y';
        ch3 = 'Y';

        scanf("%d", &flag);

        switch(flag)
        {
        case 1:             //��Ӳ���
            while('Y'==ch2 || 'y'==ch2)
            {
                printf("��������Ҫ��ӵ���������\n");
                while((ch=getchar()) != '\n')
                    continue;
                scanf("%c", &type);
                printf("��������Ҫ��ӵ�����\n");
                if('d' == type)
                {
                    k = (int *)malloc(sizeof(int));
                    while((ch=getchar()) != '\n')
                        continue;
                    scanf("%d", k);
                    if(TRUE == EnLQueue(pLQ, k))
                    {
                        printf("��ӳɹ�\n");
                        datatype[pLQ->rear->number] = type;
                    }
                    else
                        printf("���ʧ��\n");
                }
                else if('f' == type)
                {
                    f = (float *)malloc(sizeof(float));
                    while((ch=getchar()) != '\n')
                        continue;
                    scanf("%f", f);
                    if(TRUE == EnLQueue(pLQ, f))
                    {
                        printf("��ӳɹ�\n");
                        datatype[pLQ->rear->number] = type;
                    }
                    else
                        printf("���ʧ��\n");
                }
                else if('c' == type)
                {
                    c = (char *)malloc(sizeof(char));
                    while((ch=getchar()) != '\n')
                        continue;
                    scanf("%c", c);
                    if(TRUE == EnLQueue(pLQ, c))
                    {
                        printf("��ӳɹ�\n");
                        datatype[pLQ->rear->number] = type;
                    }
                    else
                        printf("���ʧ��\n");
                }
                else if('s' == type)
                {
                    c = (char*)malloc(sizeof(char) * 15);
                    while((ch=getchar()) != '\n')
                        continue;
                    scanf("%s", c);
                    if(TRUE == EnLQueue(pLQ, c))
                    {
                        printf("��ӳɹ�\n");
                        datatype[pLQ->rear->number] = type;
                    }
                    else
                        printf("���ʧ��\n");
                }
                else
                    printf("�����������������Ч\n");

                printf("�Ƿ�Ҫ�������Ԫ�أ�Y/N��");
                while((ch=getchar()) != '\n')
                    continue;
                ch2 = getchar();
            }
            if('N'!=ch2 && 'n'!=ch2)
                printf("�Ƿ�����!\n");
            break;
        case 2:             //���Ӳ���
            while('Y'==ch3 || 'y'==ch3)
            {
                if(FALSE == DeLQueue(pLQ))
                {
                    printf("����ʧ��\n");
                }
                else
                {
                    printf("Ԫ�س��ӳɹ�\n");
                }
                printf("�Ƿ�Ҫ��������Ԫ�أ�Y/N��\n");
                while((ch=getchar()) != '\n')
                    continue;
                ch3 = getchar();
            }
            if('N'!=ch3 && 'n'!=ch3)
                printf("�Ƿ�����!\n");
            break;
        case 3:           //�鳤��
            len = LengthLQueue(pLQ);
            printf("���г���Ϊ%d\n", len);
            break;
        case 4:
            if(FALSE ==GetHeadLQueue(pLQ, &k))
                break;
            type = datatype[pLQ->front->number];
            if('d' == type)
            {
                GetHeadLQueue(pLQ, &k);
                printf("��ͷԪ��Ϊ%d\n", *k);
            }
            else if('f' == type)
            {
                GetHeadLQueue(pLQ, &f);
                printf("��ͷԪ��Ϊ%.3f\n", *f);
            }
            else if('c' == type)
            {
                GetHeadLQueue(pLQ, &c);
                printf("��ͷԪ��Ϊ%c\n", *c);
            }
            else
            {
                GetHeadLQueue(pLQ, &c);
                printf("��ͷԪ��Ϊ%s\n", c);
            }
            break;
        case 5:           //������Ƿ�Ϊ��
            if(FALSE == IsEmptyLQueue(pLQ))
            {
                printf("���в���,�Ƿ�Ҫ��ѯ���еĳ��ȣ����밴Y��\n");
                while((ch=getchar()) != '\n')
                    continue;
                ch4 = getchar();
                if('Y'==ch4 || 'y'==ch4)
                {
                    len1 = LengthLQueue(pLQ);
                    printf("���еĳ���Ϊ%d\n", len1);
                }
            }
            break;
        case 6:           //��ն���
            ClearLQueue(pLQ);
            printf("������\n");
            break;
        case 7:
            TraverseLQueue(pLQ, &LPrint);
            break;
        default:
            printf("�Ƿ�����, �����ԣ�\n");
            break;
        }
        printf("�Ƿ�Ҫ�������˵������밴Y��\n");
        while((ch=getchar()) != '\n')
            continue;
        ch1 = getchar();
        if('y'==ch1 || 'Y'==ch1)
            printf("���˵���ʾ��1��ӣ�2���ӣ�3�鳤�ȣ�4���ͷԪ�أ�5���Ƿ�Ϊ�գ�6��ն��У�7�������У�\n");
    }
    DestoryLQueue(pLQ);     //������������ٶ���
    printf("�������\n");
}
