#include "ft_containers_complexinette.hpp"
#include "wrappers/insert_one.hpp"
#include "wrappers/insert_hint.hpp"
#include "wrappers/insert_range.hpp"
#include "wrappers/upper_bound.hpp"
#include "wrappers/lower_bound.hpp"
#include "wrappers/equal_range.hpp"
#include "wrappers/count.hpp"
#include "wrappers/begin.hpp"
#include "wrappers/end.hpp"
#include "wrappers/constructor_default.hpp"
#include "wrappers/constructor_range.hpp"
#include "wrappers/constructor_copy.hpp"
#include "wrappers/destructor.hpp"
#include "wrappers/get_allocator.hpp"
#include "wrappers/size.hpp"
#include "wrappers/empty.hpp"
#include "wrappers/max_size.hpp"
#include "wrappers/clear.hpp"
#include "wrappers/erase_iterator.hpp"
#include "wrappers/erase_key.hpp"
#include "wrappers/erase_range.hpp"
#include "wrappers/swap.hpp"
#include "wrappers/find.hpp"
#include "wrappers/equal.hpp"
#include "wrappers/less.hpp"

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
	test_comp<equal<true> >(lib_complexinette::LINEAR, "equal with same size");

	test_comp<insert_one>( lib_complexinette::LOG, "insert_one");
//	test_comp<insert_hint>( lib_complexinette::CONST, "insert_hint");
	test_comp<insert_range>( lib_complexinette::LINEARITHMIC, "insert_range");
	test_comp<upper_bound>(lib_complexinette::LOG, "upper_bound");
	test_comp<lower_bound>(lib_complexinette::LOG, "lower_bound");
	test_comp<equal_range>(lib_complexinette::LOG, "equal_range");
	test_comp<begin>(lib_complexinette::CONST, "begin");
	test_comp<end>(lib_complexinette::CONST, "end");
	test_comp<constructor_default>(lib_complexinette::CONST, "constructor_default");
	test_comp<constructor_range<true> >(lib_complexinette::LINEAR, "constructor_range sorted");
	test_comp<constructor_range<false> >(lib_complexinette::LINEARITHMIC, "constructor_range not sorted");
	test_comp<constructor_copy >(lib_complexinette::LINEAR, "constructor_copy");
	test_comp<destructor >(lib_complexinette::LINEAR, "destructor");
	test_comp<get_allocator>(lib_complexinette::CONST, "get_allocator");
	test_comp<empty>(lib_complexinette::CONST, "empty");
	test_comp<size>(lib_complexinette::CONST, "size");
	test_comp<max_size>(lib_complexinette::CONST, "max_size");
	test_comp<clear>(lib_complexinette::LINEAR, "clear");
//	test_comp<erase_iterator>(lib_complexinette::CONST, "erase_iterator");
	test_comp<erase_key>(lib_complexinette::LOG, "erase_key");
//	test_comp<erase_range>(lib_complexinette::LINEAR, "erase_range");
	test_comp<erase_key>(lib_complexinette::CONST, "swap");
	test_comp<count>(lib_complexinette::LOG, "count");
	test_comp<find>(lib_complexinette::LOG, "find");
	test_comp<equal<true> >(lib_complexinette::LINEAR, "equal with same size");
	test_comp<equal<false> >(lib_complexinette::CONST, "equal with different size");
	test_comp<less>(lib_complexinette::LINEAR, "less");
}
