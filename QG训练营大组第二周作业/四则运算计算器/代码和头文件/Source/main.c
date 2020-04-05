# include "../head/RPN.h"

/*
总结：
    本程序只支持进行加减乘除的运算
    当输入除加减乘除和正常数字以外的字符时会被自动过滤掉，可能导致运算结果异常
    程序的空间复杂度过高问题当前觉得无能为力，网上的程序看了好久还是觉得不是很懂，目前靠自身只能做到如此
    目前能力完成这些功能已经耗费了不少心力，又还有其他东西要学习，就先如此，其他功能以后再继续完善
*/
int main()
{
    Stack *pS;
    DStack *DpS;
    int i, j, n = 0;
    double val, val1, val2;
    char ch, s[50];
    char a[20][8];
    double * d = (double *)malloc(sizeof(double) * 20);

    pS = Init_Stack1();
    DpS = Init_Stack2();
    printf("本程序只进行四则运算，输入除加减乘除四种预算符和正常数字以外的字符时会被自动过滤掉\n");
    scanf("%s", s);
    for(i=0; s[i]!='\0'; ++i)    //此处功能为过滤用户的非法输入，会将出正常数据及四则运算的运算符之外的东西全部过滤的掉
    {                            //再计算剩余的表达式的值
        if(0 != isdigit(s[i]))
        {
            j = 0;
            while(0!=isdigit(s[i]) || '.'==s[i]) //辨别字符串是否为浮点型数据
            {
                a[n][j++] = s[i++];
            }
            a[n++][j] = '\0';
            i--;
        }
        else if('('==s[i] || ')'==s[i] || '+'==s[i] || '-'==s[i] //辨别字符是否为运算符或括号
                    || '*'==s[i] || '/'==s[i])
        {
            a[n][0] = s[i];
            a[n++][1] = '\0';
        }
    }

    for(i=0, j=0; i<n; ++i)     //此处运用栈的知识将中缀表达式转化为后缀表达式
    {
        if(1 == isdigit(a[i][0]))   //是数据直接进入表达式
        {
            d[j++] = atof(a[i]);
        }
        else if(')' == a[i][0])     //遇到右括号将栈里的运算符出栈进入表达式，直到遇到左括号为止，并将左括号出栈，不进入表达式
        {
            while('(' != getTop(pS))
                d[j++] = pop(pS);
            pop(pS);
        }
        else if('(' == a[i][0])     //左括号直接进入表达式
            push(pS, a[i][0]);
        else if('+'==a[i][0] || '-'==a[i][0])  //'+', '-'运算符优先级较低，将栈中运算符出栈进入表达式，直到栈为空或遇到左括号
        {
            while(0==IsEmpty(pS) && getTop(pS)!='(')
                d[j++] = pop(pS);
            push(pS, a[i][0]);
        }
        else
        {
            while('/'==getTop(pS) || '*'==getTop(pS))   //若栈中运算符优先级较低则直接入栈，否则将运算符出栈进入表达式
            {                                           //直到出现优先级较低的运算符
                d[j++] = pop(pS);
            }
            push(pS, a[i][0]);
        }
    }
    while(0 == IsEmpty(pS))        //最终将栈中剩余的表达式全都出栈进入表达式
        d[j++] = pop(pS);

    for(i=0; i<j; ++i)
    {                               //此处运用另外一个栈将后缀表达式的结果算出来
        if('+' == d[i])             //原理：数据直接进栈，遇到运算符将栈顶的两个数据拉出运算再将结果放回，直到得出最终答案，将其出栈输出
        {
            val1 = Dpop(DpS);
            val2 = Dpop(DpS);
            Dpush(DpS, val1+val2);
        }
        else if('-' == d[i])
        {
            val1 = Dpop(DpS);
            val2 = Dpop(DpS);
            Dpush(DpS, val2-val1);
        }
        else if('*' == d[i])
        {
            val1 = Dpop(DpS);
            val2 = Dpop(DpS);
            Dpush(DpS, val2*val1);
        }
        else if('/' == d[i])
        {
            val1 = Dpop(DpS);
            val2 = Dpop(DpS);
            Dpush(DpS, val2/val1);
        }
        else
        {
            Dpush(DpS, d[i]);
        }
    }
    val = Dpop(DpS);
    printf("%lf", val);

    return 0;

}
