#include"string_mc.h"
using std::cout;
using std::endl;
using std::cin;


//initializing static class member
int StringMC::num_strings = 0;

//static method
int StringMC::HowMany()
{
    return num_strings;

}

//class methods
StringMC::StringMC(const char * s)
{
    len = std::strlen(s); //set size
    str = new char[len + 1]; //allot storage
    std::strcpy(str, s); //initailize pointer
    num_strings++; //set object count

}

StringMC::StringMC(const StringMC & from)
{
    len = std::strlen(from.str);
    str = new char [len + 1];
    std::strcpy(str, from.str);
    num_strings++;

}

StringMC::StringMC()
{
    len = 4;
    str = new char[1];
    num_strings++;
    str[0] = '\0';
    num_strings++;

}

StringMC::~StringMC()
{
    --num_strings;
    delete [] str;

}

//overloaded operator methods

//assigning a string to a string
StringMC & StringMC:: operator = (const StringMC & st)
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
StringMC & StringMC :: operator = (const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char [len + 1];
    std::strcpy(str, s);
    return *this;

}

//read-write char access from non const stringn
char & StringMC:: operator[](int i)
{
    return str[i];

}

//read only char access for const string
const char & StringMC::operator [] (int i ) const
{
    return str[i];
}

//overloaded operator friends
bool operator < (const StringMC & st1, const StringMC & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0 );

}

bool operator > (const StringMC & st1, const StringMC & st2)
{
    return st2 < st1;

}

bool operator == (const StringMC & st1, const StringMC & st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);

}

ostream & operator << (ostream & os, const StringMC & s)
{
    os << s.str;
    return os;
}

istream & operator >> (istream & is, StringMC & st)
{
    char temp[StringMC::CINLIM];
    is.get(temp, StringMC::CINLIM);
    if (is)
        st = temp;
    while( is && is.get () != '\n')
        continue;
    return is;


}

 
