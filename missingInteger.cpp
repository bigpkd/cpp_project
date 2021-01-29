/** Missing Integer - 100% solved : O(N) or O(N * log(N))
 *
 * Write a function: int solution(vector<int> &A);
 *
 * that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
 *
 * For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
 *
 * Given A = [1, 2, 3], the function should return 4.
 *
 * Given A = [−1, −3], the function should return 1.
 *
 * Write an efficient algorithm for the following assumptions:
        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].
 */

// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <vector>
#include <set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int solution(vector<int> &A) {
    set<int> aSet(A.begin(), A.end());
    aSet = set<int>(aSet.lower_bound(1), aSet.end());
    if (aSet.empty()) return 1;
    int res(0);
    for (int val : aSet) {
        if (val > ++res) return res;
    }
    return res + 1;
}

int main() {
//    int arr[] = {-1999888, -15, 0, 1, 20, 55};
//    int arr[] = {1, 3, 6, 4, 1, 2};
//    int arr[] = {1, 2, 3};
//    int arr[] = {0, 1, 2, 3};
    int arr[] = {-1, -3};
    vector<int> input (arr, arr + sizeof(arr) / sizeof(int));
    cout << solution(input) << endl;
    return 0;
}
