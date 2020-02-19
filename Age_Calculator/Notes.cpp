void create_product()
        {
        cout<<"\nPlease Enter The Product No. of The Product ";
        cin>>pno;
        cout<<"\n\nPlease Enter The Name of The Product ";
        gets(name);
        cout<<"\nPlease Enter The Price of The Product ";
        cin>>price;
        cout<<"\nPlease Enter The Discount (%) ";
        cin>>dis;
        }
    void show_product()
    {
        cout<<"\nThe Product No. of The Product : "<<pno;
        cout<<"\nThe Name of The Product : ";
        puts(name);
        cout<<"\nThe Price of The Product : "<<price;
        cout<<"\nDiscount : "<<dis;
    }
    int retpno()
    {
        return pno;
        }
    float retprice()
    {
        return price;
        }
    char* retname()
    {
        return name;
        }
    int retdis()
    {
        return dis;
        }
};
fstream fp;
product pr;
void write_product()
{
    fp.open("Shop.txt",ios::out|ios::app);
    pr.create_product();
    fp.write((char*)&pr,sizeof(product));
    fp.close();
    cout<<"\n\nThe Product Has Been Created ";
    getch();
}

void menu()
{
    system("cls");
    fp.open("Shop.txt",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
        cout<<"\n\n\n Program is closing ....";
        getch();
        exit(0);
    }
    cout<<"\n\n\t\tProduct MENU\n\n";
    cout<<"====================================================\n";
    cout<<"P.NO.\t\tNAME\t\tPRICE\n";
    cout<<"====================================================\n";
    while(fp.read((char*)&pr,sizeof(product)))
    {
        cout<<pr.retpno()<<"\t\t"<<pr.retname()<<"\t\t"<<pr.retprice()<<endl;
    }
    fp.close();
}
void delete_product()
{
    int no;
    system("cls");
    cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nPlease Enter The product no. of The Product You Want To Delete";
    cin>>no;
    fp.open("Shop.txt",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.txt",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&pr,sizeof(product)))
    {
        if(pr.retpno()!=no)
        {
            fp2.write((char*)&pr,sizeof(product));
        }
    }
    fp2.close();
    fp.close();
    remove("Shop.txt");
    rename("Temp.txt","Shop.txt");
    cout<<"\n\n\tRecord Deleted ..";
    getch();
}
void modify_product()
{
    int no,found=0;
    system("cls");
    cout<<"\n\n\tTo Modify ";
    cout<<"\n\n\tPlease Enter The Product No. of The Product";
    cin>>no;
    fp.open("Shop.txt",ios::in|ios::out);
    while(fp.read((char*)&pr,sizeof(product)) && found==0)
    {
        if(pr.retpno()==no)
        {
            pr.show_product();
            cout<<"\nPlease Enter The New Details of Product"<<endl;
            pr.create_product();
            int pos=-1*sizeof(pr);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&pr,sizeof(product));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
    }
    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getch();
}
