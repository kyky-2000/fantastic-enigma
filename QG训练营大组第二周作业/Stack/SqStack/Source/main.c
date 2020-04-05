#include "../Head/SqStack.h"

int main(void)
{
    SqStack * pStack;
    ElemType i, flag, len, len1, len2, val1, val2, val3;
    char ch, ch1, ch2, ch3, ch4, ch5;

    printf("请问需要生成多大的栈:(最多取两位有效数字且不大于三十)\n");
    len2 = Draw_Data2();

    while(len2<=0 || len2>=30)      //让用户输入栈长度，
    {
        printf("是否重新输入，重试请按y\n");
        while((ch=getchar()) != '\n')
            continue;
        ch5 = getchar();
        if('Y'==ch5 || 'y'==ch5)
        {
            printf("请输入:\n");
            len2 = Draw_Data2();
            continue;
        }
        return 0;
    }

    initStack(&pStack, len2);

    for(i=0; i<35; ++i)       //展示菜单
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("1----入栈元素\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("2----出栈元素\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("3----查询栈的长度\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("4----得到栈顶元素\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("5----查询栈是否为空\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("6----清空栈\n");
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
        case 1:     //入栈操作
            while('Y'==ch2 || 'y'==ch2)
            {
                printf("请输入要入栈的元素(最多允许有四位有效数字)：\n");
                val1 = Draw_Data1();
                if(SUCCESS == pushStack(pStack, val1))
                    printf("入栈成功！\n");
                else
                    printf("入栈失败！\n");
                printf("是否还要继续入栈元素（Y/N）\n");
                while((ch=getchar()) != '\n')
                    continue;
                ch2 = getchar();
            }
            if('N'!=ch2 && 'n'!=ch2)
                printf("非法输入!\n");
            break;
        case 2:        //出栈操作
            while('Y'==ch3 || 'y'==ch3)
            {
                if(SUCCESS == popStack(pStack, &val2))
                {
                    printf("出栈成功，出栈元素为:%d\n", val2);
                }
                printf("是否还要继续入栈元素（Y/N）\n");
                while((ch=getchar()) != '\n')
                    continue;
                ch3 = getchar();
            }
            if('N'!=ch3 && 'n'!=ch3)
                printf("非法输入!\n");
            break;
        case 3:         //查栈长度
            if(SUCCESS == stackLength(pStack, &len))
                printf("栈长度为%d\n", len);
            break;
        case 4:         //查栈顶元素
            if(SUCCESS == getTopStack(pStack, &val3))
                printf("栈顶元素为%d\n", val3);
            break;
        case 5:         //查栈是否为空，不空是否查长度
            if(ERROR == isEmptyStack(pStack))
            {
                printf("栈不空,是否要查询栈的长度（是请按Y）\n");
                while((ch=getchar()) != '\n')
                    continue;
                ch4 = getchar();
                if('Y'==ch4 || 'y'==ch4)
                {
                stackLength(pStack, &len1);
                printf("栈的长度为%d\n", len1);
                }
            }
            break;
        case 6:         //清空栈
            if(ERROR == clearStack(pStack))
                printf("清空失败！\n");
            break;
        default:        //非法输入处理
            printf("非法输入, 请重试！\n");
            break;
        }
        printf("是否要返回主菜单（是请按Y）\n");
        while((ch=getchar()) != '\n')
            continue;
        ch1 = getchar();
        if('y'==ch1 || 'Y'==ch1)
            printf("（菜单提示：1入栈，2出栈，3查长度，4查栈顶元素，5查是否为空，6清空栈）\n");
    }
    destroyStack(pStack);      //程序结束，清空栈
    printf("程序结束\n");
}
