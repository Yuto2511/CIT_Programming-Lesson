#include <stdio.h>

int strcmp(char *str1, char *str2);
void dictsort (char **, int);

int main(void) {
	char *flowers[] = {"cherry", "ume", "tulip", "dandelion", "peach",
	       	"marigold", "azalea", "orchid", "lily", "carnation", 
		"pansy", "hyacinth", "iris"};
	int total = sizeof(flowers) / sizeof(flowers[0]), p = 0;
	
	dictsort(flowers, total);

	for(int j = 0; j < total-1; j ++) {
		printf("%s\n", flowers[j]);
	}
	
	return 0;
}

void dictsort (char **x, int i) {
	int flg = 0;
	char *s;
	for (int ar1 = 0; ar1 < i; ar1++) {
		for (int ar2 = i-1; ar2 > ar1; ar2--) {
			flg = strcmp(x[ar1], x[ar2]);
			//printf("%d\n", flg);
			if(flg == -1){
				s = x[ar2];
				x[ar2] = x[ar1];
				x[ar1] = s;
			}
		}
	}

	return;
}

int strcmp(char *str1, char *str2) {
	int flg = 0, j = 0;
	while(str1[j+1] != 0x00 && str2[j+1] != 0x00) {
		if(str1[j] == str2[j]) {
			flg = 0;
			j ++;
		}
		else if(str1[j] > str2[j]) {
			flg = -1;
			break;
		}
		else{
			flg = 1;
			break;
		}
	}

	return flg;
}
