#include "student_predictor.hpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// this is simple Bimodal predictor with 10 bit entry index bit and 2 bit entry
// predictor return 1(taken) when highest bit of entry set as 1
your_own::your_own() {
  int idx_bit = 10;
  num_predictor_entry = pow(2, idx_bit);
  c_bit = 2;
  pred_arr = new int[num_predictor_entry]{
      0,
  };
};
your_own::~your_own() {
  if (pred_arr != NULL) delete[] pred_arr;
}
/* warning!!! Don't change argument of these function   */
int your_own::get_pred(int pc) {
  int idx = pc % num_predictor_entry;
  int prediction = (pred_arr[idx]) / (pow(2, (c_bit - 1)));
  return prediction;
}
void your_own::update(int pc, int res) {
  int idx = pc % num_predictor_entry;
  int *arr = pred_arr;
  int bit = c_bit;
  if (res == 1) {
    if ((arr[idx] + 1) <= (pow(2, bit) - 1)) {
      if (arr[idx] == 1) arr[idx] += 1;
      arr[idx] = arr[idx] + 1;
    } else
      arr[idx] = pow(2, bit) - 1;
  } else {
    if ((arr[idx] - 1) >= 0) {
      if (arr[idx] == 2) arr[idx] -= 1;
      arr[idx] = arr[idx] - 1;
    } else
      arr[idx] = 0;
  }
}
