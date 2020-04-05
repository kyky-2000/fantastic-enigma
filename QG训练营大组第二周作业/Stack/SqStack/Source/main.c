#include "../Head/SqStack.h"

int main(void)
{
    SqStack * pStack;
    ElemType i, flag, len, len1, len2, val1, val2, val3;
    char ch, ch1, ch2, ch3, ch4, ch5;

    printf("������Ҫ���ɶ���ջ:(���ȡ��λ��Ч�����Ҳ�������ʮ)\n");
    len2 = Draw_Data2();

    while(len2<=0 || len2>=30)      //���û�����ջ���ȣ�
    {
        printf("�Ƿ��������룬�����밴y\n");
        while((ch=getchar()) != '\n')
            continue;
        ch5 = getchar();
        if('Y'==ch5 || 'y'==ch5)
        {
            printf("������:\n");
            len2 = Draw_Data2();
            continue;
        }
        return 0;
    }

    initStack(&pStack, len2);

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

    ch1 = 'Y';

    while('Y'==ch1 || 'y'==ch1)
    {
        ch2 = 'Y';
        ch3 = 'Y';

        flag = Draw_Data2();

        switch(flag)
        {
        case 1:     //��ջ����
            while('Y'==ch2 || 'y'==ch2)
            {
                printf("������Ҫ��ջ��Ԫ��(�����������λ��Ч����)��\n");
                val1 = Draw_Data1();
                if(SUCCESS == pushStack(pStack, val1))
                    printf("��ջ�ɹ���\n");
                else
                    printf("��ջʧ�ܣ�\n");
                printf("�Ƿ�Ҫ������ջԪ�أ�Y/N��\n");
                while((ch=getchar()) != '\n')
                    continue;
                ch2 = getchar();
            }
            if('N'!=ch2 && 'n'!=ch2)
                printf("�Ƿ�����!\n");
            break;
        case 2:        //��ջ����
            while('Y'==ch3 || 'y'==ch3)
            {
                if(SUCCESS == popStack(pStack, &val2))
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
        case 3:         //��ջ����
            if(SUCCESS == stackLength(pStack, &len))
                printf("ջ����Ϊ%d\n", len);
            break;
        case 4:         //��ջ��Ԫ��
            if(SUCCESS == getTopStack(pStack, &val3))
                printf("ջ��Ԫ��Ϊ%d\n", val3);
            break;
        case 5:         //��ջ�Ƿ�Ϊ�գ������Ƿ�鳤��
            if(ERROR == isEmptyStack(pStack))
            {
                printf("ջ����,�Ƿ�Ҫ��ѯջ�ĳ��ȣ����밴Y��\n");
                while((ch=getchar()) != '\n')
                    continue;
                ch4 = getchar();
                if('Y'==ch4 || 'y'==ch4)
                {
                stackLength(pStack, &len1);
                printf("ջ�ĳ���Ϊ%d\n", len1);
                }
            }
            break;
        case 6:         //���ջ
            if(ERROR == clearStack(pStack))
                printf("���ʧ�ܣ�\n");
            break;
        default:        //�Ƿ����봦��
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
    destroyStack(pStack);      //������������ջ
    printf("�������\n");
}
