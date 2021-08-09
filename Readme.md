# Chord Generator
_Under construction_
## Description
Randomly generates a musical chord with basis in music theory, that is to say, the notes composing the cord are _not entirely_ random. For now, this program only supports triads, but extended chords are planned to be supported in the near future.

## Compilation Notes
This project has been tested to compile using the following compiler:
- gcc 8.1.0 (MinGW-W64)

## TODO
1. ~~implement the random chord feature; right now, it prints _all_ the supported chord qualities of a given root note. It must be only one chord, and it should be determined randomly.~~
2. include support for other chord qualities
    1. extended chords
        1. sevenths
        2. ninths
        3. elevenths
        4. thirteenths
    2. "special" chords like 6/9
3. randomly generates a number of chords; number to be determined by user
3. make the whole thing modular such that other programs can use this one