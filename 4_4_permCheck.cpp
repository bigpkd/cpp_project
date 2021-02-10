#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

int solution(vector<int> &A) {
    int res = 0;
    set<int> aSet(A.begin(), A.end());
    unsigned int expectedSum = A.size() * (A.size() + 1) / 2;
    unsigned int actualSum = accumulate(aSet.begin(), aSet.end(), 0);
    if (expectedSum != 0 && expectedSum == actualSum) res = 1;
    return res;
}

int main() {
    vector<int> empty;
    int myInts[] = {4, 1, 2, 3};
    int myInts1[] = {4, 1, 3};
    int myInts2[] = {/*-1, -3, */2, 6};
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));
    display(solution(empty));
    display(solution(v));
    display(solution(v1));
    display(solution(v2));

    return 0;
}
/** Lesson 4
4. PermCheck : Check whether array A is a permutation.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N) or O(N * log(N))
Task description : https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/
 */
