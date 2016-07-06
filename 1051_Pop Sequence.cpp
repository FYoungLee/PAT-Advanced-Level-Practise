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
