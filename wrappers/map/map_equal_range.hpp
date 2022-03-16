//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_MAP_EQUAL_RANGE_HPP
#define FT_CONTAINERS_COMPLEXINETTE_MAP_EQUAL_RANGE_HPP
#include "../../lib_complexinette/measurable_class.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class map_equal_range : public lib_complexinette::measurable_class
{
public:
	long int n;
	NAMESPACE::map<int, int> current;
	int						to_search;
	map_equal_range(int n) : n(n), to_search(0)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		auto tmp = get_random_map(n);
		current = NAMESPACE::map<int, int>(tmp.begin(), tmp.end());
		to_search = rand();
	}
	void	operator()(void)
	{
		current.equal_range(to_search);
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_MAP_EQUAL_RANGE_HPP
