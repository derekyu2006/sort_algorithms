/**
 * 插入排序
 */
#include <iostream>

void merge_sort_main(int* a, int left, int right);

void merge_sort(int* a, int n) {
  merge_sort_main(a, 0, n - 1);
}

void merge(int* a, int start, int mid, int end) {
  int* array = NULL;
  if (start > mid || end < mid) return;

  array = (int*)calloc((end - start + 1), sizeof(int));

  int i = start;
  int j = mid + 1;
  int k = 0;
  while ((i <= mid) && (j <= end)) {
    if (a[i] < a[j]) {
      array[k++] = a[i++];
    } else {
      array[k++] = a[j++];
    }
  }

  while (i <= mid) array[k++] = a[i++];
  while (j <= end) array[k++] = a[j++];

  for (int i = start, j = 0; i <= end; ++i, ++j) {
    a[i] = array[j];
  }

  free(array);
}

void merge_sort_main(int* a, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort_main(a, left, mid);
    merge_sort_main(a, mid + 1, right);
    merge(a, left, mid, right);
  }
}

