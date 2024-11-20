engine_max :-
    write('Enter the first number: '),
    read(A),
    write('Enter the second number: '),
    read(B),
    find_max(A, B, Result),  % We need a Result variable to store the output
    write('The maximum is: '),
    write(Result), nl.

find_max(X, Y, X) :-
    X > Y,
    !.
find_max(X, Y, Y) :-
    X < Y,
    !.
find_max(X, Y, equal) :-
    X = Y,
    !.

engine_min :-
    write('Enter the first number: '),
    read(A),
    write('Enter the second number: '),
    read(B),
    find_min(A, B, Result),  % We need a Result variable to store the output
    write('The smallest is: '),
    write(Result), nl.

find_min(X, Y, X) :-
    X < Y,  % We want X to be the minimum
    !.
find_min(X, Y, Y) :-
    X > Y,  % We want Y to be the minimum
    !.
find_min(X, Y, equal) :-
    X = Y,  % When both are equal
    !.
