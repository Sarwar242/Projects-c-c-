void bloodBank::loading()
{
    system("cls");
    for(int i=1; i<=50; i++)
    {
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t   Loading "<<'\n'<<'\t'<<'\t';
        for(int j=1; j<=i; j++)
            cout<<"*";
        cout<<"\n\n\t "<<2*i<<"%";
        if( i > 1 && i < 20)
            cout<<"\n\n\tCreating Temporary files";
        else if( i > 20 && i<40)
            cout<<"\n\n\tAccessing Main Memory";
        else if(i >40 && i<48)
            cout<<"\n\n\tAccessing Cache";
        else
            cout<<"\n\n\tComplete. Press Enter to Continue ";
    }
    getch();
}
