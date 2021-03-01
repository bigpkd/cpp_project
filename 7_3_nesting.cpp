#include <iostream>
#include <stack>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

int solution(string &S) {
    stack<char> opening;
    for (const char &character : S) {
        if (character == ')') {
            if (opening.empty() || opening.top() != '(') return 0;
            opening.pop();
        } else {
            opening.push(character);
        }
    }
    return opening.empty() ? 1 : 0;
}

int main() {

    string empty;
    string s = "()()()()";
    string s1 = "(())()()";
    string s2 = ")(";
    string s3 = "()";

    display(solution(empty));   // 1
    display(solution(s));   // 1
    display(solution(s1));  // 1
    display(solution(s2));  // 0
    display(solution(s3));  // 1

    return 0;
}

/** Lesson 7
3. Nesting : Determine whether a given string of parentheses (multiple types) is properly nested.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N)
Task description : https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/
*/
