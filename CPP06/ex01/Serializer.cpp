/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:12:22 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/12 18:59:58 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

uintptr_t	Serializer::serialize( Data* ptr )
{
    return ( reinterpret_cast<uintptr_t> (ptr) );
}

Data*		Serializer::deserialize( uintptr_t raw )
{
    return ( reinterpret_cast<Data*> (raw) );
}
