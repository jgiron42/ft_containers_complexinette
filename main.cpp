#include "ft_containers_complexinette.hpp"
#include "wrappers/map/map_insert_one.hpp"
#include "wrappers/map/insert_hint.hpp"
#include "wrappers/map/map_insert_range.hpp"
#include "wrappers/map/map_upper_bound.hpp"
#include "wrappers/map/map_lower_bound.hpp"
#include "wrappers/map/map_equal_range.hpp"
#include "wrappers/map/map_count.hpp"
#include "wrappers/map/map_begin.hpp"
#include "wrappers/map/map_end.hpp"
#include "wrappers/map/map_constructor_default.hpp"
#include "wrappers/map/map_constructor_range.hpp"
#include "wrappers/map/map_constructor_copy.hpp"
#include "wrappers/map/map_destructor.hpp"
#include "wrappers/map/map_get_allocator.hpp"
#include "wrappers/map/map_size.hpp"
#include "wrappers/map/map_empty.hpp"
#include "wrappers/map/map_max_size.hpp"
#include "wrappers/map/map_clear.hpp"
#include "wrappers/map/erase_iterator.hpp"
#include "wrappers/map/map_erase_key.hpp"
#include "wrappers/map/erase_range.hpp"
#include "wrappers/map/map_swap.hpp"
#include "wrappers/map/map_find.hpp"
#include "wrappers/map/map_equal.hpp"
#include "wrappers/map/map_less.hpp"

#include "wrappers/vector/vector_insert_one.hpp"
#include "wrappers/vector/vector_insert_range.hpp"
#include "wrappers/vector/vector_insert_count.hpp"
#include "wrappers/vector/vector_begin.hpp"
#include "wrappers/vector/vector_end.hpp"
#include "wrappers/vector/vector_capacity.hpp"
#include "wrappers/vector/vector_constructor_default.hpp"
#include "wrappers/vector/vector_constructor_range.hpp"
#include "wrappers/vector/vector_constructor_copy.hpp"
#include "wrappers/vector/vector_constructor_count.hpp"
#include "wrappers/vector/vector_at.hpp"
#include "wrappers/vector/vector_operator_index.hpp"
#include "wrappers/vector/vector_front.hpp"
#include "wrappers/vector/vector_back.hpp"
#include "wrappers/vector/vector_destructor.hpp"
#include "wrappers/vector/vector_get_allocator.hpp"
#include "wrappers/vector/vector_size.hpp"
#include "wrappers/vector/vector_empty.hpp"
#include "wrappers/vector/vector_max_size.hpp"
#include "wrappers/vector/vector_clear.hpp"
#include "wrappers/vector/vector_erase_iterator.hpp"
#include "wrappers/vector/vector_erase_iterator.hpp"
#include "wrappers/vector/erase_range.hpp"
#include "wrappers/vector/vector_swap.hpp"
#include "wrappers/vector/vector_equal.hpp"
#include "wrappers/vector/vector_less.hpp"

template <Measurable C>
void test_comp(lib_complexinette::complexities wanted, std::string const &name)
{
	lib_complexinette::complexities result = lib_complexinette::get_complexity<C>();

	if (result <= wanted)
		std::cout << SH_GREEN << "[OK]";
	else
		std::cout << SH_RED << "[KO]";
	std::cout << name << " complexity is: [" << lib_complexinette::names[result]
	<< "] expected: [" << lib_complexinette::names[wanted] << "]" << std::endl;
	std::cout << SH_WHITE;
}

void	test_map()
{
	std::cout << "Test map:" << std::endl;

	test_comp<map_insert_one>(lib_complexinette::LOG, "map_insert_one");
//	test_comp<insert_hint>( lib_complexinette::CONST, "insert_hint");
	test_comp<map_insert_range>(lib_complexinette::LINEARITHMIC, "map_insert_range");
	test_comp<map_upper_bound>(lib_complexinette::LOG, "map_upper_bound");
	test_comp<map_lower_bound>(lib_complexinette::LOG, "map_lower_bound");
	test_comp<map_equal_range>(lib_complexinette::LOG, "map_equal_range");
	test_comp<map_begin>(lib_complexinette::CONST, "map_begin");
	test_comp<map_end>(lib_complexinette::CONST, "map_end");
	test_comp<map_constructor_default>(lib_complexinette::CONST, "map_constructor_default");
	test_comp<map_constructor_range<true> >(lib_complexinette::LINEAR, "map_constructor_range sorted");
	test_comp<map_constructor_range<false> >(lib_complexinette::LINEARITHMIC, "map_constructor_range not sorted");
	test_comp<map_constructor_copy >(lib_complexinette::LINEAR, "map_constructor_copy");
	test_comp<map_destructor >(lib_complexinette::LINEAR, "map_destructor");
	test_comp<map_get_allocator>(lib_complexinette::CONST, "map_get_allocator");
	test_comp<map_empty>(lib_complexinette::CONST, "map_empty");
	test_comp<map_size>(lib_complexinette::CONST, "map_size");
	test_comp<map_max_size>(lib_complexinette::CONST, "map_max_size");
	test_comp<map_clear>(lib_complexinette::LINEAR, "map_clear");
//	test_comp<erase_iterator>(lib_complexinette::CONST, "erase_iterator");
	test_comp<map_erase_key>(lib_complexinette::LOG, "map_erase_key");
//	test_comp<erase_range>(lib_complexinette::LINEAR, "erase_range");
	test_comp<map_swap>(lib_complexinette::CONST, "map_swap");
	test_comp<map_count>(lib_complexinette::LOG, "map_count");
	test_comp<map_find>(lib_complexinette::LOG, "map_find");
	test_comp<map_equal<true> >(lib_complexinette::LINEAR, "map_equal with same size");
	test_comp<map_equal<false> >(lib_complexinette::CONST, "map_equal with different size");
	test_comp<map_less>(lib_complexinette::LINEAR, "map_less");
}

void test_vect(void)
{
	std::cout << "Test vector:" << std::endl;

	test_comp<vector_constructor_range>(lib_complexinette::LINEAR, "vector_constructor_range");
	test_comp<vector_constructor_default>(lib_complexinette::CONST, "vector_constructor_default");
	test_comp<vector_constructor_count>(lib_complexinette::LINEAR, "vector_constructor_count");
	test_comp<vector_constructor_copy>(lib_complexinette::LINEAR, "vector_constructor_copy");

	test_comp<vector_destructor>(lib_complexinette::LINEAR, "vector_destructor");

	//missing: operator=

	//missing: assign

	test_comp<vector_get_allocator >(lib_complexinette::CONST, "vector_get_allocator");

	test_comp<vector_at >(lib_complexinette::CONST, "vector_at");
	test_comp<vector_operator_index >(lib_complexinette::CONST, "vector_operator_index");

	test_comp<vector_front >(lib_complexinette::CONST, "front");
	test_comp<vector_back >(lib_complexinette::CONST, "back");

	test_comp<vector_begin>(lib_complexinette::CONST, "vector_begin");
	test_comp<vector_end>(lib_complexinette::CONST, "vector_end");

	test_comp<vector_empty>(lib_complexinette::CONST, "vector_empty");
	test_comp<vector_size>(lib_complexinette::CONST, "vector_size");
	test_comp<vector_max_size>(lib_complexinette::CONST, "vector_max_size");

	// missing: reserve

	test_comp<vector_capacity>(lib_complexinette::CONST, "vector_capacity");

	test_comp<vector_clear>(lib_complexinette::LINEAR, "vector_clear");

	test_comp<vector_insert_range<1> >(lib_complexinette::LINEAR, "insert_range v1");
	test_comp<vector_insert_range<2> >(lib_complexinette::LINEAR, "insert_range v2");
	test_comp<vector_insert_count<1> >(lib_complexinette::LINEAR, "insert_count v1");
	test_comp<vector_insert_count<2> >(lib_complexinette::LINEAR, "insert_count v2");
	test_comp<vector_insert_one >(lib_complexinette::LINEAR, "insert_one");

	test_comp<vector_erase_iterator>(lib_complexinette::LINEAR, "erase_iterator");

	//missing other erase

	//missing push_back

	//missing pop_back

	//missing resize

	test_comp<vector_swap>(lib_complexinette::CONST, "swap");

	test_comp<vector_equal<false> >(lib_complexinette::CONST, "equality with different size");
	test_comp<vector_equal<true> >(lib_complexinette::LINEAR, "equality with same size");
	test_comp<vector_less>(lib_complexinette::LINEAR, "less");
}

int main(int argc, char **argv)
{
	test_vect();
	test_map();
}
