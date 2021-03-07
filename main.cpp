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

int findLeader(vector<int> &A) {
    stack<int> s;
    for (const int &val : A) {
        if (!s.empty() && s.top() != val)
            s.pop();
        else
            s.push(val);
    }
    // verification (necessary in the case of leader identification)
    int leader(INT_MIN);
    if (!s.empty()) {
        int candidate = s.top();
        size_t count(0);
        for (const int &val : A)
            if (candidate == val) count++;
        if (count > A.size() / 2) leader = candidate;
    }
    return leader;
}

int solution(vector<int> &A) {
    int leader = findLeader(A);     // There can only be one leader in a sequence
    if (leader == INT_MIN) return 0;   // No leader
    vector<size_t> indexesWithLeaderOnTheLeft;
    vector<size_t> leaderInstancesCounts;
    size_t count(0);
    for (size_t i = 0; i < A.size(); ++i) {
        if (A.at(i) == leader) count++;
        if (count > (i + 1) / 2) indexesWithLeaderOnTheLeft.push_back(i);
        leaderInstancesCounts.push_back(count);
    }
    size_t equiLeadersCount(0);
    for (size_t i = 0; i < indexesWithLeaderOnTheLeft.size(); ++i) {
        size_t &equiLeaderCandidate = indexesWithLeaderOnTheLeft.at(i);
        size_t rightRangeSize = A.size() - (equiLeaderCandidate + 1);
        size_t leaderCountOnTheRight =
                leaderInstancesCounts.at(A.size() - 1)
                - leaderInstancesCounts.at(equiLeaderCandidate);
        // if right range has a leader then equiLeaderCandidate is equiLeader
        if (leaderCountOnTheRight > rightRangeSize / 2) equiLeadersCount++;
    }
    return equiLeadersCount;
}

int main() {
    int myInts[]{5, -7, 3, 5, -2, 4, 1};   //    2
    int myInts1[]{8, 8, 5, 7, 9, 8, 7, 4, 8};    //
    int myInts2[]{4, 6, 6, 6, 6, 8, 8};    //
//    int myInts3[]{3, 1, 2, 2, 5, 6};    //
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));
//    vector<int> v3(myInts3, myInts3 + sizeof(myInts3) / sizeof(int));

    display(solution(v));
    display(solution(v1));
    display(solution(v2));
//    display(solution(v3));

    return 0;
}

/** Lesson 9
0. Maximum slice problem : given a sequence of n integers a0, a1, . . . , an−1, find the slice with the
 largest sum. More precisely, we are looking for two indices p, q such that the total ap+ ap+1+ . . . + aq is maximal.
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
