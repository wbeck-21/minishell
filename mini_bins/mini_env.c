#include "../inc/minishell.h"

void mini_env(t_lst *lst)
{
    while (lst)
    {
        ft_putchar_fd(lst->var, 1);
        write(1, "\n", 1);
        lst = lst->next;
    }
	g_sig.ex_code = 0;   
}