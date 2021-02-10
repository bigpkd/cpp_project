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

int solution(vector<int> &A) {  // Task score : 100%  O(N) or O(N * log(N))
    int res = 1;
    set<int> aSet(A.begin(), A.end());
    int prev = 0;
    for (auto it = aSet.lower_bound(1); it != aSet.end() ; it++) {
        int curr = *it;
        res = curr + 1;
        if (curr - prev > 1) {
            res = prev + 1;
            break;
        }
        prev = curr;
    }
    return res;
}

int solution_2(vector<int> &A) { // Task score : 100%  O(N) or O(N * log(N))
    int res = 1;
    set<int> aSet(A.begin(), A.end());
    set<int> anotherSet(aSet.lower_bound(1), aSet.end()); // This seems to not be an issue in matter of performance
    int prev = 0;
    for (int curr : anotherSet) {
        res = curr + 1;
        if (curr - prev > 1) {
            res = prev + 1;
            break;
        }
        prev = curr;
    }
    return res;
}

int main() {
    vector<int> empty;
    int myInts[] = {1, 2, 3};
    int myInts1[] = {-1, -3};
    int myInts2[] = {-1, -3, 2, 6};
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
3. MissingInteger : Find the smallest positive integer that does not occur in a given sequence.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N) or O(N * log(N))
Task description : https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/
 */
