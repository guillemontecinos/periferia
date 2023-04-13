#include <ArduinoHttpClient.h>
// #include <WiFi101.h>
#include <WiFiNINA.h>

// Wifi settings
char ssid[] = "MIINTERNET.CL_2.4G_79F2";
char pass[] = "81023424";

char serverAddress[] = "192.168.2.155";
int port = 8000;

WiFiClient wifi;
HttpClient client = HttpClient(wifi, serverAddress, port);
int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);
  delay(5000);
  while (status != WL_CONNECTED) {
    Serial.print("Connecting to network: ");
    Serial.println(ssid);
    delay(1000);
    status = WiFi.begin(ssid, pass);
    delay(1000);
    Serial.println(status);
  }


  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {
  Serial.println("making POST request");
  String contentType = "application/x-www-form-urlencoded";
  String postData = "time=" + String(millis());

  client.post("/test", contentType, postData);

  // read the status code and body of the response
  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);

  Serial.println("Wait five seconds");
  delay(5000);
}
