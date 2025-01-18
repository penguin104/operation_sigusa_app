

#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <M5Stack.h>


// クラス定義

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

// DCモータの制御クラス
class DCmotor {
  private:
    const int max_speed = 1600,min_speed = 0;
    
    Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
    
    int pin_black,pin_white,
    default_speed_right = max_speed,
    default_speed_left = max_speed;

  public:
    DCmotor(int output_pin_black,output_pin_white){
      pin_black = output_pin_black;
      pin_white = output_pin_white;
      pwm.begin();
      pwm.setPWMFreq(1600);
    }
// モータの片方の端子に電流を流して回転方向を制御する
    void power_right(int speed = default_speed){
      default_speed_right = speed;
      pwm.setPWM(pin_black,min_speed,speed);
      pwm.setPWM(pin_white,min_speed,min_speed);
    }

    void power_left(int speed = default_speed){
      default_speed_left = speed;
      pwm.setPWM(pin_black,min_speed,min_speed);
      pwm.setPWM(pin_white,min_speed,speed);
    }

    void power_stop(){
      pwm.setPWM(pin_black,min_speed,min_speed);
      pwm.setPWM(pin_white,min_speed,min_speed);
    }
}

//pca9685接続ピン列挙型
// w：白ケーブル b：黒ケーブル（試作を参照;水色のやつ）
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

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
