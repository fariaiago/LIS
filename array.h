#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct
{
	int val;
	int pos;
}
Item;


typedef struct
{
	size_t len;
	size_t capacity;
	Item *items;
}
Array;

Array *Array_new();

Array *Array_of(int n, ...);

Array *Array_with(int size);

Array *Array_copy(Array *array);

bool Array_append(Array *array, int val, int pos);

bool Array_prepend(Array *array, int val, int pos);

void Array_free(Array *array);

#endif