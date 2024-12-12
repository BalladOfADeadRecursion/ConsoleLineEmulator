#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <cstdlib>
using namespace std;
namespace fs = std::filesystem; // Для работы с файловой системой

enum Command {
    HELP, EXIT, CD, LS,
    MKDIR, RMDIR, TOUCH, CAT,
    PING, UNAME, UPTIME, WHOAMI, 
    DATE, HISTORY, CLEAR, UNKNOWN, COMMAND
};

Command getCommandEnum(const string& command)
{
    if (command == "help") return HELP;
    else if (command == "exit") return EXIT;
    else if (command == "cd") return CD;
    else if (command == "ls") return LS;
    else if (command == "mkdir") return MKDIR;
    else if (command == "rmdir") return RMDIR;
    else if (command == "cat") return CAT;
    else if (command == "touch") return TOUCH;
    else if (command == "ping") return PING;
    else if (command == "uname") return UNAME;
    else if (command == "uptime") return UPTIME;
    else if (command == "whoami") return WHOAMI;
    else if (command == "date") return DATE;
    else if (command == "history") return HISTORY;
    else if (command == "clear") return CLEAR;
    else if (command == "command") return COMMAND;
    else return UNKNOWN;
}

void changeDirectory(const string& path) {
    if (fs::exists(path) && fs::is_directory(path))
    {
        fs::current_path(path);
        cout << "Директория изменена на: " << fs::current_path() << endl;
    }
    else
    {
        cout << "Ошибка, указанная директория не существует. " << endl;
    }
}

void logCommand(const string& command) {
    ofstream historyFile("history.txt", ios::app); // Открываем файл для записи в конец
    if (historyFile) {
        historyFile << command << endl; // Записываем команду в файл
    }
    else {
        cout << "Ошибка при записи в файл истории." << endl;
    }
}

void ShowHistory()
{
    ifstream history_file("history.txt");
    if (history_file)
    {
        string hline;
        cout << endl;
        cout << "История команд: " << endl;
        while (getline(history_file, hline))
        {
            cout << hline << endl;
        }
    }
    else
    {
        cout << "История комманд пуста или не найдена. " << endl;
    }
}


int main() {
    setlocale(LC_ALL, "Rus"); 
    string command;

    while (true) {
        cout << "\nEnter a command: " << endl;
        cin >> command;
        logCommand(command);
        Command cmd = getCommandEnum(command);

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
            cout << "ping    — проверка доступности хоста по сети" << endl;
            cout << "uname   — информация о системе (например, о типе ОС)" << endl;
            cout << "uptime  — информация о времени работы системы." << endl;
            cout << "whoami  — вывод имени текущего пользователя" << endl;
            cout << "date    — вывод текущей даты и времени." << endl;
            cout << "history — просмотр истории выполненных команд." << endl;
            cout << "clear   — очистка консоли." << endl;
            cout << "command — пример использования команд." << endl;
            cout << "exit    — выход из консоли." << endl;
            break;

        case COMMAND:
            cout << "List of command usage examples:" << endl;
            cout << endl;
            cout << "help    - help" << endl;
            cout << "cd      — cd /home/user/documents" << endl;
            cout << "ls      — ls" << endl;
            cout << "mkdir   — mkdir new_folder" << endl;
            cout << "rmdir   — rmdir old_folder" << endl;
            cout << "touch   — touch file.txt" << endl;
            cout << "cat     — cat file.txt" << endl;
            cout << "nano    — nano file.txt" << endl;
            cout << "rm      — rm file.txt" << endl;
            cout << "ping    — ping google.com" << endl;
            cout << "uname   — uname" << endl;
            cout << "uptime  — uptime" << endl;
            cout << "whoami  — whoami" << endl;
            cout << "date    — date" << endl;
            cout << "history — history" << endl;
            cout << "clear   — clear" << endl;
            cout << "command — command" << endl;
            cout << "exit    — exit" << endl;
            break;

        case CD:
        {
            string path;
            cout << "Введите путь к директории: ";
            cin >> path;
            changeDirectory(path);
            break;
        }

        case LS:
            system("dir");
            break;

        case MKDIR:
        {
            string new_folder_name;  
            cout << "Введите название новой директории: ";
            cin >> new_folder_name;
            if (fs::create_directory(new_folder_name))
            {
                cout << "Папка " << new_folder_name << " создана." << endl;
            }
            else
            {
                cout << "Ошибка при создании папки" << endl;
            }
            break;
        }

        case RMDIR:
        {
            string folder_to_remove; 
            cout << "Введите название директории для удаления: ";
            cin >> folder_to_remove;
            if (fs::remove_all(folder_to_remove) > 0)
            {
                cout << "Папка " << folder_to_remove << " удалена." << endl;
            }
            else
            {
                cout << "Ошибка при удалении папки" << endl;
            }
            break;
        }

        case TOUCH:
        {
            string new_file_name;  
            cout << "Введите название нового файла: ";
            cin >> new_file_name;
            ofstream file(new_file_name);
            if (file)
            {
                cout << "Файл " << new_file_name << " создан." << endl;
            }
            else
            {
                cout << "Ошибка при создании файла. " << endl;
            }
            break;
        }

        case CAT:
        {
            string file_to_display;  
            cout << "Введите название файла для отображения содержимого: ";
            cin >> file_to_display;
            cin.ignore();
            ifstream file(file_to_display);
            if (file)
            {
                cout << "Содержимое " << file_to_display << ": " << endl;
                string line;
                while (getline(file, line))  
                {
                    cout << line << endl;
                }
            }
            else
            {
                cout << "Ошибка при открытии файла " << endl;
            }
            break;
        }

        case PING:
        {
            string host;
            cout << "Введите хост для пинга: ";
            cin >> host;
            string command = "ping " + host;
            system(command.c_str());
            break;
        }

        case UPTIME:
            system("systeminfo | findstr /C:\"System Boot Time\""); // Показать время работы системы
            break;

        case UNAME:
            system("systeminfo | findstr /B /C:\"OS\" /C:\"Architecture\""); // Показать информацию о системе
            break;

        case WHOAMI:
            system("whoami");
            break;

        case DATE:
            system("date");
            break;

        case HISTORY:
            ShowHistory();
            break;

        case CLEAR:
            system("cls");
            break;

        case EXIT:
            cout << "Exiting the program..." << endl;
            return 0; 

        default:
            cout << "Unknown command" << endl;
            break;
        }
    }
}
