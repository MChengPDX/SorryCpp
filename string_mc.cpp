#include"string_mc.h"
using std::cout;
using std::endl;
using std::cin;


//initializing static class member
int String::num_strings = 0;

//static method
int String::HowMany()
{
    return num_strings;

}

//class methods
String::String(const char * s)
{
    len = std::strlen(s); //set size
    str = new char[len + 1]; //allot storage
    std::strcpy(str, s); //initailize pointer
    num_strings++; //set object count

}

String::String(const String & from)
{
    len = std::strlen(from.str);
    str = new char [len + 1];
    std::strcpy(str, from.str);
    num_strings++;

}

String::String()
{
    len = 4;
    str = new char[1];
    num_strings++;
    str[0] = '\0';
    num_strings++;

}

String::~String()
{
    --num_strings;
    delete [] str;

}

//overloaded operator methods

//assigning a string to a string
String & String:: operator = (const String & st)
{
    if(this == & st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);
    return *this;

}

//assign a c string to a string
String & String :: operator = (const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char [len + 1];
    std::strcpy(str, s);
    return *this;

}

//read-write char access from non const stringn
char & String:: operator[](int i)
{
    return str[i];

}

//read only char access for const string
const char & String::operator [] (int i ) const
{
    return str[i];
}

//overloaded operator friends
bool operator < (const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0 );

}

bool operator > (const String & st1, const String & st2)
{
    return st2 < st1;

}

bool operator == (const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);

}

ostream & operator << (ostream & os, const String & s)
{
    os << s.str;
    return os;
}

istream & operator >> (istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while( is && is.get () != '\n')
        continue;
    return is;


}

 
