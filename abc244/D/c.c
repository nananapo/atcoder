#include <stdio.h>

int	main(void)
{
	char	S[3];
	char	T[3];
	int		mis;

	scanf("%c %c %c\n", S, S + 1, S + 2);
	scanf("%c %c %c", T, T + 1, T + 2);
	mis = (S[0] != T[0]) + (S[1] != T[1]) + (S[2] != T[2]);
	if (mis == 0 || mis == 3)
		printf("Yes\n");
	else
		printf("No\n");
}
