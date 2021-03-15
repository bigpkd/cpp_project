#include <iostream>
#include <climits>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
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
