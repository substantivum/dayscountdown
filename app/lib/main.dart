import 'dart:math';

import 'package:app/HttpSerive.dart';
import 'package:flutter/material.dart';
import 'package:intl/intl.dart';

import 'dart:convert';
import 'package:http/http.dart' as http;

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Days Countdown',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        // This is the theme of your application.
        //
        // Try running your application with "flutter run". You'll see the
        // application has a blue toolbar. Then, without quitting the app, try
        // changing the primarySwatch below to Colors.green and then invoke
        // "hot reload" (press "r" in the console where you ran "flutter run",
        // or simply save your changes to "hot reload" in a Flutter IDE).
        // Notice that the counter didn't reset back to zero; the application
        // is not restarted.
        primarySwatch: Colors.green,
      ),
      home: const MyHomePage(title: 'Days Countdown'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage>
    with SingleTickerProviderStateMixin {
  void postRequest(int days, bool direction) async {
    var response = await http.post(Uri.parse(''), body: {
      'id': days.toString(),
      'numberOfDays': daysBetween(DateTime.now(), _DateTime).toString(),
    });
    print(response.body);
  }

  DateTime today = DateTime.now();
  DateTime _DateTime = DateTime.now();

  late Animation<double> animation;
  late AnimationController controller;
  bool arrowRight = true;
  static const int animationDuration = 700;

  @override
  void initState() {
    super.initState();

    controller = AnimationController(
      vsync: this,
      duration: const Duration(milliseconds: animationDuration),
    );
    controller.addStatusListener((status) async {});

    animation = Tween<double>(begin: 0, end: -pi).animate(controller);
  }

  @override
  void dispose() {
    controller.dispose();
    super.dispose();
  }

  void rotateArrow() {
    if (arrowRight) {
      controller.forward(from: 0);
    } else {
      controller.reverse(from: animationDuration.toDouble());
    }
    arrowRight = !arrowRight;
    print(arrowRight.toString());
  }
  //arrowRight: true - ARN to BUD
  //arrowRight: false - BUD to ARN

  static int daysBetween(DateTime from, DateTime to) {
    from = DateTime(from.year, from.month, from.day);
    to = DateTime(to.year, to.month, to.day);
    return (to.difference(from).inHours / 24).round();
  }

  void _showDatePicker() {
    showDatePicker(
            context: context,
            initialDate: today,
            firstDate: DateTime(2000),
            lastDate: DateTime(2050))
        .then((value) {
      setState(() {
        if (value != null) // Fixes crash when pressing cancel
          this._DateTime = value!; // because value is null
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
          title: const Center(
        child: Text('Days Countdown'),
      )),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Padding(
              padding: EdgeInsets.all(8.0),
              // ignore: unnecessary_const
              child: const Text(
                'Choose your date',
                style: TextStyle(
                  color: Colors.black,
                  fontSize: 20,
                ),
              ),
            ),
            MaterialButton(
              onPressed: _showDatePicker,
              color: Colors.green,
              child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: Text(DateFormat('yMd').format(_DateTime),
                    // ignore: prefer_const_constructors
                    style: TextStyle(
                      color: Colors.white,
                      fontSize: 18,
                    )),
              ),
            ),
            Row(mainAxisAlignment: MainAxisAlignment.center, children: [
              const Text(
                'BUD',
                style: TextStyle(fontSize: 25),
              ),
              AnimatedBuilder(
                  animation: animation,
                  builder: (context, child) => Transform.rotate(
                        angle: animation.value,
                        child: InkWell(
                          splashColor: Colors.transparent,
                          highlightColor: Colors.transparent,
                          borderRadius: BorderRadius.circular(60),
                          onTap: rotateArrow,
                          child: Ink.image(
                            image: const AssetImage('assets/images/arrow.webp'),
                            height: 100,
                            width: 100,
                          ),
                        ),
                      )),
              const Text(
                'ARN',
                style: TextStyle(fontSize: 25),
              )
            ]),
            MaterialButton(
              onPressed: () {
                HttpService.setCountdown(
                    daysBetween(DateTime.now(), _DateTime), arrowRight);
              },
              color: Colors.green,
              child: const Padding(
                padding: EdgeInsets.all(10.0),
                child: Text(
                  'Set Countdown',
                  style: TextStyle(color: Colors.white, fontSize: 25),
                ),
              ),
            )
          ],
        ),
      ), // This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
