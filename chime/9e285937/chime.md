# Todo: Darwinet - Consider to design a Darwinet for secure and low-foot-print IoT "swarms"?

```#9e285937``` *As of 2016-04-04 22:26*

[mail plain/text](mail.txt)

{% raw %}
How could Darwinet provide the services required for safe and cost-effective IoT and how could we design a C++ Darwinet Implementation for low-footprint embedded system applications?

1) Consider to use this article to find leads into where IoT are as of now (<http://www.ics.com/blog/qt-and-internet-things-part-2#.VwJ5c3QYFcI.twitter>)

==&gt; This article seem to present a good list of contemporary protocols?

> *“Key Protocols, Hardware Technologies, Software Frameworks*  
> *...  
> **CoAP** (6), or Constrained Application Protocol, is a software protocol for simple devices to communicate over the Internet. Standardized as RFC 7252, …

> *

> ***MRAA** (8) is a standardized API for input/output on a number of popular hardware platforms. Supported protocols include GPIO, I2C, SPI, PWM and serial UARTs. …

> *

> ***BTLE** is Bluetooth Low Energy (sometimes referred to as Bluetooth LE, BLE or Bluetooth Smart). …

> *

> ***OMA LWM2M** (9) is the Open Mobile Alliance Lightweight Machine to Machine protocol for IoT device management. …*

> ***Windows 10 IoT Core** (10) is a version of Windows 10 that is available free for "makers" for use in small footprint, low-cost devices and IoT. ...*

> ***Linux** is also a popular embedded operating system for IoT...*

> *… **Zephyr** (11), an open source real-time OS for IoT devices that was announced in February 2016 by The Linux Foundation …"*

==&gt; This article seem to present a good list on popular hardware?

> *“Popular Hardware Platforms*  
> *...*  
> ***Arduino** (2) is an open source hardware and software platform based on Atmel AVR microcontrollers and ARM processors. ...*

> ***Raspberry Pi** (3) is a family of low-cost (as little as $5) credit card-sized single-board computers that use a Broadcom system on a chip (SOC). … has a quad-core 64-bit ARM Cortex-A53 CPU, a VideoCore IV dual-core GPU ...*

> ***BeagleBoard** and **BeagleBone** (4) are low-power open-source hardware single-board computers produced by Texas Instruments. They use an ARM Cortex-A8 CPU and can Linux or Android.*

> ***Intel Galileo** (5) is an Arduino-certified development board based on the Intel x86 architecture. It uses an Intel Quark X1000 400 MHz CPU and …" *

> *"References*  
> *1. The Internet of Things: What Is It and Why Should I Care?, Qt World Summit 2015 presentation, last accessed 1 Mar 2016, <https://youtu.be/9mXlmgWCgcA>*  
> *2. Arduino Project, website, last accessed 1 Mar 2016, <http://www.arduino.cc/>*  
> *3. Raspberry Pi Project, website, last accessed 1 Mar 2016, <http://www.raspberrypi.org>*  
> *4. BeagleBoard and BeagleBone, website, last accessed 1 Mar 2016, <http://beagleboard.org/>*  
> *5. Intel Galileo, Product Overview, last accessed 1 Mar 2016, <http://www.arduino.cc/en/ArduinoCertified/IntelGalileo>*  
> *6. Constrained Application Protocol, website, last accessed 1 Mar 2016, <http://coap.technology/>*  
> *7. Cantcoap CoAP Implementation, project github repository, last accessed 1 Mar 2016, <https://github.com/staropram/cantcoap>*  
> *8. MRAA Low Level Skeleton Library for Communication on GNU/Linux platforms, documentation website, last accessed 1 Mar 2016, <http://iotdk.intel.com/docs/master/mraa/>*  
> *9. OMA Lightweight M2M Device Management Specification, website, last accessed 1 Mar 2016, <http://openmobilealliance.hs->[sites.com/lightweight-m2m-specification-from-oma](http://sites.com/lightweight-m2m-specification-from-oma)*  
> *10. Windows 10 IoT Core, product website, last accessed 1 Mar 2016, <http://dev.windows.com/en-us/iot>*  
> *11. Zephyr Project, website, last accessed 1 Mar 2016, <http://www.zephyrproject.org/>*  
> *12. QtSerialBus, git repository, last accessed 1 Mar 2016, <http://code.qt.io/cgit/qt/qtserialbus.git/>"*

2) Consider to use their gitbook on embedded C++ programming for leads to embedded darwinet library (<https://arobenko.gitbooks.io/bare_metal_cpp/content/>)?

==&gt; Exclude Dynamic Memory Management (<https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/dyn_mem.html>)?

==&gt; Warning: Requires code that can handle nullptr return instead of std::bad_alloc throw (e.g. can inject problem into third party library code not designed for nullptr returns on new)

==&gt; Exclude Excpetion Handling (<https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/exceptions.html>)

==&gt; Warning: May require implementation of residue __throw_xxx functions put in place by compiler (or libraries)

==&gt; Exclude RTTI (<https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/rtti.html>)

==&gt; Warning: typeid operator, dynamic_cast and overloading will not work.

==&gt; Q: Will boost::variant work as replacement (note no dynamic memory, exception handling and RTTI may render this impossible)?

==&gt; Exclude the standard library (<https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/nostdlib.html>)

==&gt; Warning: Requires explicit implementation of startup-code (e.g. initialisation and call of main-function that normally is provided by C++ runtime)

==&gt; Exclude static object destruction by mailing main an eternal loop (never return) (<https://arobenko.gitbooks.io/bare_metal_cpp/content/compiler_output/static.html>)

==&gt; Warning: static objects may require explicit implementation of compiler-generated "guard-acquire" and "guard-release” calls (thread safe static data).

==&gt; Consider to implement assert() (<https://arobenko.gitbooks.io/bare_metal_cpp/content/basic_needs/assertion.html>)

==&gt; Semes like a way to write “wining code” as replacement for using exceptions?

==&gt; Consider to delve into these leads on serialisation (<https://arobenko.gitbooks.io/bare_metal_cpp/content/basic_needs/serialisation.html>)

==&gt; Consider to relate this to the Protocol DSL proposal (See “Todo: Programming - Consider to design C++ Template Domains Specific Languages to design FSM Protocol Engines and Element Table Message Encodings?”)

==&gt; Sidenote: This book said nothing about multi-threading or parallel design on multi-core platforms?

…

Consider to delve deeper into this aspect of designing Darwinet as a framework for IoT “swarms”?

...

{% endraw %}
