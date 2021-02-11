#include <iostream>
#include <vector>
#include <map>
#include <set>
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
    vector<int> res;
    if (!S.empty()) {
        string sample;
        vector<size_t> sampleLengths;
        for (size_t i = 0; i < min(P.size(), Q.size()); ++i) {
            string subSample = S.substr(P.at(i), Q.at(i) + 1);
            sample.append(subSample);
            sampleLengths.push_back(Q.at(i) + 1 - P.at(i));
        }
        size_t letterCount(0);
        set<size_t> impactFactorsSet;
        map<char, size_t> impactFactorsMap{{'A', 1},
                                        {'C', 2},
                                        {'G', 3},
                                        {'T', 4}};
        auto lengthIter(sampleLengths.begin());
        for (const char &aChar : sample) {
            size_t &anImpactFactor = impactFactorsMap.at(aChar);
            impactFactorsSet.emplace(anImpactFactor);
            letterCount++;
            if (letterCount == *lengthIter/*sampleLengths.front()*/) {
                res.push_back(*impactFactorsSet.begin());
                impactFactorsSet.clear();
//                sampleLengths.erase(sampleLengths.begin());
                lengthIter++;
                letterCount = 0;
            }
        }
    }
    return res;
}

int main() {
    int myInts[]{2, 5, 0};
    int myInts1[]{4, 5, 6};
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));

    string s("CAGCCTA"), empty;
    displayVector(solution(s , v, v1));
    displayVector(solution(empty , v, v1));

    return 0;
}
/** Lesson 5
1. GenomicRangeQuery : Find the minimal nucleotide from a range of sequence DNA.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(1)
Task description : https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/
 */