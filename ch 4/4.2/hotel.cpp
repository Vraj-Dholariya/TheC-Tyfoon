#include <iostream>
using namespace std;

class Hotel {
private:
    int hotel_id;
    char hotel_name[20];
    char hotel_type[20];
    int hotel_rating;
    static char hotel_location[20];
    int hotel_establish_year;
    int hotel_staff_quantity;
    int hotel_room_quantity;

public:
    // Setter
    void setHotelData()
     {
        cout << endl;
        cout << "Enter hotel ID: ";
        cin >> hotel_id;
        cout << "Enter hotel Name: ";
        cin >> hotel_name;
        fflush(stdin);
        cout << "Enter hotel Type: ";
        cin >> hotel_type;
        fflush(stdin);
        cout << "Enter hotel rating: ";
        cin >> hotel_rating;
        fflush(stdin);
        cout << "Enter establish year: ";
        cin >> hotel_establish_year;
        cout << "Enter staff quantity: ";
        cin >> hotel_staff_quantity;
        cout << "Enter room quantity: ";
        cin >> hotel_room_quantity;
    }

    // Getter
    void getHotelData() {
        cout << endl
             << endl
             << hotel_id << " "
             << hotel_name << " "
             << hotel_type << " "
             << hotel_rating << " "
             << hotel_location << " " 
             << hotel_establish_year << " "
             << hotel_staff_quantity << " "
             << hotel_room_quantity << endl;
    }
};
char Hotel::hotel_location[] = "Surat";
