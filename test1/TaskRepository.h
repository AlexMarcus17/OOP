//
// Created by User on 27.03.2024.
//
#pragma once
#include "duration.h"

class TaskRepository {
private:
    int elems = 0;
    int size;
    int* ids;
    Duration* durations;
public:
    TaskRepository(int capacity);
    void resize();
    void add(int id, Duration duration);
    void print(char delimiter);
    Duration getTotal();
    void deleteTasks();
    int* find_tasks_between(Duration min_duration, Duration max_duration);
};
