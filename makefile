target o:
	gcc originalA.c -o originalA
	gcc originalB.c -o originalB
	gcc modifiedA.c -o modifiedA
	gcc modifiedB.c -o modifiedB
    mkdir m{1..5}
    mkdir check
    mkdir bowl{1,2}
