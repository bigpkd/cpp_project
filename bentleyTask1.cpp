/** Find a string of a given length such that each letter occurs an odd number of times
 */
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
}

int main() {
//    std::cout << vectorToString(toSumOfOddNumbers(15)) << std::endl;
//    std::cout << vectorToString(toSumOfOddNumbers(111)) << std::endl;
//    std::cout << vectorToString(toSumOfOddNumbers(110)) << std::endl;
//    std::cout << vectorToString(toSumOfOddNumbers(242)) << std::endl;

    char aChar = randomLowerCaseChar();
    std::cout << aChar << std::endl;
    std::cout << ++aChar << std::endl;
    std::cout << ++aChar << std::endl;
    std::cout << ++aChar << std::endl;
    return 0;
}
