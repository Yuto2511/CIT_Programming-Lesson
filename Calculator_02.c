#include<stdio.h>

float calculate();

int main(void)
{
    char re;
    
    while(1)
    {
        printf("Ans => %0.4f\n\n", calculate());

        printf("再計算しますか? [Y/n] ");
        scanf("%s", &re);
        if(re == 'n' || re == 'N') break;
    }

    return 0;
}

float calculate()
{
    char sign;
    float sum, num;

    scanf("%f", &sum);
    while(1)
    {
        scanf("%s", &sign);
        // '='を入力するとループを抜ける
        if(sign == '=') break;

        scanf("%f", &num);

        // 四則演算
        switch(sign)
        {
            case '+':
                sum += num;
                break;
            case '-':
                sum -= num;
                break;
            case '*':
                sum *= num;
                break;
            case '/':
                sum /= num;
                break;
            default:
                printf("計算できませんでした　演算子から入力してください\n");
                break;
        }

    }
    
    return sum;
}
