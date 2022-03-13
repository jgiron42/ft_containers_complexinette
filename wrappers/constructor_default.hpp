//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_CONSTRUCTOR_DEFAULT_HPP
#define FT_CONTAINERS_COMPLEXINETTE_CONSTRUCTOR_DEFAULT_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>


class constructor_default : public lib_complexinette::measurable_class
{
public:
	constructor_default(int n) {}
	void	operator()(void)
	{
		(void)NAMESPACE::map<int, int>();
	}
};

#endif //FT_CONTAINERS_COMPLEXINETTE_CONSTRUCTOR_DEFAULT_HPP
