//
// mergesort.c
//
// MIT licensed.
// Copyright (c) Abraham Hernandez <abraham@abranhe.com>
//
#include "array.h"
#include <string.h>
#include <stdlib.h>

// Merge the two half into a sorted data.
void
merge(Array *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;

	// Create temp arrays
	Array *L = Array_new(), *R = Array_new();

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++)
		Array_append(L, arr->items[l + i].val, arr->items[l + i].pos);
	for (j = 0; j < n2; j++)
		Array_append(R, arr->items[m + 1+ j].val, arr->items[m + 1+ j].pos);

	// Merge the temp arrays back into arr[l..r]

	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray

	while (i < n1 && j < n2)
	{
		if (L->items[i].val <= R->items[j].val)
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[], if there are any
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted

void
mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for large l and h
		int m = l+(r-l)/2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}
