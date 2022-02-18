#include <regist.h>
#include<stdio.h>



int main(){
    
    int st;         
    long patient;             
    int k1=0,k2=0;      
    
    existregist();
    
    int mxatt=1000;  
    while(mxatt>0){
        
    aply:
    printf("\nvaccinated!!!\n");
    printf("Enter aadhar card  no:");
    scanf("%li",&patient);
   
    
    st = regist_status(patient);
    int i,j=0,vstat=0,choice=0,pno;
    
    
    for(i=1;i<=1000;i++)
    {
        if(pd[i].aadhar==patient)
            j=i;
    }
   
    
    if(st==-1){
        existregist();
    
        for(int i=1;i<=1000;i++)
        {
             if(pd[i].aadhar==0){
                printf("Enter details for registration\n");
                pd[i].aadhar=pd[0].aadhar;
                printf("Enter your phone number: ");
                scanf("%d",&pd[i].ph_number);
                printf("Enter your age: ");
                scanf("%d",&pd[i].age);
                printf("Enter your secret code: ");
                scanf("%d",&pd[i].secret_code);
                break;
                }

        }
        printf("Credentials saved, log in again\n");
        goto aply;
    }
    else if (st==0)
    {
        //Verification1
        Verification1();
        
    }
    else{
        // Verification2
        printf("Confirm user, enter ph.number\n");
        prk2:
        scanf("%d",&pno);
        if(pno==pd[j].ph_number)
            goto nxt2;
        else
            printf("Wrong credentials, try again\n");
            goto prk2;
        }nxt2:

    vstat=vaccine_status(j);        

    if(vstat==1)
        printf("Please take your first vaccine\nYou have been vaccinated once\n");
    else if (vstat==2)
        printf("Please take your second vaccine\nYou have been vaccinated twice\n");
    else if (vstat==3)
        printf("You have completed two dozes of vaccination\n");
    
    
    if(pd[j].vaccine_type==1 && (vstat==1 || vstat==2))
        k1++;
    else if(pd[j].vaccine_type==2 && (vstat==1 || vstat==2))
        k2++;
    
    mxatt--;
    
    }

    
    return 0;
}

void final()
{
printf("\nlist of patients and consumed stock of vaccines\n");
    for(int i=1;i<=1000;i++)
    {
     if(pd[i].aadhar!=0){
            printf("P%d Aadhar:%li\n",i,pd[i].aadhar);
            printf("P%d Phone no:%d\n",i,pd[i].ph_number);
            printf("P%d Age:%d\n",i,pd[i].age);
            printf("P%d Secret code:%d\n",i,pd[i].secret_code);
            printf("P%d Vaccine type:%d\n",i,pd[i].vaccine_type);
            printf("P%d Vaccine dozes:%d\n",i,pd[i].vaccine_doses);
        }   
    }
    
    printf("\nVaccine type 1(COVISHIELD):%d\n",k1);
    printf("Vaccine type 2(COVAXIN):%d\n",k2);
}

void Verification1()
{
    printf("Confirm user, enter ph.number\n");
        prk1:
        scanf("%d",&pno);
        if(pno==pd[j].ph_number)
            goto nxt1;
        else
            printf("Wrong credentials, try again\n");
            goto prk1;
        nxt1:
        printf("Time for vaccine\nSelect type\n");
        printf("1:Covishield\n2:Covaxin\n");
        scanf("%d",&choice);
        if(pd[j].vaccine_type==0){
            switch (choice){
                case 1:
                    pd[j].vaccine_type=1;
                    break;
                case 2:
                    pd[j].vaccine_type=2;
                    break;
                default:
                    printf("Select option 1 or 2\n");
                    break;
                }
        }

}

