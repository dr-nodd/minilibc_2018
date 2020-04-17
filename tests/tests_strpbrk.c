/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** description
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

static char *load_strpbrk(char const *str, char const *s)
{
	void *handle;
	static char *(*my_strpbrk)(char const *, char const *) = NULL;

	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (my_strpbrk != NULL)
		return (my_strpbrk(str, s));
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	my_strpbrk = dlsym(handle, "strpbrk");
	return (0);
}

Test(strpbrk, basic_strpbrk)
{
	load_strpbrk("", "");
	cr_assert_str_eq(load_strpbrk("toto", "azerty"), strpbrk("toto", "azerty"));
	cr_assert_eq(load_strpbrk("toto", "azer"), strpbrk("toto", "azer"));
	cr_assert_eq(load_strpbrk("toto", ""), strpbrk("toto", ""));
	cr_assert_str_eq(load_strpbrk("toto", "azertyuiop"), strpbrk("toto", "azertyuiop"));
	cr_assert_eq(load_strpbrk("toto", "\0"), strpbrk("toto", "\0"));
	cr_assert_eq(load_strpbrk("\0", "t"), strpbrk("\0", "t"));
}