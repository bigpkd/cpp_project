#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

/** Description does not make it clear but the order between P, Q and R is only meant to indicate that those
 *  indexes are different from each other. So the fact that A is sorted before we process it is not an issue
 *  https://stackoverflow.com/questions/44912099/triangle-determine-if-an-array-includes-a-triangular-triplet-codility
 */
int solution(vector<int> &A) {
    int res(0);
    if (A.size() >= 3) {
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size() - 2; ++i) {
            // To avoid overflow strike, the "A.at(i) > A.at(i + 2) - A.at(i + 1)"
            // comparison is better than casting, it requires less memory
            if (A.at(i) > A.at(i + 2) - A.at(i + 1)) {
                res = 1;
                break;
            }
        }
    }
    return res;
}

int main() {
    int myInts[]{10, 2, 5, 1, 8, 20};   //  1
    int myInts1[]{10, 50, 5, 1};    //  0
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));

    display(solution(v));
    display(solution(v1));

    return 0;
}
/** Lesson 6
4. Triangle : Determine whether a triangle can be built from a given set of edges.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N*log(N))
Task description : https://app.codility.com/programmers/lessons/6-sorting/triangle/
 */