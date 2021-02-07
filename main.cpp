#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

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

int solution(int X, vector<int> &A) {
    auto it = find(A.begin(), A.end(), X);
    if (it == A.end()) {
        return -1;
    } else {
        return vector<int>(A.begin(), it).size();
    }
}

int main() {
    int x = 5;
    double myInts[]{1, 3, 1, 4, 2, 3, 5, 4};
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    display(solution(x, v));

    return 0;
}
/** Lesson 4
1. TapeEquilibrium : Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.
Task Score : 84%
Correctness : 71%
Performance : 100%
Task description : https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
 */
