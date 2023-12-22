#include <nds.h>
#include <stdio.h>
#include <maxmod9.h>
#include <time.h>
#include "soundbank.h"
#include "soundbank_bin.h"
// Tama�o pantalla
#define SCREEN_NUM_ROWS 24
#define SCREEN_NUM_COLS 32

u8 t_ogro[64] =
{
    3,8,13,5,5,3,8,3,
    0,3,5,8,8,5,3,0,
    13,13,5,5,5,5,13,13,
    4,5,2,5,5,2,5,13,
    5,13,2,2,5,2,4,5,
    5,13,2,2,2,2,13,5,
    8,13,8,8,2,8,13,8,
    13,13,8,4,13,8,13,13,
};

u8 t_suelo[64] =
{
    3,3,3,3,3,3,3,3,
    0,3,3,3,3,3,3,0,
    13,0,0,3,0,0,0,4,
    13,4,13,0,13,13,4,13,
    13,13,13,13,13,13,13,13,
    13,13,13,13,4,13,4,13,
    13,4,13,13,13,13,13,4,
    13,13,13,13,4,13,13,13,
};

u8 t_rio[64] =
{
    
    3,3,3,3,3,3,3,3,
    3,3,3,5,6,3,3,3,
    3,3,5,3,5,6,6,3,
    3,5,3,3,3,5,5,6,
	5,3,3,3,3,3,3,5,
    3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
};
u8 t_rio2[64] =
{
    
    3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
    3,3,3,3,5,6,3,3,
    3,3,3,5,3,5,6,6,
	3,5,5,3,3,3,5,5,
    5,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
};
u8 t_rio3[64] =
{
    
    3,3,3,3,3,3,3,3,
    5,6,3,3,3,3,3,3,
    3,5,3,5,3,5,5,3,
    3,3,3,3,5,3,3,3,
	3,5,3,3,3,3,3,3,
    5,3,5,5,6,5,3,5,
    3,3,3,3,5,3,3,3,
    3,3,3,3,3,3,3,3,
};

u8 t_tanque[64] =
{
    
    7,7,2,2,2,2,7,7,
    0,0,8,8,8,8,0,0,
    7,7,8,8,8,8,7,7,
    0,0,8,8,8,8,0,0,
	7,7,8,8,8,8,7,7,
    0,0,2,8,8,2,0,0,
    2,2,2,9,9,2,2,2,
    3,3,3,9,9,3,3,3,
};
u8 t_explo[64] =
{
    
    3,3,10,10,10,10,3,3,
    3,10,10,10,10,10,10,3,
    3,11,10,10,10,10,11,10,
    10,11,10,10,10,10,11,10,
	10,11,11,11,11,11,11,10,
    3,10,3,10,3,3,10,10,
    3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
};
u8 t_misil[64] =
{
    
    3,0,0,0,0,0,0,3,
    3,0,1,1,1,1,0,3,
    3,0,10,10,10,10,0,3,
    3,0,1,1,1,1,0,3,
	3,0,1,1,1,1,0,3,
    3,3,10,1,1,10,3,3,
    3,3,10,10,10,10,3,3,
    3,3,3,10,10,3,3,3,
};

u8 t_piedra[64] =
{
	7,7,7,7,7,7,7,7,
    3,7,7,7,7,7,7,3,
    3,7,7,7,7,7,7,3,
    3,7,7,7,7,7,7,3,
    3,3,7,7,7,7,3,3,
    3,3,7,7,7,7,3,3,
    3,3,3,3,7,7,3,3,
    3,3,3,3,3,3,3,3,
};
u8 t_pajaro[64] =
{
	3,3,3,7,7,3,3,3,
    3,3,3,7,9,7,3,3,
    3,3,3,7,9,7,3,3,
    3,3,3,7,9,7,7,3,
    7,0,7,7,9,9,9,7,
    11,11,9,9,9,9,9,7,
    7,7,7,7,7,7,7,3,
    3,3,3,3,0,3,3,3,
};
u8 t_pajaro2[64] =
{
	3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,
    7,0,7,7,7,7,7,7,
    11,11,9,9,9,9,9,7,
    7,7,7,7,9,7,7,3,
    3,3,3,7,9,7,3,3,
    3,3,3,7,9,7,3,3,
	3,3,3,7,7,3,3,3,
};
u8 t_MonedaAzul[64] =
{
	3,3,0,0,0,0,3,3,
    3,0,12,12,12,12,0,3,
	0,12,12,12,12,12,12,0,
    0,12,12,1,12,12,12,0,
    0,12,12,12,1,12,12,0,
    3,0,12,12,12,12,0,3,
    3,3,0,12,12,0,3,3,
    3,3,3,0,0,3,3,3,
};

u8 t_MonedaAmarilla[64] =
{
	3,3,0,0,0,0,3,3,
    3,0,11,11,11,11,0,3,
	0,11,11,4,4,11,11,0,
    0,11,4,11,11,4,11,0,
    0,11,4,11,11,4,11,0,
    3,0,11,4,4,11,0,3,
    3,3,0,11,11,0,3,3,
    3,3,3,0,0,3,3,3,
};
u8 t_MonedaRoja[64] =
{
	3,3,0,0,0,0,3,3,
    3,0,9,9,9,9,0,3,
	0,9,9,9,9,9,9,0,
    0,9,9,0,0,9,9,0,
    0,9,9,0,0,9,9,0,
    3,0,9,9,9,9,0,3,
    3,3,0,9,9,0,3,3,
    3,3,3,0,0,3,3,3,
};

u8 t_Avion[64] =
{
	3,3,3,3,9,3,3,3,
    3,3,3,9,9,3,3,3,
    3,3,9,4,4,9,3,9,
    9,9,9,4,4,9,9,9,
    9,9,9,4,4,9,9,9,
    3,3,9,4,4,9,3,9,
    3,3,3,9,9,3,3,3,
    3,3,3,3,9,3,3,3,
};
u8 t_Fondo[64] =
{
	0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
};

u8 t_Avion2[64] =
{
	3,3,3,3,9,3,3,3,
    3,3,3,9,9,3,3,3,
    3,3,9,4,4,9,3,10,
    9,9,9,4,4,9,10,11,
    9,9,9,4,4,9,10,11,
    3,3,9,4,4,9,3,10,
    3,3,3,9,9,3,3,3,
    3,3,3,3,9,3,3,3,
};

u16 mapData[768] =
{
	5,5,5,5,5,5,5,5, 5,5,5,5,5,5,5,5,  5,5,5,5,5,5,5,5, 5,5,5,5,5,5,5,5,
	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,
	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,
	2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,  2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,

	2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,  2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,
	2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,  2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,
	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,
	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,

	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,
	2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,  2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,
	2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,  2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,
	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,

	2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,  2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,
	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,
	2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,  2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,
	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,

	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,
	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,
	2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,  2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,
	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,

	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,
	2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,  2,3,2,3,2,3,2,3, 2,3,2,3,2,3,2,3,
	4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,  4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,
	1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
};

u16 mapData2[768] =
{
	15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,  15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,
	15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,  15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,
	15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,  15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,
	15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,  15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,

	15,15,2,15,15,15,15,15, 15,3,2,3,2,3,2,15,  	15,15,3,2,2,3,2,3, 		15,3,2,3,2,3,2,15,
	15,15,2,15,15,15,15,15, 15,3,15,15,15,15,3,15,  2,3,3,15,15,15,15,15, 	15,15,15,3,15,15,15,15,
	15,15,4,15,15,15,15,15, 15,4,15,15,15,15,4,15,  4,4,15,15,15,15,15,15, 	15,15,15,4,15,15,15,15,
	15,15,4,15,15,15,15,15, 15,4,15,15,15,15,4,15,  4,4,4,4,4,4,4,15, 		15,15,15,3,15,15,15,15,

	15,15,4,15,15,15,15,15, 15,4,15,15,15,15,4,15,  15,15,15,15,15,15,4,4, 	15,15,15,4,15,15,15,15,
	15,15,2,15,15,15,15,15, 15,3,15,15,15,15,3,15,  15,15,15,15,15,15,2,3, 	15,15,15,4,15,15,15,15,
	15,15,2,15,15,15,15,15, 15,3,15,15,15,15,3,15,  15,15,15,15,15,3,2,3, 	15,15,15,2,15,15,15,15,
	15,15,4,4,4,4,4,4, 		15,4,4,4,4,4,4,15,  	15,3,3,3,2,3,15,15, 	15,15,15,4,15,15,15,15,

	15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,  15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,
	15,3,2,3,2,3,15,15, 	 15,4,4,4,4,4,15,4,  		15,15,15,4,15,4,4,4, 		3,15,3,2,3,2,3,15,
	15,4,15,15,15,4,15,15,   15,15,15,3,15,15,15,2, 	15,15,15,2,15,3,15,15, 	15,15,4,15,15,15,4,15,
	15,3,15,15,15,2,15,15, 	 15,15,15,4,15,15,15,3,  	15,15,15,3,15,4,15,15, 	15,15,3,15,15,15,2,15,

	15,4,4,4,4,2,15,15, 	15,15,15,4,15,15,15,4, 	15,15,15,4,15,3,4,3, 		4,15,4,4,4,3,4,15,
	15,4,4,15,15,15,15,15, 	15,15,15,4,15,15,15,15, 	3,15,4,15,15,4,15,15, 	15,15,4,4,15,15,15,15,
	15,3,15,3,15,15,15,15, 	15,15,15,3,15,15,15,15,  	2,15,2,15,15,4,15,15, 	15,15,3,15,3,15,15,15,
	15,3,15,15,2,15,15,15, 	15,15,15,4,15,15,15,15,  	3,15,3,15,15,4,15,15, 	15,15,3,15,15,2,15,15,

	15,4,15,15,15,4,15,15, 	15,4,4,4,4,4,15,15,  		15,4,15,15,15,4,4,4, 		4,15,4,15,15,15,4,15,
	15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,  15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,
	15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,  15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,
	15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,  15,15,15,15,15,15,15,15, 15,15,15,15,15,15,15,15,
};
// Texto pantalla superior
// Gráficos pantalla inferior

void MoverOgro();
void TeclasOgro();
void ColisionOgro();
void GenerarMisil();
void GenerarMoneda();
void ConfigurarInterrupciones();
double closed_interval_rand(double x0,double x1);

void Inicializacion();
int RellenaObjetos();
void TeclasInicio();

static u16* mapMemory;
int pos_mapMemory;
int pos_mapData;
int ogro_fila = 23;
int ogro_columna = 16;
int record=0;
int mov=0;
//cambio inicio
bool extra=false;
int tiempo=0;
int tiemporeal=0;
int puntos=0;
int estado = 0;
bool final = false;
bool apoyo=false;

//efectos
mm_sound_effect ranamov= {{ SFX_RANA } ,(int)(1.0f * (1<<10)),	0,	255,0,};

mm_sound_effect lose= {{ SFX_LOSE } ,(int)(1.0f * (1<<10)),	0,	255,0,};

mm_sound_effect win= {{ SFX_WIN } ,(int)(1.0f * (1<<10)),	0,	255,0,};

mm_sound_effect coin= {{ SFX_COIN } ,(int)(1.0f * (1<<10)),	0,	255,0,};

void int_timer() 
{	
	GenerarMisil();
	
	tiempo--;
	if (tiempo==0) final=true;
	
}
void int_timer_4() //controlar eventos
{	
	tiemporeal++;
	if (tiemporeal==40 ||tiemporeal==60|| tiemporeal==80){
		
		irqEnable(IRQ_TIMER2);
		mapMemory[2*32+31]=9;
		apoyo=false;
		extra=true;
	}
	if(tiemporeal==65) {
		TIMER_DATA(1)=61000; 
		TIMER_CR(1) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ ;
	}
	if (tiempo==15 && puntos <51 && apoyo!=true){
	
		irqEnable(IRQ_TIMER2);
		mapMemory[2*32+31]=14;
		apoyo=true;
		extra=true;
	}
	
}
void int_timer_2() 
{
	//misisl
   int f,c;
	for(f=24;f>0;f--){
		for(c=0;c<32;c++){
			pos_mapMemory = f*32+c;
			if(mapMemory[pos_mapMemory]==7){
				if(mapMemory[(f)*32+c+1]==2)mapMemory[pos_mapMemory] = 3;
				else if((mapMemory[(f)*32+c+1]==3))mapMemory[pos_mapMemory] = 2;
				else mapMemory[pos_mapMemory] = 4;
				mapMemory[(f+1)*32+c] =7;
			}
			if(f==23 && mapMemory[pos_mapMemory]==4){
				mapMemory[f*32+c]  = 1;
			}
		}
		
	}
	//moneda azul
	for(f=24;f>0;f--){
		for(c=0;c<32;c++){
			pos_mapMemory = f*32+c;
			if(mapMemory[pos_mapMemory]==11){
				if(mapMemory[(f)*32+c+1]==2)mapMemory[pos_mapMemory] = 3;
				else if((mapMemory[(f)*32+c+1]==3))mapMemory[pos_mapMemory] = 2;
				else mapMemory[pos_mapMemory] = 4;
				mapMemory[(f+1)*32+c] =11;
			}
			if(f==23 && mapMemory[pos_mapMemory]==4){
				mapMemory[f*32+c]  = 1;
			}
		}
	}
	//moenda roja
	for(f=24;f>0;f--){
		for(c=0;c<32;c++){
			pos_mapMemory = f*32+c;
			if(mapMemory[pos_mapMemory]==12){
				if(mapMemory[(f)*32+c+1]==2)mapMemory[pos_mapMemory] = 3;
				else if((mapMemory[(f)*32+c+1]==3))mapMemory[pos_mapMemory] = 2;
				else mapMemory[pos_mapMemory] = 4;
				mapMemory[(f+1)*32+c] =12;
			}
			if(f==23 && mapMemory[pos_mapMemory]==4){
				mapMemory[f*32+c]  =1;
			}
		}
	}
	//moneda amarilla
	for(f=24;f>0;f--){
		for(c=0;c<32;c++){
			pos_mapMemory = f*32+c;
			if(mapMemory[pos_mapMemory]==13){
				if(mapMemory[(f)*32+c+1]==2)mapMemory[pos_mapMemory] = 3;
				else if((mapMemory[(f)*32+c+1]==3))mapMemory[pos_mapMemory] = 2;
				else mapMemory[pos_mapMemory] = 4;
				mapMemory[(f+1)*32+c] =13;
			}
			if(f==23 && mapMemory[pos_mapMemory]==4){
				mapMemory[f*32+c] = 1;
			}
		}
	}
	
	//piedra
	for(f=24;f>0;f--){
		for(c=0;c<32;c++){
			pos_mapMemory = f*32+c;
			if(mapMemory[pos_mapMemory]==8){
				if(mapMemory[(f)*32+c+1]==2)mapMemory[pos_mapMemory] = 3;
				else if((mapMemory[(f)*32+c+1]==3))mapMemory[pos_mapMemory] = 2;
				else mapMemory[pos_mapMemory] = 4;
				mapMemory[(f+1)*32+c] =8;
			}
			if(f==23 && mapMemory[pos_mapMemory]==4){
				mapMemory[f*32+c] = 1;
			}
		}
	}
}
	
void int_timer_3() //pajaro
{	
	irqDisable(IRQ_TIMER0);
	int f,c;
	
	if(apoyo==false){
		for(f=1;f<3;f++){
			for(c=0;c<32;c++){
				pos_mapMemory = f*32+c;
				if (mapMemory[pos_mapMemory]==9 || mapMemory[pos_mapMemory]==10){
					double numran=closed_interval_rand (0.1 , 0.9);
					if(numran>=0.2){
						mapMemory[(f+1)*32+c] =8;
					}
					 mapMemory[pos_mapMemory] = 3;
					 if(mov==0){
						mapMemory[f*32+(c-1)] =9;
						mov=1;
					}else{
						mapMemory[f*32+(c-1)] =10;
						mov=0;
					}
				}else{
					mapMemory[pos_mapMemory] = 3;
				}
			}
		}
		if(mapMemory[2*32+0]==9 || mapMemory[2*32+0]==10){
			irqEnable(IRQ_TIMER0);
			irqDisable(IRQ_TIMER2);
			mapMemory[2*32+0]=8;
			extra=false;
		}
	}
	else{
		for(f=1;f<3;f++){
			for(c=0;c<32;c++){
				pos_mapMemory = f*32+c;
				if (mapMemory[pos_mapMemory]==14 || mapMemory[pos_mapMemory]==16){
					double numran=closed_interval_rand (0.1 , 0.9);
					if(numran>=0.55){
						mapMemory[(f+1)*32+c] =12;
					}
					 mapMemory[pos_mapMemory] = 3;
					 if(mov==0){
						mapMemory[f*32+(c-1)] =14;
						mov=1;
					}else{
						mapMemory[f*32+(c-1)] =16;
						mov=0;
					}
				}else{
					mapMemory[pos_mapMemory] = 3;
				}
			}
		}
		if(mapMemory[2*32+0]==14 || mapMemory[2*32+0]==16){
			irqEnable(IRQ_TIMER0);
			irqDisable(IRQ_TIMER2);
			mapMemory[2*32+0]=3;
			extra=false;
		}
	}
	
	
}


int main( void )
{
	// Semilla n�meros aleatorios
	srand (time(NULL));
	ogro_fila = 23;
	ogro_columna = 15;
	int fila;
	int columna;
	int pos_mapData;


	REG_POWERCNT = POWER_ALL_2D;
	REG_DISPCNT  = MODE_0_2D   | DISPLAY_BG0_ACTIVE ;
	VRAM_A_CR    = VRAM_ENABLE | VRAM_A_MAIN_BG ;
	BGCTRL [0]   = BG_32x32    | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1);

	static u8*  tileMemory = (u8*)  BG_TILE_RAM(1);
	mapMemory  = (u16*) BG_MAP_RAM(0);

	BG_PALETTE[0]=RGB15( 0, 0, 0); // Negro
	BG_PALETTE[1]=RGB15(31,31,31); // Blanco
	BG_PALETTE[2]=RGB15(18,9,2); // marron
	BG_PALETTE[3]=RGB15( 11,26, 5); // verde radio 
	BG_PALETTE[4]=RGB15(20,20,0);  // amarillo apagado
	BG_PALETTE[5]=RGB15( 6, 21,1); // verde 2
	BG_PALETTE[6]=RGB15( 22, 30,19); // verde 3
	BG_PALETTE[7]=RGB15( 12, 12,12); // gris
	BG_PALETTE[8]=RGB15( 4, 12,3); // verde tanque
	BG_PALETTE[9]=RGB15( 21, 5,3); // rojo tanque
	BG_PALETTE[10]=RGB15( 30, 5,2); // rojo explosion
	BG_PALETTE[11]=RGB15( 30, 27,2); // amarillo explosion
	BG_PALETTE[12]=RGB15( 3, 12,27); // azul
	BG_PALETTE[13]=RGB15( 19, 17,3); // suelo
	

	dmaCopy(t_ogro,      tileMemory ,      sizeof(t_ogro));
	dmaCopy(t_suelo,    tileMemory + 64,  sizeof(t_suelo));
	dmaCopy(t_rio,      tileMemory + 128, sizeof(t_rio));
	dmaCopy(t_rio2,      tileMemory + 192, sizeof(t_rio2));
	dmaCopy(t_rio3,      tileMemory + 256, sizeof(t_rio3));
	dmaCopy(t_tanque,      tileMemory + 320, sizeof(t_tanque));//5
	dmaCopy(t_explo,      tileMemory + 384, sizeof(t_explo));
	dmaCopy(t_misil,      tileMemory + 448, sizeof(t_misil));
	dmaCopy(t_piedra,      tileMemory + 512, sizeof(t_piedra));
	dmaCopy(t_pajaro,      tileMemory + 576, sizeof(t_pajaro));
	dmaCopy(t_pajaro2,      tileMemory + 640, sizeof(t_pajaro2));//10
	dmaCopy(t_MonedaAzul,      tileMemory + 704, sizeof(t_MonedaAzul));
	dmaCopy(t_MonedaAmarilla,      tileMemory + 768, sizeof(t_MonedaAmarilla));
	dmaCopy(t_MonedaRoja,      tileMemory + 832, sizeof(t_MonedaRoja));
	dmaCopy(t_Avion,      tileMemory + 896, sizeof(t_Avion));
	dmaCopy(t_Fondo,      tileMemory + 960, sizeof(t_Fondo));
	dmaCopy(t_Avion2,      tileMemory + 1024, sizeof(t_Avion2));
	
	ConfigurarInterrupciones();
	pos_mapData = 0;
	for(fila=0;fila<24;fila++)
		for(columna=0;columna<32;columna++)
		{
			pos_mapMemory            = fila*32+columna;
			mapMemory[pos_mapMemory] = mapData2[pos_mapData];
			pos_mapData ++;
	    }
		
	consoleDemoInit();
	mmInitDefaultMem((mm_addr)soundbank_bin);
	
	//load the module
	mmLoad( MOD_FLATOUTLIES );
	mmLoad( MOD_MUSICA );
	//load sound effects
	mmLoadEffect( SFX_RANA );
	mmLoadEffect( SFX_LOSE );
	mmLoadEffect( SFX_WIN );
	mmLoadEffect( SFX_COIN );

	//Start playing module
	mmStart( MOD_MUSICA, MM_PLAY_LOOP );
	
	while(1)
	{
		if (estado == 0){ // Esperando para iniciar partida
			iprintf("\x1b[6;2HPulsa A para jugar");
			iprintf("\x1b[8;2Ho B para la dificultad 2");
			
		}
		if (estado == 1){ // Jugando

			iprintf("\x1b[4;2H                            ");
			iprintf("\x1b[6;2H                            ");
			iprintf("\x1b[8;2H                            ");
			iprintf("\x1b[4;2HPULSA B PARA PAUSAR");
			iprintf("\x1b[9;2HTiempo = %d s", tiempo);
			iprintf("\x1b[11;2HPuntos = %d     ", puntos);
			iprintf("\x1b[14;2HRecord = %d     ", record);
			
			if( mapMemory[ogro_fila*32+ogro_columna]==7|| mapMemory[ogro_fila*32+ogro_columna]==8){ 
				final=true;
				mmEffectEx(&lose);
			}
			if( mapMemory[ogro_fila*32+ogro_columna]==11){ 
				mapMemory[ogro_fila*32+ogro_columna]=0;
				tiempo=tiempo+2;
				puntos=puntos+10;
				mmEffectEx(&coin);
			}
			if( mapMemory[ogro_fila*32+ogro_columna]==13){ 
			mapMemory[ogro_fila*32+ogro_columna]=0;
				tiempo=tiempo+4;
				puntos=puntos+2;
				mmEffectEx(&coin);
			}
			if( mapMemory[ogro_fila*32+ogro_columna]==12){ 
				mapMemory[ogro_fila*32+ogro_columna]=0;
				tiempo=tiempo+6;
				puntos=puntos+16;
				mmEffectEx(&coin);
			}
		}
	
		if (estado == 2){ // Jugando
			iprintf("\x1b[4;2H                            ");
			iprintf("\x1b[4;2HJUEGO EN PAUSA");
		}
		if (final == true)
		{
			if (puntos>record){
				record=puntos;
				mmEffectEx(&win);
			}
			mmStart( MOD_MUSICA, MM_PLAY_LOOP );
			iprintf("\x1b[9;2H                                    ");
			iprintf("\x1b[4;2HEL JUEGO HA TERMINADO");
			iprintf("\x1b[11;2HPuntos = %d     ", puntos);
			iprintf("\x1b[14;2HRecord = %d     ", record);
			
			irqDisable(IRQ_TIMER2);
			irqDisable(IRQ_TIMER1);
			irqDisable(IRQ_TIMER0);
			irqDisable(IRQ_TIMER3);
			REG_KEYCNT = 0x4003;
			estado = 0;
			final=false;
		}
		swiWaitForVBlank();
	}
}

void ConfigurarInterrupciones()
{
	irqSet(IRQ_KEYS,MoverOgro);
	irqEnable(IRQ_KEYS); 
	REG_KEYCNT = 0x4003;
	
	irqEnable(IRQ_TIMER0);
	irqSet(IRQ_TIMER0,int_timer); 
	
	irqEnable(IRQ_TIMER1);
	irqSet(IRQ_TIMER1,int_timer_2); 
	
	irqEnable(IRQ_TIMER2);
	irqSet(IRQ_TIMER2,int_timer_3);
	
	irqEnable(IRQ_TIMER3);
	irqSet(IRQ_TIMER3,int_timer_4); 
	
	TIMER_DATA(0)=32768; 
	TIMER_CR(0) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ ;
	TIMER_DATA(1)=52000; 
	TIMER_CR(1) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ ;
	
	TIMER_DATA(2)=60000; 
	TIMER_CR(2) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ ;
	TIMER_DATA(3)=32768; 
	TIMER_CR(3) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ ;
	
	irqDisable(IRQ_TIMER2);
	irqDisable(IRQ_TIMER1);
	irqDisable(IRQ_TIMER0);
	irqDisable(IRQ_TIMER3);
}

void MoverOgro(){
	
	TeclasInicio();
	mapMemory[(ogro_fila)*32+ogro_columna]=1;
	
	TeclasOgro();
	pos_mapMemory = (ogro_fila)*32+ogro_columna;
	ColisionOgro(pos_mapMemory);
	
	//Dibujar ogro
	if (final==false){
		mapMemory[pos_mapMemory] = 0;
		
	}
}

void TeclasOgro(){
	
	if (REG_KEYINPUT == 0x03DF) //Izquierda
	{
		if (ogro_columna>0)
		{
			ogro_columna -= 1;
		}	
	}
	if (REG_KEYINPUT == 0x03EF) //Derecha
	{
		if (ogro_columna<31)
		{
			ogro_columna += 1;
		}	
	}
	mmEffectEx(&ranamov);
}

void TeclasInicio(){
	if (REG_KEYINPUT == 0x03FE) 
	{
		
		irqEnable(IRQ_TIMER0);
		irqEnable(IRQ_TIMER1);
		irqEnable(IRQ_TIMER3);
		REG_KEYCNT = 0x4032;
		tiempo = 60;
		tiemporeal=0;
		puntos=0;
		apoyo=false;
		extra=false;
		
		ogro_fila = 23;
		ogro_columna = 15;
		
		TIMER_DATA(1)=52000; 
		TIMER_CR(1) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ ;
	
		Inicializacion();
		estado = 1;
		mmStart( MOD_FLATOUTLIES, MM_PLAY_LOOP );
	}
	
	if (REG_KEYINPUT == 0x03FD) 
	{
		if(estado==1){
			estado=2;
			mmStart( MOD_MUSICA, MM_PLAY_LOOP );
			irqDisable(IRQ_TIMER0);
			irqDisable(IRQ_TIMER1);
			irqDisable(IRQ_TIMER3);
			irqDisable(IRQ_TIMER2);
			REG_KEYCNT = 0x4002;
		}
		else if(estado==2){
			mmStart( MOD_FLATOUTLIES, MM_PLAY_LOOP );
			estado=1;
			if(extra==true) irqEnable(IRQ_TIMER2);
			irqEnable(IRQ_TIMER0);
			irqEnable(IRQ_TIMER1);
			irqEnable(IRQ_TIMER3);
			REG_KEYCNT = 0x4032;
		}
		else{
			irqEnable(IRQ_TIMER0);
			irqEnable(IRQ_TIMER1);
			irqEnable(IRQ_TIMER3);
			REG_KEYCNT = 0x4032;
			tiempo = 40;
			tiemporeal=20;
			puntos=0;
			apoyo=false;
			extra=false;
			
			ogro_fila = 23;
			ogro_columna = 15;
			
			TIMER_DATA(1)=56000; 
			TIMER_CR(1) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ ;
	
			Inicializacion();
			estado = 1;
			mmStart( MOD_FLATOUTLIES, MM_PLAY_LOOP );
		}
	}
}

void ColisionOgro(int pos_mapMemory){
	if( mapMemory[pos_mapMemory]==7|| mapMemory[pos_mapMemory]==8){ 
		final=true;
		mapMemory[pos_mapMemory]=0;
		mmEffectEx(&lose);
	}
	if( mapMemory[pos_mapMemory]==11){ 
		mapMemory[pos_mapMemory]=0;
		tiempo=tiempo+2;
		puntos=puntos+10;
		mmEffectEx(&coin);
	}
	if( mapMemory[pos_mapMemory]==13){ 
		mapMemory[pos_mapMemory]=0;
		tiempo=tiempo+4;
		puntos=puntos+2;
		mmEffectEx(&coin);
		
	}
	if( mapMemory[pos_mapMemory]==12){ 
		mapMemory[pos_mapMemory]=0;
		tiempo=tiempo+6;
		puntos=puntos+16;
		mmEffectEx(&coin);
	}
}

void Inicializacion(){
	
	int fila;
	int columna;
	pos_mapData = 0;
	for(fila=0;fila<24;fila++)
		for(columna=0;columna<32;columna++)
		{
			pos_mapMemory            = fila*32+columna;
			mapMemory[pos_mapMemory] = mapData[pos_mapData];
			pos_mapData ++;
		}
}

void GenerarMisil()
{
	int haybom=0;
	int f,c;
	for(c=0;c<32;c++){
		double numran=closed_interval_rand (0.1 , 0.9);
		for(f=1;f<3;f++){
			pos_mapMemory = f*32+c;
			if(mapMemory[pos_mapMemory]==7){
				haybom=1;
			}
		}
		if(numran>0.72 && haybom==0){
			mapMemory[1*32+c] =7;
			haybom=0;
		}
		GenerarMoneda();
	}
}

void GenerarMoneda()
{
	int haybom=0;
	int f,c;
	for(c=0;c<32;c++){
		double numran=closed_interval_rand (0.1 , 1.9);
		for(f=1;f<2;f++){
			pos_mapMemory = f*32+c;
			if(mapMemory[pos_mapMemory]==7||mapMemory[pos_mapMemory]==11||mapMemory[pos_mapMemory]==12||mapMemory[pos_mapMemory]==13){
				haybom=1;
			}
		}
		if((numran<0.11) && haybom==0){
			mapMemory[1*32+c] =11;
			haybom=0;
		}else if((numran>1.89)&& haybom==0){
			mapMemory[1*32+c] =13;
			haybom=0;
		}else if(numran>=0.5&& numran<=0.501 && haybom==0){
			mapMemory[1*32+c] =12;
			haybom=0;
		}  
	
	}
}

double closed_interval_rand ( double x0 , double x1){
 return x0 + (x1 - x0) * rand () / (( double ) RAND_MAX ) ;
}

