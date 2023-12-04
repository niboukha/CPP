/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:08:08 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/29 16:54:05 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	fun()
{
	// const Animal	*animals[25];
	Dog *d = new Dog();

	Dog *d1 = new Dog();
	*d1 = *d;
	delete d;
	std::cout << d1->getType() << std::endl;
	// for (int i = 0; i < 25 ; i++)
	// {
	// 	if (i % 2)
	// 		animals[i] = new Dog;
	// 	else
	// 		animals[i] = new Cat;
	// }
	// for(int i = 0; i < 25; i++)
	// 	std::cout << animals[i]->getType() << std::endl;
	// for(int i = 0; i < 25; i++)
	// 	delete animals[i];
	delete d1;
}

int main()
{
	fun();
	// delete [] animals;
	system("leaks ex02");
	return 0;
}
