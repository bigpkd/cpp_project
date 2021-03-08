#include <iostream>
#include <stack>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

int solution(vector<int> &H) { // https://codility.com/media/train/solution-stone-wall.pdf
    stack<int> s;
    size_t blocks(0);
    for (const int &height : H) {
        while (!s.empty() && s.top() > height) {
            s.pop();
        }
        if (s.empty() || s.top() < height) {
            blocks++;
            s.push(height);
        }
    }
    return blocks;
}

int main() {
    int myInts[]{8, 8, 5, 7, 9, 8, 7, 4, 8};   //   7
    int myInts1[]{8, 8, 5, 7, 9, 8, 7, 4, 8};    // 7
    int myInts2[]{8, 7, 7, 8, 9, 4, 5, 8, 8};    // 7
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));

    display(solution(v));
    display(solution(v1));
    display(solution(v2));

    return 0;
}

/** Lesson 7
4. StoneWall : Cover "Manhattan skyline" using the minimum number of rectangles.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N)
Task description : https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/
*/
