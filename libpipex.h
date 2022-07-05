/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:08:58 by bjimenez          #+#    #+#             */
/*   Updated: 2022/07/05 13:22:57 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPIPEX_H
# define LIBPIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>

void	ft_ex_cmd(char *cmd, char **env);
char	*ft_get_path(char **envp, char *cmd);
char	*ft_check_path(char **all_paths, char *cmd);
void	ft_pipe(char *cmd, char **envp, int fd);
int		ft_open_f(char *filename, int t_file);
int		ft_strchr_int(char *str, char c);
void	ft_free_double_p(char **str);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
