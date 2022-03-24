//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_VECTOR_CONSTRUCTOR_COPY_HPP
#define COMPLEXINETTE_WRAPPED_VECTOR_CONSTRUCTOR_COPY_HPP
#include "../../lib_complexinette/measurable_concept.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_constructor_copy : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::vector<int> to_copy;
	vector_constructor_copy(int n) : lib_complexinette::measurable_class(n)
	{
	}
	void set(void)
	{
		to_copy = get_random_vector(n);
	}
	void	operator()(void)
	{
		(void)NAMESPACE::vector<int>(to_copy);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
