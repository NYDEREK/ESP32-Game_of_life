# ESP-WROOM-32-38pin ST7789 240x240px Display

✨"Game of life" with changable rules for experiments and fun ✨

🐱‍💻Work in Progres🐱‍💻

# 🧨Modifiable rules🧨

🎈Neighbors_min       2   -minimal neighbors cout to survive

🎈Neighbors_max       3   -maximal neighbors cout to survive

🎈Neighbors_to_spawn  3   -count of neighbors to spawn new cell

🎈Spawn_probability  50   -probability in[%] to spawn in first
                         iterration when cells are generated
                        
🎈Neighbors_range     1   -range of neighbors around 

                                                 N N N N N                                                 
                                                 N N N N N                                                 
                         N N N                   N N C N N                         
      C - cell           N C N                   N N N N N
      N - neighbor       N N N <- range = 1      N N N N N <- range = 2
 

# 🎉Project use :

Adafruit GFX library for fonts -https://github.com/adafruit/Adafruit-GFX-Library

Bodmer's TFT_espi library for ST7789 display -https://github.com/Bodmer/TFT_eSPI
