#include <stdio.h>
#include <math.h>

#define LL long long

int	main(void)
{
	LL	a;
	LL	b;
	LL	c;

	scanf("%lld %lld %lld", &a, &b, &c);
	if (a < powl(c, b))
		printf("Yes\n");
	else
		printf("No\n");
}
