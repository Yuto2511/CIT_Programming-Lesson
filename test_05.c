//大文字小文字問わず「aBcdDcbA]と入力すればOK
//「fsahlksif」と不規則だとNG
#include<stdio.h>
#include<string.h>

void flip(char *, char *);
char lower(char);
int pali(char *);

int main(void) {
        char str[256];

        printf("input string : ");
        scanf("%255s", str);

        if(pali(str)) {
                printf("OK\n");
        } else {
                printf("NG\n");
        }

        return 0;
}

void flip(char *src, char *dist) {
        char *ps, *pd;
        int i, n = strlen(src);

        ps = src;
        pd = dist + n;
        *pd = '\0';
        pd--;

        while(*ps != '\0') {
                *pd = *ps;
                ps ++;
                pd --;

        }

        return;

}


//大文字を小文字に変換
char lower(char c){
        if(c >= 'A' && c < 'Z') {
                c += 'a' - 'A';
        }
        return c;
}

int pali(char *str) {
        char strf[256];
        char *ps, *pf;
        int r = 1;

        flip(str, strf);
        ps = str;
        pf = strf;
        while(*ps != '\0') {
                //0x20は空白のこと
                //したの2行はあっているか微妙
                if(*ps == 0x20) ps++;
                if(*pf == 0x20) pf++;
                if(lower(*ps) != lower(*pf)) {
                        r = 0;
                        break;
                }
                ps++;
                pf++;
        }

        return r;
}
