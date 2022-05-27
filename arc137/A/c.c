#include <stdio.h>

#define LL long long

static LL	g_L;
static LL	g_R;

LL	max(LL a, LL b)
{
	if (a > b)
		return (a);
	return (b);
}

LL	gcd(LL a, LL b)
{
	LL	tmp;

	tmp = a;
	a = max(a, b);
	b = -max(-tmp, -b);
	while (a % b != 0)
	{
		tmp = a;
		a = b;
		b = tmp % b;
	}
	return (b);
}

int	main(void)
{
	LL	l;
	LL	r;
	LL	answer;

	scanf("%lld %lld", &g_L, &g_R);
	answer = 0;
	l = g_L;
	while (l < g_L + 1501 && l < g_R)
	{
		r = g_R;
		while (r > g_R - 1501 && r > l && r - l > answer)
		{
			if (gcd(l, r) == 1)
				answer = max(answer, r - l);
			r--;
		}
		l++;
	}
	printf("%lld\n", answer);
}
