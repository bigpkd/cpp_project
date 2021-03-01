#include <iostream>
#include <vector>
#include <map>
#include <stack>
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

int solution(vector<int> &H) {
    stack<int> s;
    set<int> existingHeights;
    size_t blocs(0);
    s.push(static_cast<int>(2 * 10e9));
    for (int height : H) {
        int lastTop = s.top();
        if (lastTop > height) {
            if (existingHeights.find(height) == existingHeights.end()) {
                blocs++;
                s.push(height);
            } else {
                if (height != *existingHeights.begin()) {
                    blocs++;
                    s.push(height);
                }
            }
        } else if (lastTop < height) {
            blocs++;
            s.push(height);
        } else if (lastTop == height) {
            continue;
        }
        existingHeights.emplace(height);
    }
    return blocs;
}

int main() {
    int myInts[]{8, 8, 5, 7, 9, 8, 7, 4, 8};   //
    int myInts1[]{0, 8, 5, 7, 9, 8, 7, 4, 8};    //
    int myInts2[]{8, 7, 7, 8, 9, 4, 5, 8, 8};    //
//    int myInts3[]{3, 1, 2, 2, 5, 6};    //
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));
//    vector<int> v3(myInts3, myInts3 + sizeof(myInts3) / sizeof(int));

    display(solution(v));
    display(solution(v1));
    display(solution(v2));
//    display(solution(v4));
//    display(solution(v3));

    return 0;
}

/** Lesson 7
4. StoneWall : Cover "Manhattan skyline" using the minimum number of rectangles.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/
*/
