# Todo: Darwinet - Consider to implement "Conway´s Game of Life" on a board of Darwinet nodes as a base for distributed computation capabilities?

```#60a9e234``` *As of 2017-07-31 17:11*

[mail plain/text](mail.txt)

{% raw %}
Could it be a good idea to design an implementation of “Conway´s Game of Life” in a Darwinet Doman of nodes as a base for other distributed computation abilities?

1) Consider the rules for Conway´s Game of Life ([https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life))?

> “*Rules*

> *The universe of the Game of Life is an infinite two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead, or "populated" or "unpopulated". Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

> *  
> *• Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.  
> *  
> *• Any live cell with two or three live neighbours lives on to the next generation.  
> *  
> *• Any live cell with more than three live neighbours dies, as if by overpopulation.  
> *  
> *• Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.  
> *

> *The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed—births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick (in other words, each generation is a pure function of the preceding one). The rules continue to be applied repeatedly to create further generations.*  
> "

…

![](Gospers_glider_gun.gif)

2) Consider what we need to do to implement Conway´s Game of Life distributing pixels on the nodes of the domain?

==&gt; Consider each node of the Darwinet Domain is assigned an x,y location in the game?

==&gt; Consider each node of the Domain must be aware of its neighbour nodes on the (x,y) boa of the game?

==&gt; Consider the nodes of the domain must share its own pixel state with its neighbours?

==&gt; Consider each node stores the total board and a total list of a mapping of Node ID to (x,y) coordinate of the board.

==&gt; Each node may now run an update algorithm on its own pixel on the borad (it can query its own node id and thus know what pixel to process)?

==&gt; The whole board is then synchronised by Darwinet Deltas and there will be no conflicts?

==&gt; Consider this kind of reflects how HPX and other distributed computation frameworks behave (each process executes as defined by its ID in the system)?

…

==&gt; Consider each node only shares a 3x3 part of the board data (The MIV storage distributed into the domain)

==&gt; Each pixel state will now be stored and shared by nine nodes in the domain (nine overlaps for each pixel state)?

==&gt; Each node algorithm may now operate only on the

> Domain x,y (relative pixel states of this domain)

> &#91;-1,-1&#93; &#91;0 ,-1&#93; &#91;+1,-1&#93;

  
> &#91;-1,0 &#93; &#91;0 ,0 &#93; &#91;+1,0 &#93;  
> &#91;-1,+1&#93; &#91;0 ,+1&#93; &#91;+1,+1&#93;

==&gt; Hm… We now have sliced the MIV into 3x3 boards in sub-domains (the whole board is not shared on domain nodes)?

…

==&gt; Consider the domain being made up of a sub-domain for each pixel state (each domain sharing a 3x3 slice of the board nodes)?

==&gt; Then each node will be sharing nine sub-domains (one for each of eight neighbours plus its own domain where it itself is the center)?

==&gt; Each sub-domain will have a member that is the center of the shared 3x3 grid and that node will calculate the center node state?

==&gt; No conflicts will occur as only one node will update the state of grid pixel x,y?

…

==&gt; Consider a mechanism where the domain distributes a task to each x,y node with the rules to calculate the state of pixel x,y of the shared board?

==&gt; Consider this ability to distribute an algorithm explicitly can serve as a base for more complicated distributed algorithms?

==&gt; But then the algorithm is not resilient (it requires all nodes to be present and do their work)?

…

==&gt; Consider a mechanism where the nodes in the domain cooperate to calculate the state of the board in turns (each node volunteering to taks)?

==&gt; Consider how the domain nodes may collaborate to complete all calculations of one turn?

==&gt; Consider ways so that each turn will complete regardless of how many nodes that participate (a single one should be able to do the whole work)?

==&gt; Consider collaborative mechanism to ry and optimise parallel collaboration in case of all nodes present?

==&gt; Ideally we would like each node to calculate its “own” pixel state (but then take on some others pixel state if that state does not gets updated)?

*==&gt; Consider what it would take to be able to play a **small** (e.g., 10x10 board) Conways Game of Life **on a global** domain of 8 billion Darwinet Nodes?*

*==&gt; Consider what it would take to play a **humongous** (e.g. 7 billion pixel board) Conways Game of Life **on a small **Darwinet Domain (say 10x10 nodes)?*

*==&gt; Finally - Consider what it would take to play a **global** board (7 billion pixels) Conways Game of Life **on a global** (7 billion nodes) Darwinet Domain?*

==&gt; These three architectures should cover a large set of other possible distributed computation algorithms of interest?

…

…

…

Consider to delve into this proof-of-concept and investigation of Darwinet distributed computation mechanisms by implementing the Conway’s Game of Life on a domain of Darwinet nodes?

...

{% endraw %}
