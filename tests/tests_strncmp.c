/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** description
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

static int load_strncmp(char const *str, char const *s, size_t n)
{
	void *handle;
	static int (*my_strncmp)(char const *, char const *, size_t) = NULL;

	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (my_strncmp != NULL)
		return (my_strncmp(str, s, n));
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	my_strncmp = dlsym(handle, "strncmp");
	return (0);
}

Test(strncmp, basic_strncmp)
{
	load_strncmp("", "", 0);
	cr_assert_eq(load_strncmp("toto", "t", 1), strncmp("toto", "t", 1));
	cr_assert_eq(load_strncmp("tata", "A", 3), strncmp("tata", "A", 3));
	cr_assert_eq(load_strncmp("Hello World", "Hello", 5),
		strncmp("Hello World", "Hello", 5));
	cr_assert_eq(load_strncmp("toto", "\0", 3), strncmp("toto", "\0", 3));
	cr_assert_eq(load_strncmp("toto", "toto32", 12), strncmp("toto", "toto32", 12));
	cr_assert_eq(load_strncmp("Hi", "hi", 0), strncmp("Hi", "hi", 0));
	cr_assert_eq(load_strncmp("Hi", "Hi", 1), strncmp("Hi", "Hi", 1));
	cr_assert_eq(load_strncmp("\0", "ta", 3), strncmp("\0", "ta", 3));
}