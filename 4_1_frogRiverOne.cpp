#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

template<typename T>
void display(const T &smth) {
    cout << smth << endl;
}

int solution(int X, vector<int> &A) {
    vector<int>sequence(X);
    iota(sequence.begin(), sequence.end(), 1);
    set<int> requiredPath(sequence.begin(), sequence.end());

    int res = -1;
    int index = -1;
    set<int> coveredPath;
    for (int position : A) {
        ++index;
        coveredPath.emplace(position);
        if (coveredPath == requiredPath) {
            res = index;
            break;
        }
    }
    return res;
}

int main() {
    int X = 5;
    double myInts[]{1, 3, 1, 4, 2, 3, 5, 4};
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    display(solution(X, v));

    return 0;
}
/** Lesson 4
1. FrogRiverOne : Find the earliest time when a frog can jump to the other side of a river.
Task Score : 100%
Correctness : 100%
Performance : 100% O(N)
Task description : https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/
 */
