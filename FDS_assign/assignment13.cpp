#include <iostream>
#include <queue>

using namespace std;

// Function to add a job to the queue
void addJob(queue<string> &jobQueue, const string &job)
{
    jobQueue.push(job);
    cout << "Job added to the queue: " << job << endl;
}

// Function to delete a job from the queue
void deleteJob(queue<string> &jobQueue)
{
    if (!jobQueue.empty())
    {
        cout << "Job deleted from the queue: " << jobQueue.front() << endl;
        jobQueue.pop();
    }
    else
    {
        cout << "Queue is empty. No job to delete." << endl;
    }
}

// Function to display the jobs in the queue
void displayJobs(const queue<string> &jobQueue)
{
    cout << "Jobs in the queue:" << endl;
    queue<string> tempQueue = jobQueue; // Create a copy for display without modifying the original
    while (!tempQueue.empty())
    {
        cout << tempQueue.front() << endl;
        tempQueue.pop();
    }
}

int main()
{
    queue<string> jobQueue;

    // Adding jobs to the queue
    addJob(jobQueue, "Job 1");
    addJob(jobQueue, "Job 2");
    addJob(jobQueue, "Job 3");

    // Displaying the initial jobs in the queue
    displayJobs(jobQueue);

    // Deleting a job from the queue
    deleteJob(jobQueue);

    // Displaying the updated jobs in the queue
    displayJobs(jobQueue);

    return 0;
}
