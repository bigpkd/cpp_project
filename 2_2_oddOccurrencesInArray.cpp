#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void display(const T &smth) {
    cout << smth << endl;
}

int solution(vector<int> &A) {
    // XOR of all elements gives us odd occurring element
    // https://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/
    int res = 0;
    for (const int &val : A) {
        res = res ^ val;
    }
    return res;
}

int main() {
//    int myints[] = {};
//    int myints[] = {2};
//    int myints[] = {2, 2, 2};
    int myints[] = {16, 29, 16, 2, 77, 77, 29};
    std::vector<int> v(myints, myints + sizeof(myints) / sizeof(int));

    display(solution(v));

    return 0;
}
/** Lesson 2
2. OddOccurrencesInArray : Find value that occurs in odd number of elements.
Task Score : 100%
Correctness : 100%
Performance : 100%
Time Complexity : O(n)

Task description : https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
 */
