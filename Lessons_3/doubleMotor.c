/********************************************/
/*ProjectName:doubleMotor					*/
/*ժҪ:L293D��������ֱ�����                */
/*˵��:ͨ�����ڷ���ָ����Կ��Ʒ�����ٶ� */
/*	   �ٶȷ�������'S'STOP,'M'Medium,'F'Fast*/
/*     ��ϸָ��ɼ�ע�͡�					*/
/********************************************/

char spd = '0';    /*�ٶȿ��ƣ�������'S'ֹͣ��'M'���٣�'F'����*/
int  spd_i = 0;
char dir = '0';      /*������ƣ�ǰ��'F'������'B'������ת'L''R'*/
/*�Ӵ��ڻ���������ָ�ָ���ʽΪ'dir'+'speed'*/
char ins [2];      /*ָ��*/
void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);   /*���2�Ķ���2*/
  pinMode(6, OUTPUT);   /*���2�Ķ���1*/
  pinMode(9, OUTPUT);   /*���1�Ķ���2*/
  pinMode(10, OUTPUT);  /*���1�Ķ���1*/
}

void loop() {
  if (Serial.available() >> 0) {
    Serial.readBytes( ins, 2 );
    Serial.println(ins);      /*�����͵�ָ���ٷ�����PC*/
    dir = ins[0];
    spd = ins[1];
    Serial.println(dir);
    Serial.println(spd);
    switch (spd) {            /*����ָ����ٶ�����PWMռ�ձ�*/
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