#include<bits/stdc++.h>
using namespace std;

class Vaccine{
    private:
    map<string, int> vaccine_data;
    public:
    Vaccine(string name,int qty){
        if(vaccine_data.find(name)==vaccine_data.end()){
            vaccine_data[name] += qty;
        }
    }
    
    void get_details_vaccine(){
        for(auto it:vaccine_data){
            
        cout<<"Vaccine Name: "<<it.first<<endl;
        cout<<"Total Quantity: "<<it.second<<endl;
        }
    }
    
    bool check(string s){
        if(vaccine_data.find(s)==vaccine_data.end()){
            return false;
        }
        return true;
    }
    
    void add_vaccine(string name,int qty){
        if(vaccine_data.find(name)==vaccine_data.end()){
            vaccine_data[name] += qty;
        }
    }
    
    int give_vacc(int n,string name){
        if(n<vaccine_data[name]){
            vaccine_data[name]-=n;
            return n;
        }
        return 0;
    }
};

class Hospital{
    private:
    string name;
    map<string,int> vaccineInventory;
    public:
    Hospital(string name){
        this->name = name;
    }
    
    void add_vaccine(Vaccine& v, int n, string vac_name){
        bool check = v.check(vac_name);
        if(check){
        if(vaccineInventory.find(vac_name) == vaccineInventory.end()){
            vaccineInventory[vac_name]=0;
        }
        int v_qty = v.give_vacc(n,vac_name);
        vaccineInventory[vac_name] += v_qty;
        }
        else{
            cout<<"Vaccine not present in inventory."<<endl;
        }
    }
    
    void get_vacc_avl(){
        cout << "Available Vaccines at " << name << " Hospital:\n";
        cout << "-----------------------------------\n";
        for (const auto& entry : vaccineInventory) {
            cout << "Vaccine: " << entry.first << "\tQuantity: " << entry.second << endl;
        }
        cout << "-----------------------------------\n";
    }
    
    bool check(string s){
        if(vaccineInventory.find(s)!=vaccineInventory.end()) return true;
        else return false;
    }
    
    void give_cust_vaccine(int n,string s){
        vaccineInventory[s]-=n;
    }
};

class Customer{
    private:
    string name;
    int age;
    long mobile;
    string address;
    string vacc = "Not Vaccinted";
    public:
    Customer(string name,int age,long mobile,string address){
        this->name = name;
        this->age = age;
        this->mobile = mobile;
        this->address = address;
    }
    
    void get_cust_data(){
        cout<<"----------------------------------"<<endl;
        cout<<"Name: "<<this->name<<endl;
        cout<<"Age: "<<this->age<<endl;
        cout<<"Mobile: "<<this->mobile<<endl;
        cout<<"Address: "<<this->address<<endl;
        cout<<"Vaccine: "<<this->vacc<<endl;
        cout<<"----------------------------------"<<endl;
    }
    
    void get_vacc(Hospital& h1,string vac){
        bool check = h1.check(vac);
        if(check){
            h1.give_cust_vaccine(1,vac);
            this->vacc = vac;
        }
        else{
            cout<<"Chhose other Vaccine"<<endl;
            h1.get_vacc_avl();
        }
    }
};



int main(){
    Vaccine v1("Covaxin",100);
    v1.get_details_vaccine();
    
    Hospital h1("MS");
    h1.add_vaccine(v1,20,"Covaxin");
    h1.get_vacc_avl();
    
    v1.get_details_vaccine();
    
    Customer c1("Aryan",19,9939201267,"KIIT");
    c1.get_cust_data();
    
    c1.get_vacc(h1,"Covaxin");
    c1.get_cust_data();
    h1.get_vacc_avl();
    
    
}
