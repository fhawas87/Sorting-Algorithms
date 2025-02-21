#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

#include "SwapAlgorithm.h"

void HeapifyAlgorithm(std::vector<int32_t> &CopyOfInputNumbers, int HeapSize, int i) {

    int32_t Largest = i;
    int32_t Left = 2 * i + 1;
    int32_t Right = 2 * i + 2;

    if (Left < HeapSize && CopyOfInputNumbers.at(Left) > CopyOfInputNumbers.at(Largest)) {

        Largest = Left;
    }

    if (Right < HeapSize && CopyOfInputNumbers.at(Right) > CopyOfInputNumbers.at(Largest)) {

        Largest = Right;
    }

    if (Largest != i) {

        std::swap(CopyOfInputNumbers.at(i), CopyOfInputNumbers.at(Largest));

        HeapifyAlgorithm(CopyOfInputNumbers, HeapSize, Largest);
    }
}

void HeapSort (std::vector<int32_t> &CopyOfInputNumbers) {

    int HeapSize = CopyOfInputNumbers.size();

    for (int i = (HeapSize / 2) - 1; i >= 0; --i) {

        HeapifyAlgorithm(CopyOfInputNumbers, HeapSize, i);
    }

    for (int i = HeapSize - 1; i >= 0; --i) {

        std::swap(CopyOfInputNumbers.at(0), CopyOfInputNumbers.at(i));

        HeapifyAlgorithm(CopyOfInputNumbers, i, 0);
    }

    std::cout << "HeapSort : ";

    for (const auto &Elements : CopyOfInputNumbers) {

        std::cout << Elements << " ";
    }

    std::cout << "\n" << "\n";
}
