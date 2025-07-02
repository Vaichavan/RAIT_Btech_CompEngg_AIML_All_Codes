% Weather facts
weather(phenoi_x, summer, hot).
weather(a1, summer, warm).
weather(phenoi_x, winter, warm).

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

% Base case: X is a direct parent of Y
ancestor(X, Y) :- parent(X, Y).

% Recursive case: X is an ancestor of Y if X is a parent of Z, and Z is an ancestor of Y
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).