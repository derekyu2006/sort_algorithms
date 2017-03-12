/**
 * 插入排序
 */
#include <iostream>

void insert_sort(int* a, const int n) {
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] > a[i]) { // 前边的元素是已经排好序的. 先判断一下是否需要插入
      int j = i - 1;
      for (; j >= 0; --j) { // 先找到要插入的位置
        if (a[j] > a[j + 1]) {
          int temp = a[j];
          a[j] = a[j + 1];
          a[j + 1] = temp;
        }
      }
    }
  }
}

void binary_insert_sort(int* a, const int n) {
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) { // 前边i - 1的元素是已经排好序的. 先判断一下是否需要插入
      int low = 0;
      int high = i - 1;
      int data = a[i];
      int mid = 0;
      while (low <= high) { // 特别注意
        mid = (low + high) / 2;
        if (data < a[mid]) high = mid - 1;
        if (data > a[mid]) low = mid + 1;
        if (data == a[mid]) break;
      }

      for (int ix = i; ix > low; --ix) {
        a[ix] = a[ix - 1];
      }

      a[low] = data;
    }
  }
}



