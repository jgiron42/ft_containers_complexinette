//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_VECTOR_LESS_HPP
#define FT_CONTAINERS_COMPLEXINETTE_VECTOR_LESS_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_less : public lib_complexinette::measurable_class
{
	public:
	NAMESPACE::vector<int> m1;
	NAMESPACE::vector<int> m2;

	vector_less(int n) : lib_complexinette::measurable_class(n)
	{
	}

	void set(void)
	{
		m1 = get_random_vector(n);
		m2 = m1;
	}
	void	operator()(void)
	{
		(void)(m1 < m2);
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_VECTOR_LESS_HPP
