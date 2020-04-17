/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** strcspn_test.c
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static void *open_asm()
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	return (handle);
}

void *load_sym(const char *sym_name)
{
	void *sym = dlsym(open_asm(), sym_name);
	const char *format = "\n-----\n\n";

	if (sym == NULL) {
		fprintf(stderr, "%s%s symbol doesn't exists, missing in Makefile?\n%s",
			format, sym_name, format);
		exit(EXIT_FAILURE);
	}
	return (dlsym(open_asm(), sym_name));
}

static size_t my_strcspn(const char *s1, const char *s2)
{
	static size_t (*sym)(const char *, const char *) = NULL;

	if (sym)
		return (sym(s1, s2));
	sym = load_sym("strcspn");
	return (sym(s1, s2));
}

static void test_strcspn(const char *s1, const char *s2)
{
	size_t mine = my_strcspn(s1, s2);
	size_t other = strcspn(s1, s2);

	cr_expect_eq(mine, other,
		"('%s', '%s') -> actual: %lu, expected: %lu",
		s1, s2, mine, other);
}

Test(my_strcspn, not_found)
{
	test_strcspn("", "");
	test_strcspn("", "a");
	test_strcspn("abcd", "f");
	test_strcspn("a", "");
}

Test(my_strcspn, found_one_char)
{
	test_strcspn("a", "a");
	test_strcspn("ab", "b");
	test_strcspn("abc", "b");
}

Test(my_strcspn, found_string)
{
	test_strcspn("b bc", "bc");
	test_strcspn("b bc toto", "bc ");
	test_strcspn("yyolo", "yolo");
	test_strcspn("totota", "tota");
	test_strcspn("o", "lo");
	test_strcspn("hehlo", "lo");
	test_strcspn("fdsadsf", "iuosj");
	test_strcspn("abcdef", "uiyptjlf");
}
