# ESP-WROOM-32-38pin ST7789 240x240px Display

✨"Game of life" with changable rules for experiments and fun ✨

🐱‍💻Work in Progres🐱‍💻

# 🧨Modifiable rules🧨

🎈Neighbors_min       2   -minimal neighbors cout to survive

🎈Neighbors_max       3   -maximal neighbors cout to survive

🎈Neighbors_to_spawn  3   -count of neighbors to spawn new cell

🎈Spawn_probability  14   -probability in[%] to spawn in first
                         iterration when cells are generated
                        
🎈Neighbors_range     1   -range of neighbors around 

                                                 N N N N N                                                 
                                                 N N N N N                                                 
                         N N N                   N N C N N                         
      C - cell           N C N                   N N N N N
      N - neighbor       N N N <- range = 1      N N N N N <- range = 2

# 🎁Randomly generated map🎁

![image](https://github.com/NYDEREK/ESP32-Game_of_life/assets/112076828/1c99afab-2b0f-48df-bd3a-a9858ddc9e62)

🎓After restart new map is randomly generated ,cells are spawning Alive or Dead with probability of "Spawn_probability"
which is equal to 14 for default settings.

 

# 🎉Project use :

Adafruit GFX library for fonts -https://github.com/adafruit/Adafruit-GFX-Library

Bodmer's TFT_espi library for ST7789 display -https://github.com/Bodmer/TFT_eSPI
