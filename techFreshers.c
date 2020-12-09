#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct _register
{
char userName[54];
char emailId[54];
char password[10];
char number[12];
}Register;
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
return;
}
file=fopen("exam.data","ab");
fwrite(&register2,sizeof(Register),1,file);
fclose(file);
printf("Successfully Register!,press eneter to continue... ");
getchar();
getchar();
system("cls");
}//Register function ends here 
int main()
{
int ch;
while(1)
{
printf("1.Register\n");
printf("2.Login\n");
printf("3.Exit\n");
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
}
if(ch==3)break;
}
return 0;
}