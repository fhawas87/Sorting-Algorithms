#include <iostream>
#include <vector>
#include <cstdint>

void InsertionSort(std::vector<int32_t> &CopyOfInputNumbers) {

    for (int i = 0; i < CopyOfInputNumbers.size(); i++) {

        int TempKey = CopyOfInputNumbers.at(i);
        int PreviousElement = i - 1;

        while (PreviousElement >= 0 && TempKey < CopyOfInputNumbers.at(PreviousElement)) {

            CopyOfInputNumbers.at(PreviousElement + 1) = CopyOfInputNumbers.at(PreviousElement);
            --PreviousElement;
        }

        CopyOfInputNumbers.at(PreviousElement + 1) = TempKey;
    }

    std::cout << "InsertionSort : ";

    for (const auto &Elements : CopyOfInputNumbers) {

        std::cout << Elements << " ";
    }

    std::cout << "\n" << "\n";
}
