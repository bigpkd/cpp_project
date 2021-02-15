#include <iostream>
#include <vector>
#include <map>

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
    int minAvgPos(0);

    double minAvgValue((A.at(0) + A.at(1)) / 2.0);
    for (int i = 0; i < A.size() - 2; ++i) {
        if ((A.at(i) + A.at(i + 1)) / 2.0 < minAvgValue) {
            minAvgValue = (A.at(i) + A.at(i + 1)) / 2.0;
            minAvgPos = i;
        }
        if ((A.at(i) + A.at(i + 1) + A.at(i + 2)) / 3.0 < minAvgValue) {
            minAvgValue = (A.at(i) + A.at(i + 1) + A.at(i + 2)) / 3.0;
            minAvgPos = i;
        }
    }
    if (A.size() > 2 && (A.at(A.size() - 3) + A.at(A.size() - 2)) / 2.0 < minAvgValue) {
        minAvgValue = (A.at(A.size() - 3) + A.at(A.size() - 2)) / 2.0;
        minAvgPos = A.size() - 3;
    }

    return minAvgPos;
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
Task Score : %
Correctness : %
Performance : 100%  O(N + M)
Task description : https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
 */