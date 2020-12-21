	//#include <esp_assert.h>
//#include <unity.h>


#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Test_Led.h"

Test_Led::Test_Led(){
    
}

void Test_Led::test_Led_state_high(int Led) {
    digitalWrite(Led, HIGH);
    //TEST_ASSERT_EQUAL(1,digitalRead(Led));
    if(digitalRead(Led == 1)){Serial.println("test_Led passed");
    delay(1000);
    digitalWrite(Led, LOW);
    delay(1000);
    };
}
