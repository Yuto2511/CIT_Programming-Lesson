#include <stdio.h>

int main(void) {
  /* 20文字の文字列を読み込むためには
     21個の配列の要素が必要です．*/
  char str[21];

  /* 変数は必要に応じて追加してください．*/
  int i = 0;
  char *ptr;
  const int df = 'a'-'A';

  /* 下記で配列 str に文字列を読み込むことができます．
     しかし，20文字を超える長さの文字列が入力されると
     不具合が発生することがあります．
     このままでもいいですが，20文字以内に制限する工夫を
     してもらうと加点になります． */
  printf("20文字以内の文字列を入力してください : ");
  do {
	  str[i] = getchar ();
  } while (str[i++] != 0x0A);

  i = 0;

  /* ここの部分で文字列strを標準出力に表示してください */
  printf("入力された文字 : ");
  do {
	  putchar (str[i]);
  } while (str[i++] != 0x0A);

  i = 0;
  
  /* ここの部分で，
     strの内容に応じて，小文字を大文字に，大文字を
     小文字に変換してください．
     必ずポインタを利用してください．
     文字を大文字や小文字に変換する関数（toupper，tolower）が
     ありますが，これは使わないでください．
  */

  ptr = str;
  while(i++ < 21) {
	  if(*ptr >= 'A' && *ptr <= 'Z') {
		  //printf("oomozi\n");
		  *ptr = *ptr + df;
	  }else if (*ptr >= 'a' && *ptr <= 'z') {
		  //printf("komozi\n");
		  *ptr = *ptr - df;
	  }
	  if(*ptr == 0x0A) break;
	  ptr++;
  }

  i = 0;
  
  /* ここの部分で変換結果を標準出力に表示してください */
  printf("変換結果の文字 : ");
  do {
	  putchar (str[i]);
  } while (str[i++] != 0x0A);


  return 0;
}
