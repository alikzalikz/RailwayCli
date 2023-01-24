#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Person
{
    string name;
    string compartment;
    string seat;
};

int Seats(ifstream &file)
{
    char ch;
    int lines = 0;
    
    file.seekg(0,ios::beg);
    while (file)
    {
        file.get(ch);

        if (ch == '\n')
        {
            lines ++;
        }
    }
    
    return lines;
}

void AddSeat()
{
    cout << endl;
    Person person;
    ofstream File("Train.txt", ios::app);
    ifstream InFile("Train.txt");

    cin.ignore();
    cout << "Enter Person name: ";
    getline(cin, person.name);
    
    string line;
    bool found = false;
    while (getline(InFile, line))
    {
        if (line.find(person.name) != string::npos)
        {
            cout << "--Person Have Ticket!--\n\n\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        if (Seats(InFile) - 1 > 60)
        {
            cout << "Enter Person compartment: ";
            getline(cin, person.compartment);
            cout << "Enter Person seat: ";
            getline(cin, person.seat);

            File << person.name << ", " << person.compartment << ", " << person.seat << endl;
            File.close();
            cout << "-- Ticket Added Successfully! --\n\n\n";
        }
        else
        {
            cout << "-- Train Was Full! --\n\n\n";
        }
    }

}

enum string_code
{
    e1,
    e2,
    e3,
    e4,
    e5,
    other
};

string_code HashIt (string const& inString)
{
    if (inString == "1") return e1;
    if (inString == "2") return e2;
    if (inString == "3") return e3;
    if (inString == "4") return e4;
    if (inString == "5") return e5;
    else return other;
}

int main()
{
    cout << "---- RAILWAY Cli ----\n\n";
    bool state = true;
    string num;
    
    while(state)
    {
        cout << "1. Reserve a Seat" << endl;
        cout << "2. Reserve a Compartment" << endl;
        cout << "3. Check Ticket" << endl;
        cout << "4. Ticket Refund" << endl;
        cout << "5. Exit" << endl;

        cout << "Please Choose Your Number: ";
        cin >> num;
        switch(HashIt(num))
        {
            case e1:
            {
                AddSeat();
                break;
            }
            case e2:
            {
                break;
            }
            case e3:
            {
                break;
            }
            case e4:
            {
                break;
            }
            case e5:
            {
                cout << endl;
                cout << "-- GOOD LUCK --";
                state = false;
                break;
            }
            case other:
            {
                cout << endl;
                cout << "-- Invalid Number! Please Try again --\n\n\n";
                break;
            }
        }
    }
}