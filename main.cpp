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
    if (S.empty())  return 1;
    if (S.size() % 2 != 0)  return 0;
    size_t startLeft = S.size() / 2 - 1;
    size_t startRight = S.size() / 2;
    map<char, char> symmetry = {{'}', '{'}, {']', '['}, {')', '('},
                                {'{', '}'}, {'[', ']'}, {'(', ')'}};
    int j(startRight);
    for (int i = startLeft; i > -1; --i) {
        if (S.at(i) != symmetry.at(S.at(j))) {
            return 1;
        }
        --i;
        ++j;
    }
    return 0;
/*    stack<char> opening;
    stack<char> closingTmp;
    stack<char> closing;
    for (char border : S) {
        if (border == '{' || border == '[' || border == '(')
            opening.push(border);
        else if (border == '}' || border == ']' || border == ')')
            closingTmp.push(symmetry.at(border));
    }
    while (!closingTmp.empty()) {
        closing.push(closingTmp.top());
        closingTmp.pop();
    }
    return opening == closing;*/
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
Task Score : %
Correctness : %
Performance : 100%  O()
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
