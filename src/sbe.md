# Sphere Binary Executable (SBE)
SBE is a file that tells the runtime how to behave and how to treat the software. 
It is capable of doing basic filesystem-based conditionning, including whitelisting and blacklisting. Even under certain conditions!
It can also dictate and specify the type of hashing algorithm to use.

This file contains hashes of different associated/related SBF and SBE files of the software. This is used by FIVALDI (File Integrety Verification Against Loading Dll Injections).

# Example 
```
size 16
entry main int

[dependency]
./deps/path/to/file.sbf
./deps/path/to/directory
./deps/path/to/directory/*
./deps/path/to/directory/*/.../
./deps/path/to/directory/...*/
./deps/path/to/directory/sub.../

[blacklist]
# to prevent loading

[whitelist]
# to allow loading
```
|    Syntax    | Description                                                                                            |
|--------------|--------------------------------------------------------------------------------------------------------|
|    `./*`     | All files and folders                                                                                  |
|  `./*/.../`  | All files, folders and subdirectories (default depth: 1)                                               |
|  `./...*/`   | recursive subdirectory traversal - `*` can be any number for max depth (default: unlimited)            |
| `./sub...*/` | recursive subdirectory traversal under `sub` folder (max depth is `*`- default: unlimited)             |
|  `./*...*/`  | Recursively all files, folders and subdirectories at any depth (max depth is `*`- default: unlimited)  |
