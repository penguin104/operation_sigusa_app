

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
class servo{
  
};



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
