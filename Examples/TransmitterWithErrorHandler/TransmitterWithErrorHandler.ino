/// @file TransmitterWithErrorHandler.ino
/// @brief Transmitter with error handler from Transmitter1 in Any/MultiStrategyLink
/// Version to work with the OlcbBasicNode example which is node 50.

#include <PJONSoftwareBitBang.h>

PJONSoftwareBitBang bus(45);

/// error_handler
void error_handler(uint8_t code, uint16_t data, void *custom_pointer) {
  if(code == PJON_CONNECTION_LOST) {
    Serial.print("Connection lost with device id ");
    Serial.println(bus.packets[data].content[0], DEC);
  }
};

int count = 0;

void receiver_function(uint8_t *payload, uint16_t length, const PJON_Packet_Info &packet_info) {
  /* Make use of the payload before sending something, the buffer where payload points to is
     overwritten when a new message is dispatched */
  if(payload[0] == 'X') {
    count++;
    Serial.print("BLINK ");
    Serial.println(count);
    // Avoid Serial interference during test flushing
    Serial.flush();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(30);
    digitalWrite(LED_BUILTIN, LOW);
  } else { 
    for (byte i = 0; i < length; i++)
    {
      Serial.print((char)payload[i]);
    }
    Serial.println(" ");
    Serial.flush();
  }
};

void setup() {
  while (!Serial);
  Serial.begin(115200);
  Serial.println("Bitbang Test: Transmitter with error handler");
  bus.strategy.set_pin(12);
  bus.set_error(error_handler);
  bus.set_receiver(receiver_function);
  if (!bus.strategy.can_start()) {
    Serial.println("PJON not running - bus.strategy.can_start() returns false");
  } else {
    bus.begin();
    bus.send_repeatedly(50, "X", 1, 1000000); // Send X to device 50 every second
    Serial.println("PJON bus is running");
  }
}

void loop() {
  bus.update();
  bus.receive(1000);
};
