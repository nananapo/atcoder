// 注意!
// dict.cに依存しています！

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
