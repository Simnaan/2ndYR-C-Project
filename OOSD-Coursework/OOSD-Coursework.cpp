#include <iostream>
#include <string>
#include <algorithm>
#include "Classes.cpp"
#include <fstream>
#include <vector>
#include <sstream>

programme myProgramme;
student myStudents;

void toUpperCase(std::string &word) {

    std::for_each(word.begin(), word.end(), [](char& c) {
        c = ::toupper(c);
        });
    return;
}
//this function uses pass by refernece to convert the string passed to it, to upper case.

void createProgramme() {
   
    myProgramme.createProgramme();

    std::cout << myProgramme.assessmentsName1;

    //code that will check if the course already exists

}

void enrolOnToFile() {


    std::string fileName;
    std::string programmeName;

    std::cout << "please enter the name of the text file.\n";
    std::cin >> fileName;
    std::cout << "please enter the name of the course you want to register the students on to.\n";
    std::cin >> programmeName;

    myStudents.createStudent(fileName);
    //This reads all the students from the file and creates an objct for each student and then stores each student in a vector of objects
    myStudents.changeCourse(programmeName);
    std::cout << "Students Course Changed\n";
}

    void viewTranscript() {
        std::stringstream ss;
        std::stringstream ss1;
        std::string student;
        int mark1;
        int mark2;

        std::cout << "Enter the ID of the student you want to view a transcipt of\n";
        std::cin >> student;

       

        for (int i = 0; i < myStudents.allStudents.size(); i++) {
            if (myStudents.allStudents[i].id == student) {

                ss << myStudents.allStudents[i].assessments1mark;
                ss >> mark1;
                //assessmentmark1 is stored as a string
                //here i am converting the string a integer so that i can compare it to numbers

                ss1 << myStudents.allStudents[i].assessments2mark;
                ss1 >> mark2;

                if ((40 < mark1) && (mark1 < 44))
                {
                    myStudents.allStudents[i].grade1 = "E";
                }
                else if ((45 < mark1) && (mark1 < 49))
                {
                    myStudents.allStudents[i].grade1 = "D";
                }
                else if ((50 < mark1) && (mark1 < 54))
                {
                    myStudents.allStudents[i].grade1 = "C";
                }
                else if ((55 < mark1) && (mark1 < 59))
                {
                    myStudents.allStudents[i].grade1 = "C+";
                }
                else if ((60 < mark1) && (mark1 < 64))
                {
                    myStudents.allStudents[i].grade1 = "B";
                }
                else if ((65 < mark1) && (mark1 < 69))
                {
                    myStudents.allStudents[i].grade1 = "B+";
                }
                else if ((70 < mark1) && (mark1 < 85))
                {
                    myStudents.allStudents[i].grade1 = "A";
                }
                else if ((86 < mark1) && (mark1 <= 100))
                {
                    myStudents.allStudents[i].grade1 = "A+";
                }

                if ((40 < mark2) && (mark2 < 44))
                {
                    myStudents.allStudents[i].grade2 = "E";
                }
                else if ((45 < mark2) && (mark2 < 49))
                {
                    myStudents.allStudents[i].grade2 = "D";
                }
                else if ((50 < mark2) && (mark2 < 54))
                {
                    myStudents.allStudents[i].grade2 = "C";
                }
                else if ((55 < mark2) && (mark2 < 59))
                {
                    myStudents.allStudents[i].grade2 = "C+";
                }
                else if ((60 < mark2) && (mark2 < 64))
                {
                    myStudents.allStudents[i].grade2 = "B";
                }
                else if ((65 < mark2) && (mark2 < 69))
                {
                    myStudents.allStudents[i].grade2 = "B+";
                }
                else if ((70 < mark2) && (mark2 < 85))
                {
                    myStudents.allStudents[i].grade2 = "A";
                }
                else if((86 < mark2) && (mark2 <= 100))
                {
                    myStudents.allStudents[i].grade2 = "A+";
                }
            }
        }
        //this code checks which grade boundary the students mark falls between and assigns the student he corresponding grade.

        myStudents.getTranscriptOne(student);
        //student ID is passed to getTranscriptOne and the transcript for the student is outputted.
    }

    void editMark() {

        std::string student;
        std::string course;

        std::cout << "Enter the ID of the student you want to edit the mark of\n";
        std::cin >> student;
      
        std::cout << "Enter course 1 or 2\n";
        std::cin >> course;
        if (course == "1") {

            std::string  mark;
            std::cout<<"enter the new mark\n";
            std::cin >> mark;

            for (int i = 0; i < myStudents.allStudents.size(); i++) {
                if (myStudents.allStudents[i].id == student) {
                    myStudents.allStudents[i].assessments1mark = mark;

                }
            }
            
        }
        else if (course == "2") {

            std::string  mark;
            std::cout << "enter the new mark\n";
            std::cin >> mark;

            for (int i = 0; i < myStudents.allStudents.size(); i++) {
                if (myStudents.allStudents[i].id == student) {
                    myStudents.allStudents[i].assessments2mark = mark;
                    std::cout << myStudents.allStudents[i].assessments2mark;

                }
            }

        }
        else {
            std::cout << "invalid course\n";
            editMark();
        }

    }

    void injectFile() {
        std::string fileName;
        std::cout << "please enter the name of the text file.\n";
        std::cin >> fileName;

        myStudents.createStudent(fileName);
        //filename is passed to createstudent function and then objects of the student are created and stored.
        std::cout << "File Injected\n";
    }

int main()
{
    //
    //
    //
    // FILE FORMAT MUST BE LIKE TESTDATA.TXT THAT IS INCLUDED IN FOLDER
    //
    //
    //

    int option = 0;

    std::cout << "\nHello, Welcome to the Student Transcript and progression/Award Application.\n";
    std::cout << "If you would like to create a programme, please type 1:\n";
    std::cout << "If you would like to enrol students onto a course from a file, please type 2:\n";
    std::cout << "If you would like to view a transcript for a given student, please type 3.\n";
    std::cout << "If you would like to edit the mark for a given student, please type 4.\n";
    std::cin >> option;
    //the user is asked which option they would like to choose and theyre input is stored into option

    switch (option) {
    //the variable option is evaluated
    case 0:
        std::cout << "You have selected to inject a text file\n";
        injectFile();
        break;
        //if option=1 then the user has selected to inject a student
    case 1:
        std::cout << "You have selected to create a programme.\n";
        createProgramme();
        break;
    //if option=1 then the user has selected to enrol on to a course
    case 2:
        std::cout << "You have selected to enrol students on to a course using a file.\n";
        enrolOnToFile();
        //call enrolOnToFile function
        break;
        //if option=2 then user has selected to enrol students on to a course using a file
    case 3:
        std::cout << "You have selected to view a transcript.\n";
        viewTranscript();
        //call view Transcript function
        break;
    //if option=3 then user has selected to view a transcript
    case 4:
        std::cout << "You have selected to edit a student mark.\n";
        editMark();
        //call editMark function
        break;
        //if option=4 then user has selected to edit a students mark
    default:
        std::cout << "That is not an option. Please select a valid option.\n\n";
        main();
        break;
    //if the user has typed in a invalid input, then the user is returned the to start of the main fuction and is asked to select and option again.
    }

    main();

}

