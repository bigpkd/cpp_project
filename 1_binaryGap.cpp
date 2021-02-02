#include <bitset>
#include <set>

#include <iostream>
#include <climits>

using namespace std;

int solution(int N) {
    bitset<32> bitN(N);
    set<int> gaps;
    if (!bitN.none() && !bitN.all()) {
        string remaining = bitN.to_string().substr(bitN.to_string().find_first_of('1'));
        size_t found = remaining.find_first_of('1');
        while (found!=std::string::npos) {
            gaps.emplace(remaining.substr(0, found).size());
            remaining = remaining.substr(found + 1);
            if (bitset<32>(remaining).none() || bitset<32>(remaining).all()) break;
            found = remaining.find_first_of('1');
        }
    }
    return *gaps.rbegin();
}

int main() {
//    cout << INT_MAX << endl;
//    cout << bitset<32>(2147483647) << endl;

    cout << bitset<32>(2147483647) << endl;
    cout << solution(2147483647) << endl;

    cout << bitset<32>(1041) << endl;
    cout << solution(1041) << endl;

    cout << bitset<32>(32) << endl;
    cout << solution(32) << endl;

    return 0;
}
/** Lesson 1
1. BinaryGap : Find longest sequence of zeros in binary representation of an integer.
        Task Score : 100%
        Correctness : 100%
        Performance : Not assessed

Task description : https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

*/