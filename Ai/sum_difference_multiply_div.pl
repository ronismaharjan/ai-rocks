add(X,Y):-
    Z is X+Y,
    write(Z).

difference(X,Y):-
    Result is X-Y,
    write(Result).

multiply(X,Y):-
    Result is X*Y,
    write(Result).

divide(X,Y):-
    Result is X/Y,
    write(Result).
