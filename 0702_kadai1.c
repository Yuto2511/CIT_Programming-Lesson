#include <stdio.h>
#include <math.h>

int dist(double a, double b, double c, double d);

int main(void) {
	double x[3], y[3];
	double a, b, c, s;

	for(int i = 0; i < 3; i ++) {
		printf("X%d = ", i);
		scanf("%lf", &x[i]);
		printf("Y%d = ", i);
		scanf("%lf", &y[i]);
	}

	a = dist(x[0], y[0], x[1], y[1]);
	b = dist(x[1], y[1], x[2], y[2]);
	c = dist(x[2], y[2], x[0], y[0]);

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

	printf("%lf, %lf, %lf\n",a,b,c);
	if(a > b + c - 0.0000001 && a < b + c + 0.000001) printf("三角形を形作りません。\n");
	else if(a*a > b*b + c*c + 0.000001) printf("この三角形は鈍角三角形です。\n");
	else if(a*a < b*b + c*c - 0.000001) printf("この三角形は鋭角三角形です。\n");
	else printf("この三角形は直角三角形です。\n");

	return 0;
}

int dist(double a, double b, double c, double d) {
	double e;

	e = (a-c)*(a-c) + (b-d)*(b-d);

	return sqrt(e);
}
