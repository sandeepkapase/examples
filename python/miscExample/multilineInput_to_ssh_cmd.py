#!/usr/bin/env python
import os
cmdSsh = "ssh -o StrictHostKeyChecking=no\
 -o UserKnownHostsFile=/dev/null\
 -o UpdateHostKeys=no -T user@10.3x.4x.16y "

cmdArgs=["show subsystem summary short",
        "show subsystem summary",
        "show subsystem summary all",
        "show subsystem fault",
        "show subsystem fault all",
        "show sas_connector"]

cmdPrefix="<<CMD myapp\n"+\
        "\n".join(["{}"]*\
        len(cmdArgs)).format(*cmdArgs) + "\nCMD"

cmdExec = cmdSsh+cmdPrefix

os.system(cmdExec)

# In the example above we are executing myapp binary which will accept
# "cmdArgs" command list and execute them on by one.
