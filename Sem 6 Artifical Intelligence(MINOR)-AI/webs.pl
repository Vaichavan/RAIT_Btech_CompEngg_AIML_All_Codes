% Weather facts
weather(phenoi_x, summer, hot).
weather(a1, summer, warm).
weather(phenoi_x, winter, warm).

% Comparison rule
warmer_than(C1, C2) :-
    weather(C1, hot, summer),
    weather(C2, warm, summer).

% Family relationships
parent(joe, jane).
parent(harry, carl).
parent(meg, jane).
parent(jane, anne).
parent(carl, ralph).
parent(hazel, harry).

% Grandparent rule
grandparent(X, Z) :-
    parent(X, Y),
    parent(Y, Z).
