#include <vector>

#include <iostream>

using namespace std;

vector<int> rotate(vector<int> &A, unsigned int K) {
    vector<int> rotated = vector<int>((A.begin() + A.size() - K), A.end());
    for (int i = 0; i < (A.size() - K); ++i) {
        rotated.push_back(A.at(i));
    }
    return rotated;
}

vector<int> solution(vector<int> &A, int K) {
    vector<int> res;
    if (!A.empty()) res = rotate(A, K % A.size());
    return res;
}

template <typename T>
void displayVector(const std::vector<T> vector) {
    for (const auto& it : vector) {
        cout << it << "   ";
    }
    cout << endl;
}

int main() {
    int myints[] = {16,2,77,29};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );

    displayVector(vector<int>());

    displayVector(v);

    displayVector(solution(v, 0));

    displayVector(solution(v, 1));

    displayVector(solution(v, 2));

    displayVector(solution(v, 3));

    displayVector(solution(v, 4));

    displayVector(solution(v, 5));

    return 0;
}
/** Lesson 2
1. CyclicRotation : Rotate an array to the right by a given number of steps.
Task Score : 100%
Correctness : 100%
Performance : Not assessed

Task description : https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
*/