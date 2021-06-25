#include <stdio.h>

int main(void) {
  int i, j, s, x[10];

  for (i = 0; i < 10; i++) {
    scanf("%d", &x[i]);
    printf("%d\n", x[i]);
  }

  /* x をソートする */
  for (i = 0; i < 10; i ++) {
	  for (j = 0; j <10; j ++) {
		  if (x[i] < x[j]){
			  s = x[i];
			  x[i] = x[j];
			  x[j] = s;
		  }
	  }
  }
  /* x を表示する */
  for (i = 0; i < 9; i ++) {
	  printf("%d, ", x[i]);
  }
  printf("%d\n", x[9]);

  return 0;
}
