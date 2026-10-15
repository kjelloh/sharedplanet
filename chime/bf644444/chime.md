# Todo: Programming - Seem KeyPath&lt;&gt; constructors in c++11 should use std::initializer_list&lt;KeyNode&gt;?

```#bf644444``` *As of 2015-12-02 01:50*

[mail plain/text](mail.txt)

{% raw %}
When reading about std::initializer_list in c++11 i come to think they seem to be very good for KeyPath&lt;&gt; constructors?

1) Here seem to be a good example of std::initializer_list (<https://en.wikipedia.org/wiki/C%2B%2B11>)?

```
class SequenceClass {
public:
    SequenceClass(std::initializer_list<int> list);
};
```

```
SequenceClass some_var = {1, 4, 5, 6};
```

2) Using std::initialiser_list we should be able to replace current construction using operator+ ?

oipos::c_InstanceTagPath untyped_SR_SEND_HOST_Path

= oipos::c_InstanceTagPath(oipos::eiPosMessageType_Undefined) + ipos::cdoiPOS_SA + ipos::cdoSR_SEND_HOST;

Would become

oipos::c_InstanceTagPath untyped_SR_SEND_HOST_Path{oipos::eiPosMessageType_Undefined, ipos::cdoiPOS_SA, ipos::cdoSR_SEND_HOST}

==&gt; By applying the “Uniform Initialisation” allowing mixed types matched to parameters?

==&gt; Or at least provide the path nodes in a list.

oipos::c_InstanceTagPath untyped_SR_SEND_HOST_Path(oipos::eiPosMessageType_Undefined) + {ipos::cdoiPOS_SA, ipos::cdoSR_SEND_HOST}

==&gt; Using an operator+ accepting an std::initialiser_list?

…

Consider to elaborate on this c++11 feature and see what enhancements we may provide to the KeyPath library?

...

{% endraw %}
