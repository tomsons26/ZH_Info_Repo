# ZH_Info_Repo

This repo will contain structures, enums and other types we've mapped out in the Generals Zero Hour 1.04 PC game and 1.04 Worldbuilder binaries, or ZH Mac version game binary, in the future this might cover Generals as well, currently we will not cover any other binaries.
Prefered information is from the PC binaries as Mac has some changes so isn't guranteed to line up with the PC version, examples of such cases are if STLPort or std members are involved.

Purpose of this is to simplify sharing this information and have a centralized discussion place so we can keep things up to date and have the ability to comment on them. 
These names may or may not be the actual names the various SAGE binaries expose as strings, in a lot of cases they will be best guesses based on behavior. The repo will be added to as we decide to or require to share information.  

# To contribute there are a couple of preferences:

* Structure members prefixed as m_ are confirmed and likely the names we will use in the actual code.  
* Anything you can't confirm leave without this prefix.
* If you are certain on a member name add the `// confirmed` comment to it. 
* Preferably if the type is used anywhere, leave a comment on where and if possible how/for what purpose, so its simpler to double check if required, bare minimum for such a comment is a address(specifying which binary as well, using ZH, WB, or MAC) or function name.
* Try to keep the information structured to its context, i.e. map chunk related things in mapchunks.h  
