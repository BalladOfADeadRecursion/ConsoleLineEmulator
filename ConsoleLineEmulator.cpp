#include <iostream>
#include <string>
using namespace std;

enum Command {
    HELP,
    EXIT,
    CD,
    LS,
    MKDIR,
    RMDIR,
    TOUCH,
    CAT,
    NANO,
    RM,
    PING,
    UNAME,
    UPTIME,
    WHOAMI,
    DATE,
    HISTORY,
    CLEAR,
    UNKNOWN
};

Command getCommandEnum(const string& command) 
{
    if (command == "help") {
        return HELP;
    }
    else if (command == "exit") {
        return EXIT;
    }
    else if (command == "exit") {
        return CD;
    }
    else if (command == "exit") {
        return LS;
    }
    else if (command == "exit") {
        return MKDIR;
    }
    else if (command == "exit") {
        return RMDIR;
    }
    else if (command == "exit") {
        return CAT;
    }
    else if (command == "exit") {
        return TOUCH;
    }
    else if (command == "exit") {
        return NANO;
    }
    else if (command == "exit") {
        return RM;
    }
    else if (command == "exit") {
        return PING;
    }
    else if (command == "exit") {
        return UNAME;
    }
    else if (command == "exit") {
        return UPTIME;
    }
    else if (command == "exit") {
        return WHOAMI;
    }
    else if (command == "exit") {
        return DATE;
    }
    else if (command == "exit") {
        return HISTORY;
    }
    else if (command == "exit") {
        return CLEAR;
    }
    else {
        return UNKNOWN;
    }
}

int main() {
    setlocale(LC_ALL, "Rus"); // Set locale for Russian if needed
    string command;

    while (true) {
        cout << "\nEnter a command: " << endl;
        cin >> command;

        // Get the corresponding command enum
        Command cmd = getCommandEnum(command);

        // Use switch based on the enum value
        switch (cmd) {
        case HELP:
            cout << "List of commands used:" << endl;
            cout << endl;
            cout << "help    — вызов списка доступных комманд." << endl;
            cout << "cd      — изменение текущей рабочей директории." << endl;
            cout << "ls      — список файлов и директорий в текущей директории." << endl;
            cout << "mkdir   — создание новой папки." << endl;
            cout << "rmdir   — удаление пустой папки." << endl;
            cout << "touch   — создание пустого файла" << endl;
            cout << "cat     — отображение содержимого текстового файла" << endl;
            cout << "nano    — команды для редактирования текстовых файлов." << endl;
            cout << "rm      — удаление файлов" << endl;
            cout << "ping    — проверка доступности хоста по сети" << endl;
            cout << "uname   — информация о системе (например, о типе ОС)" << endl;
            cout << "uptime  — информация о времени работы системы." << endl;
            cout << "whoami  — вывод имени текущего пользователя" << endl;
            cout << "date    — вывод текущей даты и времени." << endl;
            cout << "history — просмотр истории выполненных команд." << endl;
            cout << "clear   — очистка консоли." << endl;
            cout << "exit    — выход из консоли." << endl;
            break;

        case CD:
            break;

        case LS:
            break;

        case MKDIR:
            break;

        case RMDIR:
            break;

        case CAT:
            break;

        case TOUCH:
            break;

        case NANO:
            break;

        case RM:
            break;

        case PING:
            break;

        case UNAME:
            break;

        case UPTIME:
            break;

        case WHOAMI:
            break;

        case DATE:
            break;

        case HISTORY:
            break;

        case CLEAR:
            break;
        
        case EXIT:
            return 0; 

        default:
            cout << "Unknown command" << endl;
            break;
        }
    }
}



