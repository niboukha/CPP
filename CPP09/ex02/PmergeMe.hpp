/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:37:52 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/21 15:26:38 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <cmath>
#include <time.h>
#include <math.h>
#include <sstream>
#include <sys/time.h>

class PmergeMe
{
	private :

		std::vector<int>			vect;
		std::deque<int>				deq;
		
		class	InvalidInput : public std::exception
		{
			public :
				const char	*what() const throw();
		};

		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& assign);
		
	public : 

		PmergeMe(std::vector<std::string> str);
		~PmergeMe();

		void								mergeInsertionSort ();

		/* VECTOR Part */
		
		void								fillVector(std::vector<std::string>& sVect);
		std::vector<int>					sortedVector(std::vector< std::pair<int, int> >& v);
		std::vector< std::pair<int, int> >	mergeInsertionSortVec(std::vector< std::pair<int, int> >& v);
		std::vector< std::pair<int, int> >	indexedVectorOfPairs(std::vector<int>& v);
		std::vector< std::pair<int, int> >	clearAndFillNewVectorPairs(std::vector< std::pair<int, int> >& v,
												std::vector< std::pair< std::pair<int, int>, std::pair<int, int> > >&	vectPairs);
		std::vector< std::pair<int, int> >	InsertInSoredVector(std::vector< std::pair<int, int> >&	sortedVec,
												std::vector< std::pair<int, int> >&	retVect,
												std::vector< std::pair< std::pair<int, int>, std::pair<int, int> > >& vectPairs,
												std::vector< std::pair<int, int> >&	oddVector);
		std::vector< std::pair< std::pair<int, int>, std::pair<int, int> > >	makeVectorOfPairs  (std::vector< std::pair<int, int> >& v);

		void	displayFirstLineVec();
		void	displaySecondLineVec(std::vector<int> &sortedVector);
		void	displaythirdLine(unsigned long start, unsigned long end, std::vector<int>&  v);

		/* End Of Vector Part */
		
		/* DEQUE Part */
		
		void								fillDeque(std::vector<std::string>& sDeq);
		std::deque<int>						sortedDeque(std::deque< std::pair<int, int> >& d);
		std::deque< std::pair<int, int> >	mergeInsertionSortDeq(std::deque< std::pair<int, int> >& d);
		std::deque< std::pair<int, int> >	indexedDequeOfPairs(std::deque<int>& d);
		std::deque< std::pair<int, int> >	clearAndFillNewDequePairs(std::deque< std::pair<int, int> >& d,
												std::deque< std::pair< std::pair<int, int>, std::pair<int, int> > >&	deqPairs);
		std::deque< std::pair<int, int> >	InsertInSoredDeque(std::deque< std::pair<int, int> >&	sortedDeq,
												std::deque< std::pair<int, int> >&	retDeq,
												std::deque< std::pair< std::pair<int, int>, std::pair<int, int> > >& deqPairs,
												std::deque< std::pair<int, int> >&	oddDeque);
		std::deque< std::pair< std::pair<int, int>, std::pair<int, int> > >	makeDequeOfPairs  (std::deque< std::pair<int, int> >& d);

		void								displaylastLine(unsigned long start, unsigned long end, std::deque<int> & d);

		/* End Of DEQUE Part */
		
		size_t						jacobsthalInsertion(int	k);
		unsigned long				cpuTimeUsed(unsigned long start, unsigned long end);
		std::vector<std::string>	parseInput(std::vector<std::string> &input);

};

#endif
