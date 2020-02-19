#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include"medical_store.h"

using namespace std;
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct medical
{
	char id[6];
	char medi_name[20];
	int rack;
	char cabnit[2];
	int quantity;
	float sale;
	float total;
	float unit;
	float cost;
	float profit;
	float bye;
	int qty;
	char pur_date[15];
	char exp_date[15];
	char manu_date[15];
	int bill_no;
	char comp_name[20];
	char supp_name[30];
 };

struct medical temp;
struct medical x[20];
FILE *ptr;

char a[10];

struct sales_report
{
	char medi_id[6];
	char medir_name[20];
	char cust_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct sales_report s_r;
FILE *ptrs_r;

struct customer
{
	int cust_id;
	char cust_name[30];
	char city[20];
	char mob_no[11];
	char email[50];

};
struct customer temp_c;
FILE *ptr1;


struct purchase_report
{
	char medi_id[6];
	char medir_name[20];
	char supp_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct purchase_report p_r;
FILE *ptrp_r;
struct bill
{
	char billno[6];
	char cname[30];
	char mediname[30];
	int medi_qty;
	float medi_rate;
	float total;
	int day;
	int month;
	int year;

};

struct bill bil;
FILE *ptrbill;

void linkfloat()
{
	float f,*p;
	p=&f;
	f=*p;
}

medical_store::t()
{

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    //getdate(&d);
    //gettime(&t);
    gotoxy(55,1);
    printf("Date: %d-%d-%d ",now->tm_mday,now->tm_mon,now->tm_year);
    gotoxy(55,2);
    printf("Time: %d:%d:%d",now->tm_hour, now->tm_min,now->tm_sec);
    return 0;
}

void medical_store::animation()
{
    for (int i=45; i>=1; i--)
    {
        Sleep(30);
        gotoxy(1,i);
    }
    for (int i=1; i<=20; i++)
    {
        Sleep(40);
        gotoxy(1,i);
    }
}
void medical_store::medicine()
{
    char ch;
    do
    {
        system("cls");

        gotoxy(34,3);
        printf("---------------");
        gotoxy(35,4);
        printf("Medicine Menu.");
        gotoxy(34,5);
        printf("---------------");
        gotoxy(25,15);
        printf("P");
        gotoxy(26,15);
        printf("urchase New Medicine");
        gotoxy(25,19);
        printf("S");
        gotoxy(26,19);
        printf("ale Medicine");

        gotoxy(25,23);
        printf("Sto");
        gotoxy(28,23);
        printf("c");
        gotoxy(29,23);
        printf("k of Medicine");
        gotoxy(28,27);
        //textcolor(15);
        printf("Search Medicine");
        gotoxy(26,31);
        //textcolor(15);
        printf("Main Menu");
        gotoxy(10,40);
        //textcolor(15);
        printf("Press First Character for further Operations  ");


        ch=toupper(getche());
        switch(ch)
        {
        case 'P':
            medi_entry();
            break;
        case 'S':
            medi_sale();
            break;
        case 'C':
            stock();
            break;
        case 'A':
            medi_search();
            break;
        case 'M':
            main_menu();
            break;
        default://textcolor(4+BLINK);
            gotoxy(11,34);
            printf("Plese Enter right character ONLY (P,S,C,M).");
            getch();
        }
    }
    while(ch!='M');

}
void ventry(char t[],int code)
{
  int i=0;
	if(code==0)
	{
		while((t[i]=getch())!='\r' && i<30)
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='_')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}
	else if(code==1)
	{
		while((t[i]=getch())!='\r' && i<10 )
		if((t[i]>=48 && t[i]<=57) || t[i]==46 ||  t[i]=='-')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}
	else if(code==2)
	{
		while((t[i]=getch())!='\r' && i<30 )
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) ||(t[i]>=48 && t[i]<=57) || t[i]==32 || t[i]==8 ||t[i]=='@'||t[i]=='.')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}

	t[i]='\0';
}

void medical_store::medi_entry()
{
    char ch,id[6];
//  struct date d;
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    int f;
    FILE *fp;
    system("cls");
    //getdate(&d);

    ptrp_r=fopen("purreport.dat","a");
    ch='Y';
    while(ch=='Y')
    {
        system("cls");
        gotoxy(30,8);
        ////textcolor(GREEN+BLINK);
        printf(" MEDICINE PURSHASE  ");
        {
            //textcolor(WHITE);
            gotoxy(7,11);
            printf("MEDICINE ID    : ");

            gotoxy(40,11);
            printf("MEDICINE NAME  : ");

            gotoxy(7,14);
            printf("ENTER RACK NO  : ");

            gotoxy(40,14);
            printf("CABNIT NO      : ");

            gotoxy(7,18);
            printf("COMPANY NAME   : ");

            gotoxy(40,18);
            printf("SUPPLIER NAME  : ");

            gotoxy(7,21);
            printf("UNIT COST   Rs.:  ");

            gotoxy(40,21);
            printf("SALE COST   Rs.: ");

            gotoxy(7,24);
            printf("QUANTITY       :  ");

            gotoxy(7,27);
            printf("MFG.DATE(dd-mm-yyyy): ");

            gotoxy(7,29);
            printf("EXP.DATE(dd-mm-yyyy): ");

            gotoxy(25,11);
            ventry(temp.id,1);
            strcpy(id,temp.id);

            fp=fopen("medical.dat","r");
            while((fread(&temp,sizeof(temp),1,fp))==1)
            {

                if(strcmp(id,temp.id)==0)
                {
                    f=1;
                    break;
                }
            }
            fclose(fp);
            if(f==1)
            {
                gotoxy(20,31);
                printf("ID Allready Exists");
                getche();
                system("cls");
                medi_entry();
            }
            else
            {
                ptr=fopen("medical.dat","a+b");
                strcpy(temp.id,id);
                strcpy(p_r.medi_id,temp.id);
            }
            //flushall();
            gotoxy(58,11);
            ventry(temp.medi_name,0);
            strcpy(p_r.medir_name,temp.medi_name);
            //flushall();
            gotoxy(25,14);
            ventry(a,1);
            temp.rack= atoi(a);//atoi() used for convert str to int.
            //flushall();
            gotoxy(58,14);
            ventry(temp.cabnit,2);
            //flushall();
            gotoxy(25,18);
            ventry(temp.comp_name,0);
            //flushall();
            gotoxy(58,18);
            ventry(temp.supp_name,0);
            strcpy(p_r.supp_name,temp.supp_name);
            //flushall();
            gotoxy(25,21);
            ventry(a,1);
            temp.unit= atof(a);
            //flushall();
            p_r.rate=temp.unit;
            gotoxy(58,21);
            ventry(a,1);
            temp.sale= atof(a);
            //flushall();
            gotoxy(25,24);
            ventry(a,1);
            temp.quantity= atoi(a);
            p_r.qty=temp.quantity;
            //flushall();
            gotoxy(29,27);
            //flushall();
            ventry(temp.manu_date,1);
            gotoxy(29,29);
            //flushall();
            ventry(temp.exp_date,1);

            gotoxy(7,31);
            printf("==========================================================");
            temp.total=temp.quantity*temp.sale;

            //textcolor(10);
            gotoxy(10,33);
            printf("TOTAL SALE COST = Rs. %.2f",temp.total);
            temp.cost=(temp.unit*temp.quantity);
            gotoxy(40,33);
            printf("TOTAL UNIT COST = Rs. %.2f",temp.cost);
            p_r.total=temp.cost;
            p_r.sDay=now->tm_mday;
            p_r.sMonth=now->tm_mon;
            p_r.sYear=now->tm_year;
        }
        gotoxy(20,35);
        //textcolor(RED+BLINK);
        printf("S");
        //textcolor(WHITE);
        gotoxy(21,35);
        printf("ave");
        gotoxy(28,35);
        //textcolor(RED+BLINK);
        printf("C");
        //textcolor(WHITE);
        gotoxy(29,35);
        printf("ancel");
        gotoxy(18,38);
        printf("Press First charecter for the operation : ");


        ch=toupper(getche());

        if(ch=='S')
        {
            fwrite(&temp,sizeof(temp),1,ptr);
            fflush(stdin);
            //textcolor(10);
            fprintf(ptrp_r,"%s %s %s %d %.2f %.2f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,p_r.qty,p_r.rate,p_r.total,p_r.sDay,p_r.sMonth,p_r.sYear);
            system("cls");
            gotoxy(20,20);
            printf("Medicine Added sucessfully!!!!!!");
            gotoxy(20,25);
            printf("More entries  [y/n]");
            ch=toupper(getche());
            /*	if(ch=='Y')
            {
            	system("cls");
            	medi_entry();
            }*/
        }

    }
    fclose(ptr);
    fclose(ptrp_r);
}
FILE *ptrpr_r;
//===========FOR MEDICINE SALE=========================
void medical_store::medi_sale()
{
    struct bill bil;
    //struct date d;
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    int j,n,i,a;
    int d1,m,y;
    float b;
    char tar[30],ch,c_name[30];
    FILE *fp;
    int count=0;
    //getdate(&d);
    d1=now->tm_mday;
    m=now->tm_mon;
    y=now->tm_year;
    ch='y';
    while(ch=='y')
    {
        fp = fopen("dbbill.dat","a");
        ptr1 = fopen("customer.dat","r");
        ptr = fopen("medical.dat","r");
        ptrs_r=fopen("saleRpt.dat","a");
        ptrpr_r=fopen("profitRpt.dat","a");
        system("cls");
        for(i=3; i<=45; i++)    //This 'FOR' loop will print asteriks 'I'
        {
            //vertically till the 3th row is reached.
            gotoxy(50,i);
            printf("%c",219);
        }
        i=9;
        gotoxy(52,7);
        printf("Cust_ID    Cust_Name");
        //flushall();
        while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
        {
            gotoxy(53,i);
            printf("%d",temp_c.cust_id);
            gotoxy(64,i);
            printf("%s",temp_c.cust_name);
            i+=2;
        }

        gotoxy(9,7);
        printf("ENTER MEDICINE ID TO BE SOLD  : ");
        ventry(tar,1);
        //scanf("%s",&tar);
        j=0;
        while((fread(&temp,sizeof(temp),1,ptr))==1)
        {
            if((strcmp(temp.id,tar)<0) || (strcmp(temp.id,tar)>0))
            {
                x[j] = temp;
                j++;
            }
            else if((strcmp(temp.id,tar)==0))
            {

                gotoxy(8,10);
                printf(" Medicine Name        : %s",temp.medi_name);
                gotoxy(8,12);
                printf(" Quantity in stock    : %d",temp.quantity);
                gotoxy(8,14);
                printf(" Sales price          : %.2f",temp.sale);
                gotoxy(8,16);
                printf("Enter bill number     : ");
                //flushall();
                ventry(bil.billno,1);
                //scanf("%s",&bil.billno);
                gotoxy(8,18);
                printf("Enter customer Name   : ");
                //flushall();
                ventry(c_name,0);
                //scanf("%s",&c_name);
                gotoxy(8,20);
                printf("Quantity want to sale : ");
//                ventry(a,1);
                cin>>a;

//                pr_r.profit=(temp.sale-temp.unit)*a;
                x[j]=temp;
                x[j].quantity=(x[j].quantity-a);
                x[j].total=(x[j].quantity*temp.sale);
                x[j].cost=(x[j].quantity*temp.unit);
                x[j].bye=(x[j].sale*a);
                b=x[j].bye;
                x[j].qty=a;
                j++;
                count++;
                strcpy(bil.cname,c_name);
                strcpy(s_r.cust_name,c_name);
                strcpy(bil.mediname,temp.medi_name);
                bil.medi_qty=a;
                bil.medi_rate=temp.sale;
                bil.total=temp.sale*a;

                bil.day=d1;
                bil.month=m;
                bil.year=y;

                fprintf(fp,"%s %s %s %d %.2f %.2f %d %d %d\n",bil.billno,bil.cname,bil.mediname,bil.medi_qty,bil.medi_rate,bil.total,bil.day,bil.month,bil.year);
                fflush(stdin);

                fclose(fp);

                s_r.sDay=d1;
                s_r.sMonth=m;
                s_r.sYear=y;
                strcpy(s_r.medi_id,tar);
                strcpy(s_r.medir_name,temp.medi_name);
                s_r.qty=a;
                s_r.rate=temp.sale;
                s_r.total=temp.sale*a;

                //sale report
                fprintf(ptrs_r,"%s %s %s %d %.2f %.2f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,s_r.qty,s_r.rate,s_r.total,s_r.sDay,s_r.sMonth,s_r.sYear);
                fflush(stdin);
                fclose(ptrs_r);
                //profit report

//                pr_r.sDay=d1;
//                pr_r.sMonth=m;
//                pr_r.sYear=y;
//                strcpy(pr_r.medi_id,tar);
//                strcpy(pr_r.medir_name,temp.medi_name);
//                pr_r.qty=a;
//                pr_r.rate=temp.sale;
//                pr_r.unit=temp.unit;
//                fprintf(ptrpr_r,"%s %s %d %d %d %d %.2f %.2f  %.2f\n",pr_r.medi_id,pr_r.medir_name,d1,pr_r.sMonth,pr_r.sYear,pr_r.qty,pr_r.unit,pr_r.rate,pr_r.profit);
//                fflush(stdin);
//                fclose(ptrpr_r);

            }
        }
        if (count==0)
        {
            system("cls");
            gotoxy(33,10);
            printf("Not in stock!!!!!");
            getch();
            return;
        }
        fclose(ptr1);
        fclose(ptr);
        n = j;
        system("cls");
        ptr=fopen("medical.dat","wb");
        for(i=0; i<n; i++)
            fwrite(&x[i],sizeof(x[i]),1,ptr);
        fclose(ptr);
        system("cls");
        gotoxy(8,15);
        printf("* Price paid by customer = %.2f",b);
        gotoxy(8,17);
        printf("* Quantity sold          = %d",a);
        getch();
        gotoxy(10,20);
        printf("more enteries=(y/n) :");
        ch=getche();
    }

}

void medical_store::stock()
{
    int i,c;
    do
    {
        system("cls");
        ptr1=fopen("medical.dat","r");
        if(ptr1==NULL)
        {
            printf("\n\t Can not open File! ");
            exit(1);
        }
        system("cls");
        gotoxy(30,8);
        ////textcolor(GREEN+BLINK);
        printf(" STOCK OF MEDICINE ");
        //textcolor(WHITE);
        i=14;
        gotoxy(9,10);
        printf("ID.   MEDICINE NAME.    QTY     Supplier Name     Exp.Date");
        gotoxy(9,12);
        printf("==================================================================\n");

        while((fread(&temp,sizeof(temp),1,ptr1))==1)
        {
            gotoxy(9,i);
            printf(" %s",temp.id);
            gotoxy(15,i);
            printf(" %s",temp.medi_name);
            gotoxy(32,i);
            printf(" %d",temp.quantity);
            gotoxy(43,i);
            printf(" %s",temp.supp_name);
            gotoxy(60,i);
            printf(" %s",temp.exp_date);
            i++;
        }
        gotoxy(10,42);
        printf("Press [1] for Update Medicine Stock  & [0] for main menu ");
        c = (getche());
        switch (c)
        {
        case '0':
            animation();
            main_menu();
            break;
        case '1':
            update_stock();
            break;
        }

    }
    while(c != '1');
    getche();
}

void medical_store::medi_search()
{
    char mid[6];
    int i;
    system("cls");
    ptr1=fopen("medical.dat","r");
    if(ptr1==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    system("cls");
    gotoxy(10,7);
    printf("Enter Medicine Id to be searched : ");
    scanf("%s",mid);
    system("cls");

    gotoxy(30,8);
    //textcolor(GREEN+BLINK);
    printf(" MEDICINE ");
    //textcolor(WHITE);
    i=14;
    gotoxy(9,10);
    printf("ID.   MEDICINE NAME.    QTY     Supplier Name     Exp.Date");
    gotoxy(9,12);
    printf("==================================================================\n");
    while((fread(&temp,sizeof(temp),1,ptr1))==1)
    {
        if(strcmp(mid,temp.id)==0)
        {
            gotoxy(9,i);
            printf(" %s",temp.id);
            gotoxy(15,i);
            printf(" %s",temp.medi_name);
            gotoxy(32,i);
            printf(" %d",temp.quantity);
            gotoxy(43,i);
            printf(" %s",temp.supp_name);
            gotoxy(60,i);
            printf(" %s",temp.exp_date);
            i++;
            break;
        }

    }
    if(strcmp(mid,temp.id)!=0)
    {
        gotoxy(20,20);
        printf("Not in Stock.....");
    }
    getche();

}

void medical_store::update_stock()
{
    char mid[6];
    int j,a,count=0,n;
    system("cls");
    ptr=fopen("medical.dat","rb");
    if(ptr==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    system("cls");
    gotoxy(20,45);
    printf("Press Enter to go to MENU ...........");
    gotoxy(27,8);
    printf(" UPDATE MEDICINE QUANTITY ");
    gotoxy(9,10);
    printf("Enter medicine id to be update qty: ");
    scanf("%s",mid);
    j=0;

    while((fread(&temp,sizeof(temp),1,ptr))==1)
    {
        if((strcmp(temp.id,mid)<0) || (strcmp(temp.id,mid)>0))
        {
            x[j] = temp;
            j++;
        }
        else
        {
            gotoxy(8,12);
            printf("Medicine Name     : %s",temp.medi_name);
            gotoxy(8,14);
            printf("Quantity in stock : %d",temp.quantity);
            gotoxy(8,16);
            printf("Quantity want to update : ");
            scanf("%d",&a);
            x[j]=temp;
            x[j].quantity=(x[j].quantity+a);
            x[j].total=(x[j].quantity*temp.sale);
            x[j].cost=(x[j].quantity*temp.unit);
            x[j].bye=(x[j].sale*a);
            x[j].qty=a;
            j++;
            count++;
        }
    }
    if (count==0)
    {
        system("cls");
        gotoxy(33,10);
        printf("Not in stock!!!!!!");
        getch();
        return;
    }
    fclose(ptr);
    n = j;
    system("cls");
    ptr=fopen("medical.dat","wb");
    for(int i=0; i<n; i++)
        fwrite(&x[i],sizeof(x[i]),1,ptr);
    fclose(ptr);
}


void medical_store::report_menu()
{
    char ch;
    do
    {
        system("cls");

        gotoxy(34,3);
        printf("---------------");
        gotoxy(35,4);
        printf("Report Menu.");
        gotoxy(34,5);
        printf("---------------");
        gotoxy(25,12);
        //textcolor(4+BLINK);
        printf("P");
        gotoxy(26,12);
        //textcolor(15);
        printf("urchase Report");

        gotoxy(25,16);
        //textcolor(4+BLINK);
        printf("S");
        gotoxy(26,16);
        //textcolor(15);
        printf("ale Report");

        gotoxy(25,20);
        //textcolor(15);
        printf("Pr");
        gotoxy(27,20);
        //textcolor(4+BLINK);
        printf("o");
        gotoxy(28,20);
        //textcolor(15);
        printf("fit Report");

        gotoxy(25,24);
        //textcolor(15);
        printf("D");
        gotoxy(26,24);
        //textcolor(4+BLINK);
        printf("a");
        gotoxy(27,24);
        //textcolor(15);
        printf("ily Sale Report");

        gotoxy(25,28);
        //textcolor(4+BLINK);
        printf("D");
        gotoxy(26,28);
        //textcolor(15);
        printf("aily Purchase Report");

        gotoxy(25,32);
        //textcolor(4+BLINK);
        printf("M");
        gotoxy(26,32);
        //textcolor(15);
        printf("ain Menu");
        gotoxy(10,40);
        //textcolor(15);
        printf("Press First Character for further Operations  ");


        ch=toupper(getche());
        switch(ch)
        {
        case 'P':
            pur_rpt();
            break;
        case 'S':
            sale_rpt();
            break;
        case 'A':
            sale_rpt_daily();
            break;
        case 'M':
            main_menu();
            break;
        default://textcolor(4+BLINK);
            gotoxy(11,34);
            printf("Plese Enter right character ONLY (P,S,M).");
            getch();
        }
    }
    while(ch!='M');

}

void medical_store::sale_rpt()
{
    int j;
    system("cls");
    ptrs_r=fopen("saleRpt.dat","r");
    if(ptrs_r==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    system("cls");
    gotoxy(20,50);
    printf("Press any key to go to REPORT MENU ...........");
    gotoxy(30,8);
    ////textcolor(GREEN+BLINK);
    printf("Sales Report");
    //textcolor(WHITE);
    gotoxy(7,10);
    printf("ID. Medicine Name.  Customer Name.   Qty.  Rate.  Total.   Date");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
    {
        gotoxy(6,j);
        printf("%s",s_r.medi_id);
        gotoxy(11,j);
        printf("%s",s_r.medir_name);
        gotoxy(28,j);
        printf("%s",s_r.cust_name);
        gotoxy(44,j);
        printf("%d",s_r.qty);
        gotoxy(50,j);
        printf("%.2f",s_r.rate);
        gotoxy(57,j);
        printf("%.2f",s_r.total);
        gotoxy(65,j);
        printf("%d-%d-%d",s_r.sDay,s_r.sMonth,s_r.sYear);
        j=j+2;
    }
    getche();
}

void medical_store::sale_rpt_daily()
{
    int j,d,m,y;
    float total=0.00;
    system("cls");
    ptrs_r=fopen("saleRpt.dat","r");
    if(ptrs_r==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    system("cls");
    gotoxy(15,10);
    printf("Enter Date(dd-mm-yyyy):  ");
    scanf("%d-%d-%d",&d,&m,&y);
    system("cls");
    gotoxy(20,50);
    printf("Press any key to go to REPORT MENU ...........");
    gotoxy(30,8);
    printf("Sales Report");
    gotoxy(7,10);
    printf("ID. Medicine Name.  Customer Name.   Qty.  Rate.  Total.   Date");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
    {
        if(d==s_r.sDay &&m== s_r.sMonth && y==s_r.sYear)
        {
            gotoxy(6,j);
            printf("%s",s_r.medi_id);
            gotoxy(11,j);
            printf("%s",s_r.medir_name);
            gotoxy(28,j);
            printf("%s",s_r.cust_name);
            gotoxy(44,j);
            printf("%d",s_r.qty);
            gotoxy(50,j);
            printf("%.2f",s_r.rate);
            gotoxy(57,j);
            printf("%.2f",s_r.total);
            gotoxy(65,j);
            printf("%d-%d-%d",s_r.sDay,s_r.sMonth,s_r.sYear);
            j=j+2;
            total=total+s_r.total;
        }
    }
    gotoxy(7,42);
    printf("-------------------------------------------------------------------");
    gotoxy(45,43);
    printf("Total:        %.2f",total);
    getche();
}

void medical_store::pur_rpt()
{
    int j;
    system("cls");
    t();
    ptrp_r=fopen("purreport.dat","r");
    if(ptrp_r==NULL)
    {
        printf("\n\t Can not open File! ");
        exit(0);
    }
    gotoxy(20,50);
    printf("Press Enter to go to REPORT MENU ...........");

    gotoxy(30,8);
    printf("Purchase Report");
    gotoxy(7,10);
    printf("ID. Medicine Name.  Supplier Name.   Qty.  Rate.  Total.   Date");
    gotoxy(7,12);
    printf("===================================================================");
    j=14;
    while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
    {
        gotoxy(6,j);
        printf("%s",p_r.medi_id);
        gotoxy(11,j);
        printf("%s",p_r.medir_name);
        gotoxy(28,j);
        printf("%s",p_r.supp_name);
        gotoxy(44,j);
        printf("%d",p_r.qty);
        gotoxy(50,j);
        printf("%.2f",p_r.rate);
        gotoxy(57,j);
        printf("%.2f",p_r.total);
        gotoxy(65,j);
        printf("%d-%d-%d",p_r.sDay,p_r.sMonth,p_r.sYear);
        j+=2;
    }
    getche();
}


void medical_store::about()
{
    int c;
    system("cls");

    do
    {
//   window(1,1,80,50);

        //textcolor(LIGHTGRAY);
        gotoxy(28,4);
        //textcolor(RED+BLINK);
        printf("***** MEDICAL STORE *****");
        gotoxy(10,8);
        printf("=> This Project Is About Medical Store ");
        gotoxy(10,10);
        printf("=> In This Project we Can Add Medicine ,Customer,Supplier Details");
        gotoxy(10,12);
        printf("=> We Can Modifed & Delete Existing Record");
        gotoxy(10,14);
        printf("=> We Can Also Search Medicine ,Customer,Supplier Details");
        gotoxy(10,16);
        printf("=> It's Helpfull For Display Stock Of Medicine ");

        printf("<<<<-Press 1 for main menu->>>>");
        c = (getche());

        switch (c)      //This 'SWITCH' structure will ask the user for input from [1] to [7] and will display error on Invalid Entry.
        {
        case '1':
            animation();
            main_menu();
            gotoxy(26,24);
            puts("<<--ENTER FROM 1 PLEASE-->>");	//This message will only print on INVALID ENTRY and Will ask again for input.
            getch();
        }

    }
    while(c != '1');

}

void medical_store::main_menu()
{
    char ch;

    do
    {
        system("cls");
         t();
        cout<<"\n\n\n\n\t\t***Welcome To Medical Store*** "<<endl;
        cout<<"\n\t\t==========================================="<<endl;

        cout<<"\n\t\tMedicine"<<endl;
        cout<<"\n\t\tReport"<<endl;
        cout<<"\n\t\tAbout"<<endl;
        cout<<"\n\t\tExit"<<endl;
           //this function display date & time

        cout<<"\n\t\tPress First Character for further Menu  :  ";

        ch=toupper(getche());
        switch(ch)
        {
        case 'M':
            medicine();
            break;
        case 'R':
            report_menu();
            break;
        case 'A':
            about();
            break;
        case 'E':
            cout<<"\n\t\tDo you want to exit now? Y/N : ";
            Sleep(100);
            ch=(getche());
            ch=toupper(ch);
            if(ch=='Y')
            {
                animation();
                system("cls");
                cout<<"\n\t\t Please wait.....";
                Sleep(2000);
                exit(0);
            }
            else
            {
                main_menu();
            }

        default:
            cout<<"\n\n\t\t\t[Plese Enter right character ONLY (M,R,A).]";
            getch();
        }
    }
    while(ch!='E');
}
