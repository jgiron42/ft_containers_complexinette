//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_VECTOR_ERASE_ITERATOR_HPP
#define COMPLEXINETTE_WRAPPED_VECTOR_ERASE_ITERATOR_HPP
#include "measurable_concept.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_erase_iterator : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::vector<int> current;
	NAMESPACE::vector<int>::iterator to_erase;
	vector_erase_iterator(int n) : lib_complexinette::measurable_class(n)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		current = get_random_vector(n * (1 + (rand() % 10)));
		to_erase = current.end() - n;
	}
	void	operator()(void)
	{
		current.erase(to_erase);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
