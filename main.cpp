#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h> 

using namespace std;

struct Person
{
    string name;
    string family;
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

void FindTicket(ifstream &inFile, string personFullName)
{
    string line;
    while (getline(inFile, line))
    {
        if (line.find(personFullName) != string::npos)
        {
            cout << "--Person Have Ticket!--" << endl;
            cout << "---------TICKET----------" << endl;
            int countComma = 0;

            cout << "Name: ";
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] != ',' && line[i] != ' ')
                {
                    cout << line[i];
                }
                if (line[i] == ',')
                {
                    countComma++;
                    cout << endl;
                    if (countComma == 1)
                    {
                        cout << "Family: ";
                    }
                    if (countComma == 2)
                    {
                        cout << "Compartment: ";
                    }
                    if (countComma == 3)
                    {
                        cout << "Seat: ";
                    }
                }
            }
            cout << "\n-------------------\n";
        }

    }
}

bool HaveTicket()

void AddSeat()
{
    cout << endl;
    Person person;
    ofstream File("Train.txt", ios::app);
    ifstream InFile("Train.txt");



    cin.ignore();
    cout << "Enter Person name: ";
    getline(cin, person.name);
    transform(person.name.begin(), person.name.end(), person.name.begin(), ::tolower);
    
    cout << "Enter Person family: ";
    getline(cin, person.family);
    transform(person.family.begin(), person.family.end(), person.family.begin(), ::tolower);

    string fullName = person.name + ", " = person.family;

    string line;
    // bool found = ShowTicket(InFile, fullName);
    if (true)
    {
        if (Seats(InFile) - 1 < 60)
        {
            cout << "Enter Person compartment: ";
            getline(cin, person.compartment);
            cout << "Enter Person seat: ";
            getline(cin, person.seat);

            File << person.name << ", " << person.family << ", " << person.compartment << ", " << person.seat << endl;
            File.close();
            cout << "-- Ticket Added Successfully! --\n\n\n";
        }
        else
        {
            cout << "-- Train Was Full! --\n\n\n";
        }
    }

}

// void ShowDate()
// {
//     if (ifstream input{"Train.txt", ios::in})
//     {
//         while (input >> namme >> )
//         {
//             /* code */
//         }
        
//     }
// }




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