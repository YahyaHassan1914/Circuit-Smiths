#include <FS.h>
#include <ESP8266WiFi.h>

String ssid, password;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize SPIFFS
  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount file system");
    return;
  }

  // Read configuration
  readConfig(ssid, password);

  // Debug output
  Serial.println("Configuration:");
  Serial.print("SSID: s");
  Serial.print(ssid);
  Serial.println("s");
  Serial.print("Password: ");
  Serial.println(password);

  // Uncomment this line to connect to Wi-Fi after debugging
  // if (ssid.length() > 0 && password.length() > 0) {
  //   connectToWiFi(ssid, password);
  // }
}

void loop() {
  // Main code here
  // If you want to debug values continuously, you can use this code
  // but be cautious of flooding the serial monitor
  Serial.println("Configuration:");
  Serial.print("SSID: s");
  Serial.print(ssid);
  Serial.println("s");
  Serial.print("Password: ");
  Serial.println(password);
  delay(5000); // Delay to avoid flooding
}

void readConfig(String &ssid, String &password) {
  File file = SPIFFS.open("/config.ini", "r");
  if (!file) {
    Serial.println("Failed to open config file");
    return;
  }

  while (file.available()) {
    String line = file.readStringUntil('\n');
    Serial.print("Read line: ");
    Serial.println(line); // Debug: print the line read from the file
    parseConfig(line, ssid, password);
  }
  file.close();
}

void parseConfig(String line, String &ssid, String &password) {
  int separatorIndex = line.indexOf('=');
  if (separatorIndex != -1) {
    String key = line.substring(0, separatorIndex);
    String value = line.substring(separatorIndex + 1);

    if (key == "ssid") {
      ssid = value;
    } else if (key == "password") {
      password = value;
    }
  }
}

void connectToWiFi(String ssid, String password) {
  WiFi.begin(ssid.c_str(), password.c_str());
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.print("...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}
