#include "data.h"

Data::Data()
{
    ifstream stu("students.csv");
    ifstream teac("teachers.csv");
    ifstream cour("courses.csv");
    ifstream ass("assignments.csv");

    int sID;
    vector<Course*> sCourses;
    string cName;
    int cID;
    double gpa_;
    string password;
    string nombre;

    int index = 0;
    string line;
    while (getline(stu, line)) {

        stringstream ss(line);
        string split;

        getline(ss, split, ',');
        sID = stoi(split);

        getline(ss, split, ',');
        cName = split;
        getline(ss, split, ',');
        cID = stoi(split);
        sCourses.push_back(new Course(cName,cID));



        getline(ss, split, ',');
        gpa_ = stod(split);

        getline(ss, password, ',');


        students.push_back(new Student(sID, sCourses, gpa_, password, nombre));
        students[index]->addClass(new Course(cName,cID));

    }

    stu.close();

    string line2;
    string cName2;
    int cID2;
    while (getline(cour,line2)) {

        stringstream ss(line2);
        string split;

        getline(ss, split, ',');
        cName2 = split;
        getline(ss, split, ',');
        cID2 = stoi(split);
        courses.push_back(new Course(cName2,cID2));

    }

    string line3;
    string cName3;
    string assName;
    int score;
    int sID2;

    while(getline(ass,line3)) {

        stringstream ss(line3);
        string split;

        getline(ss,split, ',');
        cName3 = split;
        for (int i = 0; i < courses.size(); i++) {
            for(int j = 0; j < students.size(); j++) {

                if (courses[i]->getClassName() == cName3) {

                    if (students[j]->inClass(courses[i])) {

                        getline(ss,split, ',');
                        assName = split;
                        Assignment* a = new Assignment(assName, 100);
                        getline(ss,split, ',');
                        score = stoi(split);
                        a->inputScore(students[j],score);

                    }

                }



            }


        }


    }





}
