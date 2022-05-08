#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int	(*t_hash)(const void *);
typedef int	(*t_cmp)(const void *, const void *);

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
		dict->ptr[keyhash % dict->bsize] = tmp->next;
		return ;
	}
	while (tmp->next != NULL)
	{
		if (dict->keycmp(tmp->next->id, key) == 0)
		{
			tmp->next = tmp->next->next;
			free(tmp->next);
			return ;
		}
		tmp = tmp->next;
	}
}

#define N_MAX 202000000

static int	g_N;
static char	g_S[N_MAX];

typedef struct s_pair
{
	int	fst;
	int	snd;
}	t_pair;

t_pair	*create_pair(int fst, int snd)
{
	t_pair	*pair;

	pair = (t_pair *)malloc(sizeof(t_pair));
	pair->fst = fst;
	pair->snd = snd;
	return (pair);
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
	return (hash);
}

int	mycmp(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int	main(void)
{
	int		i;
	t_dict	*dict;
	void	*dummy;
	int		result;
	char	*key;

	scanf("%d%*c", &g_N);
	i = -1;
	result = 0;
	dict = dict_create(100000, myhash, mycmp);
	while (++i < g_N)
	{
		scanf("%[^\n]%*c", g_S);
		key = strdup(g_S);
		if (!dict_get(dict, key, &dummy))
		{
			result++;
			dict_set(dict, key, dummy);
		}
	}
	printf("%d\n", result);
}
