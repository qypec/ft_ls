cmake_minimum_required (VERSION 3.9)
project (ft_ls VERSION 0.1 LANGUAGES C)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
add_executable(ft_ls
        Makefile
        bust.c
        conclusion_without_flags.c
        flags.c
        ft_ls.c
        ft_ls.h
        init.c
        print.c
        push_back.c
        rec_penetration.c
        struct_filenames.c
        whatsspecific.c
        #struct_sort.c
        )
add_subdirectory(libft)
target_link_libraries(ft_ls libft)