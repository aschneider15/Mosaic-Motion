# Mosaic Motion ©️: "The Ultimate Revival Puzzle Game for Nintendo®️ Game Boy™️!"

## Currently in development by Aidan Schneider

### Demo Pictures:

![Title Screen](demo_pics/demo1.bmp)
![Selection Screen (1 of 2)](demo_pics/demo2.bmp)
![Selection Screen (2 of 2)](demo_pics/demo3.bmp)
![Puzzle Solving](demo_pics/demo4.bmp)
![Puzzle Solved](demo_pics/demo5.bmp)

### Thanks for checking out my project!
Feel free to [download the rom and try it yourself](https://github.com/aschneider15/Mosaic-Motion/releases) using the Game Boy emulator of your choice! 

For information about the design process and what features I plan on including by the time this project is finished, please check out [my design document.](/Design%20Document.md)

For anyone wondering, my favorite part to work on so far has been the soundtrack! I'll be uploading oscilloscope views of the whole thing once it's finished on the [Absent Corner YouTube channel](https://youtube.com/@absentcorner), so stay tuned for that!

### Personal Notes:

## Resources

- [Game Boy Pan Docs](https://gbdev.io/pandocs/About.html)
- [GBDK Documentation](https://gbdk-2020.github.io/gbdk-2020/docs)
- [Larold's Jubilant Junkyard](https://laroldsjubilantjunkyard.com/)

## What I'm working toward right now!
Last updated 09/25/2025

## Modularization

- Mostly in regard to the Puzzle Solve scene. I'm hoping to break it up so that I can reuse bits and pieces, such as the GetTiles, SetCurrentPuzzleData and RandomizeTiles functions, as well as the feature that I'm going to mention next. Really, the way I'm going to lay it out ideally is have a series of new source files which contain helper functions to support a Standard-Puzzle, Shift-Puzzle and Twist-Puzzle scene.   

## Time Attack Mode

- Start with a base time, \(which the player may be allowed to select, I haven't decided yet\), and create a seperate UpdateTimer function which counts *down* from the original time rather than counting up.
  - I think my original idea was to have them pick between a few time options, which will probably be easiest to implement in a possible scoreboard feature
- When a time of 00:10:00 is reached, play a sound effect that indicates time is running out
- I also might change the music, similar to how Tetris's music speeds up when you get close to the line at the top of the screen. 
- The goal of Time Attack is to solve as many puzzles as possible in the given time limit, so the engine will have to generate a new puzzle every time the player completes one.
  - I think it would be fun to have little transitions between puzzles, kind of like how battle transitions worked in the Pokemon games back in the day
  - Fade to black, slide to the side, drop to the bottom, scattered replacement, "shrink," etc.