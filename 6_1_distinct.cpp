#include <iostream>
#include <vector>
#include <set>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

int solution(vector<int> &A) {
    return set<int>(A.begin(), A.end()).size();
}

int main() {
    int myInts3[]{2, 1, 1, 2, 3, 1};    // 3
    vector<int> v3(myInts3, myInts3 + sizeof(myInts3) / sizeof(int));

    display(solution(v3));

    return 0;
}
/** Lesson 6
1. Distinct : Compute number of distinct values in an array.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N*log(N)) or O(N) 
Task description : https://app.codility.com/programmers/lessons/6-sorting/distinct/
 */