#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

// Global variables declaration
char date1[10], operation[20], lastName[20], firstName[20], profession[20], phoneNumber[14];
float balance;

/* Structures */
struct Customer{
    int idCustomer;
    char lastName [20];
    char firstName [20];
    char profession [20];
    char phoneNumber [14];
}customer;

struct Account{
    int idCustomer;
    int idAccount;
    char lastName [20] ;
    float balance;
}account;
struct Customer customer;
struct Account account;

void operationMenu(); // Operations management menu
void accountMenu(); // Accounts management menu
void generalMenu();    // General menu
void customerMenu(); // Customer management menu
int searchCustomerById(int idCustomer); // Search customer by his id


//gotoxy function
void gotoxy(int x,int y) {
    printf("%c[%d;%df",0x1B,y,x);
}

/* Id Generator */
int generateId() {
    int id,lastId=0;
    const int MAX=1000,MIN=1;
    FILE *file;
    file=fopen("last_id","r");
    fscanf(file,"%d",&lastId);
    fclose(file);
    srand(time(NULL));
    id=(rand()%(MAX-MIN+1))+MIN;

    return id+lastId;
}

/* THE MAIN FUNCTION */
int main() {
    generalMenu();
    return 0;
}

/* GENERAL MENU : WHO CALLS ON OTHER MENUS */
void generalMenu()
{
    int choice;
    system("cls");
    printf("\n");
    printf("=======================================");
    printf("========================================\n");
    puts(
"\t\t __   __       __  __                   __           \n"
"\t\t/ _  |_  |\\ | |_  |__|  /\\  |     |\\/| |_  |\\ | |  | \n"
"\t\t\\__| |__ | \\| |__ | \\  /--\\ |__   |  | |__ | \\| |__| \n");
    printf("=======================================");
    printf("========================================\n\n\n");
    printf("\t\t1. Customer management\n\n");
    printf("\t\t2. Account management\n\n");
    printf("\t\t3. Operations management\n\n");
    printf("\t\t4. Quit\n\n");
    gotoxy(20,22);
    printf("Your Choice : ");
    scanf("%d",&choice);
    system("cls");
    switch (choice) {
        case 1 : customerMenu();break; // Customer management menu
        case 2 : accountMenu();break; // Account management menu
        case 3 : operationMenu();break; // Operations management menu
        case 4 : exit(0);break;
        default: exit(1);break;
    }
}

// Customer management menu
void customerMenu()
{
    int choice;
    printf("\n");
    printf("=======================================");
    printf("========================================\n");
    puts(
"\t\t __       __ ___  __        __  __  \n"
"\t\t/   |  | (_   |  /  \\ |\\/| |_  |__| \n"
"\t\t\\__ |__| __)  |  \\__/ |  | |__ | \\  \n");
    printf("=======================================");
    printf("========================================\n\n\n");
    printf("\t\t1. Add Customer\n\n");
    printf("\t\t2. Edit Customer\n\n");
    printf("\t\t3. Delete Customer\n\n");
    printf("\t\t4. Search Customer\n\n");
    printf("\t\t5. General Menu\n\n");
    gotoxy(20,22);
    printf("Your Choice : ");
    scanf("%d",&choice);
    //clrscr();
    system("cls");
    switch (choice) {
        case 1 : addCustomer();break;
        case 2 : editCustomer();break;
        case 3 : deleteCustomer();break;
        case 4 : searchCustomer();break;
        case 5 : generalMenu();break;
    }
}

// Account management menu
void accountMenu() {
    int a;
    printf("\n=======================================");
    printf("========================================\n");
    puts(
"\t\t      __  __  __            ___ \n"
"\t\t /\\  /   /   /  \\ |  | |\\ |  |  \n"
"\t\t/--\\ \\__ \\__ \\__/ |__| | \\|  |  \n");
    printf("=======================================");
    printf("========================================\n\n\n");
    printf("\t\t1. New account\n\n");
    printf("\t\t2. Consultation\n\n");
    printf("\t\t3. Closing account\n\n");
    printf("\t\t4. General Menu\n\n");
    gotoxy(20,20);
    printf("Your choice : ");
    scanf("%d",&a);
    system("cls");
    switch (a) {
        case 1 : createAccount();break;
        case 2 : consultAccount();break;
        case 3 : deleteAccount();break;
        case 4 : generalMenu();break;
        default: exit(1);
    }
}

// Operations management menu
void operationMenu()
{
    int choice;//choice
    printf("\n=======================================");
    printf("========================================\n");
    puts(
"\t\t __   __   __  __       ___    __       \n"
"\t\t/  \\ |__) |_  |__)  /\\   |  | /  \\ |\\ | \n"
"\t\t\\__/ |    |__ | \\  /--\\  |  | \\__/ | \\| \n");
    printf("=======================================");
    printf("========================================\n\n\n");
    printf("\t\t1. Withdrawal\n\n");
    printf("\t\t2. Transfer\n\n");
    printf("\t\t3. General Menu\n\n");
    gotoxy(20,18);
    printf("Your choice : ");
    scanf("%d",&choice);
    system("cls");
    switch (choice) {
        case 1 :withdrawal();break;
        case 2 :transfer();break;
        case 3 :generalMenu();break;
    }
}

/* Allows to read the final balance of a given account */
float getBalance(int idCustomer,int idAccount) {
    FILE *fp;
    fp = fopen("bank_accounts","r");

    while(!feof(fp) && fscanf(fp,"%d %d %f %s %s\n",&account.idCustomer,&account.idAccount,&account.balance,&operation,&date1) != EOF) {
        if(account.idCustomer==idCustomer && account.idAccount==idAccount) {
            balance=account.balance;
        }
    }
    fclose(fp);

    return balance;
}

/* CUSTOMER MANAGEMENT MENU */
// Adding a customer
void addCustomer() {
    FILE *fp,*file;
    int rep;
    do {
        fp = fopen("bank_customers","a");
        printf("\n\n\n============================ ADD CUSTOMER ===================================\n\n\n");
        customer.idCustomer=generateId();
        file=fopen("last_id","w");
        fprintf(file,"%d",customer.idCustomer);
        fclose(file);
        printf("\t> Customer ID : #%08d\n",customer.idCustomer);
        printf("\n\t> Lastname : ");
        scanf("%s",&customer.lastName);
        printf("\n\t> Firstname : ");
        scanf("%s",&customer.firstName);
        printf("\n\t> Profession : ");
        scanf("%s",&customer.profession);
        printf("\n\t> Phone number : ");
        scanf("%s",&customer.phoneNumber);

        fprintf(fp,"\n %d %s %s %s %s ",customer.idCustomer,customer.lastName,customer.firstName,customer.profession,customer.phoneNumber);
        fclose(fp);
        Sleep(1500);
        printf(" \n\tCREATION : Successfully completed\n");
        printf("\n\tDo you want to add another customer (0) or return (1): ");
        scanf("%d",&rep);
        system("cls");
    } while(rep==0);
    customerMenu();
}

// Edit Customer function
void editCustomer() {
    FILE *fp,*fc;
    char r;
    int ch,id;
    printf("\n\n\n============================  EDIT CUSTOMER =====================================\n\n\n");
    printf("\tEnter Customer ID : ");
    scanf("%d",&id);
    printf("\n\t1. Lastname\n");
    printf("\n\t2. Firstname\n");
    printf("\n\t3. Profession \n");
    printf("\n\t4. Phone Number \n");
    printf("\n\t5. Return\n");
    printf("\n\tYour choice : ");
    scanf("%d",&ch);

    switch (ch) {
        case 1  :
                    fp=fopen("bank_customers","r+");
                    fc=fopen("bank_customers_tmp","a");
                    printf("\n\tLastname : ");
                    scanf("%s",&lastName);
                    while(!feof(fp) && fscanf(fp,"%d %s %s %s %s",&customer.idCustomer,&customer.lastName,&customer.firstName,&customer.profession,&customer.phoneNumber)!=EOF) {
                        if(customer.idCustomer==id) {
                            fprintf(fc,"%d %s %s %s %s\n",customer.idCustomer,lastName,customer.firstName,customer.profession,customer.phoneNumber);
                        }
                        else {
                            fprintf(fc,"%d %s %s %s %s\n",customer.idCustomer,customer.lastName,customer.firstName,customer.profession,customer.phoneNumber);
                        }
                    }
                    fclose(fp);
                    fclose(fc);
                    remove("bank_customers");
                    rename("bank_customers_tmp","bank_customers");
                    break;

        case 2  :   fp=fopen("bank_customers","r+");
                    fc=fopen("bank_customers_tmp","a");
                    printf("\n\tFirstname : ");
                    scanf("%s",&firstName);
                    while(!feof(fp) && fscanf(fp,"%d %s %s %s %s",&customer.idCustomer,&customer.lastName,&customer.firstName,&customer.profession,&customer.phoneNumber)!=EOF) {
                        if(customer.idCustomer==id) {
                            fprintf(fc,"%d %s %s %s %s\n",customer.idCustomer,customer.lastName,firstName,customer.profession,customer.phoneNumber);
                        }
                        else {
                            fprintf(fc,"%d %s %s %s %s\n",customer.idCustomer,customer.lastName,customer.firstName,customer.profession,customer.phoneNumber);
                        }
                    }
                    fclose(fp);
                    fclose(fc);
                    remove("bank_customers");
                    rename("bank_customers_tmp","bank_customers");
                    break;

        case 3  :   fp=fopen("bank_customers","r+");
                    fc=fopen("bank_customers_tmp","a");
                    printf("\n\tProfession : ");
                    scanf("%s",&profession);
                    while(!feof(fp) && fscanf(fp,"%d %s %s %s %s",&customer.idCustomer,&customer.lastName,&customer.firstName,&customer.profession,&customer.phoneNumber)!=EOF) {
                        if(customer.idCustomer==id) {
                            fprintf(fc,"%d %s %s %s %s\n",customer.idCustomer,customer.lastName,customer.firstName,profession,customer.phoneNumber);
                        }
                        else {
                            fprintf(fc,"%d %s %s %s %s\n",customer.idCustomer,customer.lastName,customer.firstName,customer.profession,customer.phoneNumber);
                        }
                    }
                    fclose(fp);
                    fclose(fc);
                    remove("bank_customers");
                    rename("bank_customers_tmp","bank_customers");
                    break;

        case 4  :   fp=fopen("bank_customers","r+");
                    fc=fopen("bank_customers_tmp","a");
                    printf("\n\tPhone Number : ");
                    scanf("%s",&phoneNumber);
                    while(!feof(fp) && fscanf(fp,"%d %s %s %s %s",&customer.idCustomer,&customer.lastName,&customer.firstName,&customer.profession,&customer.phoneNumber)!=EOF) {
                        if(customer.idCustomer==id) {
                            fprintf(fc,"%d %s %s %s %s\n",customer.idCustomer,customer.lastName,customer.firstName,customer.profession,phoneNumber);
                        }
                        else {
                            fprintf(fc,"%d %s %s %s %s\n",customer.idCustomer,customer.lastName,customer.firstName,customer.profession,customer.phoneNumber);
                        }
                    }
                    fclose(fp);
                    fclose(fc);
                    remove("bank_customers");
                    rename("bank_customers_tmp","bank_customers");
                    break;

        case 5 : generalMenu();break;
    }
    printf("\n\tEdit: Successfully completed!");
    Sleep(1500);
    system("cls");
    customerMenu();
}


// Delete function: one by one or all
void deleteCustomer() {
    FILE *fp,*fc,*fa,*fat;;
    int idAccount,idCustomer,choice;
    float balance_r;
    int rep,rep1;
    printf("\n\n\n============================== DELETE CUSTOMER =====================================\n\n\n");
    printf("\t\t1. One by one\n");
    printf("\n\t\t2. All\n");
    printf("\n\t\tYour choice : ");
    scanf("%d",&choice);

    if (choice==1) {
        do {
            printf("\n\t\tEnter Customer ID : ");
            scanf("%d",&idCustomer);
            if(searchCustomerById(idCustomer)==1) {
                system("cls");
                printf("\n\n\n============================== DELETE CUSTOMER =====================================\n\n\n");
                printf("\tCustomer ID : #%08d\n",idCustomer);

                fp = fopen("bank_customers","r");
                fc = fopen("bank_customers_tmp","a");
                printf("\n\n\tAre you sure you want to delete this Account (0) or return (1): ");
                scanf("%d",&rep1);
                Sleep(1500);
                if(rep1==0) {
                    // Delete Customer from Bank_Customers
                    while(!feof(fp) && fscanf(fp,"%d %s %s %s %s",&customer.idCustomer,&customer.lastName,&customer.firstName,&customer.profession,&customer.phoneNumber)!=EOF) {
                        if(customer.idCustomer==idCustomer){}
                        else {
                            fprintf(fc,"%d %s %s %s %s\n",customer.idCustomer,customer.lastName,customer.firstName,customer.profession,customer.phoneNumber);
                        }
                    }
                    fclose(fp);
                    fclose(fc);
                    remove("bank_customers");
                    rename("bank_customers_tmp","bank_customers");
                    // Delete Customer accounts from Bank_Accounts
                    if(1){
                        printf("test:"+idCustomer);
                        fa = fopen("bank_accounts","r");
                        fat = fopen("bank_accounts_tmp","a");

                        while(fscanf(fa,"%d %d %f %s %s",&account.idCustomer,&account.idAccount,&account.balance,&operation,&date1) != EOF ) {
                            if(idCustomer==account.idCustomer) {
                            }
                            else {
                                fprintf(fat,"%d %d %f %s %s\n",account.idCustomer,account.idAccount,account.balance,operation,date1);
                            }
                        }
                        fclose(fa);
                        fclose(fat);
                        remove("bank_accounts");
                        rename("bank_accounts_tmp","bank_accounts");
                    }
                    printf("\n\tDelete: Successfully completed!");
                    Sleep(1500);
                    printf("\n\n\tDo you want to delete another Customer (0) or return (1): ");
                    scanf("%d",&rep);
                    system("cls");
                }
                else {
                    system("cls");
                    generalMenu();
                    break;
                }
            }
            else {
                printf("\a\n\n\t\tCustomer ID not found!");
                printf("\n\n\t\tDo you want to enter another ID (0) or return (1): ");
                scanf("%d",&rep);
                system("cls");
            }
        } while(rep==0);
    }
    else if(choice==2) {
        printf("\n\t\tAre you sure you want to delete All (0) or return (1): ");
        scanf("%d",&rep1);
        Sleep(2000);
        if(rep1==0) {
            fp = fopen("bank_customers","w+");
            fc = fopen("bank_accounts","w+");
        }
    }
    system("cls");
    customerMenu();
}

/* Search a Customer */
void searchCustomer() {
    FILE *fp;
    int ch,id,found=0,rep;
    char lastName[20];
    do {
        printf("\n\n\n==============================  SEARCH CUSTOMER  =====================================\n\n\n");
        printf("\t\t1. By Customer ID\n");
        printf("\n\t\t2. By Lastname\n");
        printf("\n\t\tYour choice : ");
        scanf("%d",&ch);
        fp = fopen("bank_customers","r");
        if (ch==1) {
            printf("\n\t\tEnter Customer ID : ");
            scanf("%d",&id);
            Sleep(2000);
            while(!feof(fp) &&  fscanf(fp,"%d %s %s %s %s",&customer.idCustomer,&customer.lastName,&customer.firstName,&customer.profession,&customer.phoneNumber) != EOF ) {
                if (id==customer.idCustomer) {
                    found=1;
                    printf("\n\t\tResults :\n\n");
                    printf(" Customer ID : %d     Lastname : %s\t Firstname : %s     Profession : %s     Phone Number : %s\n\n",customer.idCustomer,customer.lastName,customer.firstName,customer.profession,customer.phoneNumber);
                }
            }
            if (found==0) {
                printf("\n\t\tCustomer ID not found!\n");
            }
        }
        else if (ch==2) {
            printf("\n\t\tVotre lastName :");scanf("%s",&lastName);Sleep(2000);
            while(!feof(fp) &&  fscanf(fp,"%d %s %s %s %s \n ",&customer.idCustomer,&customer.lastName,&customer.firstName,&customer.profession,&customer.phoneNumber) != EOF )
                {
                    if (strcmp(lastName,customer.lastName) == 0) {
                        found=1;
                        printf("\n\t\tResults :\n\n");
                        printf(" Customer ID : %d     Lastname : %s\t Firstname : %s     Profession : %s     Phone Number : %s\n\n",customer.idCustomer,customer.lastName,customer.firstName,customer.profession,customer.phoneNumber);
                    }
                }
            if (found==0) {
                printf("\n\n\t\t\aLastname not found!");
            }
        }
        fclose(fp);
        printf("\tDo you want to search for another customer (0) or return (1): ");
        scanf("%d",&rep);
        system("cls");
    } while(rep==0);
    customerMenu();
}

// Search Customer by ID
int searchCustomerById(int idCustomer) {
    FILE *fp;
    int found=0;

    fp = fopen("bank_customers","r");
    while( fscanf(fp,"%d %s %s %s %s",&customer.idCustomer,&customer.lastName,&customer.firstName,&customer.profession,&customer.phoneNumber) != EOF ) {
        if (idCustomer==customer.idCustomer) {
            found=1;
            fclose(fp);
            return found;
        }
    }
    fclose(fp);
    return found;
}

/* ACCOUNT MANAGEMENT */
// Create a new account
void createAccount() {
    FILE *fp,*file;
    int rep,idCustomer;
    do{
        printf("\n\n\n============================   CREATE ACCOUNT  =====================================\n\n\n");
        printf("\tEnter Customer ID : ");
        scanf("%d",&idCustomer);
        Sleep(1500);
        system("cls");
        if(searchCustomerById(idCustomer)==1){
            fp = fopen("bank_accounts","a");
            printf("\n\n\n============================   CREATE ACCOUNT  =====================================\n\n\n");
            printf("\n\tCustomer ID : %#08d\n",idCustomer);
            account.idAccount=generateId();
            file=fopen("last_id","w");
            fprintf(file,"%d",account.idAccount);
            fclose(file);
            printf("\n\tAccount ID : %#08d\n",account.idAccount);
            printf("\n\tBasic balance : ");
            scanf("%f",&account.balance);
            while(account.balance<1000){
                printf("\n\tBasic balance must be >=1000 : ");
                scanf("%f",&account.balance);
            }
            /* Creation date */
            char format[11];
            time_t temps;
            struct tm date;

            time(&temps);
            date=*localtime(&temps);

            strftime(format,11," %x\n", &date);
            //puts(format);
            strcpy(date1, format);
            printf("\n\tCreation date : %s\n",date1);

            fprintf(fp,"%d %d %.2f %s %s",idCustomer,account.idAccount,account.balance,"0",date1);
            fclose(fp);
            Sleep(1500);
            printf("\tCREATION : Successfully completed\n");
            printf("\n\tDo you want to add another account (0) or return (1): ");
            scanf("%d",&rep);
            system("cls");
        }
        else {
            printf("\a\n\tCustomer Account not found!");
            printf("\n\n\tDo you want to enter another ID (0) or return (1): ");
            scanf("%d",&rep);
            system("cls");
        }
    } while(rep==0);
    accountMenu();
}
// Account consultation
void consultAccount() {
    int idCustomer;
    FILE *fp,*fc;
    int largeur=8,i=1,j,rep;
    char lastName[20],plastName[20];
    char format[32],format0[32],format1[32],format2[32],format3[32];/* format for printf*/

    do {
        printf("\n\n\n========================== Consulting Accounts ============================\n\n");
        printf("\n\n\tCustomer ID : ");
        scanf("%d",&idCustomer);
        Sleep(1500);
        system("cls");
        printf("\n\n\n========================= Consulting Accounts ===========================\n\n\n");
        if(searchCustomerById(idCustomer)==1){
            printf("*************************************************************************\n");
            printf("*");
            printf("Customer ID : #%08d",idCustomer);
            printf("\t\t\t\t\t\t*\n");
            printf("*************************************************************************\n");
            sprintf(format,"| %%%ds |",largeur-2 );
            printf(format," Account ID ");
            sprintf(format,"| %%%ds |",largeur+3 );
            printf(format," Full  Name ");
            sprintf(format,"| %%%ds |",largeur+8 );
            printf(format,"Basic balance");
            sprintf(format,"|    %%%ds  |\n",13 );
            printf(format,"Operation");
            printf("|\t       ||\t       ||\t\t   ||  carried out/date |\n");
            printf("*************************************************************************\n");
            fp = fopen("bank_accounts","r");
            fc = fopen("bank_customers","r");
            while( fscanf(fc,"%d %s %s %s %d",&customer.idCustomer,&customer.lastName,&customer.firstName,&customer.profession,&customer.phoneNumber) != EOF ) {
                if(idCustomer==customer.idCustomer) {
                    strcpy(lastName, customer.lastName);
                    strcpy(plastName, customer.firstName);
                }
            }
            fclose(fc);

            while(fscanf(fp,"%d %d %f %s %s",&account.idCustomer,&account.idAccount,&account.balance,&operation,&date1) != EOF ) {
                if(idCustomer==account.idCustomer) {
                    /*instructions*/
                    sprintf(format0,"| $%%%dd |" ,-11);
                    sprintf(format1,"|%%%ds %%s|",largeur-1 );
                    sprintf(format2,"| %%%d.2f Dhs |",largeur+4 );
                    sprintf(format3,"|%%%ds %%s |\n",largeur+1);

                    printf(format0,account.idAccount);
                    printf(format1,lastName,plastName);
                    printf(format2,account.balance);
                    printf(format3,operation,date1);
                    printf("*************************************************************************\n");
                }
            }
            fclose(fp);
        }
        else {
            printf("\a\tCustomer ID not found!\n\n");
        }
        printf("\nDo you want to consult another customer accounts (0) or return (1)? ");
        scanf("%d",&rep);
        system("cls");
    } while(rep==0);
    accountMenu();
}
// Delete an account
void deleteAccount() {
    FILE *fp,*fc;
    int idAccount,idCustomer;
    float balance_r;
    int rep;
    printf("\n\n\n=========================== DELETE ACCOUNT =================================\n\n\n");
    do {
        printf("\tEnter Customer ID : ");
        scanf("%d",&idCustomer);
        if(searchCustomerById(idCustomer)==1){
            system("cls");
            do {
                printf("\n\n\n=========================== DELETE ACCOUNT =================================\n\n\n");
                printf("\tCustomer ID : #%08d\n",idCustomer);
                printf("\n\tAccount ID : ");
                scanf("%d",&idAccount);
                system("cls");
                printf("\n\n\n=========================== DELETE ACCOUNT =================================\n\n\n");
                if(searchAccountById(idAccount)==1) {
                    fp = fopen("bank_accounts","r");
                    fc = fopen("bank_accounts_tmp","a");

                    printf("\tCustomer ID : #%08d\n",idCustomer);
                    printf("\n\tAccount ID : $%04d\n",idAccount);
                    while(!feof(fp) && fscanf(fp,"%d %d %f %s %s",&account.idCustomer,&account.idAccount,&account.balance,&operation,&date1)!=EOF) {
                        if(account.idAccount==idAccount){}
                        else {
                            fprintf(fc,"%d %d %f %s %s\n",account.idCustomer,account.idAccount,account.balance,operation,date1);
                        }
                    }
                    fclose(fp);
                    fclose(fc);
                    remove("bank_accounts");
                    rename("bank_accounts_tmp","bank_accounts");
                    Sleep(1500);
                    printf("\n\tDELETE : Successfully completed!");
                    printf("\n\n\tDo you want to delete another Account (0) or return (1): ");
                    scanf("%d",&rep);
                    system("cls");
                }
                else {
                    Sleep(1500);printf("\n\t\aAccount ID not found!");
                    printf("\n\n\tDo you want to enter another ID (0) or return (1): ");
                    scanf("%d",&rep);
                    system("cls");
                }
            } while(rep==0);
        }
        else {
            Sleep(1500);
            printf("\n\t\aCustomer ID not found!");
            printf("\n\n\tDo you want to enter another ID (0) or return (1): ");
            scanf("%d",&rep);
            system("cls");
        }
    } while(rep==0);
    accountMenu();
}

// Search Account by id
int searchAccountById(int idAccount) {
    FILE *fp;
    int found=0;

    fp = fopen("bank_accounts","r");
    while( fscanf(fp,"%d %d %f %s %s",&account.idCustomer,&account.idAccount,&account.balance,&operation,&date1) != EOF ) {
        if (idAccount==account.idAccount) {
            found=1;
            fclose(fp);
            return found;
        }
    }
    fclose(fp);
    return found;
}

/* OPERATIONS MANAGEMENT */
// Withdrawing money
void withdrawal() {
    FILE *fp;
    int idAccount,idCustomer;
    float balance_r;
    int rep;

    do{
        printf("\n\n\n============================  WITHDRAWAL balance  ===================================\n\n\n");
        printf("\tEnter Customer ID : ");
        scanf("%d",&idCustomer);
        if(searchCustomerById(idCustomer)==1) {
            system("cls");
            do {
                printf("\n\n\n============================  WITHDRAWAL balance  ===================================\n\n\n");
                printf("\tCustomer ID : #%08d",idCustomer);
                printf("\n\n\tAccount ID : ");
                scanf("%d",&idAccount);
                system("cls");
                printf("\n\n\n============================  WITHDRAWAL balance  ===================================\n\n\n");
                if(searchAccountById(idAccount)==1) {
                    fp = fopen("bank_accounts","a");

                    printf("\tCustomer ID : #%08d\n",idCustomer);
                    printf("\n\n\tAccount ID : $%04d",idAccount);
                    printf("\n\n\tAmount : ");
                    scanf("%f",&balance_r);
                    while(balance_r>700) {
                        printf("\n\tAmount withdrawn must be <=700dhs : ");
                        scanf("%f",&balance_r);
                    }
                    // Withdrawn date
                    char format[11];
                    time_t temps;
                    struct tm date;

                    time(&temps);
                    date=*localtime(&temps);

                    strftime(format,11," %x\n", &date);
                    //puts(format);
                    strcpy(date1, format);
                    balance=getBalance(idCustomer,idAccount);
                    balance-=balance_r;
                    fprintf(fp,"%d %d %.2f -%.2f %s\n",idCustomer,idAccount,balance,balance_r,date1);
                    fclose(fp);
                    Sleep(1500);
                    printf("\n\tWITHDRAWAL : Successfully completed\n");
                    printf("\n\tDo you want to withdraw another Amount (0) or return (1): ");
                    scanf("%d",&rep);
                    system("cls");
                }
                else {
                    printf("\n\t\aAccount ID not found!");
                    printf("\n\n\tDo you want to enter another ID (0) or return (1): ");
                    scanf("%d",&rep);
                    system("cls");
                }
            } while(rep==0);
        }
        else {
            printf("\n\t\aCustomer ID not found!");
            printf("\n\n\tDo you want to enter another ID (0) or return (1): ");
            scanf("%d",&rep);
            system("cls");
        }
    } while(rep==0);
    operationMenu();
}

// Money transfer
void transfer() {
    FILE *fp;
    int idAccount,idCustomer;
    float balance_v;
    int rep;

    do {
        printf("\n\n\n============================  WITHDRAWAL balance  ===================================\n\n\n");
        printf("\tEnter Customer ID : ");
        scanf("%d",&idCustomer);
        if(searchCustomerById(idCustomer)==1) {
            system("cls");
            do {
                printf("\n\n\n============================  WITHDRAWAL balance  ===================================\n\n\n");
                printf("\tCustomer ID : #%08d\n",idCustomer);
                printf("\n\tAccount ID : ");
                scanf("%d",&idAccount);
                system("cls");
                printf("\n\n\n============================  WITHDRAWAL balance  ===================================\n\n\n");
                if(searchAccountById(idAccount)==1){
                    fp = fopen("bank_accounts","a");
                    printf("\tCustomer ID : #%08d\n",idCustomer);
                    printf("\n\tAccount ID : $%04d\n",idAccount);
                    printf("\n\tAmount : ");scanf("%f",&balance_v);

                    // Transfer date
                    char format[11];
                    time_t temps;
                    struct tm date;

                    time(&temps);
                    date=*localtime(&temps);

                    strftime(format,11," %x\n", &date);
                    //puts(format);
                    strcpy(date1, format);
                    balance=getBalance(idCustomer,idAccount);
                    balance+=balance_v;

                    fprintf(fp,"%d %d %.2f +%.2f %s\n",idCustomer,idAccount,balance,balance_v,date1);
                    fclose(fp);
                    Sleep(1500);
                    printf("\n\tTransfer: Successfully completed\n");
                    printf("\n\tBalance : %f",balance);
                    printf("\n\n\tDo you want to transfer another Amount (0) or return (1) : ");
                    scanf("%d",&rep);
                    system("cls");
                }
                else {
                    Sleep(1500);
                    printf("\n\t\aAccount ID not found!");
                    printf("\n\n\t;Do you want to enter another ID (0) or return (1): ");
                    scanf("%d",&rep);
                    system("cls");
                }
            } while(rep==0);
        }
        else {
            printf("\n\t\aCustomer ID not found!");
            printf("\n\n\tDo you want to enter another ID (0) or return (1): ");
            scanf("%d",&rep);
            system("cls");
        }
    } while(rep==0);
    operationMenu();
}
