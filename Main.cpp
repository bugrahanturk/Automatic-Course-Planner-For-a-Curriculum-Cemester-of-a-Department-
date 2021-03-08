#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "Course.hpp"
#include "Classes.hpp"
#include "Schedule.hpp"
#include <vector>
#include "BigClass.hpp"

//std::fstream.getline();

int main() {

   Schedule mySchedule = Schedule();
   vector<Course *> myCourses;
   try {

       myCourses = Course::readCoursesFile("C:\\Users\\Salim\\Desktop\\CENG206 Project II\\sample_files\\courses.csv");
   }
   catch (int e) {
       cout << "Proper Courses file is not found! " << endl;
       return -1;
   }

   Course::displayVec(myCourses);
   cout << "\n\n";

   try {
       mySchedule.myClasses = Classes::readClassesFile("C:\\Users\\Salim\\Desktop\\CENG206 Project II\\sample_files\\classroom.csv");
   }
   catch (...) {
       cout << "Proper Classes file is not found! " << endl;
       return -1;
   }
 
   bool cont;
   try {
       cont = mySchedule.takeService(myCourses, "C:\\Users\\Salim\\Desktop\\CENG206 Project II\\sample_files\\service.csv");
       if (!cont) {
           cout << "There is no way to make a perfect schedule for the department.";
           return 0;
       }
   }
   catch (int e) {
       cout << "services not found";
   }
   
   cont = mySchedule.takeBusy(myCourses, "C:\\Users\\Salim\\Desktop\\CENG206 Project II\\sample_files\\busy.csv");
   if (!cont) {
       cout << "There is no way to make a perfect schedule for the department.";
       return 0;
   }
   cont = mySchedule.putRest(myCourses);
   if (!cont) {
       cout << "There is no way to make a perfect schedule for the department.";
       return 0;
   }


   mySchedule.displayCourses();


   

    return 0;
}
