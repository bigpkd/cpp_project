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

int solution_9(vector<int> &A) {
    size_t maxSide = A.front();
    while (A.at(maxSide - 1) < maxSide) maxSide--;
    for (size_t i = 0; i < A.size(); ++i) {
        size_t side(A.at(i));
        if (side < maxSide || A.size() - i < side) continue;
        size_t course(i + 1);
        bool assign(true);
        while (course < i + side) {
            if (A.at(course) < side) {
                assign = false;
                break;
            }
            course++;
        }
        if (course > maxSide && assign) maxSide = side;
    }
    return maxSide;
}

int solution(vector<int> &A) {
    size_t maxSide = A.front();
    while (A.at(maxSide - 1) < maxSide) maxSide--;
    for (size_t i = 0; i < A.size(); ++i) {
        size_t side(A.at(i));
        if (side < maxSide || A.size() - i < side) continue;
        size_t course(i + 1);
        bool assign(true);
        while (course < i + side) {
            if (A.at(course) < side) {
                assign = false;
                break;
            }
            course++;
        }
        if (course > maxSide && assign) maxSide = side;
    }
    return maxSide;
}

int main() {
    int myInts[]{1, 2, 5, 3, 1, 3};    // 2
    int myInts1[]{3, 3, 3, 5, 4};    // 3
    int myInts2[]{6, 5, 5, 6, 2, 2};   // 4
    int myInts3[]{6, 1, 5, 6, 2, 2};    // 2
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
/** The Matrix Challenge 2021
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/challenges/matrix2021/
 */