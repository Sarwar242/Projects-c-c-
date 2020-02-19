using namespace std;

void add_medicine();
struct detail{
    char name[100];
    char com[100];
    double price;
};

void add_medicine()
{
    FILE *fpd,*fc;
    char d[100];
    struct detail D;
    int i=1;

    fflush(stdin);
    cout<<"\n\tEnter the Name of the Medicine: ";
    cin>>D.name;

    fc = fopen("Medicine_For_Life.txt","r");
    while(fscanf(fc,"%s",d) != EOF)
    {
        i++;
    }
    fclose(fc);


    fflush(stdin);
    cout<<"\n\tEnter Company Name: ";
    cin>> D.com;

    fflush(stdin);
    cout<<"\n\tEnter Price: ";
    cin>>D.price;
    fpd=fopen("detail.txt","a+");
    fprintf(fpd,"\t%s\t\t\t\t %s\t\t\t\t%.2lf\n\n",D.name,D.com,D.price);
    rewind(fpd);
    fclose(fpd);
}


void infront()

{
    cout<<"\n\n\t\t\t\t Welcome To  Medicine For Life.\n"<<endl;

    cout<<"\t#  Press '1'  For Buying Medicine."<<endl;
    cout<<"\t#  Press '2'  For searching Medicine.\n"<<endl;
    cout<<"\t#  Press '3'  For Sell Record a Specific Date.\n"<<endl;
    cout<<"\t#  Press '4'  To Show Sell Record.\n"<<endl;
    cout<<"\t#  Press '5'  To Add Medicine.\n"<<endl;
    cout<<"\t#  Press '0'  For exit.\n"<<endl;
    cout<<"\n\tEnter Choice Keyword ::"<<endl;

}

void Medicine()
{
    FILE *pm;
    char pme[200];
    int i=1;

    cout<<"\n\tSelect Your Medicine\n\tPress '0' for Back\n"<<endl;
    pm = fopen("Medicine_For_Life.txt","r");

    while(fscanf(pm,"%s",pme) != EOF)
    {
        cout<<i<<". "<<pme<<endl;
        i++;
    }
    fclose(pm);
    cout<<"\n\tEnter Choice Keyword:: "<<endl;
}

void select(unsigned int a)
{
    FILE *me;
    char pme[500];
    switch(a)
    {
        case 1 : me = fopen("napa_extra.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 2 : me = fopen("saclo.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 3 : me = fopen("azithromicin.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 4 : me = fopen("ranidin.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 5 : me = fopen("cofe.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 6 : me = fopen("deleta.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 7 : me = fopen("cefaclav.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 8 : me = fopen("fenadine.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 9 : me = fopen("myolax.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 10: me = fopen("algin.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 11: me = fopen("omeprazole.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 12: me = fopen("pevisone.txt","r");
                    fgets(pme,150,me);
                    fclose(me);
                 break;
        case 13:
            cout<<"\n\tMedicine Name\t\t\tCompany Name\t\t\tPrice.\n\n"<<endl;
            me= fopen("detail.txt","r");
            while(!feof(me)){
                fgets(pme,150,me);
                puts(pme);
               }
            fclose(me);
            break;

    }
    if(a >= 1 && a <= 12)
    {
        cout<<"\n\tMedicine Name\t\t\tCompany Name\t\t\tPrice.\n\n"<<endl;
        puts(pme);

    }
    else if(a==13)
    {   getch();
        return;
    }
    else
        cout<<"\n\tWrong Keyword\n"<<endl;

    getch();

}
