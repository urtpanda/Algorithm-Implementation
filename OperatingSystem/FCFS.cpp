
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int processes[n], burst_time[n], arrival_time[n], waiting_time[n], turnaround_time[n];

    // Input burst time and arrival time
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burst_time[i];
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> arrival_time[i];
    }

    int service_time[n];
    service_time[0] = arrival_time[0];
    waiting_time[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + burst_time[i - 1];
        waiting_time[i] = service_time[i] - arrival_time[i];
        if (waiting_time[i] < 0)
            waiting_time[i] = 0;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }

    // Print results
    cout << "\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i] << "\t" << burst_time[i] << "\t\t" << arrival_time[i]
             << "\t\t" << waiting_time[i] << "\t\t" << turnaround_time[i] << endl;
    }

    return 0;
}
