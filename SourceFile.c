#include<stdio.h>           //Inclusion
#include<conio.h>           //Of
#include<string.h>          //Header
#include<stdlib.h>          //Files
#include<time.h>            //Is
#include<windows.h>         //Done
#include<ctype.h>           //In This
#include<mmsystem.h>        //Section
//Since code blocks does not have built in gotoxy() function, so we build it here
COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void fullscreen()//Mimics Alt+Enter to make full screen
{
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
void view();                                        //Function Declaration
void dataentry();
void dataadd();
void edit();
void actual_standard_model();
void music();
void login();
void check();
void titleborder();
void loginscreen();
void border();
void screen1();
void fborder();
void outro();
int particlecheck(char []);
int particlecheckcharge(char []);
int particlecheckspin(char []);
void usleep();
char pass[10],username[16];
struct particles                                //Structure Declaration
{
    char name[20];
    char symbol[20];
    char mass[20];
    char charge[20];
    char spin[20];
    char family[20];
} particle;
void search()//This function searches particles on the basis of name, charge and spin
{
    char inp='\0';
    system("cls");
    titleborder();
    border();
    gotoxy(98,7);
    printf("|Search Panel|");
    char a;
    char b[20];
    re:
    gotoxy(90,15);
        printf("[1] Type [n] to search on the basis of Name");
    gotoxy(90,16);
        printf("[2] Type [c] to search on the basis of Charge");
    gotoxy(90,17);
        printf("[3] Type [s] to search on the basis of Spin");
    gotoxy(90,18);
        printf("[4] Type [p] to goto control panel");
    gotoxy(90,22);
        printf("Enter your privilege:");
    scanf(" %c",&a);
    if((a=='n')||(a=='N'))
    {
        system("cls");
        titleborder();
        border();
        gotoxy(98,7);
            printf("|Name Search|");
        gotoxy(90,15);
             printf("Enter name of particle you want to search:\t");
        scanf(" %s",b);
        system("cls");
        titleborder();
        border();
        gotoxy(98,7);
            printf("|Name Search Result|");
        gotoxy(60,15);
            printf("Name\t\tSymbol\t\tMass\t\tCharge\t\tSpin\t\tFamily\n");
        if((particlecheck(b))==1)
        {
            FILE *sm;
            sm = fopen("particles.bin","r");
            while(fread(&particle,sizeof(particle),1,sm))
                if((strcmp(particle.name,b))==0)
                {
                    gotoxy(60,17);
                        printf("%s",particle.name);
                    gotoxy(82,17);
                        printf("%s",particle.symbol);
                    gotoxy(96,17);
                        printf("%s",particle.mass);
                    gotoxy(114,17);
                        printf("%s",particle.charge);
                    gotoxy(129,17);
                        printf("%s",particle.spin);
                    gotoxy(144,17);
                        printf("%s",particle.family);
                    break;
                }
            fclose(sm);
            gotoxy(90,22);
                printf("[1] Type [s] to go to search panel");
            gotoxy(90,23);
                printf("[2] Type any other key to go to control panel");
            gotoxy(90,26);
                printf("Enter your privilege: ");
            scanf(" %c",&inp);
            if(inp=='s')
                search();
            else
                screen1();
        }
        else if(particlecheck(b)==0)
        {
            system("cls");
            titleborder();
            border();
            gotoxy(98,7);
                printf("|Name Search|");
            gotoxy(90,15);
                printf("Particle Not Found.");
            gotoxy(90,27);
                printf("[1] Type [s] to go to search panel");
            gotoxy(90,28);
                printf("[2] Type any other key to go to control panel");
            gotoxy(90,30);
                printf("Enter your privilege: ");
            scanf(" %c",&inp);
            if(inp=='s')
                search();
            else
                screen1();
        }
    }
    else if ((a=='c')||(a=='C'))
    {
        system("cls");
        titleborder();
        border();
        gotoxy(98,7);
            printf("|Charge Search|");
        gotoxy(90,15);
            printf("Enter charge of particle you want to search:\t");
        scanf(" %[^\n]",b);
        system("cls");
        titleborder();
        border();
        gotoxy(98,7);
            printf("|Name Search Result|");
        gotoxy(60,15);
            printf("Name\t\tSymbol\t\tMass\t\tCharge\t\tSpin\t\tFamily");
        if((particlecheckcharge(b))==1)
        {
            FILE *sm;
            sm = fopen("particles.bin","r");
            int i=0,j=17;
            while(fread(&particle,sizeof(particle),1,sm))
            {
                if(strcmp(particle.charge,b)==0)
                {
                    gotoxy(60,j);
                        printf("%s",particle.name);
                    gotoxy(82,j);
                        printf("%s",particle.symbol);
                    gotoxy(96,j);
                        printf("%s/c^2",particle.mass);
                    gotoxy(114,j);
                        printf("%s",particle.charge);
                    gotoxy(129,j);
                        printf("%s",particle.spin);
                    gotoxy(144,j);
                        printf("%s",particle.family);
                    j++;
                }
                i++;
            }
            fclose(sm);
            gotoxy(90,27);
                printf("[1] Type [s] to go to search panel");
            gotoxy(90,28);
                printf("[2] Type any other key to go to control panel");
            gotoxy(90,30);
                printf("Enter your privilege: ");
            scanf(" %c",&inp);
            if(inp=='s')
                search();
            else
                screen1();
        }
        else if(particlecheck(b)==0)
        {
        system("cls");
        titleborder();
        border();
        gotoxy(98,7);
            printf("|Charge Search|");
        gotoxy(90,15);
            printf("Particle Not Found.");
        gotoxy(90,27);
            printf("[1] Type [s] to go to search panel");
        gotoxy(90,28);
            printf("[2] Type any other key to go to control panel");
        gotoxy(90,30);
            printf("Enter your privilege: ");
        scanf(" %c",&inp);
        if(inp=='s')
            search();
        else
            screen1();
        }
    }
    else if ((a=='s')||(a=='S'))
    {
        system("cls");
        titleborder();
        border();
        gotoxy(98,7);
            printf("|Spin Search|");
        gotoxy(90,15);
            printf("Enter spin of particle you want to search:\t");
        scanf(" %[^\n]",b);
        system("cls");
        titleborder();
        border();
        gotoxy(98,7);
            printf("|Name Search Result|");
        gotoxy(60,15);
            printf("Name\t\tSymbol\t\tMass\t\tCharge\t\tSpin\t\tFamily");
        if((particlecheckspin(b))==1)
        {
            FILE *sm;
            sm = fopen("particles.bin","r");
            int i=3,j=17;
            while (fread(&particle, sizeof(particle), 1, sm))
            {
                if(strcmp(b,particle.spin)==0)
                {
                    gotoxy(60,j);
                        printf("%s",particle.name);
                    gotoxy(82,j);
                        printf("%s",particle.symbol);
                    gotoxy(96,j);
                        printf("%s/c^2",particle.mass);
                    gotoxy(114,j);
                        printf("%s",particle.charge);
                    gotoxy(129,j);
                        printf("%s",particle.spin);
                    gotoxy(144,j);
                        printf("%s",particle.family);
                    j++;
                }
                i++;
            }
            fclose(sm);
            gotoxy(90,27);
                printf("[1] Type [s] to go to search panel");
            gotoxy(90,28);
                printf("[2] Type any other key to go to control panel");
            gotoxy(90,30);
                printf("Enter your privilege: ");
            scanf(" %c",&inp);
            if(inp=='s')
                search();
            else
                screen1();
        }
        else if(particlecheck(b)==0)
        {
            system("cls");
            titleborder();
            border();
            gotoxy(98,7);
                printf("|Spin Search|");
            gotoxy(90,15);
                printf("Particle Not Found.");
            gotoxy(90,27);
                printf("[1] Type [s] to go to search panel");
            gotoxy(90,28);
                printf("[2] Type any other key to go to control panel");
            gotoxy(90,30);
                printf("Enter your privilege: ");
            scanf(" %c",&inp);
            if(inp=='s')
                search();
            else
                screen1();
        }
    }
    else if (a=='p')
        screen1();
    else
    {
        system("cls");
        titleborder();
        border();
        gotoxy(98,7);
            printf("|Search Panel|");
        gotoxy(90,15);
            printf("Wrong Entry!");
        gotoxy(90,27);
            printf("[1] Type [s] to go to search panel");
        gotoxy(90,28);
            printf("[2] Type any other key to go to control panel");
        gotoxy(90,30);
            printf("Enter your privilege: ");
        scanf(" %c", &inp);
        if(inp=='s')
            search();
        else
            screen1();
    }
}
void screen1()//This is the starting page, which displays the control panel.
{
    rr:
    system("cls");
    system("color 7");
    titleborder();
    border();
    char str[6];
    gotoxy(98,7);
        printf("|CONTROL PANEL|");
    gotoxy(90,17);
        printf("[3] Type [exit] to exit the program ");
    gotoxy(90,15);
        printf("[1] Type [admin] to go to admin panel");
    gotoxy(90,16);
        printf("[2] Type [info] to goto General User Panel");
    gotoxy(90,23);
        printf("Enter you privilege:");
    scanf("%s",str);
    if( strcmp(str,"admin")==0)
    {
        system("cls");
        login();
        check();
        system("cls");
        loginscreen();
    }
    else if( strcmp(str,"info")==0)
    {
        system("cls");
        fborder();
        system("cls");
        system("COLOR 7");
        actual_standard_model();
    }
    else if( strcmp(str,"exit")==0)
    {
        system("cls");
        outro();
        exit(0);
    }
    else
    {
        gotoxy(90,26);
        printf("Wrong Input. Retry");
        _getch();
        system("cls");
        goto rr;
    }
}
void border()//This function puts border on the edges
{
    int i;
    int dots=202;
    gotoxy(0,16);
    int j =219;
    for (i = 0; i < dots; i++)
    {
        gotoxy(i+4,10);
            printf("%c",j);
        gotoxy(i+4,40);
            printf("%c",j);
    }
    for (i = 0; i < 30; i++)
    {
        gotoxy(4,i+10);
            printf("%c\n",j);
        gotoxy(205,i+10);
            printf("%c\n",j);
    }
}
void fborder()//This function is for the larger border
{
    int i;
    int dots=211;
    gotoxy(0,16);
    int j =178;
    for (i = 0; i < dots; i++)
    {
        gotoxy(i,1);
            printf("%c",j);
        gotoxy(i,50);
            printf("%c",j);
    }
    for (i = 0; i < 53; i++)
    {
        gotoxy(4,i);
            printf("%c\n",j);
        gotoxy(205,i);
            printf("%c\n",j);
            gotoxy(6,51);
            printf("Bishal Bashyal");
            gotoxy(195,51);
            printf("Atul Karn");
    }
}
void titleborder()//This function prints the title border, inside which we display the type of panel in which we are in
{
    int i;
    int q=178;
    int dots=105;
    int j =219;
    for (i = 0; i < dots; i++)
    {
        gotoxy(50+i,5);
            printf("%c",j);
    }
    for(i=0;i<=104;i++)
    {
        gotoxy(50+i,7);
            printf("%c",q);
    }
    for (i = 0; i < 5; i++)
    {
        gotoxy(50,i+5);
            printf("%c\n",j);
        gotoxy(155,i+5);
            printf("%c\n",j);
    }
}
void loginscreen()//This is the Admin panel, which displays the all the menu for admin
{
    system("color 7");
    titleborder();
    border();
    gotoxy(98,7);
        printf("|Admin Panel|");
    char inp;
    gotoxy(90,15);
        printf("[1] Press [r] to reset and retype all data");
    gotoxy(90,16);
        printf("[2] Press [e] to edit any mistakes in data");
    gotoxy(90,17);
        printf("[3] Press [a] to add more data");
    gotoxy(90,18);
        printf("[4] Press [i] to goto info mode");
    gotoxy(90,20);
        printf("[5] Press an other key to goto control panel");
    gotoxy(90,19);
        printf("[5] Press [v] to view  data");
    gotoxy(90,22);
        printf("Enter your privilege:");
    scanf(" %c",&inp);
    if(inp=='r')
        dataentry();
    if(inp=='e')
        edit();
    if(inp=='v')
        view();
    if(inp=='i')
        actual_standard_model();
    if(inp=='a')
        dataadd();
    else
        screen1();
}
void login(void)//This is the login panel, which asks the user-name and password from the user
{
    titleborder();
    border();
    gotoxy(98,7);
        printf("|LOGIN PANEL|");
    int i=0;
    gotoxy(90,15);
        printf("Enter the Username : ");
    scanf(" %[^\n]",username);
    gotoxy(90,17);
        printf("Enter The Password : ");
    while(pass[i]!=13)
    {
        pass[i]=_getch();
        if(pass[i]==13)
            break;
        printf("*");
        i++;
    }
    pass[i]='\0';
}
int verify()//This function verifies the user-name and password, returns 1 if it is correct and 0 if incorrect
{
    char a;
    if( strcmp(username,"user")==0  &&  strcmp(pass,"password")==0 )
        return 1;
    else
        return 0;
}
void check()//Takes the output from verify function and prints login successful if successful and vice versa
{
    border();
    int key;
    if(verify()==1)
    {
        system("color a");
        gotoxy(90,25);
            printf("Login Succesful");
        _getch();
        system("cls");
    }
    if(verify()==0)
    {
        system("color 4");
        gotoxy(90,25);
            printf("Login Information Incorrect.");
        gotoxy(90,26);
            printf("Press [Enter] to retry");
        gotoxy(90,27);
            printf("Press any other key to land to Control Panel");
        fflush(stdin);
        key=_getch();
        if(key!=13)
        {
            screen1();
        }
        else
        {
            system("cls");
            system("color 7");
        login();
        verify();
        check();
        }
    }
}
void music()//This function welcomes the user by changing colors and playing music
{
    fborder();
    system("color 4f");
    int delayer = 20; // this is defined for milliseconds
    int numDots = 211;
    int j=219;
    char prompt[] = "WELCOME";
    printf("\e[?25l"); //This one is for Hiding Cursor, thIS WORD written in fput \E[?251 was taken as ANSI codesheet from devhints.io/ansi//
    char buf[16];
    int i;
    PlaySound(TEXT("namer2.wav"),NULL,SND_ASYNC);
    while (1)
    {
        gotoxy(105,23);
            printf("%s",prompt);
        gotoxy(0,16);
        for (i = 0; i < numDots; i++)
        {
            gotoxy(i,16);
            usleep(delayer*1000);
            int j =219;
            printf("%c",j);
            snprintf(buf, sizeof(buf), "color %1d",i/10);
            system(buf);
            gotoxy(i,30);
            printf("%c",j);
        }
        for (i = 0; i < 30-17; i++)
        {
            usleep(delayer*400);
            gotoxy(0,i+17);
                snprintf(buf, sizeof(buf), "color %1d",i/10);
            system(buf);
            printf("%c\n",j);
            gotoxy(210,i+17);
                printf("%c\n",j);
        }
        for (i = 0; i < 30-17; i++)
        {
            usleep(delayer*400);
            gotoxy(i^2,i+17);
                snprintf(buf, sizeof(buf), "color %1d",i/2);
            system(buf);
            printf("%c\n",j);
            gotoxy(210-i^2,i+17);
                printf("%c\n",j);
        }
        break;
    }
    gotoxy(95,35);
        printf("|Press any key to Continue|");
    _getch();
    system("cls");
}
void view()//This function displays all the particles in table form for the use of admin
{
    system("cls");
    border();
    titleborder();
    gotoxy(98,7);
        printf("|VIEW PANEL|");
    gotoxy(90,15);
    FILE *sm;
    sm = fopen("particles.bin","rb" );
    int i=0;
    gotoxy(60,15);
        printf("Name\t\tSymbol\t\tMass\t\tCharge\t\tSpin\t\tFamily");
    while (fread(&particle, sizeof(particle), 1, sm))
    {
        gotoxy(60,i+17);
            printf("%s",particle.name);
        gotoxy(82,i+17);
            printf("%s",particle.symbol);
        gotoxy(96,i+17);
            printf("%s",particle.mass);
        gotoxy(114,i+17);
            printf("%s",particle.charge);
        gotoxy(129,i+17);
            printf("%s",particle.spin);
        gotoxy(144,i+17);
            printf("%s",particle.family);
        i++;
    }
    gotoxy(90,36);
    printf("|Press any key to Continue|");
    _getch();
    system("cls");
    loginscreen();
}
void main()//This is the main function
{
    fullscreen();
    music();
    screen1();
}
int particlecheck(char a[10])//This function checks whether the particle exists or not on the basis of name
{
    FILE *sm;
    sm =fopen("particles.bin", "rb");
    while(!feof(sm))
    {
        fread(&particle, sizeof(particle), 1, sm);
        if (strcmp(a,particle.name)==0)
        {
            fclose(sm);
            return 1;
        }
    }
    fclose(sm);
    return 0;
}
void edit()//This function edits individual particles
{
    char c;
    FILE *sm ,*sm1;
    char a[20];
    system("cls");
    border();
    titleborder();
    gotoxy(98,7);
        printf("|EDIT PANEL|");
    gotoxy(90,15);
        printf("Enter The Particle To Edit : ");
    scanf(" %[^\n]",a);
    if ((particlecheck(a))==1)
    {
        system("cls");
        border();
        titleborder();
        gotoxy(98,7);
            printf("|EDIT PANEL|");
        gotoxy(90,18);
            printf("The Particle exists.");
        gotoxy(90,19);
            printf("Press any key to edit its value");
        _getch();
        system("cls");
        border();
        titleborder();
        gotoxy(98,7);
            printf("|EDIT PANEL|");
        if(1)
        {
            sm = fopen("particles.bin", "rb");
            sm1 = fopen("New.bin", "wb");
            while ( fread(&particle,sizeof(particle),1,sm) )
            {
                border();
                titleborder();
                gotoxy(98,7);
                    printf("|EDIT PANEL|");
                if (strcmp(a,particle.name)!= 0)
                    fwrite(&particle,sizeof(particle),1,sm1);
                else if(strcmp(a,particle.name)== 0)
                {
                    gotoxy(90,16);
                        printf("Enter new data:");
                    gotoxy(90,17);
                        printf("Enter The Name :\t ");
                    scanf(" %[^\n]",particle.name);
                    gotoxy(90,18);
                        printf("Enter The Symbol :\t ");
                    scanf(" %[^\n]",particle.symbol);
                    gotoxy(90,19);
                        printf("Enter The Mass :\t ");
                    scanf(" %{^\n]",particle.mass);
                    gotoxy(90,20);
                        printf("Enter The Charge :\t ");
                    scanf(" %[^\n]",particle.charge);
                    gotoxy(90,21);
                        printf("Enter The Spin :\t ");
                    scanf(" %[^\n]",particle.spin);
                    gotoxy(90,22);
                        printf("Enter The Family :\t ");
                    scanf(" %[^\n]",particle.family);
                    fwrite(&particle,sizeof(particle),1,sm1);
                    gotoxy(90,23);
                        printf("Do you want to edit more data[y/n]?:");
                    scanf(" %c",&c);
                    if(c=='y')
                        edit();
                    }
                }
                fclose(sm);
                fclose(sm1);
            }
            remove("particles.bin");
            rename("New.bin","particles.bin");
            gotoxy(90,24);
                printf("Particle information edited");
            gotoxy(90,25);
                printf("Press any key to continue to Admin Panel");
            _getch();
            system("cls");
            loginscreen();
        }
        else
        {
            printf("Particle Does not exist");
            printf("Retype particles name");
            _getch();
            edit();
        }
}
void dataentry()//This function is to enter data of particles from the start
{
    system("cls");
    FILE *sm;
    sm=fopen("particles.bin", "wb");
    int i;
    char b;
    do
    {
        titleborder();
        gotoxy(98,7);
            printf("|Data Panel|");
        border();
        gotoxy(90,15);
            printf("Enter name of the particle:\t");
        scanf(" %[^\n]",particle.name);
        gotoxy(90,16);
            printf("Enter symbol of particle");
        scanf(" %[^\n]",particle.symbol);
        gotoxy(90,17);
            printf("Enter mass of particle");
        scanf(" %s",particle.mass);
        gotoxy(90,18);
            printf("Enter charge of particle");
        scanf(" %[^\n]",particle.charge);
        gotoxy(90,19);
            printf("Enter spin of particle");
        scanf(" %[^\n]",particle.spin);
        gotoxy(90,20);
            printf("Enter family of particle");
        scanf(" %[^\n]",particle.family);
        gotoxy(90,22);
        fwrite(&particle , sizeof(particle) , 1 ,sm );
        i++;
        printf("Do you want to add more?[y/n]");
        scanf(" %c",&b);
        system("cls");
    }
    while(b=='y'||b=='Y');
    fclose(sm);
}
void dataadd()//This function is to add more particles
{
    system("cls");
    FILE *sm;
    sm=fopen("particles.bin", "ab");
    int i;
    char b;
    do
    {
        titleborder();
        gotoxy(98,7);
            printf("|Data Panel|");
        border();
        gotoxy(90,15);
            printf("Enter name of the particle:\t");
        scanf(" %[^\n]",particle.name);
        gotoxy(90,16);
            printf("Enter symbol of particle");
        scanf(" %[^\n]",particle.symbol);
        gotoxy(90,17);
            printf("Enter mass of particle");
        scanf(" %s",particle.mass);
        gotoxy(90,18);
            printf("Enter charge of particle");
        scanf(" %[^\n]",particle.charge);
        gotoxy(90,19);
            printf("Enter spin of particle");
        scanf(" %[^\n]",particle.spin);
        gotoxy(90,20);
            printf("Enter family of particle");
        scanf(" %[^\n]",particle.family);
        fwrite(&particle , sizeof(particle) , 1 ,sm );
        i++;
        gotoxy(90,22);
            printf("Do you want to add more?[y/n]");
        scanf(" %c",&b);
        system("cls");
    }
    while(b=='y'||b=='Y');
    fclose(sm);
}
void actual_standard_model()//This function prints the actual standard model
{
    system("cls");
    fborder();
    int q;
    int n=219;
    q=220;
    FILE *sm;
    sm = fopen("particles.bin","rb" );
    int i;
    for(i=0;i<=40;i++)
    {
        gotoxy(65+i,3);
        printf("%c",q-44);
        gotoxy(123+i,3);
        printf("%c",q-44);
    }
    gotoxy(97,3);
        printf("STANDARD MODEL OF PARTICLE PHYSICS");
    gotoxy(77,6);
        printf("Three Generations Of Matter(Fermions)");
    gotoxy(126,6);
        printf("Interactions/Force Carriers(Bosons)");
    gotoxy(60,8);
        printf("Mass");
    gotoxy(58,9);
        printf("Charge");
    gotoxy(60,10);
        printf("Spin");
    char a[7]="QUARKS";
    for (i=0;i<7;i++)
    {
        gotoxy(63,i+15);
        printf("%c",a[i]);
    }
    char b[7]="LEPTONS";
    for (i=0;i<7;i++)
    {
        gotoxy(63,i+29);
        printf("%c",b[i]);
    }
    char g[7]="SCALAR";
    char h[7]="BOSONS";
    for (i=0;i<6;i++)
    {
        gotoxy(165,i+9);
        printf("%c",g[i]);
        gotoxy(168,i+9);
        printf("%c",h[i]);
    }
    char jk[7]="VECTOR";
    char lm[7]="BOSONS";
    for (i=0;i<6;i++)
    {
        gotoxy(146,i+19);
        printf("%c",jk[i]);
        gotoxy(146,i+30);
        printf("%c",lm[i]);
    }
    gotoxy(65,7);
    for(i=1;i<=99;i++)
        printf("%c",q);
    gotoxy(66,15);
    for(i=1;i<=97;i++)
        printf("%c",q);
    gotoxy(66,23);
    for(i=1;i<=78;i++)
       printf("%c",q);
    gotoxy(66,31);
    for(i=1;i<=78;i++)
       printf("%c",q);
    gotoxy(66,39);
    for(i=1;i<=78;i++)
       printf("%c",q);
    for(i=1;i<=31;i++)
    {
        gotoxy(65,7+i);
            printf("%c",n);
    }
    for(i=1;i<=32;i++)
    {
        gotoxy(65,7+i);
            printf("%c",n);
    }
    for(i=1;i<=32;i++)
    {
        gotoxy(85,7+i);
            printf("%c",n);
    }
    for(i=1;i<=32;i++)
    {
        gotoxy(105,7+i);
            printf("%c",n);
    }
    for(i=1;i<=32;i++)
    {
        gotoxy(125,7+i);
            printf("%c",n);
    }
    for(i=1;i<=32;i++)
    {
        gotoxy(144,7+i);
            printf("%c",n);
    }
    for(i=1;i<=8;i++)
    {
        gotoxy(163,7+i);
        printf("%c",n);
    }
    int j=0;
    for(i=0;i<=4;i++)
    {
        fread(&particle, sizeof(particle), 1, sm);
        gotoxy(68+j,8);
            printf("%s/c^2",particle.mass);
        gotoxy(68+j,9);
            printf("%s",particle.charge);
        gotoxy(68+j,10);
            printf("%s",particle.spin);
        gotoxy(73+j,12);
            printf("%s",particle.symbol);
        gotoxy(72+j,14);
            printf("%s",particle.name);
        j=j+20;
    }
    j=0;
    for(i=0;i<=3;i++)
    {
        fread(&particle, sizeof(particle), 1, sm);
        gotoxy(68+j,16);
            printf("%s/c^2",particle.mass);
        gotoxy(68+j,17);
            printf("%s",particle.charge);
        gotoxy(68+j,18);
            printf("%s",particle.spin);
        gotoxy(73+j,20);
            printf("%s",particle.symbol);
        gotoxy(72+j,22);
            printf("%s",particle.name);
        j=j+20;
    }
    j=0;
    for(i=0;i<=3;i++)
    {
        fread(&particle, sizeof(particle), 1, sm);
        gotoxy(68+j,24);
            printf("%s/c^2",particle.mass);
        gotoxy(68+j,25);
            printf("%s",particle.charge);
        gotoxy(68+j,26);
            printf("%s",particle.spin);
        gotoxy(73+j,28);
            printf("%s",particle.symbol);
        gotoxy(72+j,30);
            printf("%s",particle.name);
        j=j+20;
     }
    j=0;
    for(i=0;i<=3;i++)
    {
        fread(&particle, sizeof(particle), 1, sm);
        gotoxy(68+j,32);
            printf("%s/c^2",particle.mass);
        gotoxy(68+j,33);
            printf("%s",particle.charge);
        gotoxy(68+j,34);
            printf("%s",particle.spin);
        gotoxy(73+j,36);
            printf("%s",particle.symbol);
        gotoxy(72+j,38);
            printf("%s",particle.name);
        j=j+20;
     }
    fclose(sm);
    gotoxy(88,42);
        printf("[1] Press [enter] to goto search panel");
    gotoxy(88,43);
        printf("[2] Press any other key to goto control panel");
    char s;
    int d;
    d=_getch();
    if(d==13)
        search();
    else
        screen1();
}
int particlecheckcharge(char a[20])//This function checks whether the particle exists or not on the basis of charge
{
    FILE *sm;
    sm =fopen("particles.bin", "r");
    while(!feof(sm))
    {
        fread(&particle, sizeof(particle), 1, sm);
        if (strcmp(a,particle.charge)==0)
        {
            fclose(sm);
            return 1;
        }
    }
    fclose(sm);
    return 0;
}
int particlecheckspin(char a[20])//This function checks whether the particle exists or not on the basis of spin
{
    FILE *sm;
    sm =fopen("particles.bin", "r");
    while(!feof(sm))
    {
        fread(&particle, sizeof(particle), 1, sm);
        if (strcmp(a,particle.spin)==0)
        {
            fclose(sm);
            return 1;
        }
    }
    fclose(sm);
    return 0;
}
void outro()//This function welcomes the user by changing colors and playing music
{
    fborder();
    system("color 4f");
    int delayer = 20; // this is defined for milliseconds
    int numDots = 211;
    int j=219;
    char prompt[] = "THANK YOU!";
    printf("\e[?25l"); //This one is for Hiding Cursor, thIS WORD written in fput \E[?251 was taken as ANSI codesheet from devhints.io/ansi//
    char buf[16];
    int i;
    PlaySound(TEXT("namer2.wav"),NULL,SND_ASYNC);
    while (1)
    {
        gotoxy(105,23);
            printf("%s",prompt);
        gotoxy(0,16);
        for (i = 0; i < numDots; i++)
        {
            gotoxy(i,16);
            usleep(delayer*1000);
            int j =219;
            printf("%c",j);
            snprintf(buf, sizeof(buf), "color %1d",i/9);
            system(buf);
            gotoxy(i,30);
                printf("%c",j);
        }
        for (i = 0; i < 30-17; i++)
        {
            usleep(delayer*400);
            gotoxy(0,i+17);
                snprintf(buf, sizeof(buf), "color %1d",i/9);
            system(buf);
            printf("%c\n",j);
            gotoxy(210,i+17);
                printf("%c\n",j);
        }
        for (i = 0; i < 30-17; i++)
        {
            usleep(delayer*40);
            gotoxy(i^2,i+17);
                snprintf(buf, sizeof(buf), "color %1d",i/2);
            system(buf);
            printf("%c\n",j);
            gotoxy(210-i^2,i+17);
                printf("%c\n",j);
        }
        break;
    }
    gotoxy(95,35);
        printf("|Press any key to Exit|");
    _getch();
    system("cls");
}
