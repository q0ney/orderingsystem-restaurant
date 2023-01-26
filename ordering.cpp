#include "header.hpp"

// funkcja wczytująca dane z pliku, dzieląca je w odpowiedni sposób, zapisując do poszczególnych tablic 
void MenuLoading(string* names, int* prices, string* ingredients, int* size, string file_name)
{
    fstream current_file;
    current_file.open(file_name, ios::in);
    if (current_file.good()) 
    {
        string line = "";
        string element;
        char separator = ';';

        int index = 0;
        while (!current_file.eof())
        {
            getline(current_file, line); // pobieranie kolejnych linii pliku
            stringstream LINE(line);

            int part = 0;
            // pętla przechodząca przez kolejne fragmeny danej linii, 
            // przypisując je do odpowiednich tablic
            while (getline(LINE, element, separator)) 
            {
                if (part == 0)
                    names[index] = element;
                if (part == 1)
                    prices[index] = stoi(element);  // stoi() - string to int
                if (part == 2)
                    ingredients[index] = element;
                part++;
            }
            index++;
        }
        *size = index;
        current_file.close();
    }
    else 
    {
        cout << "Wystapil nieoczekiwany blad, sprobuj uruchomic aplikacje ponownie.";
        exit(0);
    }
}

// funkcja wyświetla menu dań
void MenuDisplay(string* names, int* prices, string* ingredients, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i + 1 << "] " << names[i];
        if (ingredients[i] != "")
            cout << " (" << ingredients[i] << ")";
        cout << endl << "cena: " << prices[i] << " PLN" << endl << endl;
    }
}

// funkcja wyświetlająca pozycje dodane do zamówienia
void OrderDisplay(string* names, int* prices, int* order, int size)
{
    int sum = 0;
    cout << "Twoje zamowienie\n";
    for (int i = 0, j = 1; i < size; i++)
    {
        if (order[i])
        {
            cout << "[" << j << "]  " << order[i] << " x " << prices[i] 
                 << "PLN " << names[i] << endl;
            
            sum += (order[i] * prices[i]);
            ++j;
        }
    }
    cout << "Lacznie do zaplaty: " << sum << "PLN\n\n";
}

// funkcja steruje przebiegiem procesu zamawiania 
void Ordering(string* names, int* prices, string* ingredients, int* order, int size)
{
    int input, input_2;
    
    while (true)
    { 
        MenuDisplay(names, prices, ingredients, size);
        cout << "[0] ZAMKNIJ APLIKACJE\n";
        cout << "\nWybierz pozycje z menu: ";
        cin >> input;
        if (input and input <= size)
        {
            cout << "Podaj ilosc porcji: ";
            cin >> input_2;
            system(clear);
            cout << "\nDo zamowienia dodano " << input_2 << " x " 
                 << names[input - 1] << endl << endl;
            order[input - 1] = input_2;
        }
        else if (not input)
            exit(0);
        else
        {
            cout << "\nPodano zla pozycje! ";
            continue;
        }
choice:        
        cout << "[1] Kontynuuj zamawianie\n";
        cout << "[2] Wyswietl zamowienie\n";
        cout << "[3] Usun pozycje z zamowienia\n";
        cout << "[4] Przejdz do podsumowania\n";
        cout << "\n[0] ZAMKNIJ APLIKACJE\n";
        
        while(true)
        {
            cin >> input;
            if (input == 1)
                break;
                
            else if (input == 2)
            {   
                system(clear);
                OrderDisplay(names, prices, order, size);
                goto choice; 
                
            }
            else if (input == 3) 
            {
                system(clear);
                OrderDisplay(names, prices, order, size);
                cout << "Wybierz pozycje ktora chcesz usunac: ";
                cin >> input_2;
                for (int i = 0, j = 1; i < size; i++)
                {
                    if(order[i])
                    {
                        if(j == input_2)
                            order[i] = 0;
                        j++;
                    }
                }
                system(clear);
                cout << "Usunieto pozycje\n";
                OrderDisplay(names, prices, order, size);
                goto choice;  
            }
            else if (input == 4)
                break;
            else if (input == 0)
                exit(0);
            else 
                cout << "niepoprawna wartosc, wprowadz ponownie: ";
        }
        system(clear);
        if (input == 1)
            continue;
        if (input == 4)
            break;
        
    }
    
    OrderDisplay(names, prices, order, size);
    
    cout << endl << "[1] Zamawiam\n";
    cout << "[2] Powrot\n";
    cout << "\n[0] ZAMKNIJ APLIKACJE\n";
    
    while (true)
    {
        cin >> input;
        if (input == 1)
            break;
        else if (input == 2)
            goto choice;
        else if (input == 0)
            exit(0);
        else
             cout << "niepoprawna wartosc, wprowadz ponownie: ";
        
    }
}