/// Structures (Nested structure)
#include<stdio.h>
#include<string.h>
#include<conio.h>


struct create_account
{
    char first_name[50];
    char last_name[50];
    char username[50];
    char password[50];

    struct birthday
    {
        int day;
        int month;
        int year;
    }birth;
    struct Sex
    {
        int male;
        int female;
    }sex;
};

void pass_gen(char *pass)
{
    int i  = 0;
    char ch;
    while(1)
    {
        ch = getch();
        if(ch==13)
            break;
        putchar('*');
        pass[i++] = ch;
    }
    pass[i] = '\0';
}

int main()
{
    struct create_account user;
    char passck[50];
    char sexck[50];
    printf("Enter Your First Name : ");
    scanf("%s",user.first_name);
    printf("\nEnter Your Last Name : ");
    scanf("%s",user.last_name);
    printf("\nEnter Your Username : ");
    scanf("%s",user.username);
    printf("\nEnter Your Password :");
    pass_gen(user.password);
    printf("\nRepeat Your Password :");
   pass_gen(passck);
    if(strcmp(user.password,passck)!=0)
    {
        printf("\nDo not match password");
        return 0;
    }
    printf("\nEnter Your Birth Date:\n");
    printf("\tDay : ");
    scanf("%d",&user.birth.day);
    printf("\tMonth : ");
    scanf("%d",&user.birth.month);
    printf("\tYear : ");
    scanf("%d",&user.birth.year);
    printf("\nEnter Your Sex (If male press m else press f) : ");
    scanf("%s",sexck);
    if(strcmp(sexck,"m")==0||strcmp(sexck,"M")==0)
    {
    user.sex.male=1;
    user.sex.female=0;
    }
    else if(strcmp(sexck,"f")==0||strcmp(sexck,"F")==0)
    {
    user.sex.male=0;
    user.sex.female=1;
    }
    else
    {
        printf("You have pressed wrong key\n");
        return 0;
    }

    printf("First Name %s\n",user.first_name);
    printf("Last Name %s\n",user.last_name);
    printf("UserName %s\n",user.username);
    printf("Password %s\n",user.password);
    printf("Date of Birth %d / %d / %d\n",user.birth.day,user.birth.month,user.birth.year);
    printf("Sex :");
    if(user.sex.male==1)
        printf("Male");
    else if(user.sex.female==1)
        printf("Female");

    return 0;
}
