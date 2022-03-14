//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_DESTRUCTOR_HPP
#define COMPLEXINETTE_WRAPPED_DESTRUCTOR_HPP
#include "../../lib_complexinette/measurable_class.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class map_destructor : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::map<int, int> *to_destroy;
	map_destructor(int n) : lib_complexinette::measurable_class(n), to_destroy(NULL)
	{
	}
	~map_destructor()
	{
		free(to_destroy);
	}
	void set(void)
	{
		free(to_destroy);
		to_destroy = new NAMESPACE::map<int, int>(get_random_map(n));
	}
	void	operator()(void)
	{
		to_destroy->~map<int, int>();
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
