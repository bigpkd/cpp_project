#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

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

int solution(int N) {
    int factors(0);
    long i;
    for (i = 1; i * i < N; i++)
        if (N % i == 0) factors += 2;
    if (i * i == N) factors++;
    return factors;
}

int main() {
    display(solution(36));   // 9
    display(solution(25));   // 3
    display(solution(24));   // 8
    display(solution(81));   // 5
    display(solution(INT_MAX));   // 2

    return 0;
}

/** Lesson 10
1. CountFactors : Count factors of given number n.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(√N)
Task description : https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/
*/

/** Lesson 10
2. Flags : Find the maximum number of flags that can be set on mountain peaks.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/
*/

/** Lesson 10
3. MinPerimeterRectangle : Find the minimal perimeter of any rectangle whose area equals N.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/
*/

/** Lesson 10
4. Peaks : Divide an array into the maximum number of same-sized blocks, each of which should contain an index P such that A[P - 1] < A[P] > A[P + 1].
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/peaks/
*/
