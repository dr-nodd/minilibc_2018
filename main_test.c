/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** description
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(void)
{
	char *str = strdup("toTo");
	char *str2 = strdup("totA");

	printf("%d\n", strcasecmp("totOa", "toto"));
	return 0;
}