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

vector<int> solution_9(string &S, vector<int> &P, vector<int> &Q) {
/* NOTA : at all times we must be able to know the number of occurrences of each genome in any sequence */
    int genoms[3][S.size() + 1];
    for (size_t i = 0; i < S.size(); ++i) {
        genoms[0][i+1] = genoms[0][i] + ('A' == S.at(i));
        genoms[1][i+1] = genoms[1][i] + ('C' == S.at(i));
        genoms[2][i+1] = genoms[2][i] + ('G' == S.at(i));
    }
    vector<int> res(P.size());
    for (size_t i = 0; i < P.size(); ++i) {
        int fromIndex = P.at(i);
        int toIndex = Q.at(i) + 1;
        if (genoms[0][toIndex] - genoms[0][fromIndex] > 0) res.at(i) = 1;   // A exists in the sequence
        else if (genoms[1][toIndex] - genoms[1][fromIndex] > 0) res.at(i) = 2;  // No A, C exists in the sequence
        else if (genoms[2][toIndex] - genoms[2][fromIndex] > 0) res.at(i) = 3;  // No A nor C, G exists in the sequence
        else res.at(i) = 4;  // No A nor C nor G, thus T exists in the sequence
    }
    return res;
}
/** Using map instead of jagged arrays allows for example to use the ".at()" function that prevent code from executing when out of range */
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
/* NOTA : at all times we must be able to know the number of occurrences of each nucleotide in any sequence */
    const vector<size_t> prefixSums = vector<size_t>(S.size() + 1, 0);
    map<char, vector<size_t>> instances = {{'A', prefixSums}, {'C', prefixSums}, {'G', prefixSums}};
    // census of instances through prefix sums computation
    for (size_t i = 0; i < S.size(); ++i) {
        instances.at('A').at(i + 1) = instances.at('A').at(i) + ('A' == S.at(i));
        instances.at('C').at(i + 1) = instances.at('C').at(i) + ('C' == S.at(i));
        instances.at('G').at(i + 1) = instances.at('G').at(i) + ('G' == S.at(i));
    }
    vector<int> res(P.size());
    // deduction of minimal nucleotides of DNA sequence ranges
    for (size_t i = 0; i < P.size(); ++i) {
        int fromIndex = P.at(i);
        int toIndex = Q.at(i) + 1;  // due to prefixSum principle, this is where the sums including the instance at index i actually are
        if (instances.at('A').at(toIndex) - instances.at('A').at(fromIndex) > 0) res.at(i) = 1;   // A exists in the sequence
        else if (instances.at('C').at(toIndex) - instances.at('C').at(fromIndex) > 0) res.at(i) = 2;  // No A, C exists in the sequence
        else if (instances.at('G').at(toIndex) - instances.at('G').at(fromIndex) > 0) res.at(i) = 3;  // No A nor C, G exists in the sequence
        else res.at(i) = 4;  // No A nor C nor G, thus T exists in the sequence
    }
    return res;
}

int main() {
    int myInts[]{2, 5, 0};
    int myInts1[]{4, 5, 6};
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));

    string s("CAGCCTA");
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