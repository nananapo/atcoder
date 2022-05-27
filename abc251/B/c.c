#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

// 辞書にキーが存在するか確認する
bool	dict_exists(t_dict *dict, void *key)
{
	void	*ptr;

	return (dict_get(dict, key, &ptr));
}

typedef t_dict	t_set;

t_set	*set_create(int size, t_hash hash_func, t_cmp cmp_func)
{
	return (dict_create(size, hash_func, cmp_func));
}

void	set_add(t_set *set, void *value)
{
	dict_set(set, value, NULL);
}

void	set_del(t_set *set, void *value)
{
	dict_del(set, value);
}

bool	set_exists(t_set *set, void *value)
{
	return (dict_exists(set, value));
}

static int		g_N;
static int		g_W;
static int		g_A[1000];
static t_set	*g_set;

void	add_int(int n)
{
	int	*a;

	a = malloc(sizeof(int));
	*a = n;
	set_add(g_set, a);
}

void	solve(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < g_N && g_A[i] <= g_W)
	{
		j = i + 1;
		add_int(g_A[i]);
		while (j < g_N && g_A[i] + g_A[j] <= g_W)
		{
			if (i == j - 1 || g_A[j - 1] != g_A[j])
			{
				k = j + 1;
				add_int(g_A[i] + g_A[j]);
				while (k < g_N && g_A[i] + g_A[j] + g_A[k] <= g_W)
					add_int(g_A[i] + g_A[j] + g_A[k++]);
			}
			j++;
		}
		i++;
	}
}

int	cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	myhash(const void *a)
{
	return (*(int *)a % 199 + ((*(int *)a) << 5) % 12000 + *(int *)a);
}

int	main(void)
{
	int	i;

	scanf("%d %d", &g_N, &g_W);
	i = -1;
	while (++i < g_N)
		scanf("%d", g_A + i);
	qsort(g_A, g_N, sizeof(int), cmp);
	g_set = set_create(10000, myhash, cmp);
	solve();
	printf("%d\n", g_set->len);
}
