#include <iostream>

using namespace std ;

void hospital(int days);

int main()
{
    int days;

    cout << "Enter Number of days you visited Hospital: ";
    cin >> days;

    hospital(days);

}

void hospital(int days)
{
    int patients , doctors = 7 ,day=1,untreated_patients=0,treated_patients=0;
    for (int i = 1; i <= days; i++)
    {
        cout << "Number of patients who visited hospital on Day "<< i << ": ";
        cin >> patients;

        if (patients<=doctors) 
        {
            treated_patients = treated_patients + patients ;
        }
        else
        {
            untreated_patients = untreated_patients+ (patients - doctors);
            treated_patients = treated_patients + doctors ;
        }
        
        day = day + 1;
        if (day == 3)
        {
            if (untreated_patients>treated_patients)
                doctors ++;
            day = 0;

        }


    }
        cout << "Treated Patients: "<< treated_patients<<endl;
        cout << "Untreated Patients: "<< untreated_patients<<endl;


}