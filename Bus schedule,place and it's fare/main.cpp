#include<stdio.h>
#include<iostream>
#include<stdlib.h>//includes function involving memory allocation,process control,conversations
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<cstdio>

using namespace std;

char filename[200],uni[2000],read[2000],loc[2000],backup[1000];

struct bus
{

    char seri[30];
    char title[200];
    char detail[1500];

};

struct busn
{

    char s[30];
    char nam[200];

};

int main()
 {

  FILE *fp,*fpt,*fpi;

   struct bus file;
    struct busn lst;

     char r,ch[20];
     system("color 3f");
      printf("\n               # WELCOME TO MY (BUS SCHEDULE,PLACE & IT'S FARE) PROJECT. #\n\n");
       printf("               # CREATED BY PROTAP MISTRY... #\n\n");
        printf("               # DEPARTMENT OF C.S.E.,UNIVERSITY OF BARISAL. #\n\n");
         printf("               => Please press any key to go next: ");

        getch();//it is an input function used to read single character and hold the output<conio.h>
       system("cls");

      printf("\n          # Only from Barisal & University of Barisal to another place by bus.\n\n");
     printf("          => Please press any key to go main menu: ");

    getch();

   while(1)
  {
 main:

system("cls");

 printf("\n\n\t<<<<<<<<<< Welcome to main menu >>>>>>>>>>\n\n");
  printf("\n\n\t=> Here two types of bus::: \n");
   printf("\n\n\t1.University bus.\n");
    printf("\n\n\t2.Local bus.\n");
     printf("\n\n\t3.Add new route...\n");
      printf("\n\n\t4.Exit...\n");
       printf("\n\n\t=> Please press one serial number from above: ");

        fflush(stdin);//buffer before reading between stdin-every input take serially

         r=getchar();//input single char and return it to the program<stdio.h>

          switch(r)
        {
       case '1':
           uni:

      read[2000];
     system("cls");

    printf("\n\n\tUniversity bus routes:::\n\n");

   fp=fopen("University_bus.txt","r");
  rewind(fp);//set the file position of pointer for beginning of the file then start work
 fread(&uni,sizeof(uni),1,fp);
  //1=current position
printf("\n%s\n",uni);

 fclose(fp);
 printf("=>Enter 0 for going to main menu...\n");
  fflush(stdin);
   printf("\n\n=> Now get details about a route please enter a serial number from above and after seeing it press any key to go main menu: ");
    gets(filename);
     if(!strcmp(filename,"0"))
      goto main;


       fpt=fopen(filename,"r+");
        if(fpt==NULL)
        {
        system("cls");
       printf("\t\t\nWrong keyword,press any key to go back:");
        getch();
        goto uni;
        }

    //advance mode of read_fread or fwrite both are acceptable.
        rewind(fpt);
        fread(&read,sizeof(read),1,fpt);
        system("cls");

        fflush(stdout);
         printf("\n%s\n",read);


          fclose(fpt);
          getch();

         break;

       case '2':
      loc:
      system("cls");

     printf("\n\n\tLocal bus routes:::\n\n");

   fp=fopen("Local_bus.txt","r");
  fread(&loc,sizeof(loc),1,fp);
 printf("\n%s\n",loc);
fclose(fp);
printf("=>Enter 0 for going to main menu...\n");
 fflush(stdin);
  printf("\n\n=> Now get details about a route please enter a serial number from above and after seeing it press any key to go main menu: ");
   gets(filename);
   if(!strcmp(filename,"0"))
    goto main;

    fpt=fopen(filename,"r+");
    if(fpt==NULL)
    {
        system("cls");
        printf("\t\t\nWrong keyword,press any key to go back:");
        getch();
        goto loc;
    }
     rewind(fpt);
      fread(&read,sizeof(read),1,fpt);
       system("cls");
        printf("\n%s\n",read);

         fclose(fpt);
          getch();

          break;

         case '3':

        sub:
       system("cls");

      fflush(stdin);
     printf("\n\t<<<<< Welcome to add new route menu >>>>>\n");
    printf("\n\t1.University bus\n");
   printf("\n\t2.Local bus\n");
  printf("\n\n\tEnter 0 to go to main menu...\n\n");
 fflush(stdin);
printf("\n\tWhat type of route you want to add? \n");
 printf("\n\n\n\tPlease enter a serial number from above: ");
   gets(ch);
    if(!strcmp(ch,"0"))
        {
       goto main;
        }
        if(!strcmp(ch,"1"))

            {
                lol:
            system("cls");

             fflush(stdin);
            printf("\n\n\tEnter a serial number of the route that you want to add:::\n\t");
           gets(filename);
          strcpy(lst.s,filename);
         strcpy(file.seri,filename);
        fpi=fopen(filename,"r");
        if(fpi!=NULL)
        {
            printf("\n\tFile already exist.\n\tFor retrying press any key...\n");
            getch();
            goto lol;
        }
        else
        {
        fpi=fopen(filename,"w");
        }
       fflush(stdin);
      printf("\n\n\tEnter a title of the route and press any key after finishing it...\n");
     gets(backup);
    strcpy(lst.nam,backup);
   strcpy(file.title,backup);

 fflush(stdin);
printf("\n\n\tEnter other details of the route [To terminate press #]:\n");
 scanf("%[^#]",file.detail);

  getchar();

   fprintf(fpi,"%s. %s :: \n\n Time Details:: %s\n",file.seri,file.title,file.detail);
    fclose(fpi);

     fp=fopen("University_bus.txt","a+");
      fprintf(fp,"%s. %s\n",lst.s,lst.nam);
       fclose(fp);
        printf("\n\n\tYou have successfully added a new route in the university bus section. \n");
         printf("\n\n\t=> Press any key to go back...");
          getch();
          goto uni;
           }

      if(!strcmp(ch,"2"))


       {
           system ("cls");
      fflush(stdin);
     printf("\n\n\tEnter a serial number of the route that you want to add...\n\t");
    gets(filename);
   strcpy(lst.s,filename);
  strcpy(file.seri,filename);

fpi=fopen(filename,"r");
if(fpi!=NULL)
        {
            printf("\n\tFile already exist\n\tPlease try another key...\n");
            getch();
            goto lol;
        }
        else
        {
        fpi=fopen(filename,"w");
        }
 rewind(fpi);
  fflush(stdin);
   printf("\n\n\tEnter a title of the route and press any key after finishing it...\n");
    gets(backup);
     strcpy(lst.nam,backup);
      strcpy(file.title,backup);

       fflush(stdin);
        printf("\n\n\tEnter other details of the route [To terminate press #]:\n");
         scanf("%[^#]",file.detail);
          getchar();
           fprintf(fpi,"%s. %s:: \n\n Time Details:: %s\n",file.seri,file.title,file.detail);
          fclose(fpi);

         fp=fopen("Local_bus.txt","a+");
        fprintf(fp,"%s. %s\n",lst.s,lst.nam);
       fclose(fp);
      printf("\n\n\t You have successfully added a new route in the local bus section. \n");
     printf("\n\n\t=> Press any key to go back...");
    getch();

 }


else
    {

  system("cls");

   printf("\n\n Sorry you have entered a wrong keyword...\n\n=>Press any key to go back... ");

    getch();
     goto sub;

      }


        case '4':

         system("cls");

          printf("\n\n# THANK YOU FOR VISITING MY SITE #\n\n");
         printf("# DEVELOPED BY PROTAP MISTRY #\n\n");
        printf("# DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING_4th BATCH #\n\n");
       printf("# UNIVERSITY OF BARISAL #\n\n");
      printf("# MY HOME DISTRICT IS BAGERHAT #\n\n");
     printf("=> Please press any key to exit...");

   getch();
  return 0;

default:

 system("cls");

  printf("\n\nSorry you have entered a wrong keyword...\n\n");
   printf("=>Please press any key to go back: ");

    getch();
     goto main;
      }

       }
        return 0;
         }
