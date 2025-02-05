import 'dart:io';

import 'package:flutter_blue_plus/flutter_blue_plus.dart';

class Bluetooth {
  var bluetoothDeviceList = [];
  
  FlutterBluePlus flutterBlue;
  
  Bluetooth (this.flutterBlue) {
    flutterBlue = FlutterBluePlus();
    if(CheckSupport() == false){
      return;
    }

    FlutterBluePlus.adapterState.listen((BluetoothAdapterState state){
      print(state);
      if(state == BluetoothAdapterState.on){
        // on action
      }else{
        // off action
      }
    });

    BluetoothOnAndroid();

    
  }
  
  Future<bool> CheckSupport() async{
    if(await FlutterBluePlus.isSupported == false){
      print("Bluetooth not supported by this device");
      return false;
    }
    return true;
  }

  Future<void> BluetoothOnAndroid()async{
    if (Platform.isAndroid) {
      await FlutterBluePlus.turnOn();
    }
  }

}
