/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** description
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

static size_t load_strlen(char const *str)
{
	void *handle;
	static size_t (*my_strlen)(char const *) = NULL;

	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (my_strlen != NULL)
		return (my_strlen(str));
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	my_strlen = dlsym(handle, "strlen");
	return (0);
}

Test(strlen, basic_strlen)
{
	load_strlen("");
	cr_assert_neq(load_strlen("toto"), 5);
	cr_assert_eq(load_strlen("toto"), strlen("toto"));
	cr_assert_eq(load_strlen("\n"), strlen("\n"));
	cr_assert_eq(load_strlen(""), strlen(""));
	cr_assert_eq(load_strlen("\0"), strlen("\0"));
	cr_assert_eq(load_strlen("paul\0toto"), strlen("paul\0toto"));
	cr_assert_eq(load_strlen("toto-tata"), strlen("toto-tata"));
}