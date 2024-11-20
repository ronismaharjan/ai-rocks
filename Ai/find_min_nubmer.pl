find_min(X,Y,Y):-
    X>Y,!.
find_min(X,Y,X):-
    X<Y,!.
find_min(X,Y,equal):-
    X=Y,!.
