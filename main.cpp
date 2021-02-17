#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

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
    const int INTERSECTING_PAIRS_LIMIT = 10000000;

    return 1;
}

double inter(int center1, int radius1, int center2, int radius2) {
    double num = radius2*radius2 - radius1*radius1 - center2*center2 + center1*center1;
    double denom = 2 * ( center1*center1 - center2*center2 );
    return num / denom;
}

int main() {
    int myInts[]{1, 5, 2, 1, 4, 0};   // 11
    int myInts1[]{5, 5, 5, 4};    //
    int myInts2[]{1, 1, 3, 5, 0};    //
    int myInts3[]{3, 1, 2, 2, 5, 6};    //
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));
    vector<int> v3(myInts3, myInts3 + sizeof(myInts3) / sizeof(int));

//    display(solution(v));
//    display(solution(v1));
//    display(solution(v2));
//    display(solution(v3));

    display(inter(0,1, 1,5));   // inclusion
    display(inter(0,1, 2,2));
    display(inter(0,1, 3,1));   // no
    display(inter(0,1, 4,4));
    display(inter(0,1, 5,0));   // no

    display(inter(3,1, 0,1));   // no
    display(inter(20,9, 0,2));   // no
    display(inter(3,1, 0,1));   // no
    display(inter(20,9, 0,2));   // no

    display(inter(20,9, 19,1));   // no
    display(inter(20,9, 15,2));   // no
    display(inter(19,12,0,9));   // no
    display(inter(15, 2, 20,9));   // no

    return 0;
}
/** Lesson 6
3. NumberOfDiscIntersections : Compute the number of intersections in a sequence of discs.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/
 */