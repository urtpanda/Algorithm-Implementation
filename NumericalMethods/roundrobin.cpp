#include <iostream>
using namespace std;

int main() {
    int n, quantum;

    // Taking user input for the number of processes and time quantum
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> quantum;

    int processes[n], burst_time[n], arrival_time[n], remaining_time[n];
    int waiting_time[n] = {0}, turnaround_time[n];

    // Taking user input for burst time and arrival time
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;  // Process IDs start from 1
        cout << "Enter arrival time for process " << processes[i] << ": ";
        cin >> arrival_time[i];
        cout << "Enter burst time for process " << processes[i] << ": ";
        cin >> burst_time[i];
        remaining_time[i] = burst_time[i];  // Initialize remaining time with burst time
    }

    int current_time = 0, completed = 0;
    bool done;

    // Loop until all processes are completed
    while (completed < n) {
        done = true;
        // Traverse all processes
        for (int i = 0; i < n; i++) {
            // Process only if it has arrived and has remaining burst time
            if (arrival_time[i] <= current_time && remaining_time[i] > 0) {
                done = false;  // At least one process is still not completed

                if (remaining_time[i] > quantum) {
                    // Process runs for the time quantum
                    current_time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    // Process completes within the time quantum
                    current_time += remaining_time[i];
                    waiting_time[i] = current_time - burst_time[i] - arrival_time[i];
                    turnaround_time[i] = current_time - arrival_time[i];
                    remaining_time[i] = 0;
                    completed++;
                }
            }
        }

        // If no process is ready, move time forward
        if (done) {
            current_time++;
        }
    }

    // Display results
    for (int i = 0; i < n; i++) {
        cout << "Process " << processes[i] << ": Waiting time = " << waiting_time[i]
             << ", Turnaround time = " << turnaround_time[i] << endl;
    }

    return 0;
}
