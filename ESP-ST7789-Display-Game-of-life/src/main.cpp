/*=======Game of life========*/
/* Author: Szymon Nyderek    */
/* uC: ESP-WROOM-32 38pin    */
/* Display: 240x240px ST7789 */
/*===========================*/

//includes
#include <Arduino.h>
#include "TFT_eSPI.h"
#include "Adafruit_GFX.h"
#include "Free_Fonts.h"

//defines
#define Alive    1
#define Dead     0
#define screen_width 240//pixels
#define screen_height 240//pixels
#define width 214//222//cells
#define height 214//222//cells

//rules 
#define neighbors_min    33 //minimal neighbors cout to survive 
#define neighbors_max     57 //maximal neighbors cout to survive
#define neighbors_to_spawn_min 34 //count of neighbors to spawn new pixel
#define neighbors_to_spawn_max 45 //count of neighbors to spawn new pixel
#define Spawn_probability 40 //probability in[%] to spawn in first iterration 
#define neighbors_range   5 //range of neighbors around | | | |
//                                                  N N N N N
//                                                  N N N N N
//                          N N N                   N N C N N      
//  C - cell                N C N                   N N N N N
//  N - neighbor            N N N <- range = 1      N N N N N <- range = 2

//matrixes
uint8_t Cur_Matrix[width + (2*neighbors_range)][height + (2*neighbors_range)];
uint8_t New_Matrix[width + (2*neighbors_range)][height + (2*neighbors_range)];

// screen correction
int Ver_scr_cor = ((screen_height - height) / 2);
int Hor_scr_cor = ((screen_width - width) / 2);

// Use hardware SPI
TFT_eSPI tft = TFT_eSPI();

//functions
int Get_neighbors_count(int w, int h, int range);//returns how many neighbors cell has


//porting functions
void display_init(void);//initialize your display
void display_intro(void);//your intro 
void display_pixel_Alive(int w, int h);// your functions for displaying 
void display_pixel_Dead(int w, int h);// alive and dead pixels
int get_rand_numb(int max); //your function for RNG

void setup() {
 //initialize Display
 display_init();
 display_intro();
 //random number generating (randomness)
 randomSeed(analogRead(13));
 //Generate random matrix
  for (int i = (height + neighbors_range); i >= neighbors_range;i--)
 {
   for (int j = neighbors_range; j <= (width + neighbors_range);j++)
   {
     uint8_t rng = (get_rand_numb(100) + 1);
     if(rng <= Spawn_probability)
     {
       Cur_Matrix[j][i] = Alive;
     }
     else
     {
       Cur_Matrix[j][i] = Dead;
     }
   }
 }
}

void loop() {
 
 // check all cells
 for (int i = (height + neighbors_range); i >= neighbors_range;i--)
 {
   for (int j = neighbors_range; j <= (width + neighbors_range);j++)
   {
    //get neighbors count
     int nei_count = Get_neighbors_count(j, i, neighbors_range);// better generate it one time insted of 3 times in every "if"
     //check game rules and modify new matrix
     if ((Cur_Matrix[j][i] == Dead) &&  (nei_count >= neighbors_to_spawn_min) && (nei_count <= neighbors_to_spawn_max))
     {
       New_Matrix[j][i] = Alive; // if cell is death and has enough neighbors then this cell is getting alive
     } 
     if((Cur_Matrix[j][i] == Alive) && (nei_count > neighbors_max))
     {
      New_Matrix[j][i] = Dead; //if cell has to mant neighbors then this cell dies
     }
     if((Cur_Matrix[j][i] == Alive) && (nei_count < neighbors_min))
     {
       New_Matrix[j][i] = Dead; //if cell has not enough neighbors then this cell dies
     }
   }
 }
 //ReWrite New_Matrix to Cur_Matrix
 for (int i = ((height + (2 * neighbors_range)) - 1); i >= 0;i--)
 {
   for (int j = 0; j <= ((width + (2 * neighbors_range))-1);j++)
   {
     Cur_Matrix[j][i] = New_Matrix[j][i];
   }
 }

 // Display Cur_Matrix on screen
 for (int i = (height + neighbors_range); i >= neighbors_range; i--)
 {  
   for (int j = neighbors_range; j <= (width + neighbors_range);j++)
   {
    if(Cur_Matrix[j][i] ==Alive)
    {
      //tft.drawPixel((j + Ver_scr_cor) , (i + Hor_scr_cor), TFT_WHITE);
       display_pixel_Alive((j + Ver_scr_cor), (i + Hor_scr_cor));
    }
    else
    {
      //tft.drawPixel((j + Ver_scr_cor) , (i + Hor_scr_cor), TFT_BLACK); 
      display_pixel_Dead((j + Ver_scr_cor), (i + Hor_scr_cor));
    }
   }
 }
}

int Get_neighbors_count(int w, int h, int range)
{
 int neighbors_count = 0;
 for (int i = (h + range); i >= (h - range); i--) // go down
 {
   for (int j = (w - range); j <= (w + range); j++) //go right
   {
     if (Cur_Matrix[j][i] == Alive)
     {
       neighbors_count++;
     }
   }
  }
  if(Cur_Matrix[w][h] == Alive)
  {
   neighbors_count--;
  }
  return neighbors_count;
}
void display_init(void)//initializing Display
{
  tft.init();
  tft.setRotation(4); //Screen rotation 
  tft.fillScreen(TFT_BLACK); //Bg color 
}
void display_intro(void)// intro to tests
{
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(75, 100, 4);
  tft.setFreeFont(FF7);   
  tft.setTextColor(TFT_WHITE);
  tft.print("ESP");tft.setTextColor(TFT_RED);tft.print("<3 \n");
  tft.setCursor(60, 130);
  tft.setFreeFont(FF5); 
  tft.setTextColor(TFT_GREENYELLOW);
  tft.println("Starting ...");
  delay(3500);
  tft.fillScreen(TFT_BLACK);
}
void display_pixel_Alive(int w, int h)
{
  tft.drawPixel(w, h,TFT_WHITE);
}

void display_pixel_Dead(int w, int h)
{
  tft.drawPixel(w, h,TFT_BLACK);
}

int get_rand_numb(int max)
{
  int rand_num;
  rand_num = random(max);
  return rand_num;
}

