#include <stdio.h>
#include <string.h>

int	kto10(char *s, int len, int k)
{
	int	r;
	int	i;

	r = 0;
	i = -1;
	while (++i < len)
		r = r * k + s[i] - '0';
	return (r);
}

int	main(void)
{
	char	A[1024 * 1024];
	char	B[1024 * 1024];
	int		K;

	scanf("%d%*c%s %s", &K, A, B);
	printf("%lld\n",
		(long long)kto10(A, strlen(A), K)
		* (long long)kto10(B, strlen(B), K));
}
