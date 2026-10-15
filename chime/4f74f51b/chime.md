# Todo: Dream CAD Tool - Consider a CAD tool where objects exist only relative each other and made up only of relative points, lines, faces (and have NO absolute coordinate system with an origo)?

```#4f74f51b``` *As of 2019-07-22 18:33*

[mail plain/text](mail.txt)

{% raw %}
I find it disturbing and totally unintuitive to be forced to design in an absolute coordinate system and would like the origin to go (the origin is a view property, not part of the designed artefacts)

1) Consider why I would like my CAD tool to NOT use an absolute coordinate system?

> *I have come to realise that the coordinate system origin in Fusion 360 or any other 2D or 3D drawing tool is just in the way for me when I want to design. And when I started to think about it I realised that maybe we can make any absolute space to be part of a view, not actually part of any designed artefact per se.*

> *So is this possible. It would mean that we can NOT have a design that consists of only one point. This point would not have anything to relate to and thus it can not exist. But two points can relate each other. And when we have three points we can have each point relate to the two other.*

> *But now we have the problem with property explosion. We can not have each point relate to every other point. So we need a strategy to pick what point (or points) to relate to for each point in the model.*

> *Maybe we can prefer to relate to point clusters? So where there are many points together we identify some "centre" point or points and have points more spread out to relate these "important" or ubiquitous point locations? But here it seems to get interesting. When you remove a point you have to ensure you do not destroy the relation between other points. That is, before we can remove a point we need to ensure the relation between that point and between other points don't get screwed up. How can we do this in some efficient way?*

> *Ideally we would like to store only one set of space coordinates for each point. But this would mean we can store only one relation to one other point. And further, each point must have an additional unique identity. We can not use an absolute coordinate as its identity. So in any case we will need to store both a space relation and a unique identity.*

> *It seems we need something that can be thought of as a diagonal matrix? If we place the point identity on each row and column of the matrix. Then we can define all relations with a carefully selected diagonal in the matrix. A diagonal chosen so that each point relate to another point (not relating to itself). And we can imagine to add more relations for some efficiency purposes and then use some points for relations to other points more than others. These points would show up in the matrix as having rows or columns defined.*

> *In fact, we MUST have each point relate to two other points! Otherwise we would only have points paired up to relate each other. And we have no way to define a cluster of points to belong together as a frame.*

> *As a spin-off we can define some relations as variable, as in unconstrained, and other as limited by some relation function or even fixated relative one or several points. So in a way we get the ability to model constraints in the same model as the one used to define any point.*

...

{% endraw %}
