#include <stdio.h>
#include <unistd.h>

#define LL unsigned long long

// 2baseな文字列と桁数
char	g_R[1000000];
int		g_k;

int	get_keta(LL x)
{
	int	i;

	i = 1;
	while ((x / 2) != 0)
	{
		x /= 2;
		i++;
	}
	return (i);
}

void	make_r(LL x)
{
	int	keta;

	g_k = get_keta(x);
	keta = g_k;
	while (x != 0)
	{
		g_R[--keta] = '0' + (x % 2);
		x = x / 2;
	}
}

LL	create_ll(void)
{
	LL	l;
	int	i;

	l = 0;
	i = -1;
	while (++i < g_k)
		l = l * 2 + (g_R[i] == '1');
	return (l);
}

int	main(void)
{
	int		N;
	LL		X;
	char	S[1000100];
	int		i;

	scanf("%d %lld %s", &N, &X, S);
	make_r(X);
	i = -1;
	while (++i < N)
	{
		if (S[i] == 'U')
			g_k--;
		else
			g_R[g_k++] = '0' + (S[i] == 'R');
	}
	printf("%lld\n", create_ll());
}
