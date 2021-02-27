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
    /*unsigned*/ int N = A.size();
    int C[N];
    int radius, intersectionsCount=0, t=0;

    // Mark left and middle of disks
    for (int center=0; center < N; center++) {
        C[center] = -1;
        radius = A[center];
        if (radius >= center) {
            C[0]++;
        } else {
            C[center - radius]++;
        }
    }
    // Sum of left side of disks at location
    for (int i=0; i<N; i++) {
        t += C[i];
        C[i] = t;
    }
    // Count pairs, right side only:
    // 1. overlaps based on disk size
    // 2. overlaps based on disks but not centers
    for (int i=0; i<N; i++) {
        radius = A[i];
        intersectionsCount += radius < N - i ? radius : N - i - 1;
        if (i != N-1) {
            intersectionsCount += C[radius < N - i ? i + radius : N - 1];
        }
        if (intersectionsCount > INTERSECTING_PAIRS_LIMIT) return -1;
    }
    return intersectionsCount;
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

    return 0;
}
/** Lesson 6
3. NumberOfDiscIntersections : Compute the number of intersections in a sequence of discs.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/

 http://www.lucainvernizzi.net/blog/2014/11/21/codility-beta-challenge-number-of-disc-intersections/
 */