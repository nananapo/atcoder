#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	S[25];
	int		len;

	scanf("%s", S);
	len = strlen(S);
	if (S[len - 1] == 't')
		printf("ist\n");
	else
		printf("er\n");
}
