//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_VECTOR_CONSTRUCTOR_COUNT_HPP
#define COMPLEXINETTE_WRAPPED_VECTOR_CONSTRUCTOR_COUNT_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_constructor_count : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::vector<int> current;
	int count;
	vector_constructor_count(int n) : lib_complexinette::measurable_class(n)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		count = n;
		current = get_random_vector((1 + (rand() % 10)));
	}
	void	operator()(void)
	{
		NAMESPACE::vector<int>(count, 1);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
