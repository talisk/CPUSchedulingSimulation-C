#include "Schedule.h"

using namespace std;

int main() {
    // Init Data Structure
    PCBQueue queue;
    InitQueue(queue);

    cout<<"Fill data from file(0)"<<endl;
    cout<<"Fill data from user input(other)"<<endl;

    int selection;
    cin>>selection;

    if (!selection) {
        cout<<"File path:";
        string path;
        cin>>path;
        // Fill data from file
        GetDataToQueue(path, queue);
    } else {
        // Fill data from user input
        for (int i = 0; i < 3; ++i) {
            EnterQueue(queue);
        }
    }

    // Go Scheduling
    Schedule(queue);

    return 0;
}