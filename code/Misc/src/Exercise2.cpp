//Include io -> from terminal
#include <iostream>
#include <cmath>
#include <list>

using namespace std;

void intInterchange(int& a, int &b) {
    int x = a;
    a = b;
    b = x;
}

void interchange(double& a, double &b) {
    double x = a;
    a = b;
    b = x;
}

void intBubbleSort(int inputArray[], int N) {
    //Iterate every element in the array
    for (int i = 0; i < N; i++) {
        // Work through the sub-array of unsorted elements, comparing values
        // note, the last 'i' elements will have been sorted, so we don't iterate those
        for (int j = 0; j < N - i - 1; j++) {

            //  cout << "Comparing[" << i << "]..." << inputArray[j] << " and " << inputArray[j + 1] << endl;
            if (inputArray[j] > inputArray[j + 1]) {
                intInterchange(inputArray[j], inputArray[j + 1]);
            }
        }
    }
}

void bubbleSort(double inputArray[], int N) {
    //Iterate every element in the array
    for (int i = 0; i < N; i++) {
        // Work through the sub-array of unsorted elements, comparing values
        // note, the last 'i' elements will have been sorted, so we don't iterate those
        for (int j = 0; j < N - i - 1; j++) {

            //  cout << "Comparing[" << i << "]..." << inputArray[j] << " and " << inputArray[j + 1] << endl;
            if (inputArray[j] > inputArray[j + 1]) {
                interchange(inputArray[j], inputArray[j + 1]);
            }
        }
    }
}

int main() {

    int unsortedIntList[] = {3,1,2, 17, 44, 12, 9, 3};
    double unsortedDoubleList[] = {3,1,2, 17, 44, 12, 9, 3};

    intBubbleSort(unsortedIntList, 8);
    bubbleSort(unsortedDoubleList, 8);

    for (int val : unsortedIntList) {
        cout << val << ", ";
    }
    cout << endl;

    for (double val : unsortedDoubleList) {
        cout << val << ", ";
    }
    cout << endl;

    return 0;
}
