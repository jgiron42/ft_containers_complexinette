//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_ERASE_KEY_HPP
#define COMPLEXINETTE_WRAPPED_ERASE_KEY_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class erase_key : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::map<int, int> current;
	NAMESPACE::map<int, int>::key_type to_erase;
	erase_key(int n) : lib_complexinette::measurable_class(n)
	{
	}
	void set(void)
	{
		current = get_random_map(n);
		to_erase = rand();
	}
	void	operator()(void)
	{
		current.erase(to_erase);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
