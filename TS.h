#include <ThingSpeak.h>

unsigned long myChannelNumber = 1;
const char * myWriteAPIKey = "9FTW4KIU2OP5O8AE";

void TSS() {
  ThingSpeak.begin(client);
}

void TSL(){
  ThingSpeak.setField(1, DHTT);
  ThingSpeak.setField(2, DHTH);
  ThingSpeak.setField(3, T);
  ThingSpeak.setField(4, level);
  ThingSpeak.setField(5, pHv);
  ThingSpeak.setField(6, Pompa);

  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
}