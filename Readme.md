# Chord Generator
_Under construction_
## Description
Randomly generates a musical chord with basis in music theory, that is to say, the notes composing the cord are _not entirely_ random. For now, this program only supports triads, but extended chords are planned to be supported in the near future.

## Compilation Notes
This project has been tested to compile using the following compiler:
- gcc 8.1.0 (MinGW-W64)

## Other Notes
The codebase is a mess right now and any seasoned programmer may fall ill upon laying eyes on the code (trust me, I was itching to refactor this as I read what I wrote but elected not to as that would stop me from coding). I wasn't able to learn the best practices for programming back in college and this is my first time doing a project that is bigger than the exercises given to us back then. I intend to refactor the codebase as I learn along the way. Hopefully, now that the program is capable of doing the bare minimum that it is required to do (i.e. it generates a random major/minor/sus2/sus4 chord), I can now divert focus on refactoring and making things neater and more readable. Please bear with me.

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