//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_VECTOR_EQUAL_HPP
#define FT_CONTAINERS_COMPLEXINETTE_VECTOR_EQUAL_HPP
#include "../../lib_complexinette/measurable_class.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

template <bool equal_size>
class vector_equal : public lib_complexinette::measurable_class
{
	public:
	NAMESPACE::vector<int> v1;
	NAMESPACE::vector<int> v2;

	vector_equal(int n) : lib_complexinette::measurable_class(n)
	{
	}

	void set(void)
	{
		v1 = get_random_vector(n);
		v2 = v1;
		if (equal_size)
			v2.back()++;
		else
			v2.push_back(12);
	}
	void	operator()(void)
	{
		(void)(v1 == v2);
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_VECTOR_EQUAL_HPP
