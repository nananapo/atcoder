#include <stdio.h>
#include <stdlib.h>

void	answer(int i)
{
	printf("%d\n", i);
	exit(0);
}

int	candiv2(int x)
{
	x = x + 1;
	return (x / 2);
}

int	main(void)
{
	int	H;
	int	W;

	scanf("%d%d", &H, &W);
	if (H == 1 || W == 1)
		printf("%d\n", H * W);
	else
		answer(candiv2(W) * candiv2(H));
}
