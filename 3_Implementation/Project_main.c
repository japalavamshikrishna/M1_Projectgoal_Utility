#include<stdio.h>
#include "regist.h"


// Program begins from this section
int main(){
    
    int update;         // A return parameter to check update of coustomer
    long p;             // Variable that stores coustomer's aadhar number
    int k1=0,k2=0;      //Vaccine type 1 and 2 quantity
    
    coustomerregist();
    
    int att=1000;    // Variable that determines the total number of execution required by EOD
    while(att>0){
        
    aply:
    printf("\nLet's get vaccinated!!!\n");
    printf("Enter your aadhar number:");
    scanf("%li",&p);
   
    
    update = regist_update(p);
    int i,j=0,vstat=0,choice=0,pno;
    
    i=1;
    while(i<=1000){
        if(pd[i].aadhar==p)
            j=i;
    i++;
    }
    
    if(update==-1){
        existregist();
        i=1;
        while(i<=1000)_aadhar==0){
                printf("Fill details for registration\n");
                pd[i].c_aadhar=pd[0].aadhar;
                printf("Enter your phone number: ");
                scanf("%d",&pd[i].ph_number);
                printf("Enter your age: ");
                scanf("%d",&pd[i].age);
                printf("Enter your secret code: ");
                scanf("%d",&pd[i].secret_code);
                break;}
            i++;
        }
        printf("Credentials saved, log in again\n");
        goto aply;
    }
    else if (update==0){
        //Verification
        printf("Confirm user, enter ph.number\n");
        prk1:
        scanf("%d",&pno);
        if(pno==pd[j].c_ph_number)
            goto nxt1;
        else
            printf("Wrong credentials, try again\n");
            goto prk1;
        nxt1:
        printf("Time for vaccine\nSelect type\n");
        printf("1:Covishield\n2:Covaxin\n");
        scanf("%d",&choice);
        if(pd[j].c_vaccine_type==0){
            switch (choice){
                case 1:
                    pd[j].c_vaccine_type=1;
                    break;
                case 2:
                    pd[j].c_vaccine_type=2;
                    break;
                default:
                    printf("Select option 1 or 2\n");
                    break;
                }
        }
    }
    else{
        // Verification
        printf("Confirm user, enter ph.number\n");
        prk2:
        scanf("%d",&pno);
        if(pno==pd[j].c_ph_number)
            goto nxt2;
        else
            printf("Wrong credentials, try again\n");
            goto prk2;
        }nxt2:

    vstat=vaccine_status(j);        //update of coustomer based on being vaccinated

    if(vstat==1)
        printf("Please take your first vaccine\nYou have been vaccinated once\n");
    else if (vstat==2)
        printf("Please take your second vaccine\nYou have been vaccinated twice\n");
    else if (vstat==3)
        printf("You have completed two dozes of vaccination\n");
    
    // Count of total number of vaccine vials used
    if(pd[j].c_vaccine_type==1 && (vstat==1 || vstat==2))
        k1++;
    else if(pd[j].c_vaccine_type==2 && (vstat==1 || vstat==2))
        k2++;
    
    att--;
    
    }

    printf("\nFinal list of coustomers and consumed stock of vaccines\n");
    int i=1;
    while(i<=1000){
        if(pd[i].c_aadhar!=0){
            printf("P%d coustomer Aadhar:%li\n",i,pd[i].c_aadhar);
            printf("P%d coustomer Phone no:%d\n",i,pd[i].c_ph_number);
            printf("P%d coustomer Secret code:%d\n",i,pd[i].c_secret_code);
            printf("P%d coustomer Vaccine type:%d\n",i,pd[i].c_vaccine_type);
            printf("P%d coustomer Vaccine dozes:%d\n",i,pd[i].c_vaccine_doses);
        }
    i++;
    }
    printf("\nVaccine type 1(COVISHIELD):%d\n",k1);
    printf("Vaccine type 2(COVAXIN):%d\n",k2);
}