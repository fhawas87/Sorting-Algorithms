#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

#include "SwapAlgorithm.h"

void SelectionSort (std::vector<int32_t> &CopyOfInputNumbers) {

    for (int i = 0; i < CopyOfInputNumbers.size() - 1; i++) {

        int MinIndex = i;

        for (int j = i + 1; j < CopyOfInputNumbers.size(); j++) {

            if (CopyOfInputNumbers.at(j) < CopyOfInputNumbers.at(MinIndex)) {

                MinIndex = j;
            }
        }

        //CopyOfInputNumbers.at(MinIndex) ^= CopyOfInputNumbers.at(i);
        //CopyOfInputNumbers.at(i) ^= CopyOfInputNumbers.at(MinIndex);
        //CopyOfInputNumbers.at(MinIndex) ^= CopyOfInputNumbers.at(i);

        XORSwapAlgorithm(CopyOfInputNumbers.at(MinIndex), CopyOfInputNumbers.at(i));
    }

    std::cout << "SelectionSort : ";

    for (const auto &Elements : CopyOfInputNumbers) {

        std::cout << Elements << " ";
    }

    std::cout << "\n" << "\n";
}
