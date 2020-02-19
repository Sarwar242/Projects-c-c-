
///Name       : Manishanker Biswas.
///Class Roll : 17CSE047
///Exam Roll  : CSE039
///Dept.      :C.S.E.


#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>

void infront()

{
    printf("\n\n\t\t\t\t Welcome to the Pharmacy Management.\n");

    printf("\t#  Press '1'  For Buying Medicine.\n");
    printf("\t#  Press '2'  For searching Medicine.\n");
    printf("\t#  Press '3'  For Sell Record a Specific Date.\n");
    printf("\t#  Press '4'  To Show Sell Record a Specific Date.\n");
    printf("\t#  Press '0'  For exit.\n");
    printf("\n\tEnter Choice Keyword ::");

}
void Medicine()
{
    FILE *pm;
    char pme[200];
    printf("\n\tSelect Your Medicine\n\tPress '0' for Back\n");
    pm = fopen("Pharmacy Management.txt","r");

    while(fscanf(pm,"%s",pm) != EOF)
        printf("\n\t%s\n",pm);
    fclose(pm);
    printf("\n\tEnter Choice Keyword:: ");
}
void select(unsigned int a)
{
    FILE *me;
    char pme[150];
     char athr[150];
    char cmp[150];
    switch(a)
    {
        case 1 : me = fopen("napa extra.txt","r");
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
    }
    if(a >= 1 || a <= 12)
    {
        printf("\n\t Medicine Name\t\t\t  Company Name\t\t\tPrice.\n\n");
        puts(pme);
    }
    else
        printf("\n\tWrong Keyword\n");


}
int main()
{
    char ch,medi[100],sear[150],sear2[150],med[150],med2[150];
    unsigned int nm,nm2,i,j,c=0,c1=0,t=0,ii;

    int test;

    start:
        infront();

ch=getch();

        if(ch=='1'){
                system("cls");
                Medicine();
                 scanf("%u",&nm2);
                 system("cls");
                 if(nm == 0)
                     goto start;
                 else
                    select(nm2);
        }
       else if(ch=='2'){
                system("cls");
                printf("Enter medicine Name:");
                gets(sear);
                for(ii=0;sear[ii]!='\0';ii++){
                    if(sear[ii]>64&&sear[ii]<96){
                        sear[ii]=sear[ii]+32;
                    }
                }
                FILE *fp;
                fp=fopen("search.txt","r");
                fgets(sear2,150,fp);
                fclose(fp);
                c1=strlen(sear);
                for(i=0;sear2[i]!='\0';i++){
                    c=0;
                    for(j=0;sear[j]!='\0';j++){
                        if(sear[j]==sear2[j+i]){
                            c++;
                            if(c+1==c1){
                                t=c;
                                break;
                            }
                        }
                        if(c==c1){
                                break;
                            }
                    }
                }
                if(t+1==c1){
                        if(strcmp(sear,"napa extra")==0){
                            test=1;
                        }
                        else if(strcmp(sear,"saclo")==0){
                            test=2;
                        }
                        else if(strcmp(sear,"azithromicin")==0){
                            test=3;
                        }
                        else if(strcmp(sear,"ranidin")==0){
                            test=4;
                        }
                        else if(strcmp(sear,"cofe")==0){
                            test=5;
                        }
                        else if(strcmp(sear,"deleta")==0){
                            test=6;
                        }
                        else if(strcmp(sear,"cefaclav")==0){
                            test=7;
                        }
                        else if(strcmp(sear,"fenadine")==0){
                            test=8;
                        }
                        else if(strcmp(sear,"myolax")==0){
                            test=9;
                        }
                        else if(strcmp(sear,"algin")==0){
                            test=10;
                        }
                        else if(strcmp(sear,"omeprazole")==0){
                            test=11;
                        }
                        else if(strcmp(sear,"pevisone")==0){
                            test=12;
                        }
                    printf("\n Self No %d \n",test);
                }
                else{
                    printf("sorry\n");
                }
       }




        else if(ch=='3'){
                system("cls");
            printf(" Medicine and Date \n");
            gets(med);
            FILE *fp1;
            fp1=fopen("list.txt","a");
            fputs(med,fp1);
            fprintf(fp1,"\n");
            fclose(fp1);
        }
        else if(ch=='4'){
                system("cls");
            printf(" Medicine Sell and Date \n\n");
            FILE *fp1;
            fp1=fopen("list.txt","r");
            while(fgets(med2,100,fp1)){
                puts(med2);
            }
            fclose(fp1);
        }


    return 0;
}
