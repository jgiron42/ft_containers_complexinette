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
#include "wrappers/map/swap.hpp"
#include "wrappers/map/map_find.hpp"
#include "wrappers/map/map_equal.hpp"
#include "wrappers/map/map_less.hpp"

template <class C>
void test_comp(lib_complexinette::complexities wanted, std::string const &name)
{
	lib_complexinette::complexities result = lib_complexinette::get_complexity<C>();

	if (result <= wanted)
		std::cout << SH_GREEN;
	else
		std::cout << SH_RED;
	std::cout << name << " complexity is: [" << lib_complexinette::names[result]
	<< "] expected: [" << lib_complexinette::names[wanted] << "]" << std::endl;
	std::cout << SH_WHITE;
}

int main(int argc, char **argv)
{
	test_comp<map_equal<true> >(lib_complexinette::LINEAR, "map_equal with same map_size");

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
	test_comp<swap>(lib_complexinette::CONST, "swap");
	test_comp<map_count>(lib_complexinette::LOG, "map_count");
	test_comp<map_find>(lib_complexinette::LOG, "map_find");
	test_comp<map_equal<true> >(lib_complexinette::LINEAR, "map_equal with same size");
	test_comp<map_equal<false> >(lib_complexinette::CONST, "map_equal with different size");
	test_comp<map_less>(lib_complexinette::LINEAR, "map_less");
}
