#ifndef header_hpp
#define header_hpp

#include <iostream>  
#include <string>  
#include <vector>  
#include <sstream>  
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;

const char clear[] = "clear"; // for Linux
//const char clear[] = "cls"; // for Windows

//  inputInfo.cpp
string Username(); 
void CheckDay();
void OrderTime(int* hours, int* minutes);
bool OrderType(string user);
void DeliveryAdress();

//  ordering.cpp
void MenuLoading(string* names, int* prices, string* ingredients, int* size, string file_name);
void MenuDisplay(string* names, int* prices, string* ingredients, int size);
void OrderDisplay(string* names, int* prices, int* order, int size);
void Ordering(string* names, int* prices, string* ingredients, int* order, int size);

#endif

