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