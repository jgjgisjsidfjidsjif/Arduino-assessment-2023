#define unit_delay 250 

//International morse code theory:
    //Dash length = unit_delay*3
    //Pause between elements = unit_delay
    //Pause between letters = unit_delay*3
    //Pause between words = unit_delay*7


constexpr char alpha_nocap[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};// Array of non capitalized letters.
constexpr char alpha_cap[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // Array of capitalized letters
constexpr char numbers[] = {'1','2','3','4','5','6','7','8','9','0'}; // Array of numbers.
char morse_alpha[]={'.', '-'}; // array of dots and dashes. 0 = *, 1 = -.
String code = "";
int len = 0; //length
char character; //
int sel_array; // This selects the array. 1 for the non capitalized letters, 2 for the capitalized letters, 3 for the numbers. 
int array_char; // This selects the part of the array.
int testfunction; // Tests further processing data from the specified part of the array

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);// initialize LED
  Serial.begin(115200);
  Serial.println("Messenger ready. Type a message to be translated to morse code.");
}

void m_dot(){ // Function for dot, mainly for optimization
    Serial.print(morse_alpha[0]);//Print .
    digitalWrite(LED_BUILTIN, HIGH); //turn the LED on
    delay(unit_delay);//wait unit_delay
}

void m_dash(){ //Function for dash, mainly for optimization.
  Serial.print(morse_alpha[1]);//print -
  digitalWrite(LED_BUILTIN, HIGH); //turn the LED on
  delay(unit_delay*3); // Wait unit_delay*3, as a subsitute of - being held for 3 units.
}

void off(int offtime){ //Turns LED Off for a specified time (in the brackets.)
    digitalWrite(LED_BUILTIN, LOW); //turn the LED off
  delay(offtime);
} 

void rosetta_stone(){// Basically a massive switch statement that goes through the arrays to find the text.
  switch(character){
    case alpha_cap[0]: // If character was A, or a
    case alpha_nocap[0]: // lowercase
    m_dot(); //Dot
    off(unit_delay);// Wait the unit delay
    m_dash(); //Dash
    off(unit_delay*3);// Between letters, international morse code dictates that there should be a gap of unit_delay*3. 
    break; //end the statement and go back.
    case alpha_cap[1]: // If the character was B
    case alpha_nocap[1]: // Or its lower case equivalence
    m_dash();
    off(unit_delay);
    m_dot();
    off(unit_delay);
    m_dot();
    off(unit_delay);
    m_dot();
    off(unit_delay*3);// Between letters, international morse code dictates that there should be a gap of unit_delay*3. 
    break;// End the statement.
    case alpha_cap[2]: //If the letter is C
    case alpha_nocap[2]: //Or its lower case equivalent
    m_dash();
    off(unit_delay);
    m_dot();
    off(unit_delay);
    m_dash();
    off(unit_delay);
    m_dot();
    off(unit_delay*3);
    break;// End the statement
    case alpha_cap[3]: //If the letter is D
    case alpha_nocap[3]: // Or its lower case equivalent
    m_dash();
    off(unit_delay);
    m_dot();
    off(unit_delay);
    m_dot();
    off(unit_delay*3);
    break;//End the statement and go back
    case alpha_cap[4]: //If the letter is E
    case alpha_nocap[4]: // Or its lower case equivalent.
    m_dot();
    off(unit_delay*3);
    break;//End the statement
    case alpha_cap[5]:  //If the letter is F
    case alpha_nocap[5]: // Or its lower case equivalent
        m_dot();
    off(unit_delay);
        m_dot();
    off(unit_delay);
        m_dash();
    off(unit_delay);
        m_dot();
    off(unit_delay*3);
    break;//End the statement
    case alpha_cap[6]: //If the letter is G
    case alpha_nocap[6]: //Or the lowercase equivalent
    m_dash();
    off(unit_delay);
    m_dash();
    off(unit_delay);
    m_dot();
    off(unit_delay*3);
    break;//G
    case alpha_cap[7]: //If the letter is H
    case alpha_nocap[7]: // Or its lowercase equivalent
    m_dot();
    off(unit_delay);
    m_dot();
    off(unit_delay);
    m_dot();
    off(unit_delay);
    m_dot();
    off(unit_delay)*3;
    break;//End the statement and go back
    case alpha_cap[8]: // If the letter is I
    case alpha_nocap[8]: //Or the lowercase equivalent

    break;//I
        case alpha_cap[9]:
    case alpha_nocap[9]:
    break;//J
        case alpha_cap[10]:
    case alpha_nocap[10]:
    break;//K
        case alpha_cap[11]:
    case alpha_nocap[11]:
    break;//L
        case alpha_cap[12]:
    case alpha_nocap[12]:
    break;//M
        case alpha_cap[13]:
    case alpha_nocap[13]:
    break;//N
        case alpha_cap[14]:
    case alpha_nocap[14]:
    break;//O
        case alpha_cap[15]:
    case alpha_nocap[15]:
    break;//P
        case alpha_cap[16]:
    case alpha_nocap[16]:
    break;//Q
        case alpha_cap[17]:
    case alpha_nocap[17]:
    break;//R
        case alpha_cap[18]:
    case alpha_nocap[18]:
    break;//S
        case alpha_cap[19]:
    case alpha_nocap[19]:
    break;//T
        case alpha_cap[20]:
    case alpha_nocap[20]:
    break;//U
        case alpha_cap[21]:
    case alpha_nocap[21]:
    break;//V
        case alpha_cap[22]:
    case alpha_nocap[22]:
    break;//W
        case alpha_cap[23]:
    case alpha_nocap[23]:
    break;//X
        case alpha_cap[24]:
    case alpha_nocap[24]:
    break;//Y
        case alpha_cap[25]:
    case alpha_nocap[25]:
    break;//Z
    case numbers[0]:
    break;
    case numbers[1]:
    break;
    case numbers[2]:
    break;
    case numbers[3]:
    break;
    case numbers[4]:
    break;
    case numbers[5]:
    break;
    case numbers[6]:
    break;
    case numbers[7]:
    break;
    case numbers[8]:
    break;
    case numbers[9]:
    break;
    case ' ':
    Serial.print(" ");
    delay(unit_delay*3);// Between letters, there has to be a morse code delay of the unit_delay*3.
    break;
    }

  }

void text2morse(){ // Cuts the sent text to the individual character, then ships it off to the rosetta stone, which translate it to the morse code.
  len = code.length(); //Length variable to show how large the text is.
  for (int i = 0; i < len; i++){ //This statement goes through the characters of the text inputted.
    character = code.charAt(i); //This selects the current character
    rosetta_stone(); // Calls the Rosetta stone, which translates the character to morse.
    }
  }

void loop() {
  while (Serial.available()){
    code = Serial.readString();
    Serial.print(code);
    Serial.print(" = ");
    text2morse();
    Serial.println("");
    }
    delay(1000);
    
}
