#include "ft_containers_complexinette.hpp"

template <typename T>
T *get_random_array(long int n)
{
	T *ret = new T[n];
	static int fd = -1;

	if (n == -1)
	{
		close(fd);
		return NULL;
	}
	if (fd == -1)
	{
		fd = open("/dev/urandom", O_RDONLY);
		if (fd == -1)
		{
			perror("complexinette: open");
			exit(1);
		}
	}
	if (read(fd, ret, n * sizeof(T)) != n * sizeof(T))
	{
		perror("complexinette: read");
		exit(1);
	}
	return (ret);
}


//template <>
//NAMESPACE::pair<int const, int> *get_random_array(long int n)
//{
//	int *tmp = get_random_array<int>(n);
//	NAMESPACE::pair<int const, int> *ret = new NAMESPACE::pair<int const, int>[n];
//
//	for (int i = 0; i < n; i++)
//		ret[i] = NAMESPACE::pair<int const, int>(tmp[i], tmp[i]);
//	delete tmp;
//	return (ret);
//}

NAMESPACE::map<int, int> get_random_map(long int n)
{
	int *tmp = get_random_array<int>(n);
	NAMESPACE::map<int, int> ret;

	for (int i = 0; i < n; i++)
		ret[tmp[i]] = tmp[i];
	delete [] tmp;
	return (ret);
}

NAMESPACE::vector<int> get_random_vector(long int n)
{

	int *tmp = get_random_array<int>(n);
	NAMESPACE::vector<int> ret(tmp, tmp + n);
	delete [] tmp;
	return (ret);
}
