#include<iostream>
#include<cstdlib>
#include<fstream>
#include<conio.h>
#include<cstring>
#include<string>
#include"Pharmacy.h"

using namespace std;

int main()
{
    char ch,sear[150],sear2[150],med[150],med2[150];
    unsigned int nm,i,j,c=0,c1=0,t=0,ii;

    int test;


    while(1){
        start:

        system("cls");
        infront();
        if(ch=='0')
            return 0;

        ch=getch();

        if(ch=='1'){
                system("cls");
                Medicine();
                cin>>nm;
                system("cls");
                if(nm == 0)
                     goto start;
                else
                     select(nm);
        }
       else if(ch=='2'){
                system("cls");
                test=0;
                printf("Enter medicine Name: ");
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
                        if(strcmp(sear,"napa")==0){
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
                    getch();
                }
                else{
                    printf("sorry\n");
                    getch();
            }
        }


        else if(ch=='3'){
            system("cls");
            cout<<" Medicine and Date \n"<<endl;
            gets(med);
            FILE *fp1;
            fp1=fopen("list.txt","a");
            fputs(med,fp1);
            fprintf(fp1,"\n");
            fclose(fp1);
        }
        else if(ch=='4'){
            system("cls");
            cout<<" Medicine Sell and Date \n\n"<<endl;
            FILE *fp1;
            fp1=fopen("list.txt","r");
            while(fgets(med2,100,fp1)){
                puts(med2);
            }
            fclose(fp1);
        }
        else if(ch=='5')
        {
            system("cls");
            cout<<" Add New Medicine \n"<<endl;
            add_medicine();
            cout<<"\tMedicine Has Been Added "<<endl;
            cout<<"\n\n\tPress any key ";

            getch();
        }
    }


    return 0;
}
