#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template<typename T>
void display(const T &smth) {
    cout << smth << endl;
}

template<typename T>
void displayVector(const std::vector<T> vector) {
    for (const auto &it : vector) {
        cout << it << " ; ";
    }
    cout << endl;
}

int solution(vector<int> &A) {
    long range = A.size() + 1;
    long sumOfRange = range * (range + 1) / 2;
    long sumOfVector = accumulate(A.begin(), A.end(), 0);
    return (int) (sumOfRange - sumOfVector);
}

int main() {
    int myInts[]{1, 2, 3, 5};
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    display(solution(v));

    return 0;
}
/** Lesson 3
2. PermMissingElem : Find the missing element in a given permutation.
Task Score : 100%
Correctness : 100%
Performance : 100%
Task description : https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/
 */
