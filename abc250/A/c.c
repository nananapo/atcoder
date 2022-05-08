#include <stdio.h>

int	main(void)
{
	int	H;
	int	W;
	int	a;
	int	b;
	int	r;

	scanf("%d %d %d %d", &H, &W, &a, &b);
	r = 4;
	if (a == 1)
		r--;
	if (a == H)
		r--;
	if (b == 1)
		r--;
	if (b == W)
		r--;
	printf("%d\n", r);
}
