// Comment the next line to use ABP authentication on TTN. Leave it as it is to use recommended OTAA
#define OTAA
#define CAYENNE

#ifndef LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED
#define LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED

#ifndef OTAA
// UPDATE WITH YOUR TTN KEYS AND ADDR.
// Setting for ABP
static PROGMEM u1_t NWKSKEY[16] = { 0x22, 0x81, 0x54, 0x66, 0x29, 0x15, 0xB1, 0xB7, 0x4E, 0x49, 0x39, 0xE3, 0x22, 0x08, 0x6A, 0xA3 }; // LoRaWAN NwkSKey, network session key 
static u1_t PROGMEM APPSKEY[16] = { 0x8D, 0xBA, 0xB2, 0xE9, 0xF5, 0xDC, 0x42, 0xAD, 0x2A, 0xA6, 0x16, 0xC8, 0x81, 0x1A, 0xCE, 0x7B }; // LoRaWAN AppSKey, application session key 
static const u4_t DEVADDR = 0x260116FF ; // LoRaWAN end-device address (DevAddr)
#else
// Settings from OTAA device
static const u1_t PROGMEM DEVEUI[8]={ 0x42, 0xE8, 0xA1, 0x55, 0x03, 0xFD, 0xEF, 0x00 } ; // Device EUI, hex, lsb
static const u1_t PROGMEM APPEUI[8]={ 0x0B, 0xD8, 0x02, 0xD0, 0x7E, 0xD5, 0xB3, 0x70 }; // Application EUI, hex, lsb
static const u1_t PROGMEM APPKEY[16] = { 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 }; // App Key, hex, msb

void os_getDevEui (u1_t* buf) { 
    for (int i=0;i <8;i++){
        buf[i] = DEVEUI[7-i];
    }
}
void os_getArtEui (u1_t* buf) { 
    for (int i=0;i <8;i++){
        buf[i] = APPEUI[7-i];
    }
}
void os_getDevKey (u1_t* buf) {  
    memcpy_P(buf, APPKEY, 16);
}
#endif

#endif //LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED
