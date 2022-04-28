#include <stdio.h>
#include <math.h>

void	put_answer(int N, int n)
{
	int		i;
	char	str[21];

	i = -1;
	while (++i < N)
	{
		if ((n & 1 << (N - i - 1)) != 0)
			str[i] = ')';
		else
			str[i] = '(';
	}
	str[i] = '\0';
	printf("%s\n", str);
}


int	main(void)
{
	int	N;
	int	NP;
	int	n;
	int	i;
	int	popcount;

	scanf("%d", &N);
	NP = pow(2, N);
	n = -1;
	while (++n < NP)
	{
		i = -1;
		popcount = 0;
		while (++i < N)
		{
			if ((n & 1 << (N - i - 1)) != 0)
				popcount--;
			else
				popcount++;
			if (popcount < 0)
				break;
		}
		//printf("%d , %d\n", n, popcount);
		if (popcount == 0)
			put_answer(N, n);
	}
}
