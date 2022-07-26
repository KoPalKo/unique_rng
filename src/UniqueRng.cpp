#include "../lib/UniqueRng.h"

using namespace std;

int UniqueRng::operator()() {
	int number;
	do {
		number = rand() % (stop-start) + start;
	} while (find(numbers.begin(), numbers.end(), number) != numbers.end());
	numbers.push_back(number);
	return number;
}