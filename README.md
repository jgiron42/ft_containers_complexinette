# ft_containers_complexinette
profiling a base de regression non lineaire pour le projet ft_containers de 42

this tester use my lib_complexinette to find the complexities of your ft_containers then compare it to what the ISO specify.
⚠️ this tester only work on linux 🐧

## usage

```
git clone --recurse-submodules https://github.com/jgiron42/ft_containers_complexinette.git
cd ft_containers_complexinette
export INCLUDES=<path_to_your_includes_separated_by_space>
make
sudo ./ft_containers_complexinette
```

you may have to edit the file `includes.hpp`

if you want to run this tester without sudo you can enable perf event monitoring for all users with `sudo sh -c 'echo 1 >/proc/sys/kernel/perf_event_paranoid'`


![img](https://i.ibb.co/2Ynz8jD/Screenshot-from-2022-03-13-23-28-33.png)
