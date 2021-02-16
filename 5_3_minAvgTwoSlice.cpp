#include <iostream>
#include <vector>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

int solution(vector<int> &A) {
    int startingPosition(0);

    double minimalAverage((A.at(0) + A.at(1)) / 2.0);
    for (int i = 0; i < A.size() - 2; ++i) { 
        double averageOnSliceOfTwo = (A.at(i) + A.at(i + 1)) / 2.0;
        if (averageOnSliceOfTwo < minimalAverage) {
            minimalAverage = averageOnSliceOfTwo;
            startingPosition = i;
        }
        double averageOnSliceOfThree = (A.at(i) + A.at(i + 1) + A.at(i + 2)) / 3.0;
        if (averageOnSliceOfThree < minimalAverage) {
            minimalAverage = averageOnSliceOfThree;
            startingPosition = i;
        }
    }
    double averageOnLastSliceOfTwo = (A.at(A.size() - 2) + A.at(A.size() - 1)) / 2.0;
    if (averageOnLastSliceOfTwo < minimalAverage) {
        startingPosition = A.size() - 2;
    }

    return startingPosition;
}

int main() {
    int myInts[]{4,2,2,5,1,5,8};
    int myInts1[]{2, 2};
    int myInts2[]{2, 5};
    int myInts3[]{2, 2, 5, 1};
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
/** Lesson 5
3. MinAvgTwoSlice : Find the minimal average of any slice containing at least two elements.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N)
Task description : https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
 */