#include <WiFi.h>
 
const char* ssid     = "kkkkk";
const char* password = "uginokok16";
 
WiFiServer server(80);
 
void setup()
{
  Serial.begin(115200);
 
  pinMode(32, OUTPUT);      // set the LED pin mode
  pinMode(33, OUTPUT);      // set the LED pin mode
  pinMode(34, OUTPUT);      // set the LED pin mode
  pinMode(35, OUTPUT);      // set the LED pin mode
 
  delay(10);
 
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 
  server.begin();
}
 
int value = 0;
 
void loop() {
  WiFiClient client = server.available();   // listen for incoming clients
 
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
 
            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/32H\">here</a> to turn the LED on pin 32 on.<br>");
            client.print("Click <a href=\"/32L\">here</a> to turn the LED on pin 32 off.<br>");
            client.print("<br>");
 
            client.print("Click <a href=\"/33H\">here</a> to turn the LED on pin 33 on.<br>");
            client.print("Click <a href=\"/33L\">here</a> to turn the LED on pin 33 off.<br>");
            client.print("<br>");
 
            client.print("Click <a href=\"/34H\">here</a> to turn the LED on pin 34 on.<br>");
            client.print("Click <a href=\"/34L\">here</a> to turn the LED on pin 34 off.<br>");
            client.print("<br>");
 
            client.print("Click <a href=\"/35H\">here</a> to turn the LED on pin 35 on.<br>");
            client.print("Click <a href=\"/35L\">here</a> to turn the LED on pin 35 off.<br>");
            client.print("<br>");
 
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
 
        // Check to see if the client request was "GET /xH" or "GET /xL":
        if (currentLine.endsWith("GET /32H")) {
          digitalWrite(32, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /32L")) {
          digitalWrite(32, LOW);                // GET /L turns the LED off
        }
 
        if (currentLine.endsWith("GET /33H")) {
          digitalWrite(33, HIGH);               // GET /H turns the LED on
        }
 
        if (currentLine.endsWith("GET /33L")) {
          digitalWrite(33, LOW);                // GET /L turns the LED off
        }
 
        if (currentLine.endsWith("GET /34H")) {
          digitalWrite(34, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /34L")) {
          digitalWrite(34, LOW);                // GET /L turns the LED off
        }
 
        if (currentLine.endsWith("GET /35H")) {
          digitalWrite(35, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /35L")) {
          digitalWrite(35, LOW);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
