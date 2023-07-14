#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void printDiag(bool info=false)
{
//	CRT OUTER LINE (TOP)    
	setcolor(WHITE);			
	line(100,140,450,140);
	line(450,140,600,50);
//	CRT OUTER LINE (BOTTOM)
    line(100,260,450,260);
    line(450,260,600,340);
    
//  Screen	
 	ellipse(600,195,0,360,20,145);
// 	Base
 	rectangle(80,140,100,260);
// 	Pins
	rectangle(40,150,80,160);
	rectangle(40,180,80,190);
	rectangle(40,210,80,220);
	rectangle(40,240,80,250);
	
//	Electron Gun
	rectangle(100,190,140,210);
	
//	Focusing System
//	Top

	line(170,170,230,170);
	line(180,180,220,180);
	line(170,170,170,190);
	line(230,170,230,190);
	
	line(180,180,180,190);
	line(220,180,220,190);
	
	line(220,190,230,190);
	line(170,190,180,190);
	
	
//	Bottom
//	line(180,220,200,220);
	
	line(170,230,230,230);
	line(180,220,220,220);
	line(170,230,170,210);
	line(230,230,230,210);
	
	line(180,220,180,210);
	line(220,220,220,210);
	
	line(220,210,230,210);
	line(170,210,180,210);
	
//	Deflection System
//	X Deflect
//	Back
	line(280,180,320,180);
	line(280,180,280,190);
	line(320,180,320,210);
	line(310,210,320,210);

//	Front
	line(270,190,310,190);
	line(270,190,270,220);
	line(310,190,310,220);
	line(270,220,310,220);

//	Y Deflect
//	Top
	line(360,180,400,180);
	line(370,170,410,170);
	line(360,180,370,170);
	line(400,180,410,170);

//	Rear
	line(360,220,400,220);
	line(370,210,410,210);
	line(360,220,370,210);
	line(400,220,410,210);
////	
//Y Deflect
////	Top
//	line(340,180,380,180);
//	line(350,170,390,170);
//	line(340,180,350,170);
//	line(380,180,390,170);
//
////	Rear
//	line(340,220,380,220);
//	line(350,210,390,210);
//	line(340,220,350,210);
//	line(380,220,390,210);

	if(info)
	{
		line(60,245,60,345);
		outtextxy(60,350,"Pins");
		line(120,200,120,345);
		outtextxy(120,350, "Electron Gun");
		line(200,200,200,315);
		outtextxy(200,320, "Focusing System");
		line(300,80,300,185);
		outtextxy(300,80, "X deflect");
		line(380,80,380,175);
		outtextxy(370,60, "Y deflect");
		line(600,195,600,395);
		outtextxy(600,400, "Phoshphor Coated Screen");
		outtextxy(300,450,"Working Of CRT");
		delay(5000);
	}
}
int main() {
    int gdriver = DETECT, gmode;
//  clrscr();
    initgraph(&gdriver, &gmode, (char*)"");
//  set Window Size
	initwindow(800, 600);
//  print(120,200,0,260);
//	print(380,200,2,100);+
	
	printDiag(true);
	int movement=260;
	for(int i=0;i<movement;i++)
    {
    	printDiag();
    	setcolor(10);
    	line(120,200,120+i,200+0);
    	line(120,201,120+i,201+0);
    	delay(10);
    	cleardevice();
//    	printDiag();
    }
	
    movement=220;
    int factor=0;
	for(int i=0;i<movement;i++)
    {
    	printDiag();
    	setcolor(10);
//		Fixed Line
    	line(120,200,380,200);
    	line(120,201,380,201);
    	line(380,200,380+i,200-factor);
    	line(380,201,380+i,201-factor);
    	if(!(i%2))
    		factor;
//    	printf(" %lf ",factor);
    	delay(10);
    	cleardevice();
//    	printDiag();
    }
//    ray till deflection
    line(120,200,380,200);
    line(120,201,380,201);
//    deflected Ray
    line(380,200,600,200-factor);
    line(380,201,600,201-factor);
	printDiag();
//	Pixel Glown
    putpixel(600,200-factor,YELLOW);
    putpixel(601,200-factor,YELLOW);
    putpixel(600,201-factor,YELLOW);
    putpixel(601,201-factor,YELLOW);
    delay(1000);
    cleardevice();
//    Ray Disappeared
    printDiag();

    putpixel(600,200-factor,YELLOW);
    putpixel(601,200-factor,YELLOW);
    putpixel(600,201-factor,YELLOW);
    putpixel(601,201-factor,YELLOW);
    putpixel(600,202-factor,YELLOW);
    putpixel(601,202-factor,YELLOW);
    putpixel(600,203-factor,YELLOW);
    putpixel(601,203-factor,YELLOW);
    delay(3000);
    cleardevice();
//    Pixel Disappeared
    printDiag();
    printDiag(true);
    getch();
    closegraph();
    
    return 0;
}
