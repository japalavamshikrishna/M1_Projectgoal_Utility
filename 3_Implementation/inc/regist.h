#ifndef REGIST_C
#define REGIST_C

 // Checks for registration details of new members
int regist_status(long pd );

// Checks details from the pre registered members
int customerregist();

// Checks how many doses should be given
int vaccine_status(int );

// Structure that stores all details of a coustmer
typedef struct coustmer{
    long c_aadhar;
    int c_ph_number;
    int c_secret_code;
    int c_vaccine_type;
    int c_vaccine_doses;
}coustmer_details;

// variable pd that stores details of upto 1000 members
coustmer_details pd[1000];

#endif