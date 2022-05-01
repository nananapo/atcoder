#include <stdio.h>

#define LL long long

int	ctz(LL n)
{
	int	result;

	result = 0;
	while (n != 0 && n % 2 == 0)
	{
		result++;
		n /= 2;
	}
	return (result);
}

LL	pow2(int pow)
{
	LL	result;

	result = 1;
	while (pow-- > 0)
		result *= 2;
	return (result);
}

int	main(void)
{
	int	N;
	LL	now;
	int	T;
	LL	mask;

	scanf("%d", &N);
	now = 0;
	while (N-- > 0)
	{
		scanf("%d", &T);
		mask = pow2(T);
		now = (now + mask) / mask * mask;
		if (ctz(now) != T)
			now += mask;
	}
	printf("%LLd", now);
}
