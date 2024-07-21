#include <FS.h>        // File system library
#include <LittleFS.h>  // LittleFS library

void setup() {
  Serial.begin(115200);
  delay(10000);  // Give time to open the Serial Monitor
  Serial.println("Starting setup...");

  Serial.println("Mounting LittleFS...");
  if (!LittleFS.begin()) {
    Serial.println("Failed to mount file system");
    return;
  }
  Serial.println("LittleFS mounted successfully");

  Serial.println("Listing files:");
  listDir("/", 0);
  Serial.println("Setup complete");
}

void loop() {
  // Nothing to do here
}

void listDir(const char *dirname, uint8_t levels) {
  Serial.printf("Entering listDir: %s, levels: %d\n", dirname, levels);

  Dir dir = LittleFS.openDir(dirname);
  
  while (dir.next()) {
    Serial.printf("Found entry: %s\n", dir.fileName().c_str());
    if (dir.isDirectory()) {
      Serial.printf("DIR : %s\n", dir.fileName().c_str());
      if (levels) {
        String subDir = String(dirname) + "/" + dir.fileName();
        Serial.printf("Entering sub-directory: %s\n", subDir.c_str());
        listDir(subDir.c_str(), levels - 1);
      }
    } else {
      Serial.printf("FILE: %s, SIZE: %d\n", dir.fileName().c_str(), dir.fileSize());
    }
  }
  Serial.printf("Exiting listDir: %s\n", dirname);
}
