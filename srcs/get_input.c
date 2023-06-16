/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:19:24 by etlaw             #+#    #+#             */
/*   Updated: 2023/04/23 20:41:46 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
			i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_dup(int num, char **input, int i)
{
	i++;
	while (input[i])
	{
		if (ft_atoi(input[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

static char	**get_input(int ac, char **av)
{
	char	**buff;
	char	*tmp;
	char	*line;
	int		i;

	if (ac == 2)
		buff = ft_split(av[1], ' ');
	else
	{
		i = 1;
		line = ft_strdup(av[i]);
		while (av[++i])
		{
			tmp = ft_strdup(av[i]);
			line = ps_strjoin(line, tmp, " ");
			free(tmp);
		}
		buff = ft_split(line, ' ');
		free (line);
	}
	return (buff);
}

char	**get_crt_input(int ac, char **av)
{
	char	**input;
	int		i;
	long	num;

	i = 0;
	input = get_input(ac, av);
	while (input[i])
	{
		num = ft_atoi(input[i]);
		if (!isnum(input[i]))
			errormsg("\033[0;31mError : Input is not number\033[42m");
		if (!check_dup(num, input, i))
			errormsg("\033[0;31mError : Duplicate numbers\033[42m");
		if (num < -2147483648 || num > 2147483647)
			errormsg
			("\033[0;31mError : Value above max int or below min int\033[42m");
		i++;
	}
	return (input);
}
