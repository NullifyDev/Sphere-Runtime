# Sphere Binary Executable (SBE)
SBE is a file that tells the runtime how to behave and how to treat the software. 
It is capable of doing basic filesystem-based conditionning, including whitelisting and blacklisting. Even under certain conditions!
It can also dictate and specify the type of hashing algorithm to use.

This file contains hashes of different associated/related SBF and SBE files of the software. This is used by FIVALDI (File Integrety Verification Against Loading Dll Injections).

# Example 
```
size 16 
entry main int

nofivaldi

[whitelist]
path/to/exempt/file.sbf
mod/*/mymod.[sbf/sbe]   # * wild card for "any folder"

mod/mymod.sbe  # Prioritizes first extension 
mod/mymod.sbf 

[blacklist]
path/to/excluded/file.sbf
mod.BAK/*
```
