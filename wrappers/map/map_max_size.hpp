//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_MAP_MAX_SIZE_HPP
#define FT_CONTAINERS_COMPLEXINETTE_MAP_MAX_SIZE_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class map_max_size : public lib_complexinette::measurable_class
{
	public:
	NAMESPACE::map<int, int> current;

	map_max_size(int n) : lib_complexinette::measurable_class(n)
	{
	}

	void set(void)
	{
		current = get_random_map(n);
	}
	void	operator()(void)
	{
		current.max_size();
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_MAP_MAX_SIZE_HPP
