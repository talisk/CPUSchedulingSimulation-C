//
// Created by 孙恺 on 15/11/7.
//

#include "Global.h"

#ifndef CPUSCHEDULING_PCB_H
#define CPUSCHEDULING_PCB_H

#pragma mark - Data type define

typedef struct PCB {
    string processName;
    int requiredTime;
    int priority;
    int status;
    struct PCB *next;
}PCB, *PCBPtr;

typedef struct PCBQueue {
    int count;
    PCBPtr front;
    PCBPtr rear;
}PCBQueue;


#pragma mark - Queue operation

void InitQueue (PCBQueue &queue);

void DestoryQueue (PCBQueue &queue);

void EnterQueue (PCBQueue &queue);

void EnterQueue (PCBQueue &queue, PCBPtr process);

void DeleteProcessFromQueue (PCBQueue &queue, PCBPtr process);

void SortQueueWithPriority (PCBQueue &queue);

#pragma mark - Output

void PrintQueue (PCBQueue &queue);

void PrintProcess (PCBPtr process);

#endif //CPUSCHEDULING_PCB_H
