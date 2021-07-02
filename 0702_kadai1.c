// 07/02 kadai1 三角形の種類を判定
#include <stdio.h>
#include <math.h>

//プロトタイプ宣言
int dist(double a, double b, double c, double d);

int main(void) {
	double x[3], y[3];
	double a, b, c, s=0;

	//座標を入力
	for(int i = 0; i < 3; i ++) {
		printf("X%d = ", i);
		scanf("%lf", &x[i]);
		printf("Y%d = ", i);
		scanf("%lf", &y[i]);
	}

	//dist()２点間の距離を求める
	a = dist(x[0], y[0], x[1], y[1]);
	b = dist(x[1], y[1], x[2], y[2]);
	c = dist(x[2], y[2], x[0], y[0]);

	//aを最大の長さとする
	if(b > a && b > c) {
		s = b;
		b = a;
		a = s;
	}
	if(c > a && c > b) {
		s = c;
		c = a;
		a = s;
	}

	//三角形の種類を判定
	printf("%lf, %lf, %lf\n",a,b,c);
	if(sqrt(a) == sqrt(b) + sqrt(c)) printf("三角形を形作りません。\n");
	else if(a == b + c) printf("この三角形は直角三角形です。\n");
	else if(a > b + c) printf("この三角形は鈍角三角形です。\n");
	else if(a < b + c) printf("この三角形は鋭角三角形です。\n");

	return 0;
}

//２点間距離を求める関数、但し戻り値は二乗の形で出力
int dist(double a, double b, double c, double d) {
	double e;

	e = (a-c)*(a-c) + (b-d)*(b-d);

	return e;
}
