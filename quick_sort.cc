/**
 * 插入排序
 */
#include <iostream>

void quick_sort_main(int* a, int left, int right);

void quick_sort(int* a, int n) {
  quick_sort_main(a, 0, n - 1);
}

int partition(int* a, int left, int right) {
  int key = a[left];
  while (left < right) {
    while (a[right] > key && left < right) --right;
    if (left < right) {
      a[left++] = a[right];
    }
    while (a[left] < key && left < right) ++left;
    if (left < right) {
      a[right--] = a[left];
    }
  }

  a[left] = key;

  return left;
}

void quick_sort_main(int* a, int left, int right) {
  if (left < right) {
    int div_ix = partition(a, left, right); // div_ix位置上的元素是排好序放在正确的位置上了.
    quick_sort_main(a, left, div_ix - 1);
    quick_sort_main(a, div_ix + 1, right);
  }
}

