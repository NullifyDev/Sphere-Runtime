# Runtime

The runtime is an [SBF](sbf.md) interpreter that will implement its own standard functions if it finds itself in a freestanding environment. The runtime can only start running if an [SBE](sbe.md) is a runtime argument.
The runtime will be constantly active  inside a freestanding environment. However, if inside an Operating System, not only will it load the OS's standard, but also check for any existing Sphere Runtime priocesses. If so, the sbe will be executed accordingly as a memory-block-contained software.

Only through Runtime can [SBFs](sbf.md) load [SBEs](sbe.md)