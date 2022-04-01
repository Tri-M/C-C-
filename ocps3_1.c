#include <iostream>
#include <stdlib>

using namespace std;

class Address
{

        public:
        Address(int h, string st, int appt, string c, string s, string pc);
        Address(int h, string st, string c, string s, string pc);
        bool comes_before(Address a) const;
        void print() const;

        private:
        int house_number;
        string street;
        int apartment_number;
        string city;
        string state;
        string postal_code;
};

Address::Address(int h, string st, int appt, string c, string s, string pc)
{

        house_number = h;
        street = st;
        apartment_number = appt;
        city = c;
        state = s;
        postal_code = pc;
}

Address::Address(int h, string st, string c, string s, string pc)
{


        house_number = h;
        street = st;
        city = c;
        state = s;
        postal_code = pc;
}
void Address::print()const
{

        cout << house_number << " " << street;
        if (apartment_number > 0 )
                cout << ", #" << apartment_number << endl;
                cout << city << ", " << state << ", " << postal_code << endl;
}

bool Address::comes_before( Address other)const
{

        return postal_code < other.postal_code;

}


int main()
{

        Address aHouse(100, "N.University Dr.", "Edmond", "OK", 73034);

        Address anApartment(201, "N.E. 89th St.", 305, "Oklahoma City", "OK", 73134);

        cout << " Comparing Address\n\n";
        a.House.print();

        cout << "\nwith address\n\n";

        anApartment.print();

        if(a.House.comes_before(anApartment))

                cout << "\nThe HOUSE address comes before the APARTMENT address\n";
        else
                cout << "\nThe HOUSE address does o come before the APARTMENT address\n";




        if (anApartment.comes_before(aHouse))

                cout << " \nThe APARTMENT address comes before the HOUSE address\n";
        else
                cout << " \nThe APARTMENT address does not come before the HOUSE address\n";

        return 0;

    }
