#include <iostream>
#include <assert.h>

#include "gperftools/heap-checker.h"

using namespace std;

struct Info
{
    int type;
    std::string name;
};

class SimpleWorker
{
public:
    void ToWork()
    {
        HeapLeakChecker heap_checker("heap_checker_test_foo");
        {
            for(int i = 0; i < 10; i++) {
                auto info = new Info;
                info->type = 1;
                info->name = "mike";

                // do something...
                std::cout << "new info addr:" << info << std::endl;

                // forget to delete...
            }
        }

        if (!heap_checker.NoLeaks()) {
            cout << "SimpleWorker::ToWork heap memory leak" << endl;
//            assert(NULL == "heap memory leak");
        }
    }
};

void NonClassFunWorkNonLeak()
{
    int* num = new int(1024);
    cout << "num value: " << *num << endl;

    delete num;
}

void NonClassFunWorkLeak()
{
    int* num = new int(2048);
    cout << "num value: " << *num << endl;
    malloc(5000);
    // forget to delete...
}

int main()
{
    cout << "Start heap check!" << endl;

    SimpleWorker worker;
    worker.ToWork();

    NonClassFunWorkNonLeak();
    NonClassFunWorkLeak();

    cout << "Stop heap check!" << endl;

    return 0;
}
