find_max(X,Y,X):-
    X>Y,!.
find_max(X,Y,Y):-
    X<Y,!.
find_max(X,Y,equal):-
    X=Y,!.
