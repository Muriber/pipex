/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:35:35 by bjimenez          #+#    #+#             */
/*   Updated: 2022/07/05 13:01:33 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

void	ft_free_double_p(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free(str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strchr_int(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*ft_check_path(char **all_paths, char *cmd)
{
	int		i;
	char	*path;
	char	*cmd_path;

	i = -1;
	while (all_paths[++i])
	{
		path = ft_strjoin(all_paths[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		r;

	i = 0;
	if (n == 0)
		r = 0;
	else
	{
		while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		{
			i++;
		}
		r = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (r);
}
