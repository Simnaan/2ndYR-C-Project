#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>

class programme {
public:
	std::string programmeName;
	int programmeStartYear;
	int programmeEndYear;
	std::string courseName1;
	std::string courseName2;
	std::string researchProjectName;
	std::string levelOfStudy;
	int numOfAssessments1;
	int numOfAssessments2;
	std::string assessmentsName1[5];
	int assessmentsWeighting1[5];
	std::string assessmentsName2[5];
	int assessmentsWeighting2[5];
	std::string assessmentsDeadline1[5];
	std::string assessmentsDeadline2[5];


	void createProgramme() {
		std::cout << "Please enter the name of the programme: \n";
		std::cin >> programmeName;

		toUpperCase(programmeName);
		//programmeName is passed to this function to convert it to upper case

		std::cout << "Please enter when the programme starts: \n";
		std::cin >> programmeStartYear;

		std::cout << "Please enter when the programme will end: \n";
		std::cin >> programmeEndYear;

		bool valid = false;

		while (!valid)
		if (programmeStartYear > programmeEndYear) {
			std::cout << "The programme start year and end year are not valid.\n";

			std::cout << "Please enter when the programme starts: \n";
			std::cin >> programmeStartYear;

			std::cout << "Please enter when the programme will end: \n";
			std::cin >> programmeEndYear;

			if (programmeStartYear < programmeEndYear) {
				std::cout << "Programme Start year validated\n";
				valid = true;
			}
			else {
				valid = false;
			}

		}
		else
		{
			valid = true;
		}
		//This validates whether the start year is before the end year for the programme

		valid = false;
		while (!valid) {
			std::cout << "Please enter the level of Study: \n";
			std::cin >> levelOfStudy;
			toUpperCase(levelOfStudy);

			if ((levelOfStudy == "H") || (levelOfStudy == "I") || (levelOfStudy == "C")) {
				std::cout << "Level of study validated\n";
				valid = true;
			}
			else {
				std::cout << "This level of study does not exist, please enter a valid level of study: \n";
				valid = false;
			}
		}
			

		
		//This validates whether the level of study exists

		std::cout << "Please enter the name of your first course: \n";
		std::cin >> courseName1;
		toUpperCase(courseName1);

		std::cout << "Please enter the number of assessments for your first course: \n";
		std::cin >> numOfAssessments1;

		valid = false;
		while (!valid) {
			int totalweighting = 0;
			for (int i = 0; i < numOfAssessments1; i++) {

				std::cout << "Please enter the name of the assessment: \n";
				std::cin >> assessmentsName1[i];
				toUpperCase(assessmentsName1[i]);

				std::cout << "Please enter the deadline for the assessment, in the format DD/MM/YYYY: \n";
				std::cin >> assessmentsDeadline1[i];

				std::cout << "Please enter the weighting for " << assessmentsName1[i] << ": \n";
				std::cin >> assessmentsWeighting1[i];
				totalweighting = totalweighting + assessmentsWeighting1[i];
			}

			if (totalweighting != 100) {
				std::cout << "the weigthing for the assessments do not add up to 100. Please enter course details again. \n";
				totalweighting = 0;
				
			}
			else {
				valid = true;
				totalweighting = 0;
			}
		}
		//validates whether the total weighting adds up to 100

		std::cout << "Please enter the name of your second course: \n";
		std::cin >> courseName2;
		toUpperCase(courseName2);

		std::cout << "Please enter the number of assessments for your second course: \n";
		std::cin >> numOfAssessments2;

		valid = false;
		while (!valid) {
			int totalweighting = 0;
			for (int i = 0; i < numOfAssessments2; i++) {

				std::cout << "Please enter the name of the assessment: \n";
				std::cin >> assessmentsName2[i];
				toUpperCase(assessmentsName2[i]);

				std::cout << "Please enter the deadline for the assessment, in the format DD/MM/YYYY: \n";
				std::cin >> assessmentsDeadline2[i];
				
				std::cout << "Please enter the weighting for " << assessmentsName2[i] << ": \n";
				std::cin >> assessmentsWeighting2[i];
				totalweighting = totalweighting + assessmentsWeighting2[i];
			}

			if (totalweighting != 100) {
			std::cout << "the weigthing for the assessments do not add up to 100. Please enter course details again. \n";


			}
			else {
				valid = true;
			}
		}
		//validates whether the total weighting adds up to 100

		if (levelOfStudy=="H") {
			std::cout << "Please enter the name of your research project: \n";
			std::cin >> researchProjectName;
		}

		std::cout << "Programme Created\n";

	}

	void writeToFile(std::string programmeName,int programmeStartYear,int programmeEndYear,std::string courseName1,std::string courseName2,std::string researchProjectName,std::string levelOfStudy,int numOfAssessments1,int numOfAssessments2,std::string assessmentsName1[5],int assessmentsWeighting1[5],std::string assessmentsName2[5],
	int assessmentsWeighting2[5],std::string assessmentsDeadline1[5],std::string assessmentsDeadline2[5]) {

		std::string fileName = programmeName + ".txt";
		std:: ofstream myfile (fileName);
		
		myfile << programmeName<<","<< programmeStartYear << ","<< programmeEndYear<<","<< courseName1<<","<< courseName2<<","<< researchProjectName<<","<< levelOfStudy<<","<< numOfAssessments1<<","<< numOfAssessments2<<","<< assessmentsName1[0]<<","<< assessmentsName1[1] << "," << assessmentsName1[2] << "," << assessmentsName1[3] << "," << assessmentsName1[4] << "," << assessmentsName1[5] << "," << assessmentsWeighting1[0]<<","<< assessmentsWeighting1[1] << "," << assessmentsWeighting1[2] << "," << assessmentsWeighting1[3] << "," << assessmentsWeighting1[4] << "," << assessmentsWeighting1[5] << "," << assessmentsName2[0]<<","<< assessmentsName2[1] << "," << assessmentsName2[2] << "," << assessmentsName2[3] << "," << assessmentsName2[4] << "," << assessmentsName2[5] << "," << assessmentsWeighting2[0]<<","<< assessmentsWeighting2[1] << "," << assessmentsWeighting2[2] << "," << assessmentsWeighting2[3] << "," << assessmentsWeighting2[4] << "," << assessmentsWeighting2[5] << "," << assessmentsDeadline1[0]<<","<< assessmentsDeadline1[1] << "," << assessmentsDeadline1[2] << "," << assessmentsDeadline1[3] << "," << assessmentsDeadline1[4] << "," << assessmentsDeadline1[5] << "," << assessmentsDeadline2[0] <<","<< assessmentsDeadline2[1] << "," << assessmentsDeadline2[2] << "," << assessmentsDeadline2[3] << "," << assessmentsDeadline2[4] << "," << assessmentsDeadline2[5];
		myfile.close();
	}
	
	void toUpperCase(std::string& word) {
		std::for_each(word.begin(), word.end(), [](char& c) {
			c = ::toupper(c);
			});
		return;
	}
	//this function uses pass by refernece to convert the string passed to it, to upper case.
};

class student : public programme {
	
public:
	std::string id;
	std::string firstName;
	std::string surName;
	std::string assessments1;
	std::string assessments2;
	std::string assessments1mark;
	std::string assessments2mark;
	std::string y1Aggregate;
	std::string y2Aggregate;
	std::string y3Aggregate;
	std::string grade1;
	std::string grade2;
	std::string filler;
	std::string filler2;
	std::vector<student> allStudents;

	student() {
		id = "";
		firstName = "";
		surName = "";
		programmeName = "";
		levelOfStudy = "";
		courseName1 = "";
		courseName2 = "";
		assessments1 = "";
		assessments1mark = "";
		assessments2 = "";
		assessments2mark = "";
		y1Aggregate = "";
		y2Aggregate = "";
		y3Aggregate = "";
		grade1 = "";
		grade2 = "";

	}
	
	student(std::vector<std::string> studentData) {
		id = studentData[0];
		firstName = studentData[1];
		surName = studentData[2];
		programmeName = studentData[3];
		levelOfStudy = studentData[4];
		courseName1 = studentData[5];
		courseName2 = studentData[6];
		assessments1 = studentData[7];
		assessments1mark = studentData[8];
		assessments2 = studentData[9];
		assessments2mark = studentData[10];
		y1Aggregate = studentData[11];
		y2Aggregate = studentData[12];
		y3Aggregate = studentData[13];
		grade1 = "i";
		grade2 = "i";
	}

	void createStudent(std::string fileName) {

		std::string File = "C:\\Users\\Simnaan\\OneDrive\\Documents\\Computer Science Liverpool Hope\\OOSD\\OOSD-Coursework\\" + fileName + ".txt";
		//This formats the text file and adds on the correct directory for the file
		std::string line;
		std::vector<std::string> studentInfo;
		//this will store all the student info

		std::ifstream myFile(File);

		if (myFile.is_open())
		{
			while (getline(myFile, line))
			{
				if (line.size() > 0) {

					studentInfo.push_back(line);

					//then once first student object is created store in array of objects then move to next line of text file.
				}
			}
			myFile.close();
		}

		else {
			std::cout << "Unable to open file";
		}

			createStudent(studentInfo);
			//this vector is sent to the createStudent function and it will create objects of each student.
		}

		void createStudent(std::vector<std::string> studentInfo) {

			std::vector<std::string> studentData;
			std::string line;

			for (int i = 1; i < studentInfo.size(); i++) {

				std::stringstream temp (studentInfo[i]);
				  
				while (getline(temp,line,','))
				{
					studentData.push_back(line);
				}
				//each line stored in the StudentInfo vector is taken and split after every "," and store in the studentData vector

				student Estudent(studentData);
				//once first element of studentInfo is split full and stored in studentData, it is passed to constructor to create object of that student
				allStudents.push_back(Estudent);
				//object of student is stored in allStudents which is a vector of objects
				
				studentData.clear();

			}
		
		}
		//overloaded function


		void changeCourse(std::string programmeName) {

			for (int i = 0; i < allStudents.size(); i++) {
				allStudents[i].programmeName = programmeName;
			}
		}

		void getTranscriptOne(std::string student) {

			if (allStudents.size() == 0) {
				std::cout << "You have not loaded any students, please load students first.\n";
			}
			else {
				for (int i = 0; i < allStudents.size(); i++) {
					if (allStudents[i].id == student) {

						std::cout << allStudents[i].id + "\n";
						std::cout << allStudents[i].firstName + "\n";
						std::cout << allStudents[i].surName + "\n";
						std::cout << allStudents[i].programmeName + "\n";
						std::cout << allStudents[i].courseName1 + "\n";
						std::cout << allStudents[i].courseName2 + "\n";
						std::cout << allStudents[i].levelOfStudy + "\n";
						std::cout << allStudents[i].assessments1 + "\n";
						std::cout << allStudents[i].assessments1mark + "\n";
						std::cout << allStudents[i].assessments2 + "\n";
						std::cout << allStudents[i].assessments2mark + "\n";
						std::cout << allStudents[i].y1Aggregate + "\n";
						std::cout << allStudents[i].y2Aggregate + "\n";
						std::cout << allStudents[i].y3Aggregate + "\n";
						std::cout << allStudents[i].grade1 + "\n";
						std::cout << allStudents[i].grade2 + "\n";
					}
				}
			}
		}
};

