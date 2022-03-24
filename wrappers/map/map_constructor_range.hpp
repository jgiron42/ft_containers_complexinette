//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_CONSTRUCTOR_range_HPP
#define COMPLEXINETTE_WRAPPED_CONSTRUCTOR_range_HPP
#include "measurable_concept.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

template <bool is_sorted>
class map_constructor_range : public lib_complexinette::measurable_class
{
public:
	std::vector<NAMESPACE::map<int, int>::value_type> to_insert;
	input_iterator<std::vector<NAMESPACE::map<int, int>::value_type>::iterator> begin;
	input_iterator<std::vector<NAMESPACE::map<int, int>::value_type>::iterator> end;
	map_constructor_range(int n) : lib_complexinette::measurable_class(n)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		to_insert.clear();
		if (is_sorted)
		{
			auto tmp = get_random_map(n);
//			to_insert.insert(to_insert.map_begin(), tmp.map_begin(), tmp.map_end());
			for (auto i = tmp.begin(); i != tmp.end(); i++)
				to_insert.push_back(*i);
		}
		else
		{
			auto tmp = get_random_array<int>(n);
			for (int i = 0; i < n; i++)
				to_insert.push_back(NAMESPACE::map<int, int>::value_type(tmp[i], tmp[i]));
		}
		begin = input_iterator<std::vector<NAMESPACE::map<int, int>::value_type>::iterator>(to_insert.begin());
		end = input_iterator<std::vector<NAMESPACE::map<int, int>::value_type>::iterator>(to_insert.end());
	}
	void	operator()(void)
	{
		(void)NAMESPACE::map<int, int>(begin, end);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
