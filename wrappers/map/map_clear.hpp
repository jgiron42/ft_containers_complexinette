//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_CLEAR_HPP
#define COMPLEXINETTE_WRAPPED_CLEAR_HPP
#include "../../lib_complexinette/measurable_class.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class map_clear : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::map<int, int> *to_clear;
	map_clear(int n) : lib_complexinette::measurable_class(n)
	{
	}
	void set(void)
	{
		to_clear = new NAMESPACE::map<int, int>(get_random_map(n));
	}
	void	operator()(void)
	{
		to_clear->clear();
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
