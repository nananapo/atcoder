#include <stdio.h>

#define ll long long

int	ctz(ll n)
{
	int	result;

	result = 0;
	while (n != 0 && n % 2 == 0)
	{
		result++;
		n/=2;
	}
	return (result);
}

ll	pow2(int pow)
{
	ll	result;

	result = 1;
	while (pow-- > 0)
		result *= 2;
	return result;
}

int	main(void)
{
	int	N;
	ll	now;
	int	T;
	ll	mask;

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
	printf("%lld", now);
}
