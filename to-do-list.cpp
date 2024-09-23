#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);
    tasks.push_back({description, false});
    cout << "Task added successfully.\n";
}

void viewTasks() {
    cout << "Your tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " (completed)";
        }
        cout << endl;
    }
}

void markTaskAsCompleted() {
    int index;
    cout << "Enter the index of the task to mark as completed: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid index.\n";
    }
}

void removeTask() {
    int index;
    cout << "Enter the index of the task to remove: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed.\n";
    } else {
        cout << "Invalid index.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Mark task as completed\n";
        cout << "4. Remove task\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
