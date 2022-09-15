#include "../inc/minishell.h"

void    mini_dq(char *str)
{
    ft_putchar_fd("minishell: command not found: ", 2);
    ft_putchar_fd("minishell: command not found: ", 2);
    str += 2;
    if (*str)
        ft_putchar_fd(str, 2);
    ft_putendl_fd("\033[1;37m", 2);
    g_sig.ex_code = 127;
}