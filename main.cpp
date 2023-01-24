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

bool HaveTicket(string searchContent)
{
    ifstream inFile("Train.txt");
    string line;
    bool state = false;

    while (getline(inFile, line))
    {
        if (line.find(searchContent) != string::npos)
        {
            state = true;
            return true;
        }
    }
    if (!state)
    {
        return false;
    }
}

string Availabe(int state)
{
    string SeatsNum = "0";
    for (int compartmentsI = 1; compartmentsI <= 10; compartmentsI++)
    {
        for (int seatsI = 1; seatsI <= 6; seatsI++)
        {
            string str = " " + to_string(compartmentsI) + ", " + to_string(seatsI);
            if (!HaveTicket(str))
            {
                if (state == 0)
                {
                    SeatsNum = to_string(compartmentsI);
                    break;
                }
                if (state == 1)
                {
                    SeatsNum = to_string(seatsI);
                    break;
                }

            }
        }
        if (SeatsNum != "0")
        {
            break;
        }
    }
    return SeatsNum;
}

void ShowTicket(string personFullName)
{
    ifstream inFile("Train.txt");
    string line;
    bool state = false;
    while (getline(inFile, line))
    {
        if (line.find(personFullName) != string::npos)
        {
            state = true;
            cout << "\n-- Passenger Have Ticket! --" << endl;
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
            cout << "\n-------------------\n\n\n";
        }
    }
    if (!state)
    {
        cout << "\nSorry, Passenger don't have Ticket\n\n\n";
    }
}

string GiveFullName()
{
    cout << endl;
    string str;
    string name;
    string family;
    cin.ignore();
    cout << "Enter Passenger Name: ";
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    
    cout << "Enter Passenger Family: ";
    cin >> family;
    transform(family.begin(), family.end(), family.begin(), ::tolower);

    return str = name + ", " + family;
}

void AddSeat()
{
    cout << endl;
    Person person;
    ofstream File("Train.txt", ios::app);
    ifstream InFile("Train.txt");

    cin.ignore();
    cout << "Enter Passenger name: ";
    getline(cin, person.name);
    transform(person.name.begin(), person.name.end(), person.name.begin(), ::tolower);
    
    cout << "Enter Passenger family: ";
    getline(cin, person.family);
    transform(person.family.begin(), person.family.end(), person.family.begin(), ::tolower);

    string fullName = person.name + ", " + person.family;

    if (HaveTicket(fullName))
    {
        ShowTicket(fullName);
    }
    else
    {
        if (Availabe(0) != "0")
        {
            person.compartment = Availabe(0);
            person.seat = Availabe(1);

            File << person.name << ", " << person.family << ", " << person.compartment << ", " << person.seat << endl;
            File.close();
            cout << "\n-- Ticket Added Successfully! --" << endl;
            ShowTicket(fullName);
        }
        else
        {
            cout << "\n-- Train Was Full! --\n\n\n";
        }
    }

}

// TODO: delete ticket but show not find
void RefundTicket(string fullName)
{
    string line;
    string str = "";
    bool state = false;

    ifstream InFile("Train.txt");
    while (getline(InFile, line))
    {
        if (line.find(fullName) == string::npos)
        {
            str += line + '\n';
            break;
        }
        else
        {
            state = true;
        }
    }
    InFile.close();

    ofstream File("Train.txt");
    File << str;
    File.close();

    if (state)
    {
        cout << "\n-- Ticket Refunded Successfully!-- " << endl;
    }
    else
    {
        cout << "\nTicket not found!" << endl;
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

        cout << "Please Choose Number: ";
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
                string fullName = GiveFullName();
                ShowTicket(fullName);
                break;
            }
            case e4:
            {
                string fullName = GiveFullName();
                RefundTicket(fullName);
                break;
            }
            case e5:
            {
                cout << "\n-- GOOD LUCK --";
                state = false;
                break;
            }
            case other:
            {
                cout << "\n-- Invalid Number! Please Try again --\n\n\n";
                break;
            }
        }
    }
    return 0;
}