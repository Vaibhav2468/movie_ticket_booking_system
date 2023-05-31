#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "conio2.h"
#include <dir.h>
#include <errno.h>
//function decration
struct login{
char fname[30];
char lname[30];
char username[30];
char password[30];
};
struct admin{
char admin_username[30];
char admin_password[30];
};
struct book
{
	char index_no[5];
	char theatre[20];
	char movie[20];
	char s_cost[5];
	char p_cost[5];
	char address[40];
}b;
struct ticket
{
    char show_time[6];
    char name[6];
}t;
void final_book(char*,char*,char*,char*,char*,char*,char*,int,int,int,int,int,char*);
void theatre_t(char*,char*,char*,char*,char*,char*,char*);
void theatre_a();
void theatre_b();
void theatre_c();
void theatre_d();
void theatre_e();
void show_time(char*,char*,char*,char*,char*,char*);
void select_theatre();
void show_theatre();
void menu();//after login
void my_booking();
void insert_details();
void succesfully_login();//admin
void admin(void);
void regist(void);
void login(void);
void upper_screen();
void print_char(char,int,int,int);
void print_title(char*,int,int,int);
void print_title_in_middle(char*,int,int);
void print_basic_screen();
///MMMMMMMMMMMM int main MMMMMMMMMMMMMMMMMMMMMMMMMMMMM
int main()
{
    int result=mkdir("H:\\Movie Ticket Booking APP");
    if(result!=0 && errno!=17)
    {
    printf("Sorry! Application can not run");
    printf("\nError code:%d,",errno);
    perror("Reason");
    return 1;
    }
    int n;
    print_basic_screen();
    print_title("1.Admin",35,8,LIGHTCYAN);
    print_title("2.sign in",35,9,LIGHTCYAN);
    print_title("3.sign up",35,10,LIGHTCYAN);
    print_title_in_middle("enter your responce:",11,LIGHTCYAN);
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        {
            admin();
            break;
        }
    case 2:
        {
           login();
            break;
        }
    case 3:
        {
           regist();
            break;
        }
        default:
        {
            print_title_in_middle("please enter correct input...",12,RED);
            getch();
            main();
        }
    }
}
///DEFINATIN DESIGNs***********************************************
void print_char(char ch,int reps,int row,int text_color)
{
    textcolor(text_color);
    gotoxy(1,row);
    for(int i=1;i<=reps;i++)
    {
        printf("%c",ch);
    }
}
void print_title(char *title,int column,int row,int text_color){
    textcolor(text_color);
    gotoxy(column,row);
    printf("%s",title);
}
void print_title_in_middle(char* title,int row,int text_color){
    textcolor(text_color);
    int column=(80-strlen(title))/2;
    gotoxy(column,row);
    printf("%s",title);
}
void print_basic_screen()
{
    clrscr();
    print_title_in_middle("MOVIE TICKET BOOKING APP",2,CYAN);
    print_char('-',80,1,LIGHTCYAN);
    print_char('-',80,3,LIGHTCYAN);
    print_char('-',80,6,LIGHTCYAN);
    print_char('-',80,22,LIGHTCYAN);
}
void upper_screen()
{
    print_char('-',80,1,LIGHTCYAN);
    print_title_in_middle("MOVIE TICKET BOOKING APP",2,LIGHTCYAN);
    print_char('-',80,3,LIGHTCYAN);
    print_char('-',80,6,LIGHTCYAN);
}
///======================ADMIN/REGIST/LOGIN=======================================================
void admin()
{
    int n;
    print_basic_screen();
    struct admin a;
    char data_username[30]={"admin@gmail.com"};
    char data_password[30]={"123456"};
    print_title_in_middle("Admin login",7,BROWN);
    print_title_in_middle("enter your user id:",9,LIGHTCYAN);
    scanf("%s",a.admin_username);
    print_title_in_middle("enter your password:",10,LIGHTCYAN);
    scanf("%s",a.admin_password);
    if(strcmp(a.admin_username,data_username)==0&&strcmp(a.admin_password,data_password)==0)
    {
        succesfully_login();
    }
      else
      {
          print_title_in_middle("Please Enter correct UserID and Password/tri again",11,RED);
          getch();
          admin();
      }
}
void succesfully_login()
{
    print_basic_screen();
    int n;
    print_basic_screen();
    print_title_in_middle("succesfully login...",7,LIGHTGREEN);
    print_title("1.insert details",35,8,LIGHTCYAN);
    print_title("2.show theatres",35,9,LIGHTCYAN);
    print_title("3.Back",35,10,LIGHTCYAN);
    print_title("4.Home",35,11,LIGHTCYAN);
    print_title("Enter your response:",35,12,LIGHTCYAN);
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        {
        insert_details();
        break;
        }
    case 2:
        {
        show_theatre();
        print_title("continue back..",1,23,LIGHTCYAN);//theatre dekhne ke baad succefully login chalana hai
        getch();
        succesfully_login();//yaha isliye kyoki booking ke time jab show_theatre chale  toh ye function na chale vaha par
        break;
        }
    case 3:
        {
        admin();
        break;
        }
     case 4:
         {
        main();
        break;
         }
    default:
        {
        print_title("plese give correct input..",35,13,RED);
        getch();
        succesfully_login();
        }
    }
}
void regist()
{
    print_basic_screen();
    FILE *fp;
    struct login b,c;
    print_title_in_middle("SIGN UP",7,BROWN);
    print_title("Enter first name:",35,9,LIGHTCYAN);
    scanf("%s",b.fname);
    print_title("Enter last name:",35,10,LIGHTCYAN);
    scanf("%s",b.lname);
    print_title("username:",35,11,LIGHTCYAN);
    scanf("%s",b.username);
    print_title("Enter password:",35,12,LIGHTCYAN);
    scanf("%s",b.password);
    fp=fopen("H:\\Movie Ticket Booking APP\\regist.txt","a");
	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%s %s \n",b.username,b.password);
	}
	fclose(fp);
    print_title("account created...",35,13,LIGHTGREEN);
    getch();
    login();
}
void login()
{
    int n;
    print_basic_screen();
    char user_id[30],pass_word[20];
    print_title("user sign in",35,7,BROWN);
    print_title("enter your user id:",35,9,LIGHTCYAN);
    scanf("%s",user_id);
    print_title("enter your password:",35,10,LIGHTCYAN);
    scanf("%s",pass_word);
    struct login b,c;
    FILE*fp;
    int available=0;//important
    fp = fopen("H:\\Movie Ticket Booking APP\\regist.txt","r");
	if(fp == NULL)
	{
        print_title_in_middle("Please Enter correct UserID and Password/tri again",11,RED);
        print_title_in_middle("new user first sign up...",12,RED);
        getch();
        main();
    }
	rewind(fp);
	fscanf(fp,"%s %s",c.username,c.password);
    while(feof(fp)==0)//while(fgetc(fp)!=EOF)
    {
        if(strcmp(user_id,c.username)==0&&strcmp(pass_word,c.password)==0)
        {
            menu();
            available=1;
        }
        fscanf(fp,"%s %s",c.username,c.password);
    }
        if(available!=1)
        {
            print_title_in_middle("Please Enter correct UserID and Password/new user first registerd",23,RED);
            getch();
            main();
            fclose(fp);
        }
}
///iiiiiiiiiiiiiiii insert_details iiiiiiiiiiiiiiiiiiiiiiii
void insert_details()
{
    char ch;
    do
    {
    print_basic_screen();
	FILE *fp;
	struct book b;
    print_title("enter theatre index no.:",35,8,LIGHTCYAN);
	scanf("%s",b.index_no);
    print_title("enter theatre name:",35,9,LIGHTCYAN);//bina space ke
    scanf("%s",b.theatre);//gets yaha nahi chal sakta /bina space ke name de;
    print_title("enter movie name:",35,10,LIGHTCYAN);
	scanf("%s",b.movie);
	print_title("enter silver cost:",35,11,LIGHTCYAN);
	scanf("%s",b.s_cost);
	print_title("enter platinam cost:",35,12,LIGHTCYAN);
	scanf("%s",b.p_cost);
	print_title("enter address:",35,13,LIGHTCYAN);
	scanf("%s",b.address);
	fp=fopen("H:\\Movie Ticket Booking APP\\insert_details.txt","a");
	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%s %s %s %s %s %s\n",b.index_no,b.theatre,b.movie,b.s_cost,b.p_cost,b.address);//\n for new line
		print_title("record insert succesfully",35,14,LIGHTGREEN);

	}
	fclose(fp);
	//////////////////////////////////////////////////////////////////////////
	if(strcmp(b.index_no,"1")==0)//agar index ki value 1 di hai toh thaertor_a chalge
	theatre_a();
	else if(strcmp(b.index_no,"2")==0)
    theatre_b();
    else if(strcmp(b.index_no,"3")==0)
    theatre_c();
    else if(strcmp(b.index_no,"4")==0)
    theatre_d();
    else if(strcmp(b.index_no,"5")==0)
    theatre_e();
    //////////////////////////////////////////////////////////////////
    print_title("would you want add another theatre y/n",35,15,LIGHTGREEN);
    fflush(stdin);
    scanf("%c",&ch);
    }while(ch=='y');
	print_title("continue home screen...",1,23,LIGHTGREEN);
	getch();
	main();
}
///LLLLLLLLLLLLLLLL   AFTER LOGIN LLLLLLLLLLLLLLLLLLLLLLLLLLLL
void menu()
{
    print_basic_screen();
    print_title("successfully login...",35,7,GREEN);
    print_title("1.book ticket",35,8,LIGHTCYAN);
    print_title("2.my bookings",35,9,LIGHTCYAN);
    print_title("3.Back",35,10,LIGHTCYAN);
    print_title("4.Home",35,11,LIGHTCYAN);
    print_title("Enter your response:",35,12,LIGHTCYAN);
    int n;
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        {
            show_theatre();
            break;
        }
    case 2:
        {
            my_booking();
            break;
        }
    case 3:
        {
            login();
            break;
        }
    case 4:
        {
            main();
            break;
        }
  }
}
///BBBBBBBBBBBBBBBBBBB BOOKING BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBb
void show_theatre()
{
    system("cls");
    upper_screen();//beacase basick screen yaha nahi chal sakta
    FILE*fp;
    char ch;
    fp = fopen("H:\\Movie Ticket Booking APP\\insert_details.txt","r");
	if(fp == NULL)
	{
		printf("file does not found!");
		printf("\ncontinue home....");
		getch();
		main();
	}
	else
	{
        textcolor(BROWN);
        printf("index_no|theatre|movie|silver |platinam|address\n");
		while( ( ch = fgetc(fp) ) != EOF )
        {
            textcolor(LIGHTCYAN);
      		printf("%c",ch);
        }
	}
	fclose(fp);
    print_char('-',80,22,LIGHTCYAN);
    select_theatre();
}
void select_theatre()
{
    char index_no[5];
	print_title("enter index_no:",1,14,LIGHTCYAN);
	scanf("%s",index_no);
	struct book b;
	FILE *fp;
	int available=0;//important
	fp = fopen("H:\\Movie Ticket Booking APP\\insert_details.txt","r");
	if(fp == NULL)
	{
	    printf("file does not found!");
		printf("\ncontinue home....");
		getch();
		main();

	}
	rewind(fp);//for wabas end to first
	fscanf(fp,"%s %s %s %s %s %s",b.index_no,b.theatre,b.movie,b.s_cost,b.p_cost,b.address);
    while(feof(fp)==0)// while(fgetc(fp)!=EOF)
    {
        if(strcmp(index_no,b.index_no)==0)
        {
            print_title("found movie:",1,15,LIGHTGREEN);
            textcolor(LIGHTCYAN);
            printf("\nindex_no :%s",b.index_no);
            printf("\ntheatre name :%s",b.theatre);
            printf("\nMovie name :%s",b.movie);
            printf("\nsilver ticket cost:%s",b.s_cost);
            printf("\nplatinam ticket cost:%s",b.p_cost);
             printf("\nadress :%s",b.address);
            printf("\n\ncontinue...");
            getch();
            available =1;
            break;
        }
        fscanf(fp,"%s %s %s %s %s %s",b.index_no,b.theatre,b.movie,b.s_cost,b.p_cost,b.address);
    }
    if(available!=1)
    {
        printf("movie not found /trai again");
        getch();
        show_theatre();
        fclose(fp);
    }
////////////////////////////////////////////////
show_time(b.index_no,b.theatre,b.movie,b.s_cost,b.p_cost,b.address);
}
void show_time(char*index,char* theatre,char* movie,char* s_cost,char* p_cost,char*address)
{
    print_basic_screen();
    char show_time_a[5][6]={{"9 AM"},{"12 PM"},{"3 PM"},{"12 PM"},{"9 PM"}};
    int n;//take show time
    char show_time[6];
    int available=0;//important//yadi dusri baar program chalta hai toh available ki value ko bapas 0 karna
    int i;
    print_title_in_middle("show time running",7,BROWN);
    print_title("1.9:00 AM",35,8,LIGHTCYAN);
    print_title("2.12:00 PM",35,9,LIGHTCYAN);
    print_title("3.3:00 PM",35,10,LIGHTCYAN);
    print_title("4.6:00 PM ",35,11,LIGHTCYAN);
    print_title("5.9:00 PM",35,12,LIGHTCYAN);
    print_title("Enter your show time",35,13,LIGHTCYAN);
    scanf("%d",&n);
    for(i=0;i<=4;i++)
    {
        if(n==i+1)
        {
            strcpy(show_time,show_time_a[i]);
            available=1;
        }
    }
     if(available!=1)
    {
        print_title("not available show time",35,15,LIGHTCYAN);
        getch();
            select_theatre();//yadi ye chalta hai toh niche wali file nahi chalegi
    }
theatre_t(index,theatre,movie,s_cost,p_cost,address,show_time);
}
void theatre_t(char* index,char* theatre,char* movie,char* s_cost,char* p_cost,char* address,char* show_time)//function name and passed variable should be uniqe
{
     int ss_cost=atoi(s_cost);//string to intiger convert
     int pp_cost=atoi(p_cost);//
     char crr[60][3]={{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"},{"10"},{"11"},{"12"},{"13"},{"14"},{"15"},{"16"},{"17"},{"18"},{"19"},{"20"},{"21"},{"22"},{"23"},{"24"},{"25"},{"26"},{"27"},{"28"},{"29"},{"30"},//which never change
     {"31"},{"32"},{"33"},{"34"},{"35"},{"36"},{"37"},{"38"},{"39"},{"40"},{"41"},{"42"},{"43"},{"44"},{"45"},{"46"},{"47"},{"48"},{"49"},{"50"},{"51"},{"52"},{"53"},{"54"},{"55"},{"56"},{"57"},{"58"},{"59"},{"60"}};
    char arr[60][3];
    char brr[3];//enter your desired seat
    char x[3]={"X"};
    char ch;//yes no cheq
    int i;
    int silver=0;//count silver ticket
    int platinam=0;//count platinam ticket
    int silver_cost=0;
    int platinam_cost=0;
    int total_cost;
    FILE*fp;
    do
    {
        int available=0;//imprtant availbale ki value vapas 0 kardo becasuse do while
        if(strcmp(index,"1")==0)
            fp=fopen("H:\\Movie Ticket Booking APP\\theatre_a.txt","r");
        else if(strcmp(index,"2")==0)
            fp=fopen("H:\\Movie Ticket Booking APP\\theatre_b.txt","r");
        else if(strcmp(index,"3")==0)
            fp=fopen("H:\\Movie Ticket Booking APP\\theatre_c.txt","r");
        else if(strcmp(index,"4")==0)
            fp=fopen("H:\\Movie Ticket Booking APP\\theatre_d.txt","r");
        else if(strcmp(index,"5")==0)
            fp=fopen("H:\\Movie Ticket Booking APP\\theatre_e.txt","r");
	if(fp ==NULL)
	{
		printf("FIle not Found");
	}
	else
	{              //1  2  3  4  5  6  7 8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 2930 31 32 33 34 35 36 37 38 39 4041 42  43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60
		fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
 arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19],arr[20],arr[21],arr[22],arr[23],arr[24],arr[25],arr[26],arr[27],arr[28],arr[29],arr[30],
 arr[31],arr[32],arr[33],arr[34],arr[35],arr[36],arr[37],arr[38],arr[39],arr[40],arr[41],arr[42],arr[43],arr[44],arr[45],arr[46],arr[47],arr[48],arr[49],arr[50],arr[51],arr[52],arr[53],arr[54],arr[55],arr[56],arr[57],arr[58],arr[59]);
	}
	fclose(fp);
	////////////////////////////////////
	system("cls");
	upper_screen();
    print_title("seat position\n",1,7,BROWN);
    printf("silver cost %d INR [1-30]\n",ss_cost);
    printf("platinam cost %d INR [31-60]\n",pp_cost);
    textcolor(LIGHTCYAN);
 	printf("%s  %s  %s  %s %s  %s  %s  %s  %s  %s\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9]);
 	printf("%s  %s  %s  %s %s  %s  %s  %s  %s  %s\n",arr[10],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19]);
 	printf("%s  %s  %s  %s %s  %s  %s  %s  %s  %s\n",arr[20],arr[22],arr[23],arr[24],arr[25],arr[26],arr[27],arr[28],arr[29]);
 	printf("%s  %s  %s  %s %s  %s  %s  %s  %s  %s\n",arr[30],arr[32],arr[33],arr[34],arr[35],arr[36],arr[37],arr[38],arr[39]);
 	printf("%s  %s  %s  %s %s  %s  %s  %s  %s  %s\n",arr[40],arr[42],arr[43],arr[44],arr[45],arr[46],arr[47],arr[48],arr[49]);
 	printf("%s  %s  %s  %s %s  %s  %s  %s  %s  %s\n",arr[50],arr[52],arr[53],arr[54],arr[55],arr[56],arr[57],arr[58],arr[59]);
 	print_char('-',80,16,LIGHTCYAN);
	printf("enter your seat no:");
	scanf("%s",brr);
	for(i=0;i<=59;i++)
    {
        if(strcmp(brr,arr[i])==0)//user ne jo seat di agar vo khaali hai, toh usko x se bhar dege,aur availbale main 1 ho jayga
        {
            strcpy(arr[i],x);
            available=1;//important
            if(i<=29)//means 0-30
            {
               silver++;
               silver_cost=silver_cost+ss_cost;
            }
            else
            {
                platinam++;
                platinam_cost=platinam_cost+pp_cost;
            }
        }
    }
    if(available!=1)//agar awalable ki value 1 nahi hoti hai toh ..
    {
        textcolor(RED);
        printf(" seat %s not available\n",brr);
        getch();
        theatre_t(index,theatre,movie,s_cost,p_cost,address,show_time);
    }
    ////////////////////////////////////////////////////////////////
     if(strcmp(index,"1")==0)
        fp=fopen("H:\\Movie Ticket Booking APP\\theatre_a.txt","w");
        else if(strcmp(index,"2")==0)
        fp=fopen("H:\\Movie Ticket Booking APP\\theatre_b.txt","w");
        else if(strcmp(index,"3")==0)
        fp=fopen("H:\\Movie Ticket Booking APP\\theatre_c.txt","w");
        else if(strcmp(index,"4")==0)
        fp=fopen("H:\\Movie Ticket Booking APP\\theatre_d.txt","w");
        else if(strcmp(index,"5")==0)
        fp=fopen("H:\\Movie Ticket Booking APP\\theatre_e.txt","w");
	if(fp ==NULL)
	{
		printf("FIle not Found");
	}
	else
	{              //1  2  3  4  5  6  7 8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
		fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
 arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19],arr[20],arr[21],arr[22],arr[23],arr[24],arr[25],arr[26],arr[27],arr[28],arr[29],arr[30],arr[31],arr[32],arr[33],arr[34],arr[35],arr[36],arr[37],arr[38],arr[39],
 arr[40],arr[41],arr[42],arr[43],arr[44],arr[45],arr[46],arr[47],arr[48],arr[49],arr[50],arr[51],arr[52],arr[53],arr[54],arr[55],arr[56],arr[57],arr[58],arr[59]);
	}
	fclose(fp);
 ///////////////////////////////////////////////////////////////////
   printf("silver is %d and cost %d\n",silver,silver_cost);
	printf("platinam is %d and price %d\n",platinam,platinam_cost);
	total_cost=silver_cost+platinam_cost;
	printf("total  cost %d\n",total_cost);
	printf("would you want to book another seat(y/n)");
	fflush(stdin);//important
	scanf("%c",&ch);
	}while(ch=='y');
	///////////////////////////
	final_book(index,theatre,movie,s_cost,p_cost,address,show_time,silver,platinam,silver_cost,platinam_cost,total_cost,brr);
}
void final_book(char* index,char* theatre,char* movie,char* s_cost,char* p_cost,char* address,char* show_time,int silver,int platinam,int silver_cost,int platinam_cost,int total_cost,char*brr)
{
    //printf("%s %s %s %s %s %s %s %d %d %d %d %d %s",index,theatre,movie,s_cost,p_cost,address,show_time,silver,platinam,silver_cost,platinam_cost,total_cost,brr);
    char fname[20];
    char lname[20];
    char date[20];
    char mobile[20];
    print_basic_screen();
    print_title_in_middle("enter your basic details",7,BROWN);
    print_title("1.date:",35,8,LIGHTCYAN);
    scanf("%s",date);
    print_title("2.first name:",35,9,LIGHTCYAN);
	scanf("%s",fname);
    print_title("3.last name:",35,10,LIGHTCYAN);
	scanf("%s",lname);
    print_title("4.mobile no.:",35,11,LIGHTCYAN);
	scanf("%s",mobile);
	print_title("6.book ticket...",35,13,LIGHTCYAN);
	  print_basic_screen();
    print_title_in_middle("your ticket bookd",7,LIGHTGREEN);
    textcolor(LIGHTCYAN);
    printf("\n\t\t\t\ttheatre : %s",theatre);
    printf("\n\t\t\t\tdate: %s",date);
	printf("\n\t\t\t\tyour first name: %s",fname);
	printf("\n\t\t\t\tyour last name: %s",lname);
	printf("\n\t\t\t\tmobile Number : %s",mobile);
	printf("\n\t\t\t\tmovie: %s",movie);
	printf("\n\t\t\t\tshow time: %s",show_time);
	printf("\n\t\t\t\tseat : %s",brr);
	printf("\n\t\t\t\tsilver: %d",silver);
	printf("\n\t\t\t\tplatinam : %d",platinam);
	printf("\n\t\t\t\tsilver cost : %d",silver_cost);
	printf("\n\t\t\t\tplatinam cost : %d",platinam_cost);
	printf("\n\t\t\t\ttotal cost: %d",total_cost);
    FILE*fp;
	fp=fopen("H:\\Movie Ticket Booking APP\\my_booking.txt","a");
	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{             //1  2  3  4  5  6  7  8  9  10 11 12 13    //1      2    3     4     5      6      7        8   9      10       11              12         13
		fprintf(fp,"%s %s %s %s %s %s %s %s %d %d %d %d %d\n",theatre,date,fname,lname,mobile,movie,show_time,brr,silver,platinam,silver_cost,platinam_cost,total_cost);
	}
	fclose(fp);//file close cumplsari
	print_title("continue home screen...",1,23,LIGHTGREEN);
    getch();
    menu();
}
///MMMMMMMMMMMMMMMMM MY BOOKING MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
void my_booking()
{
    system("cls");
    upper_screen();
    char ch;
    textcolor(BROWN);
    printf("booking history\n");
    FILE*fp;
    fp=fopen("H:\\MOVIE TICKET BOOKING APP\\my_booking.txt","r");
	if(fp == NULL)
	{
		printf("file does not found... !");
		printf("\ncontinue...");
		getch();
		menu();
	}
	else
	{
		while( ( ch = fgetc(fp) ) != EOF )
        {
            textcolor(LIGHTCYAN);
      		printf("%c",ch);
        }
	}
	fclose(fp);
    print_char('-',80,22,LIGHTCYAN);
    print_title("continue home screen...",1,23,LIGHTGREEN);
    getch();
    menu();
}
///==============================================================================================================
void theatre_a()
{
   char arr[60][3]={{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"},{"10"},{"11"},{"12"},{"13"},{"14"},{"15"},{"16"},{"17"},{"18"},{"19"},{"20"},{"21"},{"22"},{"23"},{"24"},{"25"},{"26"},{"27"},{"28"},{"29"},{"30"},{"31"},
   {"32"},{"33"},{"34"},{"35"},{"36"},{"37"},{"38"},{"39"},{"40"},{"41"},{"42"},{"43"},{"44"},{"45"},{"46"},{"47"},{"48"},{"49"},{"50"},{"51"},{"52"},{"53"},{"54"},{"55"},{"56"},{"57"},{"58"},{"59"},{"60"}};
    FILE*fp;
    fp=fopen("H:\\Movie Ticket Booking APP\\theatre_a.txt","w");
	if(fp ==NULL)
	{
		printf("FIle not Found");
	}
	else
	{              //1  2  3  4  5  6  7 8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
		fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
 arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19],arr[20],arr[21],arr[22],arr[23],arr[24],arr[25],arr[26],arr[27],arr[28],arr[29],arr[30],
 arr[31],arr[32],arr[33],arr[34],arr[35],arr[36],arr[37],arr[38],arr[39],arr[40],arr[41],arr[42],arr[43],arr[44],arr[45],arr[46],arr[47],arr[48],arr[49],arr[50],arr[51],arr[52],arr[53],arr[54],arr[55],arr[56],arr[57],arr[58],arr[59]);
		printf("file inserted...\n");
		getch();
	}
	fclose(fp);
}
void theatre_b()
{
   char arr[60][3]={{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"},{"10"},{"11"},{"12"},{"13"},{"14"},{"15"},{"16"},{"17"},{"18"},{"19"},{"20"},{"21"},{"22"},{"23"},{"24"},{"25"},{"26"},{"27"},{"28"},{"29"},{"30"},
   {"31"},{"32"},{"33"},{"34"},{"35"},{"36"},{"37"},{"38"},{"39"},{"40"},{"41"},{"42"},{"43"},{"44"},{"45"},{"46"},{"47"},{"48"},{"49"},{"50"},{"51"},{"52"},{"53"},{"54"},{"55"},{"56"},{"57"},{"58"},{"59"},{"60"}};
    FILE*fp;
    fp=fopen("H:\\Movie Ticket Booking APP\\theatre_b.txt","w");
	if(fp ==NULL)
	{
		printf("FIle not Found");
	}
	else
	{              //1  2  3  4  5  6  7 8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
		fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
 arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19],arr[20],arr[21],arr[22],arr[23],arr[24],arr[25],arr[26],arr[27],arr[28],arr[29],arr[30],
 arr[31],arr[32],arr[33],arr[34],arr[35],arr[36],arr[37],arr[38],arr[39],arr[40],arr[41],arr[42],arr[43],arr[44],arr[45],arr[46],arr[47],arr[48],arr[49],arr[50],arr[51],arr[52],arr[53],arr[54],arr[55],arr[56],arr[57],arr[58],arr[59]);
		printf("file inserted...\n");
		getch();
	}
	fclose(fp);
}
void theatre_c()//seats names/which never change
{
   char arr[60][3]={{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"},{"10"},{"11"},{"12"},{"13"},{"14"},{"15"},{"16"},{"17"},{"18"},{"19"},{"20"},{"21"},{"22"},{"23"},{"24"},{"25"},{"26"},{"27"},{"28"},{"29"},{"30"},
   {"31"},{"32"},{"33"},{"34"},{"35"},{"36"},{"37"},{"38"},{"39"},{"40"},{"41"},{"42"},{"43"},{"44"},{"45"},{"46"},{"47"},{"48"},{"49"},{"50"},{"51"},{"52"},{"53"},{"54"},{"55"},{"56"},{"57"},{"58"},{"59"},{"60"}};
    FILE*fp;
    fp=fopen("H:\\Movie Ticket Booking APP\\theatre_c.txt","w");
	if(fp ==NULL)
	{
		printf("FIle not Found");
	}
	else
	{              //1  2  3  4  5  6  7 8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
		fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
 arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19],arr[20],arr[21],arr[22],arr[23],arr[24],arr[25],arr[26],arr[27],arr[28],arr[29],arr[30],
 arr[31],arr[32],arr[33],arr[34],arr[35],arr[36],arr[37],arr[38],arr[39],arr[40],arr[41],arr[42],arr[43],arr[44],arr[45],arr[46],arr[47],arr[48],arr[49],arr[50],arr[51],arr[52],arr[53],arr[54],arr[55],arr[56],arr[57],arr[58],arr[59]);
		printf("file inserted...\n");
		getch();
	}
	fclose(fp);
}
void theatre_d()//seats names/which never change
{
   char arr[60][3]={{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"},{"10"},{"11"},{"12"},{"13"},{"14"},{"15"},{"16"},{"17"},{"18"},{"19"},{"20"},{"21"},{"22"},{"23"},{"24"},{"25"},{"26"},{"27"},{"28"},{"29"},{"30"},
   {"31"},{"32"},{"33"},{"34"},{"35"},{"36"},{"37"},{"38"},{"39"},{"40"},{"41"},{"42"},{"43"},{"44"},{"45"},{"46"},{"47"},{"48"},{"49"},{"50"},{"51"},{"52"},{"53"},{"54"},{"55"},{"56"},{"57"},{"58"},{"59"},{"60"}};
    FILE*fp;
    fp=fopen("H:\\Movie Ticket Booking APP\\theatre_d.txt","w");
	if(fp ==NULL)
	{
		printf("FIle not Found");
	}
	else
	{              //1  2  3  4  5  6  7 8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
		fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
 arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19],arr[20],arr[21],arr[22],arr[23],arr[24],arr[25],arr[26],arr[27],arr[28],arr[29],arr[30],
 arr[31],arr[32],arr[33],arr[34],arr[35],arr[36],arr[37],arr[38],arr[39],arr[40],arr[41],arr[42],arr[43],arr[44],arr[45],arr[46],arr[47],arr[48],arr[49],arr[50],arr[51],arr[52],arr[53],arr[54],arr[55],arr[56],arr[57],arr[58],arr[59]);
		printf("file inserted...\n");
		getch();
	}
	fclose(fp);
}
void theatre_e()//seats names/which never change
{
   char arr[60][3]={{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"},{"10"},{"11"},{"12"},{"13"},{"14"},{"15"},{"16"},{"17"},{"18"},{"19"},{"20"},{"21"},{"22"},{"23"},{"24"},{"25"},{"26"},{"27"},{"28"},{"29"},{"30"},
   {"31"},{"32"},{"33"},{"34"},{"35"},{"36"},{"37"},{"38"},{"39"},{"40"},{"41"},{"42"},{"43"},{"44"},{"45"},{"46"},{"47"},{"48"},{"49"},{"50"},{"51"},{"52"},{"53"},{"54"},{"55"},{"56"},{"57"},{"58"},{"59"},{"60"}};
    FILE*fp;
    fp=fopen("H:\\Movie Ticket Booking APP\\theatre_e.txt","w");
	if(fp ==NULL)
	{
		printf("FIle not Found");
	}
	else
	{              //1  2  3  4  5  6  7 8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
		fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
 arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19],arr[20],arr[21],arr[22],arr[23],arr[24],arr[25],arr[26],arr[27],arr[28],arr[29],arr[30],
 arr[31],arr[32],arr[33],arr[34],arr[35],arr[36],arr[37],arr[38],arr[39],arr[40],arr[41],arr[42],arr[43],arr[44],arr[45],arr[46],arr[47],arr[48],arr[49],arr[50],arr[51],arr[52],arr[53],arr[54],arr[55],arr[56],arr[57],arr[58],arr[59]);
		printf("file inserted...\n");
		getch();
	}
	fclose(fp);
}
///=============================================================================================================================================







