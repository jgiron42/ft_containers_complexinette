//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_INSERT_HPP
#define COMPLEXINETTE_WRAPPED_INSERT_HPP
#include "../../lib_complexinette/measurable_concept.hpp"
#include "../../ft_containers_complexinette.hpp"
#include <stdlib.h>

class map_insert_one : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::map<int, int> current;
	NAMESPACE::pair<const int, int> *to_insert;
	map_insert_one(int n) : lib_complexinette::measurable_class(n), to_insert(NULL)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		auto tmp = get_random_map(n);
		current = NAMESPACE::map<int, int>(tmp.begin(), tmp.end());
		int key = rand();
		delete to_insert ;
		to_insert = new NAMESPACE::pair<const int, int>(key, key);
	}
	void	operator()(void)
	{
		current.insert(*to_insert);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
