#include <stdio.h>
#include "regist.h"

int regist_status(long p){

    // Checks for registration details of new customer    
    pd[0].c_aadhar=p;
    for(int i=1;i<=1000;i++){
        if(pd[0].aadhar==pd[i].c_aadhar){
            if(pd[i].c_vaccine_type==0)
                return 0;
            else
                return 1;
        }
   
    }
    return -1;
}

// Checks how many doses should be given
int vaccine_status(int i){
     
    if (pd[i].c_vacchine_doses==0){
        pd[i].c_vacchine_doses++;
        return 1;}
    else if(pd[i].c_vacchine_doses==1){
        pd[i].c_vacchine_doses++;
        return 2;}
    else if (pd[i].c_vacchine_doses==2){
        return 3;}
    else
        return 0;

}