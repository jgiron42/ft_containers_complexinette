//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_VECTOR_INSERT_COUNT_HPP
#define COMPLEXINETTE_WRAPPED_VECTOR_INSERT_COUNT_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

template <int version>
class vector_insert_count : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::vector<int> current;
	int count;
	NAMESPACE::vector<int>::iterator	pos;
	vector_insert_count(int n) : lib_complexinette::measurable_class(n)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		if (version == 1)
		{
			count = n;
			current = get_random_vector((1 + (rand() % 10)));
			current.reserve(current.size() + n + 1);
			pos = current.end();
		}
		else if (version == 2)
		{
			count = 1;
			current = get_random_vector(n * (1 + (rand() % 10)));
			current.reserve(current.size() + 1);
			pos = current.end() - n;
		}
	}
	void	operator()(void)
	{
		current.insert(pos, count, 1);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
