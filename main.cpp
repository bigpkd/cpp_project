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

int solution(vector<int> &A) {
    stack<int> s;
    s.push(-1);
    for (const int &val : A) {
        if (!s.empty() && s.top() != val)
            s.pop();
        else
            s.push(val);
    }
    // verification (necessary in the case of leader identification)
    if (s.empty()) cout << "empty\n";
    cout << s.top() << endl;
    int candidate (s.top());
    size_t count(0);
    for (const int &val : A) {
        if (candidate == val) count++;
    }
    if (count <= A.size() / 2) return -1;
    cout << count << " - " << endl;
    return s.top();
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

//    display(solution(v));
    display(solution(v1));

//    display(solution(v4));
//    display(solution(v3));

    return 0;
}

/** Lesson 8
1. Dominator : Find an index of an array such that its value occurs at more than half of indices in the array.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/8-leader/dominator/
*/

/** Lesson 8
2. EquiLeader : Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/8-leader/equi_leader/
*/
