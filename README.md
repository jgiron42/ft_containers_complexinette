# ft_containers_complexinette (personal project)
profiling based on non linear regression for the 42 project ft_containers.

this program act more as a proof of concept than a usable tester because it involve a certain number of false positives and false negatives results. However this has been a very interesting (and I think innovative) project to do for me.

this tester use my lib_complexinette to find the complexities of your ft_containers then compare it to what the ISO specify.

⚠️ this tester only work on linux 🐧 (because it use linux perf)

:warning: this tester gives an **aproximation** of the complexity it is still under developement
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
