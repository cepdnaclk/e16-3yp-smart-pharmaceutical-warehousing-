
class UART{
  private:
    int incomingByte = 0;    // for incoming serial data

  public:
    Display disp ;

  UART(){
    
    Serial.begin(115200);
  } 

  void setup_disp(Display k ){
      disp = k ;
  }

  void RX(){
      if (Serial.available()>1) {
      
        //Serial.println(Serial.readString());
        String tem = Serial.readString() ;
        disp.play( tem );
        mqtt.pub(tem);
      }
  }

  void TX(){
    Serial.println("hello");
    delay(2000);
  }
  
};
