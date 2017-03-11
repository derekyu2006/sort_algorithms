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

