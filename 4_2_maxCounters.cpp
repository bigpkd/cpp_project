#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

template<typename T>
void displayVector(const std::vector<T> vector) {
    for (const auto &it : vector) {
        cout << it << " ; ";
    }
    cout << endl;
}

vector<int> solution(int N, vector<int> &A) {
    vector<int> counters(N);
    int highestCounter = 0;
    int lastUpdate = 0;
    for (int &counterNumber : A) {
        if (1 <= counterNumber && counterNumber <= N) {
            int index = --counterNumber;
            if (counters.at(index) < lastUpdate) {
                counters.at(index) = lastUpdate + 1;
            } else {
                ++counters.at(index);
            }
            if (highestCounter < counters.at(index)) {
                highestCounter = counters.at(index);
            }
        } else if (counterNumber == N + 1) {
            lastUpdate = highestCounter;
        }
    }
    for (int &counter : counters) {
        if (counter < lastUpdate) {
            counter = lastUpdate;
        }
    }
    return counters;
}

int main() {
    int myInts[] = {3, 4, 4, 6, 1, 4, 4};
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    displayVector(solution(5, v));

    return 0;
}
/** Lesson 4
2. MaxCounters : Calculate the values of counters after applying all alternating operations: increase counter by 1; set value of all counters to current maximum.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N + M)
Task description : https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/
 */
