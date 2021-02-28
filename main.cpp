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

int solution(string &S) {
    stack<char> opening;
    for (char character : S) {
        switch (character) {
            case '}':
                if (opening.empty() || opening.top() != '{') return 0;
                opening.pop();
                break;
            case ']':
                if (opening.empty() || opening.top() != '[') return 0;
                opening.pop();
                break;
            case ')':
                if (opening.empty() || opening.top() != '(') return 0;
                opening.pop();
                break;
            default:
                opening.push(character);
                break;
        }
    }
    return opening.empty() ? 1 : 0;
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

    string empty = "", s = "{[()()]}", s1 = "([)()]", s2 = ")(", s3 = "{{{{", s4;

    display(solution(empty));
    display(solution(s));
    display(solution(s1));
    display(solution(s2));
//    display(solution(v3));

    return 0;
}
/** Lesson 7
1. Brackets : Determine whether a given string of parentheses (multiple types) is properly nested.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N)
Task description : https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/
*/

/** Lesson 7
2. Fish : N voracious fish are moving along a river. Calculate how many fish are alive. .
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/
*/

/** Lesson 7
3. Nesting : Determine whether a given string of parentheses (multiple types) is properly nested.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/
*/

/** Lesson 7
4. StoneWall : Cover "Manhattan skyline" using the minimum number of rectangles.
Task Score : %
Correctness : %
Performance : 100%  O()
Task description : https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/
*/
