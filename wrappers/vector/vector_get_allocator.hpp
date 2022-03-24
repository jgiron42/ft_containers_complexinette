//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_VECTOR_GET_ALLOCATOR_HPP
#define FT_CONTAINERS_COMPLEXINETTE_VECTOR_GET_ALLOCATOR_HPP
#include "../../lib_complexinette/measurable_concept.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_get_allocator : public lib_complexinette::measurable_class
{
	public:
	NAMESPACE::vector<int> current;

	vector_get_allocator(int n) : lib_complexinette::measurable_class(n)
	{
	}

	void set(void)
	{
		current = get_random_vector(n);
	}
	void	operator()(void)
	{
		(void)current.get_allocator();
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_VECTOR_GET_ALLOCATOR_HPP
