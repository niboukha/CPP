/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:35:44 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/14 12:41:37 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename U>

void	iter(T addArr, size_t lengthArr, U fun)
{
	for (size_t i = 0; i < lengthArr; i++)
		fun(addArr[i]);
}

template <typename T>

void	func(T &addArr)
{
	std::cout << addArr << std::endl;
}

#endif
