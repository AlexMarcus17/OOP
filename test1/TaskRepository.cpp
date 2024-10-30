//
// Created by User on 27.03.2024.
//
#include "TaskRepository.h"
#include <iostream>

TaskRepository::TaskRepository(int capacity) {
    this->size = capacity;
    this->durations = new Duration[capacity];
    this->ids = new int[capacity];
}

void TaskRepository::resize() {
    Duration* newDurations = new Duration[size * 2];
    int* newIds = new int[size * 2];
    for(int i=0;i<size;i++) {
        newDurations[i] = this->durations[i];
        newIds[i] = this->ids[i];
    }
    size = size * 2;
    delete[] this->ids;
    delete[] this->durations;
    this->ids = newIds;
    this->durations = newDurations;
}

void TaskRepository::add(int id, Duration duration) {
    for(int i=0; i< this->elems; i++)
        if(id==this->ids[i]) {
            printf("Id already exists");
            return;
        }
    if(this->size == this->elems)
        this->resize();
    this->durations[elems] = duration;
    this->ids[elems] = id;
    elems++;
}

Duration TaskRepository::getTotal() {
    int totalseconds = 0;
    for(int i=0; i< this->elems; i++)
        totalseconds += this->durations[i].getSeconds();
    return Duration(totalseconds, 's');
}

void TaskRepository::print(char delimiter) {
    for(int i=0; i< this->elems; i++) {
        std::cout<<this->ids[i]<<delimiter<<this->durations[i].getSeconds()<<std::endl;
    }
}

void TaskRepository::deleteTasks() {
    this->ids = nullptr;
    this->durations = nullptr;
}

int *TaskRepository::find_tasks_between(Duration min_duration, Duration max_duration) {
    int* IDs = new int[this->elems];
    int index = 0;
    int minseconds = min_duration.getSeconds();
    int maxseconds = max_duration.getSeconds();
    for(int i=0; i< this->elems; i++) {
        if(this->durations[i].getSeconds()>=minseconds&&this->durations[i].getSeconds()<=maxseconds) {
            IDs[index] = this->ids[i];
            index++;
        }

    }
}