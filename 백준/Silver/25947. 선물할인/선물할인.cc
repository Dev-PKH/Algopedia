#include <bits/stdc++.h>
using namespace std;

#define ll long long

int arr[100002];
ll sum[100002], hsum[100002]; // 원가 누적합, 할인가 누적합

int n, b, a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b >> a;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + arr[i];             // 정가 누적합
        hsum[i] = hsum[i - 1] + arr[i] / 2;       // 할인가 누적합
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // i개의 선물을 살 때
        if (sum[i] <= b) ans = i;
        else {
            int k = min(a, i); // 할인 가능한 개수
            // i개 중 뒤에서 k개 할인 적용
            ll cost = sum[i] - ( (sum[i] - sum[i - k]) - (hsum[i] - hsum[i - k]) );
            if (cost <= b) ans = i;
        }
    }

    cout << ans;
    return 0;
}