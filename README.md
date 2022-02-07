## Arduino_XMPP_IoT

Introduction
------------

Arduino-XMPP-IoT is a C-based example, which will allow communication of an ESP32 with an XMPP server. [Prosody](https://prosody.im/download/start) is recommended as XMPP server. An example of an XMPP server configuration using prosody is attached in this repository.


Limitations
-----------

This client library is somewhat restricted in what in can do. The major restrictions are as follows:
    
1. SASL-PLAIN authentication only
2. No SSL/TLS encryption on the stream

