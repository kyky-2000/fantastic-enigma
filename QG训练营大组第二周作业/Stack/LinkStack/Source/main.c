#include "../head/LinkStack.h"

int main(void)
{
    LinkStack * pStack;
    ElemType i, flag, len, len1, val1, val2, val3;
    char ch, ch1, ch2, ch3, ch4;


    for(i=0; i<35; ++i)       //չʾ�˵�
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("1----��ջԪ��\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("2----��ջԪ��\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("3----��ѯջ�ĳ���\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("4----�õ�ջ��Ԫ��\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("5----��ѯջ�Ƿ�Ϊ��\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("6----���ջ\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");

    initLStack(&pStack);
    ch1 = 'Y';

    while('Y'==ch1 || 'y'==ch1)
    {
        ch2 = 'Y';
        ch3 = 'Y';

        scanf("%d", &flag);

        switch(flag)
        {
        case 1:             //��ջ����
            while('Y'==ch2 || 'y'==ch2)
            {
                printf("������Ҫ��ջ��Ԫ��(�����������λ��Ч����)��\n");
                val1 = Draw_Data(4);
                if(SUCCESS == pushLStack(pStack, val1))
                    printf("��ջ�ɹ���\n");
                else
                    printf("��ջʧ�ܣ�\n");
                printf("�Ƿ�Ҫ������ջԪ�أ�Y/N��");
                while((ch=getchar()) != '\n')
                    continue;
                ch2 = getchar();
            }
            if('N'!=ch2 && 'n'!=ch2)
                printf("�Ƿ�����!\n");
            break;
        case 2:             //��ջ����
            while('Y'==ch3 || 'y'==ch3)
            {
                if(SUCCESS == popLStack(pStack, &val2))
                {
                    printf("��ջ�ɹ�����ջԪ��Ϊ:%d\n", val2);
                }
                printf("�Ƿ�Ҫ������ջԪ�أ�Y/N��\n");
                while((ch=getchar()) != '\n')
                    continue;
                ch3 = getchar();
            }
            if('N'!=ch3 && 'n'!=ch3)
                printf("�Ƿ�����!\n");
            break;
        case 3:           //�鳤��
            if(SUCCESS == LStackLength(pStack, &len))
                printf("ջ����Ϊ%d\n", len);
            break;
        case 4:           //��ջ��Ԫ��
            if(SUCCESS == getTopLStack(pStack, &val3))
                printf("ջ��Ԫ��Ϊ%d\n", val3);
            break;
        case 5:           //��ջ�Ƿ�Ϊ�գ������Ƿ�鳤��
            if(ERROR == isEmptyLStack(pStack))
            {
                printf("ջ����,�Ƿ�Ҫ��ѯջ�ĳ��ȣ����밴Y��\n");
                while((ch=getchar()) != '\n')
                    continue;
                ch4 = getchar();
                if('Y'==ch4 || 'y'==ch4)
                {
                    LStackLength(pStack, &len1);
                    printf("ջ�ĳ���Ϊ%d\n", len1);
                }
            }
            break;
        case 6:           //���ջ
            if(ERROR == clearLStack(pStack))
                printf("���ʧ�ܣ�\n");
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
            printf("���˵���ʾ��1��ջ��2��ջ��3�鳤�ȣ�4��ջ��Ԫ�أ�5���Ƿ�Ϊ�գ�6���ջ��\n");
    }
    destroyLStack(pStack);     //�������������ջ
    printf("�������\n");
}
