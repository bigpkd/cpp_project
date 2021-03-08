#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <climits>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

template<typename T>
void displayVector(const std::vector<T> vector) {
    for (const auto &val : vector) {
        cout << val << " ; ";
    }
    cout << endl;
}

template<typename T, typename U>
void displayMap(std::map<T, U> map) {
    for (const auto entry : map) {
        cout << "(" << entry.first << " : " << entry.second << ") ";
    }
    cout << endl;
}

int solution_9(vector<int> &A) {
    if (A.size() < 3) return 0;
    vector<int> prefixSums(A.begin(), A.end());
    for (size_t p = 1; p < A.size(); ++p) {
        prefixSums.at(p) = prefixSums.at(p - 1) + prefixSums.at(p);
    }
    int res(0);
    for (size_t p = 0; p < A.size() - 2; ++p) {
        for (size_t q = p + 2; q < A.size(); ++q) {
            for (size_t i = p + 1; i < q; ++i) {
                int leftSum = prefixSums.at(i - 1) - prefixSums.at(p);
                int rightSum = prefixSums.at(q - 1) - prefixSums.at(i);
                res = max(res, leftSum + rightSum);
            }
        }
    }
    return res;
}

int solution(vector<int> &A) {
    if (A.size() < 3) return 0;
    vector<int> prefixSums(A.begin(), A.end());
    for (size_t p = 1; p < A.size(); ++p) {
        prefixSums.at(p) = prefixSums.at(p - 1) + prefixSums.at(p);
    }
    int res(0);
    for (size_t p = 0; p < A.size() - 2; ++p) {
        for (size_t q = p + 2; q < A.size(); ++q) {
            for (size_t i = p + 1; i < q; ++i) {
                int leftSum = prefixSums.at(i - 1) - prefixSums.at(p);
                int rightSum = prefixSums.at(q - 1) - prefixSums.at(i);
                res = max(res, leftSum + rightSum);
            }
        }
    }
    return res;
}

int main() {
    int myInts[]{3, 2, 6, -1, 4, 5, -1, 2};       //  17
    int myInts1[]{8, 8, 5, 7, 9, 8, 7, 4, 8};   //  44
    int myInts2[]{4, 6, 6, 6, 6, 8, 8};         //  26
    int myInts3[]{3, 4, 5};    //   0
//    int myInts3[]{0, 10, -5, -2, 0};    //    10
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));
    vector<int> v3(myInts3, myInts3 + sizeof(myInts3) / sizeof(int));

    display(solution(v));
    display(solution(v1));
    display(solution(v2));
    display(solution(v3));

    return 0;
}

/** Lesson 9
0. MaximumSlice : given a sequence of n integers a_0, a_1, . . . , a_n−1, find the slice with the
 largest sum. More precisely, we are looking for two indices p, q such that the total a_p+ a_p+1+ . . . + a_q is maximal.
 We assume that the slice can be empty and its sum equals 0.

 Task description : https://codility.com/media/train/7-MaxSlice.pdf
*/

/** Lesson 9
1. MaxDoubleSliceSum : Find the maximal sum of any double slice.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_double_slice_sum/
*/

/** Lesson 9
2. MaxProfit : Given a log of stock prices compute the maximum possible earning.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/
*/

/** Lesson 9
3. MaxSliceSum : Find a maximum sum of a compact subsequence of array elements.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/
*/
