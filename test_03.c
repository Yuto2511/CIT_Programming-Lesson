#include<stdio.h>

int main(void)  {
        int b[32];
        int i, n;

        printf("input integer n : ");
        scanf("%d", &n);

        for(i = 0; i < 32; i++) {
                if((n & (1 << i)) != 0) b[i] = 1;
                else b[i] = 0;
        }

        for(i = 31; i >= 0; i --){
        else{
                printf("%d", b[i]);
                if(i % 4 == 0) putchar(' ');
        }
        printf("\n");

        return 0;

}
