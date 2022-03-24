//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_VECTOR_INSERT_RANGE_HPP
#define COMPLEXINETTE_WRAPPED_VECTOR_INSERT_RANGE_HPP
#include "measurable_concept.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

template <int version>
class vector_insert_range : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::vector<int> to_insert;
	NAMESPACE::vector<int>	current;
	NAMESPACE::vector<int>::iterator	pos;
	vector_insert_range(int n) : lib_complexinette::measurable_class(n)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		if (version == 1)
		{
			to_insert = get_random_vector(n);
			current = get_random_vector((1 + (rand() % 10)));
			current.reserve(current.size() + n + 1);
			pos = current.end();
		}
		else if (version == 2)
		{
			to_insert = get_random_vector(1);
			current = get_random_vector(n * (1 + (rand() % 10)));
			current.reserve(current.size() + 1);
			pos = current.end() - n;
		}
	}
	void	operator()(void)
	{
		current.insert(pos, to_insert.begin(), to_insert.end());
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
