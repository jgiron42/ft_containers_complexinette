//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_VECTOR_CONSTRUCTOR_DEFAULT_HPP
#define FT_CONTAINERS_COMPLEXINETTE_VECTOR_CONSTRUCTOR_DEFAULT_HPP
#include "../../lib_complexinette/measurable_concept.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>


class vector_constructor_default : public lib_complexinette::measurable_class
{
public:
	vector_constructor_default(int n) {}
	void	operator()(void)
	{
		(void)NAMESPACE::vector<int>();
	}
};

#endif //FT_CONTAINERS_COMPLEXINETTE_VECTOR_CONSTRUCTOR_DEFAULT_HPP
