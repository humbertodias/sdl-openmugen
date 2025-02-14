//    Open Mugen is a redevelopment of Elecbyte's M.U.G.E.N wich will be 100% compatible to it
//    Copyright (C) 2004  Sahin Vardar
//
//    If you know bugs or have a wish on Open Muegn or (money/girls/a car) for me ;-)
//    Feel free and email me: sahin_v@hotmail.com  ICQ:317502935
//    Web: http://openmugen.sourceforge.net/
//    --------------------------------------------------------------------------
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "global.h"

void scale2x(SDL_Surface *src, SDL_Surface *dst);

//Konstructor
CVideoSystem::CVideoSystem()
{
    // work=screen=NULL;
    work=NULL;
    window=NULL;
    renderer=NULL;
    nowTime=lastTime=0;
    nFpsCount=0;
    renderer = NULL;
     
    
}
//Destructor
CVideoSystem::~CVideoSystem()
{
    PrintMessage("CVideoSystem::~CVideoSystem() Cleaning Up");
    CleanUp();
    
}

void CVideoSystem::CleanUp()
{
   //SDL_FreeSurface(work);
   //SDL_FreeSurface(screen); 
   //SDL_FreeSurface(font);
}

bool CVideoSystem::InitSystem()
{
    PrintMessage("CVideoSystem::InitSystem()");

    // Create SDL2 window
    window = SDL_CreateWindow(OMTITLE,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        320, 240, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        throw CError("SDL_CreateWindow Failed");
        return false;
    }

    //Set the icon for the application
    // SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL);
    // TODO: SDL2
    SDL_Surface* icon = SDL_LoadBMP("icon.bmp");
    if (icon != NULL) {
        SDL_SetWindowIcon(window, icon);
        SDL_FreeSurface(icon);  // Libere a superfície após usá-la
    }


    // Create SDL2 renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        throw CError("SDL_CreateRenderer Failed");
        return false;
    }

    // Create texture for rendering
    work = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 320, 240);
    if (work == NULL)
    {
        throw CError("SDL_CreateTexture Failed");
        return false;
    }

    // Set background color (magenta)
    SDL_SetRenderTarget(renderer, work);
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, NULL);

    // Initialize FPS manager
    SDL_initFramerate(&m_FPSmanager);
    SDL_setFramerate(&m_FPSmanager, 60);

    // Load debug fonts
    LoadFont();

    return true;
}

void CVideoSystem::LoadFont()
{
    FILE *pFile;
    char strTemp[255];
    int i=0;
    
    //Loading debug fonts
    font=SDL_LoadBMP("data/DebugFonts.bmp");
    
    if(font==NULL)
       PrintMessage("CVideoSystem:: DebugFonts not found");
       
    pFile=fopen("data/font.txt","r");
    
    if(pFile==NULL)
        PrintMessage("font.txt not found");
    
    while(!feof(pFile))
    {
        fgets(strTemp,255,pFile);
        sscanf(strTemp,"%c %i %i",&my_Fonts[i].c,&my_Fonts[i].x,&my_Fonts[i].nWidth);
        i++;    
    }
    
    // SDL_SetColorKey(font,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0,0,0));

    // Set color key (black as transparent)
    SDL_SetColorKey(font, SDL_TRUE, SDL_MapRGB(font->format, 0, 0, 0));

    // Convert surface to texture
    SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer, font);
    if (!fontTexture)
    {
        throw CError("SDL_CreateTextureFromSurface Failed");
    }

    // Free the surface after conversion
    SDL_FreeSurface(font);

}

//To clear the screen
// void CVideoSystem::Clear()
// {
//     Uint32 Color;
//
//     Color=SDL_MapRGB(screen->format,0,0,0);
//     SDL_FillRect(work,NULL,Color);
//
// }

void CVideoSystem::Clear()
{
    SDL_SetRenderTarget(renderer, work); // Set texture as render target
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color
    SDL_RenderClear(renderer); // Clear the texture
    SDL_SetRenderTarget(renderer, NULL); // Reset to default
}


//Copy the work surface to screen backbuffer and then flip
void CVideoSystem::Draw()
{
    
    // SDL_UnlockSurface(work);

    void* pixels;
    int pitch;
    SDL_LockTexture(work, NULL, &pixels, &pitch);  // Lock texture (if needed)
    SDL_UnlockTexture(work);


    nowTime=SDL_GetTicks();
    if(nowTime > lastTime+500)
    {
        nFps=(float)nFpsCount*1000 / (nowTime-lastTime);
        nFpsCount=0;
        lastTime=nowTime;
    
    }
    DrawText(0,0,"%2.2f FPS",nFps);
         
    //FilterImage();
    
    //scale2x(work,screen);
    
    // SDL_BlitSurface(work,NULL,screen,NULL);
    
    SDL_RenderCopy(renderer, work, NULL, NULL);
    SDL_RenderPresent(renderer);


    // SDL_Flip(screen);
    // TODO: SDL2
    SDL_RenderPresent(renderer);

    
     //Limit the frame rate to 60 Hz
    SDL_framerateDelay(&m_FPSmanager);
    
    nFpsCount++;
    
   
}

//this is the MMX version of Scale2x only uses this if we have a CPU with MMX support
void CVideoSystem::FilterImage()
{
/*#ifndef _XBOX
    if(SDL_LockSurface(work) < 0)
        PrintMessage("Was not able to lock work surface");
    
    if(SDL_LockSurface(screen) < 0)
        PrintMessage("Was not able to lock screen surface");
    
   
   scale2x_uint16 *dst0,*dst1;
   scale2x_uint16 *scr0,*scr1,*scr2;
 
   dst0=(scale2x_uint16*)screen->pixels;
   dst1=dst0+(screen->pitch/2);   
   
   scr0=(scale2x_uint16*)work->pixels;
   scr1=scr0 + (work->pitch/2);
   scr2=scr1 + (work->pitch/2);
   
    scale2x_16_mmx(dst0,dst1,scr0,scr1,scr2,640);
   
   
   
     
  for(int i=0;i<240;i++)
  {
      scale2x_16_mmx(dst0,dst1,scr0,scr1,scr2,640);
      dst0+=(screen->pitch/2);
      dst1+=(screen->pitch);
      
 /*     scr0=scr1;
      scr1=scr2;
      scr2+=(work->pitch/2);
   
     
  }
  
   SDL_UnlockSurface(work);
   SDL_UnlockSurface(screen);
   
   //Clear the MMX 
   scale2x_mmx_emms();
#endif*/

}

void CVideoSystem::DrawRect(Sint16 x,Sint16 y,Sint16 x1,Sint16 y1,Uint8 R,Uint8 G,Uint8 B)
{
       
}

//Draw a string to video
void CVideoSystem::DrawText(int x,int y,char *strText,...)
{
   char string[255];                  // Temporary string
  
  int nRow=0;
  int nCol=0;
  
  SDL_Rect fontRect;
  SDL_Rect screenRect;

  va_list ap;                // Pointer To List Of Arguments
  va_start(ap, strText);     // Parses The String For Variables
  vsprintf(string, strText, ap); // Converts Symbols To Actual Numbers
  va_end(ap);
  
  memset(&fontRect,0,sizeof(SDL_Rect));
  memset(&screenRect,0,sizeof(SDL_Rect));
  
  screenRect.w=5;
  screenRect.h=8;

  
  fontRect=screenRect;
    
  screenRect.x=x;
  screenRect.y=y;
  
  
  for(int i=0;i<strlen(string);i++)
  {
    for(int j=0;j<255;j++)
    {
        if(string[i]==my_Fonts[j].c)
        {
          
          fontRect.x=my_Fonts[j].x;
          fontRect.w=my_Fonts[j].nWidth;
                
          j=255;
        }
    
    }
    
    if(string[i]!=32)
    {
     // SDL_BlitSurface(font,&fontRect,work,&screenRect);

        SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer, font);
        SDL_RenderCopy(renderer, fontTexture, &fontRect, &screenRect);
        SDL_DestroyTexture(fontTexture); // Clean up after rendering

    screenRect.x+=fontRect.w;
    }
    else
    screenRect.x+=5;
    
   
  }
 

//  SDL_BlitSurface(font,NULL,work,NULL);



}
//Creates a SDL Surface
// SDL_Surface * CVideoSystem::CreateSurface(int x,int y)
// {
//     SDL_Surface* temp=NULL;
//
//     temp=SDL_CreateRGBSurface(SDL_SWSURFACE,x,y,16,screen->format->Rmask
//                                                   ,screen->format->Gmask
//                                                   ,screen->format->Bmask
//                                                   ,screen->format->Amask);
//
//
//     if(temp==NULL)
//     {
//         PrintMessage("CVideoSystem::CreateSurfac Create Surfacce Failed %s",SDL_GetError());
//         return NULL;
//     }
//     return temp;
//
// }

SDL_Texture* CVideoSystem::CreateTexture(int width, int height)
{
    SDL_Texture* texture = SDL_CreateTexture(renderer,
                                             SDL_PIXELFORMAT_RGBA8888,
                                             SDL_TEXTUREACCESS_TARGET,
                                             width, height);

    if (!texture)
    {
        PrintMessage("CVideoSystem::CreateSurface Failed: %s", SDL_GetError());
        return NULL;
    }

    return texture;
}


void CVideoSystem::NormalBlt(SFFSPRITE *lpSprite,s16 x,s16 y,bool bMask)
{
     u16 *lpWorkData;
     u16 pitch;

     s16 width=lpSprite->PcxHeader.widht;
     s16 height=lpSprite->PcxHeader.height;
     u8* byData=lpSprite->byPcxFile;
     u16 *ColorTable=lpSprite->ColorPallet;
     
     //calculate x and y value
     y-=height-(height-lpSprite->y);
     x-=width-(width-lpSprite->x);
     
     // lpWorkData=(u16*)work->pixels;
     // pitch=work->pitch/2;

    void* tempPixels;
    int tempPitch;

    if (SDL_LockTexture(work, NULL, &tempPixels, &tempPitch) == 0) {
        lpWorkData = (uint16_t*)tempPixels;  // Cast to 16-bit
        pitch = tempPitch / 2;  // Convert pitch from bytes to 16-bit words
        SDL_UnlockTexture(work);
    } else {
        PrintMessage("Failed to lock texture: %s", SDL_GetError());
    }

     u16 yClip=0;
     u16 yClip2=0;
     u16 xClip=0;
     u16 xClip2=0;
        
     
     if( x+width > XMAX)
     {
       width-=  x+width - XMAX;  
     }
  
     if( x<0 )
     {
         xClip=-x;
         x=0;
     }
    
    
     if(y+height >YMAX)
        height-=y+height - YMAX;
    
     if(y<0)
     {
        yClip=-y;
        y=0;           
     }
    
     lpWorkData+=y*pitch;
     lpWorkData+=x;
    
    if(!bMask)
    {
              
         for(int i=yClip;i<height;i++)
         {
      
            for(int j=xClip;j<width;j++)
            {
              *lpWorkData=ColorTable[byData[j + i*lpSprite->PcxHeader.widht]];               
               lpWorkData++;
               
             }
             lpWorkData-=width-xClip;
             lpWorkData+=pitch;

          }

     }
     else
     {
         for(int i=yClip;i<height;i++)
         {
      
            for(int j=xClip;j<width;j++)
            {
              if(byData[j + i*lpSprite->PcxHeader.widht] != byData[0])      
              *lpWorkData=ColorTable[byData[j + i*lpSprite->PcxHeader.widht]];               
               lpWorkData++;
               
             }
             lpWorkData-=width-xClip;
             lpWorkData+=pitch;

          }
         
         
     }

}

void CVideoSystem::NormalFlipH(SFFSPRITE *lpSprite,s16 x,s16 y,bool bMask)
{
      u16 *lpWorkData;
     u16 pitch;

     s16 width=lpSprite->PcxHeader.widht;
     s16 height=lpSprite->PcxHeader.height;
     u8* byData=lpSprite->byPcxFile;
     u16 *ColorTable=lpSprite->ColorPallet;
     
     //calculate x and y value
     y-=height-(height-lpSprite->y);
     x-=width-lpSprite->x;
     
     // lpWorkData=(u16*)work->pixels;
     // pitch=work->pitch/2;

    void* tempPixels;
    int tempPitch;

    if (SDL_LockTexture(work, NULL, &tempPixels, &tempPitch) == 0) {
        lpWorkData = (uint16_t*)tempPixels;  // Cast to 16-bit
        pitch = tempPitch / 2;  // Convert pitch from bytes to 16-bit words
        SDL_UnlockTexture(work);
    } else {
        PrintMessage("Failed to lock texture: %s", SDL_GetError());
    }

     
     u16 yClip=0;
     u16 yClip2=0;
     u16 xClip=0;
     u16 xClip2=0;
        
     
     if( x+width > XMAX)
     {
       xClip2=width;  
       width-=  x+width - XMAX;
     //need for h flip
       xClip2=xClip2-width;
     }
  
     if( x<0 )
     {
         xClip=-x;
         x=0;
     }
    
    
     if(y+height >YMAX)
        height-=y+height - YMAX;
    
     if(y<0)
     {
        yClip=-y;
        y=0;           
     }
    
     lpWorkData+=y*pitch;
     lpWorkData+=x;
    
    if(!bMask)
    {           
         for(int i=yClip;i<height;i++)
         {
      
            for(int j=xClip;j<width;j++)
            {
              *lpWorkData=ColorTable[byData[width-j+xClip2-1 + i*lpSprite->PcxHeader.widht]];               
               lpWorkData++;
               
             }
             lpWorkData-=width-xClip;
             lpWorkData+=pitch;

          }

    }
    else
    {
         for(int i=yClip;i<height;i++)
         {
      
            for(int j=xClip;j<width;j++)
            {
              if(byData[width-j+xClip2-1 + i*lpSprite->PcxHeader.widht] != byData[0])
              *lpWorkData=ColorTable[byData[width-j+xClip2-1 + i*lpSprite->PcxHeader.widht]];               
               lpWorkData++;
               
             }
             lpWorkData-=width-xClip;
             lpWorkData+=pitch;

          }
        
    }
     
}

// u16 CVideoSystem::MapRGB(Uint8  red,Uint8  green,Uint8 blue)
// {
//    return (u16)SDL_MapRGB(screen->format,red,green,blue);
// }

uint16_t CVideoSystem::MapRGB(uint8_t red, uint8_t green, uint8_t blue) {
    SDL_PixelFormat* format = SDL_AllocFormat(SDL_PIXELFORMAT_RGB565);
    uint16_t mappedColor = (uint16_t)SDL_MapRGB(format, red, green, blue);
    SDL_FreeFormat(format); // Free memory after use
    return mappedColor;
}

/*
void CVideoSystem::NormalBlt(SFFSPRITE *lpSprite,s16 x,s16 y,bool bMask,float xScale,float yScale,PalFX *effect)
{
     u16 *lpWorkData;
     u16 pitch;

     s16 width=(u16)(lpSprite->PcxHeader.widht*xScale);
     s16 height=(u16)(lpSprite->PcxHeader.height*yScale);
     u8* byData=lpSprite->byPcxFile;
     RGBColor *ColorTable=lpSprite->ColorPallet;
     
     //calculate x and y value
     y-=height-(height-lpSprite->y*yScale);
     x-=width-(width-lpSprite->x*xScale);

     
     
     if(SDL_LockSurface(work) < 0)
        PrintMessage("Was not able to lock work surface");

     lpWorkData=(u16*)work->pixels;
     pitch=work->pitch/2;
     
//clipping    

     u16 yClip=0;
     u16 yClip2=0;
     u16 xClip=0;
     u16 xClip2=0;
     
     Clip(x,y,width,height,xClip,xClip2,yClip,yClip2);        
     
     
     lpWorkData+=y*pitch;
     lpWorkData+=x;
     
     
        //only use the the scaled verion if we need to scale
       if( (xScale != 1.0) || (yScale !=1.0) )
       {      
  
         for(int i=yClip;i<height;i++)
         {
      
            for(int j=xClip;j<width;j++)
            {
              *lpWorkData=(u16)SDL_MapRGB(screen->format,
                                       ColorTable[byData[(u16)(j/xScale) + (u16)(i/yScale)*lpSprite->PcxHeader.widht]].R,
                                       ColorTable[byData[(u16)(j/xScale) + (u16)(i/yScale)*lpSprite->PcxHeader.widht]].G,
                                       ColorTable[byData[(u16)(j/xScale) + (u16)(i/yScale)*lpSprite->PcxHeader.widht]].B);               
               lpWorkData++;
               
             }
             lpWorkData-=width-xClip;
             lpWorkData+=pitch;

        }
         
     }
     
  
     if( (xScale == 1.0) && (yScale == 1.0) )
     {
          for(int i=yClip;i<height;i++)
     {
      
      if(!bMask)
      {
    
        for(int j=xClip;j<width;j++)
        {
           *lpWorkData=(u16)SDL_MapRGB(screen->format,
                                ColorTable[byData[j + i*lpSprite->PcxHeader.widht]].R,
                                ColorTable[byData[j + i*lpSprite->PcxHeader.widht]].G,
                                ColorTable[byData[j + i*lpSprite->PcxHeader.widht]].B);
           lpWorkData++;
               
        }
        lpWorkData-=width-xClip;
        lpWorkData+=pitch;

       }
       else
       {
        for(int j=xClip;j<width;j++)
        {
           if((u16)SDL_MapRGB(screen->format,
                                ColorTable[byData[j + i*lpSprite->PcxHeader.widht]].R,
                                ColorTable[byData[j + i*lpSprite->PcxHeader.widht]].G,
                                ColorTable[byData[j + i*lpSprite->PcxHeader.widht]].B) 
           != (u16)SDL_MapRGB(screen->format,
                                ColorTable[0].R,
                                ColorTable[0].G,
                                ColorTable[0].B) ) 
           {
           
                     
           *lpWorkData=(u16)SDL_MapRGB(screen->format,
                                ColorTable[byData[j + i*lpSprite->PcxHeader.widht]].R,
                                ColorTable[byData[j + i*lpSprite->PcxHeader.widht]].G,
                                ColorTable[byData[j + i*lpSprite->PcxHeader.widht]].B);
           }
           lpWorkData++;
               
        }
        lpWorkData-=width-xClip;
        lpWorkData+=pitch;
           
       }      
             
     }
         
     }
     
        
     SDL_UnlockSurface(work);
}
*/
            
                            
