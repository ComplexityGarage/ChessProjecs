# Real-time display of a chessboard
# Authors 
- Eryk Bluj
- Mateusz Janus
# Description of the project 
For our final project during Garage of Complexity course we decided to create a chessboard with an integrated display system. The board detects the arrangement of pieces and shows their positions on a computer screen. To identify each piece, we placed a certain resistor inside it. The electric circuit in our project is based on a voltage divider. Each square on the board has two wires. When a piece is placed on it, a given resistor completes the circuit. This results in a characteristic voltage drop. Multiplexers (MUX in short) were used to determine a position of a piece. Each multiplexer corresponds to a row of the chessboard, with its I/O pins assigned to individual squares. The voltage value on every square is read cyclically by an Arduino board and a representation of a chess board is created in a PuTTY terminal. You can see the photo of the chessboard and an example view of the chessboard in a terminal below (**the latter will be uploaded soon**).
<p align="center">

<img src="https://github.com/user-attachments/assets/fc20bb24-6716-4a46-b886-19e6c10ea949" height = "400" width="500">


# Science and tech used 
In order to place a resistor inside a chess piece we drilled a small hole in the bottom. A resistor was placed on a chequers piece and then glued to a chess piece. Two holes were also made inside chequers pieces so that the resistors would fit easily. **Circuit scheme will be uploaded soon.**

List of equipment:
1. wooden chessboard with plastic chess and chequers pieces
2. ridiculous number of wires 
3. 12 resistors representing each chess piece (a list of reistance values corresponding to chess pieces can be found below)
4. 8 10k&Omega; resistors
5. 8 CD4051 multiplexers
7. Arduino mega 2560 and Arduino Uno Rev3 boards

List of resitors with a matching piece (resistance --- piece):
### white pieces:
1. 510 &Omega; --- pawn
2. 1.2 k&Omega; --- knight
3. 2.2 k&Omega; --- bishop
4. 4.7 k&Omega; --- rook
5. 6.8 k&Omega; --- queen
6. 10 k&Omega; --- king
### black pieces:
1. 47 k&Omega; --- pawn
2. 68 k&Omega; --- knight
3. 100 k&Omega; --- bishop
4. 220 k&Omega; --- rook
5. 300 k&Omega; --- queen
6. 680 k&Omega; --- king



# State of the art 
We learned many useful things throughout this project and the whole course in general. We extended our knowledge about Arduino boards. We are now familliar with basic working principle of multiplexers. We also gained experience in understanding documentation and wiring related to new components. The terminal available in Arduino IDE software wasn't suitable for our project, that's why we had to learn to use PuTTY software, which enabled us to display chess pieces on a screen. In addition to that, we learned how to efficiently divide tasks and deal with troubleshooting.
# What next?
There are a few things that need improvement in our project. Placing a piece onto a chessboard is inconvenient and requires precision. To tackle this problem we might use sensors instead of resistors, so that the game can go smoothly. Another thing we want to change is the display, which is rather plain and schematic. We are planning to use Python in order to enhance the visuals. Due to a lack of time and wires we didn't manage to finish the whole project. In the future we will work on wiring the whole board and improving the stability of the circuit.
# Sources 
- [Volatge divider] ( https://en.wikipedia.org/wiki/Voltage_divider )
- [PuTTY softawre] ( https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html )
- [MUX datasheet] ( https://www.ti.com/lit/ds/symlink/cd4053b.pdf?ts=1758418394447&ref_url=https%253A%252F%252Fwww.google.com%252F )

