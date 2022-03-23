//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_VECTOR_INSERT_RANGE_HPP
#define COMPLEXINETTE_WRAPPED_VECTOR_INSERT_RANGE_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class vector_insert_range : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::vector<int> to_insert;
	NAMESPACE::vector<int>	current;
	NAMESPACE::vector<int>::iterator	pos;
	vector_insert_range(int n) : lib_complexinette::measurable_class(n)
	{
		srand(0);
	}
	void set(void)
	{
		int insert_size;

		insert_size = n - rand() % n;
		to_insert = get_random_vector(insert_size);
		current = get_random_vector(2 * (n - insert_size));
		current.reserve(current.size() + insert_size + 1);
		pos = current.begin() + (n - insert_size);
	}
	void	operator()(void)
	{
		current.insert(pos, to_insert.begin(), to_insert.end());
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
