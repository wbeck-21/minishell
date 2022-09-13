# include "../inc/minishell.h"

t_list	*do_split(char *str)
{
	t_list	*list;
	t_list	*new;
	char	**strs;
	int		i;

	i = 0;
	list = NULL;
	strs = ft_split(str, '|');
	while (strs[i])
	{
		new = ft_lstnew(strs[i]);
		ft_lstadd_back(&list, new);
		i++;
	}
	free_mem(strs); // ее нет 
	return (list);
}

void	make_split(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		tmp->cmd = ft_split(tmp->content, ' ');
		tmp = tmp->next;
	}
}

char	*insert_inside_gap2(t_inside_gap_2	change, char *content) // возвращает в строку символы,  которые пропали из-за сплита и result_line()
{
	int	i;

	i = -1;
	while (*(content + ++i)) //  после строки смотрим по символьно и ищем символы
	{
		if (*(content + i) == change.in_redirect)
			*(content + 1) = '<';
		if (*(content + i) == change.out_redirect)
			*(content + 1) = '>';
		if (*(content + i) == change.pipe)
			*(content + 1) = '|';
		if (*(content + i) == change.cmd_separator)
			*(content + 1) = ';';
		if (*(content + i) == change.tilda)
			*(content + 1) = '~';
		if (*(content + i) == change.gap)
			*(content + 1) = '\'';
	}
	return (content);
}