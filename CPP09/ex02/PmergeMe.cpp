/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:38:28 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/21 15:22:06 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<std::string> str) 
{
	std::vector<std::string>	s;
	
	s = parseInput(str);
	if (s.empty())
		throw InvalidInput();
	fillVector(s);
	fillDeque(s);
}

PmergeMe::PmergeMe(const PmergeMe& copy) { this->operator=(copy); }

PmergeMe&	PmergeMe::operator=(const PmergeMe& assign) { (void)assign; return (*this); }

PmergeMe::~PmergeMe() { }

const char*	PmergeMe::InvalidInput::what() const throw()
{
	return ("Error");
}

	/* PARSE input */

std::vector<std::string>    PmergeMe::parseInput(std::vector<std::string> &input)
{
	std::vector<std::string>	s;
	std::string	str;
	
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i].find_first_of(" ") != std::string::npos)
		{
			input[i] += " ";
			for (size_t j = 0; j < input[i].length(); j++)
			{
				if (input[i][j] != ' ')
					str += input[i][j];
				else if(!str.empty())
				{
					s.push_back(str);
					str.clear();
				}
			}
		}
		else
			s.push_back(input[i]);
	}
	for (size_t i = 0; i < s.size(); i++)
	{
		if ((s[i].find_first_not_of("0123456789") != std::string::npos and s[i][0] != '+')
			or (s[i].find_first_not_of("0123456789+") != std::string::npos))
				throw InvalidInput();
		if (s[i][0] == '0' and s[i].size() > 1)
			throw InvalidInput();
	}
	return (s);
}

	/* SORT numbers with VECTOR */
	
void	PmergeMe::fillVector(std::vector<std::string> &sVect)
{
	int num;
	std::string s;
	
	for (size_t i = 0; i < sVect.size(); i++)
	{
    	std::istringstream(sVect[i]) >> num;
		if (sVect[i].find_first_of('+') != std::string::npos)
			s += '+';
    	std::ostringstream toStr;
		toStr << num;
		s += toStr.str();
		if (sVect[i].compare(s))
			throw InvalidInput();
		s.clear();
		vect.push_back(num);
	}
}

void	PmergeMe::displayFirstLineVec()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;
}

std::vector<int>	PmergeMe::sortedVector(std::vector< std::pair<int, int> >& v)
{
	std::vector<int>	sortedVec;

	for (size_t i = 0; i <	v.size(); i++)
		sortedVec.push_back(v[i].first);
	return (sortedVec);
}

void	PmergeMe::displaySecondLineVec(std::vector<int> &sortedVec)
{
	std::cout << "After:  ";
	for (size_t i = 0; i < sortedVec.size(); i++)
		std::cout << sortedVec[i] << ' ';
	std::cout << "\n";
}

std::vector< std::pair<int, int> >	PmergeMe::indexedVectorOfPairs(std::vector<int>& v)
{
	std::vector< std::pair<int, int> >	indexedVector;
	
	for (size_t it = 0; it < v.size(); it++)
		indexedVector.push_back(std::make_pair(v[it], it));
	return (indexedVector);
}

size_t		PmergeMe::jacobsthalInsertion(int	k)
{
	return ((pow(2, k + 1) + pow(-1, k)) / 3);
}

std::vector< std::pair< std::pair<int, int>, std::pair<int, int> > > PmergeMe::makeVectorOfPairs(std::vector< std::pair<int, int> > &v)
{
	std::vector< std::pair< std::pair<int, int>, std::pair<int, int> > >	vectPairs;
	
	for (size_t i = 0; i < v.size(); i += 2)
	{
		if (i + 1 < v.size())
		{
			if (v[i].first > v[i + 1].first)
				vectPairs.push_back(std::make_pair(v[i], v[i + 1]));
			else
				vectPairs.push_back(std::make_pair(v[i + 1], v[i]));
		}
	}
	return (vectPairs);
}
	
std::vector< std::pair<int, int> >	PmergeMe::clearAndFillNewVectorPairs(std::vector< std::pair<int, int> > &v,
										std::vector< std::pair< std::pair<int, int>, std::pair<int, int> > >&	vectPairs)
{
	v.clear();
	for(size_t i = 0; i < vectPairs.size(); i++)
		v.push_back(std::make_pair(vectPairs[i].first.first, i));
	return (v);
}

std::vector< std::pair<int, int> >	PmergeMe::InsertInSoredVector(
										std::vector< std::pair<int, int> >&	sortedVec,
										std::vector< std::pair<int, int> >&	retVect,
										std::vector< std::pair< std::pair<int, int>, std::pair<int, int> > >& vectPairs,
										std::vector< std::pair<int, int> >&	oddVector)
{
	size_t	i;
	int		k;
	
	k = 2;
	i = 0;
	for (; i < retVect.size(); i++)
		sortedVec.push_back(vectPairs[retVect[i].second].first);

	sortedVec.insert(lower_bound(sortedVec.begin(), sortedVec.end(), 
		vectPairs[retVect[0].second].second), vectPairs[retVect[0].second].second);
	i = jacobsthalInsertion(k);
	while(1)
	{
		if (i > retVect.size())
		{
			while (i > retVect.size())
				i--;
			while (i > jacobsthalInsertion(k - 1))
			{
				if (jacobsthalInsertion(k) + jacobsthalInsertion(k - 1) - 1 <= sortedVec.size())
				{
					sortedVec.insert(lower_bound(sortedVec.begin(), sortedVec.begin() + jacobsthalInsertion(k) + jacobsthalInsertion(k - 1) - 1,
						vectPairs[retVect[i - 1].second].second), vectPairs[retVect[i - 1].second].second);
				}
				else
					sortedVec.insert(lower_bound(sortedVec.begin(), sortedVec.end(),
						vectPairs[retVect[i - 1].second].second), vectPairs[retVect[i - 1].second].second);
				i--;
			}
			break;
		}
		sortedVec.insert(lower_bound(sortedVec.begin(), sortedVec.begin() + jacobsthalInsertion(k) + jacobsthalInsertion(k - 1) - 1,
					vectPairs[retVect[i - 1].second].second), vectPairs[retVect[i - 1].second].second);

		if (i - 1 == jacobsthalInsertion(k - 1))
		{
			k++;
			i = jacobsthalInsertion(k);
			continue;
		}
		i--;
	}
	if (oddVector.size() == 1)
		sortedVec.insert(lower_bound(sortedVec.begin(), sortedVec.end(), oddVector[0]), oddVector[0]);
	return (sortedVec);
}

std::vector< std::pair<int, int> >	PmergeMe::mergeInsertionSortVec(std::vector< std::pair<int, int> >& v)
{
	std::vector< std::pair< std::pair<int, int>, std::pair<int, int> > >	vectPairs;
	std::vector< std::pair<int, int> >	oddVector;
	std::vector< std::pair<int, int> >	retVect;
	std::vector< std::pair<int, int> >	sortedVec;
	
	if (v.size() == 1)
		return(v);
   	if (v.size() & 1)
		oddVector.push_back(v[v.size() - 1]);
	vectPairs = makeVectorOfPairs (v);
	v 		  = clearAndFillNewVectorPairs(v, vectPairs);
	retVect   = mergeInsertionSortVec(v);
	sortedVec = InsertInSoredVector(sortedVec, retVect, vectPairs, oddVector);

	return(sortedVec);
}

unsigned long	PmergeMe::cpuTimeUsed(unsigned long start, unsigned long end)
{
	return (((unsigned long) (end - start)));
}

void	PmergeMe::displaythirdLine(unsigned long start, unsigned long end, std::vector<int> &v)
{
	std::cout << "Time to process a range of   " << v.size() << " elements with std::vector<int> : ";
	std::cout << cpuTimeUsed(start, end) << " us" << std::endl;
}

/* SORT numbers with DEQUE */

void	PmergeMe::fillDeque(std::vector<std::string> &sDeq)
{
	int num;
	std::string s;
	
	for (size_t i = 0; i < sDeq.size(); i++)
	{
    	std::istringstream(sDeq[i]) >> num;
		if (sDeq[i].find_first_of('+') != std::string::npos)
			s += '+';
    	std::ostringstream toStr;
		toStr << num;
		s += toStr.str();
		if (sDeq[i].compare(s))
			throw InvalidInput();
		s.clear();
		deq.push_back(num);
	}
}

std::deque<int>	PmergeMe::sortedDeque(std::deque< std::pair<int, int> >& v)
{
	std::deque<int>	sortedDeq;

	for (size_t i = 0; i <	v.size(); i++)
		sortedDeq.push_back(v[i].first);
	return (sortedDeq);
}

std::deque< std::pair<int, int> >	PmergeMe::indexedDequeOfPairs(std::deque<int> &d)
{
	std::deque< std::pair<int, int> >	indexedDeque;
	
	for (size_t it = 0; it < d.size(); it++)
		indexedDeque.push_back(std::make_pair(d[it], it));
	return (indexedDeque);
}

std::deque< std::pair< std::pair<int, int>, std::pair<int, int> > > PmergeMe::makeDequeOfPairs(std::deque< std::pair<int, int> > &d)
{
	std::deque< std::pair< std::pair<int, int>, std::pair<int, int> > >	deqPairs;
	
	for (size_t i = 0; i < d.size(); i += 2)
	{
		if (i + 1 < d.size())
		{
			if (d[i].first > d[i + 1].first)
				deqPairs.push_back(std::make_pair(d[i], d[i + 1]));
			else
				deqPairs.push_back(std::make_pair(d[i + 1], d[i]));
		}
	}
	return (deqPairs);
}
	
std::deque< std::pair<int, int> >	PmergeMe::clearAndFillNewDequePairs(std::deque< std::pair<int, int> > &d,
										std::deque< std::pair< std::pair<int, int>, std::pair<int, int> > >&	deqPairs)
{
	d.clear();
	for(size_t i = 0; i < deqPairs.size(); i++)
		d.push_back(std::make_pair(deqPairs[i].first.first, i));
	return (d);
}

std::deque< std::pair<int, int> >	PmergeMe::InsertInSoredDeque(
										std::deque< std::pair<int, int> >&	sortedDeq,
										std::deque< std::pair<int, int> >&	retDeq,
										std::deque< std::pair< std::pair<int, int>, std::pair<int, int> > >& deqPairs,
										std::deque< std::pair<int, int> >&	oddDeque)
{
	
	size_t	i;
	int		k;
	
	k = 2;
	i = 0;
	for (; i < retDeq.size(); i++)
		sortedDeq.push_back(deqPairs[retDeq[i].second].first);

	sortedDeq.insert(lower_bound(sortedDeq.begin(), sortedDeq.end(), 
		deqPairs[retDeq[0].second].second), deqPairs[retDeq[0].second].second);
	i = jacobsthalInsertion(k);
	while(1)
	{
		if (i > retDeq.size())
		{
			while (i > retDeq.size())
				i--;
			while (i > jacobsthalInsertion(k - 1))
			{
				if (jacobsthalInsertion(k) + jacobsthalInsertion(k - 1) - 1 <= sortedDeq.size())
					sortedDeq.insert(lower_bound(sortedDeq.begin(), sortedDeq.begin() + jacobsthalInsertion(k) + jacobsthalInsertion(k - 1) - 1,
						deqPairs[retDeq[i - 1].second].second), deqPairs[retDeq[i - 1].second].second);
				else
					sortedDeq.insert(lower_bound(sortedDeq.begin(), sortedDeq.end(),
						deqPairs[retDeq[i - 1].second].second), deqPairs[retDeq[i - 1].second].second);
				i--;
			}
			break;
		}
		sortedDeq.insert(lower_bound(sortedDeq.begin(), sortedDeq.end(),
					deqPairs[retDeq[i - 1].second].second), deqPairs[retDeq[i - 1].second].second);
		if (i - 1 == jacobsthalInsertion(k - 1))
		{
			k++;
			i = jacobsthalInsertion(k);
			continue;
		}
		i--;
	}
	if (oddDeque.size() == 1)
		sortedDeq.insert(lower_bound(sortedDeq.begin(), sortedDeq.end(), oddDeque[0]), oddDeque[0]);
	return (sortedDeq);
}

std::deque< std::pair<int, int> >	PmergeMe::mergeInsertionSortDeq(std::deque< std::pair<int, int> >& d)
{
	std::deque< std::pair< std::pair<int, int>, std::pair<int, int> > >	deqPairs;
	std::deque< std::pair<int, int> >	oddDeque;
	std::deque< std::pair<int, int> >	retDeq;
	std::deque< std::pair<int, int> >	sortedDeq;
	
	if (d.size() == 1)
		return(d);
   	if (d.size() & 1)
		oddDeque.push_back(d[d.size() - 1]);

	deqPairs  = makeDequeOfPairs (d);
	d 		  = clearAndFillNewDequePairs(d, deqPairs);
	retDeq    = mergeInsertionSortDeq(d);
	sortedDeq = InsertInSoredDeque(sortedDeq, retDeq, deqPairs, oddDeque);

	return(sortedDeq);
}

void	PmergeMe::displaylastLine(unsigned long start, unsigned long end, std::deque<int>  &d)
{
	std::cout << "Time to process a range of   " << d.size() << " elements with std::deque<int>  : ";
	std::cout << cpuTimeUsed(start, end) << " us" << std::endl;	
}

void	PmergeMe::mergeInsertionSort()
{
	std::vector<int>					sortedVec;
	std::deque<int>						sortedDeq;
	std::vector< std::pair<int, int> >	sortedVecPair;
	std::vector< std::pair<int, int> >	indexVec;
	std::deque< std::pair<int, int> >	sortedDeqPair;
	std::deque< std::pair<int, int> >	indexDeq;
	struct timeval 						tv;
	
	displayFirstLineVec();
	
	gettimeofday(&tv, NULL);
	unsigned long startVec = 1000000 * tv.tv_sec + tv.tv_usec;
	
	indexVec = indexedVectorOfPairs(vect);
	sortedVecPair = mergeInsertionSortVec(indexVec);
	sortedVec	  = sortedVector(sortedVecPair);

	gettimeofday(&tv, NULL);
	unsigned long endVec = 1000000 * tv.tv_sec + tv.tv_usec;
	
	displaySecondLineVec(sortedVec);
	
	gettimeofday(&tv, NULL);
	unsigned long startDeq = 1000000 * tv.tv_sec + tv.tv_usec;
	
	indexDeq      = indexedDequeOfPairs(deq);
	sortedDeqPair = mergeInsertionSortDeq(indexDeq);
	sortedDeq     = sortedDeque(sortedDeqPair);
	
	gettimeofday(&tv, NULL);
	unsigned long endDeq = 1000000 * tv.tv_sec + tv.tv_usec;
	
	displaythirdLine(startVec, endVec, sortedVec);
	displaylastLine(startDeq, endDeq, sortedDeq);
}
