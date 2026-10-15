# Todo: Find a Graph Layout algorithm that may be animated

```#ab0f333f``` *As of 2015-10-11 19:44*

[mail plain/text](mail.txt)

{% raw %}
It is not clear how the Boost graph layout methods may be animated (drawn whilst iterating to equilibrium)?

1) This seems to be a good site that expelling the forced spring layout algorithm (<http://allegroviva.com/allegrolayout2/force-directed-layouts/>)

2) This example seems to suggest that the boost layout algorithm use the position_map also as input and thus may be iterated (<http://stackoverflow.com/questions/10466843/fruchterman-reingold-layout-doesnt-converge>)?

// The same position map (get(vertex_position, g)) is used in two consecutive calls, first to create a random map and then as in/out to force directed layout.

...

random_graph_layout(g, get(vertex_position, g), space);

fruchterman_reingold_force_directed_layout(g, get(vertex_position, g), space,cooling(linear_cooling&lt;double&gt;(100)));

// Note that get(property,graph) is part of the boost graph library (<http://www.boost.org/doc/libs/1_53_0/libs/graph/doc/using_property_maps.html>)

// Note that the code above requires the property vertex_position to be installed into the Boost namespace using the

namespace boost {

enum vertex_position_t { vertex_position };

BOOST_INSTALL_PROPERTY(vertex, position);  
};

// And BOOST_INSTALL_PROPERTY(KIND,NAME) defines a property the graph may possess (<http://www.boost.org/doc/libs/1_52_0/boost/graph/properties.hpp>)

// In this case the property defined by the enum vertex_position is defined and thus

adjacency_list&lt;vecS, vecS, undirectedS, property&lt;vertex_position_t, point&gt; &gt; g(edge_list.begin(), edge_list.end(), seq.size()); defines a graph having such a property

// and get(vertex_position, g) works.

3) This would suggest one should be able to fist crate some initial starting position map and then iterate the call to fruchterman_reingold_force_directed_layout using the same position map until it has converged?

a) The named parameter cooling shall provide a functional object that returns the ”temperature” of the current iteration.

b) We should be able to fool the layout function to terminate immediately by providing a cooling function that always returns 0?

c) Then we may keep track of the ”temperature” outside the call and terminate when we want (e.g. by using linear_cooling&lt;double&gt;(100) ourselves)?

E.g.:

// Inputs

Graph g = ...

Topology space = ...

PositionMap position = ...

// init position to random layout

random_graph_layout(g, position, space);

linear_cooling&lt;double&gt; our_actual_cooling_function(100)

bool converged = false;

while (converged == false) {

fruchterman_reingold_force_directed_layout(g, position, space,cooling(my_immedate_cooling));

draw_graph(position); // our draw function that updates view to current position map

converged = (our_actual_cooling_function() == 0);

}

…

Elaborate on this approach to see if we can fool the layout function to be externally it eared in this way?

{% endraw %}
