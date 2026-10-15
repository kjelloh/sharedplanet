# Todo: Programming - Consider to define a C++ front-end, core, backend base units with totally header-isolation of each others types?

```#69eb53c5``` *As of 2016-07-27 20:26*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to implement the front-end-core-backend idiom as C++ translation units with totally isolated headers (no leakage of types between them)?

1) Consider to define the Front, Core, backend idiom in terms of type isolations?

==&gt; Consider these h-files to be totally isolated from platform (e.g., no windows, Linux or MacOS types)?

FrontEnd.cpp &lt;— FronEnd.h —&gt; FrontEndImpl.h -&gt; FrontEndImpl.cpp

^  ^

|----------------------  |

|  |

Core.cpp &lt;— Core.h -&gt; CoreImpl.h -&gt; CoreImpl.cpp

^  ^

|----------------------  |

|  |

BackEnd.cpp &lt;— BackEnd.h -&gt; BackendImpl.h -&gt; BackendImpl.cpp

^ \\___________________________________/  ^

|  |  |

|  Isolated  |

|   |

---------------------------------------------------------------------------

|

Build Environment

Platform

…

Consider to elaborate and try out this idiom for cpp/h file isolation based on FrontEnd, Core, backEnd architecture?

...

{% endraw %}
