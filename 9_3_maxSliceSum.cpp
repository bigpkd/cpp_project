#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

int solution(vector<int> &A) {
    int maxEnding(0), maxSlice(INT_MIN);
    for (const int &value : A) {
        maxEnding = (maxEnding < 0 && value >= maxEnding) ? value : maxEnding + value;
        maxSlice = max(maxSlice, maxEnding);
    }
    return maxSlice;
}

int main() {
    int myInts[]{3, 2, -6, 4, 0};   //  5
    int myInts1[]{-10};             //  -10
    int myInts2[]{-2, 1};           //  1
    int myInts3[]{-5, -3, -1};      //  -1
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

/** Lesson 9
3. MaxSliceSum : Find a maximum sum of a compact subsequence of array elements.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N)
Task description : https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/
*/
