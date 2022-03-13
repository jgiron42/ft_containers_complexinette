//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_CONSTRUCTOR_range_HPP
#define COMPLEXINETTE_WRAPPED_CONSTRUCTOR_range_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

template <bool is_sorted>
class constructor_range : public lib_complexinette::measurable_class
{
public:
	std::vector<NAMESPACE::map<int, int>::value_type> to_insert;
	constructor_range(int n) : lib_complexinette::measurable_class(n)
	{
		srand(0);
	}
	void set(void)
	{
		to_insert.clear();
		if (is_sorted)
		{
			auto tmp = get_random_map(n);
//			to_insert.insert(to_insert.begin(), tmp.begin(), tmp.end());
			for (auto i = tmp.begin(); i != tmp.end(); i++)
				to_insert.push_back(*i);
		}
		else
		{
			auto tmp = get_random_array<int>(n);
			for (int i = 0; i < n; i++)
				to_insert.push_back(NAMESPACE::map<int, int>::value_type(tmp[i], tmp[i]));
		}
	}
	void	operator()(void)
	{
		(void)NAMESPACE::map<int, int>(to_insert.begin(), to_insert.end());
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
