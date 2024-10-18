#include <iostream>
#include <string>
using namespace std;

// global variable, used const to define and initialize together
const int MAX_TASKS = 100;

struct Task
{
    // description for task
    string desc;
    // tells the tasks is completed or not
    bool completed;
};

// display menu or starting screen
void displayMenu()
{
    cout << "\n--- To-Do List Menu ---" << endl;
    cout << "1. View To-Do List" << endl;
    cout << "2. Add a Task" << endl;
    cout << "3. Mark a Task as Completed" << endl;
    cout << "4. Delete a Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

// to view task
void viewTasks(Task all_tasks[], int taskCount)
{
    if (taskCount == 0)
    {
        cout << "Your To-Do List is empty!" << endl;
    }
    else
    {
        cout << "\nYour To-Do List:" << endl;
        for (int i = 0; i < taskCount; ++i)
        {
            cout << i + 1 << ". " << (all_tasks[i].completed ? "[Completed] " : "[Pending] ") << all_tasks[i].desc << endl;
        }
    }
}

// add a task
void addTask(Task all_tasks[], int &taskCount)
{
    if (taskCount >= MAX_TASKS)
    {
        cout << "Your To-Do List is full. Cannot add more tasks." << endl;
        // will return because can't add another task now.
        return;
    }
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, all_tasks[taskCount].desc);
    // new task should be marked as incompleted
    all_tasks[taskCount].completed = false;
    taskCount++;
    cout << "Task added Successfully!" << endl;
}

// to mark a task completed
void markTaskCompleted(Task all_tasks[], int taskCount)
{
    viewTasks(all_tasks, taskCount);
    if (taskCount == 0)
        return;

    cout << "Enter the task number to mark task as completed: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= taskCount)
    {
        all_tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    }
    else
    {
        cout << "Invalid! Please Enter a valid task number!" << endl;
    }
}

// delete a task
void deleteTask(Task all_tasks[], int &taskCount)
{
    viewTasks(all_tasks, taskCount);
    if (taskCount == 0)
        return;

    cout << "Enter the task number to delete: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= taskCount)
    {
        // we will shift task by one position so that the task will overwrite and the all_tasks[tasknumber] will be deleted
        for (int i = taskNumber - 1; i < taskCount - 1; ++i)
        {
            all_tasks[i] = all_tasks[i + 1];
        }
        // reduce the task by 1 count because one task is deleted now
        taskCount--;
        cout << "Task Successfully deleted!" << endl;
    }
    else
    {
        cout << "Invalid! Please Enter a valid task number!" << endl;
    }
}

int main()
{
    // array to store tasks
    Task all_tasks[MAX_TASKS];
    // current number of tasks
    int taskCount = 0;
    int i = 0;

    while (true)
    {
        displayMenu();
        int user_choice;
        cin >> user_choice;

        switch (user_choice)
        {
        case 1:
            viewTasks(all_tasks, taskCount);
            break;
        case 2:
            addTask(all_tasks, taskCount);
            break;
        case 3:
            markTaskCompleted(all_tasks, taskCount);
            break;
        case 4:
            deleteTask(all_tasks, taskCount);
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}
