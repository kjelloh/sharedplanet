# Todo: Consider to design an Arduino based used 18650 cell tester, marker and package arranger robot?

```#832f7126``` *As of 2018-10-15 19:17*

[mail plain/text](mail.txt)

{% raw %}
It seems it could be a fun project to design a robot that automatically tests 18650 cell capacity and then marks and groups them into packages of similar capacity?

1) Consider this youtube video “Make Matched 18650 DIY Powerwall Modules using Builder tool [rePackr.com](http://rePackr.com)” about testing 18650 cells and arrange them into similar (balanced) cell packages (<https://www.youtube.com/watch?v=hXYf1r62vqc&t=404s>)?

==&gt; It seems he uses a cell package webb tool that lives here (<https://j35.us/rePackrCOM>)

![](<Screenshot 2018-10-15 at 18.52.34.png>)

==&gt; Consider to

> Cell Holders [http://j35.us/100cellHolders](https://www.youtube.com/redirect?q=http%3A%2F%2Fj35.us%2F100cellHolders&event=video_description&redir_token=BfMYzim8y6PV59C6UisvDD_ufr58MTUzOTcwNzkxMkAxNTM5NjIxNTEy&v=hXYf1r62vqc)  
> Cell Tester [http://j35.us/ZanflareC4](https://www.youtube.com/redirect?q=http%3A%2F%2Fj35.us%2FZanflareC4&event=video_description&redir_token=BfMYzim8y6PV59C6UisvDD_ufr58MTUzOTcwNzkxMkAxNTM5NjIxNTEy&v=hXYf1r62vqc)

2) Consider a robot that can pick 18650 cells, place them into a capacity tester and mark them with capacity?

==&gt; Consider a design so that we can place the cells to be picked by the robot?

==&gt; Consider if to buy or build an 18650 cell capacity tester for our robot (we need to be able to automate insertion and removal of cells)?

==&gt; Consider what “printer” to use to print the date and capacity of the cells?

==&gt; Consider to design an “output tray” where the robot places measured cells (and optionally also knows where they are)?

==&gt; Consider to design the robot to automatically arrange the measured cells into groups of cell packages of similar capacity?

…

3) Consider what we can consider to measure to be able to arrange the cells into “similar” cell packages?

==&gt; Consider we would like cells in each package to be arranged in series so that cells with similar capacities are place in the same location in each package?

==&gt; Or does the order of the cells not matter (when charged the cells with lower charged will automatically swallow the most charge and thus even up the charge between cells in series)?

==&gt; Consider we would like to measure each cell charge and discharge rate and curve (assuming we like cells in a package to have as similar charge curve as possible)?

==&gt; Or will they have similar charge and discharge curve if they have the same capacity?

==&gt; Consider cells with the same capacity still can charge and discharge with different current based on their design (and thus they DO have different discharge curves)?

…

==&gt; Consider we would like to measure each cell internal resistance (and arrange cells so that each cell within a group, and each group, will have matched internal resistance)?

==&gt; Consider what more properties of the cells we could measure and keep track of to be able to arrange them properly into cell packages?

...

{% endraw %}
