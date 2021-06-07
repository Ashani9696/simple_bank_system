#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

int main();

class Bank
{
    public:
    virtual void getData () = 0;
};

class Staff : public Bank
{
private:
    int index,phonNumber,OThours;
    char name[50],address[50];
    double BasicSalary,NetSalary;
public:
    void getData();
    void Calculate();
    void WriteData();
    void ReadData();
    void UpdateStaff();
    void DeleteStaff();
};

class Customers : public Bank
{
private:
    int nic,CphoneNumber;
    char Cname[50],Caddress[20];
    double deptAmount;
public:
    void getData();
    void WriteDataCustomer();
    void ReadDataCustomer();
    void UpdateCustomer();
    void DeleteCustomer();
};

//********************************************************************************************************************************
//
//********************************************************************************************************************************

void Staff :: getData()
{
      WriteData();
}

void Staff :: WriteData()
{
    Staff obj;
    ofstream OutFile;
    OutFile.open("Staff.dat",ios::binary | ios::out);

    cout<<"Enter Index Number: ";
    cin>>index;
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter Address: ";
    cin>>address;
    cout<<"Enter Your Phone Number: ";
    cin>>phonNumber;
    cout<<"Enter Basic Salary: ";
    cin>>BasicSalary;
    cout<<"Enter OT hours: ";
    cin>>OThours;
    obj.Calculate();

    OutFile.write(reinterpret_cast<char *>(&obj),sizeof(Staff));
    OutFile.close();
}

void Staff :: ReadData()
{
    Staff obj;
    ifstream InFile;
    InFile.open("Staff.dat",ios::binary | ios::in);

    if(!InFile)
    {
        cout<<"File Does not found!!!"<<endl;
    }
    else
    {
        cout<<"====================================================================================================================\n";
        cout<<"Index Number              Name                   Address             Phone Number                Basic Salary        "<<endl;
        cout<<"====================================================================================================================\n";

        while(InFile.read(reinterpret_cast<char *>(&obj),sizeof(Staff)))
        {
            cout<<obj.index<<"\t\t\t\t"<<obj.name<<"\t\t\t\t"<<obj.address<<"\t\t\t\t"<<obj.phonNumber<<"\t\t\t\t"<<obj.BasicSalary<<endl;
        }
    }
    InFile.close();
}

void Staff :: UpdateStaff()
{
    Staff obj;
    int indx;
    fstream InFile;
    InFile.open("Staff.dat",ios::binary | ios::in | ios::out);

    cout<<"Enter Index Number to Update: ";
    cin>>indx;

    while(InFile.read(reinterpret_cast<char *>(&obj),sizeof(Staff)))
    {
        if(indx==obj.index)
        {
            cout<<"Index Number is: "<<obj.index<<endl;
            cout<<"Name is: "<<obj.name<<endl;
            cout<<"Address is: "<<obj.address<<endl;
            cout<<"Phone NUmber is: "<<obj.phonNumber<<endl;
            cout<<"Basic Salary is: "<<obj.BasicSalary<<endl;

            cout<<endl<<endl<<endl;

            obj.getData();

            int pos = (-1)*static_cast<int>(sizeof(obj));
            InFile.seekp(pos,ios::cur);
            InFile.write(reinterpret_cast<char *>(&obj),sizeof(Staff));
            cout<<"\nRECORD UPDATE!!!!"<<endl;

            InFile.close();
        }
        else
        {
            cout<<"Invalid Index Number!!!";
        }
    }
}

void Staff :: DeleteStaff()
{
    Staff obj;
    int indx;

    fstream InFile,TempOut;
    InFile.open("Staff.dat",ios::binary | ios::in );
    TempOut.open("tempStaff.dat",ios::binary | ios::out);

    InFile.seekp(0,ios::beg);

    cout<<"Enter Index You want to delete: ";
    cin>>indx;

    while(InFile.read(reinterpret_cast<char *>(&obj),sizeof(Staff)))
          {
            if(indx==obj.index)
            {
                TempOut.write(reinterpret_cast<char *>(&obj),sizeof(Staff));
            }
            else
            {
                cout<<"can't Found Index Number!!";
            }
          }

        remove("Staff.dat");
        rename("tempStaff.dat","Staff.datrename");
        cout<<"\n\nRecord Deleted Successfully!!!!"<<endl;
}

void Staff :: Calculate()
{
    NetSalary = BasicSalary + (OThours*2000) - ((BasicSalary * 8/100) + (BasicSalary*3/100));
}

//********************************************************************************************************************************
//
//********************************************************************************************************************************

void Customers :: getData()
{
    WriteDataCustomer();
}

void Customers :: WriteDataCustomer()
{
    Customers obj;
    ofstream OutFile;
    OutFile.open("Customers.dat",ios::binary | ios::out);

    cout<<"Enter NIC Number: ";
    cin>>nic;
    cout<<"Enter Name: ";
    cin>>Cname;
    cout<<"Enter Address: ";
    cin>>Caddress;
    cout<<"Enter Phone Number: ";
    cin>>CphoneNumber;
    cout<<"Enter Deposit Amount: ";
    cin>>deptAmount;

    OutFile.write(reinterpret_cast<char *>(&obj),sizeof(Customers));
    OutFile.close();
}


void Customers :: ReadDataCustomer()
{
    Customers obj;
    ifstream InFile;
    InFile.open("Customers.dat",ios::binary | ios::in);

    if(!InFile)
    {
        cout<<"File Does not found!!!"<<endl;
    }
    else
    {
        cout<<"====================================================================================================================\n";
        cout<<"Nic Number              Name                   Address             Phone Number                Deposit Amount       "<<endl;
        cout<<"====================================================================================================================\n";

        while(InFile.read(reinterpret_cast<char *>(&obj),sizeof(Customers)))
        {
            cout<<obj.nic<<"\t\t\t\t"<<obj.Cname<<"\t\t\t\t"<<obj.Caddress<<"\t\t\t\t"<<obj.CphoneNumber<<"\t\t\t\t"<<obj.deptAmount<<endl;
        }
    }
    InFile.close();
}


void Customers :: UpdateCustomer()
{
    Customers obj;
    int ni;
    fstream InFile;
    InFile.open("Customers.dat",ios::binary | ios::in | ios::out);

    cout<<"Enter Index Number to Update: ";
    cin>>ni;

    while(InFile.read(reinterpret_cast<char *>(&obj),sizeof(Customers)))
    {
        if(ni==obj.nic)
        {
            cout<<"NIC is: "<<obj.nic<<endl;
            cout<<"Name is: "<<obj.Cname<<endl;
            cout<<"Address is: "<<obj.Caddress<<endl;
            cout<<"Phone Number is: "<<obj.CphoneNumber<<endl;
            cout<<"Deposit Amount is: "<<obj.deptAmount<<endl;

            cout<<endl<<endl<<endl;

            obj.getData();

            int pos = (-1)*static_cast<int>(sizeof(obj));
            InFile.seekp(pos,ios::cur);
            InFile.write(reinterpret_cast<char *>(&obj),sizeof(Customers));
            cout<<"\nRECORD UPDATE!!!!"<<endl;

            InFile.close();
        }
        else
        {
            cout<<"Invalid Index Number!!!";
        }
    }
}

void Customers :: DeleteCustomer()
{
    Customers obj;
    int ni;

    fstream InFile,TempOut;
    InFile.open("Customers.dat",ios::binary | ios::in );
    TempOut.open("tempCustomers.dat",ios::binary | ios::out);

    InFile.seekp(0,ios::beg);

    cout<<"Enter Index You want to delete: ";
    cin>>ni;

    while(InFile.read(reinterpret_cast<char *>(&obj),sizeof(Customers)))
          {
            if(ni==obj.nic)
            {
                TempOut.write(reinterpret_cast<char *>(&obj),sizeof(Customers));
            }
            else
            {
                cout<<"can't Found Index Number!!";
            }
          }

        remove("Customers.dat");
        rename("tempCustomers.dat","Customers.dat");
        cout<<"\n\nRecord Deleted Successfully!!!!"<<endl;
}


void WhoAreYou(Bank *b)
{
   b->getData();
}
int main()
{

    Customers c;
    Staff s;

    cout<<"1.Staff"<<endl;
    cout<<"2.Customer"<<endl;
    cout<<"0.Exit"<<endl;

    cout<<"Enter Your Choice: ";
    switch(getch())
    {
    case '1':
        system("CLS");
        cout<<"1.ADD"<<endl;
        cout<<"2.READ"<<endl;
        cout<<"3.UPDATE"<<endl;
        cout<<"4.DELETE"<<endl;
        cout<<"5.BACK"<<endl;
        switch(getch())
        {
        case '1':
            system("CLS");
            WhoAreYou(&s);
            break;
        case '2':
            s.ReadData();
            break;
        case '3':
            s.UpdateStaff();
            break;
        case '4':
            s.DeleteStaff();
            break;
        case '5':
            main();
            break;
        default:
            main();
            break;
        }
        break;
    case '2':
        system("CLS");
        cout<<"1.ADD"<<endl;
        cout<<"2.READ"<<endl;
        cout<<"3.UPDATE"<<endl;
        cout<<"4.DELETE"<<endl;
        cout<<"5.BACK"<<endl;
        switch(getch())
        {
        case '1':
            system("CLS");
            WhoAreYou(&c);
            break;
        case '2':
            c.ReadDataCustomer();
            break;
        case '3':
            c.UpdateCustomer();
            break;
        case '4':
            c.DeleteCustomer();
            break;
        case '5':
            main();
            break;
        default:
            main();
            break;
        }
        break;
    case '0':
        exit(0);
        break;
    default:
        cout<<"Try Again....!!!";
        getch();
        main();

    }

}
