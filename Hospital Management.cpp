#include<iostream>
using namespace std;
int nho=0;
class hospital
{
    protected:
    string ag;
    string hospital_name[50];
    string hospital_location[50];
    int total_beds[50];
    int occupied_beds[50];
    int available_beds[50];
    float ratings[50];
    long contact[50];
    public:
    void getdataH()
    {
        getline(cin,ag);
        int ch=0;
        cout<<"Enter the name of the hospital :\n";
        getline(cin,hospital_name[nho]);
        cout<<"Enter the location of the hospital :\n";
        getline(cin,hospital_location[nho]);
        cout<<"Enter the no. of beds :\n";
        cin>>total_beds[nho];
        cout<<"Enter the no. of available beds :\n";
        cin>>available_beds[nho];
        cout<<"Enter the rating of the hospital :\n";
        cin>>ratings[nho];
        cout<<"Enter the contact no of the hospital :\n";
        cin>>contact[nho];
        occupied_beds[nho]=total_beds[nho]-available_beds[nho];
        cout<<"Do you want to continue?\nEnter 1 for Yes\n      2 for No\n";
        cin>>ch;
        nho++;
            if(ch==1)
                getdataH();
    }
    void searchBed()
    {
        cout<<"Enter the no. of beds you need\n";
        int beds,count=0;
        cin>>beds;
        for(int i=0;i<nho;i++)
        {
            if(beds<=available_beds[i])
            {
                cout<<hospital_name[i]<<"\t\t\t"<<hospital_location[i]<<"\t\t\t"<<total_beds[i]<<"\t\t\t"<<available_beds[i]<<"\t\t\t"<<ratings[i]<<"\t\t\t"<<contact[i]<<endl;
                count=1;
            }
        }
        if(count==0)
        {
            cout<<"No such hospital found. Please try again.\n";
            searchBed();
        }
    }
    void searchname()
    {
        getline(cin,ag);
        cout<<"Enter the name of the hospital you want to search\n";
        string hn;
        int count;
        getline(cin,hn);
        for(int i=0;i<nho;i++)
        {
            if(hn==hospital_name[i])
            {
                cout<<"Name\t\t\tLocation\t\t\tTotal beds\t\t\tBeds Available\t\t\tRating\t\t\tContact\n";
                cout<<hospital_name[i]<<"\t\t\t"<<hospital_location[i]<<"\t\t\t"<<total_beds[i]<<"\t\t\t"<<available_beds[i]<<"\t\t\t"<<ratings[i]<<"\t\t\t"<<contact[i]<<endl;
                count=1;
            }
        }
        if(count==0)
        {
            cout<<"No such hospital found. Please try again.\n";
            searchname();
        }
    }
    void updateInfo()
    {
        int count=0;
        getline(cin,ag);
        cout<<"Which hospital do you want to update info of?\n";
        string hn;
        getline(cin,hn);
        for(int i=0;i<nho;i++)
        {
            if(hn==hospital_name[i])
            {
                cout<<"What do you want to update?\n1)Name of Hospital\n2)Location of the Hospital\n3)Total Number of Beds\n4)Occupied Beds\n5)Rating of the Hospital\n6)Contact Number of the Hospital"<<endl;
                int ch;
                cin>>ch;
                switch(ch)
                {
                    case 1:
                        cout<<"Enter the updated name of the hospital :\n";
                        getline(cin,hospital_name[i]);
                    break;
                    case 2:
                        cout<<"Enter the updated location of the hospital :\n";
                        getline(cin,hospital_location[i]);
                    break;
                    case 3:
                        cout<<"Enter the updated no. of beds :\n";
                        cin>>total_beds[i];
                    break;
                    case 4:
                        cout<<"Enter the updated no. of available beds :\n";
                        cin>>available_beds[i];
                    break;
                    case 5:
                        cout<<"Enter the updated rating of the hospital :\n";
                        cin>>ratings[i];
                    break;
                    case 6:
                        cout<<"Enter the updated contact no of the hospital :\n";
                        cin>>contact[i];
                    break;
                    default:
                        cout<<"Incorrect option selected please try again.\n";
                        updateInfo();
                }
                count++;
                break;
            }
        }
        if(count==0)
        {
            cout<<"The name you entered does not match any hospitals availabe. Please try again.";
            updateInfo();
        }

    }
    void displayH()
    {
        cout<<"Name\t\t\tLocation\t\t\tTotal beds\t\t\tBeds Available\t\t\tRating\t\t\tContact\n";
        for(int i=0;i<nho;i++)
            cout<<hospital_name[i]<<"\t\t\t"<<hospital_location[i]<<"\t\t\t"<<total_beds[i]<<"\t\t\t"<<available_beds[i]<<"\t\t\t"<<ratings[i]<<"\t\t\t"<<contact[i]<<endl;
    }
};
class patient:public hospital
{
    string patient_name[50][50];
    string patient_id[50][50];
    string patient_gender[50][50];
    string patient_blood_type[50][50];
    string patient_room[50][50];
    public:
    void getdataP()
    {
        getline(cin,ag);
        for(int i=0;i<nho;i++)
        {
            int ch=0;
            cout<<"\nEnter data of patients in "<<hospital_name[i];
            for(int j=0;j<occupied_beds[i];j++)
            {
                cout<<"\nPatient "<<j+1;
                cout<<"\nEnter the patient's name :\n";
                getline(cin,patient_name[i][j]);
                cout<<"Enter the patient's id :\n";
                getline(cin,patient_id[i][j]);
                cout<<"Enter the patient's gender :\n";
                getline(cin,patient_gender[i][j]);
                cout<<"Enter the patient's blood type :\n";
                getline(cin,patient_blood_type[i][j]);
                cout<<"Enter the patient's room number :\n";
                getline(cin,patient_room[i][j]);
            }
        }
    }
    void displaydataP()
    {
        getline(cin,ag);
        cout<<"Enter the hospital of which you want the patient data of :\n";
        string hpt;
        getline(cin,hpt);
        int count=0;
        for(int i=0;i<nho;i++)
        {
            if(hpt==hospital_name[i])
            {
                cout<<"Name\t\tID\t\tGender\t\tBlood Type\t\tRoom no.\n";
                for(int j=0;j<occupied_beds[i];)
                {
                    cout<<patient_name<<"\t\t"<<patient_id<<"\t\t"<<patient_gender<<"\t\t"<<patient_blood_type<<"\t\t"<<patient_room;
                }
                count=1;
                break;
            }
        }
        if(count==0)
        {
            cout<<"Please check if you entered the correct name of the hospital";
            displaydataP();
        }
    }
    void updateInfo()
    {
        cout<<"Do you want to update\n1)Hospital Data\n2)Patient Data?\n";
        int co;
        cin>>co;
        if(co==1)
        {
            hospital::updateInfo();
        }
        else
        {
            int count=0;
            getline(cin,ag);
        string hn,pn;
        cout<<"Which hospital is the patient in?\n";
        getline(cin,hn);
        for(int i=0;i<nho;i++)
        {
            if(hn==hospital_name[i])
            {
                cout<<"Enter the name of the patient you want to update the data of:\n";
                getline(cin,pn);
                for(int j=0;j<occupied_beds[i];j++)
                {
                    cout<<"What do you want to update?\n1)Name of the Patient\n2)ID of the Patient\n3)Gender of the Patient\n4)Blood type of the Patient\n5)Room no. of the Patient\n"<<endl;
                    int ch;
                    cin>>ch;
                    switch(ch)
                    {
                        case 1:
                            cout<<"Enter the updated name of the patient :\n";
                            getline(cin,patient_name[i][j]);
                        break;
                        case 2:
                            cout<<"Enter the updated ID of the Patient :\n";
                            getline(cin,patient_id[i][j]);
                        break;
                        case 3:
                            cout<<"Enter the updated gender of the Patient :\n";
                            getline(cin,patient_gender[i][j]);
                        break;
                        case 4:
                            cout<<"Enter the updated blood type of the Patient :\n";
                            getline(cin,patient_blood_type[i][j]);
                        break;
                        case 5:
                            cout<<"Enter the updated Room No. of the Patient :\n";
                            getline(cin,patient_room[i][j]);
                        break;
                        default:
                            cout<<"Incorrect option selected please try again.\n";
                            updateInfo();
                    }
                    count++;
                    break;
                    }
                }
            }
        }
    }
};
int main()
{
    patient p;
    p.getdataH();
    p.getdataP();
    int cont=1;
    while(cont!=0)
    {
        cout<<"What do you want to do?\n1)Search hospital by name\n2)Search hospitals by available beds\n3)Display hospitals\n4)Update data of a patient\n5)Display data of patients at a hospital\n";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1:
                p.searchname();
            break;
            case 2:
                p.searchBed();
            break;
            case 3:
                p.displayH();
            break;
            case 4:
                p.updateInfo();
            break;
            case 5:
                p.displaydataP();
            break;
            default:
                cout<<"Wrong choice entered";
        }
        cout<<"Do you want to continue?\n Enter 1 for Yes\n      2 for No\n";
        cin>>cont;
    }
}
