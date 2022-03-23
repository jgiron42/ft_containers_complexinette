//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_OPERATOR_EQUAL_HPP
#define COMPLEXINETTE_WRAPPED_OPERATOR_EQUAL_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class operator_equal : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::map<int, int> to_copy;
	NAMESPACE::map<int, int> tmp;
	operator_equal(int n) : lib_complexinette::measurable_class(n)
	{
	}
	void set(void)
	{
		to_copy = get_random_map(n);
		tmp.clear();
	}
	void	operator()(void)
	{
		tmp = to_copy;
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
