/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:08:08 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 10:17:00 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	fun()
{
	const Animal	*animals[25];
	for (int i = 0; i < 25 ; i++)
	{
		if (i % 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
	}
	for(int i = 0; i < 25; i++)
		std::cout << animals[i]->getType() << std::endl;
	for(int i = 0; i < 25; i++)
		delete animals[i];
		
//---------------------------------------------------------------
	//std::cout << "shallow VS deep" << std::endl;
	Dog	obj;
	Cat	obj1;
	
	obj.setDogIdea("Dankey", 1);
	obj1.setCatIdea("nono", 2);

	Dog obj_dog;
	Cat obj_cat;

	obj_dog = obj;
	obj_cat = obj1;
	std::cout << obj_dog.getDogIdea(1) << " :::DOG::: " << obj.getDogIdea(1) << std::endl;
	std::cout << obj_cat.getCatIdea(2) << " :::CAT::: " << obj1.getCatIdea(2) << std::endl;

	obj.setDogIdea("hh", 1);
	obj1.setCatIdea("jjjj", 2);
	std::cout << obj_dog.getDogIdea(1) << " :::DOG::: " << obj.getDogIdea(1) << std::endl;
	std::cout << obj_cat.getCatIdea(2) << " :::CAT::: " << obj1.getCatIdea(2) << std::endl;
}

int main()
{
	fun();
	// delete [] animals;
	// system("leaks ex01");
	return 0;
}
