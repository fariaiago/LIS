#include "array.h"
#include <string.h>


Array *Array_new()
{
	Array *array = malloc(sizeof(Array));
	if (array)
	{
		array->capacity = 10;
		array->len = 0;
		array->items = calloc(10, sizeof(Item));
	}
	return array;
}


Array *Array_of(int n, ...)
{
	Array *array = Array_new();
	va_list args;
	va_start(args, n);
	for (size_t i = 0; i < n; i++)
	{
		Array_append(array, va_arg(args, int), i);
	}
	va_end(args);
	return array;
}

Array *Array_with(int size)
{
	Array *array = malloc(sizeof(Array));
	if (array)
	{
		array->capacity = size;
		array->len = 0;
		array->items = calloc(array->capacity, sizeof(Item));
	}
	return array;
}

Array *Array_copy(Array *og)
{
	Array *array = malloc(sizeof(Array));
	if (array)
	{
		array->capacity = og->capacity;
		array->len = og->len;
		array->items = calloc(og->capacity, sizeof(Item));
		memcpy(array, og, array->len * sizeof(Item));
	}
	return array;
}

bool Array_append(Array *array, int val, int pos)
{
	if (!array)
	{
		return false;
	}
	if (array->capacity == array->len)
	{
		array->items = realloc(array->items,
			array->capacity * 2 * sizeof(Item));
	}
	array->items[array->len].val = val;
	array->items[array->len].pos = pos;
	array->len++;
	return true;
}

// Item *Array_pop(Array *array)
// {
// 	if (!array)
// 	{
// 		return NULL;
// 	}
// 	array->len--;
// 	array->items[array->len].val = 0;
// 	array->items[array->len].pos = 0;
// 	return true;
// }

void Array_free(Array *array)
{
	free(array->items);
	free(array);
}