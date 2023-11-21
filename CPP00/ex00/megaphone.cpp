/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:13:23 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/21 10:51:54 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int	main(int ac, char **av)
{
	std::string	arg;
	std::size_t	j;
	int	i;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 0;
		while (av[++i])
		{
			arg = av[i];
			j = -1;
			while (++j < arg.length())
				std::cout << (char)std::toupper(arg[j]);
		}
	}
	return (0);
}
