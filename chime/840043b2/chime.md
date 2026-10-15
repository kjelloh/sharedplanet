# Todo: Tha C++ Type System - Consider an enum is in fact the distribution in time of an array distributed in space?

```#840043b2``` *As of 2018-05-19 13:07*

[mail plain/text](mail.txt)

{% raw %}
It seems an enum and an array may be each others duality in space versus in time?

-1) It even seems the duality extends to Tha itself distributed in time or in space?

==&gt; Consider an PRODUCT in space becomes a SUM in time (values at a memory locations (at specific time) becomes values at points in time (at some location in space) and vice versa)?

==&gt; An example is streaming of data (Each data in space becomes an event in time where the event is the SUM type of the indexed values in space)?

==&gt; Consider a SUM in space becomes a PRODUCT in time (values in time (at some location in space) becomes values at points in space (at a specific point in time) and vice versa)?

==&gt; An example is a datalog (events in time is made into log in space where each location in space in the log corresponds to a time with a value from the SUM type)?

1) Consider an enum is a type defining an array of values indexed by name and located in time (one value at each point in time)

==&gt; Consider the enum defines an array of values indexed by name?

==&gt; Consider an enum can hold any of these values at any point in time?

...

2) Consider an array is type defining indexed values located i (memory) space?

==&gt; Consider the array defines an array of values indexed by integer?

==&gt; Consider an array can hold any value defined by the value type at any location in (memory) space?

…

3) It seems generally a SUM defines a distribution in time while a PRODUCT defines a distribution in space?

==&gt; A **SUM** Meta-value instance can hold **one value** of the SET of values at **any point in time**?

==&gt; A **PRODUCT** Meta-value instance can hold **one value** of the SET of values at **any location in space**?

…

4) It seems in C++ an int array and an int enum is each others dualities in time and space?

==&gt; An int enum type defines a vector of singleton types from the host SET int indexed by name with a value instance distributing those options in time?

==&gt; An array type defines a vector of values from the

meta-3 enum

meta-2 enum : int enum_type {name_1, name_2, name_3…}

&lt;Distributed in time&gt;

**name_1**

meta-1 enum_type x { **name_2** } // Any enum type member at a point in time

**name_3**

**…**

meta-3: array

meta-2: array : int array_type { 0, 1, 2, 3, …}

&lt;distributed in space&gt;

**0 1 2 3 …**

meta-1: array_type y {14, 27, -3, 4, ...}

…

Consider to delve into this idea of SUM being the distributed-in-time duality of PRODUCT distributed in space (and vice versa)?

{% endraw %}
