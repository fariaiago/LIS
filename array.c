#include "array.h"

Array *Array_new()
{
	Array *array = malloc(sizeof(Array));
	if (array)
	{
		array->capacity = 10;
		array->len = 0;
		array->items = calloc(array->capacity, sizeof(int));
	}
	return array;
}

bool Array_append(Array *array, int item)
{
	if (!array)
	{
		return false;
	}
	if (array->capacity == array->len)
	{
		array->items = realloc(array->items,
			array->capacity * 2 * sizeof(int));
	}
	array->items[array->len] = item;
	array->len++;
	return true;
}

bool Array_pop(Array *array)
{
	if (!array)
	{
		return false;
	}
	array->len--;
	array->items[array->len] = 0;
	return true;
}

void Array_free(Array *array)
{}