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

struct job {
	std::string name;
	lib_complexinette::complexities expected;
	std::future<lib_complexinette::complexities> result;
};

template <Measurable C>
void launch_job(std::list<job *> &job_list, lib_complexinette::complexities wanted, std::string const &name)
{
	job *j = new job;
	j->name = name;
	j->expected = wanted;
	j->result = std::async(lib_complexinette::get_complexity<C>);
	job_list.push_back(j);
}

void get_result(job &j)
{
	j.result.wait();
	lib_complexinette::complexities result = j.result.get();
	std::string result_str;
	if (result <= j.expected)
		std::cout << SH_GREEN << "[OK]";
	else
		std::cout << SH_RED << "[KO]";
	if (result > lib_complexinette::SIGNALED)
		result_str = strsignal(result - lib_complexinette::SIGNALED);
	else
		result_str = lib_complexinette::names[result];
	std::cout << j.name << " complexity is: [" << result_str
	<< "] expected: [" << lib_complexinette::names[j.expected] << "]" << std::endl;
	std::cout << SH_WHITE;
}

void	test_map(std::list<job *> &job_list)
{
	launch_job<map_insert_one>(job_list, lib_complexinette::LOG, "map_insert_one");
//	launch_job<insert_hint>(job_list,  lib_complexinette::CONST, "insert_hint");
	launch_job<map_insert_range>(job_list, lib_complexinette::LINEARITHMIC, "map_insert_range");
	launch_job<map_upper_bound>(job_list, lib_complexinette::LOG, "map_upper_bound");
	launch_job<map_lower_bound>(job_list, lib_complexinette::LOG, "map_lower_bound");
	launch_job<map_equal_range>(job_list, lib_complexinette::LOG, "map_equal_range");
	launch_job<map_begin>(job_list, lib_complexinette::CONST, "map_begin");
	launch_job<map_end>(job_list, lib_complexinette::CONST, "map_end");
	launch_job<map_constructor_default>(job_list, lib_complexinette::CONST, "map_constructor_default");
	launch_job<map_constructor_range<true> >(job_list, lib_complexinette::LINEAR, "map_constructor_range sorted");
	launch_job<map_constructor_range<false> >(job_list, lib_complexinette::LINEARITHMIC, "map_constructor_range not sorted");
	launch_job<map_constructor_copy >(job_list, lib_complexinette::LINEAR, "map_constructor_copy");
	launch_job<map_destructor >(job_list, lib_complexinette::LINEAR, "map_destructor");
	launch_job<map_get_allocator>(job_list, lib_complexinette::CONST, "map_get_allocator");
	launch_job<map_empty>(job_list, lib_complexinette::CONST, "map_empty");
	launch_job<map_size>(job_list, lib_complexinette::CONST, "map_size");
	launch_job<map_max_size>(job_list, lib_complexinette::CONST, "map_max_size");
	launch_job<map_clear>(job_list, lib_complexinette::LINEAR, "map_clear");
//	launch_job<erase_iterator>(job_list, lib_complexinette::CONST, "erase_iterator");
	launch_job<map_erase_key>(job_list, lib_complexinette::LOG, "map_erase_key");
//	launch_job<erase_range>(job_list, lib_complexinette::LINEAR, "erase_range");
	launch_job<map_swap>(job_list, lib_complexinette::CONST, "map_swap");
	launch_job<map_count>(job_list, lib_complexinette::LOG, "map_count");
	launch_job<map_find>(job_list, lib_complexinette::LOG, "map_find");
	launch_job<map_equal<true> >(job_list, lib_complexinette::LINEAR, "map_equal with same size");
	launch_job<map_equal<false> >(job_list, lib_complexinette::CONST, "map_equal with different size");
	launch_job<map_less>(job_list, lib_complexinette::LINEAR, "map_less");
}

void test_vect(std::list<job *> &job_list)
{
	std::cout << "Test vector:" << std::endl;

	launch_job<vector_constructor_range>(job_list, lib_complexinette::LINEAR, "vector_constructor_range");
	launch_job<vector_constructor_default>(job_list, lib_complexinette::CONST, "vector_constructor_default");
	launch_job<vector_constructor_count>(job_list, lib_complexinette::LINEAR, "vector_constructor_count");
	launch_job<vector_constructor_copy>(job_list, lib_complexinette::LINEAR, "vector_constructor_copy");

	launch_job<vector_destructor>(job_list, lib_complexinette::LINEAR, "vector_destructor");

	//missing: operator=

	//missing: assign

	launch_job<vector_get_allocator >(job_list, lib_complexinette::CONST, "vector_get_allocator");

	launch_job<vector_at >(job_list, lib_complexinette::CONST, "vector_at");
	launch_job<vector_operator_index >(job_list, lib_complexinette::CONST, "vector_operator_index");

	launch_job<vector_front >(job_list, lib_complexinette::CONST, "front");
	launch_job<vector_back >(job_list, lib_complexinette::CONST, "back");

	launch_job<vector_begin>(job_list, lib_complexinette::CONST, "vector_begin");
	launch_job<vector_end>(job_list, lib_complexinette::CONST, "vector_end");

	launch_job<vector_empty>(job_list, lib_complexinette::CONST, "vector_empty");
	launch_job<vector_size>(job_list, lib_complexinette::CONST, "vector_size");
	launch_job<vector_max_size>(job_list, lib_complexinette::CONST, "vector_max_size");

	// missing: reserve

	launch_job<vector_capacity>(job_list, lib_complexinette::CONST, "vector_capacity");

	launch_job<vector_clear>(job_list, lib_complexinette::LINEAR, "vector_clear");

	launch_job<vector_insert_range<1> >(job_list, lib_complexinette::LINEAR, "insert_range v1");
	launch_job<vector_insert_range<2> >(job_list, lib_complexinette::LINEAR, "insert_range v2");
	launch_job<vector_insert_count<1> >(job_list, lib_complexinette::LINEAR, "insert_count v1");
	launch_job<vector_insert_count<2> >(job_list, lib_complexinette::LINEAR, "insert_count v2");
	launch_job<vector_insert_one >(job_list, lib_complexinette::LINEAR, "insert_one");

	launch_job<vector_erase_iterator>(job_list, lib_complexinette::LINEAR, "erase_iterator");

	//missing other erase

	//missing push_back

	//missing pop_back

	//missing resize

	launch_job<vector_swap>(job_list, lib_complexinette::CONST, "swap");

	launch_job<vector_equal<false> >(job_list, lib_complexinette::CONST, "equality with different size");
	launch_job<vector_equal<true> >(job_list, lib_complexinette::LINEAR, "equality with same size");
	launch_job<vector_less>(job_list, lib_complexinette::LINEAR, "less");
}

int main(int argc, char **argv)
{
	std::list<job *> job_list;
	test_vect(job_list);
	test_map(job_list);
	for ( auto i : job_list)
	{
		get_result(*i);
		delete i;
	}
}
