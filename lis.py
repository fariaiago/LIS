import math

def merge(arr, l, m, r):
	n1 = m - l + 1
	n2 = r - m

	# create temp arrays
	L = [0] * (n1)
	R = [0] * (n2)

	# Copy data to temp arrays L[] and R[]
	for i in range(0, n1):
		L[i] = arr[l + i]

	for j in range(0, n2):
		R[j] = arr[m + 1 + j]

	# Merge the temp arrays back into arr[l..r]
	i = 0     # Initial index of first subarray
	j = 0     # Initial index of second subarray
	k = l     # Initial index of merged subarray

	while i < n1 and j < n2:
		if L[i] <= R[j]:
			arr[k] = L[i]
			i += 1
		else:
			arr[k] = R[j]
			j += 1
		k += 1

	# Copy the remaining elements of L[], if there
	# are any
	while i < n1:
		arr[k] = L[i]
		i += 1
		k += 1

	# Copy the remaining elements of R[], if there
	# are any
	while j < n2:
		arr[k] = R[j]
		j += 1
		k += 1

# l is for left index and r is right index of the
# sub-array of arr to be sorted

def mergeSort(arr, l, r):
	if l < r:

		# Same as (l+r)//2, but avoids overflow for
		# large l and h
		m = l+(r-l)//2

		# Sort first and second halves
		mergeSort(arr, l, m)
		mergeSort(arr, m+1, r)
		merge(arr, l, m, r)

def divide_lis(X: list, i, j, pred):
	if i == j:
		pred[i] = 0
	elif j > i:
		n = j - i + 1
		x = math.floor((j - i + 1) / 2.0)
		Xsorted = X.copy()
		mergeSort(Xsorted, 0, len(Xsorted) - 1)
		m_e = Xsorted[i + x].val
		Y1 = []
		Y2 = []
		for k in range(0,n):
			if X[k] < m_e:
				Y1.append(X[k])
			else:
				Y2.append(X[k])
		divide_lis(Y1, i, i + x - 1, pred)
		divide_lis(Y2, x + i, j, pred)
		combine_lis(X, i, j, m_e, pred)

def combine_lis(X, i, j, m_e, pred):
	max_ind = 0, max_len = 0, longest_LIS_len = 0
	n = j - i + 1
	Knuth = []
	Knuth.append( 0, 0)
	int *is_present = []
	for r in range(0, n):
		k = pred[X[r].pos]
		j = is_present[k]
		if X[r].val <= m_e:
			if (longest_LIS_len <= j + 1):
				longest_LIS_len = j + 1
		else:
			if k == 0:
				j = longest_LIS_len
			else:
				if j == 0:
					Item *p = bin_search(X, longest_LIS_len, max_len, X->items[r].val)
					j = p->pos
		is_present[Knuthitems[j + 1].pos] = 0
		pred[X[r].pos] = Knuth[j].pos
		Knuth[j + 1].val = X[r].val
		Knuth[j + 1].pos = X[r].pos
		is_present[Xitems[r].pos] = j + 1
		if max_len <= j + 1:
			max_ind = X[r].pos
			max_len = j + 1
