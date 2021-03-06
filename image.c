#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"
#include "palette.h"

uint8_t palette[256][3]={
{0,0,0},//0
{0,0,0},
{0,0,0},
{0,0,0},
{0,0,0},
{0,0,0},
{0,0,0},
{0,0,0},
{0,0,0},
{0,0,0},
{23,35,35},
{35,51,51},
{47,67,67},
{63,83,83},
{75,99,99},
{91,115,115},
{111,131,131},
{131,151,151},
{159,175,175},
{183,195,195},
{211,219,219},//20
{239,243,243},
{51,47,0},
{63,59,0},
{79,75,11},
{91,91,19},
{107,107,31},
{119,123,47},
{135,139,59},
{151,155,79},
{167,175,95},
{187,191,115},
{203,207,139},
{223,227,163},
{67,43,7},
{87,59,11},
{111,75,23},
{127,87,31},
{143,99,39},
{159,115,51},
{179,131,67},//40
{191,151,87},
{203,175,111},
{219,199,135},
{231,219,163},
{247,239,195},
{71,27,0},
{95,43,0},
{119,63,0},
{143,83,7},
{167,111,7},
{191,139,15},
{215,167,19},
{243,203,27},
{255,231,47},
{255,243,95},
{255,251,143},
{255,255,195},
{35,0,0},
{79,0,0},
{95,7,7},//60
{111,15,15},
{127,27,27},
{143,39,39},
{163,59,59},
{179,79,79},
{199,103,103},
{215,127,127},
{235,159,159},
{255,191,191},
{27,51,19},
{35,63,23},
{47,79,31},
{59,95,39},
{71,111,43},
{87,127,51},
{99,143,59},
{115,155,67},
{131,171,75},
{147,187,83},
{163,203,95},//80
{183,219,103},
{31,55,27},
{47,71,35},
{59,83,43},
{75,99,55},
{91,111,67},
{111,135,79},
{135,159,95},
{159,183,111},
{183,207,127},
{195,219,147},
{207,231,167},
{223,247,191},
{15,63,0},
{19,83,0},
{23,103,0},
{31,123,0},
{39,143,7},
{55,159,23},
{71,175,39},//100
{91,191,63},
{111,207,87},
{139,223,115},
{163,239,143},
{195,255,179},
{79,43,19},
{99,55,27},
{119,71,43},
{139,87,59},
{167,99,67},
{187,115,83},
{207,131,99},
{215,151,115},
{227,171,131},
{239,191,151},
{247,207,171},
{255,227,195},
{15,19,55},
{39,43,87},
{51,55,103},//120
{63,67,119},
{83,83,139},
{99,99,155},
{119,119,175},
{139,139,191},
{159,159,207},
{183,183,223},
{211,211,239},
{239,239,255},
{0,27,111},
{0,39,151},
{7,51,167},
{15,67,187},
{27,83,203},
{43,103,223},
{67,135,227},
{91,163,231},
{119,187,239},
{143,211,243},
{175,231,251},//140
{215,247,255},
{11,43,15},
{15,55,23},
{23,71,31},
{35,83,43},
{47,99,59},
{59,115,75},
{79,135,95},
{99,155,119},
{123,175,139},
{147,199,167},
{175,219,195},
{207,243,223},
{63,0,95},
{75,7,115},
{83,15,127},
{95,31,143},
{107,43,155},
{123,63,171},
{135,83,187},
{155,103,199},
{171,127,215},
{191,155,231},
{215,195,243},
{243,235,255},
{63,0,0},
{87,0,0},
{115,0,0},
{143,0,0},
{171,0,0},
{199,0,0},
{227,7,0},
{255,7,0},
{255,79,67},
{255,123,115},
{255,171,163},
{255,219,215},
{79,39,0},
{111,51,0},
{147,63,0},
{183,71,0},
{219,79,0},
{255,83,0},
{255,111,23},
{255,139,51},
{255,163,79},
{255,183,107},
{255,203,135},
{255,219,163},
{0,51,47},
{0,63,55},
{0,75,67},
{0,87,79},
{7,107,99},
{23,127,119},
{43,147,143},
{71,167,163},
{99,187,187},
{131,207,207},
{171,231,231},
{207,255,255},
{63,0,27},
{103,0,51},
{123,11,63},
{143,23,79},
{163,31,95},
{183,39,111},
{219,59,143},
{239,91,171},
{243,119,187},
{247,151,203},
{251,183,223},
{255,215,239},
{39,19,0},
{55,31,7},
{71,47,15},
{91,63,31},
{107,83,51},
{123,103,75},
{143,127,107},
{163,147,127},
{187,171,147},
{207,195,171},
{231,219,195},
{255,243,223},
{55,75,75},
{255,183,0},
{255,219,0},
{255,255,0},
{39,143,135},
{7,107,99},
{7,107,99},
{7,107,99},
{27,131,123},
{155,227,227},
{55,155,151},
{55,155,151},
{55,155,151},
{115,203,203},
{67,91,91},
{83,107,107},
{99,123,123},
{8,67,8},
{16,85,16},
{24,103,24},
{32,121,32},
{40,139,40},
{48,157,48},
{56,175,56},
{64,193,64},
{72,211,72},
{80,219,80},
{88,237,88},
{92,255,92}
};

void image_new(rct2_image_t* image,uint16_t width,uint16_t height,int16_t x_offset,int16_t y_offset,uint16_t flags)
{
image->width=width;
image->height=height;
image->x_offset=x_offset;
image->y_offset=y_offset;
image->flags=flags;
image->data=calloc(width*height,sizeof(uint8_t));
}


void image_copy(rct2_image_t* src,rct2_image_t* dst)
{
dst->width=src->width;
dst->height=src->height;
dst->x_offset=src->x_offset;
dst->y_offset=src->y_offset;
dst->flags=src->flags;
dst->data=calloc(src->width*src->height,sizeof(uint8_t));
memmove(dst->data,src->data,src->width*src->height);
}
//TODO prevent writing outside image
void image_blit(rct2_image_t* dst,rct2_image_t* src,int16_t x_offset,int16_t y_offset)
{
x_offset+=src->x_offset;
y_offset+=src->y_offset;
	if(x_offset<0||y_offset<0||x_offset+src->width>dst->width||y_offset+src->height>dst->height)
	{
	printf("Image blit out of bounds\n");
	return;
	}
	for(int y=0;y<src->height;y++)
	for(int x=0;x<src->width;x++)
	{
		if(src->data[y*src->width+x])dst->data[(y_offset+y)*dst->width+x_offset+x]=src->data[y*src->width+x];
	}
}

//TODO proper error  handling
void image_write_bmp(rct2_image_t* image,FILE* file)
{
int padding=(4-(image->width*3)%4)%4;

int data_size=image->height*(image->width*3+padding);

uint8_t bitmap_header[54];
memset(bitmap_header,0,54);

bitmap_header[0]='B';
bitmap_header[1]='M';
*((uint32_t*)(bitmap_header+2))=54+data_size;
*((uint32_t*)(bitmap_header+10))=54;
*((uint32_t*)(bitmap_header+14))=40;
*((uint32_t*)(bitmap_header+18))=image->width;
*((uint32_t*)(bitmap_header+22))=image->height;
*((uint16_t*)(bitmap_header+26))=1;
*((uint16_t*)(bitmap_header+28))=24;
*((uint32_t*)(bitmap_header+38))=2834;
*((uint32_t*)(bitmap_header+42))=2834;

fwrite(bitmap_header,1,54,file);

    for(int y=image->height-1;y>=0;y--)
    {
        for(int x=0;x<image->width;x++)
        {
        uint8_t index=image->data[x+image->width*y];
        fputc(palette[index][2],file);
        fputc(palette[index][1],file);
        fputc(palette[index][0],file);
        }
        for(int k=0;k<padding;k++)fputc(0,file);
    }
//return ERROR_NONE;
}

void image_destroy(rct2_image_t* image)
{
free(image->data);
}
