#include <iostream>

#include "ball.h"

void dump(int* data, const int len) {
  for (int i = 0; i < len; ++i) {
    std::cout << data[i] << " ";
  }

  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  int unsort_nums[] = {9, 1, 7, 3, 5, 2, 4, 8};
  int len = sizeof(unsort_nums) / sizeof(int);
  std::cout << "Before sortting.." << std::endl;
  dump(unsort_nums, len);

  // 1.0@ 冒泡排序
  ball_sort(unsort_nums, len);
  dump(unsort_nums, len);

  

  return 0;
}
