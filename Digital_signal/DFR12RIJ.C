/* 	DIGITALE SIGNALVERARBEITUNG
	DISKRETE FOURIER-REIHE  (12-WERTE-ARRAY)
	DARST. REALTEIL UND PHASE ( DFR12RIJ.C )  */

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <snap.h>

void main()
{
	int GraphMode, GraphDriver;
	double X[12], CR[12], CI[12], PI, SKAL1, SKAL2, SKAL3;
	int N, K, I_VZ_IM, I_VZ_RE;
	
	PI=3.141593;    /*-- Konstante PI  --*/
/*-- Nullsetzen der Felder und Eintragen des x(n)-Verlaufs  --*/
	for (N=0;N<=11;N++) {
	    CR[N] = 0.0;
	    CI[N] = 0.0;
	    X[N] = 4.0 + cos(2.0*PI*N/12.0) + sin(2.0*PI*N/6.0);
	}

	for (K=0;K<=11;K++) {
	     for (N=0;N<=11;N++) {
		  CR[K] = CR[K]+(1.0/12.0)*X[N]*cos(2.0*PI*K*N/12.0);
		  CI[K] = CI[K]-(1.0/12.0)*X[N]*sin(2.0*PI*K*N/12.0);
	     }
	}


	
	
/*-- SKALIEREN von X, REALTEIL CR und IM.TEIL CI fuer GRAFIK ohne Rundung */

	for (N=0;N<=11;N++) {
	    X[N] = X[N] * 3.0;
	    CR[N] = CR[N] * 10.0;
	    CI[N] = CI[N] * 10.0;
	}
/*-- Vorbereitung der graphischen  Ausgabe --*/
	GraphDriver=DETECT;
	initgraph(&GraphDriver,&GraphMode, "C:\\TC\\BGI");
	cleardevice();
/*-- Darstellung von X, REAL- UND IMAG.TEIL auf dem Schirm  --*/
	for (N=0;N<=11;N++) {
	    line (5*N,50,5*N,(50-(int)X[N]));
	    line (5*N,120,5*N,(120-(int)CR[N]));
	    line (5*N,160,5*N,(160-(int)CI[N]));
	}
	capture("C:\\TC\\Capture\\DFR12RIJ.jpg");
	getch(); /*-- mit <RETURN> geht es weiter --*/
	closegraph();
}