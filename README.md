`target.c` is the target, this is the process whos PEB gets patched

`patch.c` gets built into a dll to be injected into `target.c`, it sets the `BeingDebugged` field of the PEB to 0

`inject.c` is an extremely simple dll injector
