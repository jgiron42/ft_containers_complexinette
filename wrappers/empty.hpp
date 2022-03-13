//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_EMPTY_HPP
#define FT_CONTAINERS_COMPLEXINETTE_EMPTY_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class empty : public lib_complexinette::measurable_class
{
	public:
	NAMESPACE::map<int, int> current;

	empty(int n) : lib_complexinette::measurable_class(n)
	{
	}

	void set(void)
	{
		current = get_random_map(n);
	}
	void	operator()(void)
	{
		current.empty();
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_EMPTY_HPP
