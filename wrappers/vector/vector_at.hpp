//
// Created by joachim on 3/13/22.
//

#ifndef FT_CONTAINERS_COMPLEXINETTE_VECTOR_AT_HPP
#define FT_CONTAINERS_COMPLEXINETTE_VECTOR_AT_HPP
#include "../../lib_complexinette/measurable_class.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_at : public lib_complexinette::measurable_class
{
	public:
	NAMESPACE::vector<int> current;
	int index;

	vector_at(int n) : lib_complexinette::measurable_class(n)
	{
	}

	void set(void)
	{
		current = get_random_vector(n);
		index = rand() % n;
	}
	void	operator()(void)
	{
		current.at(index);
	}
};
#endif //FT_CONTAINERS_COMPLEXINETTE_VECTOR_AT_HPP
