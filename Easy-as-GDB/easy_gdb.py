#TODO write a description for this script
#@author 
#@category _NEW_
#@keybinding 
#@menupath 
#@toolbar 


#TODO Add User Code Here
import gdb
import string
import queue

MAX_FLAG_LEN = 0x200

class Checkpoint(gdb.Breakpoint):
    def __init__(self, queue, target_hitcount, *args):
        super().__init__(*args)
        self.silent = True
        self.queue = queue
        self.target_hitcount = target_hitcount
        self.hit = 0

    def stop(self):
        res = []
        self.hit += 1
        if self.hit == self.target_hitcount:
            al = gdb.parse_and_eval("$al")
            dl = gdb.parse_and_eval("$dl")
            self.queue.put(al == dl)
        return False

class Solvepoint(gdb.Breakpoint):
    def __init__(self, *args):
        super().__init__(*args)
        self.silent = True
        self.hit = 0

    def stop(self):
        self.hit += 1
        return False

gdb.execute("delete")
sp = Solvepoint("*0x00000a71")
queue = queue.Queue()
flag = ""
ALPHABET = string.ascii_letters + string.digits + "{}_"

for i in range(len(flag), MAX_FLAG_LEN):
    for c in ALPHABET:
        bp = Checkpoint(queue, len(flag) + 1, '*0x0001098e')
        gdb.execute("run <<< {}{}".format(flag, c))
        result = queue.get(timeout = 1)
        print(result)
        bp.delete()
        if result:
            flag += c
    if sp.hit > 0:
        print("Found flag: {}".format(flag))
        gdb.execute("q")