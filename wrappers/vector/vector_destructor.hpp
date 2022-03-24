//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_VECTOR_DESTRUCTOR_HPP
#define COMPLEXINETTE_WRAPPED_VECTOR_DESTRUCTOR_HPP
#include "../../lib_complexinette/measurable_concept.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_destructor : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::vector<int> *to_destroy;
	vector_destructor(int n) : lib_complexinette::measurable_class(n), to_destroy(NULL)
	{
	}
	~vector_destructor()
	{
		free(to_destroy);
	}
	void set(void)
	{
		free(to_destroy);
		to_destroy = new NAMESPACE::vector<int>(get_random_vector(n));
	}
	void	operator()(void)
	{
		to_destroy->~vector<int>();
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
