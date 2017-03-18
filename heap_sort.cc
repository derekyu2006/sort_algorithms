/**
 * 冒泡排序
 */
#include <iostream>

void build_heap(int* a, const int n);
void adjust_heap(int* a, const int n, int parent);

/**
 * 排序步骤:
 * 1. 先把所有元素调整成大根堆
 * 2. 交换堆顶元素和最后一个元素, 这样最后一个元素就是最大的元素
 * 3. 再次调整堆(此时不包含已经调整好了的数组后面的元素).
 *
 * 4. 待数组中所有元素都排序好(不是调整好堆), 按顺序输出即可.
 */
void heap_sort(int* a, const int n) {
  build_heap(a, n);
  int length = static_cast<int>(n);
  while (length > 1) {
    int temp = a[length - 1];
    a[length - 1] = a[0];
    a[0] = temp;
    --length;
    adjust_heap(a, length, 0);
  }
}

void build_heap(int* a, const int n) {
  int length = static_cast<int>(n);
  int begin = length / 2 - 1; // 得到最后一个元素的父结点
  for (int i = begin; i >= 0; --i) { // 调整的时候按照从叶子到根结点的方法进行.
    adjust_heap(a, length, i);
  }
}

void adjust_heap(int* a, const int n, int parent) {
  int left = 2 * parent;
  int right = 2 * parent + 1;
  int largest = parent;
  while (left < n || right < n) {
    if (left < n && a[largest] < a[left]) {
      largest = left;
    }

    if (right < n && a[largest] < a[right]) {
      largest = right;
    }

    if (largest != parent) {
      int temp = a[parent];
      a[parent] = a[largest];
      a[largest] = temp;
      parent = largest; // 每次调整都要从跟当前结点到最后一个结点.
      left = 2 * parent;
      right = 2 * parent + 1;
    } else {
      break; // 如果当前结点已经满足堆的特性, 就没必要再往下进行了.
    }
  }
}

