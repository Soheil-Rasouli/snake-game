#include <iostream>
#include <windows.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>


using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int x, int y) {
	COORD CurserPosition;
	CurserPosition.X=x;
	CurserPosition.Y=y;
	SetConsoleCursorPosition(console,CurserPosition);
}
class point {
	private:
		int x,y;
	public:
		point(int x, int y) {
			this->x =x;
			this->y =y;

		}
		point() {

		}


		void setpoint(int x, int y) {
			this->x =x;
			this->y =y;

		}
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
		void moveUP() {
			y--;
		}
		void moveDown() {
			y++;
		}
		void moveRight() {
			x++;
		}
		void moveLeft() {
			x--;
		}
		void Draw() {
			gotoxy(x,y);
			cout<<"*";
		}
		void erase() {
			gotoxy(x,y);
			cout<<" ";
		}
		void debug() {
			cout<<x;

		}


};
int X=0;
int Y=0;
void feed(){
	X=rand()%50;
	Y=rand()%50;
	gotoxy(X,Y);
	cout<<"#";
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	
	int size=6;
	point a[10];

while(1==1){
	feed();

	for(int pashmak=1; pashmak<=size; pashmak++) {
		a[pashmak].setpoint(pashmak,1);
        }
	




	
	while(a[size].getX()<X){
			for(int f=1; f<=size; f++) {	
				a[f].moveRight();
				a[f].Draw();
				usleep(10000);
				a[1].erase();
			
				if(a[f].getX()==X){
					for(int g=1;g<=size;g++){
						a[g].erase();
					}
				}	
			}
	}
	
	
	for(int pashmak=1; pashmak<=size; pashmak++) {
		a[pashmak].setpoint(X,pashmak);
    } 
    
    
    
	while(a[1].getY()<Y){
		    
		for(int f=1; f<=size; f++) {	
			a[f].moveDown();
			a[f].Draw();
			usleep(10000);

			a[1].erase();	
			if(a[f].getY()==Y)
			{
			   break;
			}
		}
	}
	    
	for(int pashmak=1; pashmak<=size; pashmak++) {
		a[pashmak].setpoint(X,pashmak);
    }
	
	while(a[1].getY()>Y){
		
		for(int f=1; f<=size; f++){
			
			a[f].moveUP();
			a[f].Draw();
			usleep(10000);

			a[1].erase();
			if(a[f].getY()==Y)
			{
			   break;
			}
		}
	}
	
	for(int pashmak=1; pashmak<=size; pashmak++) {
		a[pashmak].setpoint(1,pashmak);
    }
	  
	while(a[size].getX()>X){
			for(int f=1; f<=size; f++) {	
				a[f].moveLeft();
				a[f].Draw();
				usleep(10000);
				a[1].erase();
			
				if(a[f].getX()==X){
					for(int g=1;g<=size;g++){
						a[g].erase();
					}
				}	
			}
	}
	
	
}	

	


	return 0;
}
