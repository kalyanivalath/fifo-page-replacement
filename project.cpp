#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// checks if page is already inside memory
static bool isPageF(const vector<int>& frames, int page)
{
    return find(frames.begin(), frames.end(), page) != frames.end();
}

// prints the current frames
static void printFrames(const vector<int>& frames)
{
    for (int page : frames)
    {
        cout << page << " ";
    }
    cout << "\n";
}

int main()
{
    // number of frames
    int frameCount = 0;

    // reads the word "Frames" and then the number
    string label;
    cin >> label >> frameCount;

    // store page ref string, rep mem frames, keep track of the oldest page in q
    vector<int> pages;
    vector<int> frames;
    queue<int> fifoQueue;

    int page;

    // loop to read all page ref val
    while (cin >> page)
    {
        pages.push_back(page);
    }

    // print page ref str
    for (int p : pages)
    {
        cout << p << " ";
    }
    cout << "\n";

    cout << "Page replacement using FIFO\n";

    int pageFaults = 0;

    // goes through each page reference
    for (int i = 0; i < pages.size(); i++)
    {
        int currentPage = pages[i];

        // if page not in memory then page fault
        if (!isPageF(frames, currentPage))
        {
            pageFaults++;

            // if there is room add the page
            if (frames.size() < frameCount)
            {
                frames.push_back(currentPage);
                fifoQueue.push(currentPage);
            }
            else
            {
                // remove the oldest page
                int oldestPage = fifoQueue.front();
                fifoQueue.pop();

                // erase oldest page from frames
                auto it = find(frames.begin(), frames.end(), oldestPage);
                if (it != frames.end())
                {
                    frames.erase(it);
                }

                // add the new page
                frames.push_back(currentPage);
                fifoQueue.push(currentPage);
            }
        }

        cout << "time step " << i << ": ";
        printFrames(frames);
    }

    cout << "total number of page faults = " << pageFaults << "\n";
    return 0;
}
