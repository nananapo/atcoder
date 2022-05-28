#include <stdio.h>

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	tmp;

	scanf("%d %d %d", &a, &b, &c);
	tmp = a;
	a = min(a, c);
	c = max(tmp, c);
	if (a <= b && b <= c)
		printf("Yes\n");
	else
		printf("No\n");
}
