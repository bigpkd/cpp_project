#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> toSumOfOddNumbers(int N) {
    vector<int> res;
    if (N % 2 == 0) {
        int count = 0;
        while (N % 2 == 0) {
            count++;
            N /= 2;
        }
        res = vector<int>(++count, N);
    } else {
        res.push_back(N);
    }
    return res;
}

string vectorToString(vector<int> vector) {
    string res = "";
    for (int val : vector) {
        res += to_string(val) + " ";
    }
    return res;
}

char randomLowerCaseChar() {
    return 'a' + rand()%26;
}

string solution(int N) {
    string res = "";
    vector<int> sumOfNumbers = toSumOfOddNumbers(N);
    char first = randomLowerCaseChar();
    for (int number : sumOfNumbers) {
        res.append(string(number, first));
        ++first;
        if (first == 'z' + 1) first = 'a';
    }
    return res;
}

int main() {
//    cout << vectorToString(toSumOfOddNumbers(15)) << endl;
//    cout << vectorToString(toSumOfOddNumbers(111)) << endl;
//    cout << vectorToString(toSumOfOddNumbers(110)) << endl;
//    cout << vectorToString(toSumOfOddNumbers(242)) << endl;

//    char aChar = randomLowerCaseChar();
//    cout << aChar << endl;
//    cout << ++aChar << endl;
//    cout << ++aChar << endl;
//    cout << ++aChar << endl;

    cout << solution(15) << endl;
    cout << solution(111) << endl;
    cout << solution(110) << endl;
    cout << solution(242) << endl;
    
    return 0;
}
