#include <iostream>

using namespace std ;

string findZodiacSign(int day, string month);

int main()
{
    int day;
    string month;

    cout << "Enter the day of birth: ";
    cin>> day ;
    cout <<"Enter the month of birth (e.g., January, February): ";
    cin >> month ;

    cout << "Zodiac Sign: "<<findZodiacSign(day,month);
}

string findZodiacSign(int day, string month)
{
    if ((month == "March" || month == "April") && (day != 20))
        if ((month == "March") && ( day>20 && day <=31))
           return ("Aries"); 
        if ((month == "April") && ( day>=1 && day <20))
            return ("Aries");

    if (month == "May" || month == "April")
        if (((month == "April") && ( day>=20 && day <=31)))
            return ("Taurus");
        if (((month == "May") && ( day>=1 && day <=20)))
            return ("Taurus");

    if (month == "May" || month == "June")
        if (((month == "June") && ( day>=1 && day <=20)))
            return ("Gemini");
        if (((month == "May") && ( day>=21 && day <=31)))
            return ("Gemini");

    if (month == "June" || month == "July")
        if (((month == "June") && ( day>=21 && day <=31)))
            return ("Cancer");
        if (((month == "July") && ( day>=1 && day <=22)))
            return ("Cancer");

    if (month == "July" || month == "August")
        if (((month == "July") && ( day>=23 && day <=31)))
            return ("Leo");
        if (((month == "August") && ( day>=1 && day <=22)))
            return ("Leo");

    if (month == "August" || month == "September")
        if (((month == "August") && ( day>=23 && day <=31)))
            return ("Virgo");
        if (((month == "September") && ( day>=1 && day <=22)))
            return ("Virgo");

    if (month == "September" || month == "October")
        if (((month == "September") && ( day>=23 && day <=31)))
            return ("Libra");
        if (((month == "October") && ( day>=1 && day <=22)))
            return ("Libra");

    if (month == "October" || month == "November")
        if (((month == "October") && ( day>=23 && day <=31)))
            return ("Scorpio");
        if (((month == "November") && ( day>=1 && day <=21)))
            return ("Scorpio");

    if (month == "November" || month == "December")
        if (((month == "November") && ( day>=22 && day <=31)))
            return ("Sagittarius");
        if (((month == "December") && ( day>=1 && day <=21)))
            return ("Sagittarius");

    if (month == "December" || month == "January")
        if (((month == "December") && ( day>=22 && day <=31)))
            return ("Capricorn");
        if (((month == "January") && ( day>=1 && day <=19)))
            return ("Capricorn");

    if (month == "January" || month == "February")
        if (((month == "January") && ( day>=20 && day <=31)))
            return ("Aquarius");
        if (((month == "February") && ( day>=1 && day <=18)))
            return ("Aquarius");

    if (month == "February" || month == "March")
        if (((month == "April") && ( day>=19 && day <=28)))
            return ("Pisces");
        if (((month == "March") && ( day>=1 && day <=20)))
            return ("Pisces");

}