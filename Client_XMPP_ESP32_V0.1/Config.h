

#include "Templates.h"
#include "Base64.h"
#include <WiFi.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define artifact_name "t_watch"
#define artifact_password "mirror"

const int httpPort = 5222;
char* ssid_names[3] = {"****", "****", "****"}; //SSID Net
char* xmppServer[4] = {"000.000.000.000", "000.000.000.000", "000.000.000.000", "000.000.000.000"}; // XMMPP Server, IP addres.
char* pass_names[3] = {"****", "*****", "*****"}; // Net Password
char* agents_names[2] = {"agent1", "phone_agent"};

char* ssid     = ssid_names[0];
char* password = pass_names[0];
char* xmpp_server = xmppServer[3];
char* agent_name = agents_names[0];

boolean create_new_account = true;
boolean xmpp_verbose = false;

char temp_buffer_0[20];
char temp_buffer_1[20];


int value = 0;
