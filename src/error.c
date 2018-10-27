#include <lemin.h>

static const char	g_usage[] = "Usage: ./lem-in "
	 "[--silent] [--solo] [--ways] [--steps] [--help] (< file|file)"
	 "";

void	delaftersplit(char ***arr)
{
	int 	i;
	char	**temp;

	i = -1;
	if (arr == NULL || *arr == NULL || **arr == NULL)
		return ;
	temp = *arr;
	while (temp[++i])
		if (temp[i] != NULL)
			ft_strdel(&temp[i]);
	free(temp);
}

void    ft_error(char *err)
{
	if (!err)
		ft_printf("%s\n", g_usage);
	ft_printf("%s\n", err);
	exit(0);
}
