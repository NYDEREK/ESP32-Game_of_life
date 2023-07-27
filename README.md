# ESP-WROOM-32-38pin ST7789 240x240px Display

✨"Game of life" with changable rules for experiments and fun ✨

✨Easy rules modifying ✨

✨Portable for many TFT displays such as ILI9341 ✨

✨Randomly generated maps so you are only changing rules ✨
# Try other games and create your own
💎Game of life : B3/S2-3

💎Coral: B3/S45678

💎Larger than life: R5/B34-45/S33-57

# Example settings for "Larger than life"

 neighbors_min     33 - minimal neighbors cout to survive 
 
 neighbors_max     57 - maximal neighbors cout to survive
 
 neighbors_to_spawn_min 34 - count of neighbors to spawn new pixel
 
 neighbors_to_spawn_max 45 - count of neighbors to spawn new pixel
 
 Spawn_probability 40 - probability in[%] to spawn in first iterration 
 
 neighbors_range   5 - range of neighbors around | | | |
 
                                                    N N N N N
                                                    N N N N N
                            N N N                   N N C N N      
    C - cell                N C N                   N N N N N
    N - neighbor            N N N <- range = 1      N N N N N <- range = 2

# Game of life
![image](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/a96cffdd-64bf-43c7-a367-8afd74261e41)

# Larger than life
![image](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/25b4fb0e-5f50-47d5-b6a9-237a51bfce43)

# Coral
![image](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/748415bb-0f56-4d24-927c-28c4554beb8b)

# 🎉Project use :

Adafruit GFX library for fonts -https://github.com/adafruit/Adafruit-GFX-Library

Bodmer's TFT_espi library for ST7789 display -https://github.com/Bodmer/TFT_eSPI
