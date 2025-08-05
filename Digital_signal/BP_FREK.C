/* Amplitudengang Bandpass  */

#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<snap.h>

void main()
{
int GraphDriver, GraphMode, N;
double Re_z, Im_z, Re_n, Im_n, Omega, Betrag;


/* Amplitudengang von
 Y[N] = 1.7119*Y[N-1] -0.81*Y[N-2] + X[N] -X[N-1]
 Radius=0.9, Periode=20 , 0 < Omega < Pi in 300 Schritten */

GraphDriver= DETECT;

initgraph(&GraphDriver,&GraphMode, "C:\\TC\\BGI");

cleardevice();
Re_z=0.0; 
Im_z = 0.0;
Re_n =0.0;
Im_n =0.0;

for(N=0;N<=299;N++) 
	{
	Omega = 3.141593 * N/300.0;
	Re_z = 1.0 - cos(Omega);
	Im_z = sin(Omega);
	Re_n = 1.0  - 1.7119*cos(Omega) + 0.81 * cos(2.0*Omega);
	Im_n = 1.7119 * sin(Omega) - sin(2.0 * Omega);
	Betrag = sqrt((Re_z*Re_z + Im_z*Im_z)/(Re_n * Re_n +Im_n *Im_n));
	

	if(Betrag > 0.0) Betrag = Betrag * 3.0 +0.5;
	if(Betrag < 0.0) Betrag = Betrag * 3.0 -0.5;

	line(N,100,N,(100-(int)Betrag));
	}


getch();

capture("C:\\TC\\Capture\\BP_FREK.jpg");
closegraph();
}