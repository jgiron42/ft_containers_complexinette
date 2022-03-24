//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_VECTOR_CONSTRUCTOR_range_HPP
#define COMPLEXINETTE_WRAPPED_VECTOR_CONSTRUCTOR_range_HPP
#include "measurable_concept.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_constructor_range : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::vector<int> to_insert;
	vector_constructor_range(int n) : lib_complexinette::measurable_class(n)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		to_insert = get_random_vector(n);
	}
	void	operator()(void)
	{
		(void)NAMESPACE::vector<int>(to_insert.begin(), to_insert.end());
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
