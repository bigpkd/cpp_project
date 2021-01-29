#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> toSumOfOddNumbers(int N) {
    vector<int> res;
    if (N % 2 == 0) {
        res.push_back(N - 1);
        res.push_back(1);
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

    cout << solution(15) << " | " <<  solution(15).size() << endl;
    cout << solution(111) << " | " << solution(111).size() << endl;
    cout << solution(110) << " | " << solution(110).size() << endl;
    cout << solution(242) << " | " << solution(242).size() << endl;

    cout << solution(2) << " | " << solution(2).size() << endl;
    cout << solution(4) << " | " << solution(4).size() << endl;
    cout << solution(8) << " | " << solution(8).size() << endl;
    cout << solution(16) << " | " << solution(16).size() << endl;

    cout << solution(12) << " | " << solution(12).size() << endl;

    return 0;
}
