/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:20:30 by wbeck             #+#    #+#             */
/*   Updated: 2022/09/20 22:20:31 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// При выполнении команды bash открывается новая оболочка. 
// Переменная среды $SHLVL содержит количество уровней оболочки, 
// на которых работает текущая оболочка.

// В новом окне терминала выполнение следующей команды даст 
// разные результаты в зависимости от используемого дистрибутива Linux.

// При выполнении каждой команды bash значение $SHLVL увеличивается на единицу.

// Больше здесь: https://riptutorial.com/bash/example/16882/-shlvl#:~:text=The%20%24SHLVL%20environment%20variable%20holds,the%20Linux%20distribution%20in%20use.

void    mini_shlvl(t_mini *mini, char **envp)
{
    char    *tmp;
    int     i;
    t_lst   *lst;

    lst = mini->list;
    i = 0;
    signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
    while (lst && ft_strncmp(lst->var, "SHLVL=", 6))
        lst = lst->next;
    if (!lst)
    {
        while (envp[i] && ft_strncmp(envp[i], "SHLVL=", 6))
            i++;
        tmp = ft_substr(envp[i], 0, 6);
        envp[i] = ft_strjoin(tmp, "0");
    }
}