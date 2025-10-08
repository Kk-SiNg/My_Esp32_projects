
String MorseDictionnary[36][2] ={
  {"A",".-"},
  {"B","-..."},
  {"C","-.-."}, 
  {"D","-.."}, 
  {"E","."}, 
  {"F","..-."}, 
  {"G","--."}, 
  {"H","...."}, 
  {"I",".."}, 
  {"J",".---"}, 
  {"K","-.-"}, 
  {"L",".-.."}, 
  {"M","--"}, 
  {"N","-."}, 
  {"O","---"}, 
  {"P",".--."}, 
  {"Q","--.-"}, 
  {"R",".-."}, 
  {"S","..."}, 
  {"T","-"}, 
  {"U","..-"}, 
  {"V","...-"}, 
  {"W",".--"}, 
  {"X","-..-"}, 
  {"Y","-.--"}, 
  {"Z","--.."}, 
  {"0","-----"},
  {"1",".----"},
  {"2","..---"},
  {"3","...--"},
  {"4","....-"},
  {"5","....."},
  {"6","-...."},
  {"7","--..."},
  {"8","---.."},
  {"9","----."}
};

String code;
int output_pin = 2;

void setup() {
  Serial.begin(115200);
  pinMode(output_pin, OUTPUT);
}

void loop() {
  code = Serial.readString();
  // Serial.println(code);

  for(int i = 0; i < code.length(); i++){
    Serial.println(code[i]);
    
    for(int j = 0; j < 36; j++){
      if(MorseDictionnary[j][0] == String(code[i])){
        for(char ch: MorseDictionnary[j][1]){

          // Serial.print(ch);
          if(ch == '.'){
            digitalWrite(output_pin, HIGH);
            delay(50);
            digitalWrite(output_pin, LOW);
            delay(50);
          }

          else{
            digitalWrite(output_pin, HIGH);
            delay(200);
            digitalWrite(output_pin, LOW);
            delay(50);
          }

        }
        delay(200);
      }
    }
  }
}
