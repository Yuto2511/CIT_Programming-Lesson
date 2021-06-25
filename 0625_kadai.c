#include <stdio.h>

int main(void) {
  char str[21];
  int i = 0;
  char *ptr;
  const int df = 'a'-'A';
	
  printf("20文字以内の文字列を入力してください : ");
  do {
	  str[i] = getchar ();
  } while (str[i++] != 0x0A);

  i = 0;

  printf("入力された文字 : ");
  do {
	  putchar (str[i]);
  } while (str[i++] != 0x0A);

  i = 0;
	
  ptr = str;
  while(i++ < 21) {
	  if(*ptr >= 'A' && *ptr <= 'Z') {
		  //printf("oomoji\n");
		  *ptr = *ptr + df;
	  }else if (*ptr >= 'a' && *ptr <= 'z') {
		  //printf("komoji\n");
		  *ptr = *ptr - df;
	  }
	  if(*ptr == 0x0A) break;
	  ptr++;
  }

  i = 0;
  
  printf("変換結果の文字 : ");
  do {
	  putchar (str[i]);
  } while (str[i++] != 0x0A);


  return 0;
}
