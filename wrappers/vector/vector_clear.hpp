//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_VECTOR_CLEAR_HPP
#define COMPLEXINETTE_WRAPPED_VECTOR_CLEAR_HPP
#include "../../lib_complexinette/measurable_class.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_clear : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::vector<int> to_clear;
	vector_clear(int n) : lib_complexinette::measurable_class(n)
	{
	}
	void set(void)
	{
		to_clear = get_random_vector(n);
	}
	void	operator()(void)
	{
		to_clear.clear();
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
