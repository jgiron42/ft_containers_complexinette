//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_VECTOR_BEGIN_HPP
#define FT_CONTAINERS_COMPLEXINETTE_VECTOR_BEGIN_HPP
#include "../../lib_complexinette/measurable_class.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_begin : public lib_complexinette::measurable_class
{
	public:
	NAMESPACE::vector<int> current;

	vector_begin(int n) : lib_complexinette::measurable_class(n)
	{
	}

	void set(void)
	{
		current = get_random_vector(n);
	}
	void	operator()(void)
	{
		current.begin();
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_VECTOR_BEGIN_HPP
