//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_MAP_EQUAL_HPP
#define FT_CONTAINERS_COMPLEXINETTE_MAP_EQUAL_HPP
#include "../../lib_complexinette/measurable_concept.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

template <bool equal_size>
class map_equal : public lib_complexinette::measurable_class
{
	public:
	NAMESPACE::map<int, int> m1;
	NAMESPACE::map<int, int> m2;

	map_equal(int n) : lib_complexinette::measurable_class(n)
	{
	}

	void set(void)
	{
		m1 = get_random_map(n);
		m2 = m1;
		int to_insert = (--(m2.end()))->first + 1;
		if (equal_size)
		{
			m2.erase(--(m2.end()));
			m2[to_insert] = to_insert;
		}
		else
			m2[to_insert] = to_insert;
	}
	void	operator()(void)
	{
		(void)(m1 == m2);
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_MAP_EQUAL_HPP
