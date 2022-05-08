#include <stdio.h>

void	putline(int is_white, int N, int A, int B)
{
	int	i;
	int	j;
	int	k;
	int	f;

	i = -1;
	f = is_white;
	while (++i < A)
	{
		j = -1;
		while (++j < N)
		{
			k = -1;
			while (++k < B)
			{
				if (is_white)
					printf(".");
				else
					printf("#");
			}
			is_white = !is_white;
		}
		is_white = f;
		printf("\n");
	}
}

int	main(void)
{
	int	N;
	int	A;
	int	B;
	int	i;

	scanf("%d %d %d", &N, &A, &B);
	i = -1;
	while (++i < N)
		putline(i % 2 == 0, N, A, B);
}
