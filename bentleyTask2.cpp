/**
 */

// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <vector>
#include <set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

bool isEven(int val) {
    return val%2==0;
}

int solution(vector<int> &A) {
    set<int> aSet(A.begin(), A.end());
    int maxEven = 0, maxOdd = 0;
    bool isEvenFound = false, isOddFound = false;
    set<int>::reverse_iterator it;
    for (it = aSet.rbegin(); it != aSet.rend(); ++it) {
        if (isEven(*it) && !isEvenFound) {
            maxEven = *it;
            isEvenFound = true;
        } else if (!isEven(*it) && !isOddFound){
            maxOdd = *it;
            isOddFound = true;
        }
        if (isOddFound && isEvenFound) break;
    }
    return maxOdd + maxEven;
}

int main() {
    int arr[] = {-1999888, -15, 0, 1, 20, 55};
//    int arr[] = {5,3,10,6,11};  // 11 10 21
//    int arr[] = {20,10,7,5};    // 7 20 27
//    int arr[] = {7,13,15,13};   // 15 0 15
//    int arr[] = {2,6,4,6};      // 0 6 6
    vector<int> input (arr, arr + sizeof(arr) / sizeof(int));
    cout << solution(input) << endl;

/*    int d = 1000000000 + 1000000000;
    cout << INT_MAX << endl;
    cout << LONG_LONG_MAX << endl;
    cout << d << endl;*/
    return 0;
}
