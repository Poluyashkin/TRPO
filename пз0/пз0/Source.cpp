#include <iostream>
using namespace std;

int main(){
    int Year;
    cout << "Enter a year number: ";
    cin >> Year;
    int Remainder = Year % 12;


    switch (Remainder){
    case 1:
        cout << Year << " year of the rooster" << endl;
        break;
    case 2:
        cout << Year << " year of the dog" << endl;
        break;
    case 3:
        cout << Year << " year of the pig" << endl;
        break;
    case 4:
        cout << Year << " year of the rat" << endl;
        break;
    case 5:
        cout << Year << " year of the bull" << endl;
        break;
    case 6:
        cout << Year << " year of the tiger" << endl;
        break;
    case 7:
        cout << Year << " year of the cat and rabbit" << endl;
        break;
    case 8:
        cout << Year << " year of the dragon" << endl;
        break;
    case 9:
        cout << Year << " year of the snake" << endl;
        break;
    case 10:
        cout << Year << " year of the hourse" << endl;
        break;
    case 11:
        cout << Year << " year of the goat" << endl;
        break;
    case 0:
        cout << Year << " year of the monkey" << endl;
        break;
    default:
        cout << "Error!!!" << endl;
    }
    return 0;
}