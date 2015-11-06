/*

 IoTAnalytics Examples
 
 Written 2014 by Adrian McEwen
 Modify 2015 by Michael Rosen
 
 This code is in the public domain.
 
 */

#include <SPI.h>         
#include <WiFi.h>
#include <IoTkit.h>    // include IoTkit.h to use the Intel IoT Kit
#include <Ethernet.h>  // must be included to use IoTkit

int status = WL_IDLE_STATUS;
char ssid[] = "mynetwork";  //  your network SSID (name)
char pass[] = "mypassword";       // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)

const int pinTemp = A0;      // pin of temperature sensor

IoTkit iotkit; // IoTkit object, for talking to enableiot.com

float temperature;
int B=3975;                  // B value of the thermistor
float resistance;


void setup() 
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    // don't continue:
    while(true);
  } 

  String fv = WiFi.firmwareVersion();
  if( fv != "1.1.0" )
    Serial.println("Please upgrade the firmware");

  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  Serial.println("Connected to wifi");
  printWifiStatus();

  Serial.println("Initializing iotkit");
  iotkit.begin();
  
  // First off we need to register the type of sensor
  Serial.println("Registering sensor");
  iotkit.send("{ \"n\": \"temperature\", \"t\": \"temperature.v1.0\"}\n");
}

void loop()
{
  // Take a temperature reading
  int val = analogRead(pinTemp);                               // get analog value
  resistance=(float)(1023-val)*10000/val;                      // get resistance
  temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;     // calc temperature
  Serial.print("Temperature is ");
  Serial.println(temperature);

  // Send to enableiot
  Serial.println("Sending temperature to enableiot.com");
  iotkit.send("temperature", (double) temperature);

  // wait ten seconds before checking again
  delay(10000); 
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}






