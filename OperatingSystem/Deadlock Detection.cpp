
#include <iostream>
#include <vector>

using namespace std;

// Function to detect deadlock in the system
bool detectDeadlock(const vector<vector<int>>& allocation, const vector<vector<int>>& request, vector<int>& available) {
    int n = allocation.size();    // Number of processes
    int m = available.size();      // Number of resources

    vector<int> work = available;  // Initialize work as available resources
    vector<bool> finish(n, false); // Finish vector to track if a process can complete

    // Initialize finish for each process
    for (int i = 0; i < n; i++) {
        bool hasAllocation = false;
        for (int j = 0; j < m; j++) {
            if (allocation[i][j] != 0) {
                hasAllocation = true;
                break;
            }
        }
        finish[i] = !hasAllocation; // If no allocation, mark as true (already "finished")
    }

    bool foundProcess;
    while (true) {
        foundProcess = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) { // Process is not finished
                bool canAllocate = true;
                // Check if request[i] <= work
                for (int j = 0; j < m; j++) {
                    if (request[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                // If resources can be allocated to process i
                if (canAllocate) {
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j]; // Free resources held by process i
                    }
                    finish[i] = true; // Mark process i as finished
                    foundProcess = true; // Indicate that a process has been found
                    cout << "Process " << i << " can finish.\n";
                }
            }
        }
        // If no such process found, exit the loop
        if (!foundProcess) break;
    }

    // Detect if there is a deadlock
    bool deadlock = false;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) { // If finish[i] is still false, process i is deadlocked
            deadlock = true;
            cout << "Process " << i << " is in a deadlock.\n";
        }
    }
    return deadlock;
}

int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> request(n, vector<int>(m));
    vector<int> available(m);

    cout << "Enter allocation matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> allocation[i][j];

    cout << "Enter request matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> request[i][j];

    cout << "Enter available resources:\n";
    for (int j = 0; j < m; j++)
        cin >> available[j];

    if (detectDeadlock(allocation, request, available))
        cout << "Deadlock detected in the system.\n";
    else
        cout << "No deadlock detected in the system.\n";

    return 0;
}
