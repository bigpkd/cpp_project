#include <iostream>
#include <algorithm>
#include <vector>
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

//int solution(vector<int> &A) {
//}

int countDivisors(int n) {
    int divisors(0);
    int i;
    for (i = 1; i * i < n; ++i)
        if (n % i == 0) divisors += 2;
    if (i * i == n) divisors++;
    return divisors;
}

int countDivisors_1(int n) {
    int divisors(0);
    int i(1);
    while (i * i < n) {
        if (n % i == 0) divisors += 2;
        i++;
    }
    if (i * i == n) divisors++; // square roots are accounted for twice
    return divisors;
}

bool isPrime(int n) {
    for (int i = 2; i * i < n; ++i) {   // We assume that 1 is neither a prime nor a composite number,
        if (n % i == 0) return false;
    }
    return true;
}

int countTailCoins(int n) {
    vector<bool> coins(n + 1, 0);
    int tails(0);
    for (size_t i = 1; i < coins.size(); ++i) {
        for (size_t j = i; j <= n; j += i) {    // can we say j < n + 1
            coins.at(j) = !coins.at(j);
            if (coins.at(j)) tails++;
            else tails --;
        }
    }
    return tails;
}

int coins(int n) {
    int res(0);
    vector<bool> coins(n + 1, false);
    for (size_t i = 1; i < n + 1; ++i) {
        size_t k(i);
        while (k <= n) {
            coins.at(k) = (coins.at(k) + 1) % 2;
            k += i;
        }
        res += coins.at(i);
    }
    return res;
}

int main() {
//    display(countDivisors(36));   // 9
//    display(countDivisors(25));   // 3
//    display(countDivisors(24));   // 8
//    display(countDivisors(81));   // 5
//
    display(isPrime(36));   // 0
    display(isPrime(25));   // 1
    display(isPrime(24));   // 0
    display(isPrime(81));   // 0

    display(coins(36));   // 0
    display(coins(25));   // 1
    display(coins(24));   // 0
    display(coins(81));   // 0

//    display(countTailCoins(36));   // 0
//    display(countTailCoins(25));   // 1
//    display(countTailCoins(24));   // 0
//    display(countTailCoins(81));   // 0

    int myInts[]{3, 2, -6, 4, 0};   //  5
    int myInts1[]{-10};             //  -10
    int myInts2[]{-2, 1};           //  1
    int myInts3[]{-5, -3, -1};      //  -1
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));
    vector<int> v3(myInts3, myInts3 + sizeof(myInts3) / sizeof(int));

//    display(solution(v));
//    display(solution(v1));
//    display(solution(v2));
//    display(solution(v3));

    return 0;
}

/** Lesson 10
0.1. Counting divisors : count the number of divisors of n.

 Task description : https://codility.com/media/train/8-PrimeNumbers.pdf
*/

/** Lesson 10
0.2. Primality test.

 Task description : https://codility.com/media/train/8-PrimeNumbers.pdf
*/

/** Lesson 10
0.3. Exercise : Consider n coins aligned in a row. Each coin is showing heads at the beginning.
                1   2   3   4   5   6   7   8   9   10
 Then, n people turn over corresponding coins as follows. Person i reverses coins with numbers that are multiples of i.
 That is, person iflips coins i, 2· i, 3· i, . . . until no more appropriate coins remain. The goal is to count the number
 of coins showing tails. In the above example,thefinal configuration is:
                1_^   2   3   4_^   5   6   7   8   9_^   10

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
