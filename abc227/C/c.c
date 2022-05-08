#include <stdio.h>

#define LL long long

static LL	g_N;

int	main(void)
{
	LL	a;
	LL	b;
	LL	c;
	LL	answer;

	scanf("%lld", &g_N);
	answer = 0;
	a = 1;
	while (a * a * a <= g_N && a * a * a > 0)
	{
		b = a;
		while (a * b * b <= g_N && a * b * b > 0)
		{
			answer = answer + (g_N / a / b) - b + 1;
			b += 1;
		}
		a += 1;
	}
	printf("%lld\n", answer);
}
