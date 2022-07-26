#pragma once
#include <iostream>
#include <vector>

using namespace std;

class UniqueRng {
public:
	int start;
	int stop;
	UniqueRng(int a, int b) : numbers() { srand(time(NULL)); start = a; stop = b; }
	int operator()();
private:
	vector<int> numbers;

};