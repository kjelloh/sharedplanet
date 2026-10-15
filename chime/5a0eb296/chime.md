# Todo: Tha, Elm and Immer - Consider the C++ Immer immutable data structures based text editor "ewig" is in fact implementing the Elm model, view, update?

```#5a0eb296``` *As of 2017-07-04 09:14*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good to understand how to use immutable data structures by studying the text editor ”ewig” example and relate it to the Elm run-time model, view, update idiom?

1) The ”ewig” editor seesm to live here (<https://github.com/arximboldi/ewig>)?

2) Consider to understand the ewig::run main loop in relation to teh Elm run-time idiom?

> int run(const char\* fname)  
> {  
> auto state = application{load_buffer(fname), key_map_emacs};  
> auto ui = tui{};  
> draw(state, ui.size());

> while (auto new_state = update(state, ui.next())) {  
> state = \*new_state;  
> draw(state, ui.size());  
> }

> return 0;  
> }

==&gt; Application seems to be what Elm calls ”the model”?

> struct application  
> {  
> buffer current;  
> key_map keys;  
> key_seq input;  
> immer::vector&lt;text&gt; clipboard;  
> immer::vector&lt;message&gt; messages;  
> };

==&gt;

3) It seems to depend on the ncurses library that lives here (<https://www.gnu.org/software/ncurses/>)?

==&gt; It (ncurses) seems to be a library to write GUI like front-ends on terminal based console windows (<https://en.wikipedia.org/wiki/Ncurses>)?

> ”*ncurses (new curses) is a programming library providing an application programming interface (API) that allows the programmer to write text-based user interfaces in a terminal-independent manner. It is a toolkit for developing "GUI-like" application software that runs under a terminal emulator. It also optimizes screen changes, in order to reduce the latency experienced when using remote shells.*"

==&gt;

4) It seems ncurses library can be installed onto Mac OS using brew?

> kjell-olov-hogdahls-macbook-pro:Cellar kjell-olovhogdahl$ **brew** install **homebrew/dupes/ncurses**  
> Updating Homebrew...  
> ==&gt; **Auto-updated Homebrew!**  
> Updated 1 tap (homebrew/core).  
> ==&gt; **New Formulae**  
> dwarf tokei  
> ==&gt; **Updated Formulae**  
> apache-flink frei0r packetbeat  
> aws-sdk-cpp git-lfs paket  
> awscli glibmm pegtl  
> bazel grpc platformio  
> bro gtkmm3 poppler  
> consul iperf3 rom-tools  
> crowdin liblcf s3cmd  
> elasticsearch logstash teleport  
> fibjs lxc tinyxml2  
> filebeat mame typescript  
> fluent-bit metricbeat unbound  
> fmt nats-streaming-server

> Warning: homebrew/dupes was deprecated. This tap is now empty as all its formulae were migrated.  
> ==&gt; **Tapping homebrew/dupes**  
> Cloning into '/usr/local/Homebrew/Library/Taps/homebrew/homebrew-dupes'...  
> remote: Counting objects: 5, done.  
> remote: Compressing objects: 100% (5/5), done.  
> remote: Total 5 (delta 0), reused 3 (delta 0), pack-reused 0  
> Unpacking objects: 100% (5/5), done.  
> Tapped 0 formulae (30 files, 23.9KB)  
> Warning: Use ncurses instead of deprecated homebrew/dupes/ncurses  
> ==&gt; **Downloading <https://homebrew.bintray.com/bottles/ncurses-6.0_3.el_capitan.bo>**  
> ==&gt; **Downloading from <https://akamai.bintray.com/70/70443e997a0964193949192a4d764>**  
> ######################################################################## 100,0%  
> ==&gt; **Pouring ncurses-6.0_3.el_capitan.bottle.tar.gz**  
> ==&gt; **Using the sandbox**  
> ==&gt; **Caveats**  
> This formula is keg-only, which means it was not symlinked into /usr/local,  
> because macOS already provides this software and installing another version in  
> parallel can cause all kinds of trouble.

> If you need to have this software first in your PATH run:  
> echo 'export PATH="/usr/local/opt/ncurses/bin:$PATH"' &gt;&gt; ~/.bash_profile

> For compilers to find this software you may need to set:  
> LDFLAGS: -L/usr/local/opt/ncurses/lib  
> CPPFLAGS: -I/usr/local/opt/ncurses/include

> ==&gt; **Summary**  
> 🍺 /usr/local/Cellar/ncurses/6.0_3: 2,820 files, 8.9MB  
> kjell-olov-hogdahls-macbook-pro:Cellar kjell-olovhogdahl$

==&gt; The ncurses seems to have been installed to ”**/usr/local/Cellar/ncurses/6.0_3**”?

> kjell-olov-hogdahls-macbook-pro:ncursesw kjell-olovhogdahl$ pwd  
> /usr/local/Cellar/ncurses/6.0_3/include/ncursesw  
> kjell-olov-hogdahls-macbook-pro:ncursesw kjell-olovhogdahl$ ls  
> curses.h cursesp.h etip.h ncurses.h term_entry.h  
> cursesapp.h cursesw.h form.h ncurses_dll.h termcap.h  
> cursesf.h cursslk.h menu.h panel.h tic.h  
> cursesm.h eti.h nc_tparm.h term.h unctrl.h  
> kjell-olov-hogdahls-macbook-pro:ncursesw kjell-olovhogdahl$

==&gt; For some reason the ”ewig” includes ”ncursesw/ncurses.h"

> extern "C" {  
> #include &lt;ncursesw/ncurses.h&gt;  
> }

==&gt; Which seems to suggest we need to set the Include path to point at ”**/usr/local/Cellar/ncurses/6.0_3/include**” \*sigh\*?

…

Consider to elaborate and possibly show that the Immer based ewig editor does in fact implement the Elm run-time idiom?

...

{% endraw %}
