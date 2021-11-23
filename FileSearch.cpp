#include<iostream>
#include<cstring>
#include<fstream>
#include <sstream>
#include <string>
#include<cstdlib>

using namespace std;

class student
{
 string id;
 string name;
 string father_name;
 int age;
 public:
       void setid(string a){id=a;}
       void setname(string b){name=b;}
       void setfather_name(string c){father_name=c;}
       void setage(int o){age=o;}
       string getid(){return id;}
       string getname(){return name;}
       string getfather_name(){return father_name;}
       int getage(){return age;}
};

fstream file;

void add()
{
      system("CLS");
      string i,n,fn;
      int age1;
      student s;
 cout<<"Enter ID: ";
 cin>>i;
 s.setid(i);
 cout<<"Enter Name: ";
 cin>>n;
 s.setname(n);
 cout<<"Enter Father Name: ";
 cin>>fn;
 s.setfather_name(fn);
 cout<<"Enter CGPA: ";
 cin>>age1;
 s.setage(age1);

 file.open("students.txt") ;
 file<<"\n"<<i<<" "<<n<<" "<<fn<<" "<<age1;

 file.close();
}

void show_all()
{
      system("CLS");
      string a;
      int k=0;
      string arr[40];

       ifstream mfile ("students.txt");
       while (!mfile.eof())
            {
                  getline (mfile,a);
                  int j = 0;
                  stringstream s(a);
                  while (s.good() && j < 4)
                       {
                            s >> arr[j];
                            ++j;
                       }
                  if(k!=0){cout<<"Number Of Student:"<<k;}
                  for(j = 0; j < 4; ++j)
                  {


                        if(arr[j]!="")
                           {
                              if(j==0)cout <<"\nID     :";
                              else if(j==1)cout <<"Name   :";
                              else if(j==2)cout <<"father Name :";
                              else if(j==3)cout <<"Age   :";
                              cout << arr[j] << endl;
                           }

                  }
                  k++;
            }
      mfile.close();
      cout<<"\n\n";
}
void searchStudent()
{
       string idno;
       int k=0;
       cout<<"Any Information of Students: ";
       cin>>idno;
       system("CLS");
       string a;
       int i=0;
       string arr[40];

       ifstream mfile ("students.txt");
       while (!mfile.eof())
            {
                  getline (mfile,a);
                  int j = 0;
                  stringstream s(a);
                  while (s.good() && j < 4)
                        {
                            s >> arr[j];
                            ++j;
                        }

                  if(idno==arr[i] ||idno==arr[i+1] ||idno==arr[i+2]||idno==arr[i+3])
                        {
                              cout<<"Student Details : "<<k;
                              for(j = 0; j < 4; ++j)
                                    {
                                          if(j==0)cout <<"\nID     :";
                                          else if(j==1)cout <<"Name   :";
                                          else if(j==2)cout <<"Father Name :";
                                          else if(j==3)cout <<"Age  :";
                                          cout<<arr[j]<< endl;

                                    }

                        }
            k++;

             }
      mfile.close();
      cout<<"\n\n";

}

int main()
{
      int option;

 while(1)
 {
  //cout<<"Enter 1 to Enter Record\n";
  cout<<"1.Show All Student Details\n";
  cout<<"2.Search Bar\n";
  //cout<<"Enter 4 to Exit\n";
  cout<<"\n\nChoice 1 or 2 : ";
  cin>>option;

  switch (option)
  {
   //case 1:
   // add();
   // cout<<"\n\nRecord Entered\n";
   // break;
   case 1:
    show_all();
    break;
   case 2:
    searchStudent();
    break;
   //case 4:
   // exit(0);
   // break;
  }
 }



       return 0;
}
