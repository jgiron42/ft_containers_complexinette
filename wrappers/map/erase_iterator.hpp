//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_ERASE_ITERATOR_HPP
#define COMPLEXINETTE_WRAPPED_ERASE_ITERATOR_HPP
#include "measurable_concept.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class erase_iterator : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::map<int, int> current;
	NAMESPACE::map<int, int>::iterator to_erase;
	erase_iterator(int n) : lib_complexinette::measurable_class(n)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		current = get_random_map(n);
		to_erase = current.begin();
		for (int i = 1; i < rand() % current.size(); i++)
			to_erase++;
	}
	void	operator()(void)
	{
		current.erase(to_erase);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
