//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_ERASE_RANGE_HPP
#define COMPLEXINETTE_WRAPPED_ERASE_RANGE_HPP
#include "measurable_concept.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class erase_range : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::map<int, int> current;
	NAMESPACE::map<int, int>::iterator begin;
	NAMESPACE::map<int, int>::iterator end;
	erase_range(int n) : lib_complexinette::measurable_class(n)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		current = get_random_map(n);
		begin = current.begin();
		for (int i = 1; i < rand() % (current.size() / 2 + current.size() % 2); i++)
			begin++;
		end = begin;
		for (int i = 1; i < (current.size() / 2); i++)
			end++;
	}
	void	operator()(void)
	{
		current.erase(begin, end);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
