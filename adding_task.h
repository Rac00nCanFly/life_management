//
// Created by Ola on 08.03.2025.
//

#ifndef ADDING_TASK_H
#define ADDING_TASK_H
#include <iostream>
#include <chrono>
//class dealing with date
class Date {
    int year_;
    int month_;
    int day_;
    int hour_;
    public:
    Date(int year, int month, int day, int hour):year_(year), month_(month), day_(day), hour_(hour) { }
    int static get_current_year() {
        using namespace std::chrono;
        return static_cast<int>(
        year_month_day{time_point_cast<days>(system_clock::now())}.year());
    }
    int getYear() const {
        return year_;
    }
    void set_year(int year) {
        while (year < get_current_year()) {
            std::cout<<"Ups year must be greater or equal to current year. Please enter correct year"<<std::endl;
            std::cin>>year;
        }
        year_ = year;
    }

};
//creating class fo0r adding tasks
// class AddingTask {
//     public:
//     char name[];
//
// };
#endif //ADDING_TASK_H
