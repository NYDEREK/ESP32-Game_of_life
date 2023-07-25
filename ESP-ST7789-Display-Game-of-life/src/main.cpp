/*=======Game of life========*/
/* Author: Szymon Nyderek    */
/* uC: ESP-WROOM-32 38pin    */
/* Display: 240x240px ST7789 */
/*===========================*/

//includes
#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "TFT_eSPI.h"
#include "Free_Fonts.h"

//defines
#define Alive    1
#define Dead     0
#define screen_width 240//pixels
#define screen_height 240//pixels
#define width 222//cells
#define height 222//cells

//rules 
#define neighbors_min      2 //minimal neighbors cout to survive 
#define neighbors_max      3 //maximal neighbors cout to survive
#define neighbors_to_spawn 3 //count of neighbors to spawn new pixel
#define Spawn_probability 50 //probability in[%] to spawn in first iterration 
#define neighbors_range    1 //range of neighbors around | | | |
//                                                  N N N N N
//                                                  N N N N N
//                          N N N                   N N C N N      
//  C - cell                N C N                   N N N N N
//  N - neighbor            N N N <- range = 1      N N N N N <- range = 2

//matrixes
uint8_t Cur_Matrix[width + (2*neighbors_range)][height + (2*neighbors_range)];
uint8_t New_Matrix[width + (2*neighbors_range)][height + (2*neighbors_range)];
// width times height times one byte equals size of Matrix

//screen correction
int Ver_scr_cor = ((screen_height - height) / 2);
int Hor_scr_cor = ((screen_width - width) / 2);

// Use hardware SPI
TFT_eSPI tft = TFT_eSPI();

//functions
int Get_neighbors_count(int w, int h, int range);//returns how many neighbors cell has
void display_init(void);//initialize display
void display_intro(void);

void setup() {
 //initialize Display
 display_init();
 display_intro();
 //random number generating (randomness)
 randomSeed(analogRead(0));
 //Generate random matrix
  for (int i = (height + neighbors_range); i >= neighbors_range;i--)
 {
   for (int j = neighbors_range; j <= (width + neighbors_range);j++)
   {
     uint8_t rng = (random(100) + 1);
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
     if ((Cur_Matrix[j][i] == Dead) && (nei_count == neighbors_to_spawn))
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
      tft.drawPixel((j + Ver_scr_cor) , (i + Hor_scr_cor), TFT_WHITE);
    }
    else
    {
      tft.drawPixel((j + Ver_scr_cor) , (i + Hor_scr_cor), TFT_BLACK); 
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
  tft.setRotation(4);
  tft.fillScreen(TFT_BLACK); 
}
void display_intro(void)// intro to tests
{
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(80, 100, 4);
  //tft.setFreeFont(FF7);   
  tft.setTextColor(TFT_WHITE);
  tft.print("ESP");tft.setTextColor(TFT_RED);tft.print("<3 \n");
  tft.setCursor(50, 130);
  //tft.setFreeFont(FF5); 
  tft.setTextColor(TFT_GREENYELLOW);
  tft.println("     Starting ...");
  delay(3500);
  tft.fillScreen(TFT_BLACK);
}
