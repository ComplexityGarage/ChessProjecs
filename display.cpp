#include <Arduino.h>

int selectPins[3] = {11, 12, 13}; // digital pins of arduino, which mux is connected to (A,B,C)
int muxSignal[8] = {A0,A1,A2,A3,A4,A5,A6,A7}; // arduino analog pins for each mux 
String analog_pin[8] = {"A0","A1","A2","A3","A4","A5","A6","A7"};

const char* pieces[] = { " ", "♟", "♞", "♝","♜", "♛", "♚" }; //chess pieces
const char* colors[2] = {"\033[35m", "\033[37m"}; //magenta (instead of black), white

int ValueToPiece(int sig){ //function returning matching index of a "pieces" array based on signal value
  if(sig == 1023){
    return 0;
  }

  else if( (sig >= 50 && sig <= 70) || (sig >= 838 && sig <= 890) ){ //pawns, 510 ohm i 47k ohm
    return 1;
  }

  else if( (sig >= 100 && sig <= 145) || (sig >= 893 && sig <= 903) ){ //knights, 1.2k ohm i 68k ohm
    return 2;
  }

  else if( (sig >= 175 && sig <= 230) || (sig >= 930 && sig <= 940) ){ //bishops, 2.2k ohm i 100k ohm
    return 3;
  }

  else if( (sig >= 323 && sig <= 333) || (sig >= 981 && sig <= 991) ){ //rooks, 4.7k ohm i 220k ohm
    return 4;
  }

  else if( (sig >= 370 && sig <= 450) || (sig >= 993 && sig <= 1002 ) ){ //queens, 6.8k ohm i 300k ohm
    return 5;
  }

  else if( (sig >= 480 && sig <= 620) || (sig >= 1004 && sig <= 1020 ) ){ //kings, 10k ohm i 680k ohm
    return 6;
  }
  else return 0;
}

int ValueToColor(int sig){ //function returning an index of "colors" array
  if (sig < 650){ //magenta
    return 1;
  }
  if (sig> 800){ //white
    return 0;
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(selectPins[i], OUTPUT);
  }
}

void loop() {
  int size = 8;
 
  Serial.print("\033[2J"); //clearing terminal
  Serial.print("\033[H");
  Serial.println("WIDOK");
   for (int row = 0; row < size; row++) { //loop interaiting through MUXes
    
      
    for (int col = 0; col < size; col++) { //loop iteraiting through MUX' pins
     
      // Set select pins to binary of channel number
      for (int i = 0; i < 3; i++) {
        digitalWrite(selectPins[i], (col >> i) & 1);
      }

      int val = analogRead(muxSignal[row]); //reading a signal from an I/O pin of a MUX
      
      if ((row + col) % 2 == 0){
        Serial.print("[");}
        else
          Serial.print(" ");
       
      int pc_idx = ValueToPiece(val);
      int clr_idx = ValueToColor(val);
      
      Serial.print(colors[clr_idx]); //color choice
      Serial.print(pieces[pc_idx]); //displaying a given piece
      Serial.print("\033[0m"); //color reset
      
      
      
      if ((row + col) % 2 == 0) Serial.print("]");
      else Serial.print(" ");
      
    }
    Serial.println();
  }
  delay(1000);
}

