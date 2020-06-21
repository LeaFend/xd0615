#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);//����1
  pinMode(IN2, OUTPUT);//����2
  pinMode(IN3, OUTPUT);//����3
  pinMode(IN4, OUTPUT);//����4
  pinMode(S1, OUTPUT);//Ƭѡ1
  pinMode(S2, OUTPUT);//Ƭѡ2
  pinMode(S3, OUTPUT);//Ƭѡ3
  pinMode(S4, OUTPUT);//Ƭѡ4

  pinMode(LT, OUTPUT); //����
  pinMode(BT, OUTPUT); //����
  digitalWrite(LT, HIGH);
  digitalWrite(BT, HIGH);
  digitalWrite(S1, HIGH);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  digitalWrite(S4, HIGH);
}

int cnt1 = 0;
byte income[4] = {0};
void loop() {
  /*��ȡ�����յ�����λ���֣�����ֳ�4�ĵ��������ִ洢��income[0]��income[3]*/
  if (Serial.available() >> 0) {
    income[cnt1] = Serial.read();
    income[cnt1] -= '0';
    Serial.println(income[cnt1]);
    if (cnt1 < 4) {
      cnt1++;
    }
    else {
      cnt1 = 0;
    }
    digitalWrite(S1, LOW);
    digitalWrite(IN1, income[0] & 0x01);
    digitalWrite(IN2, (income[0] >> 1) & 0x01);
    digitalWrite(IN3, (income[0] >> 2) & 0x01);
    digitalWrite(IN4, (income[0] >> 3) & 0x01);
    digitalWrite(S1, HIGH);

    digitalWrite(S2, LOW);
    digitalWrite(IN1, income[1] & 0x01);
    digitalWrite(IN2, (income[1] >> 1) & 0x01);
    digitalWrite(IN3, (income[1] >> 2) & 0x01);
    digitalWrite(IN4, (income[1] >> 3) & 0x01);
    digitalWrite(S2, HIGH);

    digitalWrite(S3, LOW);
    digitalWrite(IN1, income[2] & 0x01);
    digitalWrite(IN2, (income[2] >> 1) & 0x01);
    digitalWrite(IN3, (income[2] >> 2) & 0x01);
    digitalWrite(IN4, (income[2] >> 3) & 0x01);
    digitalWrite(S3, HIGH);

    digitalWrite(S4, LOW);
    digitalWrite(IN1, income[3] & 0x01);
    digitalWrite(IN2, (income[3] >> 1) & 0x01);
    digitalWrite(IN3, (income[3] >> 2) & 0x01);
    digitalWrite(IN4, (income[3] >> 3) & 0x01);
    digitalWrite(S4, HIGH);
  }
}