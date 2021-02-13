#include <iostream>
#include <vector>
#include <map>
#include <string>

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
    int res = -1;

    return res;
}

int main() {
    int myInts[]{4,2,2,5,1,5,8};
    int myInts1[]{4, 5, 6};
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));

    display(solution(v));

    return 0;
}
/** Lesson 5
2. MinAvgTwoSlice : Find the minimal average of any slice containing at least two elements.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N + M)
Task description : https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/
 */