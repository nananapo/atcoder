#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (a * 100 + b <= c * 100 + d)
		printf("Takahashi\n");
	else
		printf("Aoki\n");
}
