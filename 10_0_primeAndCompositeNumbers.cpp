#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void display() { cout << endl; }

template<typename T, typename... Ts>
void display(T smth, Ts... smths) {
    cout << smth << " ";
    display(smths...);
}

int countDivisors(int n) {  /** O(√n) */
    int divisors(0);
    int i;
    for (i = 1; i * i < n; ++i)
        if (n % i == 0) divisors += 2;
    if (i * i == n) divisors++;
    return divisors;
}

int count_divisors(int n) {  /** O(√n) */
    int divisors(0);
    int i(1);
    while (i * i < n) {
        if (n % i == 0) divisors += 2;
        i++;
    }
    if (i * i == n) divisors++; // square roots are accounted for twice
    return divisors;
}

bool isPrime(int n) {  /** O(√n) */
    for (int i = 2; i * i < n; ++i) {   // We assume that 1 is neither a prime nor a composite number,
        if (n % i == 0) return false;
    }
    return true;
}

int countTails(int n) {  /** O(n*log n) */
    vector<bool> coins(n + 1, 0);
    int tails(0);
    for (size_t i = 1; i < coins.size(); ++i) {
        for (size_t j = i; j <= n; j += i) {    // can we say j < n + 1
            coins.at(j) = !coins.at(j);
            if (coins.at(j)) tails++;
            else tails --;
        }
    }
    return tails;
}

int coins(int n) {  /** O(n*log n) */
    int res(0);
    vector<bool> coins(n + 1, false);
    for (size_t i = 1; i < n + 1; ++i) {
        size_t k(i);
        while (k <= n) {
            coins.at(k) = (coins.at(k) + 1) % 2;
            k += i;
        }
        res += coins.at(i);
    }
    return res;
}

/**
 * Notice that each coin will be turned over exactly as many times as the number of its divisors. The coins that are
 * reversed an odd number of times show tails, meaning that it is sufficient to find the coins with an odd number of
 * divisors.We know that almost every number has a symmetric divisor (apart from divisors of the form √n). Thus, every
 * number of the form k² has an odd number of divisors. There are exactly floor(√n) such numbers between 1 and n. Finding
 * the value of floor(√n) takes logarithmic time (or constant time if we use operations on floating point numbers)
 */
int golden_tails_count(int n) {    /** O(n) */
    return (int) floor(sqrt(n));
}

int main() {
    display(countDivisors(36));   // 9
    display(countDivisors(25));   // 3
    display(countDivisors(24));   // 8
    display(countDivisors(81));   // 5
    display();
    display(isPrime(36));   // 0
    display(isPrime(25));   // 1
    display(isPrime(24));   // 0
    display(isPrime(81));   // 0
    display();
    display(coins(36));   // 6
    display(coins(25));   // 5
    display(coins(24));   // 4
    display(coins(81));   // 9
    display();
    display(countTails(36));   // 6
    display(countTails(25));   // 5
    display(countTails(24));   // 4
    display(countTails(81));   // 9
    display();
    display(golden_tails_count(36));   // 6
    display(golden_tails_count(25));   // 5
    display(golden_tails_count(24));   // 4
    display(golden_tails_count(81));   // 9

    return 0;
}

/** Lesson 10
0.1. Counting divisors : count the number of divisors of n.

 Task description : https://codility.com/media/train/8-PrimeNumbers.pdf
*/

/** Lesson 10
0.2. Primality test.

 Task description : https://codility.com/media/train/8-PrimeNumbers.pdf
*/

/** Lesson 10
0.3. Exercise (Reversing coins) : Consider n coins aligned in a row. Each coin is showing heads at the beginning.
                1   2   3   4   5   6   7   8   9   10
 Then, n people turn over corresponding coins as follows. Person i reverses coins with numbers that are multiples of i.
 That is, person i flips coins i, 2· i, 3· i, . . . until no more appropriate coins remain. The goal is to count the number
 of coins showing tails. In the above example,the final configuration is:
                1_^   2   3   4_^   5   6   7   8   9_^   10

 Task description : https://codility.com/media/train/8-PrimeNumbers.pdf
*/
