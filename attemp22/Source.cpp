/*-----------------------------*						
 *      Jon Barton             *           
 *      Assigmnet final        *
 *      Program                *
 *      05/01/2017             * 
 *-----------------------------*/

#include<conio.h>
#include<iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <mmsystem.h>
#include <ctime>
#include <string>
#include <math.h> 

#define rnd()    (((FLOAT)rand())/RAND_MAX)//random number generator 
#define RUNS 1000 
#define srand
#define ESC 27

//keyboard inputs 
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP  (vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)



using  namespace std;

/* functions for clear screen, gotoxy(x pont, y point) textcolor(15) changes
color. hline(4 = x, -2 =y, 11 = color and 60 = lengh)
void vline(4 = x, -2 =y, 11 = color and 60 = lengh);
*/
void clrscr(void);
void gotoxy(int, int);
void textcolor(int);
void hline(int, int, int, int);
void vline(int, int, int, int);

void randomblocks(void); //This is for the randomly colours and blocks to  generate 




//this sets the screen. and also ints c 
int x = 80, y = 25, c;
//ASCii 219 = block 
char b = 219; // This is to set the acsii code to block. 
void Instruction(void); //For the main menu instructions. 







			  /**************************************************************
			  *  these Functions for Aniamtions 							*
			  *															    *
			  **************************************************************/
void AnimationMenu(void);
void  Instructionanmenu(void);
void mario(int, int);
void AnimationM(void); // This will just flip flop from each out by itself. but arrows still used for this animations. 
void link(int,int);
void linkanimation(void);   // just moves no flip flop 
void mario2(int, int);
void AnimationP(void);//this will use space to flip pokeball and om
void Kiby(int, int);
void pokeball(int, int);
void om(int, int);
void animationK(void); // just moves no flip flop

// Functions for the maths selection 
void mathsmenu(void);
int fib();
int Caeser();
char ceasar(char m);
void CaserCiperHistory(void);
void InstructionMa(void);
void gameoflife(void);
void primemenu(void);
void sieveofEratosthenes(void);
void bruteforcep(void);
// int a and d  arrays are  for GoL 
int a[80][25];//arrays for GoL
int d[80][25];//Arrays For GoL
			  //char z = 219;
			  //int x, y, c = 0;


int fib(int position);

void main(void)
{
	int choice; // this defining the choice  
	do
	{
		do
		{
			b = 219;
			hline(5, 2, 11, 67); // ( x, y,  color and  lengh)
			hline(5, 13, 11, 67);// ( x, y,  color and  lengh)
			vline(5, 3, 11, 10);// ( x, y,  color and  lengh)
			vline(71, 3, 11, 10); // ( x, y,  color and  lengh)

			textcolor(15);
			gotoxy(15, 4);
			cout << "Welcome to Jon Barton Program .\n";
			textcolor(14);
			gotoxy(15, 5);
			cout << "Press (1) To look at the instructions.\n";
			textcolor(15);
			gotoxy(15, 6);
			cout << "Press (2) To Go OnTo The AnimationMenu .\n ";
			textcolor(14);
			gotoxy(15, 7);
			cout << "Press (3) To Go OnTo The MathsMenu.\n  ";
			textcolor(15);
			gotoxy(15, 8);
			cout << "Press (4)To See A Magic Trick.\n  ";
			textcolor(14);
			gotoxy(15, 9);
			cout << "Press (Esc) To exit the program.\n";
			textcolor(15);
			gotoxy(15, 10);
			cout << "Enter 1, 2 , 3, 4 or 6";
			choice = _getch();

		}

		while (choice != '1'&& choice != '2' && choice != '3' && choice != '4' && choice !='5' &&  choice != '6');
		// if 1 is pressed on the keyboard it loads up instruction();
        //if a number from 1 to 4 is pressed then it will load up that program. 
		// Getch/Getchar will  make sure the termial will not just load up and close straight away. 
		if (choice == '1') { clrscr(); Instruction(); getch(); }
		if (choice == '2') { clrscr();  AnimationMenu(); getch(); }
		if (choice == '3') { clrscr(); mathsmenu(); getch(); }
		if (choice == '4') { clrscr(); randomblocks(); getch(); }
	

	} while (choice != '6'); // When 6 is pressed it will end the program
	clrscr();




}




void randomblocks(void)
{
	do 
	{

		{
			x = rand() % 80;    //This randomising the  x point on to the screen, as each ascii character will spawn anyware from 0 - 80 on x 
			y = rand() % 24;   //This randomising the  y point on to the screen,  as each ascii character will spawn anyware from 0 - 25 on y 
			c = rand() % 16;  //This randomising the Bios colours on to the screen.
			textcolor(c);
			gotoxy(x, y);    //goto is used to put the blocks in x and y cords    

			cout << b;
			b = 33 + rand() % 157; //  This randomise ASC II characters  from 33 - 254 on the ASC II table  
			x++; // Incriment the value of x by one each time 
		}
		x = 0; //  resets the vaules back to 0 
		y++; // Incriment the value of y by one each time 
		gotoxy(0, 0);
		
	}
	while (!KEY_DOWN(VK_ESCAPE)); //While  Esc is down returns back to the main menu. 
	clrscr(); //After esc has been pressed clear the screen. so the randomblocks will don't behinde the main menu. 

}




void Instruction(void)
{
	hline(5, 3, 11, 66); // ( x, y,  color and  lengh)
	hline(6, 12, 11, 65);// ( x, y,  color and  lengh)
	vline(5, 3, 11, 10);
	// ( x, y,  color and  lengh)
	vline(71, 3, 11, 10);  // ( x, y,  color and  lengh)


	textcolor(15);
	gotoxy(10, 4);
	cout << "Welcome to the Instruction ";
	textcolor(14);
	gotoxy(10, 5);
	cout << "To Use Each program, you will need to press 1, 2, 3, 4 or 5  ";
	textcolor(15);
	gotoxy(10, 6);
	cout << "To get return to menu please press ESC.\n  ";
	textcolor(14);
	gotoxy(10, 7);
	cout << "To use the animation use down and up keys to move mario  ";
	textcolor(15);
	gotoxy(10, 8);
	cout << "To leave the whole program Just Press 6";

	while (!KEY_DOWN(VK_ESCAPE)); //While  Esc is down returns back to the main menu. 
	clrscr(); //After esc has been pressed clear the screen. 
}



void AnimationMenu(void)
{
	int list;
	do
	{
		do
		{
			b = 219;
			hline(5, 2, 12, 67); // ( x, y,  color and  lengh)
			hline(5, 13, 12, 67);// ( x, y,  color and  lengh)
			vline(5, 3, 12, 10); // ( x, y,  color and  lengh)
			vline(71, 3, 12, 10);  // ( x, y,  color and  lengh)
			textcolor(15);
			gotoxy(15, 4);
			cout << "Welcome to Program .\n";
			textcolor(14);
			gotoxy(15, 5);
			cout << "Press (M) To use mario .\n";
			textcolor(15);
			gotoxy(15, 6);
			cout << "Press (P) To use Pokemon  .\n ";
			textcolor(14);
			gotoxy(15, 7);
			cout << "Press (L) To use Link  .\n  ";
			textcolor(15);
			gotoxy(15, 7);
			cout << "Press (K) To use Kirby  .\n  ";
			textcolor(14);
			gotoxy(15, 8);
			cout << " Press (I) To Look at the Instructions.\n ";
			textcolor(15);
			gotoxy(15, 9);
			cout << "Press(B) To Go Back To Main Menu Please ";
			textcolor(14);
			gotoxy(15, 10);
			cout << "Enter M, P , L, K, I  or B -";
			list = _getch();

		} 
		while (list != 'm' && list != 'i' && list != 'p' &&list != 'b' &&list != 'k' &&list!= 'l');
		// if m is pressed on the keyboard it loads up AnimationM();
		//if a leter from m to k  is pressed then it will load up that program. 
		// Getch/Getchar will  make sure the termial will not just load up and close straight away.  

		if (list == 'i') { clrscr(); Instructionanmenu(); getch(); }
		if (list == 'm') { clrscr(); AnimationM(); getch(); }
		if (list == 'p') { clrscr();  AnimationP(); getch(); }
		if (list == 'l') { clrscr();  linkanimation(); getch(); }
		if (list == 'k') { clrscr(); animationK(); getch(); }
	
	}

	while (list != 'b'); { clrscr(); main(); getch(); } //while b is pressed it will go back to the main menu
												// clrscr means clear screen when on of the letters/number has been pressed  
	
}
//end of main

void Instructionanmenu(void)
{
	hline(5, 3, 11, 66); // ( x, y,  color and  lengh)
	hline(6, 12, 11, 65); // ( x, y,  color and  lengh)
	vline(5, 3, 11, 10);// ( x, y,  color and  lengh)
	vline(71, 3, 11, 10); // ( x, y,  color and  lengh)
	textcolor(15);
	gotoxy(10, 4);
	cout << "Welcome to the Instruction For Animation";
	textcolor(14);
	gotoxy(10, 5);
	cout << "While Using The Animations To Move Them Use The Arrows Keys.\n";
	textcolor(15);
	gotoxy(10, 6);
	cout << "For Pokemon  Animations Please Press Space Bar\n";
	gotoxy(10, 7);
	 cout << "To switch from ball and pokemon.\n  ";
	textcolor(14);
	gotoxy(10, 8);
	cout << "To Return To The Animation Menu Press b.\n  ";
	
	while (!KEY_DOWN(VK_ESCAPE));  //While  Esc is down returns back to the animation menu.
	clrscr(); //this will clear screen when on of the letters has been pressed  
}


void AnimationM(void)
{
	int x = 1, y = 1, vt = 1, vx = 0;
	DWORD t1, t2;
	t1 = GetTickCount(); // This is retrieces the numbers of millisecons since the system has been running 
	do {
		t2 = GetTickCount(); //  THis is the second Geticktime. 
		if (t2 - t1 > 100)
		{ // If t2 take t1 are less than onehundred
			t1 = t2; //  make both t1, t2 the same 
			if (KEY_DOWN(VK_UP)) //if Key up is pressed  then incriment down y
			{ //VK_DOWN is ascii Key for up  arrow 
				y--;
			}
			if (KEY_DOWN(VK_DOWN)) //if the Key down is pressed then incriment up y 
			{  //VK_DOWN is ascii Key for down arrow 
				y++;
			}
			if (KEY_DOWN(VK_LEFT))//if the Key down is pressed then incriment down x   
			{ // //VK_DOWN is ascii Key for left arrow 
				x--;
			}
			if (KEY_DOWN(VK_RIGHT))//if the Key down is pressed then incriment dup x  
			{//VK_DOWN is ascii Key for right arrow 
				x++;
			}
            if (x > 80) //if x is greater than 80. set x to 80; 
			{
				x = 80;
			}
			if (y > 25) //if y is greater than 25 . set y to 25; 
			{
				y = 25;
			}
			if (x < 1) // if x is less than 1.   set x to 1 
			{
				x = 1;
			}
			if (y < 1) // if y is less than 1.   set y to 1 
			{
				y = 1;
			}
			clrscr();
			mario(x, y);
			if (vt == 0)   // if vt is 0 then vt 1 then just mario
			{
				mario(x, y);
				vt = 1;
			}
			else  //else use mario2 
			{
			mario2(x, y);
			vt = 0;
			}
		}
	} while (!KEY_DOWN(VK_ESCAPE));
	clrscr();
}




void mario(int x, int y)
{
	//main program start
	hline(x + 0, y + 1, 12, 6); // top hat
	hline(x + -1, y + 2, 12, 11); // bottom hat
  /* This is all the parts of the Face in yellow*/
	//hline/vline(x,y,colour,length);
	hline(x + 2, y + 3, 14, 2);
	hline(x + 5, y + 3, 14, 1);
	hline(x + 1, y + 4, 14, 3);
	hline(x + 5, y + 4, 14, 3);
	hline(x + 2, y + 5, 14, 3);
	hline(x + 6, y + 5, 14, 3);
	hline(x + -1, y + 4, 14, 1);
	hline(x + -1, y + 5, 14, 1);
	hline(x + -1, y + 6, 14, 4);
	hline(x + -1, y + 7, 14, 8);
	/*This is the hair */
	hline(x + -1, y + 3, 15, 3);
	hline(x + -2, y + 5, 15, 1);
	hline(x + 0, y + 4, 15, 1);
	hline(x + 0, y + 5, 15, 2);
	/* the tash*/
	hline(x + 3, y + 6, 13, 6);
	hline(x + 5, y + 5, 13, 1);
}


void mario2(int x, int y)
{
	//main program start
    hline(x + 0, y + 1, 10, 6); // top hat
	hline(x + -1, y + 2, 10, 11); // bottom hat
	/* This is all the parts of the Face in yellow*/
	hline(x + 2, y + 3, 14, 2);
	hline(x + 5, y + 3, 14, 1);
	//hline/vline(x,y,colour,length);
	hline(x + 1, y + 4, 14, 3);
	hline(x + 5, y + 4, 14, 3);
	hline(x + 2, y + 5, 14, 3);
	hline(x + 6, y + 5, 14, 3);
	hline(x + -1, y + 4, 14, 1);
	hline(x + -1, y + 5, 14, 1);
	hline(x + -1, y + 6, 14, 4);
	hline(x + -1, y + 7, 14, 8);
	/*This is the hair */
	hline(x + -1, y + 3, 15, 3);
	hline(x + -2, y + 5, 15, 1);
	hline(x + 0, y + 4, 15, 1);
	hline(x + 0, y + 5, 15, 2);
	/* the tash*/
	hline(x + 3, y + 6, 13, 6);
	hline(x + 5, y + 5, 13, 1);
}



void linkanimation(void)

{
    int x = 1, y = 1;
	DWORD t1, t2;
	t1 = GetTickCount(); // This is retrieces the numbers of millisecons since the system has been running 
	do {
		t2 = GetTickCount(); //  THis is the second Geticktime. 
		if (t2 - t1 > 100)
		{ // If t2 take t1 are less than onehundred
			t1 = t2; //  make both t1, t2 the same 
			if (KEY_DOWN(VK_UP)) //if Key up is pressed  then incriment down y
			{ //VK_DOWN is ascii Key for up  arrow 
				y--;
			}
			if (KEY_DOWN(VK_DOWN)) //if the Key down is pressed then incriment up y 
			{  //VK_DOWN is ascii Key for down arrow 
				y++;
			}
			if (KEY_DOWN(VK_LEFT))//if the Key down is pressed then incriment down x   
			{ // //VK_DOWN is ascii Key for left arrow 
				x--;
			}
			if (KEY_DOWN(VK_RIGHT))//if the Key down is pressed then incriment dup x  
			{//VK_DOWN is ascii Key for right arrow 
				x++;
			}
			if (x > 80) //if x is greater than 80. set x to 80; 
			{
				x = 80;
			}
			if (y > 25) //if y is greater than 25 . set y to 25; 
			{
				y = 25;
			}
			if (x < 1) // if x is less than 1.   set x to 1 
			{
				x = 1;
			}
			if (y < 1) // if y is less than 1.   set y to 1 
			{
				y = 1;
			}
			clrscr();
			link(x, y);

		}

	}
	while (!KEY_DOWN(VK_ESCAPE)); clrscr(); 
}

void link(int x , int y )
{
	//hat
	hline(x +13, y + 1, 10, 10);
	hline(x + 12, y + 2, 10, 12);
	hline(x + 11, y + 3, 10, 14);
	hline(x + 10, y + 4, 10, 16);
	hline(x + 10, y + 5, 10, 1);
	hline(x + 25, y + 5, 10, 1);
    //hood 
	hline(x + 14, y + 7, 10, 2);
	hline(x + 20, y + 7, 10, 2);
	hline(x + 11, y + 5, 6, 14);
	hline(x + 10, y + 6, 6, 16);
	hline(x + 10, y + 7, 6, 2);
	hline(x + 10, y + 8, 6, 2);
	hline(x + 10, y + 8, 6, 2);
	hline(x + 24, y + 7, 6, 2);
	hline(x + 24, y + 8, 6, 2);
	hline(x + 14, y + 8, 14, 2); //eyes 
	hline(x + 20, y + 8, 14, 2); //eyes 
     //face 
	vline(x + 16, y + 7, 6, 3);
	vline(x + 17, y + 7, 6, 3);
	vline(x + 18, y + 7, 6, 3);
	vline(x +  19, y + 7, 6, 3);
	hline(x + 12, y + 7, 7, 2);
	hline(x + 12, y + 8, 7, 2);
	hline(x + 9, y + 9, 7, 18);
	hline(x + 10, y + 10, 7, 6);
	
	hline(x + 11, y + 11, 7, 5);
	hline(x + 14, y + 12, 7, 11);
	hline(x + 16, y + 13, 7, 4);
	hline(x + 20, y + 12, 7, 5);
	hline(x + 20, y + 10, 7, 6);
	hline(x + 20, y + 11, 7, 5);
	hline(x + 22, y + 7, 7, 2);
	hline(x + 22, y + 8, 7, 2);
	/* This selection is the ears */
	vline(x + 7, y + 4, 7, 4);
	vline(x + 8, y + 5, 7, 4);
	vline(x + 9, y + 6, 7, 4);

	vline(x + 28, y + 4, 7, 4);
	vline(x + 27, y + 5, 7, 4);
	vline(x + 26, y + 6, 7, 4);

	hline(x + 28, y + 7, 11, 1);
	hline(x + 27, y + 8, 11, 2);
	hline(x + 26, y + 9, 11, 3);
	hline(x + 26, y + 10, 11, 3);
	hline(x + 26, y + 11, 11, 3);

	hline(x + 26, y + 12, 15, 3);
	hline(x + 26, y + 13, 15, 3);
	hline(x + 26, y + 14, 15, 2);
    //mouth 
	hline(x + 16, y + 10, 6, 4);
	hline(x + 16, y + 11, 6, 4);
	//top 
	hline(x + 9, y + 10, 10, 1);
	hline(x + 9, y + 11, 10, 2);
	hline(x + 25, y + 11, 10, 1);
	hline(x + 20, y + 12, 10, 6);
	hline(x + 20, y + 13, 10, 6);
	hline(x + 19, y + 14, 10, 6);
	hline(x + 20, y + 15, 10, 5);
	hline(x + 21, y + 16, 10, 4);
     hline(x + 18, y + 16, 10, 1);
	hline(x + 18, y + 17, 10, 2);
	hline(x + 18, y + 18, 10, 2);
	hline(x + 21, y + 19, 10, 6);
	hline(x + 25, y + 17, 10, 2);
	hline(x + 25, y + 18, 10, 2);
	hline(x + 19, y + 20, 10, 8);
	hline(x + 19, y + 21, 10, 8);
	hline(x + 18, y + 22, 10, 4);
	hline(x + 18, y + 19, 10, 1);
	/*Shield*/
    hline(x + 6, y + 12, 6, 8);
	hline(x + 5, y + 13, 6, 11);
	hline(x + 4, y + 14, 6, 5);
	hline(x + 4, y + 15, 6, 5);
	hline(x + 4, y + 16, 6, 2);
	hline(x + 14, y + 16, 6, 3);
	hline(x + 11, y + 17, 6, 6);
	hline(x + 11, y + 18, 6, 6);
	hline(x + 11, y + 19, 6, 6);
	hline(x + 11, y + 20, 6, 6);
	hline(x + 4, y + 17, 6, 5);
	hline(x + 4, y + 18, 6, 5);
	hline(x + 4, y + 19, 6, 5);
	hline(x + 4, y + 20, 6, 5);
	hline(x + 4, y + 21, 6, 13);
	hline(x + 4, y + 22, 6, 12);
	hline(x + 6, y + 23, 6, 9);
    hline(x + 11, y + 14, 6, 8);
	hline(x + 11, y + 15, 6, 6);
    hline(x + 19, y + 14, 10, 6);
    /*belt*/
	hline(x + 18, y + 15, 6, 2);
	hline(x + 19, y + 19, 6, 2);
	hline(x + 18, y + 20, 6, 2);
	hline(x + 18, y + 21, 6, 1);
	hline(x + 19, y + 16, 6, 2);
	hline(x + 20, y + 17, 6, 5);
	hline(x + 20, y + 18, 6, 5);
	hline(x + 25, y + 16, 6, 2);
	hline(x + 25, y + 15, 6, 2);
	hline(x + 25, y + 14, 6, 1);
    //gap
	hline(x + 17, y + 15, 13, 1);
	hline(x + 17, y + 16, 13, 1);
	hline(x + 17, y + 17, 13, 1);
	hline(x + 17, y + 18, 13, 1);
	hline(x + 17, y + 19, 13, 1);
	hline(x + 17, y + 20, 13, 1);
	hline(x + 17, y + 20, 13, 1);
	hline(x + 17, y + 21, 13, 1);
	hline(x + 16, y + 22, 13, 1);
	hline(x + 15, y + 23, 13, 1);
	hline(x + 7, y + 24, 13, 8);
	//shoe
	hline(x+ 25, y + 21, 6, 2);
	hline(x + 22, y + 22, 6, 5);
	hline(x + 22, y + 23, 6, 5);
	hline(x + 22, y + 24, 6, 5);
	hline(x + 22, y +  25, 6, 5);
}

void animationK(void)
{
    int x = 1, y = 1;
	DWORD t1, t2;
     t1 = GetTickCount(); // This is retrieces the numbers of millisecons since the system has been running 
	do {
		t2 = GetTickCount(); //  THis is the second Geticktime. 
		if (t2 - t1 > 100)
		{ // If t2 take t1 are less than onehundred
			t1 = t2; //  make both t1, t2 the same 
			if (KEY_DOWN(VK_UP)) //if Key up is pressed  then incriment down y
			{ //VK_DOWN is ascii Key for up  arrow 
				y--;
			}
             if (KEY_DOWN(VK_DOWN)) //if the Key down is pressed then incriment up y 
			{  //VK_DOWN is ascii Key for down arrow 
				y++;
			}
			if (KEY_DOWN(VK_LEFT))//if the Key down is pressed then incriment down x   
			{ // //VK_DOWN is ascii Key for left arrow 
				x--;
			}
            if (KEY_DOWN(VK_RIGHT))//if the Key down is pressed then incriment dup x  
			{//VK_DOWN is ascii Key for right arrow 
				x++;
			}
             if (x > 80) //if x is greater than 80. set x to 80; 
			{
				x = 80;
			}
            if (y > 25) //if y is greater than 25 . set y to 25; 
			{
				y = 25;
			}
             if (x < 1) // if x is less than 1.   set x to 1 
			{
				x = 1;
			}
            if (y < 1) // if y is less than 1.   set y to 1 
			{
				y = 1;
			}
			clrscr();
			Kiby(x, y);
		}
	} while (!KEY_DOWN(VK_ESCAPE)); //vk escapes is the esp key 
	clrscr();
}

void Kiby(int x, int y)
{
	//outline
	hline(x + 10, y + 3, 10, 10);
	hline(x + 20, y + 4, 10, 1);
	hline(x + 21, y + 5, 10, 1);
	hline(x + 22, y + 6, 10, 2);//hunle
	vline(x + 24, y + 7, 10, 2); //hubble
	hline(x + 22, y + 9, 10, 2);//hubble

								//inside the  hat thing 
	hline(x + 10, y + 4, 12, 10);
	hline(x + 10, y + 5, 12, 11);
	hline(x + 9, y + 5, 12, 12);
	hline(x + 9, y + 6, 12, 13);
	//hline(17, 6, 15, 3);
	hline(x + 11, y + 7, 15, 7);
	hline(x + 18, y + 7, 12, 4);
	hline(x + 18, y + 8, 12, 2);
	hline(x + 17, y + 8, 15, 1);

	//pinkish bosy 
	hline(x + 8, y + 7, 13, 3);
	hline(x + 6, y + 8, 13, 11);
	hline(x + 7, y + 9, 13, 1);
	hline(x + 9, y + 9, 13, 6);
	hline(x + 16, y + 9, 13, 4);
	hline(x + 7, y + 10, 13, 6);
	hline(x + 7, y + 11, 13, 6);
	hline(x + 7, y + 12, 13, 4);
	hline(x + 7, y + 13, 13, 7);
	hline(x + 15, y + 13, 13, 6);
	hline(x + 16, y + 11, 13, 4);
	hline(x + 16, y + 10, 13, 3);
	hline(x + 18, y + 12, 13, 4);
	hline(x + 15, y + 14, 13, 6);
	hline(x + 8, y + 14, 13, 6);
	vline(x + 14, y + 10, 13, 2);
	hline(x + 13, y + 12, 13, 3);
	//eys 
	vline(x + 13, y + 9, 10, 3);
	vline(x + 15, y + 9, 10, 3);
	// bottom half 
	hline(x + 7, y + 15, 13, 11);
	hline(x + 7, y + 16, 13, 10);
	hline(x + 8, y + 17, 13, 9);
	hline(x + 9, y + 18, 13, 8);
	hline(x + 11, y + 19, 13, 4);
	//mouths 
	vline(x + 14, y + 13, 10, 2);
	//cheeks
	hline(x + 11, y + 12, 12, 2);
	hline(x + 16, y + 12, 12, 2);

	// right foot
	hline(x + 20, y + 8, 10, 2);
	vline(x + 19, y + 9, 10, 2);
	hline(x + 20, y + 11, 10, 1);
	vline(x + 21, y + 12, 10, 7);
	hline(x + 18, y + 15, 10, 4);
	hline(x + 17, y + 16, 10, 1);
	vline(x + 16, y + 17, 10, 5);
	hline(x + 15, y + 19, 10, 1);
	hline(x + 17, y + 21, 10, 2);
	hline(x + 20, y + 19, 10, 1);
	hline(x + 19, y + 20, 10, 1);
	hline(x + 12, y + 20, 10, 4);
	//inside the foot
	hline(x + 18, y + 16, 13, 3);
	hline(x + 17, y + 17, 13, 4);
	hline(x + 17, y + 18, 13, 4);
	hline(x + 17, y + 19, 13, 3);
	hline(x + 17, y + 20, 13, 2);

	/// inside of the foot
	hline(x + 8, y + 19, 13, 2);
	hline(x + 7, y + 20, 13, 5);


	// left foot 
	hline(x + 10, y + 19, 10, 2);
	hline(x + 8, y + 17, 10, 1);
	hline(x + 8, y + 18, 10, 2);
	hline(x + 7, y + 19, 10, 1);
	hline(x + 6, y + 20, 10, 1);
	hline(x + 7, y + 21, 10, 5);



	//left side 
	vline(x + 7, y + 14, 10, 3);
	vline(x + 6, y + 8, 10, 6);
	hline(x + 7, y + 7, 10, 2);
	hline(x + 8, y + 9, 10, 1);
	vline(x + 9, y + 4, 10, 3);


}


void AnimationP(void)
{
	int x = 1, y = 1, vt = 1, vx = 0;
	DWORD t1, t2;
	t1 = GetTickCount(); // This is retrieces the numbers of millisecons since the system has been running 
	do {
		t2 = GetTickCount(); //  THis is the second Geticktime. 
		if (t2 - t1 > 100)
		{ // If t2 take t1 are less than onehundred
			t1 = t2; //  make both t1, t2 the same 
			if (KEY_DOWN(VK_UP)) //if Key up is pressed  then incriment down y
			{ //VK_DOWN is ascii Key for up  arrow 
				y--;
			}
			if (KEY_DOWN(VK_DOWN)) //if the Key down is pressed then incriment up y 
			{  //VK_DOWN is ascii Key for down arrow 
				y++;
			}
			if (KEY_DOWN(VK_LEFT))//if the Key down is pressed then incriment down x   
			{ // //VK_DOWN is ascii Key for left arrow 
				x--;
			}
			if (KEY_DOWN(VK_RIGHT))//if the Key down is pressed then incriment dup x  
			{//VK_DOWN is ascii Key for right arrow 
				x++;
			}
			if (x > 80) //if x is greater than 80. set x to 80; 
			{
				x = 80;
			}
			if (y > 25) //if y is greater than 25 . set y to 25; 
			{
				y = 25;
			}
			if (x < 1) // if x is less than 1.   set x to 1 
			{
				x = 1;
			}
			if (y < 1) // if y is less than 1.   set y to 1 
			{
				y = 1;
			}
			clrscr();
			if (KEY_DOWN(VK_SPACE)) vt = !vt;
			t1 = t2;
			if (vt == 1)
			{
				pokeball(x, y);

			}
			else
			{
				clrscr();
				om(x, y);
			}
		}
	} while (!KEY_DOWN(VK_ESCAPE));
	clrscr();
}



void om(int x, int y)
{

	hline(x + 12, y + 2, 6, 7);
	hline(x + 19,  y + 3, 6, 2);//right side of the main out line 
	hline(x + 21, y + 4, 6, 1);//right side of the main out line 
	vline(x + 22, y + 5, 6, 2); //right side of the main out line 
	vline(x + 23, y + 7, 6, 5); //right side of the main outline 
	hline(x + 22, y + 12, 6, 1); //right side of the main outline
	hline(x + 20, y + 13, 6, 2); //right side of the main outline 
	hline(x + 20, y + 14, 6, 1);  //right side of the main outline 
	hline(x + 21, y + 15, 6, 1); //right side of the main outline 
	hline(x + 18, y + 16, 6, 3); //right side of the main outline 
	hline(x + 17, y + 15, 6, 1);  //right side of the main outline 
	hline(x + 16, y + 17, 6, 2); //right side of the main outline 
	hline(x + 15, y + 16, 6, 1); //right side of the main outline 
	hline(x + 13, y + 17, 6, 2); //right side of the main outline
						 //Left selction outline 
	hline(x + 12, y + 16, 6, 1);//bottom middle 
	hline(x + 10, y + 17, 6, 2); //bottom left
	hline(x + 11, y + 15, 6, 1);
	hline(x + 7, y + 16, 6, 3);
	hline(x + 6, y + 15, 6, 2);
	hline(x + 8, y + 14, 6, 1);
	hline(x + 5, y + 14, 6, 1);
	hline(x + 6, y + 13, 6, 1);


	//left top side 
	hline(x + 10, y + 3, 6, 2);
	hline(x + 9, y + 4, 6, 1);
	vline(x + 8, y + 5, 6, 3);
	vline(x + 7, y + 8, 6, 5);
	hline(x + 8, y + 11, 6, 1);
	hline(x + 9, y + 10, 6, 2);
	vline(x + 11, y + 11, 6, 1);
	hline(x + 12, y + 12, 6, 2);
	hline(x + 12, y + 13, 6, 1);
	hline(x + 14, y + 11, 6, 2);
	hline(x + 16, y + 12, 6, 1);
	hline(x + 17, y + 13, 6, 2);
	hline(x + 17, y + 13, 6, 1);
	vline(x + 17, y + 9, 6, 4);
	hline(x + 18, y + 8, 6, 1);
	vline(x + 19, y + 9, 6, 2);

	hline(x + 6, y + 14, 11, 2);
	hline(x + 9, y + 14, 11, 6);

	hline(x + 7, y + 13, 11, 3);
	hline(x + 8, y + 15, 11, 3);
	hline(x + 12, y + 15, 11, 5);
	hline(x + 10, y + 16, 11, 3);

	hline(x + 13, y + 16, 11, 2);
	hline(x + 16, y + 16, 11, 2);
	hline(x + 18, y + 15, 11, 3);
	hline(x + 17, y + 14, 11, 4);

	//shell
	hline(x + 12, y + 3, 14, 7);
	hline(x + 9, y + 4, 14, 12);
	hline(x + 9, y + 5, 14, 13);
	hline(x + 9,  y + 6, 14, 13);
	hline(x + 9, y + 7, 14, 14);
	hline(x + 8, y + 8, 14, 10);
	hline(x + 8, y + 9, 14, 9);
	hline(x + 8, y + 10, 14, 1);
	hline(x + 11, y + 10, 14, 6);
	hline(x + 12, y + 11, 14, 3);
	hline(x + 16, y + 11, 14, 1);
	hline(x + 19, y + 8, 14, 4);
	hline(x + 20, y + 9,  14, 3);
	hline(x + 20, y + 10,  14, 3);
	hline(x + 19, y +  11,  14, 4);
	vline(x + 18, y + 9,  14, 4);
	hline(x + 19, y +  12,  14, 3);
}




void pokeball(int x, int y)//int x, int y)

{
	hline(x + 10, y + 1, 11, 4);  //out line of the ball
	hline(x + 10, y + 2, 12, 4); // red part for the ball
	hline(x + 8, y + 2, 11, 2);
	hline(x + 14, y + 2, 11, 2);
	vline(x + 7, y + 3, 11, 2);//left side of the ball 
	vline(x + 16, y + 3, 11, 2); //right side of the ball
	vline(x + 6, y + 5, 11, 2);
	vline(x + 5, y + 7, 11, 4);

	vline(x + 6, y + 11, 11, 2);
	hline(x + 6, y + 9, 11, 1); // middle part 
	hline(x + 7, y + 10, 11, 3);//middle part 
	hline(x + 9, y + 9, 11, 1);//middle part
	hline(x + 10, y + 8, 11, 3);//middle part 
	hline(x + 10, y + 11, 11, 3); //middle part 
	hline(x + 13, y + 9, 11, 1);//middle part 
	hline(x + 13, y + 10, 11, 4);//middle part 
	hline(x + 17, y + 9, 11, 1);// middle part 

	hline(x + 8, y + 3, 12, 8);//ball colour 
	hline(x + 8, y + 4, 12, 8); //ball colour
	hline(x + 7, y + 5, 12, 10);//ball colour
	hline(x +  7, y + 6, 12, 10); //ball colour 
	hline(x + 6, y +  7, 12, 12);//ball colour 
	hline(x + 6, y + 8, 12, 4);//ball colour
	hline(x + 8, y + 7, 12, 12);
	hline(x + 7, y + 9, 12, 2);//ball colour 
	hline(x + 12, y + 8, 12, 6);//ball colour 
	hline(x + 15, y+ 9, 12, 2);//ball colour 
	hline(x + 7, y + 13, 11, 2);
	hline(x + 9, y + 14, 11, 6); //base 
	vline(x + 17, y + 5, 11, 2);
	vline(x + 18, y + 7, 11, 4);

	//vline(19, , 11, 4);
	vline(x + 17, y + 11, 11, 2);
	hline(x + 15, y +  13, 11, 2);
}


void mathsmenu()
{
	int choice; // this defining the list 
	do
	{
		do
		{
			b = 219;
			hline(5, 1, 14, 67);    // ( x, y,  color and  lengh)
			hline(5, 13, 14, 67);   // ( x, y,  color and  lengh)
			vline(5, 2, 14, 11);   // ( x, y,  color and  lengh)
			vline(71, 2, 14, 11);  // ( x, y,  color and  lengh)
			textcolor(15);
			gotoxy(15, 3);
			cout << "Welcome to Math Menu  .\n";
			textcolor(14);
			gotoxy(15, 4);
			cout << "Press (1) To look at the instructions.\n";
			textcolor(15);
			gotoxy(15, 5);
			cout << "Press (P) To Use see The Prime numbers .\n ";
			textcolor(14);
			gotoxy(15, 6);
			cout << "Press (F) To Use The Fibonacci .\n  ";
			textcolor(15);
			gotoxy(15, 7);
			cout << "Press (C) For Caeser Ciper.\n  ";
			textcolor(14);
			gotoxy(15, 8);
			cout << "Press (H) For Caeser Ciper History.\n  ";
			textcolor(15);
			gotoxy(15, 9);
			cout << "Press (B) To  Return To The Main Menu .\n  ";
			textcolor(14);
			gotoxy(15, 10);
			cout << "Press (G) To run GameOfLife.\n";
			textcolor(15);
			gotoxy(15, 11);
			cout << "Enter 1, P , F, C, B, H or  6 -";
			choice = _getch();

		}

		while (choice != '1'&& choice != 'p' && choice != 'f' && choice != 'g' && choice != 'c' && choice != '6' && choice != '7' && choice != 'b' && choice != 'h');
		// if 1 is pressed on the keyboard it loads up InstructionsM();
		//if a leter/numbers from 1 to f  is pressed then it will load up that program. 
		// Getch/Getchar will  make sure the termial will not just load up and close straight away.
		if (choice == '1') { clrscr(); InstructionMa(); getch(); }
		if (choice == 'p') { clrscr();   primemenu();  getch(); }
		if (choice == 'g') { clrscr();  gameoflife(); getch(); }
		if (choice == 'c') { clrscr();  Caeser(); getch(); }
		if (choice == 'h') { clrscr(); CaserCiperHistory(); getch(); }
		if (choice == 'f') { clrscr(); fib(); getch(); }

	}
	
	
	while (choice != 'b'); { clrscr(); main(); getch(); } //while b is pressed it will go back to the main menu
														// clrscr means clear screen when on of the letters/number has been pressed  




}


void InstructionMa()
{
	hline(5, 3, 11, 66); // ( x, y,  color and  lengh)
	hline(6, 12, 11, 65); // ( x, y,  color and  lengh)
	vline(5, 3, 11, 10); // ( x, y,  color and  lengh) 
	vline(71, 3, 11, 10);  // ( x, y,  color and  lengh)
   textcolor(15);
	gotoxy(10, 4);
	cout << "Welcome to the Instruction For Maths Menu";
	textcolor(10);
	gotoxy(10, 5);
	cout << "To Use The Glider Gun in GoL Please Press G.\n";
	textcolor(14);
	gotoxy(10, 6);
	cout << "To Continual Use The Caeser Ciper Please Press Space Bar.\n  ";
	textcolor(13);
	gotoxy(10, 7);
	cout << "To Restart Game of life Please Press Space Bar.\n  ";
	textcolor(13);
	gotoxy(10, 8);
	cout << "To Return To The Maths  Menu Press B.\n  ";



	while (!KEY_DOWN(VK_ESCAPE)); clrscr();
}




void gameoflife(void)//main program start
{
	
	for (x = 0; x<80; x++) // plus one each time until it eachs to 80. 
	{
		for (y = 0; y<25; y++) // plus one each time until it eachs to 25. 
		{
			a[x][y] = (int)((rand() / (float)RAND_MAX)*2.0); //first array = randon/ float random max * 20. 
		}
	}
	do
	{
		clrscr();
		//view array a
		for (x = 0; x<80; x++)
		{
			for (y = 0; y<25; y++)
			{
				gotoxy(x, y);
				if (a[x][y] == 1) cout << b;
			}
		}
		//calculate next generation
		for (x = 1; x<79; x++)
		{
			for (y = 1; y<24; y++)
			{
				c = 0;
				if (a[x - 1][y - 1] == 1) c++;
				if (a[x][y - 1] == 1) c++;
				if (a[x + 1][y - 1] == 1) c++;
				if (a[x - 1][y] == 1) c++;
				if (a[x + 1][y] == 1) c++;
				if (a[x - 1][y + 1] == 1) c++;
				if (a[x][y + 1] == 1) c++;
				if (a[x + 1][y + 1] == 1) c++;

				// game of life rules
				if (a[x][y] == 1 && c < 2) d[x][y] = 0;    //if the popluation c < 2  then dead .
				if (a[x][y] == 1 && (c == 2 || c == 3)) d[x][y] = 1;   //if the popluation c == 2  or  c == 3 then alive.
				if (a[x][y] == 1 && c > 3) d[x][y] = 0;  //if the popluation = 4 and c > 6 then dead. 
				if (a[x][y] == 0 && c == 3) d[x][y] = 1; //if the popluation c =3  then alive  
				if (a[x][y] == 1 && c > 6) d[x][y] = 0; //if the popluation c > 6 then dead. 

			}
		}

		//copy b[] into a[]
		for (x = 0; x<80; x++)
		{
			for (y = 0; y<25; y++)
			{
				a[x][y] = d[x][y];
				
			}

			

			if (KEY_DOWN(0x47)) // if G has been press run this code 
			{ 
				clrscr(); // clear the screen
				for (x = 0; x < (80 - 1); x++)	{ // Starting at 0, if x is less than (80 - 1)  (def. 79), incriment x by one.
					for (y = 0; y < (25 - 1); y++)// Starting at 0, if y is less than (25 - 1) (def. 24 ), incriment y by one.
					{ 
						a[x][y] = 0; // Make a[] 0
						d[x][y] = 0; //  and the same for d[]
					}
				}
				// The following section will now draw a gosper glider 

				a[2][6] = 1; 
				a[2][7] = 1;
				a[3][6] = 1;
				a[3][7] = 1;
				a[12][6] = 1;
				a[12][7] = 1;
				a[12][8] = 1;
				a[13][5] = 1;
				a[13][9] = 1;
				a[14][4] = 1;
				a[15][4] = 1;
				a[14][10] = 1;
				a[15][10] = 1;
				a[16][7] = 1;
				a[17][5] = 1;
				a[17][9] = 1;
				a[18][6] = 1;
				a[18][7] = 1;
				a[18][8] = 1;
				a[19][7] = 1;
				a[22][4] = 1;
				a[23][4] = 1;
				a[22][5] = 1;
				a[23][5] = 1;
				a[22][6] = 1;
				a[23][6] = 1;
				a[24][3] = 1;
				a[24][7] = 1;
				a[26][2] = 1;
				a[26][3] = 1;
				a[26][7] = 1;
				a[26][8] = 1;
				a[35][4] = 1;
				a[36][4] = 1;
				a[35][5] = 1;
				a[36][5] = 1;
			}


		}
		// _getch();
		if (KEY_DOWN(VK_SPACE))
		{
			//randomly set array a
			for (x = 0; x < (80 - 1); x++)
			{ /// Starting at 0, if y is less than (25 - 1) (def. 24 ), incriment y by one.
				for (y = 0; y < (25 - 1); y++)
				{ // Starting at 0, if y is less than (25 - 1) (def. 24 ), incriment y by one.
					a[x][y] = rand() % 2; // Randomise the value of a[]
				}
			}
		}

		Sleep(500); //slows the genarating  
		clrscr();
	
	}

	while (!KEY_DOWN(VK_ESCAPE)); clrscr();
}




int fib()
{
	b = 219;  //Ascii Key code for ascii block 
	hline(5, 2, 11, 67); // ( x, y,  color and  lengh)
	hline(5, 13, 11, 67); // ( x, y,  color and  lengh)
	vline(5, 3, 11, 10); // ( x, y,  color and  lengh) 
	vline(71, 3, 11, 10);  // ( x, y,  color and  lengh)
	gotoxy(15, 4);
	int answer, position;
	gotoxy(16, 5);
	cout << "Which position? ";
	cin >> position;
	cout << endl;
	gotoxy(15, 6);
	answer = fib(position);
	cout << answer << " is the ";
	cout << position << "th Fibonacci number. " << endl;
	return 0;
	clrscr();
	while (!KEY_DOWN(VK_ESCAPE));

}

int fib(int n) //int n is used to find what the nth term is 
{
	int NumberTwo = 1, NumberOne = 1, answer = 2;
		if (n < 3)
		return 1;
		for (n -= 3; n != 0; n--) //for nth number -=3 n not equal to 0 then take n
	{
		NumberTwo = NumberOne;    //This is will use number one that was defind
		NumberOne = answer;        //Number one will use the int answer. 
		answer = NumberOne + NumberTwo; // This will add number one and number two to get the prime number.
										//20th fib = 6765 
	}

	return answer;
}

void CaserCiperHistory()
{
	b = 219;  //Ascii Key code for ascii block 
	hline(5, 2, 11, 67); // ( x, y,  color and  lengh)
	hline(5, 13, 11, 67);// ( x, y,  color and  lengh)
	vline(5, 3, 11, 10);// ( x, y,  color and  lengh)
	vline(71, 3, 11, 10);  // ( x, y,  color and  lengh)
	gotoxy(15, 5);
	textcolor(15);
	cout << "Welcome To The History Of The CaeserCiper.\n" << endl;
	gotoxy(10, 6);
	textcolor(13);
	cout << "This method of Ciper was named after Julius Caesar.\n  " << endl;
	gotoxy(10, 7);
	cout << "When The message was encryped it would shift.\n  " << endl;
	gotoxy(10, 8);
	cout << "The whole message will shift by any number, as this would .\n  " << endl;
	gotoxy(10, 9);
	cout << "Allow Caesar to send messages to troops without,\n  " << endl;
	gotoxy(10, 10);
	cout << "enemies knowing what his plans are" << endl;
	gotoxy(10, 11);
	cout << "This method was used for centuries  until  .\n  " << endl;

	while (!KEY_DOWN(VK_ESCAPE));
	clrscr();
}


 

int Caeser() {
	string input;

	do {
		b = 219; //Ascii Key code for ascii block
		hline(5, 2, 11, 67); // ( x, y,  color and  lengh)
		hline(5, 13, 11, 67);// ( x, y,  color and  lengh)
		vline(5, 3, 11, 10);// ( x, y,  color and  lengh)
		vline(71, 3, 11, 10);  // ( x, y,  color and  lengh)
		gotoxy(15, 5);
		cout << "Enter text:\n" << endl;
		gotoxy(15, 6);
		cout << "Enter  2 blank lines to quit.\n" << endl;
		gotoxy(15, 7);
		getline(cin, input);
		gotoxy(15, 8);
		string output = "";

		for (int i = 0; i < input.length(); i++) //when i is less than input.length
		{
			output += ceasar(input[i]); // output += caesar input [i]

		}
		cout << output << endl;
		return 0;
		clrscr();
	} while (!input.length() == 0); // while input.length == 0 then return to maths menu. 
}


char ceasar(char m)
{
	if (isalpha(m))
	{
		m = toupper(m); //use upper to keep from having to use two seperate for A..Z a..z
		m = (((m - 65) + 13) % 26) + 65; //this will more all letter forward  by 13. 
										 //an example Hello = urvyyb 
	}
	//if m isn't alpha, just send it back.
	return m;

}
void primemenu()
{
	int list; //this is a list 
		do
	{
		do
		{
			b = 219;
			hline(5, 2, 11, 73);  // ( x, y,  color and  lengh)
			hline(5, 13, 11, 73);  // ( x, y,  color and  lengh)
			vline(5, 3, 11, 10);  // ( x, y,  color and  lengh) 
			vline(77, 3, 11, 10);   // ( x, y,  color and  lengh)  
			textcolor(15);
			gotoxy(10, 4);
			cout << "Welcome to Prime Number  Menu  .\n";
			textcolor(14);
			gotoxy(10, 5);
			cout << "Press (1) To use the break force to find prime numbers .\n";
			textcolor(15);
			gotoxy(10, 6);
			cout << "Press (2) To use the sieve of Eratosthenes to find prime numbers.\n ";
			textcolor(14);
			gotoxy(10, 7);
			cout << "Press (b) To go back to Maths Menu.";
			textcolor(15);
			gotoxy(10, 8);
			cout << "Enter 1, 2 , b";
			list = _getch();
		} while (list != '1'&& list != '2' && list != 'b');

		if (list == '1') { clrscr(); bruteforcep(); getch(); }
		if (list == '2') { clrscr();  sieveofEratosthenes(); getch(); }
		


	} 
	while (list != 'b'); { clrscr(); main(); getch(); } //while b is pressed it will go back to the main menu
														  // clrscr means clear screen when on of the letters/number has been pressed  
}




void bruteforcep(void)

{
	int i, j, k;
	int flag;

	DWORD starttime, endtime;
	float totaltime;

	starttime = GetTickCount();//get start time
	for (k = 0; k < RUNS; k++) //This allows have 1000 runs 
	{
		//for (i = 3; i < 100000; i++)
		for (i = 3; i < 100000; i += 2)
		{

			flag = 0;

			//flag == 1; 
			{

				//for (j = 3; j < i; j++)
				for (j = 3; j < i; j += 2)
					//if (fmod((float)i, (float)j) == 0) (flag = 1); //if modding int i and j together = 0, it is not a prime number.
					if (i%j == 0) (flag = 1); //if modding int i and j together = 0, it is not a prime number.

				if (flag == 0)
				{
					c++;
					//cout << i << " is prime!\n";
				}
				if (flag == 1)
				{
					//bang out of calculation
					j = i;
					//c++;
					//cout << i << " is not prime!\n";
				}
			}
		}

		// Including not prime and prime = 613.125
		//Without is not prime = 455.56 seconds
		// without is not prime and prime = 0.234 and running 10000 times 
		//Without is prime = 536.688
		//if (i%j == 0) (flag = 1); //if modding int i and j together = 0, it is not a prime number.

		/*if (flag == 0)
		{
		c++;
		//cout << i << " is prime!\n";
		}
		if (flag ==1)
		{
		//bang out of calculation
		j=i;
		//c++;
		//cout << i << " is not prime!\n";
		/*  3.9 seconds

		/*
		c = 0;//reset c
		//this will now run for 10000.
		for (i = 0; i < 100000; i++)
		{

		if (flag == 0)  c++;
		}
		*/

		endtime = GetTickCount();//get finish time
								 //calc time
		totaltime = ((float)endtime - (float)starttime) / 1000.0;//calculate total time in secs

		b = 219;
		hline(5, 5, 14, 67); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
		hline(5, 14, 14, 67);
		vline(5, 5, 14, 10);
		vline(71, 5, 14, 10);  // Right side

		gotoxy(15, 8);
		std::cout << "Totaltime=" << totaltime << " sec\n";
		gotoxy(15, 9);
		std::cout << "primes found " << c << std::endl;
		gotoxy(15, 10);
		printf("Press any key to end....where's the any key?");
		getch();
		while (!KEY_DOWN(VK_ESCAPE)); clrscr();
		
	}

}







void sieveofEratosthenes(void)
{
	
	int flag;
	char x[100000]; // char char x [100000] 
	int i, j, k, c = 0;

	DWORD starttime, endtime;
	float totaltime;


	for (k = 0; k < RUNS; k++) //This allows to run the program for 10000 tmes 
	{

		starttime = GetTickCount();//get start time
		for (i = 0; i < 100000; i++) x[i] = 0;//0=prime, 1=not prime



		x[0] = 1; //This is set 0 to not prime
		x[1] = 1;//This set 1 to not prime

		for (i = 2; i < 316; i++)
		{

			if (x[i] == 0)//if prime 
			{
				for (j = i * 2; j < 100000; j = j + i)x[j] = 1;
			}
		}

		c = 0;//reset c so the run can go back through the code without making the end result (prime numbers be higher) 
		for (i = 0; i < 100000; i++)
		{
			if (x[i] == 0) c++; // repets the process 
		}//end of K runs loop //time 0.001172


		

		endtime = GetTickCount();//get finish time
								 //calculate time
		totaltime = ((float)endtime - (float)starttime) / (1000.0*RUNS);//calculate total time in secs

		b = 219;
		hline(5, 5, 14, 67); // ( x, y,  color and  lengh)
		hline(5, 14, 14, 67);// ( x, y,  color and  lengh)
		vline(5, 5, 14, 10);// ( x, y,  color and  lengh)
		vline(71, 5, 14, 10);  // ( x, y,  color and  lengh)

		gotoxy(15, 8);
		std::cout << "Totaltime=" << totaltime << " sec\n";       //this is uses the total time from endtime - starttime  / 1000.0 to get the 
		gotoxy(15, 9);
		std::cout << "primes found " << c << endl;// This uses c to get all the primes found. 
		gotoxy(15, 10);
		std::printf("Press any key to end....where's the any key?");
		getch();
		while (!KEY_DOWN(VK_ESCAPE)) clrscr();


	}
}





/* This is Code below is From Dr Andy Watson @ CityPlym*/
/* Void hline, void vline for drawing a  border*/


void hline(int x, int y, int c, int l)
{
	int i;
	textcolor(c);
	for (i = 0; i<l; i++)// for loop  in array as this will stop untill reach length
	{
		gotoxy(i + x, y);
		cout << b;
	}

}
void vline(int x, int y, int c, int l)
{
	int i;
	textcolor(c);
	for (i = 0; i<l; i++)// for loop  in array as this will stop untill reach length
	{
		gotoxy(x, i + y);
		cout << b;
	}

}


// This  defines the textcolor,gotoxy and clrscr functions
void textcolor(int c)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c);
}

void gotoxy(int x, int y)         //define gotoxy function
{
	static HANDLE hStdout = NULL;
	COORD coord;

	coord.X = x;
	coord.Y = y;
	if (!hStdout) { hStdout = GetStdHandle(STD_OUTPUT_HANDLE); }
	SetConsoleCursorPosition(hStdout, coord);
}
void clrscr(void) // clrscr function
{
	static HANDLE hStdout = NULL;
	static CONSOLE_SCREEN_BUFFER_INFO csbi;
	const COORD startCoords = { 0,0 };
	DWORD dummy;

	if (!hStdout)
	{
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hStdout, &csbi);
	}
	FillConsoleOutputCharacter(hStdout, ' ', csbi.dwSize.X * csbi.dwSize.Y, startCoords, &dummy);
	gotoxy(0, 0);
}