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
    int res(0);
    if (A.size() >= 3) {
        for (int i = 0; i < A.size() - 2; ++i) {
            for (int j = i + 1; j < A.size() - 1; ++j) {
                for (int k = j + 1; k < A.size(); ++k) {
                    bool t1 = (long) A.at(i) + (long) A.at(j) > (long) A.at(k);
                    bool t2 = (long) A.at(j) + (long) A.at(k) > (long) A.at(i);
                    bool t3 = (long) A.at(k) + (long) A.at(i) > (long) A.at(j);
                    if (t1 && t2 && t3) {
                        res = 1;
                        break;
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    int myInts[]{10, 2, 5, 1, 8, 20};   //
    int myInts1[]{10, 50, 5, 1};    //
//    int myInts2[]{1, 1, 3, 5, 0};    //
//    int myInts3[]{3, 1, 2, 2, 5, 6};    //
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
//    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));
//    vector<int> v3(myInts3, myInts3 + sizeof(myInts3) / sizeof(int));

    display(solution(v));
    display(solution(v1));
//    display(solution(v2));
//    display(solution(v3));

    return 0;
}
/** Lesson 6
3. NumberOfDiscIntersections : Compute the number of intersections in a sequence of discs.
Task Score : 62%
Correctness : 100%
Performance : 0%  O()
Task description : https://app.codility.com/programmers/lessons/6-sorting/triangle/
 */