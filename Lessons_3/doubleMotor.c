/********************************************/
/*ProjectName:doubleMotor					*/
/*摘要:L293D驱动两个直流电机                */
/*说明:通过串口发送指令，可以控制方向和速度 */
/*	   速度分三档：'S'STOP,'M'Medium,'F'Fast*/
/*     详细指令可见注释。					*/
/********************************************/

char spd = '0';    /*速度控制，分三档'S'停止，'M'中速，'F'快速*/
int  spd_i = 0;
char dir = '0';      /*方向控制，前进'F'，后退'B'，左右转'L''R'*/
/*从串口缓冲区接收指令，指令格式为'dir'+'speed'*/
char ins [2];      /*指令*/
void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);   /*电机2的端子2*/
  pinMode(6, OUTPUT);   /*电机2的端子1*/
  pinMode(9, OUTPUT);   /*电机1的端子2*/
  pinMode(10, OUTPUT);  /*电机1的端子1*/
}

void loop() {
  if (Serial.available() >> 0) {
    Serial.readBytes( ins, 2 );
    Serial.println(ins);      /*将发送的指令再返还到PC*/
    dir = ins[0];
    spd = ins[1];
    Serial.println(dir);
    Serial.println(spd);
    switch (spd) {            /*根据指令的速度设置PWM占空比*/
      case 'S': spd_i = 0; break;
      case 'M': spd_i = 127; break;
      case 'F': spd_i = 255; break;
    }
    switch (dir) {
      case 'F': 
        analogWrite(6,spd_i);
        digitalWrite(5,LOW);
        analogWrite(10,spd_i);
        digitalWrite(9,LOW);
        break;
      case 'B': 
        analogWrite(5,spd_i);
        digitalWrite(6,LOW);
        analogWrite(9,spd_i);
        digitalWrite(10,LOW);
        break;
      case 'L':
        analogWrite(6,spd_i);
        digitalWrite(5,LOW);
        analogWrite(10,0);
        digitalWrite(9,LOW);
        break;
      case 'R':
        analogWrite(6,0);
        digitalWrite(5,LOW);
        analogWrite(10,spd_i);
        digitalWrite(9,LOW);
        break;
    }
  }
}