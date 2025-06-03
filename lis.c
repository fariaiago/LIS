#include "mergesort.h"
#include "array.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void combine_list(int *X, int i, int j, int m_e)
{}

void divide_lis(int *X, int i, int j, int *pred, int *Xsorted)
{
	if (i == j)
	{
		pred[i] = 0;
	}
	else if (j > i)
	{
		int n = j - i + 1;
		int x = (int) floor((j - i + 1) / 2.0);
		int m_e = Xsorted[i + x - 1];
		Array *Y1 = Array_new();
		Array *Y2 = Array_new();
		for (size_t k = 0; k < n; k++)
		{
			if (X[k] < m_e)
			{
				Array_append(Y1,X[k]);
			}
			else
			{
				Array_append(Y2, X[k]);
			}
		}
		divide_lis(Y1->items, i, i + x - 1, pred, Xsorted);
		divide_lis(Y2->items, x + i, j, pred, Xsorted);
	}
}

int main(void)
{
	// divide_lis();
}