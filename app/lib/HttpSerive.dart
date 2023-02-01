import 'dart:convert';
import 'package:http/http.dart';

class HttpService {
  static const String apiURL =
      'https://backend.thinger.io/v3/users/substantivum/devices/DaysCountdown/resources/dateIn';
  static const String authKey =
      'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJkZXYiOiJEYXlzQ291bnRkb3duIiwiaWF0IjoxNjc1MjY4OTMxLCJqdGkiOiI2M2RhOTM0MzNkMTVjNTVkOTQ1ZGUzNDgiLCJzdnIiOiJldS1jZW50cmFsLmF3cy50aGluZ2VyLmlvIiwidXNyIjoic3Vic3RhbnRpdnVtIn0.0ycR81HG7oObZkv6jGmO_4t8PJrakMfxQ2yYsKgN8eM';

  static Future<bool> setCountdown(int daysLeft, bool arrowRight) async {
    Map<String, String> headers = {
      "Content-type": "application/json",
      "Authorization": authKey,
      "Accept": "application/json, text/plain",
    };
    Map<String, dynamic> content = {"date": daysLeft, "arrow": arrowRight};
    String json = jsonEncode(content);

    // Make the post request
    print("post");
    Response response =
        await post(Uri.parse(apiURL), headers: headers, body: json);

    print(response.statusCode);
    print(response.body);

    if (response.statusCode == 200) {
      Map<String, dynamic> _body = jsonDecode(response.body);

      if (_body["status"] == "Error") {
        print("Something went wrong! Packet back: $_body");
        return false;
      }
      return true;
    } else {
      print(response.statusCode);
      print(response.body);
      return false;
    }
  }
}
