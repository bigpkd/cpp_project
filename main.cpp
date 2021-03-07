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
    int myInts[]{4, 3, 4, 4, 4, 2};   //    2
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

/** Lesson 8
2. EquiLeader : Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/8-leader/equi_leader/
*/
