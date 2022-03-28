#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void showDashboard(void);
int mm;
FILE  *fptr;
// function for creating new account 
// first case
void openNewAccount(){
    
                    // open file 
                    fptr = fopen("D:\\bankData.txt","a");
                    int accNum;
                    char mob[20];
                    char name[50];
                    char accType;
                    int openAmt;
                    char menuBut;
                    char typ;
                    
                    system("clear");
                    printf("***Open New Account***\n");
                    printf("---------------------------------------------------------------------\n");
                    printf("Account Number : ");
                    scanf("%d",&accNum);
                    fprintf(fptr,"\n%d\t\t\t",accNum);
                    printf("\n");
                    printf("Name : ");
                    scanf("%s",name);
                    fprintf(fptr,"%s\t\t\t",name);
                    printf("\n");
                    printf("Mobile No : ");
                    scanf("%s",mob);
                    fprintf(fptr,"%s\t\t\t",mob);
                    printf("\n");
                    
                    printf("Account Type(S/C): ");
                    scanf("%s",&typ);
                    if(typ=='s'||typ=='S'){
                        printf("A/C Type : Saving\n");
                        fprintf(fptr,"%c\t\t\t",typ);
                    }
                    else{
                        printf("A/C Type : Current\n");
                        fprintf(fptr,"%c\t\t\t",typ);
                    }
                    printf("\n");
                    
                    printf("Opening Amount : ");
                    scanf("%d",&openAmt);
                    fprintf(fptr,"%d\t\t\t",openAmt);
                    printf("\n");
                    printf("---------------------------------------------------------------------\n");
                    printf("Amount Deposited %d ", openAmt);
                    printf("Succesfully!\n");
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
    int getcurrBalance = 5000;
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
                    fptr = fopen("D:\\bankData.txt","r");
                    char ch;
                    printf("\t\t\t\t\t\t***Customer List***\n");
                   // printf("\t\t\t\t\tA/c No\tName\tMobile\tA/C Type\tBalance");
                   printf("A/C No\t\t\t");
                   printf("Name\t\t\t");
                   printf("Mobile\t\t\t");
                   printf("A/C Type\t\t\t");
                   printf("Balance\t\t\t");
                   printf("\n------------------------------------------------------------------------------------------------------------------------");
                   
                   if(NULL==fptr){
                       printf("\nNo Userdata Found!");
                   }
                   
                   else{
                       do {
                         ch = fgetc(fptr);
                         printf("%c", ch);
                        } while (ch != EOF);
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
                    
                                                              fclose(fptr);

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
    printf("5. Exit\t"); 
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

