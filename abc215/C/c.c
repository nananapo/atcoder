#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

int	myhash(const void *key)
{
	char	*s;
	int		len;
	int		i;
	int		hash;

	s = (char *)key;
	len = (int) strlen(s);
	i = -1;
	hash = len * s[0] * s[len - 1];
	while (++i < len)
		hash += (s[i] % 53) * (s[len - i - 1] % 49);
	if (hash < 0)
		hash = - (hash + 1);
	return (hash);
}

int	mycmp(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
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

static char		g_S[100];
static int		g_K;
static int		g_len;
static int		g_use[100];
static int		g_count;
static t_set	*g_set;

char	*get_answer(void)
{
	int		i;
	int		j;
	char	*s;

	s = (char *)calloc(g_len + 1, sizeof(char));
	i = -1;
	while (++i < g_len)
	{
		j = -1;
		while (++j < g_len)
			if (g_use[j] == i + 1)
				s[i] = g_S[j];
	}
	return (s);
}

void	answer2(void)
{
	char	*a;

	a = get_answer();
	if (!set_exists(g_set, a))
	{
		g_count++;
		set_add(g_set, a);
	}
	if (g_count == g_K)
	{
		printf("%s\n", a);
		exit(0);
	}
}

void	answer(int c)
{
	int		i;

	if (c == g_len)
	{
		answer2();
		return ;
	}
	i = -1;
	while (++i < g_len)
	{
		if (g_use[i] == 0)
		{
			g_use[i] = c + 1;
			answer(c + 1);
			g_use[i] = 0;
		}
	}
}

int	cmp(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}

int	main(void)
{
	scanf("%s %d", g_S, &g_K);
	g_len = strlen(g_S);
	qsort(g_S, g_len, sizeof(char), cmp);
	g_set = set_create(10000, myhash, mycmp);
	answer(0);
}
