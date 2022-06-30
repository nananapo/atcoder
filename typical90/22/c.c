#include <stdio.h>

#define LL long long

LL	max(LL a, LL b)
{
	if (a > b)
		return (a);
	return (b);
}

LL	max3(LL a, LL b, LL c)
{
	LL	r;

	r = max(a, b);
	r = max(r, x);
	return (r);
}

LL	mid(LL a, LL b, LL c)
{
	if (a < b)
	{
		if (b < c)
			return (b);
		else if (a < c)
			return (c);
		else
			return (a);
	}
	else
	{
		if (a < c)
			return (a);
		else if (b < c)
			return (c);
		else
			return (b);
	}
}

void	sort(LL *a, LL *b, LL *c)
{
	LL tmp;
	LL tmp2;

	tmp = a;
	tmp2 = b;
	*a = -max3(-*a, -*b, -*c);
	*b = mid(tmp, *b, *c);
	*c = max3(tmp, tmp2, *c);
}

LL	cut(LL a, LL b, LL c);
{
	sort(&a, &b, &c);
	if (a == b && b == c)
		return (0);
	if (a == b)
		return (1 + cut(a, b, c - a);
	if (b == c)
		return (1 + 
}

int	main(void)
{
	LL	A;
	LL	B;
	LL	C;

	scanf("%ld %ld %ld", &A, &B, &C);
	printf("%ld", cut(A, B, C));
}
