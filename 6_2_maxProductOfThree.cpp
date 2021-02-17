#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    set<int> potentialMaxProductsOfThree;
    size_t positionsOfExtremes[]{0, 1, 2, A.size() - 3, A.size() - 2, A.size() - 1};
    set<size_t> positions(positionsOfExtremes, positionsOfExtremes + sizeof(positionsOfExtremes) / sizeof(size_t));
    for (size_t i : positions) {
        for (size_t j : positions) {
            if (i == j) continue;
            for (size_t k : positions) {
                if (i == k || j == k) continue;
                potentialMaxProductsOfThree.emplace(A.at(i) * A.at(j) * A.at(k));
            }
        }
    }
    return *potentialMaxProductsOfThree.rbegin();
}

int main() {
    int myInts[]{-3, 1, 2, -2, 5, 6};   // 60
    int myInts1[]{-5, 5, -5, 4};    // 125
    int myInts2[]{-1, -1, -3, -5, 0};    // 0
    int myInts3[]{-3, -1, -2, -2, -5, -6};    // -4
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
Performance : 100%  O(N*log(N))
Task description : https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
 */