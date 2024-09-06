# Mosaic Motion©️: "The Ultimate Revival Puzzle Game for Nintendo®️ Game Boy™️!"

---

# Table of Contents

- [Introduction](#introduction)
  - [Why Game Boy software?](#why-game-boy-software)
  - [Why a puzzle game?](#why-a-puzzle-game)
  - [What tools were used to make Mosaic Motion?](#what-tools-were-used-to-make-mosaic-motion)
- [Core Features](#core-features)
  - [Game Modes](#game-modes)
    - Standard Mode
    - Twist Mode
    - Shift Mode
    - Flip Mode\*
  - [Game Styles](#game-styles)
    - Time Attack Style
    - Strategist Style
  - [Options Menu](#options-menu)
    - Mode Select
    - Difficulty Select
    - BGM Options
  - [Settings](#settings)
  - Saved Data
- [Extra Features](#extra-features)
  - [Achievement Board](#achievement-board)
  - [Secret BGM Options](#secret-bgm-options)
  - [Profile System](#profile-system)
  - [Game Manual](#game-manual)

---

# Introduction

## Why Game Boy software?

I've been a huge Game Boy fan for as long as I remember. I've been playing Game Boy games since I could read, having received a hand-me-down Teal GBC the summer after I turned six years old (mind you, this was well into the DS era; I'm only 21 as of writing this!) Playing Pokemon Yellow, Pocket Bomberman, Super Mario Land 2, and others on long car trips are some of my most cherished childhood memories. Later in high school, discovering games like Link's Awakening DX, Mole Mania, Pokemon GSC and Metroid II through the 3DS Virtual Console only furthered my interest. By the time I got to college, I was fortunate enough to be able to collect a few of the games I had never played before, like Dragon Quest 1&2 (and 3!), Tetris DX, and Kirby's Pinball Land, in addition to the Super Game Boy peripheral for Super Nintendo.

Pair this with my fixation on computer programming (I've been coding since I was thirteen), and it was inevitable that I would discover the GBDK toochain. I've flirted with the idea of publishing Game Boy software since finding GB Studio when I was a junior in high school, but just never committed the time I needed to finish a polished product. My university's CS department requires its students to spend one semester developing and publishing a piece of software, and I saw it as the perfect chance to test my skills and harken back to a bygone era: the era of begging your parents to buy more AA-batteries; the era where you had to tilt the screen at _just_ the right angle to see anything; the era where blowing into your cartridge fixed it every time;

The era of the Game Boy.

## Why a puzzle game?

Frankly, the main reason's kind of a cop-out: I only have a few months to make this game, and I'm doing everything on my own! All the graphics, coding, sound effects and music are a solo endeavor. I don't think there'd be time to write, test, and publish a platformer or RPG or anything like that in my timeframe, so I'm trying to keep the scope realistic.

Additionally, while the Game Boy has a myriad of notable titles, some of the most famous and well-polished are puzzle games (Tetris, Yoshi's Cookie, Kirby Star Stacker, and even the Game & Watch Gallery games to some extent), and I'm hoping to evoke feelings from those types of games for the people who play Mosaic Motion.

I also wanted to make something that _absolutely_ could not have been made in GB Studio. Not to discredit people who only work with that software (they truly make some amazing things!), but I wanted to approach something with a bit of a higher skill ceiling, and the way that Mosaic Motion handles its core mechanics could only (as far as I know) be written in a lower-level language that has access to the system's hardware resources (mainly for the ability to read to and write from VRAM).

## What tools were used to make Mosaic Motion?

Here's a laundry list of all the development tools I used (still in progress as of 9/6/24):

| Tool               | Creator                    | Purpose                                                                                      |
| ------------------ | -------------------------- | -------------------------------------------------------------------------------------------- |
| Aseprite           | David Capello              | The image editing software I use to create sprite and background art                         |
| CBT-FX             | CoffeeBat                  | The sound driver that handles sound effects                                                  |
| Famitracker 0CC    | JSR & HertzDevil           | The tracker I use to prototype music tracks and sound effects                                |
| FX Hammer          | Aleksi Eeben               | The software that I use to create sound effects                                              |
| GBDK-2020          | The GBDK-2020 Organization | Compilers, linkers, libraries, and other build tools used to turn C code into a Game Boy ROM |
| hUGEtracker        | SuperDisk                  | The tracker I use to write the final music tracks                                            |
| hUGEdriver         | SuperDisk                  | The sound driver that handles music                                                          |
| PNG2ASSET          | Larold's Jubilant Junkyard | Converts PNG images into C arrays which GBDK can handle                                      |
| Visual Studio Code | Microsoft                  | The IDE (or is it a text editor?) I use to write the code                                    |

---

# Core Features

## Game Modes

Mosaic Motion features gameplay centered around the manipulation of mosaic tiles within a square board. The goal is to align the tiles, which upon puzzle initialization are scrambled, into the proper order. The player can select the method of tile manipulation through one of four "modes". Additionally, after selecting a game mode, the player will choose one of two "styles" of gameplay, which serve as win conditions.

### Standard Mode

Standard Mode presents the player with a traditional slide puzzle, where the player must slide tiles into a single "gap space" in order to set the tiles into the correct alignment.

### Twist Mode

Twist Mode demands that the player manipulate a 2x2 box around the board which allows for clockwise or counter-clockwise rotation of the four tiles within that box.

### Shift Mode

Shift mode gives the player two axes which can be manipulated around the board. Tiles which are in-line with the axes can be moved one space in the four cardinal directions, wrapping around when a piece would pass over the edge of the board.

### Flip Mode\*

Similarly to Shift Mode, Flip mode gives the player two axes to control and allows tiles aligned with said axes to be manipulated, however rather than being moved, the tiles are flipped completely in that direction (i.e: ABCD -> DCBA).

\* I don't know if I'm going to implement this feature at all, since I haven't tested if it would be theoretically possible to solve.

## Game Styles

### Time Attack Style

In Time Attack Style, the player is required to solve as many puzzles within a given time period as possible. The player will be able to choose said period, ranging from one minute to fifteen minutes. The number of puzzles completed by the player will be recorded in the scoreboard.

### Strategist Style

In Strategist Style, the player is tasked with completing a single puzzle in both the shortest amount of time and the fewest number of operations. The player will receive a score based on how he or she performs.

## Options Menu

The options menu is the screen where players will be presented with their gameplay choices, namely which mode and style they would like to play, the difficulty of the puzzle, and which background music (if any) they want to listen to.

### Mode Select

Players decide between playing on Standard Mode, Twist Mode, Shift Mode, and Flip Mode (maybe).

### Style Select

Players decide between playing with Strategist Style or Time Attack Style. Time Attack also provides the player with a slider, allowing him or her to choose the length of the time challenge.

### Difficulty Select

Players decide between playing on Easy, Medium, or Hard difficulty:

- Easy difficulty requires the player to solve a 3x3 puzzle (nine total pieces).
- Medium difficulty requires the player to solve a 4x4 puzzle (sixteen total pieces).
- Hard difficulty requires the player to solve a 6x6 puzzle (thirty-six total pieces).

### BGM Options

Players can choose which music track will play in the background during puzzle solving. Additionally, if he or she should so choose, a player can opt to turn the music off.

At present, I'd like to implement three different music tracks, but I may want to add more in the future.

## Saved Game

Mosaic Motion will support battery-backed SRAM persistence, allowing records and the player's names on the scoreboard to remain, even when the Game Boy system is turned off. This might end up being quite challenging, since going into this project, I know next to nothing about bank switching.

---

# Extra Features

If I have some extra time as the project deadline approaches, I'd love to be able to implement these! I have them organized in order of feasibility, subject to change in the future depending on how things go...

## Secret BGM Options

Either through unlocking or a special button combination (or "cheat code"), I would like to include several additional music files available for the player to select during gameplay. Initially, I had the idea of doing covers of 60s songs, but that might get me in some legal trouble, so maybe I'll just stick to original compositions or stuff in the public domain.

## SGB Features

As a Game Boy aficionado myself, I love it when games incorporate special features only available through playing the game using the SNES's Super Game Boy peripheral. As it turns out, GBDK supports a pretty robust variety of SGB features out of the box, including custom-made boarders, and sound effects played through the SNES's onboard SPC700 processor. I think it would be neat to have at least a unique and visually appealing boarder for Mosaic Motion.

## Profile System

Here's some background real quick: the original release of Tetris on the GB in 1989 didn't support battery-backed saves, which meant that whatever score the player achieved was lost as soon as power was cut to the cartridge. However, with the launch of the Game Boy Color, Nintendo published Tetris DX, which not only supported battery-backed saving, but incorporated a profile system; this system allowed up to three players to register their names as persistent profiles, with certain user information such as lifetime lines cleared and "power" saved to the profile, along with whatever placements the player had in the game modes.

If it's possible, I might want to try my hand at working that into the final build. Otherwise, I might end up doing what Nintendo and BulletproofSoft did and make the first build of the game without battery-backed saving, and release a DX version for the GBC later...

## Game Manual

Pretty self-explanatory, if I have the time, I'd love to put together a manual for the game.

---

The software product, Mosaic Motion--including the code and audio-visual elements of which it is composed--and all development tools used to create it are in no way associated with Nintendo. The copyright holder (Absent Corner) has not received a license from Nintendo to publish this piece of software for distribution on Nintendo's patented and trademarked Game Boy System.
