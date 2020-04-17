/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** description
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

static char *load_rindex(char const *str, int c)
{
	void *handle;
	static char *(*my_rindex)(char const *, int) = NULL;

	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (my_rindex != NULL)
		return (my_rindex(str, c));
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	my_rindex = dlsym(handle, "rindex");
	return (0);
}

Test(rindex, basic_rindex)
{
	load_rindex("", 0);
	cr_assert_str_eq(load_rindex("toto", 't'), rindex("toto", 't'));
	cr_assert_str_eq(load_rindex("tata", 'a'), rindex("tata", 'a'));
	cr_assert_str_eq(load_rindex("Hello World", 'l'), rindex("Hello World", 'l'));
	cr_assert_str_eq(load_rindex("toto", '\0'), rindex("toto", '\0'));
	cr_assert_str_eq(load_rindex("toto32", '3'), rindex("toto32", '3'));
	cr_assert_null(load_rindex("tata", 'b'));
	cr_assert_null(load_rindex("Hello World", 'w'));
	cr_assert_null(load_rindex("\0", 'a'));
}