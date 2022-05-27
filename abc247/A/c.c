#include <stdio.h>

int	main(void)
{
	char	S[5];

	scanf("%s", S);
	S[3] = '\0';
	printf("0%s\n", S);
}
