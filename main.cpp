#include <iostream>
#include <vector>
#include <map>
#include <set>

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
    return set<int>(A.begin(), A.end()).size();
}

int main() {
    int myInts[]{1, 2, 5, 3, 1, 3};    // 2
    int myInts1[]{3, 3, 3, 5, 4};    // 3
    int myInts2[]{6, 5, 5, 6, 2, 2};   // 4
    int myInts3[]{2, 1, 1, 2, 3, 1};    // 2
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
/** Lesson 6
2. MaxProductOfThree : Maximize A[P] * A[Q] * A[R] for any triplet (P, Q, R).
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N*log(N)) or O(N)
Task description : https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
 */