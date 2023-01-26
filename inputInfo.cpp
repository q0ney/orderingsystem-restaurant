#include "header.hpp"

// funkcja pobierająca imie od użytkownika
string Username()
{
    string username;
    cout << "Wprowadz swoje imie: ";
    cin >> username;
    while (username.length() < 3 or username.length() > 20)
    {   
        cout << "Wpisz poprawne imie" << endl;
        cin >> username;
    }
    return username;
}

// funkcja pobierająca dzień tygodnia
void CheckDay()
{
    int day_tracker;
    cout << "Wpisz nr dnia tygodnia (1 - poniedzialek itd.) " << endl;
    do
    {
        cin >> day_tracker;
        if (day_tracker == 6 or day_tracker == 7)
        {
            cout << "Restauracja jest zamknieta w weekend i nie przyjmuje zadnych zamowien!" << endl;
            exit(0);
        }
        if (day_tracker <= 0 or day_tracker > 7) 
            cout << "Wpisz poprawna liczbe" << endl;
        
    }while (day_tracker <= 0 or day_tracker > 7);
    
}

// funkcja pobierająca preferowaną godzinę zamówienia 
void OrderTime(int* hours, int* minutes)
{

    cout << "Podaj godzine na ktora chcesz swoje zamowienie (podaj najpierw godzine a pozniej minuty)"<<endl;
    cin >> *hours;
    cin >> *minutes;
    while (*hours < 10 or *hours >= 18 or *minutes < 0 or *minutes >= 60)
    {
        cout << "Wpisales niepoprawna godzine, wpisz ja ponownie!" << endl;
        cin >> *hours;
        cin >> *minutes;
    }
    system("clear");
    cout << "Zamowiles jedzenie na godzine: " << *hours << ":" << *minutes << endl;
}

// funkcja pobierająca typu zamówienia wybranego przez użytkownika
bool OrderType(string user)
{
    cout << endl;
    cout << user << ", wybierz typ zamowienia:\n";
    cout << "[1] na miejscu\n";
    cout << "[2] na dowoz\n\n";
    cout << "[0] ZAMKNIJ APLIKACJE\n";
    short int key;
    while (true)
    {
        cin >> key;
        if (key == 1) return 0;
        if (key == 2) return 1;
        if (key == 0) exit(0);
    }
}

// funkcja pobierająca adres dostaw od użytkownika
void DeliveryAdress()
{
    string city, street, postal_code, house_number;
    cout << "Podaj miasto: " << endl;
    cin >> city;
    if (city == "Poznan" or city == "poznan")
    {
        bool correct_adress;
        do
        {
            cout << "Podaj ulice" << endl;
            cin.ignore();
            getline(cin,street);
            cout << "Podaj numer domu (nr domu/nr mieszkania)" << endl;
            cin >> house_number;
            cout << "Podaj kod pocztowy" << endl;
            cin >> postal_code;
            
            cout << "\nCzy podany adres jest prawidlowy?\n";
            cout << street << " " << house_number << endl;
            cout << postal_code << " " << city << endl;
    
            cout << "\n[0] bledny adres\n";
            cout << "[1] poprawny adres\n";
            
            cin >> correct_adress;
            
            
        }while (not correct_adress);
        
    }
    else
    {
        cout<<"Przykro nam, ale nie dowozimy zamowien poza Poznan"<<endl;
        exit(0);
    }
    
}