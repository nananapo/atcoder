#include <stdio.h>

#define LL long long

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	gcd(int a, int b)
{
	int	tmp;

	tmp = a;
	a = min(a, b);
	b = -min(-tmp, -b);
	while (b % a != 0)
	{
		tmp = b;
		b = a;
		a = tmp % a;
	}
	return (a);
}

int	lcm(int a, int b)
{
	int	g;

	g = gcd(a, b);
	return (a * b / g);
}

LL	sum(LL	a, LL N)
{
	LL	d;

	d = N / a * a;
	return ((a + d) * (N / a) / 2);
}

int	main(void)
{
	int	N;
	int	A;
	int	B;

	scanf("%d %d %d", &N, &A, &B);
	printf("%lld\n", sum(1, N) - sum(A, N) - sum(B, N) + sum(lcm(A, B), N));
}
