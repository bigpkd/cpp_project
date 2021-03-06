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

int solution_9(vector<int> &A) {  /** O(N*log(N)) */
    int leader(INT_MIN);
    sort(A.begin(), A.end());
    int candidate = A.at(A.size() / 2);
    // verification (necessary in the case of leader identification)
    size_t count(0);
    for (const int &val : A)
        if (candidate == val) count++;
    if (count > A.size() / 2) leader = candidate;
    return leader;
}

int solution(vector<int> &A) {  /** O(N) */
    stack<int> s;
    s.push(INT_MAX);
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

int main() {
    int myInts[]{4, 6, 6, 6, 6, 8, 8};   //
    int myInts1[]{8, 8, 5, 7, 9, 8, 7, 4, 8};    //
    int myInts2[]{8, 7, 7, 8, 9, 4, 5, 8, 8};    //
//    int myInts3[]{3, 1, 2, 2, 5, 6};    //
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));
//    vector<int> v3(myInts3, myInts3 + sizeof(myInts3) / sizeof(int));

    display(solution(v));
    display(solution(v1));
    display(solution(v2));

    display(solution_9(v));
    display(solution_9(v1));
    display(solution_9(v2));
//    display(solution(v3));

    return 0;
}

/** Lesson 8
0. Leader : Find the value of the leader of the sequence a_0,a_1,...,a_n−1, such that 0 <= a_i <= 10^9.
            If there is no leader,the result should be -2147483648.

 Task description : https://codility.com/media/train/6-Leader.pdf
*/
