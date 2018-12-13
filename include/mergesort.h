//
// Created by vscilab on 11/19/2018.
//

#ifndef EX04_MERGESORT_MERGESORT_H
#define EX04_MERGESORT_MERGESORT_H

#include <cstdint>
#include <iostream>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {
                template<class Alpaca>
                void merge(Alpaca lower[], Alpaca upper[], int64_t size) {
                    std::cout << "lower = " << *lower << ", upper = " << *upper << ", size = " << size << std::endl;
                    Alpaca *hold = new Alpaca[size];
                    Alpaca *b = lower, *u = upper, *h = hold;
                    // std::cout << "b = " << *b << ", u = " << *u << ", h = " << *h << std::endl;
                    while(b < upper && u < upper + size/2 + size%2){
                        if (*b < *u) {
                            *h = *b;
                            b++;
                        } else {
                            *h = *u;
                            u++;
                        }
                        h++;
                    }
                    while (b < upper) {
                        *h = *b;
                        b++;
                        h++;
                    }
                    while (u < upper + size/2 + size%2){
                        *h = *u;
                        u++;
                        h++;
                    }


                    for (int64_t k = 0;k < size; k++) {
                        std::cout<< hold[k] << " ";
                        lower[k] = hold[k];
                    }
                    std::cout << std::endl;
                    delete [] hold;
                }


                template<class Alpaca>
    void mergesort(Alpaca array[], size_t size) {
        std::cout << "array = " << array << ", size = " << size << std::endl;
        if ( size > 2 ) {
            mergesort(array, size/2);
        //    std::cout << "array after mergesort 1 = " << array << ", size after mergesort 1 = " << size << std::endl;
            mergesort(array + size/2, size/2 + (size % 2));
        //    std::cout << "array after mergesort 2 = " << array << ", size after mergesort 2 = " << size << std::endl;
            merge(array, array + size/2, size);
        //    std::cout << "array after merge = " << array << ", size after merge = " << size << std::endl;
        } else if (size == 2) {
        //    std::cout << "If size == 2" << std::endl;
            if (array[1] < array[0]) {
        //        std::cout << "If array[1] < array[0]" << std::endl;
                std::swap(array[0],array[1]);
            }
        }
    }



}}}}

#endif //EX04_MERGESORT_MERGESORT_H
