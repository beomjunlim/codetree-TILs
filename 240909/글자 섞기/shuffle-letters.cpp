#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> arr(n);
    vector<string> sortedArr(n);
    vector<string> reversedArr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sortedArr[i] = arr[i];
        sort(sortedArr[i].begin(), sortedArr[i].end());
        
        reversedArr[i] = sortedArr[i];
        reverse(reversedArr[i].begin(), reversedArr[i].end());
    }
    
    vector<pair<string, int>> sortedPairs(n);
    vector<pair<string, int>> reversedPairs(n);
    
    for (int i = 0; i < n; ++i) {
        sortedPairs[i] = {sortedArr[i], i};
        reversedPairs[i] = {reversedArr[i], i};
    }
    
    sort(sortedPairs.begin(), sortedPairs.end());
    sort(reversedPairs.begin(), reversedPairs.end());
    
    vector<int> minPos(n);
    vector<int> maxPos(n);
    
    for (int i = 0; i < n; ++i) {
        string sortedStr = sortedArr[i];
        string reversedStr = reversedArr[i];
        
        // Find min position
        auto minIt = lower_bound(reversedPairs.begin(), reversedPairs.end(), make_pair(sortedStr, -1));
        int minPosValue = distance(reversedPairs.begin(), minIt) + 1;
        
        // Find max position
        auto maxIt = upper_bound(sortedPairs.begin(), sortedPairs.end(), make_pair(reversedStr, n));
        int maxPosValue = distance(sortedPairs.begin(), maxIt) + 1;
        
        minPos[i] = minPosValue;
        maxPos[i] = maxPosValue;
    }
    
    for (int i = 0; i < n; ++i) {
        cout << minPos[i] << ' ' << maxPos[i] - 1 << '\n';
    }
    
    return 0;
}