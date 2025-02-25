#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <functional>
#include <chrono>

#include "SortingAlgorithmsSourceFiles/SortingAlgorithmsSort.h"
#include "SortingAlgorithmsSourceFiles/InputConverter.h"

int main() {

    std::unordered_map<size_t, std::function<void(std::vector<int32_t>&)>> MapOfFunctions = {

        {1, BubbleSort},
        {2, HeapSort},
        {3, SelectionSort},
        {4, InsertionSort},
        {5, MergeSort},
        {6, QuickSort}

    };

    std::vector<int32_t> InputNumbers;
    std::vector<int32_t> CopyOfInputNumbers;
    std::vector<size_t> KeyToRemove;

    /*
    int SizeOfInput;

    std::cout << "Enter number of elements : ";
    std::cin >> SizeOfInput;

    InputNumbers.resize(SizeOfInput);

    std::cout << "\n" << "Enter elements : ";

    for (int i = 0; i < SizeOfInput; i++) {

        std::cin >> InputNumbers.at(i);
    }
    */

    GetInputNumbersAsString(InputNumbers);

    // This solution is more effective and transparent 

    // Also much less code

    while (!MapOfFunctions.empty()) {

        for (const auto &Elements : MapOfFunctions) {

            CopyOfInputNumbers = InputNumbers;

            auto Start = std::chrono::high_resolution_clock::now();

            Elements.second(CopyOfInputNumbers);

            auto End = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> ExecutionTime = End -Start;

            std::cout << "Execution Time : " << ExecutionTime.count() << "\n" << "\n";

            KeyToRemove.push_back(Elements.first);
            CopyOfInputNumbers.clear();
        }

        for (const auto &Key : KeyToRemove) {

            MapOfFunctions.erase(Key);
        }
    }
/*
    while (!MapOfFunctions.empty()) {

        for (const auto &Elements : MapOfFunctions) {

            switch (Elements.first) {

            case 1: {

                CopyOfInputNumbers = InputNumbers;

                auto Start = std::chrono::high_resolution_clock::now();

                BubbleSort(CopyOfInputNumbers);

                auto End = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double> ExecutionTime = End - Start;
                std::cout << "BubbleSort execution time : " << ExecutionTime.count() << "\n" << "\n" << "\n";

                KeyToRemove.push_back(Elements.first);
                CopyOfInputNumbers.clear();

                break;
            }

            case 2: {

                CopyOfInputNumbers = InputNumbers;

                auto Start = std::chrono::high_resolution_clock::now();

                HeapSort(CopyOfInputNumbers);

                auto End = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double> ExecutionTime = End - Start;
                std::cout << "HeapSort execution time : " << ExecutionTime.count() << "\n" << "\n" << "\n";

                KeyToRemove.push_back(Elements.first);
                CopyOfInputNumbers.clear();

                break;
            }

            case 3: {

                CopyOfInputNumbers = InputNumbers;

                auto Start = std::chrono::high_resolution_clock::now();

                SelectionSort(CopyOfInputNumbers);

                auto End = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double> ExecutionTime = End - Start;
                std::cout << "SelectionSort execution time : " << ExecutionTime.count() << "\n" << "\n" << "\n";

                KeyToRemove.push_back(Elements.first);
                CopyOfInputNumbers.clear();

                break;
            }

            case 4: {

                CopyOfInputNumbers = InputNumbers;

                auto Start = std::chrono::high_resolution_clock::now();

                InsertionSort(CopyOfInputNumbers);

                auto End = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double> ExecutionTime = End - Start;
                std::cout << "InsertionSort execution time : " << ExecutionTime.count() << "\n" << "\n" << "\n";

                KeyToRemove.push_back(Elements.first);
                CopyOfInputNumbers.clear();

                break;
            }

            case 5: {

                CopyOfInputNumbers = InputNumbers;

                auto Start = std::chrono::high_resolution_clock::now();

                MergeSort(CopyOfInputNumbers);

                auto End = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double> ExecutionTime = End - Start;
                std::cout << "MergeSort execution time : " << ExecutionTime.count() << "\n" << "\n" << "\n";

                KeyToRemove.push_back(Elements.first);
                CopyOfInputNumbers.clear();

                break;
            }

            case 6: {

                CopyOfInputNumbers = InputNumbers;

                auto Start = std::chrono::high_resolution_clock::now();

                QuickSort(CopyOfInputNumbers);

                auto End = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double> Executiontime = End - Start;
                std::cout << "QuickSort execution time : " << Executiontime.count() << "\n" << "\n" << "\n";

                KeyToRemove.push_back(Elements.first);
                CopyOfInputNumbers.clear();

                break;
            }

            default:

                std::cout << "Map out of elements ! Sorting Completed\n";

                break;
            }
        }

        for (const auto &key : KeyToRemove) {

            MapOfFunctions.erase(key);
        }

    }
*/
    InputNumbers.clear();
    KeyToRemove.clear();

    return 0;
}
