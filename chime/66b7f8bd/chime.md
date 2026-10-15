# Todo: C++ User Group - Consider talks to give at first Meeting 28 September?

```#66b7f8bd``` *As of 2016-06-22 17:04*

[mail plain/text](mail.txt)

{% raw %}
So, what C++ related topics may I consider to give as a talk at the first C++ User Group Event 28 September?

1) Consider ”Why C++ Strings Sucks and how to Fix Them”?

==&gt; A C++ String is an array of character, right? - Wrong!.  
==&gt; s= ”Välkommen”; means s&#91;1&#93; == ’ä’; Right? - Wrong!  
==&gt; String ”Välkommen” is well defined and understood in flight, right? - Wrong!  
==&gt; IRL Text + Character Set Encoding ==&gt; Array of Code Points.  
==&gt; All Code Points are of the same size, right? - Wrong!  
==&gt; Character Set Hell for non English Texts  
==&gt; Not even ASCII is ”safe” (The 7-bit Swedish encoding Card Payment issues)  
==&gt; Even EBCDIC is still alive  
==&gt; Code Point Adaptor Iterator to rescue?  
==&gt; No, An adaptor Iterator is not a true Iterator for the same reason the Bitfield Iterator is not.  
==&gt; Nieblers Range Adaptors to the rescue?  
==&gt; Todo: Try it out to state an opinion?  
==&gt; Widestring to the rescue, right? - Wrong.  
==&gt; We need a true Code Point Array Text class? - Maybe  
==&gt; Implement using raw Code Points (memory inefficient)  
==&gt; Implement as Range Adaptor (run-time inefficient)?  
==&gt; Implement as compile-time Code-Point-Aware template class?  
==&gt; Enable compile-time encoding optimization (char array for englioeh text, wide char array for western languages and full Unicode Code Point for Chinese Text)?  
==&gt; But not even C++ String Literals are Encode Specified at compile-time (depend on source file encoding)?  
==&gt; Todo: Test ”Välkommen” in Linux Source File?  
==&gt; -”- in Windows ASCII Source File (non UTF-8 source file)?  
==&gt; Three levels of Text Classes (client encode awareness, object encode awareness, object text awareness)?  
==&gt; Most existing String classes requires client-encode-awareness?  
==&gt; Encode-aware-string objects allows text sameness API between objects using same encoding.  
==&gt; Text-aware objects allows text sameness APIs regardless of encoding?  
==&gt; Compile-time encode awareness  
==&gt; Encode aware versus Encode unaware C++ string literals  
==&gt; Run-time Encode Awareness Failures  
==&gt; Mail with faces or question marks - Why  
==&gt; Text Files with question marks - why?  
...  
==&gt; Run-time encode awareness  
==&gt; BOM encoding of text files  
==&gt; Windows API Unicode UTF-16 implicit requirement.  
==&gt; Web APIs Encoding-definition-element (MIME-style)  
==&gt; ASCII-endcoded header defines encoding followed by encode-specific body.  
==&gt; Card Payment ISO-8583 text encode freedom heaven and hell.  
==&gt; Adding run-time encoding markers using non intrusive data?  
==&gt; White-space encoding of Code Point Set and encoding?  
==&gt; Open Source Initiative?  
==&gt; Contribute!  
==&gt; Thanks!

2) Consider ”The Meaning of Life of C++ objects”?

==&gt; Consider the meaning of constructor and destructor?  
==&gt; Consider the meaning of original and copy (which instance is the live one)?  
==&gt; Consider the meaning of a moved-from object?  
==&gt; Consider what it means to be copy-constructible (clone-able)?  
==&gt; Consider what it means to be assignable (who am I after assignment)?  
==&gt; Consider the meaning of life and the RAII (What do I take with me into the grave)?  
==&gt; Consider the difference between ”dead" and ”living” (entity) objects?  
==&gt; Consider state-full objects versus pure functions (no state nor history)  
…  
…

Consider to add proposals for a 15 minute talk at the first C++ User Group Meeting?  
...

{% endraw %}
