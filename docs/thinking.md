# thinking

I find it productive and valuable to write down my thinking as I go along.

## 20261015

Described and committed the fix to write and read 'As of' date with a space after now written index hash.

## 20261014

So the domain_to_domain does not work for entry links.

* A link to another entry in the same domain will break when an entry is cloned to a new domain.
* I wonder what we can do about this?

Also, I know - We should actually make this development somewhere else?

* But now I am applying and testing it here so this has to be good enough.
* Also, the concept of domain entries with index based on hashing the entry heading could be something 'shared planet stuff' can develop and share?

Anyhow, it seems the 'domain_update intralink' is the thing where we can fix this?

* I made the operation 'intralink' a specific operation to adress linking between entries in the same domain.
* So this seem to be where we can (for now) make this operation work also for existing intra-links?

Let's look at [update_domain/update_domain.py](../update_domain/update_domain.py)?

* So this code is Vibe coded! So we first need to understand it.
* Where is the 'add link' or 'make into link' done?
  * It seems to be done in 'intralink_line'

```python
def intralink_line(
    line: str, where: str, own: str, md: Path, domain: str, index: TitleIndex, report: Report
) -> str:

```

  * It takes the 'line' and a 'where' and some stuff and returns a mutated line.
  * It applies a regex to analyze the line.

```regex
^\s*\[(?:\\.|[^\]\\])*\]\((?P<target>[^()\s]*)\)
```

  * Using [regex101.com](https://regex101.com) I can determine what it does.
  * Ok, so this matches an existing link!
  * Makes sense as it is named 'LINKED_RE'.
  * AHA! There is a 'broken link' detector here!

```python
    linked = LINKED_RE.match(rest)
    if linked:
        if (md.parent / linked["target"]).resolve().is_file():
            report.already_linked += 1
        else:
            report.broken.append(Reference(where, linked[0].strip(), "broken", linked["target"]))
        return line
```
  * So maybe we can instead make this into a 're-link' operation?
  * At first I imagined we can just remove the link and then re-link it with the existing mechanism?
  * But this will not work for links in general (links to web pages etc.)
  * So what we need to do is to detect if the lunk is a link to a domain entry?
  * If it is, remove the link and apply the add-link code?

First, where is the code that creates a link from a plain comment about '==> Also see ...'?

* We want to reuse the code that identifies links to domain entries from plain text comments.
* Then we can re-use this code on the linked caption to see if it now (still) links to an entry in the domain.
* This comes into play for entries that has moved to a new domain (e.g., by domain_to_domain)
* Hm, what does this code do?

```python

    REFERENCE_RE = re.compile(
        rf"^(?P<lead>[\s>*_]*{ARROW}\s*(?:{'|'.join(CUES)})\s*:?\s*)"
        rf"(?P<open>[{QUOTES}])(?P<rest>.*)$",
        re.IGNORECASE,
    )

    match = REFERENCE_RE.match(line)
    if match is None:
        return line
    rest = match["rest"]
    if not rest.strip(QUOTES + " \t"):
        return line

```

* It seems I need to see the actual regex from the concatenation?
  * Well OK. That was WAY too complicated!

Now the problem is that the code does to provide a mechanism to match a plain text refernce into parts we can reuse to look up a link to another heading in the same domain.

* The REFERENCE_RE matches to named groups 'lead','open' and 'rest'
* And the code uses 'rest' to figure out the 'caption' of the entry maybe referred to.
  * The code states that for a '==> Also see "bla bla bla"' the 'bla bla bla' may itself contain quotes of different types.
  * So we can't just match what is inside a "..."?
  * I wonder if this is true though?

Anyhow. We need some way to reuse linking from a title, heading or caption on the form ```==> Also see "some heading, title or caption" ```

*  I started to design a uch simpler regex on the most basic "==> Also see ..."

```regex
^.*(?P<que>\b(see|See))\s*\"(?P<caption>.*)\"
```

  * Group 'que' (any of the words 'see', 'See')
  * Group 'caption' anything between "...".
  * Now maybe this does not work if there are nested ""?

* I started to design a much simpler link-matcher.

```regex
\s*\[(?P<title>.*)\]\((?P<target>[^()\s]*)\)
```
  * Group 'title' as anything between ```[]````
  * Group 'target' as anything between tightly following ```()```
  * Do we need anything more fancy than that?

At this stage I took a pause and tried to do a plain fresh add from the _mail domain I already created with emls_to_domain.

* Because such a direct add dos NOT intralink anything it seems to work?

```sh
kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/sharedplanet % ./update_domain/update_domain.py intralink chime
usage: update_domain.py [-h] [--dry-run] {intralink} base_dir domain
update_domain.py: error: the following arguments are required: domain
kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/sharedplanet % ./update_domain/update_domain.py intralink . chime
FUZZY (1.00): chime/2927db2a/chime.md:40  "Todo: C++ Tha - What can we learn by applying Set +,\* and Exponential on each meta-level of the Tha meta model?" -> ab703745  Todo: C++ Tha - What can we learn by applying Set +,* and Exponential on each meta-level of the Tha meta model?
FUZZY (0.99): chime/3187c1e1/chime.md:10  "Todo: Power Feeder - Consider to use a cycloidal gear box and multicopter brushless motor as for high torque robotic actuators to drive wood through a table saw?" -> cc8427d2  Todo: Power Feeder - Consider to use a cycloidal gear box and multicopter brushless motor for high torque robotic actuators to drive wood through a table saw?
FUZZY (1.00): chime/34607bde/chime.md:10  "Todo: Consider the "best" way to buy a Mafell Milling motor FM 1000 PV-WS (1000W with PV control and quick tool changer)?" -> 22cf1801  Todo: Consider the "best" way to buy a Mafell Milling motor FM 1000 PV-WS (1000 W with PV control and quick tool changer)?
FUZZY (0.96): chime/36d4c8ae/chime.md:75  "**Todo: Programming - Consider to use Boost config headers as a "standard" pre-processor library for build environment identification?**" -> 4625fc93  Todo: Programming - Consider to use Boost config headers as a "standard" pre-processor library for build environment identification?
FUZZY (0.94): chime/36d4c8ae/chime.md:83  "**Todo: Programming - Consider ways to identify and adapt to Host build environment in C++ code?**" -> 57b1d0ec  Todo: Programming - Consider ways to identify and adapt to Host build environment in C++ code?
FUZZY (1.00): chime/4ca21428/chime.md:16  "Todo: Meta Value Model - Consider to remember how it was Captain Picard that put me on track to Elm Repl and generic function modelling?" -> 4adcd5f4  Todo: Meta Value Model - Consider to remember how it was Captain Picard that put me on track to Elm Repl and generic function modeling?
FUZZY (0.99): chime/5f7240ed/chime.md:44  "Todo: Darwinet - Cosnider to use bitcoin authorization mechanism for Node authentication" -> 21c62611  Todo: Darwinet - Consider to use bitcoin authorization mechanism for Node authentication
FUZZY (0.99): chime/5f7240ed/chime.md:57  "Todo: Darwinet - Cosnider to use bitcoin authorization mechanism for Node authentication" -> 21c62611  Todo: Darwinet - Consider to use bitcoin authorization mechanism for Node authentication
FUZZY (0.99): chime/9e3bde05/chime.md:12  "Todo: Consider the Peter Millard youtube video on Blüm concealed 35 mm hinges?" -> c5e7ad98  Todo: Consider the Peter Millard youtube video on Blum concealed 35 mm hinges?
FUZZY (0.99): chime/d565333f/chime.md:12  "Todo: C++ - Consider to try out the GPL Licensed IMAP capable C++ library Mime?" -> d09ea834  Todo: C++ - Consider to try out the GPL Licensed IMAP capable C++ library VMime?
FUZZY (0.95): chime/dd94bc79/chime.md:21  "**Todo: Programming - Consider to understand the Linux File modes and how to set them appropriately using the chmod command?**" -> 261aa90d  Todo: Programming - Consider to understand the Linux File modes and how to set them appropriately using the chmod command?
UNRESOLVED: chime/008ee028/chime.md:24  "Todo: Testbench - Consider to prepare the Testbench for different build-environments and possibly targets?"
UNRESOLVED: chime/010d093b/chime.md:10  "Orderbekräftelse från [Ljusihem.se](http://Ljusihem.se) : 15134"
UNRESOLVED: chime/0694d434/chime.md:16  "Todo: Testbench - Consider to implement Presentment-file generation as a proof-of-concept of DSL-based Protocol-message-encoding engine?"
UNRESOLVED: chime/0694d434/chime.md:30  "Todo: TestBench - Consider to model protocols as levels of transformations both in view and processing?"
UNRESOLVED: chime/0694d434/chime.md:36  "Todo: Programming - Consider to try out if a REST interface may a facade to any protocol (FTP, SPDH, ISO 8583…)"
UNRESOLVED: chime/12d655ad/chime.md:37  "Todo: Manifets - Consider to write a manifest for ITfied - Smart IT for a Shared Planet?"
UNRESOLVED: chime/19e55456/chime.md:10  "TestBench - Consider to try out Git using TortoiseGit and beanstalapp git repository?"
UNRESOLVED: chime/1a3287ab/chime.md:10  "Todo: Eget AB - Överväg att dokumentera hur formatera ÅR.rtf fil till Årsredovisning i egen mall?"
UNRESOLVED: chime/1c67d70d/chime.md:10  "/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyClosureModelPlayground"
UNRESOLVED: chime/1c67d70d/chime.md:319  "/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyTestAnything"
UNRESOLVED: chime/2034404b/chime.md:22  "/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyCppStringPlayground/MyCppStringPlayground"
UNRESOLVED: chime/2061479d/chime.md:12  "Todo: C++ - Consider we should aim at starting to add transpires that generates C++ code for us (extend the asm mechanism for inline assembly)?"
UNRESOLVED: chime/2061479d/chime.md:40  "Todo: C++ - Consider we should aim at starting to add transpires that generates C++ code for us (extend the asm mechanism for inline assembly)?"
UNRESOLVED: chime/21499aa0/chime.md:12  "brute_force"
UNRESOLVED: chime/2162694c/chime.md:35  "Todo: TestBench - Consider to make a Firemonkey add-on that records and playbacks sequence diagrams?"
UNRESOLVED: chime/2927db2a/chime.md:58  "Todo: Tha Meh Repl - Consider what immutable (persistent) C++ data structure to use for the Tha instance?"
UNRESOLVED: chime/2b512b4c/chime.md:24  "Todo: Programming - Consider to design a Clang AST based Source Code Editor, IDE or GUI?"
UNRESOLVED: chime/2c5b6d08/chime.md:10  "Todo: Consider to learn Elm in VSCode by writing application to access ITfied accounting through FortKnox REST and Json API?"
UNRESOLVED: chime/2d6a3691/chime.md:10  "Kjell-Olov efterfrågar eventuella referenser till det meningsfulla och öppna utforskande samtalet om vår grumliga nutid och den förlorade andligheten (mystiken)"
UNRESOLVED: chime/308aee14/chime.md:22  "REPL does not support typing in type annotations #113"
UNRESOLVED: chime/31cac2c7/chime.md:106  "/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyCompilerDefaultClassMemberPlayGround/MyCompilerDefaultClassMemberPlayGround"
UNRESOLVED: chime/31d41888/chime.md:10  "Todo: Eget AB - Gör bokslut för ITfied 2015-2016 baserat på bifogade SIE-filer"
UNRESOLVED: chime/39248095/chime.md:10  "Todo: Consider to try out and evaluate the online service "Årsredovisning Online" to use SIE file to generate and digitally send in Annual Report to Bolagsverket and Tax Declaration to the Swedish Tax Agency?"
UNRESOLVED: chime/397c768b/chime.md:12  "Todo: Resilio Sync Pro/Home - Consider to consolidate my private Resilio Sync Home cloud of files?"
UNRESOLVED: chime/397c768b/chime.md:14  "Todo: Sync Pro - Consider to document the administration experience of creating my private cloud of shared files using Sync Pro?"
UNRESOLVED: chime/397c768b/chime.md:81  "Todo: Mac Pro - Consider to document the migration of my license and virtual machines for Parallels from my Macbook Pro 2014 Retina to my Mac Pro?"
UNRESOLVED: chime/397c768b/chime.md:99  "Todo: Mac Pro - Consider to document the migration of my license and virtual machines for Parallels from my Macbook Pro 2014 Retina to my Mac Pro?"
UNRESOLVED: chime/3b78fd47/chime.md:18  "/home/kjell-olovhogdahl/MyDefaultLinuxQtWizardsApplication"
UNRESOLVED: chime/3b78fd47/chime.md:152  "/Users/kjell-olovhogdahl/MyFirstMacOsQtWidgetsApplication"
UNRESOLVED: chime/3b78fd47/chime.md:205  "/Users/kjell-olovhogdahl/MyDefaultWindows10QtWizardsApplication"
UNRESOLVED: chime/3b78fd47/chime.md:256  "C:\\Users\\kjell-olovhogdahl\\Documents\\Visual Studio 2017\\Projects\\MyDefaultWin32Application"
UNRESOLVED: chime/3b78fd47/chime.md:302  "C:\\Users\\kjell-olovhogdahl\\Documents\\Embarcadero\\Studio\\Projects\\MyDefaultRADStudioVCLCppApp"
UNRESOLVED: chime/3c9f09f2/chime.md:112  "Todo: Testbench - Consider to use the icu-project C++ library for UTF string conversions?"
UNRESOLVED: chime/491640f5/chime.md:22  "Todo: <http://www.pianocenter.se>"
UNRESOLVED: chime/4a4c1803/chime.md:92  "/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyNordeaWebBankTextParser"
UNRESOLVED: chime/4e880192/chime.md:10  "Todo: Bokföring - Överväg att dokumentera Momsredovisning jan-mar 2018 för ITfied?"
UNRESOLVED: chime/4e880192/chime.md:12  "Todo: Eget AB - Notera att Skattedeklaration och Momsdeklaration är de två löpande under året"
UNRESOLVED: chime/4e880192/chime.md:14  "Todo: Eget AB - Överväg att förstå process (tull, moms, skatt och avgifter) och genomföra import av varor från utom EU till Sverige?"
UNRESOLVED: chime/4e880192/chime.md:16  "Todo: Eget AB - Överväg att ta reda på hur jag bokför och begär återbetalning av betalad EU moms (Jag glömt be om momsfritt köp)?"
UNRESOLVED: chime/4f856394/chime.md:10  "Mobile Solar Power"
UNRESOLVED: chime/52b0d95e/chime.md:262  "<http://llvm.org/releases/3.7.0/LLVM-3.7.0-win32.exe>"
UNRESOLVED: chime/52b0d95e/chime.md:264  "<http://llvm.org/releases/3.7.0/LLVM-3.7.0-win64.exe>"
UNRESOLVED: chime/534f618f/chime.md:10  "odo: Consider to learn Elm in VSCode by writing application to access ITfied accounting through FortKnox REST and Json API?"
UNRESOLVED: chime/5717cacb/chime.md:100  "Todo: Darwinet - Consider a design that allows parts of the Confluent Persistent MIV to distributed on nodes in the network (storing locally only whats locally required pr fits in memory)?"
UNRESOLVED: chime/5b5d7589/chime.md:10  "Todo: Darwinet - Consider distributed computing on Darwinet may be used for easy scalability and stability baed on the motivation behind Erlang design?"
UNRESOLVED: chime/62a03f0d/chime.md:46  "Conjugate Acid"
UNRESOLVED: chime/6a6173c5/chime.md:37  "/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyClosureModelPlayground/MyClosureModelPlayground"
UNRESOLVED: chime/6ca73600/chime.md:36  "/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyDataModelPlayground/MyDataModelPlayground/MetaValueTopDownPlayGround.cpp"
UNRESOLVED: chime/714507a2/chime.md:56  "Todo: Programming - Consider to implement Message Encoding/Decoding as a C++ template grammar that looks like the Element Tables used in Swedbank Specifications?"
UNRESOLVED: chime/76d04894/chime.md:141  "Sorotec - Order Confirmation/ Order: A18-88388"
UNRESOLVED: chime/777764dd/chime.md:12  "Todo: Consider to examine all the battery adapters I have to see if and how I can use them as Power Supplies in ITfied electronic lab?"
UNRESOLVED: chime/7c6907a4/chime.md:14  "Todo: Fortknox API - Consider to experiment with the Fortknox API so that I may automate the book keeping of The ITfied AB?"
UNRESOLVED: chime/81985046/chime.md:24  "Larry Temkin on Transitivity"
UNRESOLVED: chime/867a9d79/chime.md:10  "Todo: Consider a live music jamming software for internet distributed clients that works like "karaoke" but feels like "live" by recursive distribution of tracks?"
UNRESOLVED: chime/867a9d79/chime.md:12  "Todo: Överväg att göra en lista på låtar att sjunga som jag har inspelade stämmor på (För Trudelutt, Quartett, sjunga med Pernilla, Linda, Elin, fler...)"
UNRESOLVED: chime/867a9d79/chime.md:14  "PernOlov Trudelutt - Sånggodis för träffen nu på Onsdag 22 Feb :)"
UNRESOLVED: chime/871e8ee0/chime.md:28  "Todo: Programming - Consider to write Swedbank iPOS Terminal iPOS, SPDH, PPL and Clearing encoder/decoder open source libraries of interest to new iPOS Terminal Vendor?"
UNRESOLVED: chime/87b55061/chime.md:285  "/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyIRealProURLReader/MyIRealProURLReader"
UNRESOLVED: chime/89148a0f/chime.md:12  "/Users/kjell-olovhogdahl/Resilio Sync/KeyNote/C++ Nested Loops Enumeration"
UNRESOLVED: chime/89148a0f/chime.md:71  "/Users/kjell-olovhogdahl/Resilio Sync/XCode/MySetCombinationEnumerators/MySetCombinationEnumerators"
UNRESOLVED: chime/8d0b368f/chime.md:41  "Microphone stand"
UNRESOLVED: chime/8e6a668d/chime.md:72  "/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyTestAnything/MyTestAnything"
UNRESOLVED: chime/91e9ca9b/chime.md:38  "W:\\workplace\\RAD_Studio\\MyMailTodoSynchronizer"
UNRESOLVED: chime/91e9ca9b/chime.md:42  "W:\\workplace\\RAD_Studio\\MyMailTodoSynchronizer"
UNRESOLVED: chime/96bae485/chime.md:109  "/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyCppRestDSKPlayGround"
UNRESOLVED: chime/99e28304/chime.md:12  "Gödel's Incompleteness Theorems - In Our Time"
UNRESOLVED: chime/9b252462/chime.md:16  "/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyRxCppWebCrawler"
UNRESOLVED: chime/9edb20dd/chime.md:18  "Todo: Testbench - Consider to implement Presentment-file generation as a proof-of-concept of DSL-based Protocol-message-encoding engine?"
UNRESOLVED: chime/9edb20dd/chime.md:32  "Todo: TestBench - Consider to model protocols as levels of transformations both in view and processing?"
UNRESOLVED: chime/9edb20dd/chime.md:38  "Todo: Programming - Consider to try out if a REST interface may a facade to any protocol (FTP, SPDH, ISO 8583…)"
UNRESOLVED: chime/9f70a081/chime.md:10  "Todo: Programming - Consider to talk/blog on all "layers" C++ source code goes through before becoming in-memory…"
UNRESOLVED: chime/a2ba14c4/chime.md:10  "Files ready for download — Online Store"
UNRESOLVED: chime/a2ba14c4/chime.md:12  "Project Update #3: Twin Turbo Vise by Inkleind llc"
UNRESOLVED: chime/a2ba14c4/chime.md:14  "Yes! Twin Turbo Vise has been successfully funded."
UNRESOLVED: chime/a2ba14c4/chime.md:16  "Yes! Twin Turbo Vise has been successfully funded."
UNRESOLVED: chime/a2ba14c4/chime.md:18  "Project Update #2: Twin Turbo Vise by Inkleind llc"
UNRESOLVED: chime/a2ba14c4/chime.md:20  "You just backed Twin Turbo Vise"
UNRESOLVED: chime/a38aa183/chime.md:12  "V:\\workplace\\RAD_Studio\\MyFmxPandoraPlayground"
UNRESOLVED: chime/a8fddf0f/chime.md:10  "Peterson vs Zizek Live Stream Pass"
UNRESOLVED: chime/a9d89368/chime.md:109  "Using jupyter notebooks with a virtual environment"
UNRESOLVED: chime/a9d89368/chime.md:168  "notebook 6.3.0"
UNRESOLVED: chime/ab703745/chime.md:18  "/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyCppTypeSystemInCppTypeSystem"
UNRESOLVED: chime/b133ed19/chime.md:10  "Todo: Consider to document if I can build Freecad from source on macOS apple silicone?"
UNRESOLVED: chime/b35ce423/chime.md:10  "Todo: Consider possible waste water logistic solutions for my paint"
UNRESOLVED: chime/b659bc6b/chime.md:10  "Kjell-Olov säger hej och undrar om en web-teknikgrej :)"
UNRESOLVED: chime/b9f4df60/chime.md:174  "Polyakrylamid" in "Todo: Rena Penselvatten - Överväg sätt att hemma kunna rena vatten från färgrester efter penseltvätt?"
UNRESOLVED: chime/ba28d3a5/chime.md:16  "Todo: Testbench - Consider to use the icu-project C++ library for UTF string conversions?"
UNRESOLVED: chime/c2c18e21/chime.md:42  "Todo: Testbench - Consider to prepare the Testbench for different build-environments and possibly targets?"
UNRESOLVED: chime/c5182ffb/chime.md:40  "Todo: Consider to document how (and where) my brew upgrade gcc to gcc14 went?"
UNRESOLVED: chime/ca0cdb46/chime.md:18  "Todo: <http://www.pianocenter.se>"
UNRESOLVED: chime/ca665b2e/chime.md:14  "**Skyddsutrustning brändes upp i somras**"
UNRESOLVED: chime/ca665b2e/chime.md:15  "**Andningsskydd för alla svenskar brändes upp – utan protester**"
UNRESOLVED: chime/ca665b2e/chime.md:16  "**Trots stora bristen – utrustning brändes**"
UNRESOLVED: chime/ca665b2e/chime.md:17  "**Kaliber avslöjar: Skyddsutrustning eldades upp under pandemin**"
UNRESOLVED: chime/ca665b2e/chime.md:21  "**Advokaten: Bortgallringen är allvarlig**"
UNRESOLVED: chime/ca665b2e/chime.md:22  "**Bortgallrade dna-spår i NFC:s källare – hade kunnat fälla brottslingar**"
UNRESOLVED: chime/cbd8252c/chime.md:74  "/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyTestAnything/MyTestAnything"
UNRESOLVED: chime/d09ea834/chime.md:20  "==&gt; Also see explicit “Todo: Programming - Consider to study the POCO C++ standard Internet protocol library (ftp, pop3)”"
UNRESOLVED: chime/de307f3c/chime.md:16  "Todo: Deklarera Privat (KOH-Innovation) 2016"
UNRESOLVED: chime/de307f3c/chime.md:18  "Todo: Eget AB - Dokumentera process för ekonomiska transaktioner och bokföring"
UNRESOLVED: chime/de307f3c/chime.md:20  "Todo: Eget AB - Överväg att gå över till elektronisk bokföring?"
UNRESOLVED: chime/df108e46/chime.md:14  "Todo: Consider to learn about the Mobile Modem APN settings and its relevance to Swedbank Mobile Connection for test?"
UNRESOLVED: chime/e617ed29/chime.md:27  "Cetus3D Online Store - Order 2651"
UNRESOLVED: chime/ec963a37/chime.md:608  "/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyThaCppPlayground/MyThaCppPlayground"
UNRESOLVED: chime/ed219c8c/chime.md:62  "Todo: Tha and C++ value categories - Consider we can express C++ value categories (rvalue, lvalue, xvalue, prvalue) as Tha identifiers bound in different ways (no name, no value)?"
UNRESOLVED: chime/f03f3b43/chime.md:58  "/Users/kjell-olovhogdahl/Resilio Sync/XCode/MyCppTypeSystemInCppTypeSystem/MyCppTypeSystemInCppTypeSystem"
UNRESOLVED: chime/f2b721c7/chime.md:8  "Todo: Video - Ordering from China through Alibaba web-site"
UNRESOLVED: chime/f2c489a5/chime.md:10  "Your [Amazon.com](http://amazon.com/) order (#112-4791974-0141854)"
UNRESOLVED: chime/f2c489a5/chime.md:12  "Your [Amazon.com](http://amazon.com/) order of "12 Rules for Life: An..."."
UNRESOLVED: chime/fa1f3850/chime.md:56  "<http://llvm.org/releases/3.7.0/LLVM-3.7.0-win32.exe>"
UNRESOLVED: chime/fa1f3850/chime.md:58  "<http://llvm.org/releases/3.7.0/LLVM-3.7.0-win64.exe>"
UNRESOLVED: chime/fbd06a51/chime.md:41  "/Users/kjell-olovhogdahl/BitTorrent Sync/XCode/MyThaCppPlayground/MyThaCppPlayground"
SELF: chime/1e7868eb/chime.md:10  "Todo: Front-end Programming - Consider to list and try out different GUI front-end mechanisms that we can also turn into the elm-idiom unidirectional single-atom idiom?"
SELF: chime/276b4374/chime.md:10  "Todo: Consider to document different ways to capture or grab screenshots in OS X, Linux and Windows 10?"
SELF: chime/308aee14/chime.md:32  "Todo: Meta Value Model - Consider what we can learn from the Elm language for Meta Value Model design, REPL application and scripting abilities?"
SELF: chime/3b78fd47/chime.md:12  "Todo: GUI Programming - Consider to document the different IDE created entry points of default applications on different platforms and User Interface frameworks?"
SELF: chime/96b1a120/chime.md:10  "Todo: Design an exercise tool to charge batteries for electrical appliances"
SELF: chime/de7df97a/chime.md:12  "Todo: Consider to study and try out the Open Source 2D CAD application QCAD (NOT CuteCAD as a companion to 3D CAD FreeCAD)?"

chime (intralink): 1644 references: 1526 linked (1464 exact, 46 normalized, 5 loose, 11 fuzzy), 0 already linked, 112 unresolved, 6 self; 534 entries changed.
kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/sharedplanet % 
```

So at this stage I could actually be tempted to just shove this into the git repo, commit and push and be done with it?

* At least I then would have the chimes on the interwebs?
* And any future 'intralink' is a problem if and when I move something from chimne to another domain?

I wonder, can I still add from _mail to existing chimes?

* It should work?

  * I could make a new 'domain_to_domain diff --ignore my_ignore.md'
  * This would result in a poptential pick-list for what not-yet in chime
  * I could then edit a new pick-list
  * And the do domain_to_domain add --pick my_new_picks.md'?

Still, it feels a little brittle?

I also actually want to have some 'tagging' of each chime (domain entry)

* I made [repo_scripts/init_new.py](../repo_scripts/init_new.py) insert a tag based on domain/hash.
* I made the new init_new the one at the top of the repo
* I rerun the _mail to chime pipe line

  1. I diffed current chime domain with the _mail domain using my ignore.md listing to a _pick-md

```sh
kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/sharedplanet % ./domain_to_domain/domain_to_domain.py diff . _mail chime --ignore ~/Documents/GitHub/plaiground/session/0dd1a71d/ignore.md > _pick.md
_mail -> chime (diff): 2857 pending, 349 ignored, 0 in target
kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/sharedplanet % 
```

  1. I added from _mail to chime based on created _pick.md

```sh
kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/sharedplanet % ./domain_to_domain/domain_to_domain.py add . _mail chime --pick _pick.md
# ...
_mail -> chime (add), 2857 pick entries: 2857 added, 0 skipped, 0 failed, 0 unmatched
Updated 'chime/index.md' with 2858 entries.
kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/sharedplanet %
```

OK. I am simply UNABLE (!!!) to make this work?!!

* Now each entry creatd from mail gets tagged '_mail/hash'
* This comes of course from init_new being the one injecting the tag
* But I want the tag to be the current domain (so as a chime it should be 'chime/hash')

DARN!! This just don't compose?!!

I then decioded to just write the index hash into the init_new created markdown file.

* Each init_new + eml_to_domain markldown now have a line ```#hash As of mail-date```
* init_new writes the hash
* eml_to_markdown now writes the As Of date from the mail subject.

## 20261013

So I have now renamed this repo from 'chime' to 'sharedplanet'.

* In this way I can have a 'chime' being one domain and not confuse with the repo name

Also, I can use 'sharedplanet' as a tag or indicator that what is in this repo is for ALL on this planet to take in, use a,d share alike.

* [Also see the seed for SharedPlanetBusiness](https://kjelloh.github.io/sharedplanetbusiness/)
* [Also see the seed for SharedPlanetCitizen](https://kjelloh.github.io/sharedplanetcitizen/)

I now added machinery from [kjelloh.github.io/plaiground/session/0dd1a71d](https://kjelloh.github.io/plaiground/session/0dd1a71d/session)

* I expect I have to tweak it to work in some general form at the top folder of this repo.
* The goal is to 'import' selected entries from my todo-mails to the chime domain as markdown.

So I got the [test_on_todo_mails](../test_on_todo_mails.py) to work.

* It creates 'chimes (for now named 'test_chime') WITH intra-linking
* And those links are NOT updated by the domain_to_domain mechanism!

**SIGH!!* - There you have it for vibe coding!

* WHen I vibe-coded this with Claude I lacked insight into how the parts of the machinery needs to interact.
* And Claude has simply zero understanding of the consequences of the solutions it implements.
* That is, it does what it is told - but it fails to 'understand' what 'extras' needs to be added.

OK, so can I fix domain_to_domain to process the intra-links?

* Maybe it is as simple as to recognize intra-links and do a text-replace in the processing?
* I have the links in the test_chime named after this domain.

```sh
[Todo: Consider T-slot cut router bits for designs and builds in wood where T-slot fastening could be an option?](../69edf934/test_chime.md)
```

* So I need to match this pattern to detect 'test_chime' as source domain and replace with target domain.

DARN! This is SOOO CONVOLUTED!!

## 20261012

So I now have a working todo-mail pipeline in * [plaiground/session/0dd1a71d](https://kjelloh.github.io/plaiground/session/0dd1a71d/session.html)

Question is now how I consolidate into this repo?

* Should I run the scripts from the root folder in this repo to test they actually work outside the session folder where they are developed?
* Maybe I should just copy in the baked chimes now in the session folder (The final result)?
  * And then add and commit them here?
  * That is the easy way (and have it done)
  * But then any re-run of the pipe-line has to be done in the session folder?
* On the other hand, if I run the scripts from scratch here I get a new domain folder with ALL the todo-mails also here.
  * And these are NOT to be version controlled not added to this git repo.

So where am the eml-to-domain processing live?

* For now it lives in the plaiground session where they were developed and test out.
* But there they are NOT backed up.
  * Also, it is an obscure location (session/0dd1a71d, who remembers that?)

DARN! I now realize that the repo is 'chime' which is confusing

* The URL to todo-mails index as 'chimes' will contain chime/chime/index.md
* That does not look good?
* Still, my idea of having a kjelloh/chime git repo kind-of make sense?
  * It can be seen as my own chimes?
  * But then what are the sub-domains?
  * Should I consider chime/todo?
  * Or chime/from_mail?
  * Or chime/sharedplanet/todo?
  * Or what?

It seems maybe I should add the picked todo-mail domain entries as 'from_mail'?

* I can copy the baked chime folder from plaiground sesssion.
* Then do domain_to_domain to diff and pick all from chime to from_mail?
* Then link from_mail from index, README or some suitable location?
* Then add to the git repo, commit and push to Github?
  * Not Github Pages will generate web pages for all my form_mail domain entries! 

## 20261005

I now want to try out the new eml-to-entry mechanism developed in plaiground.

* [plaiground/session/0dd1a71d](https://kjelloh.github.io/plaiground/session/0dd1a71d/session.html)
* [eml_to_domain — user manual](https://kjelloh.github.io/plaiground/session/0dd1a71d/eml_to_domain/)
* [domain_to_domain — user manual](https://kjelloh.github.io/plaiground/session/0dd1a71d/domain_to_domain/)

Maybe the mechanism is now good enough to publish selected todo-mails as chimes?

* Darn! The folder with the mechanism is littered with test scripts and files!
* **Sigh** - All this littering going on!

Ok, I cleaned them up.

* But now, where do my exclude.md and pick.md files go for this specific import from my toto-mails?
  * I mean, I don't want these to show in the git repo now on the generated site?
  * But I also want to remember these filters?

Hm... Tricky!

Anyhow, does the mechanism produce sufficient result?

* The eml_to_domain seem to work just fine?

```sh
kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/chime % ./eml_to_domain/emls_to_domain.py ~/Downloads/mail_export/eml --domain todo_mail .
# ...
4433 mail files -> todo_mail: 3204 added, 487 updated, 742 skipped (superseded), 0 failed
Updated 'todo_mail/index.md' with 3204 entries.
kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/chime %
```

But now I have all the imported todo-mails in this git repo where it does NOT belong!

* So I need to figure out where to do the intermediate step eml-to-domain?
* Then do domain_to_domain from that git repo to here for those who are to become chime.



## 20260915

I now added the 'to_site.py' developed in my 'plaiground' git repo that orchestrates a local Jekyll site generation.

* Seems to work just fine for this chime repo for now?

## 20260914

I now have in 'plaiground' a mechanism that turns 'simple' eml-file to chime ok.

* But we need to iterate to have the mechanism be able to parse emails with html parts and also process images correctly.

## 20260905

So I am doing some experiemts with Apple Mail to see how I can manually export mails to local storage.

* I now suspect Apple Mail performs these exports in 'the background'
* And maybe the reason Export of my smart mailbox for toto-mails seem to dpo nothing is that it takes time for Apple Mail to perform the upfront processing before any exported files actually appear?

I seem to have two options?

1. Export a mailbox (will create a local mbox-file)
2. Drag emails to a local folder (fill create an eml-file for each mail)

It seems it actually works to drag all my todo-mails from the smart mailbox to a folder?

* For a long time (almost 30 minutes) nothing can be seen on the disk.
* And while Apple Mail works the activity monitor shows Mail at 230% CPU and mdwrite-process at 100%
* And only when all is done can I see the files on the disk.
* Only, Apple Mail created an mbox-file plus a content file?

* So does single file drag-and-drop to folder create an eml-file?
  * YES.
* And multiple drag-and-drop creates an mbox and content file?
  * Drag 2 creates two eml-files.

AHA! Suddenly 4436 files appeared on my disk!

* It must be my drag-and-drop of todo-mails to the disk that finished?

I now realise I have a lot of TODO-mails with the same heading (different revisions of the same todo)

* So Apple Mail crates eml-files with the same file name but suffixed with 1,2,3...

So how do I go about this?

* I can export my smart Todo mail box into a mbox-file
* I can drag-and-drop all my Todo-mails into eml-files

And then it seems I should be able to vibe code some python scripts to process them?

Let's try!

* I do both and get one mbox archive and one set of eml-files?
* Then I can process them with python scripts?
* I then have three representations of my Todo-mails?
* And can see if I can make them all agree on the number of Todo-mails I have?

It seems there is quite a lot of data?

* The eml-file folder is 4,45 GB!
* The mbox file was about 2,5 GB (if I remember correctly?)

I can create scripts from_emls.py and from_mbox.py?

* Preferrably also add a 'cache' storage to enble the scripts to onlyu process changes?

It is now 11:35 and I have initiated both a drag-and-drop of all my over 4500 Todo-mails as well as export of the Todo samrt mail-box.

* Let's see how long this takes and what the end result is?
* 12:04 (+30 min) 
  * No files or folders can be seen in finder
  * But 'get info' shows mbox 1,22 GB, eml-folder (0 bytes)
* 12:31 ( + 1h)
  * Now shows mbox content and GetInfo shows 2,15 GB
  * Now shows eml-files and GetInfo shows 2,19 GB för this folder (4429 files in folder)
  * Apple Mail activity CPU low
  * Process md_stores at 100% (still going?)

So at this point we have different counts for TODO-mails?

* The from_mail.py finds 4427 Todo mails
* The drag-and-drop creates 4429 eml-files

AHA! Still going (now 4431 eml-files)!

* 12:52 (+ 1:20)
  * eml-folder 'Get Info' shows 4430 Items and 2,19 GB
  * eml-folder z-shell 'find . -type f | wc -l' shows 4429 files
  * eml-folder tree command shows 1 directory, 4429 files.
  * Apple Mail Todo smart folder shows 4438 messages
  * mbox-folder 'Get Info' shows 4 items and 2,15 GB
  * Process md_stores shos 100% CPU (still going?)

At this stage I discovered some eml-files that indicates 'outliers'?

```text
├── BRF Ekbladet Todo - Skräp efter bänkrenoveringar behöver hjälp att slängas (städdag i höst?).eml
├── Owls an bells - make .NET app that reads todo mails and creates a todo-list.eml
├── Re_ Todo_ Spb - as long as we dig up or destroy....eml

├── Todo BRF Ekbladet - Marcella är ledsen på sin trädgård och kvalité på uterum.eml
├── Todo Consider a script for a video about what I have learned about metric threading?.eml
├── Todo DIY Open Oscilloscope - Consider to check out Bitscope on Raspberry Pi? 2.eml
├── Todo DIY Open Oscilloscope - Consider to check out Bitscope on Raspberry Pi?.eml
├── Todo Tha C++ - Consider ways to defines "class" meta-3 value using C++ syntax?.eml
├── Todo Tha C++ - Consider we want to be able to write meta-lambdas (to conveniently inject anonymous meta-code)?.eml
├── Todo. SharedPlanet - Consider an aciticity where we design SPB variants of national flags?.eml
├── Todo; SharedPlanet - Vill du ligga med mig?.eml

```

These are 11 e-mails that does NOT seem to be prefixed 'Todo:' (the ':' is not there...)

* So does this account for Apple Mail 4438 messages vs from_mail 4427 mails?

YES - That would perfectly explain it!

* I have configured the smart mailbox as ``` From contains 'kjell-olov' and 'Subject contains 'Todo' ```
  * And from_mail filters on 'Subject begins with 'Todo:'

GREAT! Always nice to have a map that fits the observations!

## 20260904

It seems I have now succeeded to fix the from_mail.py script?

* It now tries to decode the header text using provided encoding or utf-8, latin-1
  * It even has a fallback to ascii + hex-values for unprintables and unknowns.

For my Todo-mails it now finds 4427 mails.

* While Apple Mail states it finds 4438?

So something may still be off?

* Or Apple Mail count is off for some reason?

I now have to decide if it is 'close enough'?

* Or if I should find a way to export from Apple Mail and somehow compare with what from_mail finds?

So how can I export mails from Applke Mail to some local file format?

* It seems I can export to an mbox-file and then process it by a python script?

It seems nothing happens if I try and export my 'smart' Todo-mailbox in Apple Mail?

* I tried right-click and 'Export Mailbox' on my account.
  * This seems to silently initiate an export in the background?
  * I Apple Finder I can see a folder INBOX.partial.mbox with content that grows if a close and open the folder...
  * This is CONFUSING (opaque) user interface, but ok...

## 20260903

Today I created this repo.

I added an experimental from_mail.py script that scans the configured IMAP account for mails that are 'chimes'.

For now I use it on my own account where mails with the subject 'Todo:...' are in fact my 'chimes'.