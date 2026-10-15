# Todo: Meta Model - Consider how each Value is a member of the Set defined by declared Meta-value

```#61923d8d``` *As of 2017-06-05 15:58*

[mail plain/text](mail.txt)

{% raw %}
Consider what we can learn by focusing on the fact that each meta-layer value is itself a member of the Set of values defined by its declared meta-value?

1) Consider how each value relates to the Set defined by its meta-value?

> +1 (Meta Meta): name: value = Set {…}  
> |  
> ------------  
> | one of  
> v  
> 0 (Meta): name: value = Set {…}  
> |  
> ------------  
> | one of  
> v  
> -1 (DeFacto): name: value = Set {…}  
> |  
> ------------  
> | one of  
> v

2) Consider how each meta-value defines monoids on the defined Set (mathematical object)?

> 0 (Meta): name: value = Set {…} &lt;--  
> | | monadic operations  
> ------

==&gt;

3) Consider each meta-layer consists of declarations and definitions?

> | Meta n Declaration  
> | ------------  
> \* | |  
> 0 (Meta): name 1 - 1 value ---- Set {Possible Meta n values...}  
> | 1 |  
> | ----|----|----------  
> | | \* | |  
> -1 (DeFacto): | | name 1 - 1 value | Meta n Definition  
> | ---------|----------  
> ------------

==&gt; Consider we can write a definition with its declaration to get a compact meta-model?

> … ...  
> |  | Definition  
> |  v  
> +1 (MetaMeta): {name, meta-value, value = Set { … }&lt;-- }  
> ^  | | | monadic operations  
> |  | ------  
> -----------  |  
> | Declaration  |  
> |  -------------  
> |  | Definition  
> |  v  
> 0 (Meta): {name, meta-value, value = Set { … }&lt;-- }  
> ^  | | | monadic operations  
> |  | ------  
> -----------  |  
> | Declaration  |  
> |  -------------  
> |  | Definition  
> |  v  
> -1 (DeFacto): {name, meta-value, value = Set { … }&lt;-- }  
> ^  | | | monadic operations  
> |  | ------  
> ... ...

==&gt; It then seems a Declaration binds to a meta-value and a Definition selects a value from meta-value Set?

4) Consider functions are mappings between meta-value Sets?

> +1 (MetaMeta): {name, meta-value, value = Set { f: argument-definition -&gt; result-definition} }  
> ^ |  
> | |  
> ----------- |  
> |  ------------------------------------  
> |  | Definition({argument-name, meta-value}, expression-meta-value)  
> |  v

  
> 0 (Meta): {name, meta-value, value = Set { &#91;&#93;(argument){ expression }} }

> ^  |

> |  |

> -----------  |

> |  ----------------------

> |  | Definition(expression)

> |  v

> -1 (DeFacto): {name, meta-value, value}

==&gt; A functions meta-meta value is a pair of meta-value declaration that binds the argument name and result to a meta-value definition.

E.g., -1 (DeFacto): int f(int i) { return i\*i;}

> > +1 (MetaMeta): {name=”function", - , value = Set { f: defacto-definition1 -&gt; defacto-value2} }

> > ^  |

  
> > |  |

  
> > -----------  |

  
> > |  ----------------------

  
> > |  | Definition({{”i”, int}, {”result”, int}})

  
> > |  v

  
> > +/-0 (Meta): {name=”meta-f", meta-value=”function", value = Set { &#91;&#93;(int i){ int expression} } }

  
> > ^  |

  
> > |  |

  
> > -----------  |

  
> > |  ----------------------

  
> > |  | Definition(”i\*i")

  
> > |  v

  
> > -1 (DeFacto): {name=”f", meta-value = ”meta-f", value = &#91;&#93;(int i){i\*i}}



==&gt; The DeFacto level declares name ”f” to be meta-name ”meta-f" and defines it to be the ”i\*i” expression.

==&gt; The Meta level declares name ”meta-f” to be meta-meta-name ”function” an defines its mapping to be argument ”int i” and result ”int result”

==&gt; The meta-meta- level declares name ”function” to be a value with a Set of mappings of argument definition {meta-name, meta-value}

**…Ok, Getting there. But I suspect some gaps in the model still?**

==&gt; The function argument must be scoped to the function (So it is in effect a Meta Value Record with a members to declare argument and result)?

==&gt; The function definition must take an expression that may be bound to the argument name (renaming the argument should not brea the definition)?

...

5) Consider that we need the model to define a way to script all abstractions?

==&gt; Consider ”…” for Text value and 0…9 for numbers?

==&gt; Consider ”{ … }” for compositions?

6) Consider how the meta-lauers may ”look like” for the basic-abstractions we like all Meta-layers to provide?

==&gt; Consider how we may model the basic atomic meta-values?

==&gt; MetaNumber: Built in meta-value that initiates defacto numbers.

==&gt; Requires NO meta-meta-value.

==&gt; MetaText: Built in meta-value that initiates defacto texts.

==&gt; Requires NO meta-meta-value.

==&gt; MetaPOD: Built in meta-value that initiates defacto PODs (array of bytes)

==&gt; Requires NO meta-meta-value.

**==&gt; Consider how we may model the basic compositions?**

**==&gt; MetaArrayValue: Built In array of defacto values produced by single meta-value.**

**==&gt; Requires built-in meta-meta value that initiates MetaArrayValue from Meta Value.**

**==&gt; MetaValueArray: Built-in array of meta-values**

**==&gt; Requires built-in meta-meta value that initiates a MetaValueArray from a list of meta-values.**

**==&gt; MetaRecordValue: Built in array of defacto declarations**

**==&gt; Requires built-in meta-meta-value that initiates a MetaValueArray from a list of defacto declarations**

**==&gt; MetaValueRecord: Built in array of meta declarations**

**==&gt; Requires a built-in meta-meta-value that initiates a MetaValueRecord from a list of meta declarations**

**==&gt; MetaFunction: Built in mapping from one meta-value to another meta-value.**

**==&gt; Requires a built-in meta-meta-value that initiates a MetaFunction from a meta-value pair {meta-argument, meta-result}**

**...**

…

Consider to continue this line of reasoning to ge a final meta model we can implement in C++ code?

...

{% endraw %}
