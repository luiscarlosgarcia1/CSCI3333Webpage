#ifndef TASK_LIST_H
#define TASK_LIST_H

#include <cstddef>
#include <string>
#include <vector>
using namespace std;

// This file declares the public interface. Other .cpp files can include it.
class TaskList 
{
    public:
        void add(string task);
        void addSuffix(const string& suffix);

        int count();
        int countLongerThan(int length);

    private:
        vector<string> tasks;
};

#endif
