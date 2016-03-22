//#include <iostream>
//#include <SDL.h>
//#include <math.h>
//#include <stdio.h>
//#include <string.h>

//bool leftMouseButtonDown = false;
//bool quit = false;
//SDL_Event event;


//SDL_Window * window;
//int drawingWindowId;
//int ToolsWindowId;

//SDL_Renderer * renderer;
////SDL_Renderer * renderer2;
//SDL_Texture * texture;

//Uint32 * pixels = new Uint32[640 * 480];
////void * pixels2;

//Uint32 * backbufferPixels=NULL;
//int sizeofbackbufferPixels;

//Uint8 tmpColor;


////ToolBox Booleans
//typedef enum {FALSE,TRUE} boolean;
//boolean drawRectangle =FALSE;
//boolean drawPointLine =FALSE;
//boolean drawPointCircle =FALSE;
//boolean drawPointPencil =FALSE;
//boolean drawPointBrush =FALSE;
//boolean drawPointBucketFill =FALSE;
//boolean drawPointRedColor =FALSE;
//boolean drawPointBlackColor =FALSE;
//boolean drawPointEraser =FALSE;

//boolean NOWDRAWING =FALSE;

//boolean executedOnce =FALSE;

//SDL_Color colorpicked;

/////////////////////////////////////////////////////////////////////
///// \brief loadedSurface
//const char * path="toolbox.png";
//SDL_Surface* loadedSurface;
//SDL_Surface * surf;

//SDL_Surface* formattedSurface;
//SDL_Surface* formattedSurface;

//SDL_Texture * texture2;


//typedef struct Point
//{
//    Point(){;}
//    Point(int _x,int _y){x=_x;y=_y;}
//    ~Point(){}
//    Point(const Point &_p){x=_p.x;y=_p.y;}
//    void operator=(const Point &_p){x=_p.x;y=_p.y;}

//    int x,y;
//}p;


//Point lineStart;
//Point lineEnd;

//void drawBresenhamLine(int x,int y,int x2,int y2)
//{
//     if (x<0) {x=0;};
//     if (x>640) {x=639;}
//     if (y<0) {y=0;}
//     if (y>480) {y=479;}

//     if (x2<0) {x2=0;};
//     if (x2>640) {x2=639;}
//     if (y2<0) {y2=0;}
//     if (y2>480) {y2=479;}

//      Point * lineArray=NULL;
//      lineArray=(Point*)malloc(1*sizeof(Point));


//      //http://tech-algorithm.com/articles/drawing-line-using-bresenham-algorithm/
//      int w = x2 - x ;
//      int h = y2 - y ;
//      int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0 ;
//      if (w<0) dx1 = -1 ; else if (w>0) dx1 = 1 ;
//      if (h<0) dy1 = -1 ; else if (h>0) dy1 = 1 ;
//      if (w<0) dx2 = -1 ; else if (w>0) dx2 = 1 ;

//      int longest = abs(w) ;
//      int shortest = abs(h) ;

//      if (!(longest>shortest))
//      {
//          longest = abs(h) ;
//          shortest = abs(w) ;
//          if (h<0) dy2 = -1 ;
//          else if (h>0) dy2 = 1 ;
//          dx2 = 0 ;
//      }
//      int numerator = longest >> 1 ;
//      for (int i=0;i<=longest;i++)
//      {
//          SDL_RenderDrawPoint(renderer,x,y);

//          lineArray=(Point*)realloc(lineArray,(i+1)*sizeof(Point));
//          lineArray[i]=Point(x,y);


//    //          std::cout<<"lineArray="<<lineArray[i].x<<","<<lineArray[i].y<<std::endl;

//          numerator += shortest ;
//          if (!(numerator<longest))
//          {
//              numerator -= longest ;
//              x += dx1 ;
//              y += dy1 ;
//          } else {
//              x += dx2 ;
//              y += dy2 ;
//          }
//      }

//    //clear our buffer constantly so as to end up with only 1 line

//    //Now create the backbuffercopy of the original pixel array (our board)
//    memcpy(backbufferPixels, pixels,  640 * 480 * sizeof(Uint32));

//    for(int i=0;i<=longest;i++)
//    {

//        Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, colorpicked.r,colorpicked.g,colorpicked.b);
//        backbufferPixels[lineArray[i].y * 640 + lineArray[i].x]=tmpPixel;
//    }

//    free(lineArray);
//}


//int main(int argc, char ** argv)
//{

//    SDL_Init(SDL_INIT_VIDEO);

//    SDL_Window * window = SDL_CreateWindow("SDL2 Turtle Graphics / Spirolateral Drawing",
//        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

//    renderer = SDL_CreateRenderer(window, -1, 0);
//    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 480);

//    surf = SDL_CreateRGBSurface(0,640,480,32,0,0,0,0);
//    formattedSurface = SDL_ConvertSurfaceFormat( surf, SDL_PIXELFORMAT_ARGB8888, NULL );
//    if( formattedSurface == NULL )
//    {
//        printf( "Unable to convert loaded surface to display format! SDL Error: %s\n", SDL_GetError() );
//    }
//    else
//    {
//            int pitch;
//            void *pxs=(void*)pixels;
//            //Lock texture for manipulation
//            SDL_LockTexture( texture, NULL, &pxs, &pitch );

//            //Copy loaded/formatted surface pixels
//            memcpy( pixels, formattedSurface->pixels, 640 *480 );

//            //Unlock texture to update
//            SDL_UnlockTexture( texture );

//    }
//    //Get rid of old loaded surface
//    SDL_FreeSurface( surf );


//    memset(pixels, 255, 640 * 480 * sizeof(Uint32));


//    while (!quit)
//    {
//        SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));
//        SDL_PollEvent(&event);

//        SDL_Rect DestR;
//        DestR.x = 100;
//        DestR.y = 100;
//        DestR.w = 100;
//        DestR.h = 100;

//        switch (event.type)
//        {
//        case SDL_KEYDOWN:

//            if (event.key.keysym.sym==SDLK_SPACE)
//            {
//                memset(pixels,255,640*480*sizeof(Uint32));
//                executedOnce=FALSE;
//            }
//            break;


//        case SDL_MOUSEBUTTONUP:
//            if (event.button.button == SDL_BUTTON_LEFT)
//            {
//                leftMouseButtonDown = false;

//                //Decision made- Now mouse is up, so copy to original 'pixel' data the buffered data.
//                std::cout<<"drawPointLine="<<drawPointLine<<std::endl;

//                 if (drawPointLine && backbufferPixels!=NULL)
//                {
//                    memcpy(pixels,backbufferPixels,640*480*sizeof(Uint32));

//                    delete backbufferPixels;
//                    backbufferPixels=NULL;
//                    drawPointLine=FALSE;


//                }

//                if (drawPointCircle && backbufferPixels!=NULL)
//                {
//                    memcpy(pixels,backbufferPixels,640*480*sizeof(Uint32));

//                    delete backbufferPixels;
//                    backbufferPixels=NULL;
//                }

//                NOWDRAWING=FALSE;

//            }
//            break;
//        case SDL_MOUSEBUTTONDOWN:
//            {
//                if (event.button.button == SDL_BUTTON_LEFT)
//                {
//                    leftMouseButtonDown = true;
//                    drawPointLine=TRUE;
//                }

//            }
//            break;

//        case SDL_MOUSEMOTION:
//            if (leftMouseButtonDown)
//            {



//            }
//            break;
//        case SDL_QUIT:
//            quit = true;
//            break;
//        }


//int mouseX = event.motion.x;
//int mouseY = event.motion.y;

//if (drawPointLine==TRUE && !executedOnce)
//{
//        //avoid multiple executions
//        executedOnce=TRUE;

//        //Line Drawing
//        //Make sure we draw the texture and THEN..we draw on the top of it for the backbuffer lines,points (for circle,rectangle)
//        SDL_RenderCopy(renderer, texture, NULL, NULL);

//        Point currentmousePos(mouseX,mouseY);
//        //start line point initialized just once
//        if (!NOWDRAWING)
//        {
//            NOWDRAWING=TRUE;
//            lineStart=currentmousePos;
//        }

//        std::cout<<"lineStart="<<lineStart.x<<","<<lineStart.y<<std::endl;

//        //end line point
//        lineEnd=currentmousePos;

//        //Allocate some memory for the backbufferPixels
//        if (backbufferPixels==NULL)
//        {
//            backbufferPixels=(Uint32*)malloc(640*480* sizeof(Uint32));
//        }
//        else
//        {
//            memset(backbufferPixels,0,640*480* sizeof(Uint32));
//        }

//        //Now create the backbuffercopy of the original pixel array (our main drawing board)
//        memcpy(backbufferPixels, pixels,  640 * 480 * sizeof(Uint32));

//        //Draw Simple Spirolateral (angle 90. initial segment 1, order 2, repetitions/recursion 2)

//        int initialangle=0;
//        int initialSegment=20;
//        int order=6;
//        int repetitionRecursion=2;

//        printf ("Enter angle (ex. 60):  ");
//        scanf("%d",&initialangle);

//        printf ("Enter initialSegment length (ex. 5): ");
//        scanf("%d",&initialSegment);

//        printf ("Enter fractal order (ex. 7): ");
//        scanf("%d",&order);

//        printf ("Enter repetitionRecursion (ex. 80): ");
//        scanf("%d",&repetitionRecursion);


//        Point end=lineStart;

//        int segment=0;
//        int angle=initialangle;
//        for (int i=0; i<repetitionRecursion;i++)
//        {
//            segment=initialSegment;
////            angle=initialangle;

//            //draw lines sequentially based on the order of the spirolateral (in. example 2= times= 2 segments need to be drawn for the spirolateral to be completed)
//            for (int j=0; j<order;j++)
//            {
//                SDL_RenderPresent(renderer);

//                end.x=lineStart.x+segment*sin(angle*M_PI/180.0f);
//                end.y=lineStart.y+segment*cos(angle*M_PI/180.0f);

//                drawBresenhamLine(lineStart.x,lineStart.y, end.x,end.y);
//                memcpy(pixels,backbufferPixels,640*480*sizeof(Uint32));

//                lineStart=end;
//                segment+=initialSegment;
//                angle-=initialangle;
//                angle=fmod(angle,360.0);

//                printf ("Draw with angle %d\n:", angle);

//            }
//            SDL_RenderPresent(renderer);
//        }

//        drawPointLine=FALSE;
//}





//        // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
//        if(!leftMouseButtonDown)
//        {
//            SDL_RenderCopy(renderer, texture, NULL, NULL);
//        }

//        //update the rendered image
//        SDL_RenderPresent(renderer);

//    }

//    SDL_FreeSurface( formattedSurface );

//    delete[] pixels;
//    SDL_DestroyTexture(texture);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();

//    return 0;
//}




#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>

bool quit = false;
SDL_Event event;

SDL_Window * window;
SDL_Renderer * renderer;
SDL_Surface * image;
SDL_Surface * formattedSurface;
SDL_Texture * texture;

Uint32 * pixels;
Uint32 * backbufferpixels;
Uint32 * originalImagepixels;


void sharpen()
{
    //Filter matrix 3x3
    float sharpMat[3][3]={{-1,-2,-1},{-2,19,-2},{-1,-2,-1}};
    for (int jj=0; jj <3 ; ++jj)
        for (int ii=0; ii <3 ; ++ii)
            sharpMat[jj][ii]*=(float)1/7;


    if(pixels ==NULL)
    {
        pixels = (Uint32 *) formattedSurface->pixels;
    }

    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            //leave out the edges of the image
            if(y!=0 && y!=formattedSurface->h-1 && x!=0 && x!=formattedSurface->w-1)
            {
                float sumR=0;
                float sumG=0;
                float sumB=0;

                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        int tmpIndex = (y+i) * formattedSurface->w + x+j;

                        Uint8  red=0;
                        Uint8  green=0;
                        Uint8  blue=0;

                        //multiply with 9
                        if(i==0 && j==0)
                        {
                            SDL_GetRGB(pixels[tmpIndex], formattedSurface->format, &red, &green, &blue);
                            float r=(float)red*sharpMat[i+1][j+1];
                            float g=(float)green*sharpMat[i+1][j+1];
                            float b=(float)blue*sharpMat[i+1][j+1];

                            sumR+=r;
                            sumG+=g;
                            sumB+=b;
                        }
                        else if (abs(i)==abs(j) && i!=0) //but not the central element
                        {
                            SDL_GetRGB(pixels[tmpIndex], formattedSurface->format, &red, &green, &blue);
                            float r=(float)red*sharpMat[i+1][j+1];
                            float g=(float)green*sharpMat[i+1][j+1];
                            float b=(float)blue*sharpMat[i+1][j+1];

                            sumR+=r;
                            sumG+=g;
                            sumB+=b;
                        }
                        else
                        {
                            SDL_GetRGB(pixels[tmpIndex], formattedSurface->format, &red, &green, &blue);
                            float r=(float)red*sharpMat[i+1][j+1];
                            float g=(float)green*sharpMat[i+1][j+1];
                            float b=(float)blue*sharpMat[i+1][j+1];

                            sumR+=r;
                            sumG+=g;
                            sumB+=b;
                        }

                    }
                }

                if(sumR <0) sumR=0;  if(sumR >255) sumR=255;
                if(sumG <0) sumG=0;  if(sumG >255) sumG=255;
                if(sumB <0) sumB=0;  if(sumB >255) sumB=255;

                SDL_Color c;
                c.r=sumR;
                c.g=sumG;
                c.b=sumB;
                Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, c.r, c.g, c.b);
                pixels[ y * formattedSurface->w + x] = tmpPixel;

            }
        }
    }

}


void blur()
{
    //Filter matrix 3x3
    float blurMat[3][3]={{1.0/9,1.0/9,1.0/9},{1.0/9,1.0/9,1.0/9},{1.0/9,1.0/9,1.0/9}};

    if(pixels ==NULL)
    {
        pixels = (Uint32 *) formattedSurface->pixels;
    }

    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            int sumR=0;int sumG=0;int sumB=0;

            //leave out the edges of the image
            if(y!=0 && y!=formattedSurface->h-1 && x!=0 && x!=formattedSurface->w-1)
            {
                float sumR=0;
                float sumG=0;
                float sumB=0;

                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        int tmpIndex = (y+i) * formattedSurface->w + x+j;

                        Uint8  red=0;
                        Uint8  green=0;
                        Uint8  blue=0;

                        SDL_GetRGB(pixels[tmpIndex], formattedSurface->format, &red, &green, &blue);
                        float r=(float)red*blurMat[i+1][j+1];
                        float g=(float)green*blurMat[i+1][j+1];
                        float b=(float)blue*blurMat[i+1][j+1];

                        sumR+=r;
                        sumG+=g;
                        sumB+=b;
                    }
                }

                if(sumR <0) sumR=0;  if(sumR >255) sumR=255;
                if(sumG <0) sumG=0;  if(sumG >255) sumG=255;
                if(sumB <0) sumB=0;  if(sumB >255) sumB=255;

                SDL_Color c;
                c.r=sumR;
                c.g=sumG;
                c.b=sumB;
                Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, c.r, c.g, c.b);
                pixels[ y * formattedSurface->w + x] = tmpPixel;

            }
        }
    }
}


static float brightness=0;
void brighten(Uint32 **pixels, int brightness)
{
    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            int tmpIndex = y * formattedSurface->w + x;

            Uint8  red=0;
            Uint8  green=0;
            Uint8  blue=0;

            SDL_GetRGB((*pixels)[tmpIndex], formattedSurface->format, &red, &green, &blue);
            float r=(float)red+brightness;
            float g=(float)green+brightness;
            float b=(float)blue+brightness;

            if(r <0) r=0;  if(r >255) r=255;
            if(g <0) g=0;  if(g >255) g=255;
            if(b <0) b=0;  if(b >255) b=255;


            SDL_Color c;
            c.r=r;
            c.g=g;
            c.b=b;
            Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, c.r, c.g, c.b);
            (*pixels)[ y * formattedSurface->w + x] = tmpPixel;

        }
    }
}


int clamp(int n)
{
    if ((unsigned) n <= 255) {
        return n;
    }
    return (n < 0) ? 0 : 255;
}
static float contrastFactor=0;
void contrast(Uint32 **pixels, float contrastFactor)
{
    int maxPixelintensity=0;
    int minPixelintensity=255;
    for (int y = 0; y < formattedSurface->h; y++)
    {
        for (int x = 0; x < formattedSurface->w; x++)
        {
            int tmpIndex = y * formattedSurface->w + x;

            Uint8  red=0;
            Uint8  green=0;
            Uint8  blue=0;

            float factor = (259 * (contrastFactor + 255)) / (255 * (259 - contrastFactor));

            SDL_GetRGB((*pixels)[tmpIndex], formattedSurface->format, &red, &green, &blue);
            float r=(float)red;
            float g=(float)green;
            float b=(float)blue;

            float newRed   = clamp((factor * (r)   - 128) + 128);
            float newGreen = clamp((factor * (g)   - 128) + 128);
            float newBlue  = clamp((factor * (b)   - 128) + 128);

            SDL_Color c;
            c.r=newRed;
            c.g=newGreen;
            c.b=newBlue;
            Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, c.r, c.g, c.b);
            (*pixels)[ y * formattedSurface->w + x] = tmpPixel;

//            int currentpixelIntensity=(r+g+b) /3;
//            if(currentpixelIntensity > maxPixelintensity)
//                maxPixelintensity=currentpixelIntensity;

//            if(currentpixelIntensity < minPixelintensity)
//                minPixelintensity=currentpixelIntensity;
        }
    }



}


int main(int argc, char ** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);

    window = SDL_CreateWindow("SDL2 Grayscale",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    image = IMG_Load("Chrome_icon.png");
    formattedSurface = SDL_ConvertSurfaceFormat( image, SDL_PIXELFORMAT_ARGB8888, NULL );
    texture = SDL_CreateTextureFromSurface(renderer, formattedSurface);


    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:


            if(pixels ==NULL)
            {
                //create an array of pixels to manipulate, a backbuffer array of pixels to updat the pixels array from , and a saved orinal state of the pixels array
                pixels = (Uint32 *) formattedSurface->pixels;

                //save the original image as an array of pixels before any sort of image processing
                if(originalImagepixels ==NULL)
                {
                    originalImagepixels = new Uint32[640*480];
                    memcpy(originalImagepixels, pixels, 640*480 * sizeof(Uint32));
                }


                if(backbufferpixels ==NULL)
                {
                    backbufferpixels = new Uint32[640*480];
                }

            }

            if(event.key.keysym.sym==SDLK_s)
            {
                //allow the user sharpen frames by parameters given on the command-line
                sharpen();


//SET ALL PIXELS TO RED
//                for (int y = 0; y < formattedSurface->h; y++)
//                {
//                    for (int x = 0; x < formattedSurface->w; x++)
//                    {
//                        Uint32 pixel = pixels[y * formattedSurface->w + x];

////                        SDL_GetRGB(pixel, formattedSurface->format, &red, &green, &blue);
////                        //std::cout<<"red="<<(int)red<<std::endl;

//                        SDL_Color c;
//                        c.r=255;
//                        c.g=0;
//                        c.b=0;
//                        //create a
//                        Uint32 tmpPixel=SDL_MapRGB(formattedSurface->format, c.r,c.g,c.b);
//                        pixel = tmpPixel;

////                        pixel = (0xFF << 24) | (red << 16) | (green << 8) | blue;
//                        pixels[y * formattedSurface->w + x] = pixel;



//                    }
//                }
                break;
            }


            if(event.key.keysym.sym==SDLK_b)
            {
                //allow the user blur frames by parameters given on the command-line
                blur();
                break;
            }

            if(event.key.keysym.sym==SDLK_r)
            {
                //allow users to change the brightness
                brighten(&pixels,1);
                break;
            }
            if(event.key.keysym.sym==SDLK_d)
            {
                //allow users to change the brightness
                brighten(&pixels,-1);
                break;
            }

            if(event.key.keysym.sym==SDLK_c)
            {
                //allow users to change the brightness
                contrast(&pixels,contrastFactor++);
                break;
            }
            if(event.key.keysym.sym==SDLK_u)
            {
                //allow users to change the brightness
                contrast(&pixels,contrastFactor--);
                break;
            }

//            if(event.key.keysym.sym==SDLK_g)
//            {
//                //allow users to change the brightness
//                brighten(brightness);
//                break;
//            }

            if(event.key.keysym.sym==SDLK_1)
            {
                memcpy(pixels, originalImagepixels, 640*480*sizeof(Uint32));
                break;
            }


        case SDL_KEYUP:
            if(event.key.keysym.sym==SDLK_r)
            {
                break;
            }
            if(event.key.keysym.sym==SDLK_d)
            {
                break;
            }
        }

        SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));

        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(formattedSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    delete pixels;
    delete backbufferpixels;
    delete originalImagepixels;
    IMG_Quit();
    SDL_Quit();

    return 0;
}