#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;

    // Taking user input for the number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    int processes[n], burst_time[n], arrival_time[n], remaining_time[n], waiting_time[n], turnaround_time[n];

    // Taking user input for burst time and arrival time
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1; // Process IDs start from 1
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burst_time[i];
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> arrival_time[i];
        remaining_time[i] = burst_time[i]; // Initialize remaining time with burst time
    }

    int completed = 0, current_time = 0, min_time = INT_MAX;
    int shortest = 0, finish_time;
    bool found = false;

    // Main loop to calculate waiting time and turnaround time
    while (completed != n) {
        // Find the process with the shortest remaining time
        for (int j = 0; j < n; j++) {
            if (arrival_time[j] <= current_time && remaining_time[j] < min_time && remaining_time[j] > 0) {
                min_time = remaining_time[j];
                shortest = j;
                found = true;
            }
        }

        if (!found) {
            current_time++;
            continue;
        }

        // Reduce the remaining time of the current process
        remaining_time[shortest]--;

        // Update the minimum remaining time
        min_time = remaining_time[shortest];
        if (min_time == 0)
            min_time = INT_MAX;

        // If the process is completed
        if (remaining_time[shortest] == 0) {
            completed++;
            found = false;
            finish_time = current_time + 1;
            waiting_time[shortest] = finish_time - burst_time[shortest] - arrival_time[shortest];
            if (waiting_time[shortest] < 0)
                waiting_time[shortest] = 0;
        }

        // Increment the current time
        current_time++;
    }

    // Calculate turnaround time and display results
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        cout << "Process " << processes[i] << ": Waiting time = " << waiting_time[i]
             << ", Turnaround time = " << turnaround_time[i] << endl;
    }

    return 0;
}

