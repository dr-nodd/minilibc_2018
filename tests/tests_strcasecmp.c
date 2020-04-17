/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** description
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

static int load_strcasecmp(char const *str, char const *s)
{
	void *handle;
	static int (*my_strcasecmp)(char const *, char const *) = NULL;

	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (my_strcasecmp != NULL)
		return (my_strcasecmp(str, s));
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	my_strcasecmp = dlsym(handle, "strcasecmp");
	return (0);
}

Test(strcasecmp, basic_strcasecmp)
{
	load_strcasecmp("", "");
	cr_assert_eq(load_strcasecmp("toto", "toto"), strcasecmp("toto", "toto"));
	cr_assert_eq(load_strcasecmp("to to", "to to"), strcasecmp("to to", "to to"));
	cr_assert_eq(load_strcasecmp("tot1", "tot0"), strcasecmp("tot1", "tot0"));
	cr_assert_eq(load_strcasecmp("tot0", "tot0"), strcasecmp("tot0", "tot0"));
	cr_assert_eq(load_strcasecmp("toto", "ToTo"), strcasecmp("toto", "ToTo"));
	cr_assert_eq(load_strcasecmp("toto", "tOto"), strcasecmp("toto", "tOto"));
	cr_assert_eq(load_strcasecmp("totOa", "toto"), strcasecmp("totOa", "toto"));
	cr_assert_eq(load_strcasecmp("toto", ""), strcasecmp("toto", ""));
	cr_assert_eq(load_strcasecmp("toTo", ""), strcasecmp("toTo", ""));
	cr_assert_eq(load_strcasecmp("toto", "\0"), strcasecmp("toto", "\0"));
}