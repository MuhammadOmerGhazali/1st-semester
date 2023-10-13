#include <iostream>

using namespace std ;

float calculateAverage(float marksEnglish, float marksMaths, float marksChemistry, float marksSocialScience, float marksBiology);
string calculateGrade(float average);

int main()
{
    float marksEnglish,marksMaths,marksChemistry,marksSocialScience,marksBiology,average;
    float percentage;
    string name ,grade;

    cout<<"Enter student name: ";
    cin >> name;
    cout<<"Enter marks for English: ";
    cin >> marksEnglish;
    cout<<"Enter marks for Maths: ";
    cin >> marksMaths;
    cout<<"Enter marks for Chemistry: ";
    cin >> marksChemistry;
    cout<<"Enter marks for Social Science: ";
    cin >> marksSocialScience;
    cout<<"Enter marks for Biology: ";
    cin >> marksBiology;

    average = calculateAverage(marksEnglish,marksMaths,marksChemistry,marksSocialScience,marksBiology);
    percentage = ((marksEnglish+marksMaths+marksChemistry+marksSocialScience+marksBiology)/500)*100;

    cout << "Student Name: "<<name<<endl;
    cout << "Percentage: "<<percentage<<"%"<<endl;
    cout << "Grade: "<<calculateGrade(average)<<endl;

}

float calculateAverage(float marksEnglish, float marksMaths, float marksChemistry, float marksSocialScience, float marksBiology)
{
    int average = (marksEnglish+marksMaths+marksChemistry+marksSocialScience+marksBiology)/5;
    return average ;
}

string calculateGrade(float average)
{
    if (average <= 100 && average >= 90)
        return "A+";
    if (average <= 90 && average >= 80)
        return "A";
    if (average <= 80 && average >= 70)
        return "B+";
    if (average <= 70 && average >= 60)
        return "B";
    if (average <= 60 && average >= 50)
        return "C";
    if (average <= 50 && average >= 40)
        return "D";
    if (average <= 40 )
        return "F";



}