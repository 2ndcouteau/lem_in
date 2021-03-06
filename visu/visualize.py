import os
import sys

template = """
<html>
<head>
    <meta charset="UTF-8">
    <style type="text/css">
        #container {
            margin-left: 10%%;
            max-width: 90%%;
            height: 100%%;
            margin: auto;
        }
        ul {
            list-style-type: none;
            margin: 0;
            padding: 0;
            width: 10%%;
            background-color: #f1f1f1;
            height: 95%%; /* Full height */
            position: fixed; /* Make it stick, even on scroll */
            overflow: auto; /* Enable scrolling if the sidenav has too much content */
        }
        li {
            display: block;
            color: #000;
            margin: 10px;
            padding: 8px 16px;
            text-decoration: none;
        }
        li:hover{
            background: #8699a4;
        }
    </style>
</head>
<body>
<button onclick="gridify()">Gridify</button>
<ul id="turnsbuttonbar"></ul>
<div id="container"></div>
<script src="sigma.min.js"></script>
<script src="sigma.plugins.animate.js"></script>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<script>
    var text = `%s`;
    text = text.replace(/\s\{2,}/g, ' ');
    text = text.split('\\n');
    var s = new sigma('container');
    var graphcopy = new sigma.classes.graph();
    var lemins = text.shift();
    var turnsarray = [];
    var mode = 0;
    var repart = [-50, 50, 15];
    var turns = 0;
    var startid = {};
    var endid = {};

    function generateLeminColor(seed) {
        return (
            "#"+ Math.floor((Math.abs(Math.sin(seed) * 16777215)) %%
            16777215).toString(16)
        );
    }

    function parse_room_init(line, special) {
        var room = line.split(" ");
        var size = 3;
        var color = '#f00';

        if (special == "start") {
            size = lemins;
            startid = room[0];
        }
        if (special == "start" || special == "end") {
            color = '#0f9';
        }
        if (special == "end")
            endid = room[0];

        s.graph.addNode({
            id: room[0],
            label: room[0],
            x: Math.abs(room[1]),
            y: Math.abs(room[2]),
            basic_x: Math.abs(room[1]),
            basic_y: Math.abs(room[2]),
            grid_x: s.graph.nodes().length %% 50,
            grid_y: Math.floor(s.graph.nodes().length / 50),
            size: size,
            color: color
        });
        graphcopy.addNode(
            {
                id: room[0],
                label: room[0],
                x: Math.abs(room[1]),
                y: Math.abs(room[2]),
                basic_x: Math.abs(room[1]),
                basic_y: Math.abs(room[2]),
                grid_x: s.graph.nodes().length %% 50,
                grid_y: Math.floor(s.graph.nodes().length / 50),
                size: size,
                color: color
            }
        )
    }

    function parse_link(line) {
        var link = line.split("-");
        var color = generateLeminColor(Math.random());
        console.log("Add link: " + line);
        s.graph.addEdge({
            id: line,
            source: link[0],
            target: link[1],
            color: color,
            type: 'curve',
            size: 0.1
        });
        graphcopy.addEdge(
            {
                id: line,
                source: link[0],
                target: link[1],
                color: color,
                type: 'curve',
                size: 0.1
            }
        )
    }

    function applyTurnToGraph(line) {
        var leminsPosition = line.split(" ");

        leminsPosition.forEach(function(element, index, array) {
            var linfo = element.split("-");

            s.graph.nodes(linfo[1]).label += " " + linfo[0];
            s.graph.nodes(linfo[1]).color = generateLeminColor(linfo[0].substr(1));
        });
    }

    function setEndSize(elementvalue) {
        for (var i = 0; i <= elementvalue; i++) {
            var leminsPosition = turnsarray[i].split(" ");

            leminsPosition.forEach(function(elem, index, array) {
               var linfo = elem.split("-");

               if (linfo[1] == endid)
                   s.graph.nodes(linfo[1]).size += 1;
               else
                   s.graph.nodes(linfo[1]).size = s.graph.nodes().length
            });
        }
    }

    function showTurn(element) {
        applyTurnToGraph(turnsarray[element.value]);
        setEndSize(element.value);
        s.refresh();
        s.graph.clear();
        s.graph.read({nodes: graphcopy.nodes(), edges: graphcopy.edges()});
    }

    function getLinksFromTurn(turn, turnindex) {
        var links = [];
        var leminPos = turn.split(" ");
        leminPos.forEach(function(lemin, index, array) {
            var infos = lemin.split("-");
            if (turnindex == 0)
                links.push(startid + "-" + infos[1]);
            else {
                var previousLeminPos = turnsarray[turnindex - 1].split(" ");
                for (var i = 0; i < previousLeminPos.length; i++) {
                    var pinfos = previousLeminPos[i].split("-");

                    if (pinfos[0] == infos[0]) {
                        links.push(pinfos[1] + "-" + infos[1]);
                        break;
                    }
                }
            }
        });
        return (links);
    }

    function initGraph() {
        text.forEach(function (line, index, array) {
            line = line.replace(/(^\s+|\s+$)/g, '');
            if (line[0] == 'L'){
                $('#turnsbuttonbar').append(
                    "<li class='turnsbutton' type='button' value='" +
                    turnsarray.length +
                    "' onclick='showTurn(this)'>" + (turnsarray.length + 1) +
                    "</li>"
                );
                turnsarray.push(line);
            }
            else if  (mode == 3) {
                mode = 0;
            }
            else if (line == "##start") {
                parse_room_init(array[index + 1], "start");
                mode = 3;
            }
            else if (line == "##end") {
                parse_room_init(array[index + 1], "end");
                mode = 3;
            }
            else if (line[0] == '#') {

            }
            else if (mode == 0 && line.split(' ').length == 3)
                parse_room_init(line, "none");
        });

        turnsarray.forEach(function(elem, index, array) {
            links = getLinksFromTurn(elem, index);
            links.forEach(function(elem, index, array) {
                try {
                    parse_link(elem);
                }
                catch(err) {
                    console.log(err);
                }
            });
        });
        s.graph.nodes(endid).size = s.graph.nodes().length;
        s.graph.nodes(startid).size = s.graph.nodes().length;
        graphcopy.nodes(endid).size = graphcopy.nodes().length;
        graphcopy.nodes(startid).size = graphcopy.nodes().length;
    }

    var step = 0;
    function gridify() {
        var prefix = ['grid_', 'basic_'][step = +!step];
        sigma.plugins.animate(
         s,
         {
           x: prefix + 'x',
           y: prefix + 'y',
         }
        );
        graphcopy.nodes().forEach(function(elem, ind, arr) {
            if (prefix == 'grid_')
            {
                elem.x = elem.grid_x;
                elem.y = elem.grid_y;
            }
            else {
                elem.x = elem.basic_x;
                elem.y = elem.basic_y;
            }
        });
    }

    initGraph();
    s.settings.animationTime =  1000;
    s.refresh();
</script>
</body>
</html>
"""

if __name__ == "__main__":
    dataresult = sys.stdin.read()
    data = template % dataresult
    with open("vizualize.html", 'w') as fd:
        fd.write(data)
