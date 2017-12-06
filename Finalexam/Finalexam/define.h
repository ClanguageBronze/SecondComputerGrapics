#include<GL/freeglut.h>
#include<GL/glut.h>
#include<GL/GLU.h>
#include<GL/GL.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<mmsystem.h>


#define GAMESTART 0A01
#define GAMEQUIT 0Z99
#define GAMEINTRO 0A00

#define ANGLE 40


#define START_DAY 500

#define MID_TERM 800
#define FIRST_HOMEWORK 600
#define FINAL_TERM 1600
#define PRESETATION 1800
#define RESULT 2000

#define WINDOW_SIZE_WIDTH 800

#define WINDOW_SIZE_HEIGHT1 600
#define WINDWO_sIZE_HEIGHT2 800

#define INEXIT -1

GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info) {
	FILE *fp;
	GLubyte *bits;
	int bitsize, infosize;
	BITMAPFILEHEADER header;
	if ((fp = fopen(filename, "rb")) == NULL)return NULL;
	if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp) < 1) { fclose(fp); return NULL; }
	if (header.bfType != 'MB') { fclose(fp); return NULL; }
	infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
	if ((*info = (BITMAPINFO*)malloc(infosize)) == NULL) { fclose(fp); exit(0); return NULL; }
	if (fread(*info, 1, infosize, fp) < (unsigned int)infosize) { free(*info); fclose(fp); return NULL; }
	if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0)
		bitsize = ((*info)->bmiHeader.biWidth*((*info)->bmiHeader.biHeight)) * 3;
	if ((bits = (unsigned char *)malloc(bitsize)) == NULL) { free(*info); fclose(fp); return NULL; }
	if (fread(bits, 1, bitsize, fp) < (unsigned int)bitsize) { free(*info); free(bits); fclose(fp); return NULL; }
	fclose(fp);
	return bits;
}
