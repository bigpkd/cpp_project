#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

int solution(vector<int> &A) {
    stack<int> s;
    for (const int &val : A) {
        if (s.empty() || s.top() == val)
            s.push(val);
        else
            s.pop();
    }
    int dominatorIndex(-1);
    // verification
    if (!s.empty()) {
        int dominator(s.top());
        vector<size_t> candidates;
        for (size_t i(0); i < A.size(); i++) {
            if (dominator == A.at(i))
                candidates.push_back(i);
        }
        if (candidates.size() > A.size() / 2) dominatorIndex = candidates.at(0);
    }
    return dominatorIndex;
}

int main() {
    int myInts[]{4, 6, 6, 6, 6, 8, 8};          // 1
    int myInts1[]{8, 8, 5, 7, 9, 8, 7, 4, 8};   // -1
    int myInts2[]{8, 7, 7, 8, 9, 4, 5, 8, 8};   // -1
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));

    display(solution(v));
    display(solution(v1));
    display(solution(v2));

    return 0;
}

/** Lesson 8
1. Dominator : Find an index of an array such that its value occurs at more than half of indices in the array.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N*log(N)) or O(N)
Task description : https://app.codility.com/programmers/lessons/8-leader/dominator/
*/
