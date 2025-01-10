

#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <M5Stack.h>


//pca9685接続ピン列挙型
enum pca9685_no {
  sv1,         //首
  sv2,         //右フリッパー
  sv3,         //左フリッパー
  dc_right_b,  //右DCモータ
  dc_right_w,  //右DCモータ
  dc_left_b,   //左dcモータ
  dc_left_w    //左dcモータ
};

//サーボモータの中心の値sv1から
int sv_angleVal[3] = { 90, 70, 170 };


// サーボモータクラス
// ピン設定等コンストラクタにて設定
class Servo_pca9685 {
  private:
    Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

    int pin,
        now_angle;

    // PCA9685でサーボモータを動かすときに使用する定数
    const int servo_min = 500,
              servo_max = 2400,
              servo_deg_max = 180,
              servo_deg_min = 0;

  public:
    // コンストラクタ
    Servo_pca9685(int output_pin, int default_angle = 90) {
      pin = output_pin;
      now_angle = default_angle;
      pwm.begin();
    }

    void angle(int angle) {
      // サーボモータを利用するために出力周波数を設定 
      pwm.setPWMFreq(20);

      angle = map(
        angle,
        servo_deg_min,
        servo_deg_max,
        servo_min,
        servo_max);

      pwm.writeMicroseconds(sv1, angle);
      // 現在の角度に設定
      now_angle = angle;
    }
};



void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
