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

int findLeader(size_t start, size_t end, vector<int>& A) {
    stack<int> s;
    for (size_t i = start; i < end + 1; ++i) {
        if (s.empty() || s.top() == A.at(i)) s.push(A.at(i));
        else s.pop();
    }
    int leader(INT_MIN);
    if (!s.empty()){
        size_t count(0);
        for (size_t i = start; i < end + 1; ++i)
            if (s.top() == A.at(i)) count++;
        if (count > (end - start + 1) / 2) leader = s.top();
    }
    return leader;
}

int solution(vector<int> &A) {
    vector<size_t> equiLeaders;
    for (size_t i = 0; i < A.size() - 1; ++i) {
        int leftLeader = findLeader(0, i, A);
        int rightLeader = findLeader(i + 1, A.size() - 1, A);
        if (leftLeader != INT_MIN && rightLeader != INT_MIN) {
            if (leftLeader == rightLeader)
                equiLeaders.push_back(i);
        }
    }
    return equiLeaders.size();
}

int main() {
    int myInts[]{4, 3, 4, 4, 4, 2};   //
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

    cout << endl;

    display(findLeader(0, 0, v));
    display(findLeader(1, 5, v));
    display(findLeader(0, 2, v));
    display(findLeader(3, 5, v));

    return 0;
}

/** Lesson 8
2. EquiLeader : Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/8-leader/equi_leader/
*/
