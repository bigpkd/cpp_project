#include <iostream>
#include <vector>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

//https://rafal.io/posts/codility-max-profit.html
int solution(vector<int> &A) {
    int maxProfit(0);
    int minPrice(A.empty() ? 0 : A.front());
    int maxProfitOnThatDay(0);
    for (int &priceOfTheDay : A) {
        minPrice = min(minPrice, priceOfTheDay);
        maxProfitOnThatDay = max(0, priceOfTheDay - minPrice); // The function should return 0 if it was impossible to gain any profit.
        maxProfit = max(maxProfit, maxProfitOnThatDay);
    }
    return maxProfit;
}

int main() {
    int myInts[]{3, 2, 6, -1, 4, 5, -1, 2};     //  6
    int myInts1[]{8, 8, 5, 7, 9, 8, 7, 4, 8};   //  4
    int myInts2[]{4, 6, 6, 6, 6, 8, 8};         //  4
    int myInts3[]{23171, 21011, 21123, 21366, 21013, 21367};    //   356
    vector<int> v(myInts, myInts + sizeof(myInts) / sizeof(int));
    vector<int> v1(myInts1, myInts1 + sizeof(myInts1) / sizeof(int));
    vector<int> v2(myInts2, myInts2 + sizeof(myInts2) / sizeof(int));
    vector<int> v3(myInts3, myInts3 + sizeof(myInts3) / sizeof(int));

    display(solution(v));
    display(solution(v1));
    display(solution(v2));
    display(solution(v3));

    return 0;
}

/** Lesson 9
2. MaxProfit : Given a log of stock prices compute the maximum possible earning.
Task Score : 100%
Correctness : 100%
Performance : 100%  O(N)
Task description : https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/
*/