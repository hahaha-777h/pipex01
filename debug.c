/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhikita <hhikita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:14:49 by hhikita           #+#    #+#             */
/*   Updated: 2025/03/18 14:07:15 by hhikita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Debug for allocate_pipefd

// int	main(int ac, char *av[])
// {
// 	int	**pipefd;
// 	int	num_pipes;
// 	int	npipefd;

// 	(void)av;
// 	if (ac < 5)
// 	{
// 		printf("invalid args count\n");
// 		return (1);
// 	}
// 	pipefd = allocate_pipefd(ac);
// 	if (pipefd == NULL)
// 	{
// 		perror("Allocate failed\n");
// 		return (1);
// 	}
// 	num_pipes = 0;
// 	pipefd[0][0] = 1;
// 	while (num_pipes < ac - NON_CMD_ARGC - 1)
// 	{
// 		printf("num_pipe:%d\n", num_pipes);
// 		npipefd = 0;
// 		while (npipefd < 2)
// 		{
// 			pipefd[num_pipes][npipefd] = 5;
// 			npipefd++;
// 		}
// 		num_pipes++;
// 	}
// 	num_pipes = 0;
// 	while (pipefd[num_pipes] != NULL)
// 	{
// 		npipefd = 0;
// 		while (npipefd < 2)
// 		{
// 			printf("%d\n", pipefd[num_pipes][npipefd]);
// 			npipefd++;
// 		}
// 		num_pipes++;
// 	}
// }

// debug for get_cmds
// void	print_split(char **s)
// {
// 	int	i;

// 	if (s == NULL)
// 		return ;
// 	i = 0;
// 	while (s[i] != NULL)
// 	{
// 		printf("%s\n", s[i]);
// 		i++;
// 	}
// 	return ;
// }

// debug for	get_cmds(void);
// int	main(int ac, char *av[], char **envp)
// {
// 	int		arg_i;
// 	char	***cmds;
// 	char	**sub;
// 	t_pipex	pipex;

// 	init_pipex(&pipex);
// 	cmds = get_cmds(ac, av, &pipex);
// 	if (!cmds)
// 	{
// 		printf("Failed to get commands\n");
// 		return (1);
// 	}
// 	arg_i = 0;
// 	while (cmds[arg_i])
// 	{
// 		print_split(cmds[arg_i]);
// 		arg_i++;
// 	}
// 	return (0);
// }

// debug for get_path();
// int	main(int ac, char *av[], char **envp)
// {
// 	char **path;
// 	path = get_path(envp);
// 	if (!path)
// 		return (0);
// 	while (*path)
// 	{
// 		printf("%s\n", *path++);
// 	}
// 	return (0);
// }

// check execve()'s behavior
// #include "pipex.h"

// int	main(void)
// {
// 	char *cmd[3] = {"/bin/ls", "-l", NULL};
// 	if (execve("/bin/ls", cmd, NULL) == -1)
// 	{
// 		printf("exec failed\n");
// 		return (1);
// 	}
// 	return (0);
// }