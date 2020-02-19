int datecheck(char filename[])
{
    using namespace std;
    char a1[10]={},a2[10]={},a3[10]={};
    int len;
    len=strlen(filename);
    int i,j;
    if(len>10)
        {cout<<"invalid date format"<<endl;
        return 0;}
    int flag=1;
    j=0;
    int k=0,l=0;
    for(i=0;i<len;i++)
    {
        if((filename[i]>='0'&&filename[i]<='9')||filename[i]==45)
        {
            if(i==2&&filename[i]==45)
                {
                flag=2;
                ++i;
                }

            if(i==5&&filename[i]==45)
            {
                flag=3;
                ++i;

            }

            if(flag==1)
            {
                if(filename[i]>='0'&&filename[i]<='9')
                {

                a1[j]=filename[i];
                j++;
                }
                else
                {

                    return 0;
                }
            }
            a1[j]='\0';

            if(flag==2)
            {
                if(filename[i]>='0'&&filename[i]<='9')
                {

                a2[k]=filename[i];
                k++;
                }
                else
                {
//                    cout<<"invalid date format"<<endl;
                    return 0;
                }
            }
            a2[k]='\0';
            if(flag==3)
            {
                if(filename[i]>='0'&&filename[i]<='9')
                {

                a3[l]=filename[i];
                l++;
                }
                else
                {
//                    cout<<"invalid date format"<<endl;
                    return 0;
                }
            }
            a3[l]='\0';

        }
        else
            return 0;
    }

    int date=atoi(a1);
    int month=atoi(a2);
    int year=atoi(a3);
    int leap=0;
    int legit = 0;

    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        {leap=1;}

    if (month<13)
    {
       if (month == 1 || month==3 || month== 5 || month== 7 || month== 8 || month== 10 || month== 12 )
            {if (date <=31)
                {legit=1;}}
        else if (month == 4 || month== 6 || month== 9 || month== 11  )
            {if (date <= 30)
                {legit = 1;}}

        else
            {

                    if (leap == 0)
                            {{if (date <= 28)
                                    legit = 1;}}
                  if (leap == 1)
                            {if (date <= 29)
                                    {legit = 1;}}
             }

    }
    if(legit==1)
        return 1;
    else
        return 0;
}

int timecheck(char time[])
{
    char t1[5],t2[5];
    int len;
    len=strlen(time);
    int i,j;
    if(len>5)
        {
            return 0;
        }
    int flag=1;
    j=0;
    int k=0;
    for(i=0;i<len;i++)
    {
        if((time[i]>='0'&&time[i]<='9')||time[i]==46)
        {
            if(i==2&&time[i]==46)
                {
                flag=2;
                ++i;
                }
            if(flag==1)
            {
                if(time[i]>='0'&&time[i]<='9')
                {

                t1[j]=time[i];
                j++;
                }
                else
                {
                    return 0;
                }
            }
            t1[j]='\0';

            if(flag==2)
            {
                if(time[i]>='0'&&time[i]<='9')
                {

                t2[k]=time[i];
                k++;
                }
                else
                {
                    return 0;
                }
            }
            t2[k]='\0';

        }
        else
            return 0;
    }

    int hour=atoi(t1);
    int mnt=atoi(t2);

    int legit = 0;

    if(hour<=24)
        {
        legit=1;

        if(mnt<=60)
            legit=1;

        else
            legit=0;
        }

    if(legit==1)
        return 1;

    else
        return 0;
}
