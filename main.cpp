#include <iostream>
#include <vector>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    vector<int> res;
    return res;
}

int main() {
    int myInts[]{2, 5, 0};
    int myInts1[]{4, 5, 6};

    return 0;
}
/** Lesson 5
1. GenomicRangeQuery : Find the minimal nucleotide from a range of sequence DNA.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(1)
Task description : https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/
 */