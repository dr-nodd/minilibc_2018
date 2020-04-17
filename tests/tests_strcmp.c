/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** description
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

static int load_strcmp(char const *str, char const *s)
{
	void *handle;
	static int (*my_strcmp)(char const *, char const *) = NULL;

	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (my_strcmp != NULL)
		return (my_strcmp(str, s));
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	my_strcmp = dlsym(handle, "strcmp");
	return (0);
}

Test(strcmp, basic_strcmp)
{
	load_strcmp("", "");
	cr_assert_eq(load_strcmp("toto", "t"), strcmp("toto", "t"));
	cr_assert_eq(load_strcmp("tata", "a"), strcmp("tata", "a"));
	cr_assert_eq(load_strcmp("Hello World", "Hello"),
		strcmp("Hello World", "Hello"));
	cr_assert_eq(load_strcmp("toto", "\0"), strcmp("toto", "\0"));
	cr_assert_eq(load_strcmp("toto", "toto32"), strcmp("toto", "toto32"));
	cr_assert_eq(load_strcmp("Hi", "hi"), strcmp("Hi", "hi"));
	cr_assert_eq(load_strcmp("Hi", "Hi"), strcmp("Hi", "Hi"));
	cr_assert_eq(load_strcmp("\0", "ta"), strcmp("\0", "ta"));
}