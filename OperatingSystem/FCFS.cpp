#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> processes(n);
    vector<int> burst_time(n);
    vector<int> arrival_time(n);
    vector<int> remaining_time(n);
    vector<int> waiting_time(n, 0);
    vector<int> turnaround_time(n, 0);

    for (int i = 0; i < n; i++) {
        processes[i] = i;
        cout << "Enter burst time for process " << i << ": ";
        cin >> burst_time[i];
        cout << "Enter arrival time for process " << i << ": ";
        cin >> arrival_time[i];
        remaining_time[i] = burst_time[i]; // Initialize remaining time
    }

    int completed = 0;
    int current_time = 0;
    bool found = false;

    while (completed != n) {
        int earliest_arrival = INT_MAX;
        int idx = -1;

        // Find the process that has arrived and not yet completed
        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && remaining_time[i] > 0) {
                if (arrival_time[i] < earliest_arrival) {
                    earliest_arrival = arrival_time[i];
                    idx = i;
                    found = true;
                }
            }
        }

        if (!found) {
            current_time++;
            continue;
        }

        // Execute the process completely (Non-preemptive)
        current_time += remaining_time[idx];
        waiting_time[idx] = current_time - burst_time[idx] - arrival_time[idx];
        if (waiting_time[idx] < 0) waiting_time[idx] = 0;
        turnaround_time[idx] = burst_time[idx] + waiting_time[idx];

        remaining_time[idx] = 0; // Mark process as completed
        completed++;
        found = false;
    }

    // Display results
    cout << "\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i] << "\t"
             << burst_time[i] << "\t\t"
             << arrival_time[i] << "\t\t"
             << waiting_time[i] << "\t\t"
             << turnaround_time[i] << endl;
    }

    return 0;
}
