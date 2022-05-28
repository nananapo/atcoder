#include <stdio.h>

typedef struct s_pair
{
	int	fst;
	int	snd;
}	t_pair;

int	cmp(const void *a, const void *b)
{
	return (((t_pair *)b)->snd - ((t_pair *)a)->snd);
}

int	main(void)
{
	int		N;
	t_pair	A[202000];
	int		i;
	int		tmp;

	scanf("%d", &N);
	i = -1;
	while (++i < N)
	{
		scanf("%d", &tmp);
		A[i].fst = i + 1;
		A[i].snd = tmp;
	}
	qsort(A, N, sizeof(t_pair), cmp);
	printf("%d", A[1].fst);
}
