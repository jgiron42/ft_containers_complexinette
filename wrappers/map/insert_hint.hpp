//
// Created by joachim on 3/12/22.
//

#ifndef COMPLEXINETTE_WRAPPED_INSERT_HINT_HPP
#define COMPLEXINETTE_WRAPPED_INSERT_HINT_HPP
#include "measurable_class.hpp"
#include "ft_containers_complexinette.hpp"
#include <stdlib.h>

class insert_hint : public lib_complexinette::measurable_class
{
public:
	NAMESPACE::map<int, int> current;
	NAMESPACE::map<int, int>::iterator hint;
	NAMESPACE::pair<const int, int> *to_insert;
	insert_hint(int n) : lib_complexinette::measurable_class(n), to_insert(NULL)
	{
		srand(time(NULL));
	}
	void set(void)
	{
		auto tmp = get_random_map(n);
		current = NAMESPACE::map<int, int>(tmp.begin(), tmp.end());
		int key = rand();
		delete to_insert ;
		hint = current.begin();
		for (int i = 1; i < rand() % current.size(); i++)
			hint++;
		to_insert = new NAMESPACE::pair<const int, int>(hint->first + 1, hint->first + 1);
	}
	void	operator()(void)
	{
		current.insert(hint, *to_insert);
	}
};


#endif //COMPLEXINETTE_WRAPPED_INSERT_HPP
