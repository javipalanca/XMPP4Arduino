/*
 * This project has been based on the XMPPArduino created by Adam Rudd, 
 * was modified and adapted by Jaime A. Rincon to be integrated into ESP32 devices.
 * https://github.com/adamvr/XMPPArduino
 * 
 * 
 * The MIT License (MIT)
 *
 *   Copyright (c) 2022 Jaime Andres Rincon Arango
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 *COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 */


// XMPP Reference
//https://mrbrijesh.wordpress.com/xmpp-and-chat-server-step-by-step/
//https://xmpp.org/extensions/inbox/auth-tokens.html
//https://xmpp.org/rfcs/rfc3921.html

#include "Config.h"

// Use WiFiClient class to create TCP connections
WiFiClient client;

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  doConnection();
  init_communication_with_server();

  presence_show(true);

  //

  //unsubscribe_presence("receiver1@192.168.1.20", "mbed@192.168.1.20", true);
  //subscribe_presence("receiver1@192.168.1.20", "mbed@192.168.1.20", true);

  //unsubscribe_presence("agg_1@192.168.1.20", "mbed@192.168.1.20", true);
  //subscribe_presence("agg_1@192.168.1.20", "mbed@192.168.1.20", true);

  //presence_status("receiver1@192.168.1.20", "On-line", true);
  // Create Node
  //sendTemplate("<iq type='set' from='mbed@192.168.1.20' to='receiver1@192.168.1.20' id='create1'> <pubsub xmlns='http://jabber.org/protocol/pubsub'> <create node='embed_node'/> </pubsub> </iq>", 0);
  //delay(300);
  //read_server_1();
  //Serial.println("----------------------------------------------------------------");
  // Nodes in Service Discovery
  //sendTemplate("<iq type='get' from='mbed@192.168.1.20' to='receiver1@192.168.1.20' id='info3'> <query xmlns='http://jabber.org/protocol/disco#embed_node' node='http://jabber.org/protocol/commands'/> </iq>", 0);
  //sendTemplate("<iq type='get' from='mbed@192.168.1.20' to='agg_1@192.168.1.20' id='info1'> <query xmlns='http://jabber.org/protocol/disco#info'/> </iq>", 0);
  //sendTemplate(pub_sub_template, 0);
  //delay(300);
  //read_server_1();
  //Serial.println("----------------------------------------------------------------");

}


void loop() {


  char buf[30];

  char *message2send = "Hola Agente receiver1 ";
  char *data2concatenate = "-";
  char cstr[16];

  strcpy(temp_buffer_0, agent_name);
  strcat(temp_buffer_0, "@");
  strcpy(temp_buffer_1, temp_buffer_0);
  strcat(temp_buffer_1, xmpp_server);

  for (int i = 0; i < 3; i++) {
    itoa(i, cstr, 10);
    data2concatenate = cstr;
    strcpy(buf, message2send);
    strcat(buf, data2concatenate);
    Serial.print("Send message to ");
    Serial.println(temp_buffer_1);
    send_msg(temp_buffer_1, buf);
    delay(1000);
  }
  Serial.println("Receive Messages: ");
  for (int j = 0; j < 10; j++) {
    xmpp_process_input();
    delay(2);
  }
  
  Serial.println("Close XMPP Communication...");
  sendTemplate(close_template, 0);
  read_server_1();
  Serial.println("----------------------------------------------------------------");
  while (1) {}
}
