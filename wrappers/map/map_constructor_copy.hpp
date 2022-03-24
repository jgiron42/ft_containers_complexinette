//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_CONSTRUCTOR_COPY_HPP
#define COMPLEXINETTE_WRAPPED_CONSTRUCTOR_COPY_HPP
#include "../../lib_complexinette/measurable_concept.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class map_constructor_copy : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::map<int, int> to_copy;
	map_constructor_copy(int n) : lib_complexinette::measurable_class(n)
	{
	}
	void set(void)
	{
		to_copy = get_random_map(n);
	}
	void	operator()(void)
	{
		(void)NAMESPACE::map<int, int>(to_copy);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
