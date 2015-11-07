#include "Schedule.h"

using namespace std;

int main() {
    PCBQueue queue;
    InitQueue(queue);

    // Fill data
    for (int i = 0; i < 3; ++i) {
        EnterQueue(queue);
    }

    // Go Scheduling
    Schedule(queue);

    return 0;
}