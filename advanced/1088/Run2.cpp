#include <cstdio>

int gcd(int a, int b)
{
	if (a == 0 || b == 0) return a > b ? a : b;
	for (int t; t = a % b; a = b, b = t);
	return b;
}

void simplify(int &a, int &b)
{
	int x = gcd(a<0 ? -a : a, b);
	a /= x, b /= x; 
}

void f(int a, int b)
{
	if (b == 0) { printf("Inf"); return; }

	if (b < 0) a = -a, b = -b;
	simplify(a, b);
	bool flag = 0;
	if (a < 0) a = -a, flag = 1;

	if (flag) printf("(-");
	if (a % b == 0) printf("%d", a / b);
	else if (a < b) printf("%d/%d", a, b);
	else printf("%d %d/%d", a / b, a % b, b);
	if (flag) printf(")");
}

int main2()
{
	int a1, b1, a2, b2; scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
	f(a1, b1); printf(" + "); f(a2, b2); printf(" = "); f(a1*b2+a2*b1, b1*b2); printf("\n");
	f(a1, b1); printf(" - "); f(a2, b2); printf(" = "); f(a1*b2-a2*b1, b1*b2); printf("\n");
	f(a1, b1); printf(" * "); f(a2, b2); printf(" = "); f(a1*a2, b1*b2); printf("\n");
	f(a1, b1); printf(" / "); f(a2, b2); printf(" = "); f(a1*b2, a2*b1); printf("\n");
	return 0;
}