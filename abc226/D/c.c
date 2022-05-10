#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int		(*t_hash)(const void *);
typedef int		(*t_cmp)(const void *, const void *);

typedef struct s_dict_elem
{
	void				*id;
	void				*ptr;
	struct s_dict_elem	*next;
}	t_dict_elem;

typedef struct s_dict
{
	int			bsize;
	t_dict_elem	**ptr;
	t_hash		hash;
	t_cmp		keycmp;
	int			len;
}	t_dict;

// bucket_size	: 辞書のサイズ bsize > 0
// hash_func	: キーをhashする関数
// keycmp		: キーを比較する関数 : 等しいなら0
t_dict	*dict_create(int bucket_size, t_hash hash_func, t_cmp keycmp)
{
	t_dict	*dict;

	dict = (t_dict *)malloc(sizeof(t_dict));
	dict->bsize = bucket_size;
	dict->hash = hash_func;
	dict->keycmp = keycmp;
	dict->ptr = (t_dict_elem **)calloc(bucket_size, sizeof(t_dict_elem *));
	dict->len = 0;
	return (dict);
}

// キーを指定して、辞書から値を取り出す
//
// dict		: 辞書
// key		: キー
// result	: 結果を格納するポインタ
// return -> キーが見つかったかどうか
bool	dict_get(t_dict *dict, void *key, void **result)
{
	t_dict_elem	*tmp;
	int			keyhash;

	keyhash = dict->hash(key);
	tmp = dict->ptr[keyhash % dict->bsize];
	while (tmp != NULL)
	{
		if (dict->keycmp(tmp->id, key) == 0)
		{
			*result = tmp->ptr;
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}

// 辞書に値を設定する
//
// key	: キー
// value: 値
void	dict_set(t_dict *dict, void *key, void *value)
{
	t_dict_elem	*tmp;
	int			keyhash;

	keyhash = dict->hash(key);
	tmp = dict->ptr[keyhash % dict->bsize];
	while (tmp != NULL)
	{
		if (dict->keycmp(tmp->id, key) == 0)
		{
			tmp->ptr = value;
			return ;
		}
		tmp = tmp->next;
	}
	tmp = (t_dict_elem *)malloc(sizeof(t_dict_elem));
	tmp->id = key;
	tmp->ptr = value;
	tmp->next = dict->ptr[keyhash % dict->bsize];
	dict->ptr[keyhash % dict->bsize] = tmp;
	dict->len++;
}

// 辞書からキーのデータを削除する
//
// key : キー
void	dict_del(t_dict *dict, void *key)
{
	t_dict_elem	*tmp;
	int			keyhash;

	keyhash = dict->hash(key);
	tmp = dict->ptr[keyhash % dict->bsize];
	if (tmp == NULL)
		return ;
	if (dict->keycmp(tmp->id, key) == 0)
	{
		free(tmp);
		dict->ptr[keyhash % dict->bsize] = tmp->next;
		dict->len--;
		return ;
	}
	while (tmp->next != NULL)
	{
		if (dict->keycmp(tmp->next->id, key) == 0)
		{
			tmp->next = tmp->next->next;
			dict->len--;
			free(tmp->next);
			return ;
		}
		tmp = tmp->next;
	}
}

typedef struct s_pair
{
	int	fst;
	int	snd;
}	t_pair;

t_pair	*create_pair(int a, int b)
{
	t_pair	*tmp;

	tmp = (t_pair *)malloc(sizeof(t_pair));
	tmp->fst = a;
	tmp->snd = b;
	return (tmp);
}

int	cmp(const void *a, const void *b)
{
	t_pair	*p1;
	t_pair	*p2;

	p1 = (t_pair *)a;
	p2 = (t_pair *)b;
	if (p1->fst == p2->fst && p1->snd == p2->snd)
		return (0);
	return (1);
}

int	myhash(const void *a)
{
	t_pair	*p;
	int		hash;

	p = (t_pair *)a;
	hash = ((p->fst + 127) * 255) * ((p->snd - 127) + 255);
	if (hash < 0)
		hash = - (hash + 1);
	return (hash);
}

#define N_MAX 502

static int		g_N;
static int		g_X[N_MAX];
static int		g_Y[N_MAX];
static t_dict	*g_dict;

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	gcd(int a, int b)
{
	int	tmp;

	a = abs(a);
	b = abs(b);
	tmp = a;
	a = max(a, b);
	b = min(tmp, b);
	while (a % b != 0)
	{
		tmp = a;
		a = b;
		b = tmp % b;
	}
	return (b);
}

void	add_zeromagic(int x, int y)
{
	t_pair	*tmp;

	x = max(-1, min(1, x));
	y = max(-1, min(1, y));
	tmp = create_pair(x, y);
	dict_set(g_dict, tmp, tmp);
}

void	add_magic(int fx, int fy, int tx, int ty)
{
	int		dx;
	int		dy;
	int		g;
	t_pair	*tmp;

	dx = tx - fx;
	dy = ty - fy;
	if (dx == 0 || dy == 0)
	{
		add_zeromagic(dx, dy);
		return ;
	}
	g = gcd(dx, dy);
	dx /= g;
	dy /= g;
	tmp = create_pair(dx, dy);
	dict_set(g_dict, tmp, &dx);
}

int	main(void)
{
	int	i;
	int	j;

	scanf("%d", &g_N);
	i = -1;
	while (++i < g_N)
		scanf("%d %d", g_X + i, g_Y + i);
	g_dict = dict_create(100000, myhash, cmp);
	i = -1;
	while (++i < g_N - 1)
	{
		j = i;
		while (++j < g_N)
		{
			add_magic(g_X[i], g_Y[i], g_X[j], g_Y[j]);
			add_magic(g_X[j], g_Y[j], g_X[i], g_Y[i]);
		}
	}
	printf("%d\n", g_dict->len);
}
