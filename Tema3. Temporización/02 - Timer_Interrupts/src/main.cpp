#include <Arduino.h>
#include <Ticker.h>

#define HW_TIMER 0

Ticker timer;


#if HW_TIMER
void ICACHE_RAM_ATTR onTimer() {
  Serial.println("One second ellapsed");
}
#else
unsigned int count = 0;
void ICACHE_RAM_ATTR onTimer() {
  count++;
  Serial.print(count);
  Serial.println(" Seconds ellapsed");
}
#endif
void setup() {
  Serial.begin(9600);
  #if HW_TIMER
  // 2 timers -> 0 y 1 -> 23 bits
  // timer0 -> 0 (no es recomendable)
  // timer1 -> 1

  // freq base = 80 MHz -> 1us -> 80 ticks -> 104857.6 us máximo -> 0.1048576 s máximo
  // Divisor 16 = freq base = 5 MHz -> 1 us -> 5 ticks -> 1677721.6 us máximo -> 1.6777216 s máximo
  // Divisor 256 = freq base = 31.25 KHz -> 1 tick -> 3.2 us -> 26843545.6 us máximo -> 26.8435456 s máximo
  timer1_enable(TIM_DIV16, TIM_EDGE, TIM_LOOP);
  timer1_write(5000000); //Máx valor -> 8388608
  timer1_attachInterrupt(onTimer);
  #else
  timer.attach(1, onTimer);
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
}
