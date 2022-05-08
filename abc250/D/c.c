#include <stdio.h>

#define LL long long

static LL	g_primes[2000000];
static int	g_pcount = 0;

static LL	g_N;

int	is_prime(LL x)
{
	LL	i;
	LL	j;

	if (x % 2 == 0)
		return (x == 2);
	i = 3;
	while (i * i <= x && i * i > 0)
	{
		if (x % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

void	calc_primes(void)
{
	LL	i;

	g_primes[0] = 2;
	i = 3;
	g_pcount = 1;
	while (i <= 1000000)
	{
		if (is_prime(i))
			g_primes[g_pcount++] = i;
		i += 2;
	}
}

void	answer(void)
{
	int	i;
	int	j;
	LL	k;
	int	result;

	i = 0;
	result = 0;
	while (++i < g_pcount)
	{
		k = g_N / g_primes[i] / g_primes[i] / g_primes[i];
		if (k >= g_primes[i - 1])
			result += i;
		else
		{
			j = -1;
			while (++j < i)
			{
				if (g_primes[j] <= k)
					result++;
				else
					break ;
			}
		}
	}
	printf("%d\n", result);
}

int	main(void)
{
	scanf("%lld", &g_N);
	calc_primes();
	answer();
}
