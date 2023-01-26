#include "header.hpp"

const int MAX_SIZE = 100; //maksymalny rozmiar menu 

int main()
{
    srand(time(NULL));
    
    cout << endl;
    cout << "Witamy w restauracji ISENGARD!\n"
         << "ul Mickiewiecza 34 Poznan\n"
         << "Dni i godziny otwarcia: pn-pt 10:00 - 18:00\n"
         << "Zamowienia z dowozem tylko na obszarze Poznania\n\n";
    
    string username = Username();
    
    CheckDay();
    
    int hours = 0;
    int minutes = 0;
    OrderTime(&hours, &minutes);
    
    bool is_takeaway = OrderType(username);
    if(is_takeaway)
    {
        system(clear);
        DeliveryAdress();
        system(clear);
    }
        
    else
    {
        system(clear);    
        cout << "Numer twojego stolika: " << rand() % 11 << endl << endl;
    }
    
    int menu_size = 0;                       // zmienna przechowującej realny rozmiar menu
    string menu_names[MAX_SIZE] = {};        // tablica nazw dań
    int menu_prices[MAX_SIZE] = {};          // tablica cen
    string menu_ingredients[MAX_SIZE] = {};  // tablica składników
    int order_list[MAX_SIZE] = {};           // tablica przechowująca zamówione pozycje 
    
    MenuLoading(menu_names, menu_prices, menu_ingredients, &menu_size, "menu.txt");
    
    Ordering(menu_names, menu_prices, menu_ingredients, order_list, menu_size);
    
    cout << "Dziękujemy za zlozenie zamowenia!" << endl;
    cout << "Planowana godzina realizacji twojego zamowienia - " << hours << ":" << minutes;
    
    // Zapis rachunku do pliku 
    fstream current_file;
    current_file.open("bill.txt", ios::trunc | ios::out);
    if(current_file.good())
    {
        int sum = 0;
        current_file << "Twoje zamowienie\n";
        for (int i = 0, j = 1; i < menu_size; i++)
        {
            if (order_list[i])
            {
                current_file << "[" << j << "]  " << order_list[i] << " x " 
                             << menu_prices[i]  << "PLN " << menu_names[i] << endl;
            
                sum += (order_list[i] * menu_prices[i]);
                ++j;
            }
        }
        current_file << "Lacznie do zaplaty: " << sum << "PLN\n\n";
    }
    current_file.close();
    
    cin.ignore();
    cin.get();
    return 0;
}