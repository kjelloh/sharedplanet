# Todo: Consider to write an article on number representations and conversions (e.g., 2^10000 to decimal through big BCD)?

```#7fdf3b60``` *As of 2017-02-16 13:09*

[mail plain/text](mail.txt)

{% raw %}
Triggered by the article (<https://www.linkedin.com/pulse/multi-core-bcd-bignum-strategies-h-ricco-bucher-phd>), where I posted a comment that was received as being to ”dry”, it seems to be it would be fun to try to explain number representations in an article of my own?

1) Consider this page provides a good base to describe different number representations from a binary programming perspective (<https://chortle.ccsu.edu/AssemblyTutorial/Chapter-07/ass07_18.html>)?

2) Consider to really understand the ”” article and relate it to base encoding transformation algorithms (<https://www.linkedin.com/pulse/multi-core-bcd-bignum-strategies-h-ricco-bucher-phd>)?

3) Consider to transform one base representation (e.g. binary) to another (e.g. decimal) using only C++ available numeric types we need to ”build up” (we can’t ”tear down”)

==&gt; Consider transforming 2^10000 to its decimal representation we cant use the divide-by-new-base approach (as the value to divide is to big to be represented by a C++ type)?

> ```
> number = 247
> 247 div 16 = 15 r 7    so  digit[ 0 ] = 7

> number =  15
>  15 div 16 =  0 r 15   so  digit[ 1 ] = F
>                            ("15" is in base 10,
>                             "F" is the hex digit)

> Result: 24710 = 0xF7
> ```



==&gt; Consider instead we may build up the result instead (reversing the divide-by-base algorithm)?

0: Begin with 1\*2^0 = decimal 1

1: Shift in the next binary digit (in this case 0): 1\*2^1 + 0 = decimal 1\*2 = 2

Repeat 1 until we have the binary representation 1\*2^10000 = decimal x

Note: The ”Multiply by other base” must be implemented on our big-number-type in terms of new-base digit shifting and C++ numeric type operation!

==&gt; Consider a Big BCD ”multiply by 2” algorithm based only on decimal-digit-shift and C++ type non-precision-loss operations?

==&gt; Consider a representation using an std::vector&lt;Digit&gt; for the big decimal number (Digit = int 0…9)?

==&gt; A ”Multiply by 2” may then be implemented as:

0: Multiply first digit by 2 = {carry, new_digit} (e.g. 2\*9 = {1,8}

1: Continue to multiply the next digit with 2 and add the carry from the previous multiplication.

3: Repeat 1 until all the digits are multiplied by 2 and carry added.

==&gt; Note: Each digit operation may be parallelized as ”adding the carry” commutes (may be done as one chained operation when each multiplication is done)?

1234567

\* 2

---------

4 00000010

2 00000100

0 00001000

8 00000000

6 00000000

4 00000000

2 00000000

---------- |

2468024 |

| |

2468024 |

00000010 |

00000100 |

00001000 &lt;---/

00000000

00000000

00000000

+ 00000000

----------

2469134

==&gt; Consider this is a general algorithm to convert from any base to any other base?

Given number represented as Digits in Base_A to be converted into Digits in Base_B.

0: Convert first Digit in Base_A to Digit in Base_B with the same value.

1: Shift in the next digit in Base_A number and multiply Base_B digit with Base_A and store as Base_B pair {carry, digit}

3: Repeat 1 until all digits in Base_A number has been processed (resulting in a vector of {carry,digit} for each digit in Base_B number)

4: Finalize by adding-with-carry all the {carry-digit} results for Base_B number.

0: Multiply first digit by 2 = {carry, new_digit} (e.g. 2\*9 = {1,8}

1: Continue to multiply the next digit with 2 and add the carry from the previous multiplication.

3: Repeat 1 until all the digits are multiplied by 2 and carry added.

4) Consider to implement a C++ algorithm that implements a big-number-base-transformation algorithm using parallelized shift-A-mupliply-B idiiom?

==&gt; Consider to define a function {Base_B Carry, Base_B Reminder} = append_Digit_A(Base_A Digit, Base_B Digit)?

==&gt; Consider in this way we may transform (lift) two a Digit_A and a vector&lt;B_Digit&gt; into vector&lt;pair&lt;Carry_B, Remained_B&gt;&gt; that represents extending Base_A number and correspondingly multiplying Base_B number?

==&gt; Consider to extend this to another function G: (vector&lt;Digit_A&gt;, Digit_A, vector&lt;Digit_B&gt;) —&gt; (vector&lt;Digit_A&gt;, vector&lt;Digit_B&gt;) that we may use to transform the whole big number vector&lt;Digit_A&gt; to big number vector&lt;Digit_B&gt;?

==&gt; Consider to implement a semantics that enable us to use a Monad to bind each digit append Monoid (and then call the composed transformation with the vector&lt;Digit_A&gt; number to get vector&lt;Digit_B&gt;)?

==&gt; Also consider to select the Monoidal operations so that they may be executed in parallell?

…

…

Consider to elaborate on this idea to provide a fun explanation of number representations and also understand functional programming and ”Async Monad”?

...

{% endraw %}
