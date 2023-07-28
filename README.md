# 🎮 ESP-WROOM-32-38pin ST7789 240x240px Display
![Game_of_life (5)](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/01dcbdf5-1627-4057-ab07-b6bdd3cedd3e)




  <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/NYDEREK/ESP32-Game_of_life"> <img alt="Static Badge" src="https://img.shields.io/badge/uC-ESP32-red"> <img alt="Static Badge" src="https://img.shields.io/badge/Framework-Arduino-blue"> <img alt="Static Badge" src="https://img.shields.io/badge/VSCode-PlatformIO-orange"> <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/NYDEREK/ESP32-Game_of_life"> <img alt="GitHub commit activity (branch)" src="https://img.shields.io/github/commit-activity/t/NYDEREK/ESP32-Game_of_life">












## Features
* Easy rule modification

* Portable for many TFT displays such as ILI9341 

* Randomly generated maps so you are only changing rules

## Video
[![Watch the video](https://img.youtube.com/vi/prvvMwUMuO0/hqdefault.jpg)](https://www.youtube.com/watch?v=prvvMwUMuO0)

## Try other games and create your own
* Game of life : R1/B3/S2-3

* Coral: R1/B3/S45678

* Larger than life: R5/B34-45/S33-57

## Example settings for "Larger than life"

```bash
* neighbors_min     33 - minimal neighbors cout to survive 
* neighbors_max     57 - maximal neighbors cout to survive
* neighbors_to_spawn_min 34 - count of neighbors to spawn new pixel
* neighbors_to_spawn_max 45 - count of neighbors to spawn new pixel
* Spawn_probability 40 - probability in[%] to spawn in first iterration 
* neighbors_range   5 - range of neighbors around

N - neighbor                         N N N N N
C - cell                             N N N N N
             N N N                   N N C N N
             N C N                   N N N N N
             N N N <- range = 1      N N N N N <- range = 2
```
# Porting 
If you want to display "Game of life" on other display or use diffrent uC you have to change those functions for yours
![carbon](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/a8f0bf38-88a0-4ec4-b8bf-d838ab717cb4)

And change those defines to fit your hardware

![carbon (6)](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/2d8a2de1-e738-4a32-8390-82a3362381a2)

examples below--->
### Display init
![carbon (1)](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/6f7c78db-f85b-4eb5-8fa5-2fd0d0df21b8)
### Intro 
![carbon (2)](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/42e3cc2b-bdec-417e-9615-7c051572fb89)
### Display pixel
Here put your display function to draw a pixel .In display_pixel_Dead color should be color of your background
![carbon (3)](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/13cc97bb-c013-408d-9f5f-130cd1c9816d)

### Random Number Generation
For creating random map you need to define your uC RNG function .Function have to return random number form 0 to 99

![carbon (5)](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/a86557e1-99a4-469f-8390-4b19d6080d95)

## Project use :
* Adafruit GFX library for fonts -https://github.com/adafruit/Adafruit-GFX-Library
* Bodmer's TFT_espi library for ST7789 display -https://github.com/Bodmer/TFT_eSPI
