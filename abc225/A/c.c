#include <stdio.h>

int	main(void)
{
	char	S[4];

	scanf("%s", S);
	if (S[0] == S[1] && S[1] == S[2])
	{
		printf("1\n");
		return (0);
	}
	if (S[0] == S[1] || S[0] == S[2] || S[1] == S[2])
	{
		printf("3\n");
		return (0);
	}
	printf("6\n");
}
