#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void){
    char numc[255];
    double numf = 0;
    double sum = 0;
    char cal[0];
    double rad;

    printf("足算：+ 引算：- 掛算：* 割算：/ 円周率：p sin：s cos：c tan：t\n");
    printf("例) 2 Enter\n");
    printf("    + Enter\n");
    printf("    3 Enter\n");
    printf("    = Enter\n");
    printf("    Ans => 5\n");

    while(1){
        scanf("%s", numc);
        if(numc[0] == 0x3d) break;
        else if(numc[0] == 0x70 || numc[0] == 0x50) numf = M_PI;
        else if(numc[0] == 0x73 || numc[0] == 0x53){
            printf("sin ");
            scanf("%lf", &rad);
            numf = sin(M_PI * rad / 180);
        }
        else if(numc[0] == 0x63 || numc[0] == 0x43){
            printf("cos ");
            scanf("%lf", &rad);
            numf = cos(M_PI * rad / 180);
        }
        else if(numc[0] == 0x74 || numc[0] == 0x54){
            printf("tan ");
            scanf("%lf", &rad);
            numf = tan(M_PI * rad / 180);
        }
        else numf = atof(numc);

        switch(cal[0]){
            case 0:
                sum += numf;
                break;
            case '+':
                sum += numf;
                break;
            case '-':
                sum -= numf;
                break;
            case '*':
                sum *= numf;
                break;
            case '/':
                sum /= numf;
                break;
            Default:
                break;
        }
        rad = 0;
        //printf("cal = %s\n",cal);
        //printf("MC => %0.1f\n", sum);
        cal[0] = '\0';
        strcat(cal, numc);

    }
    printf("Ans => %0.4f\n", sum);

    return 0;
}

