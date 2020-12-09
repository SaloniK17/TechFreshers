#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
typedef struct _register
{
char userName[54];
char emailId[54];
char password[10];
char number[12];
}Register;

typedef struct _login
{
char emailId[54];
char password[10];
}Login;
void Instructions()
{
cout<<" Instructions:- "<<endl;
cout<<" 1. Make sure you have a good internet connection "<<endl;
cout<<" 2. Candidates are advised to connect their device using examination link before 15 minutes"<<endl;
cout<<" 3. Students will not  be allowed to appear in exam after 15 minutes from commencement of examinations"<<endl;
cout<<" 4. while answering the question , student will not have the option to go back or review or modify answers"<<endl;
cout<<" 5. The question paper consists of descriptive and objective questions "<<endl;
cout<<" 6. Student will be shown one set of questions at a time"<<endl;
cout<<" "<<endl;
}
void Do()
{
cout<<"  Do's :-  "<<endl;
cout<<" "<<endl;
cout<<" * Place the computer so that your back is facing the wall"<<endl;
cout<<" * Ensure Proper Lightening so that your face isclearly visible to camera"<<endl;
cout<<" * Ensure you are dressed formally"<<endl;
cout<<" * Do not keep mobile phones , notebooks with yourself"<<endl;
cout<<" " <<endl;
}
void Do_Not()
{
cout<<"  Don'ts :-  "<<endl;
cout<<" "<<endl;
cout<<" * Do not take help from any source"<<endl;
cout<<" * Do not take screenshorts while examinations"<<endl;
cout<<" * Do not wear any bluetooth devices"<<endl;
cout<<" * Do not play any type of noisy sources "<<endl;
cout<<" " <<endl;
}
void forRegister()
{
Register register1,register2;
char userName[54];
char emailId[54];
char password[10];
char number[12];
char m;
FILE*file;
int found;
while(1)
{
found=0;
printf("User Name:");
fgets(userName,54,stdin);
userName[strlen(userName)-1]='\0';
fflush(stdin);
file=fopen("exam.data","rb");
if(file!=NULL)
{
while(1)
{
fread(&register1,sizeof(Register),1,file);
if(feof(file))break;
if(!strcmp(register1.userName,userName))
{  
printf("That User Name is already allocate to someone,Please try next one\n");
getchar();
found=1;
fclose(file);
system("cls");
break;
}
}
}
fclose(file);
if(found==1)continue;
printf("Email Id:");
fgets(emailId,54,stdin);
emailId[strlen(emailId)-1]='\0';
fflush(stdin);
file=fopen("exam.data","rb");
if(file!=NULL)
{
while(1)
{
fread(&register1,sizeof(Register),1,file);
if(feof(file))break;
if(!strcmp(register1.emailId,emailId))
{
printf("someone already registered with %s \n",emailId);
getchar();
found=1;
fclose(file);
system("cls");
break;
}
}
}
fclose(file);
if(found==1)continue;
printf("Password:");
fgets(password,10,stdin);
password[strlen(password)-1]='\0';
fflush(stdin);
file=fopen("exam.data","rb");
if(file!=NULL)
{
while(1)
{
fread(&register1,sizeof(Register),1,file);
if(feof(file))break;
if(!strcmp(register1.password,password))
{
printf("password is invalid \n");
getchar();
found=1;
fclose(file);
system("cls");
break;
}
}
}
fclose(file);
if(found==1)continue;
printf("Mobile Number:");
fgets(number,12,stdin);
number[strlen(number)-1]='\0';
fflush(stdin);
break;
}
strcpy(register2.userName,userName);
strcpy(register2.emailId,emailId);
strcpy(register2.password,password);
strcpy(register2.number,number);
printf("Register(y/N):");
m=getchar();
if(m!='y'&&m!='Y')
{
printf("Not registerd\n");
getchar();
system("cls");
return;
}
file=fopen("exam.data","ab");
fwrite(&register2,sizeof(Register),1,file);
fclose(file);
printf("Successfully Register!,press eneter to continue... ");
getchar();
getchar();
system("cls");
Instructions();
Do();
Do_Not();
getchar();
system("cls");
}//Register function ends here 

void forLogin()
{
char emailId[54];
char password[10];
char m;
FILE *file;
int found;
Login login1;
Register register1;
while(1)
{
found=0;
printf("Username/emailId:");
fgets(emailId,54,stdin);
emailId[strlen(emailId)-1]='\0';
fflush(stdin);
file=fopen("exam.data","rb");
if(file!=NULL)
{
while(1)
{
fread(&register1,sizeof(Register),1,file);
if(feof(file))break;
if(!strcmp(register1.emailId,emailId)||!strcmp(register1.userName,emailId))
{
found=1;
break;
}
}
}
fclose(file);
if(found==0)
{
printf("Invalid eamil Id or user name,Please enter valid email Id or user name\n");
getchar();
system("cls");
continue;
}
found=0;
printf("Password:");
fgets(password,10,stdin);
password[strlen(password)-1]='\0';
fflush(stdin);
file=fopen("exam.data","rb");
if(file!=NULL)
{
while(1)
{
fread(&register1,sizeof(Register),1,file);
if(feof(file))break;
if(!strcmp(register1.password,password))
{
found=1;
break;
}
}
}
fclose(file);
if(found==0)
{
printf("Invalid password,Please enter correct password!\n");
getchar();
system("cls");
continue;
}
else break;
}
printf("Login(Y/N):");
m=getchar();
if(m!='Y'&&m!='y')
{
printf("Not Login\n");
getchar();
system("cls");
return;
}
strcpy(login1.emailId,emailId);
strcpy(login1.password,password);
printf("Successfully Login!,Please press enter o continue...");
getchar();
getchar();
system("cls");
Instructions();
Do();
Do_Not();
getchar();
system("cls");
}

int main()
{
system("cls");
int ch;
printf("1.Register\n");
printf("(If your use first time then go to register else login)\n");
printf("2.Login\n");
printf("Enter your choice:");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
system("cls");
forRegister();
}
if(ch==2)
{
system("cls");
forLogin();
}
return 0;
}