grand_son(X,Y):-
    father(Y,Z),
    father(Z,X).

father(mahendra,birendra).
father(mahendra,gynendra).
father(mahendra,dhirendra).
father(birendra,dipendra).
father(birendra,nirajan).
father(gynendra,paras).
father(paras,hyrendran).

