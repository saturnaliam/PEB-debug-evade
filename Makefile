target:
	gcc -o target target.c
patch:
	gcc -shared -o patch.dll patch.c
inject:
	gcc -o injector inject.c