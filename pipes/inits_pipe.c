#include "../minishell.h"

char    *concat(char *path, char *cmd)
{
    char    *tmp;
    char    *res;

    tmp = ft_strjoin(path, "/");
    res = ft_strjoin(tmp, cmd);
    return (res);
}
