//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_VECTOR_SWAP_HPP
#define FT_CONTAINERS_COMPLEXINETTE_VECTOR_SWAP_HPP
#include "measurable_concept.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_swap : public lib_complexinette::measurable_class
{
	public:
	NAMESPACE::vector<int> v1;
	NAMESPACE::vector<int> v2;

	vector_swap(int n) : lib_complexinette::measurable_class(n)
	{
	}

	void set(void)
	{
		v1 = get_random_vector(n);
		v2 = get_random_vector(n);
	}
	void	operator()(void)
	{
		v1.swap(v2);
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_VECTOR_SWAP_HPP
