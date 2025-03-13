#include <iostream>
#include <C:\Users\Ola\CLionProjects\life_management\adding_task.h>
int main() {
    Date new_task;
    int year;
    //testing year
     std::cout << "Enter Your Year: ";
     std::cin >> year;
     new_task.set_year(year);
     std::cout << new_task.getYear();
    return 0;
}