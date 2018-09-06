#include <iostream>
#include "sklist.h"

using namespace std;

//Just for test
void *GenData(int len) {
    void *ptr = new char [len];

    return ptr;
}

int main()
{
    SkList *sklist = new SkList(3);

    sklist->Insert(1, GenData(3));
    sklist->Insert(2, GenData(2));
    sklist->Insert(3, GenData(4));
    sklist->Insert(4, GenData(5));
    sklist->Insert(5, GenData(5));
    sklist->Insert(6, GenData(3));
    sklist->Insert(7, GenData(2));
    sklist->Insert(8, GenData(4));
    sklist->Insert(9, GenData(5));
    sklist->Insert(10, GenData(5));

    sklist->Display();

    sklist->Delete(8);

    sklist->Display();

    return 0;
}

