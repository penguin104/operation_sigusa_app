import 'package:flutter/material.dart';

class Home extends StatefulWidget {
  const Home({super.key});

  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          "Operation SIGUSA APP",
        ),
        backgroundColor: Colors.blue,
        foregroundColor: Colors.white,
      ),
      body: Column(
        children: [
          Row(
            children: [
              Expanded(
                child: SizedBox(
                  width: 30,
                  height: 30,
                ),
              ),
              Expanded(
                child: ElevatedButton(
                    onPressed: () {
                      //TODO:前進の命令
                    },
                    child: Icon(
                      Icons.north,
                    )),
              ),
              Expanded(
                child: SizedBox(
                  width: 30,
                  height: 30,
                ),
              ),
            ],
          ),
          Row(
            children: [
              Expanded(
                child: ElevatedButton(
                    onPressed: () {
                      //TODO:左回転の命令
                    },
                    child: Icon(
                      Icons.west,
                    )),
              ),
              Expanded(
                child: ElevatedButton(
                    onPressed: () {
                      //TODO:アクションの命令
                    },
                    child: Icon(
                      Icons.ac_unit_outlined,
                    )),
              ),
              Expanded(
                child: ElevatedButton(
                    onPressed: () {
                      //TODO:右回転の命令
                    },
                    child: Icon(
                      Icons.east,
                    )),
              ),
            ],
          ),
          Row(
            children: [
              Expanded(
                child: SizedBox(
                  width: 30,
                  height: 30,
                ),
              ),
              Expanded(
                child: ElevatedButton(
                    onPressed: () {
                      //TODO:後退の命令
                    },
                    child: Icon(
                      Icons.south,
                    )),
              ),
              Expanded(
                child: SizedBox(
                  width: 30,
                  height: 30,
                ),
              ),
            ],
          ),
        ],
      ),
      bottomNavigationBar: BottomAppBar(
        color: Colors.blue,
      ),
    );
  }
}
