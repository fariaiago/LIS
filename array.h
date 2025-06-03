#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	size_t len;
	size_t capacity;
	int *items;
}
Array;

Array *Array_new();

bool Array_append(Array *array, int item);

bool Array_prepend(Array *array, int item);

void Array_free(Array *array);

#endif