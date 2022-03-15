//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_MAP_UPPER_BOUND_HPP
#define FT_CONTAINERS_COMPLEXINETTE_MAP_UPPER_BOUND_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class map_upper_bound : public lib_complexinette::measurable_class
{
public:
	long int n;
	NAMESPACE::map<int, int> current;
	int						to_search;
	map_upper_bound(int n) : n(n), to_search(0)
	{
		srand(0);
	}
	void set(void)
	{
		auto tmp = get_random_map(n);
		current = NAMESPACE::map<int, int>(tmp.begin(), tmp.end());
		to_search = rand();
	}
	void	operator()(void)
	{
		current.upper_bound(to_search);
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_MAP_UPPER_BOUND_HPP