#include<iostream>
#include<string.h>
using namespace std;
int n=0,m=0,ch;
class Inventory
{
        string ag;
        string name[1000];
        string author[1000];
        string publisher[1000];
        int mrp[10000];
        int quantity[10000];
    public:
    void add()
    {
        getline(cin,ag);
        cout<<"Enter the name of the book :\n";
        getline(cin,name[n]);
        cout<<"Enter the name of it's author :\n";
        getline(cin,author[n]);
        cout<<"Enter the name of the publisher :\n";
        getline(cin,publisher[n]);
        cout<<"Enter the price of the book :\n";
        cin>>mrp[n];
        cout<<"Enter the quantity of the books :\n";
        cin>>quantity[n];
        n+=1;
        cout<<"Do you want to enter another book?\nEnter 1 for Yes\n      2 for No\n";
        int cho;
        cin>>cho;
        if(cho==1)
            add();
    }
    void display()
    {
        cout<<"Name\t\tAuthor\t\tPublisher\t\tPrice\t\tQuantity\n";
        for(int i=0;i<n;i++)
        {
            cout<<name[i]<<"\t\t"<<author[i]<<"\t\t"<<publisher[i]<<"\t\t\t"<<mrp[i]<<"\t\t"<<quantity[i]<<endl;
            cout<<endl;
        }
    }
    void purchase()
    {
        getline(cin,ag);
        string auth,namee;
        cout<<"Enter the name and author of the book to be purchased :\n";
        getline(cin,namee);
        getline(cin,auth);
        for(int j=0;j<=n;j++)
        {
            if(namee==name[j]&&auth==author[j])
            {
                cout<<"Name\t\tAuthor\t\tPublisher\t\tPrice\t\tQuantity\n";
                cout<<name[j]<<"\t\t"<<author[j]<<"\t\t"<<publisher[j]<<"\t\t\t"<<mrp[j]<<"\t\t"<<quantity[j]<<"\n\n";
                cout<<"Do you want to purchase this book?\nEnter 1 for Yes\n      2 for No\n";
                int cho;
                cin>>cho;
                if(cho==1)
                {
                    cout<<"Enter the number of books you want to purchase:\n";
                    int quan;
                    cin>>quan;
                    if(quan<=quantity[j])
                    {
                        cout<<"Your total bill is Rs. "<<(quan*mrp[j])<<"\nThank You for your purchase\n";
                        quantity[j]-=quan;
                    }
                    else
                    {
                        cout<<"Your desired quantity exceeds the available quantity.\nPlease try again\n";
                        purchase();
                    }
                }
                break;
            }
            else
            {
                cout<<"Book not available\nPlease try another book:\n";
                purchase();
            }
        }
    }
    void update()
    {
        string auth,namee;
        getline(cin,ag);
        cout<<"Enter the name and author of the book to be edited :\n";
        getline(cin,namee);
        getline(cin,auth);
        for(int j=0;j<=n;j++)
        {
            if(namee==name[j]&&auth==author[j])
            {
                cout<<"Name\t\tAuthor\t\tPublisher\t\tPrice\t\tQuantity\n";
                cout<<name[j]<<"\t\t"<<author[j]<<"\t\t"<<publisher[j]<<"\t\t\t"<<mrp[j]<<"\t\t"<<quantity[j]<<"\n\n";
                cout<<"Do you want to edit this book?\nEnter 1 for Yes\n      2 for No\n";
                int cho;
                cin>>cho;
                if(cho==1)
                {
                    cout<<"What do you want to change about the book? \n1.Name of the book \n2.Name of the author \n3.Name of the publisher \n4.Price of the book \n5.Quantity available\n";
                    int ch;
                    cin>>ch;
                    switch(ch)
                    {
                        case 1:
                            getline(cin,ag);
                            cout<< "Enter the changed Name\n";
                            getline(cin,name[j]);
                            break;
                        case 2:
                            getline(cin,ag);
                            cout<< "Enter the changed Author Name\n";
                            getline(cin,author[j]);
                            break;
                        case 3:
                            getline(cin,ag);
                            cout<< "Enter the changed name of the Publisher\n";
                            getline(cin,publisher[j]);
                            break;
                        case 4:
                            getline(cin,ag);
                            cout<< "Enter the changed Price\n";
                            cin>>mrp[j];
                            break;
                        case 5:
                            getline(cin,ag);
                            cout<< "Enter the change in the available quantity\n";
                            cin>>quantity[j];
                            break;
                        default:
                            cout<<"Invalid choice\n";
                    }
                    break;
                }
            }
            else
            {
                cout<<"Book not available\n";
            }
        }
    }
    void search1()
    {
        string auth,namee;
        getline(cin,ag);
        cout<<"Enter the name and author of the book to be searched :\n";
        getline(cin,namee);
        getline(cin,auth);
        int c=0;
        for(int j=0;j<=n;j++)
        {
            if(namee==name[j]&&auth==author[j])
            {
                cout<<"Name\t\tAuthor\t\tPublisher\t\tPrice\t\tQuantity\n";
                cout<<name[j]<<"\t\t"<<author[j]<<"\t\t"<<publisher[j]<<"\t\t\t"<<mrp[j]<<"\t\t"<<quantity[j]<<"\n\n";
                c=0;
                break;
            }
            else
                c=1;

        }
        if(c==1)
            cout<<"Book not available\n";
    }
};

int main()
{
    Inventory invent;
    while(m!=1)
    {
        cout<<"What do You Want To Do?\n1.Input New Books In The System \n2.Display The Available Books \n3.Purchase a Book \n4.Update The Current List\n5.Search for a book\n6.Exit\n";
        cin>>ch;
        if(ch==6)
            break;
        else
        {
            switch(ch)
            {
                case 1: invent.add();break;
                case 2: invent.display();break;
                case 3: invent.purchase();break;
                case 4: invent.update();break;
                case 5: invent.search1();break;
                default:
                cout<<"Invalid choice. Enter another option\n";
            }
        }

    }
    return 0;
}
