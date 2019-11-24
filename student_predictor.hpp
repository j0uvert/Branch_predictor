#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

class your_own {
 private:
  int num_predictor_entry;
  int c_bit;
  int *pred_arr;
  // added
  int reg_size;
  int table_size;
  int mask;
  int* BHR;	// branch history register
  // Pattern Histroy tables
  int* gPHT;
  int* cPHT;

 public:
  your_own();
  your_own(int, int);
  ~your_own();
  int get_pred(int);
  int getGlobalPred(int);
  int getMetaPred(int);
  void update(int, int);
};
