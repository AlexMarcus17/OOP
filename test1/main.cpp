#include <iostream>
#include "duration.h"
#include "TaskRepository.h"
using namespace std;
int main() {
    Duration d1 = Duration(70,'m');
    cout<<d1.getSeconds()<<endl;
    cout<<d1.get('h')<<endl;
    d1.print();
    Duration d2 = Duration(3200, 's');
    d1.plus(d2);
    cout<<d1.getSeconds()<<endl;
    cout<<d1.compare(d2)<<endl;
    TaskRepository taskRepository = TaskRepository(10);
    taskRepository.add(1, d1);
    taskRepository.add(2,d2);
    taskRepository.print(' ');
    cout<<taskRepository.getTotal().getSeconds()<<endl;
    int* ids = taskRepository.find_tasks_between(Duration(40,'m'),Duration(80,'m'));
    cout<<*ids<<endl;
    cout<<*(ids+1)<<endl;
    taskRepository.deleteTasks();
    return 0;
}
