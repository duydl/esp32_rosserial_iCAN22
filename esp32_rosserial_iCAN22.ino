/*
 * rosserial Publisher Example
 * Prints "hello world!"
 * This intend to connect to a Wifi Access Point
 * and a rosserial socket server.
 * You can launch the rosserial socket server with
 * roslaunch rosserial_server socket.launch
 * The default port is 11411
 *
 */

#include <ros.h>
#include <std_msgs/String.h>
#define ROSSERIAL_ARDUINO_TCP
#include <WiFi.h>
#include "pc2_sample.h"

const char* ssid     = "***";
const char* password = "***";
// Set the rosserial socket server IP address
IPAddress server(192,168,11,3);
// Set the rosserial socket server port
const uint16_t serverPort = 11411;

ros::NodeHandle nh;
// Make a chatter publisher
sensor_msgs::PointCloud2 pc_msgs;

ros::Publisher chatter("chatter", &pc_msgs);


void setup()
{
  // Use ESP8266 serial to monitor the process
  Serial.begin(9600);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Connect the ESP8266 the the wifi AP
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Set the connection to rosserial socket server
  nh.getHardware()->setConnection(server, serverPort);
  nh.initNode();

  // Another way to get IP
  Serial.print("IP = ");
  Serial.println(nh.getHardware()->getLocalIP());
  nh.advertise(chatter);
}

void loop()
{
  pc_msgs = pc2_sample::construct_pc_msgs();

  if (nh.connected()) {
    Serial.println("Connected");
    
    chatter.publish( &pc_msgs );
  } else {
    Serial.println("Not Connected");
  }
  nh.spinOnce();
  // Loop exproximativly at 1Hz
  delay(1000);
}