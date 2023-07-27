# 🎮 ESP-WROOM-32-38pin ST7789 240x240px Display
![Game_of_life (5)](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/01dcbdf5-1627-4057-ab07-b6bdd3cedd3e)




  <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/NYDEREK/ESP32-Game_of_life"> <img alt="Static Badge" src="https://img.shields.io/badge/uC-ESP32-red"> <img alt="Static Badge" src="https://img.shields.io/badge/Framework-Arduino-blue"> <img alt="Static Badge" src="https://img.shields.io/badge/VSCode-PlatformIO-orange"> <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/NYDEREK/ESP32-Game_of_life"> <img alt="GitHub commit activity (branch)" src="https://img.shields.io/github/commit-activity/t/NYDEREK/ESP32-Game_of_life">












## Features
* Easy rules modifying 

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


## Project use :
* Adafruit GFX library for fonts -https://github.com/adafruit/Adafruit-GFX-Library
* Bodmer's TFT_espi library for ST7789 display -https://github.com/Bodmer/TFT_eSPI
