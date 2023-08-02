/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:34:14 by emoumni           #+#    #+#             */
/*   Updated: 2023/08/02 00:38:49 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	analyse_the_args(char *str)
{
	long	i;
	long	counter;

	i = 0;
	counter = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		counter++;
		i++;
	}
	if (str[i] == '\0')
		error_s();
	string_check(str, i - 1, counter);
}

void	string_check(char *str, long i, long trigger)
{
	long	j;

	i++;
	j = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] 
			!= ' ' && str[i] != '-' && str[i] != '+')
			error_s();
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i - 1] != ' ' && str[i - 1] != '\0')
				trigger = 3;
			if (!ft_isdigit(str[i + 1]))
				error_s();
		}
		if (ft_isdigit(str[i]))
			j++;
		if (str[i] == ' ' && str[i + 1] == '\0' && j == 0)
			error_s();
		if (trigger > 2)
			error_s();
		i++;
	}
}
