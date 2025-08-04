/* Frequenz-Variation Bandsperre */
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<snap.h>
void main()
{
int GraphDriver, GraphMode;
double X[300];
double Y[300];
int N;

for (N=0;N<=299;N++) X[N]=sin(3.141593*N*(0.025+0.0005*N));

Y[0]=0;
Y[1]=0;

for (N=2;N<=299;N++) Y[N] = X[N] - 1.4142 *X[N-1] + X[N-2];
/* Nullstelle der Uebertragungsfkt bei +-2 PI/8 fuer Periode N=8 */

GraphDriver= DETECT;

initgraph(&GraphDriver,&GraphMode, "C:\\TC\\BGI");

cleardevice();


for(N=0;N<=299;N++) 
	{

	if(X[N] > 0.0) X[N]= X[N]*30.0 +0.5;
	if(X[N] < 0.0) X[N]= X[N]*30.0 -0.5;
	if(Y[N] > 0.0) Y[N]= Y[N]*30.0 +0.5;
	if(Y[N] < 0.0) Y[N]= Y[N]*30.0 -0.5;

	line(2*N,100,2*N,(100-(int)X[N]));
	line(2*N,200,2*N,(200-(int)Y[N]));

	}


getch();

capture("C:\\TC\\Capture\\B_Sperr_1.jpg");
closegraph();
}