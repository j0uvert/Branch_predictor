#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// this is simple Bimodal predictor with 10 bit entry index bit and 2 bit entry
// predictor return 1(taken) when highest bit of entry set as 1
class your_own {
 private:
  int num_predictor_entry;
  int c_bit;
  int *pred_arr;

 public:
  your_own();
  your_own(int, int);
  ~your_own();
  int get_pred(int);
  void update(int, int);
};
