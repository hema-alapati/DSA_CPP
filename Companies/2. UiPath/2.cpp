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

