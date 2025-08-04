/* Linie Zeichnen */
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<snap.h>
void main()
{
int GraphDriver, GraphMode;
double X[300], Y[300];
int N;

for (N=0;N<=299;N++) X[N]=sin(3.141593*N*(0.025+0.0005*N));

Y[0]=0;
Y[1]=0;

for (N=2;N<=299;N++) Y[N] = 1.7119*Y[N-1] -0.81*Y[N-2] + X[N] -X[N-1];
/* Radius=0.9, Periode=20 */

GraphDriver= DETECT;

initgraph(&GraphDriver,&GraphMode, "C:\\TC\\BGI");

cleardevice();


for(N=0;N<=299;N++) 
	{

		// round the result
	if(X[N] > 0.0) X[N]= X[N]*10.0 +0.5;
	if(X[N] < 0.0) X[N]= X[N]*10.0 -0.5;
	if(Y[N] > 0.0) Y[N]= Y[N]*10.0 +0.5;
	if(Y[N] < 0.0) Y[N]= Y[N]*10.0 -0.5;

	line(2*N,50,2*N,(50-(int)X[N]));
	line(2*N,150,2*N,(150-(int)Y[N]));

	}


getch();

capture("C:\\TC\\Capture\\B_3.jpg");
closegraph();
}