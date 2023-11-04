/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:58:59 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/02 12:41:16 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *zombieHorde = new Zombie[N];
	int	i;

	i = -1;
	while (++i < N)
		zombieHorde[i] = Zombie(name);
	return (zombieHorde);
}

