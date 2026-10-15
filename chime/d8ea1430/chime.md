# Todo: Programming - Consider to allow protocol Engine to apply Model Specialisation that also acts as additional Value Provider for model defined values?

```#d8ea1430``` *As of 2016-02-20 14:11*

[mail plain/text](mail.txt)

{% raw %}
A question about design of Model Based Value Provider using Encoder has been how to define what to build. Should we provide a Model that uniquely defines what to build and have the Value Provider be target-agnostic? Or should we provide a class model and require the Value Provider define what to build?

1) Consider to go for Specialised Model Value Provider Target Agnostic design?

==&gt; Consider to allow the model to define specialisations to define each unique target to build (inheritance style)?

==&gt; The Encoder may then be provided with the general protocol data model plus a path to the specialised target to build (model path)?

==&gt; Consider to enable the Model to also act as Value Provider (e.g. for constant values like Message ID and target specific values)?

==&gt; The Value Provider then is used to provide dynamic values (dynamic for the target built)?

Example: The iPOS Protocol data Encoding may be defined as General iPOS Messages specialised for OP_INIT, SR_CARD_READ etc.

==&gt; The General model plus a model path “ipos.cdoiPOS_SA.OP_PAY” then defines the specialised iPOS Message for OP_PAY (specialising cdoMSG as coOP_PAY)

==&gt; The Specialised cdoiPOS_SA (model name OP_PAY) then specialises header elements like pdoType with coast value for this type of message.

==&gt; The Encoder uses both the explicit Value Provider AND the Model as value providers (The model takes precedence, i.e. if model provides a value the explicit value provider is not asked)

Value Provider&#91;state&#93; ---(2)----|

|

Data Model&#91;model path&#93; --(1)----|

| |

| |

| v

-------------------&gt; Encoder ----&gt; Target

==&gt; The Encoder asks the Data Model for element models using model paths?

==&gt; The Encoder asks for element values using instance paths?

2) This may fit very well with a State Based Value Provider?

==&gt; The Value Provider is State Based to allow providing specialised values depending on “state”?

==&gt; The Data Model Path defines what specialised target to build (and may also be seen as a kind of “state”)?

3) Consider to compare this design with the use implement in Testbench?

==&gt; The Testbench already implements state based value provider?

==&gt; The TestBench implement model specialisation using an in-code “fix” to know what is being built and apply hard-coded knowledge (e.g. iPOS Header and iPOS Message are built differently)

==&gt; Consider to elaborate on what it would take to add Model Specialisation to the Testbench iPOS Message builder framework?

a) iPOS Interface Definition must define specialised top-containers (i.e. cdoiPOS_SA, doSA_iPOS specialised for DI_INFO, OP_xxx, SR_xxx)

b) The Specialisation must also differentiate between solicited and unsolicited SR_xxx?

c) Value Providers and Receivers must be modified to bind to the new model paths (e.g. “cdoiPOS_SA.cdoOP_PAY.Element_xxx” could now become “OP_PAY.Element_xxx”?

==&gt; Seems we may get away with only replacing paths to iPOS Header elements with specialised model paths?

==&gt; But the upside with applying general change is that the path used for specialisation (e.g. “cdoiPOS_SA.OP_PAY”) would result in this path being the prefix to all Value Requests?

“cdoiPOS_SA.pdoType”  becomes “cdoiPOS_SA.OP_PAY.pdoType”

“cdoiPOS_SA.cdo_OP_PAY.x”  becomes “cdoiPOS_SA.OP_PAY.cdoOP_PAY.x” (Confusing?)

3) Compare how this seem to work well with Protocol Stacks Encoding (where one value is the data vector provided from the uppstack layer)?

Uppstack Frame —&gt; Value Provider&#91;state&#93; ---(2)----|

|

Data Model&#91;model path&#93; --(1)----|

| |

| |

| v

-------------------&gt; Encoder ----&gt; Downstack Frame

…

Consider to try this out in code as a proof of concept to see if it holds water?

...

{% endraw %}
