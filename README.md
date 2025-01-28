<p align="center">
    <h1 align="center"><b>Runtime</b></h1>
</p>

The runtime is an [SBF](sbf.md) interpreter that will implement its own standard functions if it finds itself in a freestanding environment. The runtime can only start running if an [SBE](sbe.md) is a runtime argument.
The runtime will be constantly active  inside a freestanding environment. However, if inside an Operating System, not only will it load the OS's standard, but also check for any existing Sphere Runtime priocesses. If so, the sbe will be executed accordingly as a memory-block-contained software.

Only through Runtime can SBFs load SBEs.

# [TBA] Commands (Non-Freestanding)
|     comand                           |                             description                                  |
|--------------------------------------|--------------------------------------------------------------------------|
|`sphere start <dir/to/executable.sbe>`| runs the provided sbe                                                    |
|`sphere end <dir/to/executable.sbe>`  | sends quit signals to all processes within the given                     | 
|`sphere end <pid>`                    | sends a quit signal to the process wit the id                            |
|`sphere kill <pid>`                   | kills the process and frees the related memory entirely                  |
|`sphere kill <dir/to/executable.sbe>` | kills all processes and frees the related memory entirely                |
|`sphere pause <pid>`                  | pauses the process and skips its execution until resumed                 |
|`sphere resume <pid>`                 | resumes the process and continues from the last instruction              |
