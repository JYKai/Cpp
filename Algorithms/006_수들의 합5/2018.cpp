#include <iostream>
using namespace std;

int main(void)
{
    int N; cin >> N;
    int count = 1;
    int start_idx = 1;
    int end_idx = 1;
    int sum = 1;

    while (end_idx != N)
    {
        if (sum == N)
        {
            count++;
            end_idx++;
            sum += end_idx;
        }

        else if (sum > N)
        {
            sum -= start_idx;
            start_idx++;
        }

        else if (sum < N)
        {
            end_idx++;
            sum += end_idx;
        }
    }

    cout << count << endl;
}
