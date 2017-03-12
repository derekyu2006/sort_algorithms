/**
 * 插入排序
 */
#include <iostream>

void select_sort(int* a, const int n) {
  for (int i = 0; i< n; ++i) {
    int min = i;
    int data = a[i];
    for (int j = i + 1; j < n; ++j) {
      if (data > a[j]) {
        data = a[j];
        min = j;
      }
    }

    int temp = a[min];
    a[min] = a[i];
    a[i] = temp;
  }
}


