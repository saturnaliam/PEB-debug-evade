target:
	gcc -o target target.c
patch:
	gcc -shared -o patch.dll patch.c