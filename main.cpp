#include <iostream>
#include <algorithm>
#include "lib/UniqueRng.h"

using namespace std;

void test_generator(UniqueRng ur, int count);

int main(void) {
    UniqueRng randGen(5, 13);

    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13);

    UniqueRng randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70);

    return 0;
}

void test_generator(UniqueRng ur, int count)
{
    cout << "Generating numbers:" << endl;
    try {
        int e = ur.stop - ur.start;
        if (e >= count) {
            vector<int> num(count);
            ostream_iterator<int> out_it(cout, "\n");
            generate(num.begin(), num.end(), ur);
            copy(num.begin(), num.end(), out_it);
        }
        else { 
            throw e; 
        }
    }
    catch (int e) {
        cout << "Exception: Unable to produce unique random number" << endl;
        cout << "Tried to produce " << count << " random numbers. Got only " << e << endl;
        vector<int> num(e);
        ostream_iterator<int> out_it(cout, "\n");
        generate(num.begin(), num.end(), ur);
        copy(num.begin(), num.end(), out_it);
    }
    cout << "End of generator" << endl;
}
