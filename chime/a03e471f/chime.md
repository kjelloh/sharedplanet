# Todo: Darwinet - Consider to use MQTT and the mqtt_cpp  github C++ library for darwinet n2n messaging?

```#a03e471f``` *As of 2017-11-02 17:07*

[mail plain/text](mail.txt)

{% raw %}
It seems the mqtt protocol is very popular and gains more and more good support - so maybe its time to really try to use it for Darwinet N2N messaging to get going with the implementation and testing?

1) The github C++ “mqtt_cpp” seems to live here (<https://github.com/redboltz/mqtt_cpp>)?

> “  
> *mqtt_cpp is a header only library. It requires C++14 and the Boost Libraries 1.57.0 or later (See #33). The only feature that mqtt_cpp uses C++14 is binary literals. e.g.) 0b00001111

> You may be able to use mqtt_cpp on C++11 with binary literal extension environment such as g++ and clang++.

> Add mqtt_cpp/include to your include path. Then, include mqtt_cpp.hpp and/or mqtt_server_cpp.hpp as follows:*  
> "

2) Consider the talk CppCon 2017: Takatoshi Kondo “mqtt_cpp: Boost.Asio based mqtt communication library” on this mqtt library (<https://www.youtube.com/watch?v=zy_sUBt3wc0>)?

==&gt; It seems an mqtt network is made up of clients and brokers (servers)?

![](<MQTT ClientBroker Topic publish and listen model.tiff>)

==&gt; mqtt_cpp seems to support TCP/IP and web sockets with or without TLS?

![](<MQTT 3 supports TCPIP and WebSockets with optional TLS .tiff>)

==&gt; It seems using the mqtt_cpp library writing mqtt messaging code becomes quite easy?

![](<Boost.Asio based mqtt communication library example.tiff>)

==&gt; It seems one creates clients connected to a broker?

==&gt; Then the broker dispatches messages to “topics” to all subscribing client based on its Client Id?

...

3) Consider to use mqtt as Darwinet node-2-node protocol to develop the basic Darwinet network?

…

4) Consider to also look into IBM local web browser javascript IoT graphical programming with MQTT support (<http://noderedguide.com/tag/mqtt/>)?

![](<Receiving and parsing an MQTT message sent as a JSON string.tiff>)

…

…

Consider to use this information on mqtt protocol, C++ support and community to see if and how we can use it to make Darwinet come alive?

{% endraw %}
