int sensorValue = 0;

int outputValue = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  // 从A0口读取模拟电压值
  sensorValue = analogRead(A0);
  // 将sensorValue的值缩放成outputValue
  // 以使其满足outputValue模拟输出的取值范围(0,255)
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // 9口做模拟电压输出，将A0口接收到的模拟电压反馈在电阻和LED上
  analogWrite(9, outputValue);
  // 将sensorValue和outputValue的值通过串口返回给PC
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  // 等待2ms，主要为了保证完成模数转换和数模转换
  delay(2); 
}