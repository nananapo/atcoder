#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N_MAX 101000

static int	g_primes[101000];
static int	g_pcount = 0;

static int	g_N;
static int	g_M;
static int	g_A[N_MAX];

static int	g_factors[N_MAX];

static int	g_answers[N_MAX];
static int	g_acount;

int	is_prime(int n)
{
	int	i;

	if (n % 2 == 0)
		return (n == 2);
	i = 3;
	while (i < n && i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

void	construct_factor(void)
{
	int	i;
	int	j;
	int	a;

	i = -1;
	while (++i < g_N)
	{
		a = g_A[i];
		j = 2;
		while (j * j <= a)
		{
			if (a % j != 0)
			{
				j++;
				continue ;
			}
			g_factors[j] = 1;
			while (a % j == 0)
				a /= j;
			j++;
		}
		if (a != 1)
			g_factors[a] = 1;
	}
}

void	construct_primes(void)
{
	int	i;

	i = 1;
	while (++i < g_M)
		if (is_prime(i) && g_factors[i] == 0)
			g_primes[g_pcount++] = i;
}

void	rec(int	i, int now)
{
	if (i == g_pcount)
	{
		g_answers[g_acount++] = now;
		return ;
	}
	while (now <= g_M && now > 0)
	{
		if (i == 0)
			printf("now %d %d\n", now, g_M);
		rec(i + 1, now);
		now *= g_primes[i];
	}
}

int	mycmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	main(void)
{
	int	i;

	scanf("%d %d", &g_N, &g_M);
	i = -1;
	while (++i < g_N)
		scanf("%d", g_A + i);
	construct_factor();
	construct_primes();
	printf("pc %d\n", g_pcount);
	rec(0, 1);
	qsort(g_answers, g_acount, sizeof(int), mycmp);
	printf("%d\n", g_acount);
	i = -1;
	while (++i < g_acount)
		printf("%d\n", g_answers[i]);
}
