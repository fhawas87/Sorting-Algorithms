#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

#include "SwapAlgorithm.h"

int Partition(std::vector<int32_t> &CopyOfInputNumbers, int Low, int High) {

    int32_t Pivot = CopyOfInputNumbers.at(High);
    int SmallerElement = Low - 1;

    for (int j = Low; j <= High - 1; j++) {

        if (CopyOfInputNumbers.at(j) <= Pivot) {

            ++SmallerElement;

            std::swap(CopyOfInputNumbers.at(SmallerElement), CopyOfInputNumbers.at(j));
        }
    }

    std::swap(CopyOfInputNumbers.at(SmallerElement + 1), CopyOfInputNumbers.at(High));

    return (SmallerElement + 1);
}

void QuickSortHelperFunction(std::vector<int32_t> &CopyOfInputNumbers, int Low, int High) {

    if (Low < High) {

        int PivotIndex = Partition(CopyOfInputNumbers, Low, High);

        QuickSortHelperFunction(CopyOfInputNumbers, Low, PivotIndex - 1);
        QuickSortHelperFunction(CopyOfInputNumbers, PivotIndex + 1, High);
    }
}

void QuickSort(std::vector<int32_t> &CopyOfInputNumbers) {

    if (!CopyOfInputNumbers.empty()) {

        QuickSortHelperFunction(CopyOfInputNumbers, 0, CopyOfInputNumbers.size() - 1);
    }

    std::cout << "QuickSort : ";

    for (const auto &Elements : CopyOfInputNumbers) {

        std::cout << Elements << " ";
    }

    std::cout << "\n" << "\n";
}
