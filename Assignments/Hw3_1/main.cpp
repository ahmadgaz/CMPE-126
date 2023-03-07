#include <iostream>
#include "arrayListType.h"
using namespace std;

int main()
{

    arrayListType<int> intList(4);
    arrayListType<double> doubleList(4);

    intList.insertAt(0, 2);
    intList.insertAt(1, 4);
    intList.insertAt(2, 6);
    intList.insertAt(3, 5);

    doubleList.insertAt(0, 0.3);
    doubleList.insertAt(1, 3.5);
    doubleList.insertAt(2, 6.7);
    doubleList.insertAt(3, 2.6);

    cout << "Position of 2 in intList: " << intList.sequentialSearch(2) << endl;
    cout << "Position of 5 in intList: " << intList.sequentialSearch(5) << endl;
    cout << "Position of 3 in intList: " << intList.sequentialSearch(3) << endl;

    cout << "Position of 0.3 in doubleList: " << doubleList.sequentialSearch(0.3) << endl;
    cout << "Position of 2.6 in doubleList: " << doubleList.sequentialSearch(2.6) << endl;
    cout << "Position of 4.6 in doubleList: " << doubleList.sequentialSearch(4.6) << endl;

    return 0;
}
