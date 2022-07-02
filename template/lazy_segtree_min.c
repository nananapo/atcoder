#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_lsegtree
{
	int		size;
	int		*A;
	int		*B;
	bool	*flag;
}	t_lsegtree;

static int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static void	lsegtree_init(t_lsegtree *t, int p)
{
	if (p >= t->size - 1)
		return ;
	lsegtree_init(t, (p + 1) * 2 - 1);
	lsegtree_init(t, (p + 1) * 2);
	t->A[p] = min(t->A[(p + 1) * 2 - 1], t->A[(p + 1) * 2]);
}

static void	lsegtree_eval(t_lsegtree *t, int p)
{
	if (t->flag[p])
	{
		t->A[p] = t->B[p];
		if (p < t->size - 1)
		{
			t->B[(p + 1) * 2 - 1] = t->B[p];
			t->B[(p + 1) * 2] = t->B[p];
			t->flag[(p + 1) * 2 - 1] = true;
			t->flag[(p + 1) * 2] = true;
		}
		t->flag[p] = false;
		t->B[p] = 0;
	}
}

t_lsegtree	*lsegtree_create(int size, int *init, int zero)
{
	int			n;
	t_lsegtree	*t;

	n = 1;
	while (n < size)
		n *= 2;
	t = malloc(sizeof(t_lsegtree));
	t->size = n;
	t->A = malloc(sizeof(int) * t->size * 2);
	t->B = calloc(sizeof(int), t->size * 2);
	t->flag = calloc(sizeof(bool), t->size * 2);
	n = -1;
	while (++n < size)
		t->A[n + t->size - 1] = init[n];
	n--;
	while (++n < t->size)
		t->A[n + t->size - 1] = zero;
	lsegtree_init(t, 0);
	return (t);
}

static int	lsegtree_get_rec(t_lsegtree *t, int l, int r, int p, int pl, int pr)
{
	int	a;
	int	b;
	int	mid;

	lsegtree_eval(t, p);
	if (l == pl && r == pr)
	{
		//printf("-> %d(%d)\n", t->A[p], p);
		return (t->A[p]);
	}
	mid = pl + (pr - pl) / 2;
	//printf("g %d %d %d %d %d %d\n", l, r, p, pl, pr, mid);
	if (r <= mid)
		return (lsegtree_get_rec(t, l, r, (p + 1) * 2 - 1, pl, mid));
	if (mid <= l)
		return (lsegtree_get_rec(t, l, r, (p + 1) * 2, mid, pr));
	a = lsegtree_get_rec(t, l, mid, (p + 1) * 2 - 1, pl, mid);
	b = lsegtree_get_rec(t, mid, r, (p + 1) * 2, mid, pr);
	// printf("-> p%d, %d(%d) %d(%d)\n", p, t->A[(p + 1) * 2 - 1], (p + 1) * 2 - 1, t->A[(p + 1) * 2], (p + 1) * 2);
	return (min(a, b));
}

int	lsegtree_get(t_lsegtree *t, int l, int r)
{
	return (lsegtree_get_rec(t, l, r, 0, 0, t->size));
}

static void	lsegtree_set_rec(t_lsegtree *t, int l, int r, int x, int p, int pl, int pr)
{
	int	mid;

	lsegtree_eval(t, p);
	if (l == pl && r == pr)
	{
		t->B[p] = x;
		t->flag[p] = true;
		lsegtree_eval(t, p);
		return ;
	}
	mid = pl + (pr - pl) / 2;
	if (r <= mid)
		lsegtree_set_rec(t, l, r, x, (p + 1) * 2 - 1, pl, mid);
	else if (mid <= l)
		lsegtree_set_rec(t, l, r, x, (p + 1) * 2, mid, pr);
	else
	{
		lsegtree_set_rec(t, l, mid, x, (p + 1) * 2 - 1, pl, mid);
		lsegtree_set_rec(t, mid, r, x, (p + 1) * 2, mid, pr);
	}
	t->A[p] = min(t->A[(p + 1) * 2 - 1], t->A[(p + 1) * 2]);
}

void	lsegtree_set(t_lsegtree *t, int l, int r, int x)
{
	lsegtree_set_rec(t, l, r, x, 0, 0, t->size);
}

int main()
{
	t_lsegtree	*t;
	int			init[] = {0,1,2,3,4,5,6,7,8,9};
	int			i;
	
	t = lsegtree_create(10, init, 2147482647);

	i = -1;
	while (++i < 32)
		printf("%d ", t->A[i]);
	printf("\n");

	i = -1;
	while (++i < 10)
	{
		//printf("r1 %d\n", lsegtree_get(t, 0, i + 1));
		printf("r2 %d->%d\n", i, lsegtree_get(t, i, 10));
	}
}
