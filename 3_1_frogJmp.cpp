#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
void display(const T &smth) {
    cout << smth << endl;
}

int solution(int X, int Y, int D) {
    return (int) ceil(abs(Y - X) / (double) D);
}

int main() {

    display(solution(10, 85, 30));

    return 0;
}
/** Lesson 3
1. FrogJmp : Count minimal number of jumps from position X to Y.
Task Score : 100%
Correctness : 100%
Performance : 100%
Time Complexity : O(1)

Task description : https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/
 */
