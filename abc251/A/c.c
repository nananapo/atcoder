#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	S[10];

	scanf("%s", S);
	if (strlen(S) == 1)
		printf("%s%s%s%s%s%s\n", S, S, S, S, S, S);
	else if (strlen(S) == 2)
		printf("%s%s%s\n", S, S, S);
	else
		printf("%s%s\n", S, S);
}
