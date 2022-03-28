#include "headerFile.h"
#include "macrosFiles.h"

struct bankUser{
        int accNum;
        char mob[MOBILE];
        char name[USER_NAME];
        int openAmt;
}userAcc;

void openNewAccount();// create new account
void showDashboard();// function for file data reading
void withdrowAmount();//function for withdrowAmount
void depositeAmount();// function for depositeAmount
int avlrollno(int rno);// check whether account is correct or not
void showUserData();// show user data

FILE  *fptr;

int mm;
// function for creating new account 
// first case
void openNewAccount(){
    
                    // open file 
                    fptr = fopen(FILE_NAME,"a");

                    system("clear");
                    printf("***Open New Account***\n");
                    printf("---------------------------------------------------------------------\n");
                    
                    
                    printf("Account Number : ");
                    scanf("%d",&userAcc.accNum);             
                    printf("\n");
                    
                    
                    printf("Name : ");
                    scanf("%s", userAcc.name);
                    printf("\n");
                    
                    
                    printf("Mobile No : ");
                    scanf("%s", userAcc.mob);
                    printf("\n");
                    
                    
                    printf("Opening Amount : ");
                    scanf("%d", &userAcc.openAmt);
                    printf("\n");
                    
                    
                    fwrite(&userAcc, sizeof(userAcc), 1, fptr);
                    fclose(fptr);
                    
                    printf("---------------------------------------------------------------------\n");
                    printf("Amount Deposited Succesfully \n");
                    printf("Account Created Succesfully!");
                    
                    printf("\nPress 1 for Main Menu");
                    scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                    else{
                        printf("\nInvalid Key Enter Key Again :");
                        scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                        
                    }
                    
                    fclose(fptr);
                
exit(0);
}

//second case 

void withdrowAmount(){
                    int getcurrBalance = 5000;
                    int withdrow_Amount ;
                    system("clear");
                    printf("***withdrow Amount***\n");
                    printf("Account Number : \n");
                    printf("------------------------Account Detailes---------------------------\n");
                    printf("Name : Sandesh\n");
                    printf("Account No : 123\n");
                    printf("Availabal Balance : %d.00", getcurrBalance);
                    printf("\n");
                    printf("Withdrow Amount : ");
                    scanf("%d",&withdrow_Amount);
                    
                    if(getcurrBalance>=withdrow_Amount){
                    printf("---------------------------------------------------------------------\n");
                        printf("Succesfully withdrowed Amount!\n");
                       printf("Availabal Balance : %d.00 ", (getcurrBalance-withdrow_Amount));
                    }
                    else{
                    printf("---------------------------------------------------------------------\n");
                        printf("Insuficient Balance!\n");
                        printf("Availabal Balance : %d.00 ", (getcurrBalance));
                    }
                    
                    printf("\nPress 1 for Main Menu");
                    scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                    else{
                        printf("\nInvalid Key Enter Key Again :");
                        scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                        
                    }
                    
                    exit(0);
                    
}
// Deposite Amount
//third case
void depositeAmount(){
    int deposite_Amount;
    int getcurrBalance = 0;
                    system("clear");
                    printf("***Deposite Amount***\n");
                    printf("Account Number : \n");
                    printf("------------------------Account Detailes---------------------------\n");
                    printf("Name : Sandesh\n");
                    printf("Account No : 123\n");
                    printf("Availabal Balance : %d.00", getcurrBalance);
                    printf("\n");
                    printf("Deposite Amount : ");
                    scanf("%d",&deposite_Amount);
                    printf("---------------------------------------------------------------------\n");
                    printf("Succesfully Deposited Amount!\n");
                    printf("Availabal Balance : %d.00 ", (getcurrBalance+deposite_Amount));
                    
                    printf("\nPress 1 for Main Menu");
                    scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                    else{
                        printf("\nInvalid Key Enter Key Again :");
                        scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                        
                    }
                    exit(0);
                    
}


//Account Data
//fourth case

void showUserData(){
                     system("clear");
                     FILE *fptr2;
                    fptr2 = fopen("bankData.txt", "r");
                    printf("\nAccount No \tName\tMobile\tBalance\n\n");
                    while (fread(&userAcc, sizeof(userAcc), 1, fptr2))
                    printf("  %d\t\t%s\t%s\t%d\n", userAcc.accNum, userAcc.name, userAcc.mob,userAcc.openAmt);
                    fclose(fptr2);
                 
                    printf("\nPress 1 for Main Menu");
                    scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                    else{
                        printf("\nInvalid Key Enter Key Again :");
                        scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                        
                    }
                    
            fclose(fptr);
}



  int avlrollno(int accno)
   {
     FILE *fp;
     int c = 0;
     fp = fopen("bankData.txt", "r");
     while (!feof(fp))
     {
        fread(&userAcc, sizeof(userAcc), 1, fp);

         if (accno == userAcc.accNum)
     {
       fclose(fp);
       return 1;
     }
   }
 fclose(fp);
 return 0;
}



void searchUser(){
            FILE *fp2;
            int r, s, avl;
            printf("\nEnter the Account No :");
            scanf("%d", &r);
            avl = avlrollno(r);
            if (avl == 0){
            printf("Account No %d is not available in the file\n",r);
                
                printf("\nPress 1 for Main Menu");
                    scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                    else{
                        printf("\nInvalid Key Enter Key Again :");
                        scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                        
                    }
                
            }
            
        else
          {
           fp2 = fopen("bankData.txt", "r");
             while (fread(&userAcc, sizeof(userAcc), 1, fp2))
            {
                 s = userAcc.accNum;
              if (s == r)
              {
                      printf("\nAccount No = %d", userAcc.accNum);
                      printf("\nName    = %s", userAcc.name);
                      printf("\nMobile    = %s", userAcc.mob);
                      printf("\nBalance    = %d", userAcc.openAmt);
              }
            }
         fclose(fp2);
         
         
         
         printf("\nPress 1 for Main Menu");
                    scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                    else{
                        printf("\nInvalid Key Enter Key Again :");
                        scanf("%d",&mm);
                    
                    if(mm==1){
                            system("clear");
                        showDashboard();
                    }
                        
                    }
        
         
         
         
         
         
     }
}


// fuunction for dashboard
void showDashboard(void){
    int i;
    int ch;
    system("clear");
    printf("\t\t\tCore Banking Menu");
    printf("\n");
    printf("\t\t\t---------------------------------------------------\n");
    printf("1. Open Account\t");
    printf("2. Withdraw Amount\t");
    printf("3. Deposite Amount\t");
    printf("4. UserList\t");
    printf("5. Search User\t");
    printf("6. Exit\t"); 
    do{
    scanf("%d",&ch);
    switch(ch){
                    case 1:
                    openNewAccount();
                    break;
                    
                    case 2:
                    withdrowAmount();
                    break;
                    
                    case 3:
                    depositeAmount();
                    break;
                    
                    case 4:
                    showUserData();
                    break;
                    
                    case 5:
                    searchUser();
                    break;
                    
                    
                    default:
                    exit(0);
                    break;
        
    }
    
    }while(ch<6);
    
}

// get Username and password function for authentication
/*void string authenticationAccount(string uname, string pass){
    
}*/

// main function
void main(){
    printf("\t\t***Welcome To Bank Management System***");
    printf("\n");
    printf("\t\t---------------------------------------------------");
    printf("\n\n");
    printf("\t\t\tLogin ");
    
    printf("\n");
    
    
    
   char username[20]; 
   char userpwd[8]; 


  // user input   
  printf("\t\t\tUsername : "); 
  scanf("%s",username); 
  printf("\t\t\tPassword : "); 
  scanf("%s",userpwd);
  
 // authentication the given data; 

 if(!strcmp(username,"admin") && !strcmp(userpwd,"123")) 
 { 
  printf("\n\nLogged In Successful"); 
  showDashboard();
 }else 
 { 
  printf("\n\t\t\tInvalid Credentials!"); 
 }
 

 
}//main function bracket