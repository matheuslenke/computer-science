-module(tut3).

-export([convert_length/1, return_cities/0]).

convert_length({centimeter, X}) -> {inch, X / 2.54};


convert_length({inch, Y}) -> {centimeter, Y * 2.54}.


return_cities() -> [{moscow, {c, -10}},
    {cape_town, {f, 70}},
    {stockholm, {c, -4}},
    {paris, {f, 28}}, {london,
    {f, 36}}].
