

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



using namespace std; 

/* functions for clear screen, gotoxy(x pont, y point) textcolor(15) changes
color. hline(4 = x, -2 =y, 11 = color and 60 = lengh)
void vline(4 = x, -2 =y, 11 = color and 60 = lengh);

*/
void clrscr(void);
void gotoxy(int, int);
void textcolor(int);
void hline(int, int, int, int);
void vline(int, int, int, int);

void randomblocks(void);


int x = 80, y = 25, c;
//ASCii 219 = block 
char b = 219;

/**************************************************************
* List of voids, matrix fall,mario, fib, so on 			  *
*															  *
**************************************************************/
void AnimationMenu(void);
void  Instructionanmenu(void);
void mario(int, int);
void AnimationM(void);
void link(void);
void mario2(int, int);
void AnimationP(void);//this will use space to flip
void Kiby(int,int); 
void pokeball(int,int);
void om(int,int );
void animationK(void);

void mathsmenu(void);
int fib(); 
int Caeser();
char ceasar(char m );
void CaserCiperHistory(void);
void InstructionMa(void);
void gameoflife(void);
void primemenu(void);
void sieveofEratosthenes(void);
void bruteforcep(void); 

int a[80][25];//arrays for GoL
int d[80][25];//Arrays For GoL
//char z = 219;
//int x, y, c = 0;

void Instruction(void);
int fib(int position);

void main(void)
{





	int choice; // this defining the line 




	do
	{

		do

		{
			b = 219;
			hline(5, 2, 11, 67); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
			hline(5, 13, 11, 67);
			vline(5, 3, 11, 10);
			vline(71, 3, 11, 10);  // Right side 

			textcolor(15);

			gotoxy(15, 4);
			cout << "Welcome to Program .\n";
			textcolor(13);
			gotoxy(15, 5);
			cout << "Press (1) To look at the instructions.\n";
			textcolor(11);
			gotoxy(15, 6);
			cout << "Press (2) To Go OnTo The AnimationMenu .\n ";
			textcolor(14);
			gotoxy(15, 7);
			cout << "Press (3) To Go OnTo The MathsMenu.\n  ";
			textcolor(15);
			gotoxy(15, 8);
			cout << "Press (4)To See A Magic Trick.\n  ";
			textcolor(11); 
			gotoxy(15, 9);
			cout << "Press (5) To see a magic trick.\n  ";
			textcolor(14); 
			gotoxy(15, 10);
			cout << "Press (Esc) To exit the program.\n";
			textcolor(15); 
			gotoxy(15, 11);
			cout << "Enter 1, 2 , 3, 4, 5  or 6 -";
			choice = _getch();

		}

		while (choice != '1'&& choice != '2' && choice != '3' && choice != '4' &&  choice != '6' && choice != '7');

		if (choice == '1') { clrscr(); Instruction(); getch(); }
		if (choice == '2') { clrscr();  AnimationMenu(); getch(); }
		//{clrscr();  cout << "hey"; getch(); }
		if (choice == '3') { clrscr(); mathsmenu(); getch(); }
	  if (choice == '4') { clrscr(); randomblocks(); getch(); }
		if (choice == '7') { clrscr(); PlaySound(TEXT("Test.wav"), NULL, SND_SYNC); getch(); }

	} while (choice != '6');
	clrscr();




}




void randomblocks(void)
{
	do //for (x = 0; x<80; x++) // forward loops 
	   //{
	   //for (x = 0; x<24; x++)
	{

		{
			x = rand() % 80;
			y = rand() % 24;
			c = rand() % 16;
			textcolor(c);
			gotoxy(x, y);

			cout << b;
			b = 33 + rand() % 157; //  This ranges from 33 - 254 on the ASC II Code 
			x++; // Incriment the value of x by one each time 
		}
		x = 0; //  resets the vaules back to 0 
		y++; // Incriment the value of y by one each time 
		gotoxy(0, 0);
		x = 0;
		y = 0;
	} 
	

			
			
		

		
		//}
		while (!KEY_DOWN(VK_ESCAPE));
		clrscr();
	
}

void Instruction(void) 
{
	hline(5, 3, 11, 66); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
	hline(6, 12, 11, 65);
	vline(5, 3, 11, 10);

	vline(71, 3, 11, 10);  // Right side 



	textcolor(15);
	gotoxy(10, 4);
	cout << "Welcome to the Instruction ";
	textcolor(10);
	gotoxy(10, 5);
	cout << "To Use Each program, you will need to press 1, 2, 3, 4 or 5  ";
	textcolor(14);
	gotoxy(10, 6);
	cout << "To get return to menu please press ESC.\n  ";
	textcolor(13);
	gotoxy(10, 7);
	cout << "To use the animation use down and up keys to move mario  ";
	textcolor(12);
	gotoxy(10, 8);
	cout << "To leave the whole program Just Press 6";

	while (!KEY_DOWN(VK_ESCAPE));
	if (KEY_DOWN(VK_ESCAPE)) clrscr();
}



void AnimationMenu(void)
{
	int list;

	do
	{
		do
		{
			b = 219;
			hline(5, 2, 12, 67); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
			hline(5, 13, 12, 67);
			vline(5, 3, 12, 10);
			vline(71, 3, 12, 10);  // Right side 

			textcolor(15);

			gotoxy(15, 4);
			cout << "Welcome to Program .\n";
			textcolor(14);
			gotoxy(15, 5);
			cout << "Press (M) To use mario .\n";
			textcolor(11);
			gotoxy(15, 6);
			cout << "Press (P) To use Pokemon  .\n ";
			textcolor(13);
			gotoxy(15, 7);
			cout << "Press (L) To use Link  .\n  ";
			textcolor(15);
			gotoxy(15, 7);
			cout << "Press (K) To use Kirby  .\n  ";
			textcolor(15);
			gotoxy(15, 8);
			cout << " Press (I) To Look at the Instructions.\n ";
			textcolor(15);
			gotoxy(15, 9);
			cout << "Press(B) To Go Back To Main Menu Please "; 
			textcolor(15);
			gotoxy(15, 10);
			cout << "Enter M, P , L, K, I  or B -";
			list = _getch();
		} while (list != 'm' && list != 'i' && list != 'p' &&list != '6'&&list != 'b' &&list != 'k');
		if (list == 'i') { clrscr(); Instructionanmenu(); getch(); }
		if (list == 'm') { clrscr(); AnimationM(); getch(); }
		if (list == 'p') { clrscr();  AnimationP(); getch(); }// getch(); } //dockeykong(); getch(); }
		if (list == 'b') {  clrscr(); main(); getch(); } //this is for the first menu 
		if (list == 'k') { clrscr(); animationK(); getch(); }
	
	} while (list != '6');



}
//end of main

void Instructionanmenu(void)
{
	hline(5, 3, 11, 66); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
	hline(6, 12, 11, 65);
	vline(5, 3, 11, 10);

	vline(71, 3, 11, 10);  // Right side 



	textcolor(15);
	gotoxy(10, 4);
	cout << "Welcome to the Instruction For Animation";
	textcolor(10);
	gotoxy(10, 5);
	cout << "While Using The Animations To Move Them Use The Arrows Keys.\n";
	textcolor(14);
	gotoxy(10, 6);
	cout << "For Pokemon  Animations Please Press Space Bar To switch from ball and pokemon.\n  ";
	textcolor(13);
	gotoxy(10, 7);
	cout << "To Return To The Animation Menu Press B.\n  ";
	
	


	while (!KEY_DOWN(VK_ESCAPE));
	if (KEY_DOWN(VK_ESCAPE)) clrscr();
}
 

void AnimationM(void)
{
	int x = 1, y = 1, vt = 1, vx = 0;
	DWORD t1, t2;


	t1 = GetTickCount(); // Checks the PC time
	do { // Next, set up a while loop that only ends when key_pressed is ESC
		t2 = GetTickCount(); // Checks the PC time
		if (t2 - t1 > 50)
		{ // If t2 take t1 are less than onehundred...
			t1 = t2; // ... make T1 the same as T2 and continue
			if (KEY_DOWN(VK_UP))
			{ // If the key down is vk_up...
				y--; // ... incriment down y
			}

			if (KEY_DOWN(VK_DOWN))
			{ // If the key down is vk_down...
				y++; //  incriment up y
			}

			if (KEY_DOWN(VK_LEFT))
			{ // If the key down is vk_left...
				x--; //  incriment down x
			}

			if (KEY_DOWN(VK_RIGHT))
			{ // If the key down is vk_right...
				x++; // ... incriment up x
			}

			if (x > 80)
			{ // if x is greater than 80
				x = 80; //  set x to 80
			}

			if (y > 25)
			{ // if y is greater than 25
				y = 25; // set y to 25
			}

			if (x < 1)
			{ // if x is less than 1...
				x = 1; // ... set x to 1
			}

			if (y < 1)
			{ // if y is less than 1...
				y = 1; // ... set y to 1
			}
			clrscr();
			mario(x, y);
			if (vt == 0)
			{
				mario(x, y);
				vt = 1; 
				 
			}
			else
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


void AnimationP(void)
{
	int x = 1, y = 1, vt = 1, vx = 0;
	DWORD t1, t2;


	t1 = GetTickCount(); // Checks the PC time
	do { // Next, set up a while loop that only ends when key_pressed is ESC
		t2 = GetTickCount(); // Checks the PC time
		if (t2 - t1 > 100)
		{
			clrscr(); 
			//pokeball(x, y);
			if (KEY_DOWN(VK_SPACE)) vt = !vt;
			t1 = t2;
 
			if (vt == 1)
			{
				pokeball(x, y);
				//vt = 1;

			}
			else
			{
				clrscr(); 
				om(x, y);
				//vt = 0;

			}
		}
		
	} while (!KEY_DOWN(VK_ESCAPE));
	clrscr();
}

 


 

	
		

	 void link(void)
	 {
		 //hat
		 hline(13, 1, 10, 10);
		 hline(12, 2, 10, 12);
		 hline(11, 3, 10, 14);
		 hline(10, 4, 10, 16);
		 hline(10, 5, 10, 1);
		 hline(25, 5, 10, 1);

		 //hood 
		 hline(14, 7, 10, 2);
		 hline(20, 7, 10, 2);


		 hline(11, 5, 6, 14);
		 hline(10, 6, 6, 16);
		 hline(10, 7, 6, 2);
		 hline(10, 8, 6, 2);

		 hline(10, 8, 6, 2);

		 hline(24, 7, 6, 2);
		 hline(24, 8, 6, 2);


		 hline(14, 8, 14, 2); //eyes 
		 hline(20, 8, 14, 2); //eyes 


							  //face #

		 vline(16, 7, 6, 3);
		 vline(17, 7, 6, 3);
		 vline(18, 7, 6, 3);
		 vline(19, 7, 6, 3);
		 //vline(20, 10, 6, 5);
		 //vline(21, 10, 6, 4);
		 //vline(22, 8, 6, 5); 
		 //vline(23, 8, 6, 5);

		 hline(12, 7, 7, 2);
		 hline(12, 8, 7, 2);
		 hline(9, 9, 7, 18);
		 hline(10, 10, 7, 6);
		 //hline(10, 11, 7, 6);
		 hline(11, 11, 7, 5);
		 hline(14, 12, 7, 11);
		 hline(16, 13, 7, 4);
		 hline(20, 12, 7, 5);
		 hline(20, 10, 7, 6);
		 hline(20, 11, 7, 5);
		 hline(22, 7, 7, 2);
		 hline(22, 8, 7, 2);
		 /* This selection is the ears */
		 vline(7, 4, 7, 4);
		 vline(8, 5, 7, 4);
		 vline(9, 6, 7, 4);

		 vline(28, 4, 7, 4);
		 vline(27, 5, 7, 4);
		 vline(26, 6, 7, 4);

		 hline(28, 7, 11, 1);
		 hline(27, 8, 11, 2);
		 hline(26, 9, 11, 3);
		 hline(26, 10, 11, 3);
		 hline(26, 11, 11, 3);

		 hline(26, 12, 15, 3);
		 hline(26, 13, 15, 3);
		 hline(26, 14, 15, 2);

		 //mouth 
		 hline(16, 10, 6, 4);
		 hline(16, 11, 6, 4);

		 //top 
		 hline(9, 10, 10, 1);
		 hline(9, 11, 10, 2);
		 hline(25, 11, 10, 1);
		 hline(20, 12, 10, 6);
		 hline(20, 13, 10, 6);
		 hline(19, 14, 10, 6);
		 hline(20, 15, 10, 5);
		 hline(21, 16, 10, 4);

		 hline(18, 16, 10, 1);
		 hline(18, 17, 10, 2);
		 hline(18, 18, 10, 2);
		 hline(21, 19, 10, 6);
		 hline(25, 17, 10, 2);
		 hline(25, 18, 10, 2);
		 hline(19, 20, 10, 8);
		 hline(19, 21, 10, 8);
		 hline(18, 22, 10, 4);
		 hline(18, 19, 10, 1);
		 /*Shield*/

		 hline(6, 12, 6, 8);
		 hline(5, 13, 6, 11);
		 hline(4, 14, 6, 5);
		 hline(4, 15, 6, 5);
		 hline(4, 16, 6, 2);
		 hline(14, 16, 6, 3);
		 hline(11, 17, 6, 6);
		 hline(11, 18, 6, 6);
		 hline(11, 19, 6, 6);
		 hline(11, 20, 6, 6);
		 hline(4, 17, 6, 5);
		 hline(4, 18, 6, 5);
		 hline(4, 19, 6, 5);
		 hline(4, 20, 6, 5);
		 hline(4, 21, 6, 13);
		 hline(4, 22, 6, 12);
		 hline(6, 23, 6, 9);


		 hline(11, 14, 6, 8);
		 hline(11, 15, 6, 6);


		 hline(19, 14, 10, 6);

		 /*belt*/
		 hline(18, 15, 6, 2);
		 hline(19, 19, 6, 2);
		 //hline(17, 20, 6, 2);
		 hline(18, 20, 6, 2);
		 hline(18, 21, 6, 1);
		 hline(19, 16, 6, 2);
		 hline(20, 17, 6, 5);
		 hline(20, 18, 6, 5);
		 hline(25, 16, 6, 2);
		 hline(25, 15, 6, 2);
		 hline(25, 14, 6, 1);

		 //gap
		 hline(17, 15, 13, 1);
		 hline(17, 16, 13, 1);
		 hline(17, 17, 13, 1);
		 hline(17, 18, 13, 1);
		 hline(17, 19, 13, 1);
		 hline(17, 20, 13, 1);
		 hline(17, 20, 13, 1);
		 hline(17, 21, 13, 1);
		 hline(16, 22, 13, 1);
		 hline(15, 23, 13, 1);
		 hline(7, 24, 13, 8);
		 //shoe
		 hline(25, 21, 6, 2);
		 hline(22, 22, 6, 5);
		 hline(22, 23, 6, 5);
		 hline(22, 24, 6, 5);
		 hline(22, 25, 6, 5);
	 } 


	 void animationK(void)
	 {
		 int x = 1, y = 1;
		 DWORD t1, t2;


		 t1 = GetTickCount(); // Checks the PC time
		 do { // Next, set up a while loop that only ends when key_pressed is ESC
			 t2 = GetTickCount(); // Checks the PC time
			 if (t2 - t1 > 50)
			 { // If t2 take t1 are less than onehundred...
				 t1 = t2; // ... make T1 the same as T2 and continue
				 if (KEY_DOWN(VK_UP))
				 { // If the key down is vk_up...
					 y--; // ... incriment down y
				 }

				 if (KEY_DOWN(VK_DOWN))
				 { // If the key down is vk_down...
					 y++; // ... incriment up y
				 }

				 if (KEY_DOWN(VK_LEFT))
				 { // If the key down is vk_left...
					 x--; // ... incriment down x
				 }

				 if (KEY_DOWN(VK_RIGHT))
				 { // If the key down is vk_right...
					 x++; // ... incriment up x
				 }

				 if (x > 80)
				 { // if x is greater than 110...
					 x = 80; // ... set x to 110
				 }

				 if (y > 25)
				 { // if y is greater than 15...
					 y = 25; // ... set y to 15
				 }

				 if (x < 1)
				 { // if x is less than 1...
					 x = 1; // ... set x to 1
				 }

				 if (y < 1)
				 { // if y is less than 1...
					 y = 1; // ... set y to 1
				 }
				 clrscr();
				 Kiby(x, y);
			 }
		 } while (!KEY_DOWN(VK_ESCAPE)); clrscr(); 
	 } 

	 void Kiby(int x ,int y  )
	 {
       //outline
		 hline(x +10, y+3, 10, 10);
		 hline(x+20, y+4, 10, 1); 
		 hline(x+21, y+5, 10, 1);
		 hline(x+22, y+6, 10, 2);//hunle
		 vline(x+24, y+7, 10, 2); //hubble
		 hline(x+22, y+9, 10, 2);//hubble

		 //inside the  hat thing 
		 hline(x+10, y+4, 12, 10);
		 hline(x+ 10, y+5, 12, 11);
		 hline(x+9, y+5, 12, 12);
		 hline(x+9, y+6, 12, 13);
		 //hline(17, 6, 15, 3);
		 hline(x+11, y+7, 15, 7);
		 hline(x+18, y+7, 12, 4);
		 hline(x+18, y+8, 12, 2); 
		 hline(x+17, y+8, 15, 1);

		 //pinkish bosy 
		 hline(x+8, y+7, 13, 3); 
		 hline(x+6, y + 8, 13, 11);
		 hline(x+7, y + 9, 13, 1);
		 hline(x+9, y + 9, 13, 6);
		hline(x+16, y + 9, 13, 4);
		hline(x+7, y + 10, 13, 6);
		hline(x+7, y + 11, 13, 6);
		hline(x+7, y + 12, 13, 4);
		hline(x+7, y + 13, 13, 7);
		hline(x+15, y + 13, 13, 6);
		hline(x+16, y + 11, 13, 4);
		hline(x+16, y + 10, 13, 3);
		hline(x+18, y + 12, 13, 4);
		hline(x+15, y + 14, 13, 6);
		hline(x+8, y + 14, 13, 6);
		vline(x+14, y + 10, 13, 2);
		hline(x+13, y+12, 13, 3);
		 //eys 
		 vline(13, y + 9, 10, 3);
		 vline(15, y + 9, 10, 3);
		 // bottom half 
		 hline(7, y + 15, 13, 11);
		 hline(7, y + 16, 13, 10);
		 hline(8, y + 17, 13, 9);
		 hline(9, y + 18, 13, 8);
		 hline(11, y + 19, 13, 4);
		 //mouths 
		 vline(14, y + 13, 10, 2);
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
		 //system("color c6"); 


		 //left side 
		 vline(x + 7, y + 14, 10, 3);
		 vline(x + 6, y + 8, 10, 6);
		 hline(x + 7, y + 7, 10, 2);
		 hline(x + 8, y + 9, 10, 1);
		 vline( x + 9, y + 4, 10, 3);


}
		 





 void om (int x ,int y )
	 {

	 hline(12, 2, 6, 7);
	 hline(19, 3, 6, 2);//right side of the main out line 
	 hline(21, 4, 6, 1);//right side of the main out line 
	 vline(22, 5, 6, 2); //right side of the main out line 
	 vline(23, 7, 6, 5); //right side of the main outline 
	 hline(22, 12, 6, 1); //right side of the main outline
	 hline(20, 13, 6, 2); //right side of the main outline 
	 hline(20, 14, 6, 1);  //right side of the main outline 
	 hline(21, 15, 6, 1); //right side of the main outline 
	 hline(18, 16, 6, 3); //right side of the main outline 
	 hline(17, 15, 6, 1);  //right side of the main outline 
	 hline(16, 17, 6, 2); //right side of the main outline 
	 hline(15, 16, 6, 1); //right side of the main outline 
	 hline(13, 17, 6, 2); //right side of the main outline
	 //Left selction outline 
	 hline(12, 16, 6, 1);//bottom middle 
	 hline(10, 17, 6, 2); //bottom left
	 hline(11, 15, 6, 1); 
	 hline(7, 16, 6, 3); 
	 hline(6, 15, 6, 2);
	 hline(8, 14, 6, 1);
	 hline(5, 14, 6, 1);
	 hline(6, 13, 6, 1);
	 

	 //left top side 
	 hline(10, 3, 6, 2);
	 hline(9, 4, 6, 1);
	 vline(8, 5, 6, 3);
	 vline(7, 8, 6, 5);
	 hline(8, 11, 6, 1);
	 hline(9, 10, 6, 2);
	 vline(11, 11, 6, 1); 
	 hline(12, 12, 6, 2);
	 hline(12, 13, 6, 1);
	 hline(14, 11, 6, 2);
	 hline(16, 12, 6, 1);
	 hline(17, 13, 6, 2); 
	 hline(17, 13, 6, 1);
	 vline(17, 9, 6, 4);
	 hline(18, 8, 6, 1); 
	 vline(19, 9, 6, 2); 

	 hline(6, 14, 11, 2); 
	 hline(9, 14, 11, 6);
	
	 hline(7, 13, 11, 3);
	// hline(9, 14, 11, 2);
	 hline(8, 15, 11, 3);
	 hline(12, 15, 11,5);
	 hline(10, 16, 11, 3);
 
	 hline(13, 16, 11, 2);
	 hline(16, 16, 11, 2);
	 hline(18, 15, 11, 3);
	 hline(17, 14, 11, 4);

	 //shell
	 hline(12, 3, 14, 7);
	 hline(9, 4, 14, 12);
	 hline(9, 5, 14, 13);
	 hline(9, 6, 14, 13);
	 hline(9, 7, 14, 14);
	 hline(8, 8, 14, 10);
	 hline(8, 9, 14, 9);
	 hline(8, 10, 14, 1);
	 hline(11, 10, 14, 6);
	 hline(12, 11, 14, 3);
	 hline(16, 11, 14, 1);
	 hline(19, 8, 14, 4);
	 hline(20, 9, 14, 3);
	 hline(20, 10, 14, 3);
	 hline(19, 11, 14, 4);
	 vline(18, 9, 14, 4);
	 hline(19, 12, 14, 3);
 }



 void pokeball(int x, int y)//int x, int y)

 {
	 hline(10, 1, 11, 4);  //out line of the ball
	 hline(10, 2, 12, 4); // red part for the ball
	 hline(8, 2, 11, 2);
	 hline(14, 2, 11, 2);
	 vline(7, 3, 11, 2);//left side of the ball 
	 vline(16, 3, 11, 2); //right side of the ball
	 vline(6, 5, 11, 2);
	 vline(5, 7, 11, 4); 
	 vline(6, 11, 11, 2);
	 hline(6, 9, 11, 1); // middle part 
	 hline(7, 10, 11, 3);//middle part 
	 hline(9, 9, 11, 1);//middle part
	 hline(10, 8, 11, 3);//middle part 
	 hline(10, 11, 11, 3); //middle part 
	 hline(13, 9, 11, 1);//middle part 
	 hline(13, 10, 11, 4);//middle part 
	 hline(17, 9, 11, 1);// middle part 

	 hline(8, 3, 12, 8);//ball colour 
	 hline(8, 4, 12, 8); //ball colour
	 hline(7, 5, 12, 10);//ball colour
	 hline(7, 6, 12, 10); //ball colour 
	 hline(6, 7, 12, 12);//ball colour 
	 hline(6, 8, 12, 4);//ball colour
	 hline(7, 9, 12, 2);//ball colour 
	 hline(12, 8, 12, 6);//ball colour 
	 hline(15, 9, 12, 2);//ball colour 



	 hline(7, 13, 11, 2);
	 hline(9, 14, 11,6); //base 
	 vline(17, 5, 11, 2);
	 vline(18, 7, 11, 4);

	 //vline(19, , 11, 4);
	 vline(17, 11, 11, 2);
	 hline(15, 13, 11, 2);
 }













void mathsmenu()
{





int choice; // this defining the line




do
{

do

{
b = 219;
hline(5, 1, 14, 67); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
hline(5, 13, 14, 67);
vline(5, 2, 14, 11);
vline(71, 2, 14, 11);  // Right side

textcolor(15);

gotoxy(15, 3);
cout << "Welcome to Math Menu  .\n";
textcolor(13);
gotoxy(15, 4);
cout << "Press (1) To look at the instructions.\n";
textcolor(13);
gotoxy(15, 5);
cout << "Press (P) To Use see The Prime numbers .\n ";
textcolor(14);
gotoxy(15, 6);
cout << "Press (F) To Use The Fibonacci .\n  ";
gotoxy(15, 7);
cout << "Press (C) For Caeser Ciper.\n  ";
gotoxy(15, 8);
cout << "Press (H) For Caeser Ciper History.\n  ";
gotoxy(15, 9);
cout << "Press (B) To  Return To The Main Menu .\n  ";
gotoxy(15, 10);
cout << "Press (G) To run GameOfLife.\n";
gotoxy(15, 11);
cout << "Enter 1, P , F, C, B, H or  6 -";
choice = _getch();

}

while (choice != '1'&& choice != 'p' && choice != 'f' && choice != 'g' && choice != 'c' && choice != '6' && choice != '7' && choice != 'b' && choice != 'h');

if (choice == '1') { clrscr(); InstructionMa(); getch(); }
if (choice == 'p') { clrscr();   primemenu();  getch(); }
//{clrscr();  cout << "hey"; getch(); }
if (choice == 'g') { clrscr();  gameoflife(); getch(); }
if (choice == 'b') { clrscr(); main(); getch(); }
if (choice == 'c') { clrscr();  Caeser(); getch(); }
if (choice == 'h') { clrscr(); CaserCiperHistory(); getch(); }
if (choice == 'f') { clrscr(); fib(); getch(); }

} while (choice != '6');
clrscr();




}


void InstructionMa()
{
	hline(5, 3, 11, 66); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
	hline(6, 12, 11, 65);
	vline(5, 3, 11, 10);

	vline(71, 3, 11, 10);  // Right side 



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



	while (!KEY_DOWN(VK_ESCAPE));
	if (KEY_DOWN(VK_ESCAPE)) clrscr();
}




void gameoflife(void)//main program start
{
	//randomise the random number generator
	//srand((unsigned) time(NULL));
	//randomly set array a
	for (x = 0; x<80; x++)
	{
		for (y = 0; y<25; y++)
		{
			a[x][y] = (int)((rand() / (float)RAND_MAX)*2.0);
			//cout<<a[x][y]<<" ";
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
				if (a[x][y] == 1 && c < 2) d[x][y] = 0;
				if (a[x][y] == 1 && (c == 2 || c == 3)) d[x][y] = 1;
				if (a[x][y] == 1 && c > 3) d[x][y] = 0;
				if (a[x][y] == 0 && c == 3) d[x][y] = 1;

			}
		}

		//copy b[] into a[]
		for (x = 0; x<80; x++)
		{
			for (y = 0; y<25; y++)
			{
				a[x][y] = d[x][y];
				//cout<<a[x][y]<<" ";
			}

			//if (!KEY_DOWN(0x71));
			//{
			//clrscr();
			//a[x][y]=0 ;
			//d[x][y]=0 ; 
			//}

			if (KEY_DOWN(0x47))
			{ // If G is pressed...
				clrscr(); // ... clear the screen
				for (x = 0; x < (80 - 1); x++)
				{ // Starting at 0, if x is less than (SW-1) (def. 119), incriment x by one.
					for (y = 0; y < (25 - 1); y++)
					{ // Starting at 0, if y is less than (SH-1) (def. 29), incriment y by one.
						a[x][y] = 0; // Make a[] 0...
						d[x][y] = 0; // /// and the same for z[]
					}
				}


				a[2][6] = 1; // The following section will now draw a gosper glider
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
			{ // Starting at 0, if x is less than (SW-1) (def. 119), incriment x by one.
				for (y = 0; y < (25 - 1); y++)
				{ // Starting at 0, if y is less than (SH-1) (def. 29), incriment y by one.
					a[x][y] = rand() % 2; // Randomise the value of a[]
				}
			}
		}

		Sleep(500);
		clrscr();
		//if (KEY_DOWN(VK_ESCAPE)) clrscr();
	}

	while (!KEY_DOWN(VK_ESCAPE)); 
}
 

int fib()
{

	b = 219;
	hline(5, 2, 11, 67); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
	hline(5, 13, 11, 67);
	vline(5, 3, 11, 10);
	vline(71, 3, 11, 10);  // Right side 
	

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

int fib(int n)
{
	int NumberTwo = 1, NumberOne = 1, answer = 2;

	if (n < 3)
		return 1;

	for (n -= 3; n != 0; n--)
	{
		NumberTwo = NumberOne;
		NumberOne = answer;
		answer = NumberOne + NumberTwo;
	}

	return answer;
} 

void CaserCiperHistory()
{
	b = 219;
	hline(5, 2, 11, 67); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
	hline(5, 13, 11, 67);
	vline(5, 3, 11, 10);
	vline(71, 3, 11, 10);  // Right side  
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
		b = 219;
		hline(5, 2, 11, 67); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
		hline(5, 13, 11, 67);
		vline(5, 3, 11, 10);
		vline(71, 3, 11, 10);  // Right side 
		gotoxy(15, 5);
		cout << "Enter text:\n" << endl;
		gotoxy(15, 6);
		cout << "Enter  2 blank lines to quit.\n" << endl;
		gotoxy(15, 7);
		getline(cin, input);
		gotoxy(15, 8);
		string output = "";

		for (int i = 0; i < input.length(); i++)
		{
			output += ceasar(input[i]);

		}
		cout << output << endl;
		return 0;
		clrscr(); 
	} while (!input.length() == 0); 
	 
		// end main  
	
}


char ceasar(char m)
{
	if (isalpha(m))
	{
		m = toupper(m); //use upper to keep from having to use two seperate for A..Z a..z
		m = (((m - 65) + 13) % 26) + 65;
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
			hline(5, 2, 11, 67); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
			hline(5, 13, 11, 67);
			vline(5, 3, 11, 10);
			vline(71, 3, 11, 10);  // Right side

			textcolor(15);

			gotoxy(15, 4);
			cout << "Welcome to Prime Number  Menu  .\n";
			textcolor(13);
			gotoxy(15, 5);
			cout << "Press (1) To use the break force to find prime numbers .\n";
			textcolor(11);
			gotoxy(15, 6);
			cout << "Press (2) To use the sieve of Eratosthenes to find prime numbers.\n ";
			gotoxy(15, 7);
			cout << "Press (b) To go back to Maths Menu.";
			gotoxy(15, 8);
			cout << "Press (6) To exit the program."; 
			gotoxy(15, 9);
			cout << "Enter 1, 2 , b, 6 -";
			list = _getch();
		}
	while (list != '1'&& list != '2' && list != 'b' && list != '6');

	if (list == '1') { clrscr(); bruteforcep(); getch(); }
	if (list == '2') { clrscr();  sieveofEratosthenes(); getch(); }
	//{clrscr();  cout << "hey"; getch(); }
	if (list == 'b') { clrscr(); main(); getch(); }
	

	} while (list != '6');
clrscr(); 
}




void bruteforcep(void)
{
	int i, j, k;
	int flag;

	DWORD starttime, endtime;
	float totaltime;

	starttime = GetTickCount();//get start time
	//for (k = 0; k < RUNS; k++) //This allows have 1000 runs 
	//{
		for (i = 3; i < 100000; i++)
		{

			flag = 0; 

			 //flag == 1; 
			{
				
				for (j = 3; j < i; j++)
					if (fmod((float)i, (float)j) == 0) (flag = 1); //if modding int i and j together = 0, it is not a prime number.

				if (flag == 0)
				{
					c++;
				cout << i << " is prime!\n";
				}
				if (flag ==1)
				{
					//c++;
					//cout << i << " is not prime!\n";
				}
			}
		}
		
		// Including not prime and prime = 613.125
		//Without is not prime = 455.56 seconds
		// without is not prime and prime = 0.234 and running 10000 times 
		//Without is prime = 536.688

		/*c = 0;//reset c  
	//this will now run for 10000. 
		for (i = 0; i < 100000; i++)
		{
			
		if (flag == 0) + c++;
		}
		*/

			endtime = GetTickCount();//get finish time
								 //calc time
			totaltime = ((float)endtime - (float)starttime) / 1000.0;//calculate total time in secs
			clrscr();
			b = 219;
			hline(5, 5, 14, 67); // (4 = x, -2 =y, 11 = color and 60 = lengh)1
			hline(5, 14, 14, 67);
			vline(5, 5, 14, 10);
			vline(71, 5, 14, 10);  // Right side

			gotoxy(15, 8);
			std::cout << "Totaltime=" << totaltime << " sec\n";
			gotoxy(15, 9);
			std::cout << "primes found " << c << endl;
			gotoxy(15, 10);
			std::printf("Press any key to end....where's the any key?");
			getch();
			while (!KEY_DOWN(VK_ESCAPE)); clrscr();
		}
	

	
		



void sieveofEratosthenes(void)
{
	//long i,j;
	int flag;
	//int c=0;
	char x[100000];
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
			if (x[i] == 0) c++;
		}


		//end of K runs loop //time 0.001172

		endtime = GetTickCount();//get finish time
								 //calc time
		totaltime = ((float)endtime - (float)starttime) / (1000.0*RUNS);//calculate total time in secs



		std::cout << "Totaltime=" << totaltime << " sec\n";

		std::cout << "primes found " << c << endl;

		std::printf("Press any key to end....where's the any key?");
		getchar();

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






//Alter the code below at your peril!!!!
//It defines the textcolor,gotoxy and clrscr functions
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