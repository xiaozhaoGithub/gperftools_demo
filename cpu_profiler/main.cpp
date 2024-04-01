#include <iostream>

#include "gperftools/profiler.h"

using namespace std;

class SimpleWorker
{
public:
    long ToWork()
    {
        return 10;
    }
};

class ComplexWorker
{
public:
    long ToWork(int a)
    {
        long c = 77;
        c +=a;
        c *= 100;
        c /= 2;

        int num = 10;
        while (num--) {
            c += 1;
        }

        return c + 10;
    }
};

void NonClassFunSimpleWork()
{
    cout << "Non class fun simple work!" << endl;

    int num = 10;
    int value = 0;
    while(num--) {
        value += 1;
    }

    cout << "Non class fun simple work end!" << endl;
}

void NonClassFunWork()
{
    cout << "Non class fun work!" << endl;

    int num = __INT_MAX__;
    int value = 0;
    while(num--) {
        value += 1;
    }

    cout << "Non class fun work end!" << endl;
}

int main()
{
    ProfilerStart("cpu_profiler.prof");

    cout << "Start profiler!" << endl;

    int num = __INT_MAX__;

    SimpleWorker simple_worker;
    while (num--) {
        simple_worker.ToWork();
    }

    NonClassFunSimpleWork();
    NonClassFunWork();

    ComplexWorker complex_worker;
    int ret = 0;
    num = __INT_MAX__;
    while (num--) {
        ret += complex_worker.ToWork(1);
    }
    cout<< "ret:" << ret << endl;

    ProfilerStop();
    cout << "Stop profiler!" << endl;

    return 0;
}
