//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_MAP_SWAP_HPP
#define FT_CONTAINERS_COMPLEXINETTE_MAP_SWAP_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class map_swap : public lib_complexinette::measurable_class
{
	public:
	NAMESPACE::map<int, int> m1;
	NAMESPACE::map<int, int> m2;

	map_swap(int n) : lib_complexinette::measurable_class(n)
	{
	}

	void set(void)
	{
		m1 = get_random_map(n);
		m2 = get_random_map(n);
	}
	void	operator()(void)
	{
		m1.swap(m2);
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_MAP_SWAP_HPP
