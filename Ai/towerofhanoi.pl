tower_of_hanoi(0, _, _, _) :- !.  
tower_of_hanoi(N, Source, Target, Auxiliary) :-
    N > 0,
    M is N - 1,
    tower_of_hanoi(M, Source, Auxiliary, Target),  
    write('Move disk '), write(N), write(' from '), write(Source), write(' to '), write(Target), nl,
    tower_of_hanoi(M, Auxiliary, Target, Source). 

% Example usage:
% To move 3 disks from peg 'A' to peg 'C' using peg 'B':
% ?- tower_of_hanoi(3, a, c, b).
