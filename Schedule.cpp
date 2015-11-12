//
// Created by 孙恺 on 15/11/7.
//

#include "Schedule.h"

void Run(PCBQueue &queue) {
    SortQueueWithPriority(queue);
    cout<<"Now Run"<<endl;
    queue.front->priority--;
    queue.front->requiredTime--;
    if (queue.front->requiredTime==0) queue.front->status = 0;

    PrintProcess(queue.front);
    cout<<endl;

    if (queue.front->requiredTime!=0) {
        SortQueueWithPriority(queue);
    } else {
        queue.front->status = 0;
        DeleteProcessFromQueue(queue, queue.front);
    }
}

void Schedule(PCBQueue &queue) {
    while (queue.count!=0) {
        Run(queue);
    }
    cout<<"Scheduling finished"<<endl;
    exit(0);
}