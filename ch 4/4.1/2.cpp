#include <iostream>
#include <string.h>
using namespace std;

class Customer
{
private:
        int  cust_id;
        char cust_name[20];
        int  cust_age;
        char cust_city[20];
        int  cust_mobile_number;
        int  cust_simcard_validity;
        char cust_telecom_brand_name[20];

public:

       //setter
       void setData(int  cust_id,
        char cust_name[],
        int  cust_age,
        char cust_city[],
        int  cust_mobile_number,
        int  cust_simcard_validity,
        char cust_telecom_brand_name[])
       {
                this->cust_id = cust_id;
                strcpy(this->cust_name,cust_name);
                this->cust_age = cust_age;
                strcpy(this->cust_city,cust_city);
                this->cust_mobile_number = cust_mobile_number;
                this->cust_simcard_validity = cust_simcard_validity;
                strcpy(this->cust_telecom_brand_name,cust_telecom_brand_name);
       }
       //getter
       void getData()
       {
         cout<<"Customer ID: "<<this->cust_id<< "  Customer Name: "<< this->cust_name << "  Customer age: " <<this->cust_age<<
         "  Customer City: "<<this->cust_city<< "  Customer Mobile Number: "<<this->cust_mobile_number<< "  Simcard Validity: " <<
         this->cust_simcard_validity<< "  Telecom Brand Name: "<<this->cust_telecom_brand_name << endl;
       }
};

int main()
{
    Customer c1,c2,c3,c4,c5;
    
    c1.setData(1,"Rahul",25,"Delhi",9484365690,2,"Jio");
    c2.setData(2,"Vraj",18,"Surat",8764324453,3,"Vi");
    c3.setData(3,"Rajl",29,"Ahemadabad",9834233511,1,"Airtele");
    c4.setData(4,"veer",21,"Mumbai",9334324355,2,"Jio");
    c5.setData(5,"Shila",26,"Kolakata",9843344334,2,"Airtele");

    c1.getData();
    c2.getData();
    c3.getData();
    c4.getData();
    c5.getData();    
}

