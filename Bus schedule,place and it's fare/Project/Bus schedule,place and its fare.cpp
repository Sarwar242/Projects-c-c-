#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
int p,q,r;
printf("               # WELCOME TO (BUS SCHEDULE,PLACE & IT'S FARE) PROJECT #               \n");
printf("               # CREATED BY PROTAP MISTRY,DEPARTMENT OF C.S.E.,UNIVERSITY OF BARISAL #                    \n\n");

getch();
system("cls");

 printf("Only from Barisal & University of Barisal to another place by bus\n\n");

 getch();
 system("cls");

 printf("Here two types of bus\n");
 printf("1.University bus\n");
 printf("2.Local bus\n");
 printf("Which type of bus you needed ?\n");
 printf("Please press one serial number between two from above: ");
 start1:
 scanf("%d",&r);
 if(r==1)
 {

   printf("1. University of Barisal to Barisal club\n\n");
   printf("2. Barisal club to University of Barisal\n\n");
    printf("3. University of Barisal to Talukder filling station\n\n");
     printf("4. Talukder filling station to University of Barisal\n\n");
      printf("5. University of barisal to Nothullabadh\n\n");
       printf("6. Nothullabad to University of Barisal\n\n");

 }
 if(r==2)
 {

  printf("7. Barisal to Khulna\n\n");
         printf("8. Barisal to Dhaka\n\n");
          printf("9. Barisal to Rajshahi\n\n");
           printf("10. Barisal to Chittagong\n\n");
            printf("11. Barisal to Magura\n\n");
             printf("12. Barisal to Kuakata\n\n");

 }
 if(r==0 || r>2)
 {

     printf("No bus available");
     goto start1;

 }

             printf("Please give any serial number on the above exactly where you want to go: ");
                scanf(" %d",&p);
                printf("\n");
               if(p==1)
                {

                    printf("Only for teachers,students & workers of University of Barisal\n");
              printf("University of Barisal to Barisal club\n\n");

              }
             if(p==2)
                {

            printf("Only for teachers,students & workers of University of Barisal\n");
            printf("Barisal club to University of Barisal\n\n");

            }
           if(p==3)
           {

               printf("Only for teachers,students & workers of University of Barisal\n");
          printf("University of Barisal to Talukder filling station\n\n");

          }
         if(p==4)
        {

            printf("Only for teachers,students & workers of University of Barisal\n");
        printf("Talukder filling station to University of Barisal\n\n");

        }
       if(p==5)
    {

        printf("Only for teachers,students & workers of University of Barisal\n");
      printf("University of barisal to Nothullabadh\n\n");

      }
     if(p==6)
    {

        printf("Only for teachers,students & workers of University of Barisal\n");
    printf("Nothullabad to University of Barisal\n\n");

    }
   if(p==7)
   {

  printf("Barisal to Khulna\n\n");

   }
 if(p==8)
    {

printf("Brisal to Dhaka\n\n");
    }
    if(p==9)
        {

            printf("Barisal to Rajshahi\n\n");

        }
    if(p==10){
    printf("Barisal to Chittagong\n\n");
    }
    if(p==11){
    printf("Barisal to Magura\n\n");
    }
    if(p==12){
    printf("Barisal to Kuakata\n\n");
    }
   if(p==0 || p>12){
    printf("Place isn't available\n\n");
    return 0;
   }
    printf("Now get details about that stand please press before serial number: ");
    scanf("%d",&q);
    printf("\n");
    if(q==1)
        {
    printf("Bus stand: Main campus\n\n");
    printf("Bus name:University of Barisal\n\n");
    printf("Schedule & bus no:\n\n");
    printf("Bus no: 5 & 6_morning(8:00 A.M.)\nBus no: 5,6 & 1_morning(9:00 A.M.)\nBus no: 1_noon(12:30 P.M.)\n");
    printf("Bus no: 5 & 6_noon(1:00 P.M.)\nBus no: 5,6 & 1_noon(2:00 P.M.)\nBus no: 1_noon(3:00 P.M.)\n");
    printf("Bus no: 5 & 6_afternoon(5:15 P.M.)\n\n");
   printf("Fare: Free\n\n");
   printf("Journey time: 15 minutes\n\n");

}

   if(q==2)
    {
    printf("Bus stand: Barisal club\n\n");
    printf("Bus name:University of Barisal\n\n");
    printf("Schedule & bus no:\n\n");
    printf("Bus no: 5 & 6_morning(7:20 A.M.)\nBus no: 5 & 6_morning(8:30 A.M.)\nBus no:5,6 & 1_morning(9:30 A.M.)\n");
   printf("Bus no: 1_noon(1:00 P.M.)\nBus no: 5 & 6_noon(1:30 P.M.)\nBus no: 5,6 & 1_noon(2:30 P.M.)\n");
    printf("Bus no: 1_afternoon(3:30 P.M.)\n\n");
  printf("Fare: Free\n\n");
  printf("Journey time: 15 minutes\n\n");
    }

  if(q==3)
  {
  printf("Bus stand: Main campus\n\n");
  printf("Bus name:University of Barisal\n\n");
  printf("Schedule & bus no:\n\n");
    printf("Bus no: 2_morning(8:00 A.M.)\nBus no: 2_morning(9:00 A.M.)\nBus no: 2_noon(1:00 P.M.)\n");
  printf("Bus no: 3_noon(2:00 P.M.)\nBus no: 2_noon(3:00 P.M.)\n\n");
  printf("Fare: Free\n\n");
  printf("Journey time: 15 minutes\n\n");

}

  if(q==4)
    {
  printf("Bus stand: Talukdar filling station\n\n");
  printf("Bus name:University of Barisal\n\n");
  printf("Schedule & bus no:\n\n");
  printf("Bus no: 2_morning(7:10 A.M.)\nBus no: 2_morning(8:30 A.M.)\nBus no: 2_mornning(9:45 A.M.)\n");
  printf("Bus no: 2_noon(1:45 P.M.)\nBus no: 3_noon(2:45 P.M.)\nBus no: 2_noon(3:45 P.M.)\n\n");
  printf("Fare: Free\n\n");
  printf("Journey time: 15 minutes\n\n");

}

  if(q==5)
    {
  printf("Bus stand: Main campus\n\n");
    printf("Bus name:University of Barisal\n\n");
    printf("Schedule & bus no:\n\n");
  printf("Bus no: 7 & 9_morning(8:30 A.M.)\nBus no: 8 & 10_morning(9:00 A.M.)\nBus no: 7 & 9_morning(10:30 A.M.)\n");
  printf("Bus no: 8 & 10_morning(11:00 A.M.)\nBus no: 7 & 9_noon(1:00 P.M.)\nBus no: 8 & 10_noon(2:00 P.M.)\n");
  printf("Bus no: 7 & 9_noon(3:00 P.M.)\nBus no: 8 & 10_afternoon(5:15 P.M.)\n\n");
  printf("Fare: Free\n\n");
  printf("Journey time: 15 minutes\n\n");

}

  if(q==6)
    {
  printf("Bus stand: Nothullabad\n\n");
  printf("Bus name:University of Barisal\n\n");
  printf("Schedule & bus no:\n\n");
  printf("Bus no: 7 & 9_morning(7:30 A.M.)\nBus no: 8 & 10_morning(8:00 A.M.)\nBus no: 7 & 9_morning(9:30 A.M.)\n");
  printf("Bus no: 8 & 10_morning(10:00 A.M.)\nBus no: 7 & 9_morning(11:30 P.M.)\nBus no: 8 & 10_noon(1:30 P.M.)\n");
  printf("Bus no: 7 & 9_noon(2:30 P.M.)\nBus no: 8 & 10_ noon(3:30 P.M.)\n\n");
  printf("Fare: Free\n\n");
  printf("Journey time: 15 minutes\n\n");

}

  if(q==7)
    {
        printf("1.Bus stand: Rupatoli\n\n");
        printf("Bus name: Dhansiri\n\n");
        printf("Schedule: \n\n");
        printf("1st: morning(6:00 A.M.)\n2nd: morning(7:00 A.M.)\n3rd: morning(8:00 A.M.)\n4th: morning(9:00 A.M.)\n");
        printf("5th: morning(10:00 A.M.)\n6th: morning(11:00 A.M.)\n7th: noon(12:00 P.M.)\n8th: noon(1:00 P.M.)\n");
        printf("9th: noon(2:00 P.M.)\nlast: noon(3:00 P.M.)\n\n");
        printf("Fare: 180/=\n\n");
        printf("2.Bus stand: Nothullabad\n\n");
        printf("Bus name: B.R.T.C.\n\n");
        printf("Schedule: \n\n");
        printf("1st: morning(6:00 A.M.)\n2nd: morning(7:00 A.M.)\n3rd: morning(8:00 A.M.)\n4th: morning(9:00 A.M.)\n");
        printf("5th: morning(10:00 A.M.)\n6th: morning(11:00 A.M.)\n7th: noon(12:00 P.M.)\n8th: noon(1:00 P.M.)\n");
        printf("9th: noon(2:00 P.M.)\nlast: noon(3:00 P.M.)\n\n");
        printf("Fare: 190/=\n\n");
        printf("Journey time: 5 hour\n\n");

}

        if(q==8)
            {
        printf("Bus stand: Nothullabad\n\n");
         printf("Bus name: 1.Shakura , 2.Golden Line , 3.Meghna\n\n");
         printf("Schedule: \n\n");
         printf("1st: morning(9:00 A.M.)\nlast: afternoon(4:00 P.M.)\n\n");
        printf("Fare: 450/=\n\n");
        printf("Journey time: 5 hour\n\n");

            }

        if(q==9)
            {
        printf("Bus stand: Nothullabad\n\n");
         printf("Bus name: 1.Tuhin , 2.Golden Line , 3.Padma , 4.B.R.T.C.\n\n");
         printf("Schedule: \n\n");
         printf("1st: morning(6:00 A.M.)_B.R.T.C.\n2nd: morning(7:00 A.M.)_Padma\n3rd: noon(3.00 P.M.)_Golden Line\n");
         printf("last: night(7:00 P.M.)_Tuhin\n\n");
        printf("Fare: 550/=\n\n");
        printf("Journey time: 9 hour\n\n");

            }

        if(q==10)
            {
        printf("Bus stand: Nothullabad\n\n");
         printf("Bus name: Soudia\n\n");
         printf("Schedule: \n\n");
         printf("1st: morning(8:00 A.M.)\nlast: night(8:00 P.M.)\n\n");
        printf("Fare: 800/=\n\n");
        printf("Journey time: 10 hour\n\n");

            }

       if(q==11)
            {
        printf("Bus stand: Nothullabad\n\n");
         printf("Bus name: 1.G.M , 2.M.M , 3.Chaklader\n\n");
         printf("Schedule: \n\n");
         printf("1st: morning(8:00 A.M.)\n2nd: morning(10:00 A.M.)\n3rd: morning(11:30 A.M.)\n4th: noon(1:30 P.M.)\n");
         printf("5th: afternoon(5:00 P.M.)\nlast: night(6:00 P.M.)\n\n");
        printf("Fare: 300/=\n\n");
        printf("Journey time: 4 hour\n\n");

            }
        //return 0;
        if(q==12)
            {

        printf("Bus stand: Rupatoli\n\n");
         printf("Bus name: 1.Barisal to Kuakata , 2.Al-Arafat , 3.Shugondha , 4.Shikader\n\n");
         printf("Schedule: \n\n");
    printf("1st: morning(9:00 A.M.)\n2nd: morning(9:45 A.M.)\n3rd: morning(10:30 A.M.)\n4th: morning(10:15 A.M.)\n");
    printf("5th: morning(11:00 A.M.)\n6th: morning(11:45 A.M.)\n7th: noon(12:30 P.M.)\n8th: noon(1:15 P.M.)\n");
    printf("9th: noon(2:00 P.M.)\n10th: noon(2:45 P.M.)\n11th: noon(3:00 P.M.)\n12th: noon(3:45 P.M.)\n13th: afternoon(4:30 P.M.)\n");
    printf("14th: afternoon(5:15 P.M.)\n15th: afternoon(6:00 P.M.)\n16th: afternoon(6:45 P.M.)\n17th: night(7:30 P.M.)\n");
    printf("18th: night(8:15 P.M.)\nlast: night(9:00 P.M.)\n\n");
    printf("Fare: 200/=\n\n");
    printf("Journey time: 3 hour\n\n");

}
getch();
system("cls");
    printf("# Thank you for visiting my code #\n");
    printf("# Powered by PRO #\n");
    return 0;
}

