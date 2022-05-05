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

/*
int	myhash(const void *key)
{
	return ((int) strlen((char *)key));
}

int	mycmp(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}

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

int	main(void)
{
	t_dict	*dict;
	void	*res;
	bool	find;

	dict = dict_create(1000, myhash, mycmp);
	dict_set(dict, "a", create_pair(0, 100));
	dict_set(dict, "b", create_pair(0, 200));
	find = dict_get(dict, "a", &res);
	printf("%d\n", ((t_pair *)res)->snd);
	find = dict_get(dict, "b", &res);
	printf("%d\n", ((t_pair *)res)->snd);
	dict_del(dict, "b");
	find = dict_get(dict, "a", &res);
	printf("%d\n", find);
	dict_set(dict, "abc", create_pair(0, 123));
	find = dict_get(dict, "abc", &res);
	printf("%d\n", ((t_pair *)res)->snd);
}
*/
