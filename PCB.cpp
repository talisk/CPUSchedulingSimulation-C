//
// Created by 孙恺 on 15/11/7.
//

#include "PCB.h"

#pragma mark - Queue operation

void InitQueue (PCBQueue &queue) { // success
    queue.count = 0;
    queue.front = NULL;
    queue.rear = NULL;
}

void DestoryQueue (PCBQueue &queue) {
    PCBPtr temp = queue.front;
    for (int i = 0; i < queue.count; ++i) {
        queue.front = queue.front->next;
        free(temp);
        temp = queue.front;
    }
    queue.rear = NULL;
}

void EnterQueue (PCBQueue &queue) { // success
    PCBPtr process = (PCBPtr)malloc(sizeof(PCB));
    cout<<"Process Name(string):"; cin>>process->processName;
    cout<<"Required Time(int):"; cin>>process->requiredTime;
    cout<<"Priority(int):"; cin>>process->priority;
    cout<<"Status(E0/R1):"; cin>>process->status;
    cout<<"======================="<<endl;
    process->next = NULL;

    if (queue.count==0) {
        queue.front = process;
        queue.rear = process;
    } else {
        queue.rear->next = process;
        queue.rear = process;
    }
    queue.count++;

}


void EnterQueue (PCBQueue &queue, PCBPtr process) {
    process->next = NULL;

    if (queue.count==0) {
        queue.front = process;
        queue.rear = process;
    } else {
        queue.rear->next = process;
        queue.rear = process;
    }
    queue.count++;

}

void DeleteProcessFromQueue (PCBQueue &queue, PCBPtr process) {
    if (queue.count==0) {
        queue.front=NULL; queue.rear = NULL;
        return;
    }

    if (queue.count==1) {
        queue.front=NULL; queue.rear = NULL;
        queue.count = 0;
        return;
    }

    PCBPtr previousPtr = queue.front;
    PCBPtr movablePtr = queue.front->next;
    if (queue.front->processName == process->processName) {
        queue.front = queue.front->next;
        queue.count--;
    } else {
        while (movablePtr!=NULL) {
            if (movablePtr->processName == process->processName) {
                previousPtr->next = movablePtr->next;
                queue.count--;
                return;
            }
            previousPtr = movablePtr;
            movablePtr = movablePtr->next;
        }
    }
}

void SortQueueWithPriority (PCBQueue &queue) {
    if (queue.count==0 && queue.count==1) return;

    // Init tempQueue
    PCBQueue tempQueue;
    InitQueue(tempQueue);

    PCBPtr maxPriorityProcess = queue.front;
    PCBPtr movablePtr = queue.front->next;

    while (queue.count!=0) {

        if (queue.count==1) {
            EnterQueue(tempQueue, queue.front);
            DeleteProcessFromQueue(queue, queue.front);
            break;
        }

        // Get the process with max priority
        for (int i = 1; i < queue.count; ++i) {
            if (movablePtr->priority > maxPriorityProcess->priority) {
                maxPriorityProcess = movablePtr;
            }
            movablePtr = movablePtr->next;

        }

        DeleteProcessFromQueue(queue, maxPriorityProcess);

        // Let the process enter the queue
        EnterQueue(tempQueue, maxPriorityProcess);

        maxPriorityProcess = queue.front;
        movablePtr = queue.front->next;
    }

    queue = tempQueue;

}

void GetDataToQueue(string fileName, PCBQueue &queue) {
    char buffer[256];
    ifstream in(fileName);
    if (!in.is_open()) {
        cout<<"Opening file error"<<endl;
        exit(1);
    }

    while (!in.eof()) {
        PCBPtr process = (PCBPtr)malloc(sizeof(PCB));

        process->next = NULL;

        in.getline(buffer,100);
        process->processName = buffer;

        in.getline(buffer,100);
        process->requiredTime = atoi(buffer);

        in.getline(buffer,100);
        process->priority = atoi(buffer);

        in.getline(buffer,100);
        process->status = atoi(buffer);

        EnterQueue(queue, process);
    }
}

#pragma mark - Output

void PrintQueue (PCBQueue &queue) { // success
    if (queue.count==0) return;
    PCBPtr point = queue.front;
    for (int i = 0; i < queue.count; ++i) {
        cout<<"Queue =================="<<endl;
        cout<<"Process Name:"<<point->processName<<endl;
        cout<<"Rqueired Time:"<<point->requiredTime<<endl;
        cout<<"Priority:"<<point->priority<<endl;
        cout<<"Status:"<<(point->status?"R":"E")<<endl;
        point = point->next;
    }
}

void PrintProcess (PCBPtr process) {
    if (process==NULL) return;
    cout<<"Process ==============="<<endl;
    cout<<"Process Name:"<<process->processName<<endl;
    cout<<"Rqueired Time:"<<process->requiredTime<<endl;
    cout<<"Priority:"<<process->priority<<endl;
    cout<<"Status:"<<(process->status?"R":"E")<<endl;
}