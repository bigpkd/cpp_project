#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <climits>

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
    int maxEnding(0), maxSlice(INT_MIN);
    for (const int &value : A) {
        maxEnding = (maxEnding < 0 && value >= maxEnding) ? value : maxEnding + value;
        maxSlice = max(maxSlice, maxEnding);
    }
    return maxSlice;
}

int main() {
    int myInts[]{3, 2, -6, 4, 0};     //  5
    int myInts1[]{-10};   //  -10
    int myInts2[]{-2, 1};         //  1
    int myInts3[]{-5, -3, -1};    //   -1
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

/** Lesson 10
0.1. Counting divisors : .

 Task description : https://codility.com/media/train/8-PrimeNumbers.pdf
*/

/** Lesson 10
0.2. Primality test : .

 Task description : https://codility.com/media/train/8-PrimeNumbers.pdf
*/

/** Lesson 10
0.3. Exercise : .

 Task description : https://codility.com/media/train/8-PrimeNumbers.pdf
*/

/** Lesson 10
1. CountFactors : Count factors of given number n.
Task Score : %
Correctness : %
Performance : 100%  O()
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
