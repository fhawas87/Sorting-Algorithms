#include <cstdint>

void XORSwapAlgorithm(int32_t &FirstElement, int32_t &SecondElement) {

	if (&FirstElement != &SecondElement) {

		FirstElement ^= SecondElement;
		SecondElement ^= FirstElement;
		FirstElement ^= SecondElement;
	}
}
