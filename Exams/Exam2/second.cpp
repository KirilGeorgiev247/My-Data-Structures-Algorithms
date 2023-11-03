#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    int T;
    
    
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        int N;
        int X;
        pair<int, int> arr[50000];
        cin >> X;
        cin >> N;
        for(int j = 0; j < N; j++) {
            cin >> arr[j].first;
            arr[j].second = j;
        }
        
        sort(arr, arr + N);
        
        int left = 0;
        int right = N - 1;

        while(left <= right) {
            
            if(arr[left].first + arr[right].first == X) {
                cout << min(arr[left].second + 1, arr[right].second + 1) << ' ' << max(arr[left].second + 1, arr[right].second + 1);
                break;
            }
            else if(arr[left].first + arr[right].first < X) 
                left++;
            else 
                right--;
        }
        
        if(i != T - 1)
            cout << '\n';
        
    }
    
    
}