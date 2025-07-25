#include<iostream.h>
#include<string.h>

class person_additional_info
{
    char address[20],license[20],insurance[20];
    long int contact; 
 public:
    person_additional_info() //Default constructor
    {   
        strcpy(address,"XYZ");
        strcpy(license,"XY-0000000000");
        strcpy(insurance,"XY00000000X");
        contact=000000000;
    }
    ~person_additional_info() //Destructor
    {
        cout<<"I am in Destructor";
    }
    friend class person;
    // Declaration Friend class
};
//Definition of friend class
class person
{
    char name[20], dob[10], blood[10];
    float ht,wt;
    static int count; // Static variable
    person_additional_info *pai;
 public:
    person() //Default constructor
    {
        strcpy(name,"XYZ");
        strcpy(dob,"dd/mm/yy");
        strcpy(blood,"A +");
        ht=0;
        wt=0;
        pai=new person_additional_info;
    }
    person(person*p1) //Copy constructor
    {
        strcpy(name,p1->name);
        strcpy(dob,p1->dob);
        strcpy(blood,p1->blood);
        ht=p1->ht;
        wt=p1->wt;
        pai=new person_additional_info;
        strcpy(pai->address,p1->pai->address);
        strcpy(pai->license,p1->pai->license);
        strcpy(pai->insurance,p1->pai->insurance);
        pai->contact=p1->pai->contact;
    }
    static void showcount() //Static member function
    {
        cout<<"\nNo of records count="<<count<<"\n";
    }
    ~person()   //Destructor
    {
        cout<<"\nI am in Destructor\n";
    }
    void getdata(char name[20]);
    inline void display(); // Inline function declaration
};
void person::getdata(char name[20])
{
strcpy(this->name,name);
//this pointer
cout<<"\n Enter date of birth";
cin>>dob;
cout<<"\n Enter blood group";
cin>>blood;
cout<<"\n Enter height";
cin>>ht;
cout<<"\n Enter weight";
cin>>wt;
cout<<"\n Enter address";
cin>>pai->address;
cout<<"\n Enter Licence number";
cin>>pai->license;
cout<<"\n Enter Insurance policy number";
cin>>pai->insurance;
cout<<"\n Enter Contact number";
cin>>pai->contact;
count++;
}
//inline function definition
void person::display()
{
cout<<"\t"<<name;
cout<<"\t"<<dob;
cout<<"\t"<<blood;
cout<<"\t"<<ht;
cout<<"\t"<<wt;
cout<<"\t"<<pai->address;
cout<<"\t"<<pai->license;
cout<<"\t"<<pai->insurance;
cout<<"\t"<<pai->contact;
}
int person::count;
//Static variable definition
int main()
{
    person *p1,*p2;
    int ch;
    
    p1=new person; //call default constructor & dynamic memory allocation
    p2=new person(p1); //call copy constructor
    
    cout<<"\tName";
    cout<<"\tDob";
    cout<<"\tBlood";
    cout<<"\tHt";
    cout<<"\tWt";
    cout<<"\tAddress";
    cout<<"\tLicense";
    cout<<"\tInsurance";
    cout<<"\tContact";
    
    cout<<endl;cout<<"Default Constructor Value \n";
    p1->display();
    cout<<"\n";
    cout<<"Copy Constructor Value \n";
    p2->display();
    
    int n;
    cout<<"\nEnter how many records you want??";
    cin>>n;
    person p3[n];   //array of object
    char name[20];
    int x=0;
    do
    {
        cout<<"\nWelcome to Personal database system";
        cout<<"\n1.Enter the record";
        cout<<"\n2.Display the record";
        cout<<"\n3.Exit";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                    cout<<"\nEnter the Name ";
                    cin>>name;
                    p3[x].getdata(name);
                    person::showcount(); // calls static function
                    x++;
                    break;
            }
            case 2:
            {
                    cout<<"\tName";
                    cout<<"\tDob";
                    cout<<"\tBlood";
                    cout<<"\tHt";
                    cout<<"\tWt";
                    cout<<"\tAddress";
                    cout<<"\tLicense";
                    cout<<"\tInsurance";
                    cout<<"\tContact";
                    for(int i=0;i<n;i++)
                    {
                        cout<<"\n";
                        p3[i].display(); //calls inline function
                    }
                    break;
            }
     }
    }while(ch!=3);
  delete p1; //dynamic memory de-allocation
  delete p2;
  return 0;
}