#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    int id;         // Tarea
    int benefit;    // Beneficio
    int deadline;   // plazo lim
};

bool compareTasks(const Task& task1, const Task& task2) {
    return task1.benefit > task2.benefit;
}

std::vector<Task> selectTasks(std::vector<Task>& tasks) {
    // ordenar el arreglo
    std::sort(tasks.begin(), tasks.end(), compareTasks);

    std::vector<Task> selectedTasks;
    std::vector<bool> slotAvailable(tasks.size(), true);

    for (const auto& task : tasks) {
        for (int i = std::min(static_cast<int>(tasks.size()), task.deadline) - 1; i >= 0; --i) {
            if (slotAvailable[i]) {
                selectedTasks.push_back(task);
                slotAvailable[i] = false;
                break;
            }
        }
    }

    return selectedTasks;
}

int main() {
    std::vector<Task> tasks = {
        {1, 50, 2},
        {2, 10, 1},
        {3, 15, 2},
        {4, 30, 1}
    };

    std::vector<Task> selectedTasks = selectTasks(tasks);

    std::cout << "Selected tasks: ";
    int benefit = 0;
    for (const auto& task : selectedTasks) {
        benefit += task.benefit;
        std::cout << task.id << " ";
    }
    std::cout << std::endl;
    std::cout << "Benefit: " << benefit << std::endl;
    std::cout << std::endl;

    return 0;
}
