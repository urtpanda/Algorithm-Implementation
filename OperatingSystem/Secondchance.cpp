#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure to represent a page with its reference bit
struct Page {
    int pageNumber;
    bool referenceBit;

    Page(int number) : pageNumber(number), referenceBit(false) {}
};

// Function to implement the Second-Chance Algorithm
void secondChanceAlgorithm(vector<int> pages, int frameSize) {
    queue<Page> memory;  // Simulates the memory frames
    int pageFaults = 0;

    for (int page : pages) {
        bool pageFound = false;

        // Check if the page is already in memory
        queue<Page> tempQueue = memory;
        while (!tempQueue.empty()) {
            Page currentPage = tempQueue.front();
            tempQueue.pop();
            if (currentPage.pageNumber == page) {
                pageFound = true;
                break;
            }
        }

        if (pageFound) {
            // If page is found, set its reference bit to true
            queue<Page> updatedQueue;
            while (!memory.empty()) {
                Page currentPage = memory.front();
                memory.pop();
                if (currentPage.pageNumber == page) {
                    currentPage.referenceBit = true;
                }
                updatedQueue.push(currentPage);
            }
            memory = updatedQueue;
        } else {
            // Page fault occurred
            pageFaults++;

            // If memory is full, find a page to replace
            if (memory.size() == frameSize) {
                while (true) {
                    Page frontPage = memory.front();
                    memory.pop();

                    if (frontPage.referenceBit) {
                        // If reference bit is set, give a second chance
                        frontPage.referenceBit = false;
                        memory.push(frontPage);
                    } else {
                        // Replace the page
                        break;
                    }
                }
            }

            // Add the new page to memory
            memory.push(Page(page));
        }

        // Display the memory state
        cout << "Memory: ";
        queue<Page> displayQueue = memory;
        while (!displayQueue.empty()) {
            Page p = displayQueue.front();
            displayQueue.pop();
            cout << p.pageNumber << " ";
        }
        cout << endl;
    }

    cout << "Total Page Faults: " << pageFaults << endl;
}

int main() {
    vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int frameSize = 3;

    secondChanceAlgorithm(pages, frameSize);

    return 0;
}
