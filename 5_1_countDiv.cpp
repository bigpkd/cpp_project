#include <iostream>
#include <climits>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

int solution(int A, int B, int K) {
    long a = A % K == 0 ? A : A - A % K + K;
    long b = B % K == 0 ? B : B - B % K;
    return (b - a) / K + 1;
}

int main() {
    display(solution(6, 11, 2));
    display(solution(6, 6, 1000));
    display(solution(11, 100, 10));
    display(solution(10, 101, 10));

    display(solution(101, 123000000, 10000));
    display(solution(0, INT_MAX, 10));

    return 0;
}
/** Lesson 5
1. CountDiv : Compute number of integers divisible by k in range [a..b].
Task Score : 100%
Correctness : 100%
Performance : 100%  O(1)
Task description : https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/
 */
