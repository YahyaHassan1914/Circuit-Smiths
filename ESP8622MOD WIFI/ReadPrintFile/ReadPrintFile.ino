#include <Arduino.h>
#include <LittleFS.h>

const char *filename = "file_name.txt";  // Ensure the file path is correct

void setup() {
  Serial.begin(115200);
  delay(10000);  // Give time to open the Serial Monitor

  Serial.println("Mounting LittleFS...");
  if (!LittleFS.begin()) {
    Serial.println("Failed to mount file system");
    return;
  }
  Serial.println("LittleFS mounted successfully");

  File file = LittleFS.open(filename, "r");

  if (!file) {
    Serial.println("Could not open file for reading");
  } else {
    Serial.println("Reading file contents:");

    while (file.available()) {
      char buf[32];  // Buffer to store read data

      size_t bytesRead = file.readBytes(buf, sizeof(buf) - 1);
      buf[bytesRead] = '\0';  // Null-terminate the buffer

      Serial.print(buf);  // Print the buffer to the Serial Monitor

      yield();  // Allow background tasks to run
    }

    file.close();  // Close the file when done
  }

  LittleFS.end();  // Unmount the file system
}

void loop() {
  // Nothing to do here
}
