#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int sumA[100001] = {};

    for (int i = 1; i <= N; i++)
    {
        int temp; cin >> temp;
        sumA[i] = sumA[i - 1] + temp;
    }

    for (int i = 0; i < M; i++)
    {
        int left, right;
        cin >> left >> right;
        cout << sumA[right] - sumA[left - 1] << endl;
    }

    return 0;
}
