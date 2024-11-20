arithmetic:-
    write('Enter the first number: '),
    read(A),
    write('Enter the second number: '),
    read(B),
    write('Sum'),
    sum(A,B),
    nl,
    write('Difference'),
    difference(A,B),
    nl,
    write('Multiply'),
    multiply(A,B),
    nl,
    write('Divide'),
    divide(A,B).

sum(A,B):-
    Result is A + B,
    write('result = ',Result).

difference(A,B):-
    Result is A - B,
    write('result = ',Result).

multiply(A,B):-
    Result is A * B,
    write('result = ',Result).

divide(A,B):-
    Result is A / B,
    write('result = ',Result).
