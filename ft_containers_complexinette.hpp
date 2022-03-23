#ifndef FT_CONTAINERS_COMPLEXINETTE_H
#define FT_CONTAINERS_COMPLEXINETTE_H
#ifndef NAMESPACE
# define NAMESPACE std
#endif
#include "includes.hpp"
#include "shell_colors.hpp"
//#define COMPLEXINETTE_DEBUG
#include "complexinette.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <time.h>
#include "measurable_class.hpp"

template <typename T>
T *get_random_array(long int n);
NAMESPACE::map<int, int> get_random_map(long int n);
NAMESPACE::vector<int> get_random_vector(long int n);

#endif
