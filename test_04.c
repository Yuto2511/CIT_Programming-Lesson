#include<stdio.h>

int frac(int);
int comb(int,int);

int main(void) {
        int c, i ,n;

        printf("input integer n : ");
        scanf("%d", &n);

        printf("(a + b)%d = ", n);
        for(i = 0; i <= n; i ++) {
                c = comb(n ,i);

                if(c > 1) printf("%d ", c);
                if(n - i > 0) printf("a%d ", n-i);
                if(i > 0) printf("b%d ", i);
                if(i < n) printf("+ ");
        }
        printf("\n");

        return 0;
}

int frac(int n){
        int i, r = 1;

        for(i = 0; i < n; i ++){
                r = r * (n - i);

        }
        return r;

}

int comb(int n, int k) {
        int nume = frac(n);
        int denom = frac(k) * frac(n - k);
        int ret = nume / denom;
        return ret;
}
