#include "minishell.h"

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

void	del(void *var)
{
	(void)var;
	var = NULL;
}

char	*insert_inside_gap2(t_inside_gap_2	change, char *content) // возвращает в строку символы,  которые пропали из-за сплита и result_line()
{
	int	i;

	i = -1;
	while (*(content + ++i))
	{
		if (*(content + i) == change.pipe)
			*(content + i) = '|';
		else if (*(content + i) == change.in_redirect)
			*(content + i) = '<';
		else if (*(content + i) == change.out_redirect)
			*(content + i) = '>';
		else if (*(content + i) == change.cmd_separator)
			*(content + i) = ';';
		else if (*(content + i) == change.tilda)
			*(content + i) = '~';
		else if (*(content + i) == change.gap)
			*(content + i) = '\'';
	}
	return (content);
}