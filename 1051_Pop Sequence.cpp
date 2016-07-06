/*
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:
YES
NO
NO
YES
NO
*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int M, N, K, tp_i;
    cin >> M >> N >> K;
    vector<int> rst;
    for (int i = 0; i < K; ++i) {
        stack<int> stk_i;
        queue<int> que_i;
        for (int n = 0; n < N; ++n) {
            cin >> tp_i;
            que_i.push(tp_i);       }
        for (int n = 1; static_cast<int>(stk_i.size()) < M; ++n) {
            while (stk_i.size() && que_i.front() == stk_i.top()) {
                que_i.pop();
                stk_i.pop(); }
            if (n != que_i.front())
                stk_i.push(n);
            else {
                stk_i.push(n);
                stk_i.pop();
                que_i.pop(); } 
        }
        if (que_i.size() == 0) rst.push_back(1);
        else rst.push_back(0);
    }
    for (size_t n = 0; n < rst.size(); ++n)
        if (rst[n]) cout << "YES\n";
        else cout << "NO\n";
    return 0;
}
