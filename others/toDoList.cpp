#include<iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>

using std::cout, std::cin, std::endl, std::vector, std::string;

void clearScreen();

    class Tasks{
    private:
        string id;
        string name;
        string description;
        string dueDate;
        bool completeStatus;

    public:
        Tasks(string id, string name, string description, string dueDate, bool completeStatus)
        {
            this->id = id;
            this->name = name;
            this->description = description;
            this->dueDate = dueDate;
            this->completeStatus = completeStatus;
        }

        string getID()
        {
            return id;
        }
        void setID(string id)
        {
            this->id = id;
        }

        string getName()
        {
            return name;
        }
        void setName(string name)
        {
            this->name = name;
        }

        string getDescription()
        {
            return description;
        }
        void setDescription(string description)
        {
            this->description = description;
        }

        string getDueDate()
        {
            return dueDate;
        }
        void setDueDate(string dueDate)
        {
            this->dueDate = dueDate;
        }

        bool getCompleteStatus()
        {
            return completeStatus;
        }
        void setCompleteStatus(bool status)
        {
            this->completeStatus = status;
        }

        void markDone()
        {
            completeStatus = true;
        }

        void displayTasks()
        {
            cout << (completeStatus ? "[COMPLETED] " : "[PENDING] ");
            cout << name << " (";
            cout << description << ")" << endl;
            cout << "Due Date: " << dueDate;
        }
    };

    class toDoList{
    private:
        vector<Tasks> tasks;

    public:
        void menu()
        {
            cout << "============================" << endl;
            cout << "|        To-Do list        |" << endl;
            cout << "============================" << endl;
            cout << "1. Add a task" << endl;
            cout << "2. Delete a task" << endl;
            cout << "3. Edit a task" << endl;
            cout << "4. Display all tasks" << endl;
            cout << "5. Mark a task" << endl;
            cout << "6. Exit" << endl;
        }

        void addTask()
        {
            clearScreen();

            string id, name, description, dueDate;
            cin.ignore(); // clear leftover newline in the input buffer

            cout << "Task number: ";
            getline(cin, id);

            cout << "Task name: ";
            getline(cin, name);

            cout << "Task's description: ";
            getline(cin, description);

            cout << "Task's due date (DD-MM-YYYY): ";
            getline(cin, dueDate);

            tasks.emplace_back(id, name, description, dueDate, false); // add a task to the vector
            std::this_thread::sleep_for(std::chrono::seconds(2));
            cout << "!!! Task added successfully !!!" << endl;

        }

        void deleteTask()
        {
            clearScreen();

            if(tasks.empty())
            {
                cout << "No tasks to delete" << endl;
            }
            
            cout << "Current task(s): " << endl;
            for(int i = 0; i < tasks.size(); i++)
            {
                cout << i + 1 << ". " << tasks[i].getName() << endl;
            }

            cout << "Enter the task's number to delete: ";
            int taskChoice;
            cin >> taskChoice;
            if(taskChoice >= 1 && taskChoice <= tasks.size()) // correcting the user's choice
            {
                tasks.erase(tasks.begin() + taskChoice - 1);
                std::this_thread::sleep_for(std::chrono::seconds(2));
                cout << "Task deleted successfully" << endl;
            }
            else
            {
                cout << "Task's number does not exist" << endl;
            }
        }

        void displayTasks()
        {
            clearScreen();

            if(tasks.empty())
            {
                cout << "No task(s) to display" << endl;
            }

            cout << "Task(s): " << endl;
            for(int i = 0; i < tasks.size(); i++)
            {
                cout << i + 1 << ". "; 
                tasks[i].displayTasks();
                cout << endl;
            }
        }

        void markCompleted()
        {
            clearScreen();

            if(tasks.empty())
            {
                cout << "No task(s) to mark as completed" << endl;
            }

            for(int i = 0; i < tasks.size(); i++)
            {
                cout << i + 1 << ". " << tasks[i].getName() << endl;
            }
            cout << "Enter the task's number to mark: ";
            int taskNumber;
            cin >> taskNumber;
            if(taskNumber >= 1 && taskNumber <= tasks.size())
            {
                tasks[taskNumber - 1].markDone();
                std::this_thread::sleep_for(std::chrono::seconds(2));
                cout << "!!! Task marked as completed !!!" << endl;
            }
            else
            {
                cout << "Task's number does not exist" << endl;
            }
        }

        void editTask()
        {
            clearScreen();
            cin.ignore();

            if(tasks.empty())
            {
                cout << "No task(s) to edit" << endl;
            }

            for(int i = 0; i < tasks.size(); i++)
            {
                cout << i + 1 << ". " << tasks[i].getName() << endl;
            }
            cout << "Enter the task's number to edit: ";
            int taskNumber;
            cin >> taskNumber;
            if(taskNumber >= 1 && taskNumber <= tasks.size())
            {
                Tasks& task = tasks[taskNumber - 1]; // correcting the user's` input
                string id, name, description, dueDate;
                cin.ignore();

                cout << "Enter a new task's ID: ";
                getline(cin, id);

                cout << "Enter a new task's name: ";
                getline(cin, name);

                cout << "Enter a new task's description: ";
                getline(cin, description);

                cout << "Enter a new task's due date: ";
                getline(cin, dueDate);

                task.setID(id); // update id                    
                task.setName(name); // update name
                task.setDescription(description); // update description
                task.setDueDate(dueDate); // update due date
                
                std::this_thread::sleep_for(std::chrono::seconds(2));
                cout << "!!! Task update successfully !!!" << endl;
            }
            else
            {
                cout << "Task's number does not exist" << endl;
            }
        }

        void run()
        {
            int choice;
            do
            {
                menu();
                cout << "Enter your choice: ";
                cin >> choice;

                switch(choice)
                {
                    case 1:
                        addTask();
                        break;
                    case 2:
                        deleteTask();
                        break;
                    case 3:
                        editTask();
                        break;
                    case 4:
                        displayTasks();
                        break;
                    case 5:
                        markCompleted();
                        break;
                    case 6:
                        cout << "bye bye" << endl;
                        break;
                    default:
                        cout << "Invalid choice, try again" << endl;
                }
            } while (choice != 6);
        }
    };

    int main(){
        toDoList toDoList;
        toDoList.run();

        return 0;
    }

    void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}