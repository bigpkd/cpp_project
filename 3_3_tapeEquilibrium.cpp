#include <iostream>
#include <vector>
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

int solution(vector<int> &A) {
    int res = INT_MAX;
    int after = accumulate(A.begin(), A.end(), 0);
    int prior = 0;
    for (int val : A) {
        prior += val;
        after -= val;
        int difference = abs(prior - after);
        res = difference < res ? difference : res;
    }
    return res;
}

int main() {
    double myInts[]{3, 1, 2, 4, 3};
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    display(solution(v));

    return 0;
}
/** Lesson 3
3. TapeEquilibrium : Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.
Task Score : 84%
Correctness : 71%
Performance : 100%
Task description : https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
 */
