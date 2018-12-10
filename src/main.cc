//
// Created by vscilab on 11/19/2018.
//

#include "mergesort.h"

using namespace std;
using namespace edu::vcccd::vc::csv15;

int main(){
    int64_t numbers[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    uint64_t arraySize = (sizeof(numbers)/sizeof(int64_t));
    mergesort(numbers , arraySize);
}