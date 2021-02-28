#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

int solution(vector<int> &A, vector<int> &B) {
    stack<int> flowingDownstream;   // source -> mouth
    size_t flowingUpstream(0);     // source <- mouth
    for (size_t i = 0; i < B.size(); ++i) {
        int direction = B.at(i);
        if (direction == 1)
            flowingDownstream.push(A.at(i));
        else if (direction == 0) {
            if (flowingDownstream.empty()) flowingUpstream++;
            else {
                int lastUpstreamFishSize = flowingDownstream.top();
                while (lastUpstreamFishSize < A.at(i)) {
                    flowingDownstream.pop();
                    if (!flowingDownstream.empty()) {
                        lastUpstreamFishSize = flowingDownstream.top();
                    } else {
                        flowingUpstream++;
                        break;
                    }
                }
            }
        }
    }
    return (int) (flowingUpstream + flowingDownstream.size());
}

int main() {
    int myInts[]{4, 3, 2, 1, 5};   //
    int myInts1[]{0, 1, 0, 0, 0};    //
    int myInts2[]{1, 1, 0, 0, 0};    //
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));

    display(solution(v, v1));   // 2
    display(solution(v, v2));   // 1

    return 0;
}

/** Lesson 7
2. Fish : N voracious fish are moving along a river. Calculate how many fish are alive. .
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N)
Task description : https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/
*/
