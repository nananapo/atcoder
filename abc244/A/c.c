#include <stdio.h>

int	main(void)
{
	int		N;
	char	S[1001];

	scanf("%d %s", &N, S);
	printf("%c\n", S[N - 1]);
}
