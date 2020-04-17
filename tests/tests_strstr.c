/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** description
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>

static char *load_strstr(char const *str, char const *s)
{
	void *handle;
	static char *(*my_strstr)(char const *, char const *) = NULL;

	handle = dlopen("./libasm.so", RTLD_LAZY);
	if (my_strstr != NULL)
		return (my_strstr(str, s));
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	my_strstr = dlsym(handle, "strstr");
	return (0);
}

Test(strstr, basic_strstr)
{
	load_strstr("", "");
	cr_assert_str_eq(load_strstr("toto", "ot"), strstr("toto", "ot"));
	cr_assert_str_eq(load_strstr("hello world", " wor"), strstr("hello world", " wor"));
	cr_assert_str_eq(load_strstr("hello world", "\0"), strstr("hello world", "\0"));
	cr_assert_str_eq(load_strstr("hello world", ""), strstr("hello world", ""));
	cr_assert_eq(load_strstr("hello world", "foo bar"), strstr("hello world", "foo bar"));
	cr_assert_eq(load_strstr("hello world", "llo wod"), strstr("hello world", "llo wod"));
	cr_assert_eq(load_strstr("\0", "t"), strstr("\0", "t"));
}