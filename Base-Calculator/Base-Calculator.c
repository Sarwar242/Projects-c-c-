#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
void DtoB(void);
void DtoO(void);
void DtoH(void);
void BtoD(void);
void BtoO(void);
void BtoH(void);
void OtoB(void);
void OtoD(void);
void OtoH(void);
void HtoB(void);
void HtoO(void);
void HtoD(void);
void basic(void);
void Loading(void);


int main()
{
    char d,b,h;
    char o,ch;
    system("color FC");
    //Home:
    printf("\n\n**************************************************************************\n");
    printf("\n\t\t********Welcome to Base-Calculator********\n");
    printf("\n**************************************************************************\n");
    printf("\n\t\t\tEnter any Key to go to Main Menu:\n\t\t\t");
    getch();

    system("cls");

    printf("\n\n\n\t******************************************\n");

    printf("\n\t\t********Loading...**********\n");

    printf("\n\t******************************************\n\t");
    Loading();

    while(1){
        first:
        system("cls");
        printf("\n\t\t\t******* Base-Calculator *******\n");
        printf("\n\n\n\t  * Main Menu :::\n");
        printf("\t___________________\n\n");
        printf("\n\tDecimal to Others[1]\n");
        printf("\n\tBinary to Others[2]\n");
        printf("\n\tOctal to Others[3]\n");
        printf("\n\tHexa-Decimal to Others[4]\n");
        printf("\n\t***Basic Calculator*** [5]\n\t");
        printf("\n\t******Exit******   [6]\n\n");
        fflush(stdin);
        printf("\n\n\tEnter your Choice : ");
        ch=getchar();

        switch(ch)
        {

            case '1':
                second:
                system("cls");
                printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
                printf("\n\n\tDecimal to Binary [1]\n");
                printf("\n\tDecimal to Octal [2]\n");
                printf("\n\tDecimal to Hexa-Decimal[3]\n\n\t");
                printf("\n\tEnter 0 for Go to Main Menu.\n\n\t");
                fflush(stdin);
                d=getchar();
                switch(d){
                    case '0': goto first;

                    case '1': DtoB();
                    break;

                    case '2': DtoO();
                    break;

                    case '3': DtoH();
                    break;

                    default:
                        system("cls");
                        printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
                        printf("\n\n\n\n\tSorry, You have Entered a Wrong Choice. Please try Again...\n\n");
                        printf("\n\tEnter any key to continue.... ");
                        getch();
                        goto second;
                }
                break;

            case '2':
                third:
                system("cls");
                printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
                printf("\n\n\tBinary to Decimal [1]\n");
                printf("\n\tBinary to Octal [2]\n");
                printf("\n\tBinary to Hexa-Decimal[3]\n\n\t");
                printf("\n\tEnter 0 for Go to Main Menu.\n\n\t");
                fflush(stdin);
                b=getchar();
                switch(b){
                    case '0': goto first;

                    case '1': BtoD();
                    break;

                    case '2': BtoO();
                    break;

                    case '3': BtoH();
                    break;

                    default:
                        system("cls");
                        printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
                        printf("\n\n\n\n\tSorry, You have Entered a Wrong Choice. Please try Again...\n\n");
                        printf("\n\tEnter any key to continue.... ");
                        getch();
                        goto third;
                }
                break;

            case '3':
                forth:
                system("cls");
                printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
                printf("\n\n\tOctal to Binary[1]\n");
                printf("\n\tOctal to Decimal[2]\n");
                printf("\n\tOctal to Hexa-Decimal[3]\n\n\t");
                printf("\n\tEnter 0 for Go to Main Menu.\n\n\t");
                fflush(stdin);
                o=getchar();
                switch(o){
                    case '0': goto first;

                    case '1': OtoB();
                    break;

                    case '2': OtoD();
                    break;

                    case '3': OtoH();
                    break;

                    default:
                        system("cls");
                        printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
                        printf("\n\n\n\n\tSorry, You have Entered a Wrong Choice. Please try Again...\n\n");
                        printf("\n\tEnter any key to continue.... ");
                        getch();
                        goto forth;
                    }
                    break;

            case '4':
                fifth:
                system("cls");
                printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
                printf("\n\n\tEnter 1 for Hexa-Decimal to Binary Conversation.\n");
                printf("\n\tEnter 2 for Hexa-Decimal to Decimal Conversation.\n");
                printf("\n\tEnter 3 for Hexa-Decimal to Octal Conversation.\n\n\t");
                printf("\n\tEnter 0 for Go to Main Menu.\n\n\t");
                fflush(stdin);
                h=getchar();
                switch(h){
                    case '0': goto first;

                    case '1': HtoB();
                    break;

                    case '2': HtoD();
                    break;

                    case '3': HtoO();
                    break;

                    default:
                        system("cls");
                        printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
                        printf("\n\n\n\n\tSorry, You have Entered a Wrong Choice. Please try Again...\n\n");
                        printf("\n\tEnter any key to continue.... ");
                        getch();
                        goto fifth;
                }
                break;

               case '5':
                   basic();
                    break;

                case '6':
                        system("cls");
                        printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
                        printf("\n\n\n\n\n\t***Thank You For Using This Calculator.***\n\n\n\n\t\t\t\t%c ***SARWAR*** %c\n\n",36,36);
                        return 0;

                default:
                    system("cls");
                    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
                    printf("\n\n\n\n\tSorry, You have Entered a Wrong Choice. Please try Again...\n\n");
                    printf("\n\tEnter any key to continue.... ");
                    getch();
                    goto first;
            }

    }


    return 0;
}
void Loading(void)
{
    int c,e;

    for ( c = 1 ; c <= 10000 ; c++ )
        for ( e = 1 ; e <= 15000 ; e++ )
            {}
}

void DtoB(void)
{
    int a[20],n,i;
    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");

    printf("\n\n\n\n\tEnter a Decimal number to convert: ");
    scanf("%d",&n);
    for(i=0;n>0;i++)
        {
        a[i]=n%2;
        n=n/2;
        }
        printf("\n\tBinary of Given Number is= ");
    for(i=i-1;i>=0;i--)
    {
        printf("%d",a[i]);

    }
    printf("\n\n\n\tPress any key...");
    getch();
}

void DtoO(void)
{
    int num;
    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
    printf("\n\n\n\n\tEnter a decimal number : ");
    scanf("%d",&num);
    printf("\n\n\tOctal value is : %o\n",num);
    printf("\n\n\tPress any key...");
    getch();

}


void DtoH(void)
{
    int num, remainder;
    int i, j = 0;
    char hexadecimalnum[100];
    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
    printf("\n\n\n\n\tEnter Decimal number : ");
    scanf("%d",&num);

    while (num!= 0)
    {
        remainder =num% 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        num =num / 16;
    }
        printf("\n\n\n\tHexa-Decimal Value : ");
    for (i = j; i >= 0; i--)
            printf("%c",hexadecimalnum[i]);
        printf("\n\n\n\tPress any key...");
        getch();
        return;
}

void BtoD(void)
{
    int num, decimal_val = 0, base = 1, rem=0;
    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
    printf("\n\n\n\n\tEnter a Binary number : ");
    scanf("%d",&num);

    while(num>0)
    {
        rem = num % 10;
        decimal_val = decimal_val + rem * base;
        num = num / 10 ;
        base = base * 2;
    }

      printf("\n\tDecimal value : %d\n",decimal_val);

      printf("\n\n\tPress any key...");
        getch();
        return;

}

void BtoO(void)
{
    int num, Octal_val=0,base=1,r=0;
    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
    printf("\n\n\n\n\tEnter a Binary number : ");

    scanf("%d",&num);
    while(num>0)
    {
        r=num%10;
        Octal_val=Octal_val+r*base;
        num=num/10;
        base=base*2;
    }

    printf("\n\n\tOctal Value : %o\n",Octal_val);
     printf("\n\n\tPress any key...");
        getch();
        return;

}

void BtoH(void)
{
    int num, Hexa_val=0,base=1,r=0;
    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
    printf("\n\n\n\n\tEnter a Binary number : ");

    scanf("%d",&num);
    while(num>0)
    {
        r=num%10;
        Hexa_val=Hexa_val+r*base;
        num=num/10;
        base=base*2;
    }
    printf("\n\tHexa-Decimal Value : %X\n",Hexa_val);
     printf("\n\n\tPress any key...");
        getch();
        return;
}

void OtoB(void)
{
    long int num, decimal = 0,a[20];

    int i = 0;
    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");

    printf("\n\n\n\n\tEnter a octal number : ");


    scanf("%ld", &num);


    while (num != 0)

    {

        decimal =  decimal +(num % 10)* pow(8, i++);

        num = num / 10;

    }


    for(i=0;decimal>0;i++)
        {
        a[i]=decimal%2;
        decimal=decimal/2;
        }
        printf("\n\n\tBinary of Given Number is : ");
    for(i=i-1;i>=0;i--)
    {
        printf("%ld",a[i]);

    }
     printf("\n\n\n\tPress any key...");
        getch();
        return;
}

void OtoD(void)
{
    long int num, decimal = 0;

    int i = 0;

    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");

    printf("\n\n\n\n\tEnter any octal number: ");

    scanf("%ld", &num);

    while (num != 0)

    {

        decimal =  decimal +(num % 10)* pow(8,i);
        i++;

        num = num / 10;

    }

    printf("\t\n\n\tEquivalent decimal value: %ld\n",decimal);
     printf("\n\n\tPress any key...");
        getch();
        return;
}

void OtoH(void)
{
    int num, decimal=0, i=0;
    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
    fflush(stdin);
    printf("\n\n\n\n\tEnter a Octal number : ");
    scanf("%d",&num);
    while (num != 0)

    {
        decimal =  decimal +(num % 10)* pow(8,i);
        i++;
        num = num / 10;
    }
    printf("\n\n\tHexa-Decimal Value : %X\n\n",decimal);
    printf("\n\n\tPress any key...");
        getch();
        return;
}

void HtoB(void){

   int hex[20], dec, i, j, ch, p,a[20];

    i = 0;
    p=0;
    dec=0;
    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
    fflush(stdin);
    printf("\n\n\n\n\tEnter a Hexadecimal value : ");
    while ((ch=getchar()) != '\n') {
        if ((ch > 47 && ch < 58) || (ch > 64 && ch < 71))
            hex[i++] = ch;
        }

    for (j = i-1; j >= 0; j-- ) {
        if (hex[j] > 57)
            dec +=  (hex[j] - 55) * (int)pow((double)16, p);
        else
            dec +=  (hex[j] - 48) * (int)pow((double)16, p);

        p++;
        }

    for(i=0;dec>0;i++)
        {
        a[i]=dec%2;
        dec=dec/2;
        }
        printf("\n\n\tBinary of Given Number is : ");
    for(i=i-1;i>=0;i--)
    {
        printf("%d",a[i]);

    }

    printf("\n\n\n\n\tPress any key...");
        getch();
        return;

}

void HtoD(void)
{
    int hex[20], dec, i, j, ch, p;
    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
    i = 0;
    p=0;
    dec=0;
    fflush(stdin);

    printf("\n\n\n\n\tEnter a Hexadecimal value : ");
    while ((ch=getchar()) != '\n') {
        if ((ch > 47 && ch < 58) || (ch > 64 && ch < 71))
            hex[i++] = ch;
        }

    for (j = i-1; j >= 0; j-- ) {
        if (hex[j] > 57)
            dec +=  (hex[j] - 55) * (int)pow((double)16, p);
        else
            dec +=  (hex[j] - 48) * (int)pow((double)16, p);

        p++;
        }

    printf("\n\n\tDecimal value : %d\n",dec);
    printf("\n\n\tPress any key...");
        getch();
        return;
}

void HtoO()
{
    int hex[20], dec, i, j, ch, p;

    i=0;
    p=0;
    dec=0;

    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
    fflush(stdin);
    printf("\n\n\n\n\tEnter a Hexadecimal value : ");
    while ((ch=getchar()) != '\n') {
        if ((ch > 47 && ch < 58) || (ch > 64 && ch < 71))
            hex[i++] = ch;
        }

    for (j = i-1; j >= 0; j-- ) {
        if (hex[j] > 57)
            dec +=  (hex[j] - 55) * (int)pow((double)16, p);
        else
            dec +=  (hex[j] - 48) * (int)pow((double)16, p);

        p++;
        }

    printf("\n\n\t\tOctal Value : %o\n",dec);

    printf("\n\n\tPress any key...");
    getch();
    return;

}

void basic()
{
    double num1,num2;
    char opt;

    system("cls");
    printf("\n\t\t\t******* Base-Calculator *******\n\n\n");
            printf("\n\n\n\tEnter the first number: ");
            scanf("%lf",&num1);
            printf("\n\n\tEnter the second number: ");
            scanf("%lf",&num2);
            fflush(stdin);
            printf("\t[+]  \tAddition .\n\t[-] \tSubstraction.\n\t[*] \tMultiplication.\n\t[/] \tDivision.\n\n");
            printf("\n\n\n\n\tEnter A sign: ");
            scanf("%c",&opt);
            switch(opt)
            {
        case '+':
			    printf("\n\n\tAddition of  %.1lf and %.1lf is: %.1lf",num1,num2,num1+num2);
			    printf("\n\n\n\tPress any key...");
			    getch();
                break;

        case '-':printf("\n\n\tSubstraction of %.1lf  and %.1lf is:  %.1lf",num1,num2,num1-num2);
                printf("\n\n\n\tPress any key...");
                getch();
                break;
        case '*':printf("\n\n\tMultiplication of %.1lf  and %.1lf is:  %.1lf",num1,num2,num1*num2);
                printf("\n\n\n\tPress any key...");
                getch();
                break;
        case '/':
			if(num2==0)
			{
				printf("\tOOPS Divide by zero\n");
				printf("\n\n\n\tPress any key...");
				getch();
			}
        else
        {
        printf("\n \tDivision of %.2lf and %.2lf is:  %.3lf",num1,num2,num1/num2);
        printf("\n\n\n\tPress any key...");
        getch();
        }
            break;
    default:
        printf("\n \tYou have entered a wrong sign...\n");
        printf("\n\n\n\tPress any key...");
        getch();
        break;
            }
        return ;
}
