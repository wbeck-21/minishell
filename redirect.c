#include "minishell.h"

char	*redirect(char	*str, t_mini	**mini)
{
	int	i;

	i = 0;
	if (!*(str + i + 1) && (*(str + i) == '<' || *(str + i) == '>'))
	{
		ft_putendl_fd(ERROR"Redirect error"TEXT, 2);
		free(str);
		return (NULL);
	}
	while (*(str + i + 1))
	{
		if (*(str + i) == '<' && *(str + i + 1) != '<')
			str = input(str, &i, mini);
		else if (*(str + i) == '<' && *(str + i + 1) == '<')
			str = heredoc(str, &i, mini);
		else if (*(str + i) == '>' && *(str + i + 1) != '>')
			str = trunc_out(str, &i, mini);
		else if (*(str + i) == '>' && *(str + i + 1) == '>')
			str = append_out(str, &i, mini);
		else
			i++;
		if (!str)
			return (NULL);
	}
	return (str);
}