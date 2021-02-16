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

int solution(vector<int> &A) {
    const int PASSING_CARS_LIMIT(1000000000);
    long pairsOfPassingCars(0);             // Les trois variables suivantes doivent avoir ces types là précisément
    unsigned int eastCars(0), westCars(0);  // pour passer tous les tests
    for (const int &direction : A) {
        if (direction == 1) {
            westCars++;
        }
        else if (direction == 0){
            pairsOfPassingCars += eastCars * westCars;
            westCars = 0;
            eastCars++;
        }
        if (pairsOfPassingCars > PASSING_CARS_LIMIT) {
            pairsOfPassingCars = -1;
            break;
        }
    }
    if (A.back() == 1 && pairsOfPassingCars != -1) {
        pairsOfPassingCars += eastCars * westCars;
        if (pairsOfPassingCars > PASSING_CARS_LIMIT) pairsOfPassingCars = -1;
    }
    return pairsOfPassingCars;
}

int main() {
    int myInts[]{0, 1, 0, 1, 1};    // 5
    int myInts1[]{0, 0, 0, 1, 1, 1};    // 9
    int myInts3[]{0, 1, 1, 0, 1, 1, 0, 1, 1};   // 12
    int myInts2[]{0, 1, 1, 0, 1, 1, 0, 1, 1, 0};    // 12
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
/** Lesson 5
3. PassingCars : Count the number of passing cars on the road.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N)
Task description : https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/
 */