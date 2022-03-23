//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_VECTOR_INSERT_HPP
#define COMPLEXINETTE_WRAPPED_VECTOR_INSERT_HPP
#include "../../lib_complexinette/measurable_class.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_insert_one : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::vector<int> current;
	NAMESPACE::vector<int>::iterator pos;
	int to_insert;
	vector_insert_one(int n) : lib_complexinette::measurable_class(n)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		current = get_random_vector(n * (1 + (rand() % 10)));
		current.reserve(current.size() + 1);
		pos = current.end() - n;
		to_insert = 1;
	}
	void	operator()(void)
	{
		current.insert(pos, to_insert);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
