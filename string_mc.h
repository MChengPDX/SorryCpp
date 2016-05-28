#include<cstring>
#include<iostream>
using namespace std;

/*
 * Class that uses dynamic memory.
 * Uses a pointer to aa char instead of a char array. This means
 * class declaration does not allocate storage space for the string
 * itself. Insteead it uses new in the constructors to allocate space 
 * for the string.
 * Static class variable is special, a program creates only one copy
 * of a static class varible, regardless of the number of objects created.
 * This is shared between all objects of that class.
 *
 */

class String
{
    private:
        char * str; //pointer to a string
        int len; //length of string
        static int num_strings; //number of objects
        static const int CINLIM = 100; // cin input limit
    public:
        String(const char * s); //constructor
        String(); //default
        String(const String &); //copy constructor
        ~String();
        int length () const { return len;}
        //overloaded functions
        String & operator = (const String &);
        String & operator = (const char *);
        char & operator [] (int i);
        const char & operator [] (int i) const;
        //Friends
        friend bool operator < (const String & s, const String & s2);
        friend bool operator > (const String & s, const String & s2);
        friend bool operator == (const String & s, const String & s2);
        friend ostream & operator << (ostream & os, const String & s);
        friend istream & operator >> (istream & is, String & s);

        //static function
        static int HowMany();
        
};
