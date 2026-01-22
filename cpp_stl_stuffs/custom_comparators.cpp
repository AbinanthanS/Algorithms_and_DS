#include <bits/stdc++.h>
using namespace std;

class Job {
public:
    int timestamp;
    vector<int> req;

    Job(int ts, vector<int> r) : timestamp(ts), req(r) {} //initializer list
};

int main() {
    
    vector<Job> jobs = {
        Job(5, {1, 2, 3}),
        Job(2, {4, 5, 6}),
        Job(8, {7, 8, 9}),
        Job(1, {10, 11, 12})
    };

    
    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) {
        return a.timestamp < b.timestamp;
    });

    
    for (const auto &job : jobs) {
        cout << "Timestamp: " << job.timestamp << ", Req: ";
        for (int r : job.req) {
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}

