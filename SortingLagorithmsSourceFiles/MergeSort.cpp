#include <iostream>
#include <vector>
#include <cstdint>

void Merge(std::vector<int32_t> &CopyOfInputNumbers, int Left, int Mid, int Right) {

    int FirstSize = Mid - Left + 1;
    int SecondSize = Right - Mid;

    std::vector<int32_t> LeftPart(FirstSize);
    std::vector<int32_t> RightPart(SecondSize);

    for (int i = 0; i < FirstSize; i++) {

        LeftPart.at(i) = CopyOfInputNumbers.at(Left + i);
    }

    for (int i = 0;i < SecondSize; i++) {

        RightPart.at(i) = CopyOfInputNumbers.at(Mid + i + 1);
    }

    int Index1 = 0;
    int Index2 = 0;
    int Index3 = Left;

    while (Index1 < FirstSize && Index2 < SecondSize) {

        if (LeftPart.at(Index1) <= RightPart.at(Index2)) {

            CopyOfInputNumbers.at(Index3) = LeftPart.at(Index1);
            Index1++;
        }

        else {

            CopyOfInputNumbers.at(Index3) = RightPart.at(Index2);
            Index2++;
        }

        Index3++;
    }

    while (Index1 < FirstSize) {

        CopyOfInputNumbers.at(Index3) = LeftPart.at(Index1);

        Index1++;
        Index3++;
    }

    while (Index2 < SecondSize) {

        CopyOfInputNumbers.at(Index3) = RightPart.at(Index2);

        Index2++;
        Index3++;
    }
}

void MergeSortHelperFunction(std::vector<int32_t> &CopyOfInputNumbers, int Left, int Right) {

    if (Left < Right) {

        int Middle = Left + (Right - Left) / 2;

        MergeSortHelperFunction(CopyOfInputNumbers, Left, Middle);
        MergeSortHelperFunction(CopyOfInputNumbers, Middle + 1, Right);

        Merge(CopyOfInputNumbers, Left, Middle, Right);
    }
}

void MergeSort(std::vector<int32_t> &CopyOfInputNumbers) {

    if (!CopyOfInputNumbers.empty()) {

        MergeSortHelperFunction(CopyOfInputNumbers, 0, CopyOfInputNumbers.size() - 1);
    }

    std::cout << "MergeSort : ";

    for (const auto &Elements : CopyOfInputNumbers) {

        std::cout << Elements << " ";
    }

    std::cout << "\n" << "\n";
}
