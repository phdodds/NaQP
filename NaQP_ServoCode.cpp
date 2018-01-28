unsigned int localPort = 1111; //UDP Port used to receive data

UDP Udp; //udp instance

Servo NaQPServo1; //name of servo

int pos = 0; //position of servo

int udpSize = 0; //create a variable for the UDP packet


void setup() {
    
    NaQPServo1.attach(A4); //attach the servo to the A4 pin
    Udp.begin(localPort); //begin UDP protocol
}

void loop() {
    
        
    udpSize = Udp.parsePacket(); //read the size of the UDP packet in to the variable
    
    char packetBuffer[udpSize]; //initialize buffer of 4 bytes
    
    if( udpSize > 0){
        
        Serial.println(udpSize); //print the size of the incoming udp buffer
        
        
        Udp.read(packetBuffer, udpSize); //read the UDP message of the udpSize in to the packet buffer
        
        int pos = atoi(packetBuffer); //convert from a string to an integer
        
        Serial.println(pos); //print the integer
        

        NaQPServo1.write(pos); //write the servo position 
        
    }
    


}