//File handling for users
void storeUserData(string names[],string password[],string userClass[],int indexCount)
{
    fstream StoreUsers;
    StoreUsers.open("Users.txt",ios::out);
    for (int i=0; i<indexCount; i++)
    {
        if (i == indexCount - 1)
        {
            StoreUsers << names[i] <<"," <<password[i] <<"," << userClass[i];
        }
        else
        {
            StoreUsers << names[i] <<"," <<password[i] <<"," << userClass[i] << "\n";
        }
    }
    StoreUsers.close();
}
void readUserData(string names[],string password[],string userClass[],int &indexCount)
{
    string get = "";
    fstream readFile;
    readFile.open("Users.txt",ios::in);
    if (readFile.fail())
    {
        return;
    }
    while (!readFile.eof())
    {
        getline(readFile,get);
        names[indexCount] = getField(get , 1);
        password[indexCount] = getField(get , 2);
        userClass[indexCount] = getField(get , 3);
        indexCount++;
    }
    readFile.close();
}
string getField(string get,int field)
{
    int commaCount = 1;
    string result = "";
    for (int x=0; x<get.length();x++)
    {
        if (get[x]==',')
        {
            commaCount = commaCount + 1;
        }
        else if(commaCount == field)
        {
            result = result + get[x]; 
        } 
        else if (commaCount > field)
        {
            break;
        }
    }
    return result;
}