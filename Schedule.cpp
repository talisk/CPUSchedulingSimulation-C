//
// Created by 孙恺 on 15/11/7.
//

#include "Schedule.h"

void Run(PCBQueue &queue) {
    SortQueueWithPriority(queue);
    cout<<"Now Run ==============="<<endl;
    cout<<"Process "<<queue.front->processName<<endl;
    queue.front->priority--;
    queue.front->requiredTime--;

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
    } exit(0);
}