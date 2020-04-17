/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** description
*/


#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

static char *load_strchr(char const *str, char c)
{
	void *handle;
	static char *(*my_strchr)(char const *, char) = NULL;

	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (my_strchr != NULL)
		return (my_strchr(str, c));
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	my_strchr = dlsym(handle, "strlen");
	return (0);
}

Test(strchr, basic_strchr)
{
	load_strchr("", 0);
	cr_assert_neq(load_strchr("toto", 't'), strchr("toto", 't'));
	cr_assert_neq(load_strchr("toto", 'o'), strchr("toto", 'o'));
	cr_assert_neq(load_strchr("toto", 'a'), strchr("toto", 'a'));
	cr_assert_neq(load_strchr("toto", 0), strchr("toto", 0));
}