#include "mergesort.h"
#include "array.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(void *a, void *b)
{
	return ((Item *) a)->val - ((Item *) b)->val;
}

Item *bin_search(Array *X, int start, int end, int value)
{
	if (end - start <= 1)
	{
		return X->items[start].val < value ? &X->items[start] : NULL;
	}
	int half = (end - start) / 2;
	Item *l = bin_search(X, start, start + half, value);
	Item *r = bin_search(X, start + half + 1, end, value);
	if (!l)
	{
		return r;
	}
	else if (!r)
	{
		return l;
	}
	else
	{
		return r;
	}
}

void combine_lis(Array *X, int i, int j, int m_e, int *pred)
{
	int max_ind = 0, max_len = 0, longest_LIS_len = 0;
	int n = j - i + 1;
	Array *Knuth = Array_new();
	Array_append(Knuth, 0, 0);
	int *is_present = calloc(X->len, sizeof(int));
	for (size_t r = 0; r < n; r++)
	{
		int k = pred[X->items[r].pos];
		int j = is_present[k];
		if (X->items[r].val <= m_e)
		{
			if (longest_LIS_len <= j + 1)
			{
				longest_LIS_len = j + 1;
			}
		}
		else
		{
			if (k == 0)
			{
				j = longest_LIS_len;
			}
			else
			{
				if (j == 0)
				{
					Item *p = bin_search(X, longest_LIS_len, max_len, X->items[r].val);
					j = p->pos;
				}
			}
		}
		is_present[Knuth->items[j + 1].pos] = 0;
		pred[X->items[r].pos] = Knuth->items[j].pos;
		Knuth->items[j + 1].val = X->items[r].val;
		Knuth->items[j + 1].pos = X->items[r].pos;
		is_present[X->items[r].pos] = j + 1;
		if (max_len <= j + 1)
		{
			max_ind = X->items[r].pos;
			max_len = j + 1;
		}
	}
	Array_free(Knuth);
	free(is_present);
}

void divide_lis(Array *X, int i, int j, int *pred)
{
	if (i == j)
	{
		pred[i] = 0;
	}
	else if (j > i)
	{
		int n = j - i + 1;
		int x = (int) floor((j - i + 1) / 2.0);
		Array *Xsorted = Array_copy(X);
		// qsort(Xsorted->items, X->len - 1, sizeof(Item), (__compar_fn_t) &compare);
		int m_e = Xsorted->items[i + x].val;
		Array *Y1 = Array_new();
		Array *Y2 = Array_new();
		for (size_t k = 0; k < n; k++)
		{
			if (X->items[k].val < m_e)
			{
				Array_append(Y1, X->items[k].val, X->items[k].pos);
			}
			else
			{
				Array_append(Y2, X->items[k].val, X->items[k].pos);
			}
		}
		divide_lis(Y1, i, i + x - 1, pred);
		divide_lis(Y2, x + i, j, pred);
		combine_lis(X, i, j, m_e, pred);
		Array_free(Y1);
		Array_free(Y2);
	}
}

int main(void)
{
	Array *X = Array_of(10, 8, 9, 5, 2, 3, 7, 10, 4, 1, 6);
	int *pred = calloc(X->len, sizeof(int));
	divide_lis(X, 0, X->len - 1, pred);
}