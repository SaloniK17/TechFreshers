#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
void mainMenu();
void adminMenu();
void teacherMenu();
void testMenu();
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
char format1[6],e,f,format2[8];
int found,found1;
int a,b,j,i;
format1[0]='a';
format1[1]='d';
format1[2]='m';
format1[3]='i';
format1[4]='n';
format1[5]='\0';

format2[0]='t';
format2[1]='e';
format2[2]='a';
format2[3]='c';
format2[4]='h';
format2[5]='e';
format2[6]='r';
format2[7]='\0';
while(1)
{
found=0;
found1=0;
printf("Email Id:");
fgets(emailId,54,stdin);
emailId[strlen(emailId)-1]='\0';
fflush(stdin);
j=0;
while(1)
{
a=j;
b=0;
while(emailId[a]!='\0')
{
e=emailId[a];
f=format1[b];
if(e>=97&&e<=122)e=e-32;
if(f>=97&&f<=122)f=f-32;
if(e==f)break;
a++;
}
if(emailId[a]=='\0')
{
found1=1;
break;
}
j=a;
while(emailId[a]!='\0'&&format1[b]!='\0')
{
e=emailId[a];
f=format1[b];
if(e>=97&&e<=122)e=e-32;
if(f>=97&&f<=122)f=f-32;
if(e!=f)break;
a++;
b++;
}
j++;
if(format1[b]=='\0')break;
if(emailId[a]=='\0')
{
found1=1;
break;
}
}//checking format loop end
if(found1==0)
{
 file=fopen("admin.data","rb");
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
 printf("User Name:\n");
 printf("Please enter your user name according to  this given example:name_symbol_admin\n"); 
 fgets(userName,54,stdin);
 userName[strlen(userName)-1]='\0';
 fflush(stdin);
 file=fopen("admin.data","rb");
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
 printf("Password:");
 fgets(password,10,stdin);
 password[strlen(password)-1]='\0';
 fflush(stdin);
 file=fopen("admin.data","rb");
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
 file=fopen("admin.data","ab");
 fwrite(&register2,sizeof(Register),1,file);
 fclose(file);
 printf("Successfully Register!,press eneter to continue... ");
 getchar();
 getchar();
 system("cls");
 mainMenu();
}
else
{
found1=0;
found=0;
j=0;
while(1)
{
a=j;
b=0;
while(emailId[a]!='\0')
{
e=emailId[a];
f=format2[b];
if(e>=97&&e<=122)e=e-32;
if(f>=97&&f<=122)f=f-32;
if(e==f)break;
a++;
}
if(emailId[a]=='\0')
{
found1=1;
break;
}
j=a;
while(emailId[a]!='\0'&&format2[b]!='\0')
{
e=emailId[a];
f=format2[b];
if(e>=97&&e<=122)e=e-32;
if(f>=97&&f<=122)f=f-32;
if(e!=f)break;
a++;
b++;
}
j++;
if(format2[b]=='\0')break;
if(emailId[a]=='\0')
{
found1=1;
break;
}
}//checking format loop end
if(found1==0)
{
 file=fopen("teacher.data","rb");
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
 printf("User Name:\n");
 printf("Please enter your user name according to  this given example:name_symbol_teacher\n"); 
 fgets(userName,54,stdin);
 userName[strlen(userName)-1]='\0';
 fflush(stdin);
 file=fopen("teacher.data","rb");
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
 printf("Password:");
 fgets(password,10,stdin);
 password[strlen(password)-1]='\0';
 fflush(stdin);
 file=fopen("teacher.data","rb");
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
 file=fopen("teacher.data","ab");
 fwrite(&register2,sizeof(Register),1,file);
 fclose(file);
 printf("Successfully Register!,press eneter to continue... ");
 getchar();
 getchar();
 system("cls");
 mainMenu();
}
else
{
found=0;
 file=fopen("user.data","rb");
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
 printf("User Name:");
 fgets(userName,54,stdin);
 userName[strlen(userName)-1]='\0';
 fflush(stdin);
 file=fopen("user.data","rb");
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
 printf("Password:");
 fgets(password,10,stdin);
 password[strlen(password)-1]='\0';
 fflush(stdin);
 file=fopen("user.data","rb");
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
 file=fopen("user.data","ab");
 fwrite(&register2,sizeof(Register),1,file);
 fclose(file);
 printf("Successfully Register!,press eneter to continue... ");
 getchar();
 getchar();
 system("cls");
 mainMenu();
}
}
}//infine loop end
getchar();
system("cls");
}//Register function ends here 

void forLogin()
{
char emailId[54];
char password[10];
char m;
FILE *file;
Login login1;
Register register1;
char format1[6],e,f,format2[8];
int found,found1;
int a,b,j,i;
format1[0]='a';
format1[1]='d';
format1[2]='m';
format1[3]='i';
format1[4]='n';
format1[5]='\0';

format2[0]='t';
format2[1]='e';
format2[2]='a';
format2[3]='c';
format2[4]='h';
format2[5]='e';
format2[6]='r';
format2[7]='\0';

while(1)
{
found=0;
found1=0;
printf("Username/emailId:");
fgets(emailId,54,stdin);
emailId[strlen(emailId)-1]='\0';
fflush(stdin);
j=0;
while(1)
{
a=j;
b=0;
while(emailId[a]!='\0')
{
e=emailId[a];
f=format1[b];
if(e>=97&&e<=122)e=e-32;
if(f>=97&&f<=122)f=f-32;
if(e==f)break;
a++;
}
if(emailId[a]=='\0')
{
found1=1;
break;
}
j=a;
while(emailId[a]!='\0'&&format1[b]!='\0')
{
e=emailId[a];
f=format1[b];
if(e>=97&&e<=122)e=e-32;
if(f>=97&&f<=122)f=f-32;
if(e!=f)break;
a++;
b++;
}
j++;
if(format1[b]=='\0')break;
if(emailId[a]=='\0')
{
found1=1;
break;
}
}//checking format loop end
if(found1==0)
{
file=fopen("admin.data","rb");
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
file=fopen("admin.data","rb");
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
adminMenu();
}
else
{
found=0;
found1=0;
j=a;
while(emailId[a]!='\0'&&format2[b]!='\0')
{
e=emailId[a];
f=format2[b];
if(e>=97&&e<=122)e=e-32;
if(f>=97&&f<=122)f=f-32;
if(e!=f)break;
a++;
b++;
}
j++;
if(format2[b]=='\0')break;
if(emailId[a]=='\0')
{
found1=1;
break;
}
}//checking loop ends
if(found1==0)
{
file=fopen("teacher.data","rb");
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
file=fopen("teacher.data","rb");
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
teacherMenu(); 
}
else
{
found=0;
file=fopen("user.data","rb");
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
file=fopen("user.data","rb");
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
testMenu();
}
}//infinite loop end here
}
void mainMenu()
{
system("cls");
int ch;
printf("1.Register\n");
printf("(Already register then go to Login)\n");
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
return;
}
void adminMenu()
{

}
void teacherMenu()
{


}
void testMenu()
{

}
int main()
{
mainMenu();
return 0;
}