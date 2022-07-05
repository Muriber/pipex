/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:49:19 by bjimenez          #+#    #+#             */
/*   Updated: 2022/07/05 13:28:02 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libpipex.h"

char	*ft_get_path(char **envp, char *cmd)
{
	char	**all_paths;
	char	*cmd_path;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	cmd_path = ft_check_path(all_paths, cmd);
	return (cmd_path);
}

void	ft_ex_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (ft_strchr_int(args[0], '/') > -1)
		path = args[0];
	else
		path = ft_get_path(envp, args[0]);
	execve(path, args, envp);
	write(2, "pipex: ", 7);
	write(2, cmd, ft_strchr_int(cmd, 0));
	write(2, ": command not found\n", 20);
	exit(127);
}

void	ft_pipe(char *cmd, char **envp, int fd)
{
	pid_t	pid;
	int		fd_pipe[2];

	pipe(fd_pipe);
	pid = fork();
	if (pid == -1)
		perror("Error fork process");
	else if (pid > 0)
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], 1);
		if (fd == 0)
			exit(1);
		else
			ft_ex_cmd(cmd, envp);
	}
}

int	ft_open_f(char *filename, int t_file)
{
	if (t_file == 1)
	{
		if (access(filename, F_OK) == -1)
		{
			write(2, "pipex: ", 7);
			write(2, filename, ft_strlen(filename));
			write(2, ": No such file or directory", 27);
			return (0);
		}
		else
			return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		i;

	i = 3;
	if (argc >= 5)
	{
		fd[0] = ft_open_f(argv[1], 1);
		fd[1] = ft_open_f(argv[argc - 1], 4);
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		ft_pipe(argv[2], envp, fd[0]);
		while (i < argc - 2)
			ft_pipe(argv[i++], envp, 1);
		ft_ex_cmd(argv[i], envp);
	}
	else
	{
		write(2, "Error: wrong number of arguments\n", 33);
		return (1);
	}
	system("leaks -q pipex");
	return (0);
}
