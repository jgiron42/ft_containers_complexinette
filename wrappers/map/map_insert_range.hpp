//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_INSERT_RANGE_HPP
#define COMPLEXINETTE_WRAPPED_INSERT_RANGE_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class map_insert_range : public lib_complexinette::measurable_class
{
public:
	std::vector<NAMESPACE::map<int, int>::value_type> to_insert;
	NAMESPACE::map<int, int>	current;
	map_insert_range(int n) : lib_complexinette::measurable_class(n)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		int insert_size;

		insert_size = n - rand() % n;
		to_insert.clear();
		auto tmp = get_random_array<int>(insert_size);
		for (int i = 0; i < insert_size; i++)
			to_insert.push_back(NAMESPACE::map<int, int>::value_type(tmp[i], tmp[i]));
		current = get_random_map(n - insert_size);
	}
	void	operator()(void)
	{
		current.insert(to_insert.begin(), to_insert.end());
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
