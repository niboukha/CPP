/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:08:08 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 11:06:47 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrng = new WrongCat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << wrng->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	wrng->makeSound();
	

	delete meta;
	delete j;
	delete i;
	delete wrng;	
	return 0;
}
