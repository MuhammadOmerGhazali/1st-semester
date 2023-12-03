#include <iostream>

using namespace std;

void identity_matrix(int x[][3]);

int main()
{
    int array[3][3];

    cout <<"Enter the elements of the matrix: "<<endl;

    for (int x = 0 ; x<3;x++)
    {
        for (int y = 0;y<3;y++)
        {
            cout <<"Enter element at position ["<<x<<"]["<<y<<"]: ";
            cin >> array[x][y];
        }
    }
    
    cout <<"The matrix you entered is:"<< endl;
    for (int x = 0 ; x<3;x++)
    {
        for (int y = 0;y<3;y++)
        {
            cout <<array[x][y]<<"\t";
        }
        cout<<endl;
    }
    
    identity_matrix(array);
}

void identity_matrix(int array[][3])
{
bool check;

 for (int x = 0 ; x<3;x++)
    {
        for (int y = 0;y<3;y++)
        {
            if (x==y)
            {
                
            }
        }
    } 
/*
    if ((array[0][0]== 1 && array[1][1] == 1) && array[2][2] == 1)
    {
        if((array[0][1] == 0 && array[0][2] == 0) && (array[1][0] == 0 && array[1][2] == 0) && (array[2][1] == 0 && array[2][1] == 0 ))
        {
            cout <<"The entered matrix is an identity matrix.";
        }
    }
    else 
    {
        cout <<"The entered matrix is NOT an identity matrix.";
    }
*/

}   