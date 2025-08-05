/* Mehrdeutigkeit diskreter sinusformiger Signale  */
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<snap.h>
void main()
 {
 int GraphDriver, GraphMode;
 float X[400];float OMEGA;
 int N,L,K;

OMEGA = 2.0*3.141593/10.0; /* OMEGA = Zwei Pi durch 10 */

 for (L=0; L<=9; L++)
 {
	for (K=0; K<=39; K++)
	{
	N=K+40*L;
	X[N]= cos(OMEGA*N*L);
	}
 }

 GraphDriver=DETECT;

 initgraph(&GraphDriver,&GraphMode, "C:\\TC\\BGI");

 cleardevice();

 

for(N=0;N<=399;N++) 
	{	if(X[N] > 0.0) X[N]= X[N]*30.0 +0.5;
		if(X[N] < 0.0) X[N]= X[N]*30.0 -0.5;
		line(N,100,N,(100-(int)X[N]));
	}

capture("C:\\TC\\Capture\\Mehr_deu2.jpg");
 getch();
 closegraph();
 }