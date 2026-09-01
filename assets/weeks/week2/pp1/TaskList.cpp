#include "TaskList.h"

// Each definition repeats the class name and must match its declaration in TaskList.h.
void TaskList::add(string task) {
    tasks.push_back(task);
}

void TaskList::addSuffix(const std::string& suffix) {
    // `task` is a reference to the element stored in `tasks`.
    // Changing task changes the vector's original string.
    for (auto& task : tasks) {
        task += suffix;
    }
}

int TaskList::count() {
    return tasks.size();
}

int TaskList::countLongerThan(int length) {
    int matches = 0;

    // `const auto&` reads each stored string without copying it or allowing changes.
    for (const auto& task : tasks) {
        if (task.size() > length) {
            ++matches;
        }
    }

    return matches;
}

// A value loop is useful when a separate copy is intentional.
// For example: `for (auto task : tasks)` gives `task` its own string copy;
// changing that local copy would not change the original element in `tasks`.
