/*LED_Flash*/
int led_cnt = 0;

void setup()
{
	for(led_cnt; led_cnt<=7; led_cnt++){
		pinMode(led_cnt, OUTPUT);
	}
}

void loop()
{
	led_cnt = 7;
	for(led_cnt; led_cnt>=0; led_cnt--){
		digitalWrite(led_cnt, HIGH);
		delay(500);
		digitalWrite(led_cnt, LOW);
  }
}