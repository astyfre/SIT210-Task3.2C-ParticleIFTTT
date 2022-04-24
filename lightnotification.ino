#include <BH1750Lib.h>
#define brightLightThreshold 8000

BH1750Lib lightmeter;

void setup(){
    Serial.begin(9600);
    lightmeter.begin(BH1750LIB_MODE_CONTINUOUSHIGHRES);
    Serial.println("Running...");
}


void loop() {
    uint16_t lux = lightmeter.lightLevel();
    int level;
    
    if (lux > brightLightThreshold)
    {
        level = 1;
    }
    else
    {
        level = 0;
    }
    //String light = String(lux);
    //Particle.publish("lux", light);
    
    if (level == 1)
    {
        Particle.publish("lightLevel", "bright");
    }
    else if (level == 0)
    {
        Particle.publish("lightLevel", "dark");
    }
    delay(10000);
}