#include<fstream>
#include<string.h>
#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;

class student{
    protected:
    char name[40];
    char roll[10];
    char dep[5];
    char batch[5];
    void get(){
        system("cls");
        fflush(stdin);
        cout<<"\n\tEnter the Name: ";
        cin>>name;
        fflush(stdin);
        cout<<"\n\tEnter the Roll: ";
        cin>>roll;
        fflush(stdin);
        cout<<"\n\tEnter the Department: ";
        cin>>dep;
        fflush(stdin);
        cout<<"\n\tEnter the Batch: ";
        cin>>batch;

    }
};

class cgpa:protected student{
    private:
    char subname[10][20];
    char subcode[10][20];
    float gpa[10];
    float credit[10];
    float totalcredit;
    float subg[10];
    float total;
    int i;
    float grade;
    char gradeno[4];
    public:
    void getgpa();
    void file();
    void gra(float);
    };

void cgpa::gra(float k){
    while(1)
    {
        if(k<2.0)
        {
            strcpy(gradeno,"F");
            break;
        }
        else if(k<2.25)
        {
            strcpy(gradeno,"D" );
            break;
        }
        else if(k<2.5)
        {
            strcpy(gradeno,"c" );
            break;
        }
        else if(k<2.75)
        {
            strcpy(gradeno,"c+" );
            break;
        }
        else if(k<3.0)
        {
            strcpy(gradeno,"B-" );
            break;
        }
        else if(k<3.25)
        {
            strcpy(gradeno,"B" );
            break;
        }
        else if(k<3.5)
        {
            strcpy(gradeno,"B+" );
            break;
        }
        else if(k<3.75)
        {
            strcpy(gradeno,"A-" );
            break;
        }
        else if(k<4.0)
        {
            strcpy(gradeno,"A" );
            break;
        }
        else if(k==4)
        {
            strcpy(gradeno,"A+" );
            break;
        }

    }
}

void  cgpa::getgpa(){
    get();
    totalcredit =0;
    total=0;
    cout<<"\n\tHOW MANY SUBJECT IN HIS EXAM HE ATTEND: ";
    cin>>i;
    for(int j=0;j<i;j++)
    {
        fflush(stdin);
        cout<<"\n\t Enter the Subject Name: ";
        gets(subname[j]);
        fflush(stdin);
        cout<<"\n\t Enter the Subject Code: ";
        gets(subcode[j]);
        fflush(stdin);
        cout<<"\n\t Enter the Credit of that subject: ";
        cin>>credit[j];
        fflush(stdin);
        cout<<"\n\t Enter the GPA of that subject: ";
        cin>>gpa[j];

        totalcredit=totalcredit+credit[j];
        subg[j]=gpa[j]*credit[j];
        total=subg[j]+total;
    }

    grade=total/totalcredit;
    cout<<"\tRESULT: "<<grade;
    gra(grade);
    cout<<"\n\tGRADE: "<<gradeno;
    getch();

    fstream x("RESULT.txt",ios::app|ios::out);
    x<<endl<<name<<"\t"<<roll<<"\t"<<grade<<"\t"<<gradeno<<endl;
    x.close();

}

void cgpa::file()
{
    getgpa();
    ofstream out(roll);
    out<<"\n\tName: "<<name;
    out<<"\n\tRoll: "<<roll;
    out<<"\n\tDepartment: "<<dep;
    out<<"\n\tBatch: "<<batch;
    out<<"\n\n\n\tSubject name\t\t       Subject code\t\tCredit of that subject\t\t  GPA of that subject";
    for(int j=0;j<i;j++)
    {
        out<<"\n\t ";
        out<<subname[j];
        out<<"\t\t\t\t"<<subcode[j];
        out<<"\t\t\t\t" ;
        out<<credit[j];
        out<<"\t\t\t\t" ;
        out<<gpa[j];
    }
    out<<"\n\n\tTOTTAL CREDIT= "<<totalcredit;
    out<<"\n\n\tTOTAL GRADE POINT "<<grade;
    out<<"\n\n\tCGPA "<<gradeno<<endl;
    out.close();
}

int main()
{
    system("cls");
    int p;
    while(1)
    {
        system("cls");
        cout<<"\n\t1.  Input\n\n\t2.  Show\n\n\t3.  Search\n\n\t4.  Exit  \n\n";
        cout<<"\tEnter your choice(1-4) : ";
        cin>>p;
        if(p==1)
        {
            cgpa x;
            x.file();
        }
        if(p==2)
        {
            system("cls");
            fflush(stdin);
            cout<<"\n\tInput the Roll: ";
            char roll[20];
            cin>>roll;
            char c;
            system("cls");
            ifstream x(roll);
            while(x)
            {
                x.get(c);
                cout<<c;

            }
            getch();
        }
        if(p==3)
        {
            system("cls");
            char c;
            ifstream x("RESULT.txt");
            while(x)
            {
                x.get(c);
                cout<<c;
            }
            getch();

        }
        if(p==4)
            break;
        }

    return 0;
}
