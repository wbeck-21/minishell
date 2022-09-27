#include "minishell.h"

bool	preparser(char	*str)
{
	int		i;
	t_pre	gaps;

	gaps.gap2 = 0;
	gaps.gap = 0;
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '\'')
			gaps.gap++;
		if (*(str + i) == '\"')
			gaps.gap2++;
		i++;
	}
	if (gaps.gap % 2 || gaps.gap2 % 2)
		return (false);
	return (true);
}

t_list	*do_split(char	*str)
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
	free_mem(strs);
	return (list);
}

char *parser(char *str, t_mini *mini, int i, int flag)
{
    if (!pre_check(str))
        return (NULL);
    while (*(str + i))
    {
        if (*(str + i) == '\'')
        {
            while (*(str + i) == '\'')
            {
                flag++;
                str = do_gap(str, i);
            }
        }
        else if (*(str + i) == '\"' && flag % 2 == 0)
            while (*(str + i) == '\"')
                str = do_gap2(str, i, mini->lst, mini->change);
        else if (*(str + i) == '$' && ft_strncmp("$?", str + i, 2)
                && ft_strcmp(str + i, "$") && !was_heredoc(str) && flag % 2 == 0)
                while (*(str + i) == '$')
                    str = do_dollar(str, i, mini->lst);
        else if (*(str + i) == '\\' || *(str + i) == ';')
            return (return_message(str));
        else
            i++;
    }
    return (after_check(str, mini));
}

bool	result_line(char	**str, t_list	**history, t_mini	*mini)
{
    int i;

    if (!*str)
        handle_free(*str, *history, mini);
    i = 0;
    while (**str != '\0' && (**str == ' ' || **str == '\t'))
        (*str)++; 
    if (!*str[i])
        return (false); 
    *history = make_history(*str, *history);
    add_history(*str);
    *str = parser(*str, mini, 0, 0);
    if (!*str)
        return (false);
    i = 0;
    while (str[0][i] && str[0][i] == ' ')
        i++;
    if (!str[0][i])
        return (false);
    return (true);
}
//sudo apt-get install libreadline-dev 