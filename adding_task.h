//
// Created by Ola on 08.03.2025.
//

#ifndef ADDING_TASK_H
#define ADDING_TASK_H
#include <iostream>
#include <chrono>
/*
 TO DO:
 - dodać sprawdzenie czy wprowadzony miesiąc/dzień nie jest z przeszłości
 - stworzyć tablicę albo stringa przechowującego completion_date
 - dodać atrybuty do klasy zadanie
 */
//class dealing with date
class Date {
    int year_{};
    int month_{};
    int day_{};
    int hour_{};
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
            std::cout<<"Oops year must be greater or equal to current year. Please enter correct year"<<std::endl;
            std::cin>>year;
        }
        year_ = year;
    }
    int get_month() const {
        return month_;
    }
    void set_month(int month) {
        while (month > 13 || month < 1) {
            std::cout<<"Oops you must enter number of month between 1-12. Please enter correct month"<<std::endl;
            std::cin>>month;
        }
        month_ = month;
    }
    int get_day() const {
        return day_;
    }
    void set_day(int day) {
        while (day > 31 || day < 1) {
            std::cout<<"Oops you must enter day between 1-31. Please enter correct day"<<std::endl;
            std::cin>>day;
        }
        day_ = day;
    }
    int get_hour() const {
        return hour_;
    }
    void set_hour(int hour) {
        while (hour > 23 || hour < 1) {
            std::cout<<"Oops, you must enter hour between 1-24. Please enter correct hour";
            std::cin>>hour;
        }
        hour_ = hour;
    }
    //c-tor only for testing
    Date()= default;
};
//creating class for categories of tasks
class Categories {
protected:
    std::string category_name_;
    Categories(const std::string& category_name): category_name_{category_name} {}
    std::string get_category() const {
        return category_name_;
    }
};
//creating class for adding tasks
 class Task : protected Categories {
     std::string task_name_;
     Date completion_date_;
     enum Priority {
         It_can_wait = 0,
         Must_be_done_this_month,
         Must_be_done_within_few_days,
         Must_be_done_today,
     };
     Priority priority_;
     Categories category;
     public:
     // Task(const std::string& task_name,Date completion_date, Priority priority, Categories category_name):
     //     task_name_(task_name),
     //     completion_date_(completion_date),
     //     priority_(priority) {
     // }
 };
#endif //ADDING_TASK_H
