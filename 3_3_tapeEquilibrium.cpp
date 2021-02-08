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

int solution_2(vector<int> &A) {    // 92% 85% 100%  O(N)
    int res = INT_MAX;
    if (A.size() == 2) {
        res = abs(A.front() - A.back());
    } else if (A.size() > 2) {
        int after = accumulate(A.begin(), A.end(), 0);
        int prior = 0;
        for (int val : A) {
            prior += val;
            after -= val;
            int difference = abs(prior - after);
            res = difference < res ? difference : res;
        }
    }
    return res;
}

int solution(vector<int> &A) {  // 100% 100% 100%  O(N)
    int res = INT_MAX;
    int after = accumulate(A.begin(), A.end(), 0) - A.front();
    int prior = A.front();
    for (size_t i = 1; i < A.size(); ++i) {
        int difference = abs(prior - after);
        res = difference < res ? difference : res;
        prior += A.at(i);
        after -= A.at(i);
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
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N)
Task description : https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
 */
