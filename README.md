# corewar
This project was developed as one of the group-projects of Ecole 42 curriculum. Corewar is a virtual “arena” in which programs (“The Champions”) fight against each other. These battle programs are written in an abstract assembly language. 
There is also an assembler which compiles the Champions.
For more information about the game history, please read: https://en.wikipedia.org/wiki/Core_War

## Getting Started
The project was written on OS X El Capitan. 
To install the program you must have gcc compiler and ncurses library installed on your system. 

### Installing
```
Install the program using makefile
```


### Creating champions with ASM
```
./asm ./examples_assembler/<sourcefile.s>
will create .cor source files to be launched by ./corewar executable
-a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output
```

### Launching corewar
```
/corewar     [-dump nbr_cycles] [-n number] [-v] [-a] <champion1.cor> <...>
    -a               : Prints output from "aff" (Default is to hide it)
    -n number        : Sets the number of the next player
###################### MAP OUTPUT MODE #########################
    -dump nbr_cycles : Dumps memory after nbr_cycles then exits
#################### NCURSES OUTPUT MODE #######################
    -v               : Ncurses output mode
```

## Authors

* **Vitalii Poltavets** - Virtual machine [ChoadPet](https://github.com/ChoadPet)
* **Yaroslav Zakharchuk** - Virtual machine [ElCorte](https://github.com/ElCorrte)
* **Katerina Zakharchuk** - Assembler [kzakharc](https://github.com/kzakharc)
* **Dmitry Spiridonov** - Ncurses visualisation [d-spiridonov](https://github.com/d-spiridonov)
