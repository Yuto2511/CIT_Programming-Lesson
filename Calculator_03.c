#include<stdio.h>
#include<math.h>

float four_arithmetic_operations(float);
float trigonometric_function(float);
float calcurator(float, float, char);
float input_trigonometric();

// 整数 or 小数
float four_arithmetic_operations(float total)
{
    char sign;
    float num;

    printf("%0.1f\n", total);
    scanf("%s", &sign);
    scanf("%f", &num);
    
    return calcurator(total, num, sign);
}


// 三角関数
float trigonometric_function(float total)
{
    char sign;
    float num;

    printf("%0.1f\n", total);
    scanf("%s", &sign);
    num = input_trigonometric();
    
    return calcurator(total, num, sign);    
}


// 計算
float calcurator(float a, float b, char operator)
{
    switch(operator)
    {
        case '+':
            printf("%0.1f + %0.1f = %0.1f\n", a, b, a+b);
            a += b;
            break;
        case '-':
            printf("%0.1f - %0.1f = %0.1f\n", a, b, a-b);
            a -= b;
            break;
        case '*':
            printf("%0.1f * %0.1f = %0.1f\n", a, b, a*b);
            a *= b;
            break;
        case '/':
            printf("%0.1f / %0.1f = %0.1f\n", a, b, a/b);
            a /= b;
            break;
        default:
            printf("計算できませんでした\n");
            break;
    }
    return a;
}


//　三角関数の入力
float input_trigonometric()
{
    char trigo;
    double angle;
    float rad;

    while(1)
    {
        printf("正弦[s] or 余弦[c] or 正接[t] ?  => ");
        scanf("%s", &trigo);
        if(trigo == 's'){
            printf("sin ");
            scanf("%lf", &angle);
            rad = sin(M_PI * angle /180);
            return rad;
            break;
        }
        else if(trigo == 'c'){
            printf("cos ");
            scanf("%lf", &angle);
            rad = cos(M_PI * angle /180);
            return rad;
            break;
        }
        else if(trigo == 't'){
            printf("tan ");
            scanf("%lf", &angle);
            rad = tan(M_PI * angle /180);
            return rad;
            break;
        }
        else printf("関数を選択してください\n");
    }
}


// メインループ
int main(void)
{
    char re, mode;
    float ans = 0;
    
    while(1)
    {
        // 初期値代入
        while(1)
        {
            printf("初期値入力：整数[i] or 三角関数[t] or 計算終了[e] => ");
            scanf("%s", &mode);
            if(mode == 'i' || mode == 'I'){ scanf("%f", &ans); break; }
            else if(mode == 't' || mode == 'T'){ ans = input_trigonometric(); break; }
            else if(mode == 'e' || mode == 'E') break;
            else printf("モードを選んでください\n");
        }
        // 計算終了
        if(mode == 'e' || mode == 'E') break;

        // 計算方法か結果出力の選択
        while(1)
        {
            printf("四則演算[f] or 三角関数[t] or 計算結果[a]  => ");
            scanf("%s", &mode);
            if(mode == 'f' || mode == 'F') ans = four_arithmetic_operations(ans);
            else if(mode == 't' || mode == 'T') ans = trigonometric_function(ans);
            else if(mode == 'a' || mode == 'A') break;
            else printf("モードを選択してください\n");
        }
        // 結果出力
        printf("\nAns => %0.4f\n\n", ans);

        // 再計算
        while(1)
        {
            printf("再計算しますか? [Y/n] ");
            scanf("%s", &re);
            if(re == 'n' || re == 'N' || re == 'y' || re == 'Y') break;
        }
        // 計算終了
        if(re == 'n' || re == 'N') break;
    }

    return 0;
}