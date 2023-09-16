// Implement a prototype of a resource allocation system in a distributed parallel computing infrastructure.
// There are n resources and m tasks to schedule on them where the th task has a processing time of burstTimeli]. The total load time of a resource is the sum of the total burst times of the jobs assigned to the resources. However, a particular resource can be allocated jobs in a contiguous segment only i.e. from some index x to some index y or [x, x + 1, x+2,.
// •, .
// Find the minimum possible value of the maximum total load time of the servers if resources are allocated optimally.
// Example
// Consider n = 3, m = 6, burst Time = [4, 3, 2, 2, 2, 6].
// An optimal resource allocation is shown.
// Server
// Jobs
// Total Load Time
// 1
// 4, 3
// 4+3=7
// 2
// 2, 2, 2
// 2+2+2=6
// 3
// 6
// 6
// Here, the maximum load on any machine is 7.
// Function Description
// Complete the function getMinMaxLoadTime in the editor below.
// getMinMaxLoadTime has the following parameter(S):
// int n. the number of resources.
// int burst Time/m]: the burst time of
// jobs
// Returns
// long int. the minimum max load of the job schedule
// Constraints
// • 1 5 ns 105
// . 1 ≤ ms 105
// • 1 < burstTimelils 109


#include <iostream>
#include <vector>

using namespace std;

bool isFeasible(vector<int>& burstTime, int n, int m, int maxLoad) {
    int currentLoad = 0;
    int servers = 1;

    for (int i = 0; i < m; ++i) {
        if (currentLoad + burstTime[i] <= maxLoad) {
            currentLoad += burstTime[i];
        } else {
            servers += 1;
            currentLoad = burstTime[i];
        }

        if (servers > n) {
            return false;
        }
    }

    return true;
}

long int getMinMaxLoadTime(int n, vector<int>& burstTime) {
    long int left = *max_element(burstTime.begin(), burstTime.end());
    long int right = accumulate(burstTime.begin(), burstTime.end(), 0);

    while (left < right) {
        long int mid = left + (right - left) / 2;
        if (isFeasible(burstTime, n, burstTime.size(), mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n;
    cout << "Enter the number of resources: ";
    cin >> n;

    vector<int> burstTime;
    cout << "Enter the burst times separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        int time;
        cin >> time;
        burstTime.push_back(time);
    }

    long int result = getMinMaxLoadTime(n, burstTime);
    cout << "Minimum max load of the job schedule: " << result << endl;

    return 0;
}


// python
// def getMinMaxLoadTime(n, burstTime):
//     def is_feasible(burstTime, n, m, max_load):
//         current_load = 0
//         servers = 1

//         for i in range(m):
//             if current_load + burstTime[i] <= max_load:
//                 current_load += burstTime[i]
//             else:
//                 servers += 1
//                 current_load = burstTime[i]
            
//             if servers > n:
//                 return False
        
//         return True

//     left = max(burstTime)  # Minimum possible load
//     right = sum(burstTime)  # Maximum possible load

//     while left < right:
//         mid = (left + right) // 2
//         if is_feasible(burstTime, n, len(burstTime), mid):
//             right = mid
//         else:
//             left = mid + 1

//     return left