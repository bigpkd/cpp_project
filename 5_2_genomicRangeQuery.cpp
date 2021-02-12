#include <iostream>
#include <vector>
#include <map>
#include <string>

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

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int genoms[3][S.size() + 1];
    short unsigned int a, c, g;
    for (size_t i = 0; i < S.size(); ++i) {
        a = 0; c = 0; g = 0;
        if ('A' == S.at(i)) a = 1;
        if ('C' == S.at(i)) c = 1;
        if ('G' == S.at(i)) g = 1;
        genoms[0][i+1] = genoms[0][i] + a;
        genoms[1][i+1] = genoms[1][i] + c;
        genoms[2][i+1] = genoms[2][i] + g;
    }
    vector<int> res(P.size());
    for (size_t i = 0; i < P.size(); ++i) {
        int fromIndex = P.at(i);
        int toIndex = Q.at(i) + 1;
        if (genoms[0][toIndex] - genoms[0][fromIndex] > 0) res.at(i) = 1;
        else if (genoms[1][toIndex] - genoms[1][fromIndex] > 0) res.at(i) = 2;
        else if (genoms[2][toIndex] - genoms[2][fromIndex] > 0) res.at(i) = 3;
        else res.at(i) = 4;
    }
    return res;
}

int main() {
    int myInts[]{2, 5, 0};
    int myInts1[]{4, 5, 6};
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));

    string s("CAGCCTA"), empty;
    displayVector(solution(empty , v, v1));
    displayVector(solution(s , v, v1));

    return 0;
}
/** Lesson 5
1. GenomicRangeQuery : Find the minimal nucleotide from a range of sequence DNA.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N + M) 
Task description : https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/
 */