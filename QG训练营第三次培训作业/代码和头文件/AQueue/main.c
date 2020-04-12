# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include "AQueue.h"

int main(void)
{
    AQueue * pAQ;
    int i, flag, len, len1, val1, val2, val3;
    char ch, ch1, ch2, ch3, ch4;
    int * k;
    float * f;
    char * c;


    for(i=0; i<35; ++i)       //展示菜单
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("1----入队元素\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("2----出队元素\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("3----查询队的长度\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("4----得到队头元素\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("5----查询队列是否为空\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("6----查询队列是否已满\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("7----清空队列\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    for(i=0; i<6; ++i)
        printf("\t");
    printf("8----遍历队列\n");
    for(i=0; i<35; ++i)
        printf("***");
    printf("\n");
    printf("\n");
    printf("本队列支持四种数据类型：d---整型，s---字符串，f---浮点型，c---字符型\n");

    InitAQueue(&pAQ);
    ch1 = 'Y';

    while('Y'==ch1 || 'y'==ch1)
    {
        ch2 = 'Y';
        ch3 = 'Y';

        scanf("%d", &flag);

        switch(flag)
        {
        case 1:             //入队操作
            while('Y'==ch2 || 'y'==ch2)
            {
                printf("请输入您要入队的数据类型\n");
                while((ch=getchar()) != '\n')
                    continue;
                scanf("%c", &type);
                if('d'==type || 'f'==type || 'c'==type || 's'==type)
                    printf("请输入您要入队的数据\n");
                if('d' == type)
                {
                    k = (int *)malloc(sizeof(int));
                    datatype[pAQ->rear] = type;
                    while((ch=getchar()) != '\n')
                        continue;
                    scanf("%d", k);
                    if(TRUE == EnAQueue(pAQ, k))
                        printf("入队成功\n");
                    else
                        printf("入队失败\n");
                }
                else if('f' == type)
                {
                    f = (float *)malloc(sizeof(float));
                    datatype[pAQ->rear] = type;
                    while((ch=getchar()) != '\n')
                        continue;
                    scanf("%f", f);
                    if(TRUE == EnAQueue(pAQ, f))
                        printf("入队成功\n");
                    else
                        printf("入队失败\n");
                }
                else if('c' == type)
                {
                    c = (char *)malloc(sizeof(char));
                    datatype[pAQ->rear] = type;
                    while((ch=getchar()) != '\n')
                        continue;
                    scanf("%c", c);
                    if(TRUE == EnAQueue(pAQ, c))
                        printf("入队成功\n");
                    else
                        printf("入队失败\n");
                }
                else if('s' == type)
                {
                    c = (char*)malloc(sizeof(char) * 15);
                    datatype[pAQ->rear] = type;
                    while((ch=getchar()) != '\n')
                        continue;
                    scanf("%s", c);
                    if(TRUE == EnAQueue(pAQ, c))
                        printf("入队成功\n");
                    else
                        printf("入队失败\n");
                }
                else
                    printf("您输入的数据类型无效\n");

                printf("是否还要继续入队元素（Y/N）");
                while((ch=getchar()) != '\n')
                    continue;
                ch2 = getchar();
            }
            if('N'!=ch2 && 'n'!=ch2)
                printf("非法输入!\n");
            break;
        case 2:             //出队操作
            while('Y'==ch3 || 'y'==ch3)
            {
                if(FALSE == DeAQueue(pAQ))
                {
                    printf("出队失败\n");
                }
                printf("是否还要继续出队元素（Y/N）\n");
                while((ch=getchar()) != '\n')
                    continue;
                ch3 = getchar();
            }
            if('N'!=ch3 && 'n'!=ch3)
                printf("非法输入!\n");
            break;
        case 3:           //查长度
            len = LengthAQueue(pAQ);
            printf("队列长度为%d\n", len);
            break;
        case 4:
            if(FALSE ==GetHeadAQueue(pAQ, &k))
                break;
            type = datatype[pAQ->front];
            if('d' == type)
            {
                GetHeadAQueue(pAQ, &k);
                printf("队头元素为%d\n", *k);
            }
            else if('f' == type)
            {
                GetHeadAQueue(pAQ, &f);
                printf("队头元素为%f\n", *f);
            }
            else if('c' == type)
            {
                GetHeadAQueue(pAQ, &c);
                printf("队头元素为%c\n", *c);
            }
            else
            {
                GetHeadAQueue(pAQ, &c);
                printf("队头元素为%s\n", c);
            }
            break;
        case 5:           //查队列是否为空
            if(FALSE == IsEmptyAQueue(pAQ))
            {
                printf("队列不空,是否要查询队列的长度（是请按Y）\n");
                while((ch=getchar()) != '\n')
                    continue;
                ch4 = getchar();
                if('Y'==ch4 || 'y'==ch4)
                {
                    len1 = LengthAQueue(pAQ);
                    printf("队列的长度为%d\n", len1);
                }
            }
            break;
        case 6:
            if(FALSE == IsFullAQueue(pAQ))
                printf("队列未满\n");
            break;
        case 7:           //清空队列
            ClearAQueue(pAQ);
            break;
        case 8:
            TraverseAQueue(pAQ, &APrint);
            break;
        default:
            printf("非法输入, 请重试！\n");
            break;
        }
        printf("是否要返回主菜单（是请按Y）\n");
        while((ch=getchar()) != '\n')
            continue;
        ch1 = getchar();
        if('y'==ch1 || 'Y'==ch1)
            printf("（菜单提示：1入队，2出队，3查长度，4查队头元素，5查是否为空，6查是否已满，7清空队列，8遍历队列）\n");
    }
    DestoryAQueue(pAQ);     //程序结束，销毁队列
    printf("程序结束\n");
}
