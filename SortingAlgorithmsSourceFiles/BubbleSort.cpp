#include <cstdint>
#include <iostream>
#include <vector>

#include <SwapAlgorithm.h>

void BubbleSort(std::vector<int32_t> &CopyOfInputNumbers) {

    for (int i = 0; i < CopyOfInputNumbers.size(); i++) {
        bool HasChanged = false;
        for (int j = 0; j < CopyOfInputNumbers.size() - i - 1; j++) {

            if (CopyOfInputNumbers.at(j) > CopyOfInputNumbers.at(j + 1)) {

                //CopyOfInputNumbers.at(j) ^= CopyOfInputNumbers.at(j + 1);
                //CopyOfInputNumbers.at(j + 1) ^= CopyOfInputNumbers.at(j);
                //CopyOfInputNumbers.at(j) ^= CopyOfInputNumbers.at(j + 1);

                XORSwapAlgorithm(CopyOfInputNumbers.at(j), CopyOfInputNumbers.at(j + 1));
                HasChanged = true;
            }
        }
        if (!HasChanged) { break;}
    }
    std::cout << "\n" << "\n" << "BubbleSort : ";

    for (const auto &Elements : CopyOfInputNumbers) {

        std::cout << Elements << " ";
    }

    std::cout << "\n" << "\n";
}
